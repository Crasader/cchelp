#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Def.h"
#include <string>
#include <map>
#include <memory>
#include <fstream>
#include "msgpack/msgpack.hpp"
#include "jsoncpp/json2/json.h"

USING_NS_CC;
using std::string;
using std::map;
using std::unique_ptr;
using std::vector;

namespace ccHelp
{
	class CoordinateTransformer;

	class UtilX
	{
	public:
		static void setNodeAnchorWithoutChangePosition
			(Node *target, CREF(Vec2) newAnchor);
		static Node* warpSpriteBySize(string sprName,  CREF(Size) size, int tag = 0);
		template<class S>
		static Scene* createScene();
		static Scene* createScene(Node *scn);

		template<class T>
		static T* create(T *ref);
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
	private:
		static Vec2 anchorInPoint(const Node *node);
	};

	template <class T>
	void UtilX::replaceInVector(std::vector<T> &vec, int i, const T& obj)
	{
		vec.data()[i] = obj;
	}

	template <class K, class V>
	bool UtilX::mapContains(const map<K, V>& m, CREF(K) key)
	{
		return m.find(key) != m.cend();
	}

	template <class K, class V>
	map<K, V> UtilX::mkMap(uint n, ...)
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
	Scene* UtilX::createScene()
	{
		auto layer = S::create();
		Scene *scene = Scene::create();

		scene->addChild(layer);

		return scene;
	}

	template<class T>
	T* UtilX::create(T *ref)
	{
		return CCH_CREATE(ref);
	}

	template<class T>
	T* UtilX::createnx(T *ref)
	{
		return CCH_NOT_INIT_CREATE(ref);
	}

	class CoordinateTransformer
	{
	public:
		PUREF(Vec2 transform(CREF(Vec2) p) const);
		Vec2 transform(CREF(float) x, CREF(float) y) const;
	};
}
