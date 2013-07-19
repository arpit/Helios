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


void Timeline::draw(){
    ofSetColor(26, 188, 156, 100);
    ofSetLineWidth(2);
    ofRect(x, y-height/2, x+width, height);
    
    
    double beginning = beginDay+(beginMonth*30)+(beginYear*356);
    
        
    for(int i=0; i<milestones.size(); i++){
        Milestone m = milestones[i];
        double diff = differenceInDays(  milestones[i].day, milestones[i].month, milestones[i].year, beginDay, beginMonth, beginYear);
        
        double xpos = diff / daysPerPixel;
        int textYPos = y - height/2 - 20;
        
        ofDrawBitmapStringHighlight(milestones[i].title, xpos, textYPos);
        ofSetColor(127, 140, 141);
        ofSetLineWidth(1);
        
//        ofNoFill();
//        ofCurve(xpos+100, y-15, xpos, y, xpos, textYPos, xpos+100, textYPos+15);
//        ofFill();
                
        ofLine(xpos, y, xpos, textYPos);
        ofSetColor(ofColor::white);
        ofCircle(xpos, y, 5);
        
    }
}

void Timeline::addMilestone(Milestone ml){
    milestones.push_back(ml);
}

Timeline::~Timeline(){
    milestones.clear();
}




