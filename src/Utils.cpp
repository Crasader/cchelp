#include "Utils.h"
#include <string>
#include <cctype>
#include <iomanip>
#include "2d/CCFontAtlasCache.h"

using namespace std;

namespace ccHelp
{
    void Utils::setCascadeOpacityAllChilds(cocos2d::Node *n, bool enabled)
    {
        n->setCascadeOpacityEnabled(enabled);
        for (auto *child : n->getChildren())
        {
            child->setCascadeOpacityEnabled(enabled);
        }
    }
    
    void Utils::setCascadeOpacityRecursively(cocos2d::Node *n, bool enabled)
    {
        if (!n)
            return;
        
        n->setCascadeOpacityEnabled(enabled);
        
        for (auto *child : n->getChildren())
        {
            Utils::setCascadeOpacityRecursively(child);
        }
    }
    
    void Utils::setCascadeColorRecursively(cocos2d::Node *n, bool enabled)
    {
        if (!n)
            return;
        
        n->setCascadeColorEnabled(enabled);
        
        for (auto *child : n->getChildren())
        {
            Utils::setCascadeColorRecursively(child);
        }
    }
    
    void Utils::swallowTouch(cocos2d::Node *n)
    {
        auto *touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = [](Touch *t, cocos2d::Event *e)
        {
            return true;
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, n);
    }
    
    void Utils::swallowTouchBB(cocos2d::Node *n)
    {
        auto *touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = [=](Touch *t, cocos2d::Event *e)
        {
            if (!n->getParent())
                return false;
            
            auto pos = n->getParent()->convertToNodeSpace(t->getLocation());
            return n->getBoundingBox().containsPoint(pos);
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, n);
    }
    
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
        if (scn->getName().empty())
        {
            scn->setName("main");
        }
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
	
    void Utils::iteChildRecursively(cocos2d::Node *node, const std::function<void (Node *)> &handler)
    {
        if (!node)
            return;
        
        handler(node);
        for (auto *child : node->getChildren())
        {
            iteChildRecursively(child, handler);
        }
    }
    
	void Utils::pauseRecursively(cocos2d::Node *node)
	{
        Utils::iteChildRecursively(node, [](Node *n){
            n->pause();
        });
	}

	void Utils::resumeRecursively(cocos2d::Node *node)
    {
        Utils::iteChildRecursively(node, [](Node *n){
            n->resume();
        });
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

		if (READER.parse(content, j))
            return j;
        
        log("Invalid json file: %s", fileName.c_str());
        return Json::Value::null;
	}
    
    Json::Value Utils::jsonFromVsson(const vsson::VSSObject &vsson)
    {
        Json::Value js;
        
        std::function<void(const string&,
                           const vsson::VSSValue &)> func = [&js](const string &name,
                                                                  const vsson::VSSValue &vssv)
        {
            js[name] = vssv.asString();
        };
        
        vsson.foreach(func);
        
        return js;
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
    
    string Utils::tocapitalize(const string &s)
    {
        string cap(s);
        for (auto &c : cap) { c = std::tolower(c); }
        if (cap.length() > 0)
        {
            cap[0] = std::toupper(cap[0]);
        }
        
        return cap;
    }

	string Utils::trim(const string &s)
	{
		string trim(s);
		trim.erase(0, trim.find_first_not_of(" \t"));
		trim.erase(trim.find_last_not_of(" \t") + 1);

		return trim;
	}
    
    string Utils::enUSFormat(long d)
    {
        std::string str = StringUtils::format("%ld", d);
        
        for (long i = str.length()-3; i > 0; i -= 3)
        {
            str.insert(i, ",");
        }
        
        return str;
    }
    
    string get_suffix(short nn3)
    {
        switch (nn3) {
            case 0:
                return "";
            case 1:
                return "K";
            case 2:
                return "M";
            case 3:
                return "B";
            case 4:
                return "T";
            default:
                break;
        }
        
        nn3 -= 5;
        
        ushort nrep = 2 + (nn3 / ('z' - 'a'));
        char c = 'a' + (nn3 % ('z' - 'a'));
        
        stringstream ss;
        while (nrep > 0) {
            ss<<c;
            --nrep;
        }
        
        return ss.str();
    }
    
    string Utils::collapse(double n)
    {
        static uint DIV = 100000;
        static double MAGIC_NUM = log(10) / DIV;
        
        stringstream ss;
        if (n < 0)
        {
            ss<<'-';
            n = abs(n);
        }
        
        double nc = log(n);
        nc /= MAGIC_NUM;
        uint nn = static_cast<uint>(round(nc));
        nn /= DIV;
        ushort nn3 = nn / 3;
        
        n /= pow(10, 3 * nn3);
        
        ss<<std::setiosflags(ios::fixed)<<std::setprecision((nn3>0?2:0))<<n<<get_suffix(nn3);
        
        return ss.str();
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
    
    Vec2 Utils::convertPosition(cocos2d::Node *n, cocos2d::Node *target)
    {
        if (!n->getParent())
            return n->getPosition();
        
        return target->convertToNodeSpace(n->getParent()->convertToWorldSpace(n->getPosition()));
    }
    
    ulong Utils::time()
    {
        return (ulong) std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    
    unsigned long long Utils::timeInMicros()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    
    unsigned long long Utils::timeInNanos()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    
    Label* Utils::showToast(const string &msg,
                            const string &ttf,
                            float fontSize,
                            const cocos2d::Color4B &textColor,
                            cocos2d::Node *parent,
                            std::function<void(Label *)> edit)
    {
        if (!parent)
        {
            parent = Director::getInstance()->getRunningScene();
            if (!parent)
                return nullptr;
        }
        
        Label *lbl = Label::createWithTTF(msg, ttf, fontSize);
        if (!lbl)
            return nullptr;
        
        lbl->setTextColor(textColor);
        lbl->setAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
        lbl->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        auto parentSize = parent->getContentSize();
        lbl->setPosition(parentSize.width * 0.5, parentSize.height * 0.2);
        
        if (edit)
        {
            edit(lbl);
        }
        
        lbl->setOpacity(0);
        auto *fadeIn = FadeIn::create(0.15);
        auto *moveUp = MoveBy::create(1.35, Vec2(0, parentSize.height * 0.25));
        auto *wait = DelayTime::create(0.35);
        auto *fadeOut = FadeOut::create(1.f);
        auto *combine = Spawn::create(moveUp, Sequence::create(wait, fadeOut, nullptr), nullptr);
        auto *seq = Sequence::create(fadeIn, combine, RemoveSelf::create(), nullptr);
        lbl->runAction(seq);
        
        parent->addChild(lbl);
        return lbl;
    }
    
    
    bool Utils::pnpoly(int nvert, const Vec2 *vert, const Vec2 &test)
    {
        int i, j, c = 0;
        for (i = 0, j = nvert-1; i < nvert; j = i++) {
            if ( ((vert[i].y>test.y) != (vert[j].y>test.y)) &&
                (test.x < (vert[j].x-vert[i].x) * (test.y-vert[i].y) / (vert[j].y-vert[i].y) + vert[i].x) )
                c = !c;
        }
        return c;
    }
}