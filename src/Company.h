//
//  Company.h
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/15/13.
//
//

#ifndef __StartupsViz__Company__
#define __StartupsViz__Company__

#include <iostream>
#include "ofMain.h"
#include "CompanyEvent.h"
#include "Entity.h"
#include "RSSItem.h"
#include "MileStone.h"
#include "FundingRound.h"
#include "timeline.h"

class heCompany : public Entity{
    
public:
    ofEvent<heCompanyEvent> clickedInside;
    
    string name;
    string money_raised;
    ofTrueTypeFont	verdana30;
    
    int index;
    int radius;
    int nowRadius = 0;
    
    bool isSelected = false;
    
    vector<float> info;
    vector<float> xpositions;
    
    
    float dollarValue;
    
    int numberOfEmployees;
    
    heCompany();
    ~heCompany();
    void startAt(int x, int y);
    void setRadius(int r);
    //void draw(int color);
    void drawSphere(int color);
    
    void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    
    
    
    bool inside(float _x, float _y );
   
    vector<Milestone> newsItems;
    vector<FundingRound> fundingRounds;
    
    void setRadiiBasedOnInvestment();
    void setXBasedOnTimeline(Timeline t);
    
    void stackAt(int x, int y);
    
    
};


#endif /* defined(__StartupsViz__Company__) */
