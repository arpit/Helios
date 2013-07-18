//
//  Node.cpp
//  StartupsViz
//
//  Created by Mendoza, Alberto on 7/17/13.
//
//

#include "Node.h"

Node::Node(float _x,float _y){
    x = _x;
    y = _y;

    radius = 10;

    forceX = 0;
    forceY = 0;
}

void Node::update(){
    float friction = .5;
    forceX *= friction;
    forceY *= friction;
    
    x += forceX;
    y += forceY;
}

void Node::draw(){
    ofSetHexColor(0x222222);
    ofCircle(x, y, radius);
}

