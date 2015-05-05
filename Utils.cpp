#include "Utils.h"
#include <string>
#include <cctype>
#include "2d/CCFontAtlasCache.h"

using namespace std;

namespace ccHelp
{
	void Utils::setNodeAnchorWithoutChangePosition(Node *target, CREF(Vec2) newAnchor)
	{
		const Node *parent = target->getParent();
		if (newAnchor != target->getAnchorPoint() && parent)
		{
			Vec2 worldPosBefore = target->convertToWorldSpace(Vec2::ZERO);
			Vec2 parentPosBefore = parent->convertToNodeSpace(worldPosBefore);
			target->setAnchorPoint(newAnchor);
			Vec2 worldPosAfter = target->convertToWorldSpace(Vec2::ZERO);
			Vec2 parentPosAfter = parent->convertToNodeSpace(worldPosAfter);
			target->setPosition(target->getPosition() + (parentPosBefore - parentPosAfter));
		}
	}

	Vec2 Utils::anchorInPoint(const Node *node)
	{
		return Vec2(node->getAnchorPoint().x * node->getContentSize().width,
			node->getAnchorPoint().y * node->getContentSize().height);
	}

	Node* Utils::warpSpriteBySize(string sprName, CREF(Size) size, int tag)
	{
		Sprite *sprite = Sprite::create(sprName);
		Size frameSize = sprite->getBoundingBox().size;
		sprite->setScaleX(size.width / frameSize.width);
		sprite->setScaleY(size.height / frameSize.height);
		sprite->setContentSize(size);
		sprite->setTag(tag);

		Node *node = Node::create();
		node->setContentSize(size);
		node->addChild(sprite);
		
		node->setAnchorPoint(sprite->getAnchorPoint());
		sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		
		return node;
	}

	Scene* Utils::createScene(Node *scn)
	{
		Scene *scene = Scene::create();
		scene->addChild(scn);

		return scene;
	}

#define MAX_LENGHT 1024
	string Utils::format(const char *format, ...)
	{
		static char buffer[MAX_LENGHT];

		va_list args;
		
		va_start(args, format);
		vsprintf(buffer, format, args);
		va_end(args);
		return string(buffer);
	}
#undef MAX_LENGTH

	Data Utils::readResourceData(string fileName)
	{
		return FileUtils::getInstance()->getDataFromFile(fileName);
	}

	Data Utils::readGameData(string fileName)
	{
		if (!fileName.size())
		{
			return Data::Null;
		}

		Data ret;
		unsigned char* buffer = nullptr;
		ssize_t size = 0;
		const char* mode = "rb";

		string fullPath = FileUtils::getInstance()->getWritablePath();
		fullPath += fileName;

		// Read the file from hardware
		FILE *fp = fopen(fullPath.c_str(), mode);
		if (!fp) return Data::Null;

		fseek(fp,0,SEEK_END);
		size = ftell(fp);
		fseek(fp,0,SEEK_SET);

		buffer = (unsigned char*)malloc(sizeof(unsigned char) * size);
		size = fread(buffer, sizeof(unsigned char), size, fp);
		fclose(fp);

		if (nullptr == buffer || 0 == size)
		{
			std::string msg = "Get data from file(";
			msg.append(fullPath).append(") failed!");
			CCLOG("%s", msg.c_str());
		}
		else
		{
			ret.fastSet(buffer, size);
		}

		return ret;
	}

	bool Utils::writeGameData(string fileName, const char *data, uint len)
	{
		string fullPath = FileUtils::getInstance()->getWritablePath();
		fullPath += fileName;

		FILE *file = fopen(fullPath.c_str(), "wb");
		if (file)
		{
			fwrite(data, sizeof(char), len, file);
			fclose(file);
			return true;
		}

		return false;
	}

	bool Utils::readResourceJSON(std::string filename, Json::Value &root)
	{
		Json::Reader reader;
		Data dat = readResourceData(filename);
		if (dat.getSize() > 0)
		{
			reader.parse((const char*) dat.getBytes(), (const char*) (dat.getBytes() + dat.getSize()), root, false);
			return true;
		}

		return false;
	}

	bool Utils::readGameJSON(std::string filename, Json::Value &root)
	{
		Json::Reader reader;
		Data dat = readGameData(filename);
		if (dat.getSize() > 0)
		{
			reader.parse((const char*) dat.getBytes(), (const char*) (dat.getBytes() + dat.getSize()), root, false);
			return true;
		}

		return false;
	}

	bool Utils::writeGameJSON(CREF(string) file, const Json::Value &root)
	{
		Json::FastWriter writer;
		string json = writer.write(root);
		return writeGameData(file, json.data(), json.size());
	}

	Vec2 CoordinateTransformer::transform(CREF(float) x, CREF(float) y) const
	{
		return this->transform(Vec2(x, y));
	}

	class UICoordinateTransformer : public CoordinateTransformer
	{
	public:
		UICoordinateTransformer(float parentHeight)
			: parentHeight(parentHeight) {}

		Vec2 transform(CREF(Vec2) p) const override
		{
			return Vec2(p.x, parentHeight - p.y);
		}
	private:
		float parentHeight;
	};

	unique_ptr<CoordinateTransformer> Utils::uiCoordTransform(float parentHeight)
	{
		return unique_ptr<CoordinateTransformer>(new UICoordinateTransformer(parentHeight));
	}

	void Utils::loadCustomFonts(CREF(vector<string>) fontFiles, CREF(vector<float>) fontSizes)
	{
		for (uint i = 0; i < fontFiles.size(); ++i)
		{
			float fSize = (fontSizes.size() > i)?fontSizes[i]:12.f;
			FontAtlasCache::getFontAtlasTTF(TTFConfig(fontFiles[i].c_str(), fSize, GlyphCollection::DYNAMIC));
		}
	}
	
	void Utils::pauseRecursively(cocos2d::Node *node)
	{
		if (!node)
			return;

		node->pause();
		for (auto *child : node->getChildren())
		{
			pauseRecursively(child);
		}
	}

	void Utils::resumeRecursively(cocos2d::Node *node)
	{
		if (!node)
			return;

		node->resume();
		for (auto *child : node->getChildren())
		{
			resumeRecursively(child);
		}
	}

	bool Utils::isVisibleRecursively(const cocos2d::Node *node)
	{
		if (!node)
			return true;

		if (!node->isVisible())
			return false;

		return isVisibleRecursively(node->getParent());
	}

	Json::Value Utils::jsonFromFile(const std::string &fileName)
	{
		static Json::Reader READER;

		string content = FileUtils::getInstance()->getStringFromFile(fileName);
		Json::Value j;

		READER.parse(content, j);
		return j;
	}

	string Utils::tolower(const string &s)
	{
		string lower(s);
		for (auto &c : lower) { c = std::tolower(c); }
		return lower;
	}

	string Utils::toupper(const string &s)
	{
		string upper(s);
		for (auto &c : upper) { c = std::toupper(c); }
		return upper;
	}

	string Utils::trim(const string &s)
	{
		string trim(s);
		trim.erase(0, trim.find_first_not_of(" \t"));
		trim.erase(trim.find_last_not_of(" \t") + 1);

		return trim;
	}

	bool Utils::contains(const cocos2d::Node *node, CREF(Vec2) p)
	{
		auto pp = p +node->getAnchorPointInPoints();
		auto np = node->getPosition();
		auto sz = node->getContentSize();
		return (pp.x >= np.x) &&
			(pp.y >= np.y) &&
			(pp.x < np.x + sz.width) &&
			(pp.y < np.y + sz.height);
	}
}