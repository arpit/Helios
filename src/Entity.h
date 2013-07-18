//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __Entity_H_
#define __Entity_H_

#include <iostream>
#include "ofxJSONElement.h"
#include "Drawable.h"


class Entity : public Drawable{
    ofxJSONElement data;

public:
    float x, y , z;

    Entity(ofxJSONElement _data);

    void update();

    void draw();

    ofxJSONElement fundingRounds;

    void drawRing(float _x, float _y, float r1, float r2 , int color);
};


#endif //__Entity_H_
