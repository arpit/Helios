//
//  timeline.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/18/13.
//
//

#include "timeline.h"


void Timeline::setup() {
    
}

void Timeline::update(){
    int days = differenceInDays(endDay, endMonth, endYear, beginDay, beginMonth, beginYear);
    daysPerPixel = (double)days /(double) width;
    
    
}

void Timeline::begin( int day, int month, int year ){
    beginDay = day;
    beginMonth = month;
    beginYear = year;
}
void Timeline::end(int day, int month, int year ){
    endDay = day;
    endMonth = month;
    endYear = year;
}

float Timeline::getXBasedOn(int day, int month, int year){
    double diff = differenceInDays(  day, month, year, beginDay, beginMonth, beginYear);
    return  (float)(diff / daysPerPixel);
}


void Timeline::draw(){
    ofSetColor(ofColor::white);
    ofRect(x, y-height/2, x+width, height);
    
    
    double beginning = beginDay+(beginMonth*30)+(beginYear*356);
    
    int textYPos = 50;
        
    for(int i=0; i<milestones.size(); i++){
        Milestone m = milestones[i];
        float xpos  = getXBasedOn( milestones[i].day, milestones[i].month, milestones[i].year);
        
        textYPos+=20;
        
        int tYPos;
        if(i%2==0){
            tYPos = y+textYPos;
        }
        else{
            tYPos = textYPos;
        }
        
        glPushMatrix();
            ofRectangle bounds;
            ofTranslate(xpos, tYPos);
            //glRotatef(-45, 0, 0, 1);
            ofSetColor(ofColor::black);
            //drawHeighlightedTextInVerdana(milestones[i].title, -20, 0);
            ofDrawBitmapStringHighlight(milestones[i].title, -20, 0, m.color);
        glPopMatrix();
        
        ofSetColor(127, 140, 141, 100);
        ofSetLineWidth(1);
        
//        ofNoFill();
//        ofCurve(xpos+100, y-15, xpos, y, xpos, textYPos, xpos+100, textYPos+15);
//        ofFill();
                
        ofLine(xpos, y, xpos, tYPos);
        ofSetColor(ofColor::white);
        ofCircle(xpos, y, 5);
        
        
    }
    for(int i=0; i<markers.size(); i++){
        int x = getXBasedOn(markers[i].day, markers[i].month, markers[i].year);
        ofDrawBitmapString(ofToString(markers[i].year), x, y+14);
    }
}

void Timeline::addMilestone(Milestone ml){
    milestones.push_back(ml);
}

void Timeline::addMarker(int day, int month, int year){
    Marker m;
    m.year = year;
    m.month = month;
    m.day = day;
    
    markers.push_back(m);
    
}

Timeline::~Timeline(){
    milestones.clear();
}




