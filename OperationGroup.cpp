#include "OperationGroup.h"

namespace ccHelp
{
	OperationGroup::OperationGroup() :
		isLocked(false), nOps(0)
	{
		this->retain();
	}

	OperationGroup::OperationGroup(CCH_FUNCTION _compl) :
		completion(_compl), isLocked(false), nOps(0)
	{
		this->retain();
	}

	void OperationGroup::setCompletion(CCH_CALLBACK _compl)
	{
		CCASSERT(!completion, "Completion is callable (already setted)");
		CCASSERT(!isLocked, "Group is locked");
		this->completion = _compl;
	}
	
	CCH_FUNCTION OperationGroup::addOp(ROperation op)
	{
		CCASSERT(!isLocked, "Operations group is locked, cannot add operation");

		CCH_FUNCTION opWithActive = [this, op]
		{
			op([this]
			{
				--nOps;
				this->activeCallback();
			});
		};

		++nOps;
		return opWithActive;
	}

	CCH_FUNCTION OperationGroup::addFunc(CCH_CALLBACK func)
	{
		CCASSERT(!isLocked, "Operations group is locked, cannot add operation");

		CCH_FUNCTION funcWithActive = [this, func]
		{
			func();
			--nOps;
			this->activeCallback();
		};

		++nOps;
		return funcWithActive;
	}

	void OperationGroup::lock()
	{
		CCASSERT(!isLocked, "Operations group is already locked");

		this->isLocked = true;
		this->activeCallback();
	}

	void OperationGroup::activeCallback()
	{
		CCASSERT(isLocked, "Group must be locked before first operation finish");

		if (!nOps)
		{
			completion();
			this->release();
		}
	}

	AutoOperationGroup::AutoOperationGroup()
		: OperationGroup()
	{

	}

	AutoOperationGroup::AutoOperationGroup(CCH_CALLBACK completion)
		: OperationGroup(completion)
	{

	}

	CCH_FUNCTION AutoOperationGroup::addOp(ROperation op)
	{
		CCH_FUNCTION func = OperationGroup::addOp(op);
		this->funcs.push_back(func);
		return func;
	}

	CCH_FUNCTION AutoOperationGroup::addFunc(CCH_CALLBACK op)
	{
		CCH_FUNCTION func = OperationGroup::addFunc(op);
		this->funcs.push_back(func);
		return func;
	}


	void AutoOperationGroup::lock()
	{
		OperationGroup::lock();
		for (CCH_CALLBACK func : funcs)
		{
			func();
		}
		funcs.clear();
	}
}