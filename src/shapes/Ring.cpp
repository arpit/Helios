//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Ring.h"
#include "ofColor.h"
#include "ofPath.h"
#include "ofGraphics.h"
#include "heLerp.h"


Ring::Ring(){
    cout << "new ring" << endl;
    r1 = r2 = x = y = 0;
    _r1 = _r2 = _x = _y = 0;
    _strength = .1;
    //color.set(0, 0, 0, 50);
}



void Ring::update(){
    x = lerp(_strength,x,_x);
    y = lerp(_strength,y,_y);
    r1 = lerp(_strength,r1,_r1);
    r2 = lerp(_strength,r2,_r2);
   // cout << "update ring:" << _x << endl;

}

void Ring::draw( ){
        ofPath path;
        path.setFillColor( color );
        path.setArcResolution(64);
        path.arc(x , y, r1, r1, 0, 360);
        path.arc(x , y, r2, r2, 0, 360);
        path.close();
        path.draw();
}