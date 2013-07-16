#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"
#include "Company.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        ofTrueTypeFont	verdana30;
        string company;
    
    
        int nResults;
        float size;
        
        int titleX;
        int titleY;
    
        double convertToNumber(string m);
    
    private:
    
        string notifyString;
    
        void loadData(string s);
        vector<heCompany> companies;
        void setRadiiBasedOnInvestment();
        string stripQuotes(string s);
        void notify(string s);
};
