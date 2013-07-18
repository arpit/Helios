//
//  heTextUtils.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/18/13.
//
//

#include "heTextUtils.h"

string wrapString(string text, int width, ofxTrueTypeFontUC* font) {
    
    string typeWrapped = "";
    string tempString = "";
    vector <string> words = ofSplitString(text, " ");
    
    for(int i=0; i<words.size(); i++) {
        
        string wrd = words[i];
        cout << wrd << endl;
        
        tempString += wrd + " ";
        int stringwidth = font->stringWidth(tempString);
        if(stringwidth >= width) {
            tempString = "";
            typeWrapped += "\n";
        }
        
        typeWrapped += wrd + " ";
    }
    
    return typeWrapped;
    
}

void heDrawBitmapStringHighlight(string text, int x, int y, const ofColor& background, const ofColor& foreground) {
	vector<string> lines = ofSplitString(text, "\n");
	int maxLineLength = 0;
	for(int i = 0; i < lines.size(); i++) {
		// tabs are not rendered
		const string & line(lines[i]);
		int currentLineLength = 0;
		for(int j = 0; j < line.size(); j++) {
			if (line[j] == '\t') {
				currentLineLength += 8 - (currentLineLength % 8);
			} else {
				currentLineLength++;
			}
		}
		maxLineLength = MAX(maxLineLength, currentLineLength);
	}
	
	int padding = 4;
	int fontSize = 8;
	float leading = 1.7;
	int height = lines.size() * fontSize * leading - 1;
	
    
    int width = maxLineLength * fontSize;
    
    
	
	ofPushStyle();
	glDepthMask(false);
	ofSetColor(background);
	ofFill();
	ofPushMatrix();
	
//	if(currentStyle.drawBitmapMode == OF_BITMAPMODE_MODEL) {
//		ofTranslate(x,y,0);
//		ofScale(1,-1,0);
//		ofTranslate(-(padding), + padding - fontSize - 2,0);
//	} else {
		ofTranslate(x-(padding), y-(padding + fontSize + 2), 0);
		
//	}
	
	ofRect(0, 0, width + 2 * padding, height + 2 * padding);
	ofPopMatrix();
	ofSetColor(foreground);
	ofNoFill();
	ofDrawBitmapString(text, x, y);
	glDepthMask(true);
	ofPopStyle();
}