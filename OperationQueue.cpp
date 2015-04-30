#include "OperationQueue.h"

namespace ccHelp
{
	OperationQueue::OperationQueue()
		: isRunning(false)
	{
	}


	void OperationQueue::pushOperation(ROperation op, CCH_CALLBACK completion)
	{
		this->pushOpWithCompletion(op, completion);
	}

	void OperationQueue::pushFunction(CCH_CALLBACK func)
	{
		auto funcOp = [func](CCH_CALLBACK completion)
		{
			func();
			completion();
		};
		this->pushOpWithCompletion(funcOp, DO_NOTHING_FUNC);
	}

	uint OperationQueue::nWaitOperations() const
	{
		return this->operations.size();
	}

	bool OperationQueue::isOperating() const
	{
		return this->isRunning;
	}

	void OperationQueue::activeOperation()
	{
		if (!this->isRunning && !this->operations.empty())
		{
			auto opWithCompletion = this->operations.front();
			this->operations.pop();

			CCH_CALLBACK completion = opWithCompletion.second;
			CCH_CALLBACK complWithActiveNext = [completion, this]
			{
				completion();
				this->isRunning = false;
				this->activeOperation();
			};

			this->isRunning = true;
			opWithCompletion.first(complWithActiveNext);
		}
	}

	void OperationQueue::pushOpWithCompletion(ROperation op, CCH_CALLBACK completion)
	{
		auto opWithCompletion = make_pair(op, completion);
		this->operations.push(opWithCompletion);
		this->activeOperation();
	}
}
