#include "testApp.h"
#include <string.h>

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
    
    titleX = 20;
    titleY = 40;
    
    company = "";
    
}

//--------------------------------------------------------------
void testApp::update(){
    
   
    
}

//--------------------------------------------------------------
void testApp::draw(){
   
    ofRectangle rect = verdana30.getStringBoundingBox(company, 0,0);
    ofSetColor(ofColor::black);
    ofRect(titleX+rect.x-5, titleY+rect.y-5, rect.width+10, rect.height+10);
    
    ofSetColor(ofColor::white);
    verdana30.drawString(company, titleX, titleY);
    
    ofSetHexColor(0xDCDCDC);
    
    ofEnableSmoothing();
    for(int i=0; i<companies.size(); i++){
        ofSetCircleResolution(100);
        companies[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		company = company.substr(0, company.length()-1);
	}
	else if(key == OF_KEY_RETURN ){
		loadData(company);
	}
    else{
        company.append(1, (char)key);
    }
    
}

//---private----------------------------------------------------

string stripQuotes(string s){
    
    char quote = '"';
    
    if(s.at(0)==quote){
        return s.substr(1, s.find_last_of('"')-1);
    }
    return s;
    
}

void testApp::loadData(string s){
    string api_key = "rwdd2u4dk4gu8ppwb6e8xgxj";
    string url = "http://api.crunchbase.com/v/1/company/"+s+".js?api_key="+api_key;
    ofxJSONElement json;
	bool gotJson = json.open(url);
    
    string test = ofToString(json["dfsfsdfsdfs"]);
    
	if ( gotJson )
    {
        cout << "Got data: \n: " << test;
        heCompany c;
        
        c.name = stripQuotes(ofToString(json["name"]));
        c.money_raised = ofToString(json["total_money_raised"]);
        c.index = companies.size();
        companies.push_back(c);
        
    } else {
        cout  << "Failed to parse JSON\n" << endl;
	}
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}