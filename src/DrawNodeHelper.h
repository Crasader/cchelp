//
//  DrawNodeHelper.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "def.h"

namespace ccHelp {
    class DrawNodeHelper
    {
    public:
        static void drawSolidArc(cocos2d::DrawNode *drawNode,
                                 cocos2d::Vec2 center,
                                 float rad,
                                 float beginAngle,
                                 float endAngle,
                                 uint segments,
                                 const cocos2d::Color4F &color);
        static void drawArc(cocos2d::DrawNode *drawNode,
                            cocos2d::Vec2 center,
                            float rad,
                            float beginAngle,
                            float endAngle,
                            uint segments,
                            const cocos2d::Color4F &color);
        
    private:
        static void prepareArcVertices(cocos2d::Vec2 center,
                                       float rad,
                                       float beginAngle,
                                       float endAngle,
                                       uint segments,
                                       _out_ cocos2d::Vec2 *&vertices);
    };
}
