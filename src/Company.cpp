//
//  Company.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/15/13.
//
//

#include "Company.h"

heCompany::heCompany(){
    verdana30.loadFont("verdana.ttf", 12, true, true);
}

void heCompany::startAt(int x, int y){
    nowX = x;
    nowY = y;
}

void heCompany::setRadius(int r){
    radius = r;
}


void heCompany::drawSphere(int color){
    ofNoFill();
    ofSetColor(255, 255, 255);
    ofSphere(nowX, nowY, 0, 1);
}

void heCompany::draw(int color){
    ofSetColor(231, 76, 60, 100);
    ofCircle(nowX, nowY,  nowRadius);
    
    ofSetColor(ofColor::black);
    ofRectangle rect = verdana30.getStringBoundingBox(name, 0,0);
    
    verdana30.drawString(name, nowX-rect.width/2, nowY-rect.height/2+10);
    
    if(nowRadius < radius){
        nowRadius+=10;
    }
    
    if(nowRadius > radius){
        nowRadius-=10;
    }
    
}