//
//  timeline.h
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/18/13.
//
//

#ifndef __StartupsViz__timeline__
#define __StartupsViz__timeline__

#include <iostream>
#include "DateUtils.h"
#include "ofMain.h"
#include "MileStone.h"
#include "heTextUtils.h"

class Timeline{

public:

    int beginDay;
    int beginMonth;
    int beginYear;
    
    double daysPerPixel;
    
    int x;
    int y;
    int width;
    int height;
    
    vector<Milestone> milestones;

    int endDay, endMonth, endYear;
    
    
    ~Timeline();
    
    void begin(int year, int month, int day);
    void end(int year, int month, int day);
    void setup();
    void update();
    void draw();
    void addMilestone(Milestone ml);
    float getXBasedOn(int day, int month, int year);
    
    
};

#endif /* defined(__StartupsViz__timeline__) */
