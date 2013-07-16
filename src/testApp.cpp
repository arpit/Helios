#include "testApp.h"

//--------------------------------------------------------------

static const int red = 0xE74C3C;

void testApp::setup(){
    
    ofSetVerticalSync(true);
    //ofBackground(255,255,255);
    verdana30.loadFont("verdana.ttf", 12, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
    
    titleX = 20;
    titleY = 40;
    val = 100;
    
    
    company = "";
    
    
   
    
    cam.setNearClip(0.1);
    cam.setFarClip(100);
    
    cam.setPosition(ofVec3f(1,0,5));
    
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
   
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    
    
    
//    cam.setPosition(ofVec3f(1,0,5.0));
//    cam.begin();
//   
//    cam.enableMouseInput();
//    
//    glPushMatrix();
//    
//    ofSetColor(255, 255, 255);
//    ofNoFill();
//    ofSphere(0, 0, 0, 1);
//
//        for(int i=0; i<companies.size(); i++){
//            companies[i].drawSphere(red);
//        }
//    
//    
//    
//    glPopMatrix();
//    cam.end();
    
    
    


    
    ofSetHexColor(0xDCDCDC);
    
    ofEnableSmoothing();
    
    for(int i=0; i<companies.size(); i++){
        ofSetCircleResolution(100);
        companies[i].draw(red);
    }
    
    ofDrawBitmapStringHighlight(company, ofPoint(titleX, titleY));
    
    ofSetHexColor(0xEFF3F3);
    
    if(notifyString.size() > 0){
        ofDrawBitmapStringHighlight(notifyString, ofPoint(0, ofGetWindowHeight()-20), ofColor(236, 240, 241), ofColor::black);
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

double testApp::convertToNumber(string in){
    string m = stripQuotes(in);
    const char* DOLLAR = "$";
    const char first_letter = m.at(0);
    if(strncmp(&first_letter, DOLLAR, 1)==0){
        m = m.substr(1, m.length());
    }
    
    const char last_letter = m.at(m.length()-1);
    
    const char* BILLION = "B";
    const char* MILLION = "M";
    
    double mult = 1;
    
    if(strncmp(&last_letter, BILLION, 1)==0){
        m = m.substr(0, m.length()-1);
        mult = 1000000000;
    }
   
    
    
    if(strncmp(&last_letter, MILLION, 1)==0){
        m = m.substr(0, m.length()-1);
        mult = 1000000;
    }
    
    return ((double)atof(m.c_str()) * mult);
}

string testApp::stripQuotes(string s){
    
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
    
    
	if ( gotJson )
    {
        
        string nme = ofToString(json["name"]);
        cout << nme.c_str() << "\n " << nme.empty();
        
        string null = "null";
        
        if (nme.find(null, 0) != string::npos) {
            notify("Could not find company: "+company);
            return;
        }
        else{
            notifyString = "";
        }
        
        
        
        
        heCompany c;
        
        c.name = stripQuotes(nme);
        c.money_raised = ofToString(json["total_money_raised"]);
        
        
        
        c.dollarValue = convertToNumber(c.money_raised);
        c.index = companies.size();
        
        
        //c.startAt((c.index+1)*200, 200);
        
        c.startAt(max( (float)100.0, ofRandom(ofGetWindowWidth()-200)), max((float)300, ofRandom(ofGetWindowHeight()-200)));
        
        
        //c.startAt(0, 0);
        
        companies.push_back(c);
        setRadiiBasedOnInvestment();
        
    } else {
        cout  << "Failed to parse JSON\n" << json.getRawString() << endl;
        notify("Failed to parse JSON"+company);
	}
}


void testApp::notify(string s){
    notifyString  = s;
}


void testApp::setRadiiBasedOnInvestment(){
    
    double smallest=convertToNumber("\"$10B\"");
    double largest = 0;
    
    int maxRad = max((float)120, (float)400/companies.size());
    
    for(int i=0; i< companies.size(); i++){
        double value = companies[i].dollarValue;
        
        if(value > largest){
            largest = value;
        }
        if(value < smallest){
            smallest = value;
        }
        
    }
    
    double mult;
    
    if(smallest == largest){
        mult = -1;
    }
    else{
        cout << "Largest: " << largest << ", smallest: " << smallest << "\n";
        mult = maxRad/largest;
    }
    
    
    
    for(int i=0; i< companies.size(); i++){
        
        if(mult == -1){
            companies[i].radius = maxRad;
        }
        else{
            companies[i].radius = max(10, (int)(companies[i].dollarValue * mult));
        }
        
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