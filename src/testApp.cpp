#include "testApp.h"

//--------------------------------------------------------------

static const int red = 0xE74C3C;

void testApp::setup(){
    
    ofSetVerticalSync(true);
    //ofBackground(255,255,255);
    verdana30.loadFont("verdana.ttf", 8, true, true);
    verdana30.setLineHeight(18);
	verdana30.setLetterSpacing(1.035);
    
    ofEnableSmoothing();
    
    titleX = 20;
    titleY = 40;
    
    
    company = "";
    
    
   
    
    cam.setNearClip(0.1);
    cam.setFarClip(100);
    
    cam.setPosition(ofVec3f(1,0,5));
    
    ofEnableAlphaBlending();
    
//    loadData("facebook");
//    loadData("twitter");

    
//    loadFeed();
    
    notify("[E: Compare by Employee Size], [$: Compare by $]");
    
    //loadData("google");
    //loadData("comcast");
    
    tl.begin(1, 1, 2007);
    tl.end(10, 10, 2013);
    

    tl.setup();
    
    
}


//--------------------------------------------------------------
void testApp::update(){
    
    tl.x = 0;
    tl.y = ofGetWindowHeight()/2;
    tl.width = ofGetWindowWidth();
    tl.height = 1;
    tl.update();
    
    for(int i=0; i<companies.size(); i++){
        companies[i]->update();
    }
    
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
    
    
    
    
    for(int i=0; i<companies.size(); i++){
        
        int ii = companies.size()-i-1;
        ofColor c0;
        
        c0.setHsb(companies[ii]->hue, 200, 100);
        
        ofDrawBitmapStringHighlight(companies[ii]->name, 20 , 80 + i * 22 , c0 );
        
        companies[ii]->draw();
    }
    
    
    if(isStacked == false){
        tl.draw();
    }

    
    ofSetHexColor(0xDCDCDC);
    
    
    ofDrawBitmapStringHighlight(company, ofPoint(titleX, titleY));
    ofSetHexColor(0xEFF3F3);
    
    if(notifyString.size() > 0){
        ofDrawBitmapStringHighlight(notifyString, ofPoint(0, ofGetWindowHeight()-20), ofColor(236, 240, 241), ofColor::black);
    }
    
    int nowTitleX = ofGetWindowWidth()- STORY_ITEM_WIDTH -20;
    int nowTitleY = 20;
    ofRectangle rect;
    
    
    
    if(true){
        for(int i=0; i<feedItems.size(); i++){
            
            nowTitleY = rect.getBottom()+40;
            
            rect = verdana30.getStringBoundingBox(feedItems[i].title, nowTitleX, nowTitleY);
            
            ofSetHexColor(0x000000);
            rect.x = rect.x-10;
            rect.width = 425;
            rect.y -=5;
            rect.height +=10;
            
            ofRect(rect);
            ofSetColor(ofColor::white);
            verdana30.drawString(feedItems[i].title, nowTitleX, nowTitleY);
        }
    }
    
    
    
}

