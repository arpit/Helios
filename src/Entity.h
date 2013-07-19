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
    void applyForce( ofVec2f f );
    void applyGravity( float mag );
    ofVec2f force;
    float x, y , z;
    Entity();
    void update();
    void draw();
    vector <Ring*> rings;
    void setData(vector<float> _data );
    float getRadius();
    void concentricUpdate();
    void timeLineUpdate();
    void viewTimeLine();
    void viewConcentric();
    void viewToggle();
private:
    float _totalRadius;



    vector<float> data;
    float hue;
    bool usePhysics;


    int viewMode;
};


#endif //__Entity_H_
