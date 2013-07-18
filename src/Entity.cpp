//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Entity.h"
#include "ofxJSONElement.h"


Entity::Entity(){

}

void Entity::setData( vector <float> _data ){
   data = _data;
    float total = 0;
    for (int j = 0; j < data.size(); j++) {
        total += data[j];
    }

    while (rings.size() < data.size()){
        rings.push_back(new Ring());
    }

    while (rings.size() > data.size()){
        //rings.push_back(new Ring());
        //TODO REMOVE
    }

    for (int j = 0; j < data.size(); j++) {
        rings[j]->_x = 0;
        rings[j]->_y = 0;
        rings[j]->_r1 = 100;
        rings[j]->_r2 = 200;
    }
}

void Entity::update() {
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->update();
    }
}

void Entity::draw() {
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->update();
    }


    //float lastRad = 0;
   /* float lastAmount = 0;
    for (int j = 0; j < fundingRounds.size(); j++) {
        float amount = .001* fundingRounds[j]["raised_amount"].asDouble();
        //cout << amount << endl;
        // A = Pi * r * r;

        float r1 = sqrtf( lastAmount / 3.1416 );
        float r2 = sqrtf( (lastAmount + amount) / 3.1416 ) -1;

        lastAmount = lastAmount + amount;
        ofColor color;
        color.fromHex(20, .5 );
        cout << j << " " << r2 << " " << fundingRounds[j]["round_code"].asString() << endl;
        if (  fundingRounds[j]["round_code"].asString() == "angel") {
            color.set(0, .5);
        }
        drawRing( x , y , r1 , r2 , color );
    }*/
}
       /*
void drawRing( float _x , float _y , float r1 , float r2 , ofColor color ){
    ofSetColor(0, 0, 0);
    ofPath path;

    path.setFillColor( color );
    path.setArcResolution(128);
    path.arc(_x , _y, r1, r1, 0, 360);
    path.arc(_x , _y, r2, r2, 0, 360);
    path.close();
    path.draw();

}

float lerp( float progress , float min , float max ){
    return min + (max-min)*progress;
}            */