#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"
#include "Company.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "Button.h"
#include <GLUT/glut.h>
#include "RSSItem.h"
#include "Entity.h"
#include "heTextUtils.h"
#include "ofxTrueTypeFontUC.h"
#include "timeline.h"
#include "MileStone.h"
#include "FundingRound.h"
#include "timeline.h"
class testApp : public ofBaseApp{
	public:
		
        ofxTrueTypeFontUC	verdana30;
    
        static const int STORY_ITEM_WIDTH = 420;
    
        string company;
        int nResults;
        float size;
    
        bool isStacked = false;
    
        int titleX;
        int titleY;
    
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
    
        double convertToNumber(string m);
    
    private:
    
        heCompany* currentlySelectedCompany = 0;
        vector<heRSSItem> feedItems;
    
        
    
        string notifyString;
        ofEasyCam cam;
        vector<heCompany*> companies;
        string stripQuotes(string s);
    
        void loadData(string s);
        void setRadiiBasedOnInvestment();
        void notify(string s);
        void onClickInsideCompanyCircle(heCompanyEvent & company);
    
        void deleteCompany(heCompany* company);
        void setRadiiBasedOnEmployeeCount();

        void loadFeed();
    
        Timeline tl;
    
        void renderOnTimeline(heCompany* co);
    
    void setXBasedOnTimeline(Timeline t);
    

};
