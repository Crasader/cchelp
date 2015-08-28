#pragma once
#include "Def.h"
#include "Index2D.h"
#include "Event.h"

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
            for (uint r = 0; r < rows; ++r)
            {
                for (uint c = 0; c < cols; ++c)
                {
                    mat[r][c] = T();
                }
            }
            
			this->rows = rows;
			this->cols = cols;
		}

		inline ~Matrix()
		{
			delete2D(mat, rows);
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
        
        inline CREF(T) get(const Index2D &idx) const
        {
            return get(idx.row, idx.col);
        }

		inline CREF(T) get(uint row, uint col) const
		{
            return const_cast<Matrix<T> *>(this)->get(row, col);
		}

		inline T& get(uint row, uint col)
		{
			CCASSERT(row < rows && col < cols, "Out of range");
			return mat[row][col];
        }
        
        inline T& get(const Index2D &idx)
        {
            return get(idx.row, idx.col);
        }
        
        inline void set(T val, const Index2D &idx)
        {
            return set(val, idx.row, idx.col);
        }
        
        inline void set(T val, uint row, uint col)
        {
            CCASSERT(row < rows && col < cols, "Out of range");
            mat[row][col] = val;
        }
        
        inline void foreach(std::function<void(const Index2D&, T&)> func)
        {
            Index2D ite;
            for (ite.row = 0; ite.row < rows; ++ite.row)
            {
                for (ite.col = 0; ite.col < cols; ++ite.col)
                {
                    func(ite, this->get(ite.row, ite.col));
                }
            }
        }
        
        inline void foreach(std::function<void(const Index2D&, const T&)> func) const
        {
            Index2D ite;
            for (ite.row = 0; ite.row < rows; ++ite.row)
            {
                for (ite.col = 0; ite.col < cols; ++ite.col)
                {
                    func(ite, this->get(ite.row, ite.col));
                }
            }
        }
        
        inline void foreach(std::function<void(T&)> func)
        {
            this->foreach([&func, this](const Index2D &idx, T &val)
                          {
                              func(val);
                          });
        }
        
        inline void foreach(std::function<void(const T&)> func) const
        {
            this->foreach([&func, this](const Index2D &idx, const T &val)
                          {
                              func(val);
                          });
        }

		inline uint nRows() const {return rows;}
		inline uint nCols() const {return cols;}
	};
}