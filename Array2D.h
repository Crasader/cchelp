#pragma once

#include "cocos2d.h"
#include "Index2D.h"

namespace ccHelp
{
	class Factory;

	template<class E>
	class Array2D : public cocos2d::Object
	{
	public:
		Array2D(uint nRows, uint nCols)
			: container(new E**[nRows]),
			rows(nRows),
			cols(nCols)
		{
			for (uint i = 0; i < nRows; i++)
			{
				container[i] = new E*[nCols];
				for (uint j = 0; j < nCols; ++j)
				{
					container[i][j] = NULL;
				}
			}
		}

		virtual ~Array2D()
		{
			for (uint i = 0; i < nRows(); i++)
			{
				for (uint j = 0; j < nCols(); ++j)
				{
					CC_SAFE_RELEASE(container[i][j]);
				}

				CC_SAFE_DELETE(container[i]);
			}

			CC_SAFE_DELETE(container);
		}

		friend class Factory;

	public:
		const E* get(uint row, uint col) const
		{
			if (!isContains(row, col))
			{
				return nullptr;
			}

			return this->container[row][col];
		}

		E* get(uint row, uint col)
		{
			if (!isContains(row, col))
			{
				return nullptr;
			}

			return this->container[row][col];
		}

		const E* get(CREF(Index2D) idx) const
		{
			return get(idx.row, idx.col);
		}

		E* get(CREF(Index2D) idx)
		{
			return get(idx.row, idx.col);
		}

		void put(E *elem, uint row, uint col)
		{
			if (!isContains(row, col))
			{
				return;
			}

			E *current = this->container[row][col];
			CC_SAFE_RELEASE(current);

			this->container[row][col] = elem;
			if (elem)
			{
				elem->retain();
			}

			this->ItemDidPut(elem, current, row, col);
		}

		void put(E *elem, CREF(Index2D) idx)
		{
			this->put(elem, idx.row, idx.col);
		}

		E* operator[](CREF(Index2D) index)
		{
			return this->get(index.row, index.col);
		}

		const E* operator[](CREF(Index2D) index) const
		{
			return this->get(index.row, index.col);
		}

		uint nRows() const
		{
			return rows;
		}

		uint nCols() const
		{
			return cols;
		}

		bool isContains(uint row, uint col) const
		{
			return row < this->rows && col < this->cols;
		}

		bool isContains(CREF(Index2D) idx) const
		{
			return this->isContains(idx.row, idx.col);
		}
	protected:
		virtual void ItemDidPut(E* _new, E* old, uint row, uint col) {}
	private:
		E ***container;
		uint rows, cols;
	};
}