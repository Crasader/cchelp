//
//  DrawNodeHelper.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#include "DrawNodeHelper.h"

USING_NS_CC;

namespace ccHelp {
    void DrawNodeHelper::drawArc(cocos2d::DrawNode *drawNode, cocos2d::Vec2 center, float rad, float beginAngle, float endAngle, uint segments, const cocos2d::Color4F &color)
    {
        const float arc = endAngle - beginAngle;
        const float coef = arc / (segments - 1);
        
        Vec2 *vertices = new (std::nothrow) Vec2[segments];
        if( ! vertices )
            return;
        
        for(unsigned int i = 0;i < segments; i++)
        {
            float rads = i*coef;
            GLfloat j = rad * cosf(rads + beginAngle) + center.x;
            GLfloat k = rad * sinf(rads + beginAngle) + center.y;
            
            vertices[i].x = j;
            vertices[i].y = k;
        }
        
        drawNode->drawSolidPoly(vertices, segments, color);
        
        CC_SAFE_DELETE_ARRAY(vertices);
    }
}