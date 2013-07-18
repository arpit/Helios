//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Ring.h"
#include "ofColor.h"
#include "ofPath.h"
#include "ofGraphics.h"


Ring::Ring(){
    r1 = r2 = x = y = 0;
    _r1 = _r2 = _x = _y = 0;
}

float Ring::lerp( float progress , float min , float max ){
    return min + (max-min)*progress;
}

void Ring::update(){
    x = lerp(.1,x,_x);
    y = lerp(.1,y,_y);
    r1 = lerp(.1,r1,_r1);
    r2 = lerp(.1,r2,_r2);

}

void Ring::draw( ){
    if(r1>0.01 && abs(r1 - _r1)){
        ofPath path;
        path.setFillColor( color );
        path.setArcResolution(128);
        path.arc(x , y, r1, r1, 0, 360);
        path.arc(x , y, r2, r2, 0, 360);
        path.close();
        path.draw();
    }
}