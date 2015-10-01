//
//  ColorHelper.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 10/1/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"

namespace ccHelp {
    struct HSV
    {
        float h;
        float s;
        float v;
        
        inline HSV(float _h, float _s, float _v)
        : h(_h), s(_s), v(_v) {}
    };
    
    inline HSV RGBToHSV(cocos2d::Color3B c) {
        float r,g,b,h,s,v;
        r= c.r;
        g= c.g;
        b= c.b;
        float min = std::min(std::min(r, g), b );
        float max = std::max(std::max(r, g), b );
        
        v = max;
        float delta = max - min;
        if( max != 0 )
        {
            s = delta / max;        // s
        }
        else {
            // r = g = b = 0        // s = 0, v is undefined
            s = 0;
            h = -1;
            return HSV(h, s, 0);
        }
        if( r == max )
            h = ( g - b ) / delta;      // between yellow & magenta
        else if( g == max )
            h = 2 + ( b - r ) / delta;  // between cyan & yellow
        else
            h = 4 + ( r - g ) / delta;  // between magenta & cyan
        h *= 60;                // degrees
        if( h < 0 )
            h += 360;
//        if ( isNaN(h) )
//            h = 0;
        return HSV(h,s,v);
    }
    
    inline cocos2d::Color3B HSVToRGB(HSV hsv) {
        int i;
        float h,s,v,r,g,b;
        h= hsv.h;
        s= hsv.s;
        v= hsv.v;
        if(s == 0 ) {
            // achromatic (grey)
            r = g = b = v;
            return cocos2d::Color3B(r,g,b);
        }
        h /= 60;            // sector 0 to 5
        i = floorf( h );
        float f = h - i;          // factorial part of h
        float p = v * ( 1 - s );
        float q = v * ( 1 - s * f );
        float t = v * ( 1 - s * ( 1 - f ) );
        switch( i ) {
            case 0:
                r = v;
                g = t;
                b = p;
                break;
            case 1:
                r = q;
                g = v;
                b = p;
                break;
            case 2:
                r = p;
                g = v;
                b = t;
                break;
            case 3:
                r = p;
                g = q;
                b = v;
                break;
            case 4:
                r = t;
                g = p;
                b = v;
                break;
            default:        // case 5:
                r = v;
                g = p;
                b = q;
                break;
        }
        return cocos2d::Color3B(r, g, b);
    }
}