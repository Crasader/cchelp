#pragma once
#include "Def.h"
#include <functional>
#include <queue>

using namespace std;

namespace ccHelp
{
	typedef function<void(CCH_CALLBACK)> Operation;
	typedef const Operation& ROperation;

	class OperationQueue
	{
	public:
		OperationQueue();
		void pushOperation(ROperation, CCH_CALLBACK = DO_NOTHING_FUNC);
		void pushFunction(CCH_CALLBACK);
		uint nWaitOperations() const;
		bool isOperating() const;

	private:
		queue<pair<Operation, CCH_FUNCTION>> operations;
		bool isRunning;

		void activeOperation();
		void pushOpWithCompletion(ROperation op, CCH_CALLBACK completion);
	};
}