#pragma once
#include "Def.h"

namespace ccHelp
{
#define DELEGATE std::function<void(const T &oldVal, const T& newVal)>
	template<class T>
	class ValueProxy
	{
	private:
		T val;
		DELEGATE valueChanged;

	public:
		ValueProxy(const T& defVal = T())
		{
			this->val = defVal;
		}

		ValueProxy(const ValueProxy &other)
		{
			this->val = other.val;
		}

		void set(const T& newVal)
		{
            T oldVal = this->val;
			this->val = newVal;

			if (this->valueChanged)
			{
				this->valueChanged(oldVal, this->val);
			}
		}

		const T& operator()() const
		{
			return this->val;
		}

		const T& operator=(const T& newVal)
		{
			this->set(newVal);
			return this->val;
		}

	public:
		PROPERTY_GET(T&, ,val);
		PROPERTY_GET(DELEGATE, OnValueChanged, valueChanged);
		void setOnValueChanged(DELEGATE newDelegate, bool dispatchFirst = true)
		{
			this->valueChanged = newDelegate;
			if (this->valueChanged)
			{
				this->valueChanged(this->val, this->val);
			}
		}
	};
#undef DELEGATE
}