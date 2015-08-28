#pragma once
#include "Def.h"

namespace ccHelp
{
	struct Index2D
	{
		uint row, col;

		inline Index2D()
			: row(0), col(0) {}

		inline Index2D(uint _row, uint _col)
			: row(_row), col(_col) {}

		inline Index2D(CREF(Index2D) idx)
			: row(idx.row), col(idx.col) {}

		inline CREF(Index2D) operator=(CREF(Index2D) idx)
		{
			this->row = idx.row;
			this->col = idx.col;

			return *this;
		}

		inline operator size_t() const
		{
			return ((row>>16 & 0x0000ffff) | (row<<16 & 0xffff0000)) ^ col;
		}

		inline bool operator==(const Index2D &idx) const
		{
			return row == idx.row && col == idx.col;
		}

		inline Index2D operator+(const Index2D &idx) const
		{
			return Index2D(row + idx.row, col + idx.col);
		}

		inline const Index2D& operator+=(const Index2D &idx)
		{
			row += idx.row;
			col += idx.col;

			return *this;
		}

		inline Index2D mod(int dRow, int dCol) const
		{
			return Index2D(row + dRow, col + dCol);
		}

		inline Index2D modRow(int dRow) const
		{
			return Index2D(row + dRow, col);
		}

		inline Index2D modCol(int dCol) const
		{
			return Index2D(row, col + dCol);
		}
	};
}

namespace std
{
	template <>
    struct hash<ccHelp::Index2D>
	{
		std::size_t operator()(const ccHelp::Index2D &k) const
		{
			return (size_t) k;
		}
	};
}