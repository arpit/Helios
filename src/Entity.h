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
#include "Ring.h"


class Entity : public Drawable{
    

public:
    Entity();

    void applyForce( ofVec2f f );
    void applyGravity( float mag );
    ofVec2f force;
    float x, y , z;

    void update();
    void draw();

    void setXs( vector <float> _xs );
    void setData(vector<float> _data );
    void doStack(bool stk);
    float hue;  // 0-255 is set randomly after setData. Can be overwritten here.

    bool isStacked();
    
private:
    bool _doStack;
    vector <Ring*> rings;
    vector<float> data, xs;
    bool usePhysics;

};


#endif //__Entity_H_
