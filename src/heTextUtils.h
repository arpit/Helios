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


static ofTrueTypeFont* verdana = 0;

string wrapString(string text, int width, ofxTrueTypeFontUC* font);

void drawHeighlightedTextInVerdana(string s, int x, int y);

void heDrawBitmapStringHighlight(string text, int x, int y, const ofColor& background = ofColor::black, const ofColor& foreground = ofColor::white);

#endif /* defined(__StartupsViz__heTextUtils__) */
