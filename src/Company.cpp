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

void heCompany::draw(int color){
    ofSetHexColor(color);
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