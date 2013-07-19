//
// Created by Mendoza, Alberto on 7/18/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Entity.h"
#include "heLerp.h"




Entity::Entity(){
    _totalRadius = 0;
    hue = ofRandom(255);

}

void Entity::setData( vector <float> _data ){
    data = _data;

    while (rings.size() < _data.size()){
        rings.push_back(new Ring());
    }
    for (int j = data.size()-1; j >= 0 ; j--) {
        rings[j]->color.setHsb(
            hue ,
            lerp( ((float)j)/data.size() , 200 , 100 ),
            lerp( ((float)j)/data.size() , 100 , 200 ),
            80
        );
    }
}


void Entity::viewToggle(){
      if(viewMode == 0){
          viewTimeLine();
      }else{
          viewConcentric();
      }
}

void Entity::viewConcentric(){   // 0
    viewMode = 0;
    usePhysics = false;
    float lastValue = 0;
    for (int j = data.size()-1; j >= 0 ; j--) {
        //rings[j]->_x = x;
        //rings[j]->_y = y;
        rings[j]->_r1 = sqrtf( (lastValue) / PI );
        rings[j]->_r2 = sqrtf( (data[j]+lastValue) / PI );
        rings[j]->_strength = lerp( ((float)j)/data.size() , .1 , .09 );


        lastValue += data[j];
    }

    _totalRadius = sqrtf( (lastValue) / PI );
}

void Entity::viewTimeLine(){     // 1
    viewMode = 1;
    usePhysics = false;
    for (int j = data.size()-1 ; j >= 0 ; j--) {
        rings[j]->_x = x + 100 * j;
        rings[j]->_y = y;

        rings[j]->_r1 = 0;
        rings[j]->_r2 = sqrtf( data[j] / PI );

        rings[j]->_strength = lerp( ((float)j)/data.size() , .1 , .09 );


    }
}



float Entity::getRadius(){
    return _totalRadius;
}

void Entity::applyForce( ofVec2f f ){
    force += f;
}

void Entity::applyGravity( float mag = 5 ){
    ofVec2f g;
    g.x = x - ofGetWindowWidth() * .5;
    g.y = y - ofGetWindowHeight() * .5;
    g.scale(-mag);
    applyForce(g);
}


void Entity::concentricUpdate(){
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->_x = x;
        rings[j]->_y = y;
        rings[j]->update();
    }
}

void Entity::timeLineUpdate(){
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->_x = x + 100 * (float)j;
        rings[j]->_y = y;
        rings[j]->update();
    }
}

void Entity::update() {

    if(usePhysics){ //physics
        applyGravity();

        float friction = .5;
        force *= friction;

        x += force.x;
        y += force.y;
    }else{

    }

    if(viewMode == 0){
        concentricUpdate();
    }else{
        timeLineUpdate();
    }

}

void Entity::draw() {
    for (int j = 0; j < rings.size(); j++) {
        rings[j]->draw();
    }
    //cout << "draw entity:" << rings.size() << endl;

}