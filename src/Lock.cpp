#include "Lock.h"

namespace ccHelp
{
	Lock::Lock()
		: lockLevel(0) {}

	void Lock::lock()
	{
		++this->lockLevel;
	}

	void Lock::unlock()
	{
		if (this->lockLevel > 0)
		{
			--this->lockLevel;
		}
	}

	bool Lock::isLocked() const
	{
		return (this->lockLevel > 0);
	}
}