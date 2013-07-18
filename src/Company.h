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

class heCompany{
    
public:
    ofEvent<heCompanyEvent> clickedInside;
    
    string name;
    string money_raised;
    ofTrueTypeFont	verdana30;
    
    int index;
    int nowX;
    int nowY;
    int radius;
    int nowRadius = 0;
    
    bool isSelected = false;
    
    double dollarValue;
    
    
    heCompany();
    ~heCompany();
    void startAt(int x, int y);
    void setRadius(int r);
    void draw(int color);
    void drawSphere(int color);
    
    void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    
    bool inside(float _x, float _y );
    
};


#endif /* defined(__StartupsViz__Company__) */
