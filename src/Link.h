//
//  Link.h
//  StartupsViz
//
//  Created by Mendoza, Alberto on 7/17/13.
//
//

#ifndef __StartupsViz__Link__
#define __StartupsViz__Link__

#include <iostream>
#include "Node.h"
#include "ofMain.h"


class Link{
public:
    Link(Node* start , Node* end , float distance );

    Node* a;
    Node* b;
    
    float distance;
    float strength;
    
    void update();
    void draw();
    
   // void init( Node* start , Node* end , float distance );
    

private:
    float distanceDelta,angle,fX,fY;
    float centerDistance;
};

#endif /* defined(__StartupsViz__Link__) */
