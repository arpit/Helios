//
//  Company.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/15/13.
//
//

#include "Company.h"


heCompany::heCompany():Entity(){
    verdana30.loadFont("verdana.ttf", 12, true, true);
}


heCompany::~heCompany(){
    ofUnregisterMouseEvents(this);
}

void heCompany::startAt(int _x, int _y){
    x = _x;
    y = _y;
    ofRegisterMouseEvents(this);
}


void heCompany::setRadius(int r){
    radius = r;
}


void heCompany::drawSphere(int color){
    ofNoFill();
    ofSetColor(255, 255, 255);
//    /ofSphere(nowX, nowY, 0, 1);
}

//void heCompany::draw(int color){
//    ofSetColor(231, 76, 60, 100);
//    int rad = nowRadius;
//    if(isSelected){
//        ofCircle(nowX, nowY,  rad);
//        rad-=10;
//    }
//    
//    ofCircle(nowX, nowY,  rad);
//    
//    
//    
//    ofSetColor(ofColor::black);
//    ofRectangle rect = verdana30.getStringBoundingBox(name, 0,0);
//    
//    verdana30.drawString(name, nowX-rect.width/2, nowY-rect.height/2+10);
//    
//    if(nowRadius < radius){
//        nowRadius+=10;
//    }
//    
//    if(nowRadius > radius){
//        nowRadius-=10;
//    }
//    
//}


void heCompany::setRadiiBasedOnInvestment(){
    for (int i=0; i<fundingRounds.size(); i++) {
        info.push_back((float)fundingRounds[i].raisedAmount);
    }
    setData(info);
}

void heCompany::setXBasedOnTimeline(Timeline t){
    for (int i=0; i<fundingRounds.size(); i++) {
        xpositions.push_back(t.getXBasedOn(fundingRounds[i].funded_day, fundingRounds[i].funded_month, fundingRounds[i].funded_year));
    }
    setXs(xpositions);
    y = t.y;
    doStack(false);

}

void heCompany::mouseMoved(ofMouseEventArgs & args){}
void heCompany::mouseDragged(ofMouseEventArgs & args){}
void heCompany::mousePressed(ofMouseEventArgs & args){}
void heCompany::mouseReleased(ofMouseEventArgs & args){
    
    if(inside(args.x, args.y)){
        ofVec2f mousePos = ofVec2f(args.x, args.y);
        heCompanyEvent event;
        event.company = this;
        ofNotifyEvent(clickedInside, event, this);
    }
}

bool heCompany::inside(float _x, float _y ){
    return (ofVec2f(_x, _y).distance(ofVec2f(x, y)) < nowRadius);
}