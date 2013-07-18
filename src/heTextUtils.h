//
//  heTextUtils.h
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/18/13.
//
//

#ifndef __StartupsViz__heTextUtils__
#define __StartupsViz__heTextUtils__

#include <iostream>
#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

string wrapString(string text, int width, ofxTrueTypeFontUC* font);

void heDrawBitmapStringHighlight(string text, int x, int y, const ofColor& background = ofColor::black, const ofColor& foreground = ofColor::white);

#endif /* defined(__StartupsViz__heTextUtils__) */
