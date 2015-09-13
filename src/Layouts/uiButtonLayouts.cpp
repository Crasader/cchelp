//
//  uiButtonLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"
#include "WidgetUtils.h"
#include "ui/CocosGUI.h"

namespace ccHelp {
    struct _Button : public ui::Button
    {
        void setTitleRenderer(Label *lbl)
        {
            if (!lbl)
                return;
            
            if (_titleRenderer)
                _titleRenderer->removeFromParent();
            
            if (lbl->getParent() != this)
            {
                lbl->removeFromParent();
                this->addProtectedChild(lbl);
            }
            
            this->_titleRenderer = lbl;
        }
        
        Node *getNormalRenderer()
        {
            return _buttonNormalRenderer;
        }
    };
    
    void regisButtonLayouts()
    {
        auto *titleText = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string title;
            if (p.get(title))
            {
                if (ui::Button *btn = dynamic_cast<ui::Button*>(n))
                {
                    btn->setTitleText(title);
                }
            }
        });
        GroupLayout::registerLayout("button-title-text", titleText);
        
        
        auto *titleFontSize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float fontSize = 12;
            if (p.get(fontSize))
            {
                if (ui::Button *btn = dynamic_cast<ui::Button*>(n))
                {
                    btn->setTitleFontSize(fontSize);
                }
            }
        });
        GroupLayout::registerLayout("button-title-size", titleFontSize);
        
        auto *titleFontName = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string font;
            if (p.get(font))
            {
                if (ui::Button *btn = dynamic_cast<ui::Button*>(n))
                {
                    btn->setTitleFontName(font);
                }
            }
        });
        GroupLayout::registerLayout("button-title-font", titleFontName);
        
        
        auto *titleColor = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return;
            
            Color3B c;
            if (!LayoutHelper::asColor3(p, c))
                return;
            
            btn->setTitleColor(c);
        });
        GroupLayout::registerLayout("button-title-color", titleColor);
        
        auto *loadNormalTexture = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return;
            
            string texture;
            if (p.get(texture, 0, "texture", "tex", nullptr))
            {
                auto resType = ui::TextureResType::LOCAL;
                string res;
                if (p.get(res, 1, "res-type", "res", nullptr))
                {
                    LayoutHelper::asUIResType(res, resType);
                }
                
                btn->loadTextureNormal(texture, resType);
            }
        });
        GroupLayout::registerLayout("button-normal", loadNormalTexture);
        
        
        auto *loadPressedTexture = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return;
            
            string texture;
            if (p.get(texture, 0, "texture", "tex", nullptr))
            {
                auto resType = ui::TextureResType::LOCAL;
                string res;
                if (p.get(res, 1, "res-type", "res", nullptr))
                {
                    LayoutHelper::asUIResType(res, resType);
                }
                
                btn->loadTexturePressed(texture, resType);
            }
        });
        GroupLayout::registerLayout("button-pressed", loadPressedTexture);
        
        auto *loadDisabledTexture = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return;
            
            string texture;
            if (p.get(texture, 0, "texture", "tex", nullptr))
            {
                auto resType = ui::TextureResType::LOCAL;
                string res;
                if (p.get(res, 1, "res-type", "res", nullptr))
                {
                    LayoutHelper::asUIResType(res, resType);
                }
                
                btn->loadTextureDisabled(texture, resType);
            }
        });
        GroupLayout::registerLayout("button-disabled", loadDisabledTexture);

        auto *pressedEnabled = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            bool isEnabled = false;
            if (!p.get(isEnabled))
                return;
            
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return;
            
            btn->setPressedActionEnabled(isEnabled);
        });
        GroupLayout::registerLayout("button-pressed-enabled", pressedEnabled);
        
        auto *setZoomScale = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float zoomScale = 1;
            if (!LayoutHelper::asFloat(p, zoomScale))
                return;
            
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return;
            
            btn->setZoomScale(zoomScale);
        });
        GroupLayout::registerLayout("button-zoom-scale", setZoomScale);
    }
    
    void regisButtonQueries()
    {
        LayoutHelper::putQuery("@button-normal", [](Node *n) -> Node* {
            ui::Button *btn = dynamic_cast<ui::Button*>(n);
            if (!btn)
                return nullptr;
            
            return ((_Button *) btn)->getNormalRenderer();
        });
    }
}