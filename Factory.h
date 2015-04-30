#pragma once

#include "Def.h"
#include "Array2D.h"

namespace ccHelp
{
	class Factory
	{
	public:
		template<class E>
		static Array2D<E>* newArray2D(uint nRows, uint nCols)
		{
			Array2D<E> *ret = new Array2D<E>(nRows, nCols);
			return CCH_NOT_INIT_CREATE(ret);
		}

	private:
		Factory();
	};
}