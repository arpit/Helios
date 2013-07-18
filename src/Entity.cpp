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
   
    float total = 0;
    for (int j = 0; j < _data.size(); j++) {
        total += _data[j];
    }

    while (rings.size() < _data.size()){
        rings.push_back(new Ring());
    }


    float lastValue = 0;
    for (int j = 0; j < _data.size(); j++) {
        rings[j]->_x = x;
        rings[j]->_y = y;
        rings[j]->_r1 = sqrtf( (lastValue) / PI );
        rings[j]->_r2 = sqrtf( (_data[j]+lastValue) / PI ) -1;
        
        rings[j]->color.setHsb(ofRandom(255), 150, 220);
        
        lastValue += _data[j];
    }
}

void Entity::update() {
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->_x = x;
        rings[j]->_y = y;
        rings[j]->update();
    }
    
    //cout << "update entity:" << x << endl;
}

void Entity::draw() {
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->draw();
    }
    //cout << "draw entity:" << rings.size() << endl;

}