void testApp::renderOnTimeline(heCompany* co){
    vector<Milestone> stories = co->newsItems;
    //tl.milestones.clear();
    for(int i=0; i<stories.size(); i++){
        Milestone m = stories[i];
        tl.addMilestone(m);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (glutGetModifiers() ==  GLUT_ACTIVE_CTRL) {
        
        cout << key << endl;
        
        if(key == 4){
            // clear all
            for(int i=0; i<companies.size(); i++){
                deleteCompany(companies[i]);
            }
            tl.milestones.clear();
        }
        
        if(key == 19){
            for(int i=0; i<companies.size(); i++){
                if(isStacked==false){
                    cout << "stacking" << endl;
                    companies[i]->doStack(true);
                    companies[i]->stackAt(max( (float)100.0, ofRandom(ofGetWindowWidth()-200)), max((float)300, ofRandom(ofGetWindowHeight()-200)));
                }
                else{
                    cout << "unstacking "<< endl;
                    companies[i]->setXBasedOnTimeline(tl);
                }
                isStacked = !isStacked;
            }
        }
        
        if(strncmp((char*)&key, "D", 1)==0){
            if(currentlySelectedCompany != 0) deleteCompany(currentlySelectedCompany);
        }
        
        else if(strncmp((char*)&key, "E", 1)==0){
            setRadiiBasedOnEmployeeCount();
        }
        
        else if(strncmp((char*)&key, "$", 1)==0){
            setRadiiBasedOnInvestment();
        }
        return;
    }
    
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

//---------------------------------------------------------------
string testApp::stripQuotes(string s){
    
    char quote = '"';
    
    if(s.at(0)==quote){
        return s.substr(1, s.find_last_of('"')-1);
    }
    return s;
    
}

//--------------------------------------------------------------

void testApp::loadFeed(){
    string url = "http://localhost/~amathu001/helios/feed.js";
    ofxJSONElement json;
	bool gotJson = json.open(url);
    
    feedItems.reserve(json["items"].size());
    heRSSItem item;
    
    if(gotJson){
        for(int i=0; i<json["items"].size(); i++)
        {
            item.title =  json["items"][i]["title"].asString();
            item.title = wrapString(item.title, STORY_ITEM_WIDTH, &verdana30);
            item.desc = json["items"][i]["desc"].asString();
            item.startups = json["items"][i]["startups"].asString();
            
            loadData(item.startups);
            
            feedItems.push_back(item);
            
        }
    }
}

//---------------------------------------------------------------

void testApp::loadData(string s){
    string api_key = "rwdd2u4dk4gu8ppwb6e8xgxj";
    //string url = "http://api.crunchbase.com/v/1/company/"+s+".js?api_key="+api_key;
    
    string url = "http://ec2-107-21-104-179.compute-1.amazonaws.com/v/1/company/"+s+".js?api_key="+api_key;
    ofxJSONElement json;
	bool gotJson = json.open(url);
    
    
	if ( gotJson )
    {
        string nme = ofToString(json["name"]);
        string null = "null";
        if (nme.find(null, 0) != string::npos) {
            notify("Could not find company: "+company);
            return;
        }
        else{
            company = ""; // if success, clear the textfield
            notifyString = "";
        }

        heCompany* c = new heCompany();
        
        float rand = ofRandom(5000, 10000);
//        vector<float> d (10,rand);
//        c->setData(d);
        vector<float> xs (10,0);

//        c->setData(d); // vector of values
        c->setXs(xs);  // vector of x positions (global)
        c->doStack(true); // stack rings or not

        c->name = stripQuotes(nme);
        c->money_raised = ofToString(json["total_money_raised"]);
        c->dollarValue = convertToNumber(c->money_raised);
        c->index = companies.size();

        
        
        c->fundingRounds.reserve(json["funding_rounds"].size());
        FundingRound r;
        for(int i=0; i<json["funding_rounds"].size(); i++){
            r.sourceDescription = json["funding_rounds"][i]["source_description"].asString();
            r.raisedAmount = json["funding_rounds"][i]["raised_amount"].asInt();
            r.funded_day = json["funding_rounds"][i]["funded_day"].asInt();
            r.funded_month = json["funding_rounds"][i]["funded_month"].asInt();
            r.funded_year = json["funding_rounds"][i]["funded_year"].asInt();
            
            if(r.raisedAmount> 0){
                r.raisedAmount = r.raisedAmount/1000;
            }
            c->fundingRounds.push_back(r);
        }
        
        c->setRadiiBasedOnInvestment();
        c->setXBasedOnTimeline(tl);
        
        Milestone item;
        for(int i=0; i< json["milestones"].size(); i++){
            item.title = json["milestones"][i]["description"].asString();
            item.year = json["milestones"][i]["stoned_year"].asInt();
            item.month = json["milestones"][i]["stoned_month"].asInt();
            item.day = json["milestones"][i]["stoned_day"].asInt();
            
            item.color.setHsb(c->hue, 200, 100);
            
            c->newsItems.push_back(item);
            
            
        }
        
        string numEmp = stripQuotes(ofToString(json["number_of_employees"]));
        if (numEmp.find(null, 0) != string::npos) {
            c->numberOfEmployees = -1;
        }
        else{
            c->numberOfEmployees = atoi(numEmp.c_str());
            cout << "Company: " << c->name << ",  count: " << c->numberOfEmployees;
        }
        
        
        //c.startAt(0, 0);
        
        companies.push_back(c);
       // drawables.push_back(c);
        
        heCompany* hec = companies[companies.size()-1];
        
        //hec->startAt(max( (float)100.0, ofRandom(ofGetWindowWidth()-200)), max((float)300, ofRandom(ofGetWindowHeight()-200)));
        
        ofAddListener(hec->clickedInside , this, &testApp::onClickInsideCompanyCircle);
        setRadiiBasedOnInvestment();
        
        renderOnTimeline(c);
        
        
    } else {
        cout  << "Failed to parse JSON\n" << json.getRawString() << endl;
        notify("Failed to parse JSON"+company);
	}
}

//---------------------------------------------------------------

void testApp::notify(string s){
    notifyString  = s;
}

//---------------------------------------------------------------


void testApp::setRadiiBasedOnEmployeeCount(){
    int smallest= 10000000;
    int largest = 0;
    
    float maxRad = max((float)120, (float)400/companies.size());
    
    for(int i=0; i< companies.size(); i++){
        int value = companies[i]->numberOfEmployees;
        if(value == -1) continue;
        
        if(value > largest){
            largest = value;
        }
        if(value < smallest){
            smallest = value;
        }
        
    }
    
    float mult = 1.0;
    
    if(smallest == largest){
        mult = -1;
    }
    else{
        mult = maxRad/largest;
    }
    
    
    
    for(int i=0; i< companies.size(); i++){
        
        if(mult == -1){
            companies[i]->radius = maxRad;
        }
        else{
            companies[i]->radius = max(10, (int)(companies[i]->numberOfEmployees * mult));
            //cout << companies[i]->name << " - radius: " << companies[i]->radius << " (max rad: "<< maxRad <<", mult: "<< mult <<" )" << endl;
            
        }
        
    }
}

//---------------------------------------------------------------

void testApp::setRadiiBasedOnInvestment(){
    
    double smallest=convertToNumber("\"$10B\"");
    double largest = 0;
    
    int maxRad = max((float)120, (float)400/companies.size());
    
    for(int i=0; i< companies.size(); i++){
        double value = companies[i]->dollarValue;
        
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
            companies[i]->radius = maxRad;
        }
        else{
            companies[i]->radius = max(10, (int)(companies[i]->dollarValue * mult));
        }
        
    }
    
}

//--------------------------------------------------------------

void testApp::onClickInsideCompanyCircle(heCompanyEvent & event){
    cout << "Click " << event.company->name;
    if(currentlySelectedCompany != 0){
        currentlySelectedCompany->isSelected = false;
    }
    
    currentlySelectedCompany = event.company;
    currentlySelectedCompany->isSelected = true;
    
    notify("[Options] Delete: D |   More Info: I");
}

//--------------------------------------------------------------

void testApp::deleteCompany(heCompany* company){
    for(int i=0; i<companies.size(); i++){
        
        if(strncmp(companies[i]->name.c_str(), company->name.c_str(), company->name.length())==0){
            delete companies[i];
            companies.erase(companies.begin()+i);
            
            cout << "Now showing: " << companies.size() << endl;
            setRadiiBasedOnInvestment();
            break;
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
    //TODO

    for(int i=0; i<companies.size(); i++){
        //companies[i]->viewToggle();
    }
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