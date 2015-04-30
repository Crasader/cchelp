#pragma once
#include "Def.h"
#include <vector>
#include "cocos2d.h"
#include "UtilX.h"
#include "OperationQueue.h"

using namespace std;
USING_NS_CC;

namespace ccHelp
{
	class OperationGroup : public Ref
	{
	public:
		OperationGroup();
		OperationGroup(CCH_FUNCTION callBack);
		virtual CCH_FUNCTION addOp(ROperation op);
		virtual CCH_FUNCTION addFunc(CCH_CALLBACK func);
		virtual void lock();
		void setCompletion(CCH_CALLBACK completion);

	private:
		bool isLocked;
		uint nOps;

		CCH_FUNCTION completion;
		void activeCallback();
	};

	class AutoOperationGroup : public OperationGroup
	{
	private:
		list<CCH_FUNCTION> funcs;

	public:
		AutoOperationGroup();
		AutoOperationGroup(CCH_CALLBACK completion);

		CCH_FUNCTION addOp(ROperation op) override;
		CCH_FUNCTION addFunc(CCH_CALLBACK op) override;
		void lock() override;
	};
}