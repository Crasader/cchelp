#pragma once
#include "Def.h"

namespace ccHelp
{
	class Lock
	{
	public:
		Lock();

		void lock();
		void unlock();

		bool isLocked() const;
	private:

		uint lockLevel;
	};
}