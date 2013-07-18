//
//  Button.h
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/17/13.
//
//

#ifndef __StartupsViz__Button__
#define __StartupsViz__Button__

#include <iostream>
#include "ofMain.h"
class heButton{
    
public:
    
    ofEvent<string> buttonClicked;
    
    string label;
    int color;
    int radius = 10;
    int x;
    int y;
    ofTrueTypeFont font;
    
    void setup();
    void draw();
    
    
    
    void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    
    bool inside(float _x, float _y );
};


#endif /* defined(__StartupsViz__Button__) */
