#pragma once
#include "jsoncpp_ser.h"
#include "cocos2d.h"
#include <memory>

USING_NS_CC;


namespace ccHelp
{
	typedef void* prID;

	/*class Parcel
	{
	private:
		static union ParcelData
		{
			int iVal;
			float fVal;
			struct {
				Color4B c4bVal;
			};
			struct {
				Vec2 pVal;
			};
			struct {
				Size szVal;
			};
			struct {
				string sVal;
			};
		};
	public:
		enum Type
		{
			INT,
			FLOAT,
			COLOR4B,
			VECTOR2,
			SIZE,
		};
	private:
		Type type;
		ParcelData val;

	public:
	};*/

	class Parcel
	{
		void query(prID &out, prID param = nullptr);
	};

	typedef std::shared_ptr<Parcel*> spParcel;

	class ParcelParser
	{
		Parcel* parse(prID data);
	};

	class ParcelStaticParser
	{
		spParcel parse(prID data);
	};
}