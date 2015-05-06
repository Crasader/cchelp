//
//  AddChildLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#include "LayoutRegistration.h"
#include "Utils.h"

namespace ccHelp {
    
    class AddChildLayout : public Layout
    {
    public:
        typedef function<Node*(const Layout::Parameter &p)> Factory;
        
    private:
        static hmap<string, Factory> FACTORIES;
        
    public:
        virtual void doLayout(Node *root, const Layout::Parameter &p) const override
        {
            if (p.isArray())
            {
                for (uint i = 0; i < p.size(); ++i)
                {
                    this->doLayout(root, p[i]);
                }
            }
            else if (p.isObject())
            {
                if (!p.isMember("type") || !p["type"].isString())
                    return;
                
                if (!p.isMember("name") || !p["name"].isString())
                    return;
                
                string type = Utils::tolower(p["type"].asString());
                auto ite = FACTORIES.find(type);
                if (ite == FACTORIES.end())
                    return;
                
                Node *child = ite->second(p);
                if (!child)
                    return;
                
                child->setName(p["name"].asString());
                
                if (p.isMember("tag") && p["tag"].isInt())
                {
                    child->setTag(p["tag"].asInt());
                }
                
                root->addChild(child);
            }
        }
        
    public:
        STATIC_CONSTRUCTOR_DECLARE(AddChildLayout);
    };
    
    hmap<string, AddChildLayout::Factory> AddChildLayout::FACTORIES;
    
    STATIC_CONSTRUCTOR_IMPL(AddChildLayout)
    {
        FACTORIES["node"] = [](const Layout::Parameter &p) {return Node::create();};
        FACTORIES["layer"] = [](const Layout::Parameter &p) {return Layer::create();};
        FACTORIES["layer_color"] = [](const Layout::Parameter &p) {return LayerColor::create();};
        
        FACTORIES["sprite"] = [](const Layout::Parameter &p) {
            if (!p.isMember("sprite") || !p["sprite"].isString())
                return Sprite::create();
            
            return Sprite::create(p["sprite"].asString());
        };
        FACTORIES["sprite-frame"] = [](const Layout::Parameter &p) -> Sprite* {
            if (!p.isMember("sprite") || !p["sprite"].isString())
                return nullptr;
            
            return Sprite::createWithSpriteFrameName(p["sprite"].asString());
        };
        
        
        FACTORIES["button"] = [](const Layout::Parameter &p) {return ui::Button::create();};
        
        FACTORIES["label"] = [](const Layout::Parameter &p) {return Label::create();};
        FACTORIES["label-ttf"] = [](const Layout::Parameter &p) -> Node* {
            if (!p.isMember("font") || !p["font"].isString())
                return nullptr;
            
            float fontSize;
            if (!LayoutHelper::asFloat(p["font-size"], fontSize))
                return nullptr;
            
            Label *lbl = Label::createWithTTF("", p["font"].asString(), fontSize);
            return lbl;
        };
        FACTORIES["label-bmf"] = [](const Layout::Parameter &p) -> Node* {
            if (!p.isMember("font") || !p["font"].isString())
                return nullptr;
            
            Label *lbl = Label::createWithBMFont(p["font"].asString(), "");
            return lbl;
        };
    }
    
    void regisAddChildLayouts()
    {
        GroupLayout::registerLayout("addchild", new AddChildLayout);
    }
}
