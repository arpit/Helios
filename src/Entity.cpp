//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Entity.h"
#include "ofxJSONElement.h"


Entity::Entity( ofxJSONElement _data ){
    //data = _data;

    fundingRounds = _data["funding_rounds"];

}

void Entity::update() {
   x = 200;
   y = 200;
}

void Entity::draw() {
    //float lastRad = 0;
    float lastAmount = 0;
    for (int j = 0; j < fundingRounds.size(); j++) {
        float amount = .001* fundingRounds[j]["raised_amount"].asDouble();
        //cout << amount << endl;
        // A = Pi * r * r;

        float r1 = sqrtf( lastAmount / 3.1416 );
        float r2 = sqrtf( (lastAmount + amount) / 3.1416 ) -1;

        lastAmount = lastAmount + amount;
        int color = 0x5EADF2;
        //cout << j << " " << r2 << " " << fundingRounds[j]["round_code"].asString() << endl;
        if (  fundingRounds[j]["round_code"].asString() == "angel") {
            color = 0x7D8F9C;
        }
        drawRing( x , y , r1 , r2 , color );
    }
}

void Entity::drawRing( float _x , float _y , float r1 , float r2 , int color ){
    ofSetColor(0, 0, 0);
    ofPath path;
    ofColor c;
    c.set(0, 0, 0, 100);
    path.setFillColor( c );
    path.setArcResolution(128);
    path.arc(_x , _y, r1, r1, 0, 360);
    path.arc(_x , _y, r2, r2, 0, 360);
    path.close();
    path.draw();

}