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
    ofSetColor(ofColor::black);
    ofSetLineWidth(2);
    ofLine(x, y, x+width, y);
    
    
    double beginning = beginDay+(beginMonth*30)+(beginYear*356);
    
        
    ofSetColor(ofColor::red);
    
    for(int i=0; i<milestones.size(); i++){
        Milestone m = milestones[i];
        double diff = differenceInDays(  milestones[i].day, milestones[i].month, milestones[i].year, beginDay, beginMonth, beginYear);
        
        cout << "Milestone diff: " << diff;
        
        double xpos = diff / daysPerPixel;
        
        
        
        ofCircle(xpos, y, 5);
        
    }
}

void Timeline::addMilestone(Milestone ml){
    milestones.push_back(ml);
}

Timeline::~Timeline(){
    milestones.clear();
}




