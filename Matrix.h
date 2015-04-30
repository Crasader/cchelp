#pragma once
#include "Def.h"
#include "Index2D.h"

namespace ccHelp
{
	template <typename T>
	class Matrix
	{
	private:
		T **mat;
		uint rows, cols;

	public:
		inline Matrix(uint rows, uint cols)
		{
			CCASSERT(rows > 0 && cols > 0, "Invalid size");

			mat = alloc2D(rows, cols, T());
		}

		inline ~Matrix()
		{
			CC_SAFE_DELETE(mat);
		}

		inline CREF(T) operator[](CREF(Index2D) idx) const
		{
			return get(idx.row, idx.col);
		}

		inline T& operator[](CREF(Index2D) idx)
		{
			return get(idx.row, idx.col);
		}

		bool contains(CREF(Index2D) idx) const
		{
			return contains(idx.row, idx.col);
		}

		bool contains(uint row, uint col) const
		{
			return (row < rows && col < cols);
		}

		inline CREF(T) get(uint row, uint col) const
		{
			CCASSERT(row < rows && col < cols, "Out of range");
			return mat[row][col];
		}

		inline T& get(uint row, uint col)
		{
			CCASSERT(row < rows && col < cols, "Out of range");
			return mat[row][col];
		}

		inline uint nRows() const {return rows;}
		inline uint nCols() const {return cols;}
	};
}