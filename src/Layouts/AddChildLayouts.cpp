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
            string type;
            if (!p.get(type, 0, "type", nullptr))
                return;
            
            string name;
            if (!p.get(name, 1, "name", nullptr))
                return;
            
            type = Utils::tolower(type);
            auto ite = FACTORIES.find(type);
            if (ite == FACTORIES.end())
                return;
            
            Node *child = ite->second(p);
            if (!child)
                return;
            
            child->setName(name);
            
            int tag;
            if (p.get(tag, 3, "tag", nullptr))
            {
                child->setTag(tag);
            }
            
            root->addChild(child);
            GroupLayout::getInstance()->doLayout(child, p);
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
            string sprite;
            if (!p.get(sprite))
                return Sprite::create();
            
            return Sprite::create(sprite);
        };
        FACTORIES["sprite-frame"] = [](const Layout::Parameter &p) -> Sprite* {
            string sprite;
            if (!p.get(sprite))
                return nullptr;
            
            return Sprite::createWithSpriteFrameName(sprite);
        };
        
        FACTORIES["animation"] = [](const Layout::Parameter &p) -> Sprite* {
            string animName;
            if (!p.get(animName))
                return nullptr;
            
            Animation *anim = AnimationCache::getInstance()->getAnimation(animName);
            if (!anim)
                return nullptr;
            
            Sprite *sprite = Sprite::createWithSpriteFrame(anim->getFrames().front()->getSpriteFrame());
            sprite->runAction(RepeatForever::create(Animate::create(anim)));
            
            return sprite;
        };
        
        
        FACTORIES["button"] = [](const Layout::Parameter &p) {return ui::Button::create();};
        FACTORIES["image"] = [](const Layout::Parameter &p) {return ui::ImageView::create();};
        
        FACTORIES["label"] = [](const Layout::Parameter &p) {return Label::create();};
        FACTORIES["label-ttf"] = [](const Layout::Parameter &p) -> Node* {
            string font;
            if (!p.get(font, 0, "font", "f", nullptr))
                return nullptr;
            
            float fontSize;
            if (!p.get(fontSize, 1, "font-size", "fs", "size", "sz", "s", nullptr))
                return nullptr;
            
            Label *lbl = Label::createWithTTF("", font, fontSize);
            return lbl;
        };
        FACTORIES["label-bmf"] = [](const Layout::Parameter &p) -> Node* {
            string font;
            if (!p.get(font))
                return nullptr;
            
            Label *lbl = Label::createWithBMFont(font, "");
            return lbl;
        };
    }
    
    void regisAddChildLayouts()
    {
        GroupLayout::registerLayout("addchild", new AddChildLayout);
    }
}
