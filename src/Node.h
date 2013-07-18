//
//  Node.h
//  StartupsViz
//
//  Created by Mendoza, Alberto on 7/17/13.
//
//

#ifndef __StartupsViz__Node__
#define __StartupsViz__Node__

#include <iostream>
#include "ofMain.h"

class Node{
public:
    Node(float _x, float _y);

    float x;
    float y;
    float z;
    
    float color;
    float radius;
    
    string name;
    
    float forceX;
    float forceY;
    
    void update();
    void draw();
    


private:
    
};


#endif /* defined(__StartupsViz__Node__) */
