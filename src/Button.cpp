//
//  Button.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/17/13.
//
//

#include "Button.h"

void heButton::setup(){
    font.loadFont("verdana.ttf", 12, true, true);
}


void heButton::draw(){
    ofSetHexColor(color);
    ofCircle(x, y, radius);
    
    ofSetColor(ofColor::black);
    ofRectangle rect = font.getStringBoundingBox(label, 0,0);
    font.drawString(label, x-rect.width/2, y-rect.height/2+10);
    
}


void heButton::mouseMoved(ofMouseEventArgs & args){}
void heButton::mouseDragged(ofMouseEventArgs & args){}
void heButton::mousePressed(ofMouseEventArgs & args){}
void heButton::mouseReleased(ofMouseEventArgs & args){
    
    if(inside(args.x, args.y)){
        ofNotifyEvent(buttonClicked, label, this);
    }
}

bool heButton::inside(float _x, float _y ){
    return (ofVec2f(_x, _y).distance(ofVec2f(x, y)) < radius);
}