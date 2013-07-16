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

class heCompany{
    
public:
    string name;
    string money_raised;
    ofTrueTypeFont	verdana30;
    
    heCompany();
    
    int index;
    int nowX;
    int nowY;
    
    int radius;
    int nowRadius = 0;
    
    double dollarValue;
    
    void startAt(int x, int y);
    void setRadius(int r);
    void draw(int color);
    void drawSphere(int color);
};


#endif /* defined(__StartupsViz__Company__) */
