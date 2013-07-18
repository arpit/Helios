//
//  Link.cpp
//  StartupsViz
//
//  Created by Mendoza, Alberto on 7/17/13
//
//

#include "Link.h"

Link::Link(Node* _a , Node* _b , float _distance){
    strength = .05;
    a = _a;
    b = _b;
    distance = _distance;
}

/*
void Link::init( Node* _a , Node* _b , float _distance ){
    a = _a;
    b = _b;
    distance = _distance;
}
 */

void Link::update(){

    centerDistance = distance + a->radius + b->radius;

    angle = atan2(b->y-a->y, b->x-a->x);
    distanceDelta = sqrtf((b->x-a->x)*(b->x-a->x) + (b->y-a->y)*(b->y-a->y)) - centerDistance;
    
    fY = 0;
    fX = 0;

    strength = .05;
    
    fX = (cos(angle) * (distanceDelta) * strength)*.5;
    fY = (sin(angle) * (distanceDelta) * strength)*.5;
    
    a->forceX += fX;
    a->forceY += fY;
    b->forceX += -fX;
    b->forceY += -fY;
}


void Link::draw(){
    if((distanceDelta)>1){
        ofSetColor(255, 100, 100);
    }else if(distanceDelta<-1){
        ofSetColor(100, 255, 100);
    }else{
        ofSetColor(100, 100, 100);
    }
    ofLine(a->x, a->y, b->x, b->y);
    ofSetColor(0, 0, 0);
   // ofDrawBitmapString( ofToString(distanceDelta,2) + " " + ofToString(fY,2), (b->x + a->x)*.5 , (b->y + a->y)*.5);
}