//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __Ring_H_
#define __Ring_H_

#include <iostream>
#include "ofColor.h"


class Ring {
   public:
    Ring();

    ofColor color;
    float x,y,r1,r2;

    float _x,_y,_r1,_r2,_strength;

    void draw();
    void update();
};


#endif //__Ring_H_
