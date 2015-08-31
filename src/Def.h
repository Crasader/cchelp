#pragma once
#include "cocos2d.h"
#include <functional>

#define USING_CC_HELP using namespace ccHelp

typedef char byte;
typedef unsigned char ubyte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

namespace ccHelp
{
    class obj
    {
    public:
        virtual ~obj();
    };
    
	template<class T>
	int compare(const T& t1, const T& t2)
	{
		return (t1 > t2)?1:((t1 == t2)?0:-1);
	}

	template<typename T>
	T** alloc2D(uint nRows, uint nCols, const T& defVal = T())
	{
		T** mat = new T*[nRows];

		for (uint i = 0; i < nRows; ++i)
		{
			mat[i] = new T[nCols];

			for (uint j = 0; j < nCols; ++j)
			{
				mat[i][j] = defVal;
			}
		}

		return mat;
	}

	template<typename T>
	void set2D(T** mat, uint nRows, uint nCols, const T& val)
	{
		for (uint i = 0; i < nRows; ++i)
		{
			for (uint j = 0; j < nCols; ++j)
			{
				mat[i][j] = val;
			}
		}
	}

	template<typename T>
	void delete2D(T** mat, uint nRows)
	{
		for (uint i = 0; i < nRows; ++i)
		{
			delete []mat[i];
		}

		delete []mat;
	}

}

template<typename T>
T* autoReleasePointer(T* t)
{
	if (t)
	{
		t->autorelease();
	}

	return t;
}

template<typename T>
T* killPointer(T** t)
{
	if (*t)
	{
		delete (*t);
		(*t) = nullptr;
	}

	return nullptr;
}

typedef std::function<void()> CCH_FUNCTION;
typedef const CCH_FUNCTION& CCH_CALLBACK;
extern CCH_FUNCTION DO_NOTHING_FUNC;

#define CCH_CREATE(pRet) ((pRet && pRet->init())?(autoReleasePointer(pRet)):(killPointer(&pRet)))
#define CCH_NOT_INIT_CREATE(pRet) (autoReleasePointer(pRet))

#define CCH_ALL_COMPARATORS(CLASS, comparor) \
	inline bool operator==(const CLASS &x) const {return this->comparor(x) == 0;} \
	inline bool operator>(const CLASS &x) const {return this->comparor(x) > 0;} \
	inline bool operator<(const CLASS &x) const {return this->comparor(x) < 0;} \
	inline bool operator!=(const CLASS &x) const {return this->comparor(x) != 0;} \
	inline bool operator>=(const CLASS &x) const {return this->comparor(x) >= 0;} \
	inline bool operator<=(const CLASS &x) const {return this->comparor(x) <= 0;} \
	inline bool equals(const CLASS &x) const {return this->comparor(x) == 0;} \
	inline bool equals(const CLASS *x) const {return this->comparor(*x) == 0;}

#define CCH_ALL_COMPARATORS_NO_INL(CLASS, comparor) \
bool operator==(const CLASS &x) const {return this->comparor(x) == 0;} \
bool operator>(const CLASS &x) const {return this->comparor(x) > 0;} \
bool operator<(const CLASS &x) const {return this->comparor(x) < 0;} \
bool operator!=(const CLASS &x) const {return this->comparor(x) != 0;} \
bool operator>=(const CLASS &x) const {return this->comparor(x) >= 0;} \
bool operator<=(const CLASS &x) const {return this->comparor(x) <= 0;} \
bool equals(const CLASS &x) const {return this->comparor(x) == 0;} \
bool equals(const CLASS *x) const {return this->comparor(*x) == 0;}

#define PROPERTY_GET(Type, Name, var) \
inline const Type get##Name() const {return this->var;} \
inline Type get##Name() {return this->var;}
#define PROPERTY_VAR_GET(Type, var) PROPERTY_GET(Type, var, var)

#define PROPERTY_SET(Type, Name, var) inline void set##Name(Type val) {this->var = val;}
#define PROPERTY_VAR_SET(Type, var) PROPERTY_SET(Type, var, var)

#define PROPERTY_GET_SET(Type, Name, var) \
	PROPERTY_GET(Type, Name, var) \
	PROPERTY_SET(Type, Name, var)

#define SYTHESINE_GET(Type, Name, var) \
	private: \
	Type var; \
	public: \
	PROPERTY_GET(const Type&, Name, var)

#define SYTHESINE_VAR_GET(Type, var) SYTHESINE_GET(Type, var, var)

#define STATIC_SYTHESINE_GET(Type, Name, var) \
	private: \
	static Type var; \
	public: \
	static inline const Type& get##Name() {return var;}

#define STATIC_SYTHESINE_VAR_GET(Type, var) STATIC_SYTHESINE_GET(Type, var, var)

#define STD_HASHABLE_DETAIL(CLASS, HASHER, COMPARER) \
	inline int COMPARER (const CLASS &h) const \
	{ \
		return ccHelp::compare(this->##HASHER(), h.##HASHER());\
	} \
	CCH_ALL_COMPARATORS(CLASS, COMPARER)

#define STD_HASHABLE(CLASS) STD_HASHABLE_DETAIL(CLASS, hash, compare)

#define PUREF(func) virtual func = 0
#define CREF(CLASS) const CLASS&

#define _out_
#define _inout_

#define STATIC_CONSTRUCTOR_DECLARE(CLASS) \
	private: \
		class Initializer \
		{ \
		private: \
			Initializer(); \
			static Initializer __unused_initializer; \
		}; \
		friend class CLASS::Initializer

#define STATIC_CONSTRUCTOR_IMPL(CLASS) \
	CLASS::Initializer CLASS::Initializer::__unused_initializer;	\
	CLASS::Initializer::Initializer()

#define CCH_SYNTHESIZE_PASS_BY_REF(type, var, func) \
CC_SYNTHESIZE_PASS_BY_REF(type, var, func) \
public: inline virtual type& get##func() {return var;} 

#define ARG(...) __VA_ARGS__
