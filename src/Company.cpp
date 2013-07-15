//
//  Company.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/15/13.
//
//

#include "Company.h"

heCompany::heCompany(){
    verdana30.loadFont("verdana.ttf", 30, true, true);
}

void heCompany::draw(){
    ofSetHexColor(0xdedede);
    ofCircle((index+1) * 250, 400, 100);
    ofSetColor(ofColor::black);
    verdana30.drawString(name, (index+1)*200-100  , 400);
}