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
        Vec2 *vertices;
        prepareArcVertices(center, rad, beginAngle, endAngle, segments, vertices);
        drawNode->drawPoly(vertices, segments, true, color);
        
        CC_SAFE_DELETE_ARRAY(vertices);
    }
    
    void DrawNodeHelper::drawSolidArc(cocos2d::DrawNode *drawNode, cocos2d::Vec2 center, float rad, float beginAngle, float endAngle, uint segments, const cocos2d::Color4F &color)
    {
        Vec2 *vertices;
        prepareArcVertices(center, rad, beginAngle, endAngle, segments, vertices);
        drawNode->drawSolidPoly(vertices, segments, color);
        
        CC_SAFE_DELETE_ARRAY(vertices);
    }
    
    void DrawNodeHelper::prepareArcVertices(cocos2d::Vec2 center, float rad, float beginAngle, float endAngle, uint segments,
                                            Vec2 *&vertices)
    {
        const float arc = endAngle - beginAngle;
        const float coef = arc / (segments - 1);
        
        vertices = new (std::nothrow) Vec2[segments];
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
    }
}