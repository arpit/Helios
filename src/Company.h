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
    
    void draw();
};


#endif /* defined(__StartupsViz__Company__) */
