#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Def.h"
#include <string>
#include <map>
#include <memory>
#include <fstream>
#include "msgpack/msgpack.hpp"
#include "jsoncpp/serializor.hpp"

USING_NS_CC;
using std::string;
using std::map;
using std::unique_ptr;
using std::vector;

namespace ccHelp
{
	class CoordinateTransformer;

	class Utils
	{
	public:
		static void setNodeAnchorWithoutChangePosition
			(Node *target, CREF(Vec2) newAnchor);
		static Node* warpSpriteBySize(string sprName,  CREF(Size) size, int tag = 0);
        static Vec2 convertPosition(Node *n, Node *target);   
        
        template<class S>
		static Scene* createScene();
		static Scene* createScene(Node *scn);

		template<class T>
		static T* create(T *ref);
		template<class T>
		static T* createx(T *ref, std::function<bool(T*)> init);
		template<class T>
		static T* createnx(T *ref);

		template <class T>
		static void replaceInVector(std::vector<T> &vec, int i, const T& obj);
		static string format(const char *format, ...);
		template <class K, class V>
		static bool mapContains(const map<K, V>& m, CREF(K) key);
		template <class K, class V>
		static map<K, V> mkMap(uint n, ...);

		// read from resources
		static Data readResourceData(string fileName);
		// read from writeable path
		static Data readGameData(string fileName);
		// write to writeable path
		static bool writeGameData(string fileName, const char *data, uint len);
		// read from resources
		static bool readResourceJSON(string file, Json::Value &root);
		// read from writeable resources
		static bool readGameJSON(string file, Json::Value &root);
		// write to writeable path
		static bool writeGameJSON(CREF(string) file, const Json::Value &root);

		static unique_ptr<CoordinateTransformer> uiCoordTransform(float parentHeight);

		static void loadCustomFonts(CREF(vector<string>) fontFiles, CREF(vector<float>) = vector<float>());

		static void pauseRecursively(cocos2d::Node *node);
		static void resumeRecursively(cocos2d::Node *node);
		static bool isVisibleRecursively(const cocos2d::Node *node);
		static bool contains(const cocos2d::Node *node, CREF(Vec2) p);
		
		template <typename COLOR>
		static COLOR colorFromText(const std::string &text);

		template <typename K, typename V>
		static typename std::map<K, V>::iterator floorKey(std::map<K, V> &m, const K &k);

		static Json::Value jsonFromFile(const std::string &fileName);

		template <typename T, T DEFAULT = T()>
		static T deserialize(const std::string &fileName);

		static string tolower(const string &s);
		static string toupper(const string &s);
		static string trim(const string &s);
        
        static string enUSFormat(int d);

	private:
		static Vec2 anchorInPoint(const Node *node);
	};

	template <class T>
	void Utils::replaceInVector(std::vector<T> &vec, int i, const T& obj)
	{
		vec.data()[i] = obj;
	}

	template <class K, class V>
	bool Utils::mapContains(const map<K, V>& m, CREF(K) key)
	{
		return m.find(key) != m.cend();
	}

	template <class K, class V>
	map<K, V> Utils::mkMap(uint n, ...)
	{
		va_list args;
		va_start(args, n);

		map<K, V> ret;
		for (uint i = 0; i < n; ++i)
		{
			K key = (K) va_arg(args, K);
			V val = (K) va_arg(args, V);

			ret[key] = val;
		}

		va_end(args);

		return ret;
	}

	template<class S>
	Scene* Utils::createScene()
	{
		auto layer = S::create();
		Scene *scene = Scene::create();

		scene->addChild(layer);

		return scene;
	}

	template<class T>
	T* Utils::create(T *ref)
	{
		return CCH_CREATE(ref);
	}

	template<class T>
	T* Utils::createx(T *ref, std::function<bool(T*)> init)
	{
		if (!init(ref))
		{
			delete ref;
			return nullptr;
		}

		return ref;
	}

	template<class T>
	T* Utils::createnx(T *ref)
	{
		return CCH_NOT_INIT_CREATE(ref);
	}

	class CoordinateTransformer
	{
	public:
		PUREF(Vec2 transform(CREF(Vec2) p) const);
		Vec2 transform(CREF(float) x, CREF(float) y) const;
	};

	template <typename COLOR>
	COLOR Utils::colorFromText(const std::string &text)
	{
		std::string uText = toupper(text);

		if (uText == "WHITE")
		{
			return COLOR::WHITE;
		}
		else if (uText == "YELLOW")
		{
			return COLOR::YELLOW;
		}
		else if (uText == "BLUE")
		{
			return COLOR::BLUE;
		}
		else if (uText == "GREEN")
		{
			return COLOR::GREEN;
		}
		else if (uText == "RED")
		{
			return COLOR::RED;
		}
		else if (uText == "MAGENTA")
		{
			return COLOR::MAGENTA;
		}
		else if (uText == "BLACK")
		{
			return COLOR::BLACK;
		}
		else if (uText == "ORANGE")
		{
			return COLOR::ORANGE;
		}
		else if (uText == "GRAY")
		{
			return COLOR::GRAY;
		}

		//CCASSERT(false, cocos2d::StringUtils::format("Invalid color text: %s!", uText.c_str()).c_str());
		return COLOR::BLACK;
	}

	template <typename K, typename V>
	typename std::map<K, V>::iterator Utils::floorKey(std::map<K, V> &m, const K &k)
	{
		auto it = m.lower_bound(k);
		if (it == m.begin())
			return m.end();

		--it;
		return it;
	}

	template <typename T, T DEFAULT>
	T Utils::deserialize(const std::string &fileName)
	{
		Json::Value jv = jsonFromFile(fileName);
		if (!jv.isNull())
		{
			T t = DEFAULT;
			return Json::type::deserialize(jv, t);
		}

		return DEFAULT;
	}
}
