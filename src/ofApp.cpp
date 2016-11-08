#include "ofApp.h"

ofSerial	serial;
int			incoming[3];
int			nRead = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    mGravity = ofVec2f(0.f, 0.02f);
    
#ifdef SERIALLINUX
    serial.setup("/dev/ttyUSB0", 9600); //open the first device
#else
    serial.setup(0, 9600); //open the first device
#endif
    
    incoming[0] = incoming[1] = incoming[2] = -1;
    
    pos = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    vel = ofVec2f(0,0);
    acc = ofVec2f(0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for (int i = 0; i < mSystems.size(); i++){
        //apply gravity all particles
        mSystems[i].update(mGravity);
    }
    
    
    if(serial.available()>3){
        unsigned char incomingBytes[4];
        memset(incomingBytes, 0, 4);
        
        while ( (nRead = serial.readBytes(incomingBytes, 4)  > 0)) {
            
            string datastring = ofToString(incomingBytes);
            
            if(datastring.size()>3  && datastring.at(3) == ','){
                for(int i=0; i<3; i++) { incoming[i] = (int)  datastring.at(i); }
                serial.flush(); // should be used after sucessfull read? less weird packets
            } else {
                cout << "weird packet at frame " << ofGetFrameNum() << " : " << datastring << endl;
            }
            
            
        }
    }
    pos+=vel;
    if(pos.x<0||pos.x>ofGetWidth()) pos.x=ofGetWidth()/2;
    if(pos.y<0||pos.y>ofGetHeight()) pos.y=ofGetHeight()/2;
    vel+=acc;
    vel*=0.99;
    acc = ofVec2f(incoming[1]/200.f,incoming[2]/200.f);
}

//--------------------------------------------------------------


void ofApp::draw(){
    string info = "fps: "+ofToString(ofGetFrameRate())+"\n";
    info += "nRead: "+ofToString(nRead)+"\n";
    for(int i=0; i<3; i++) { info += ofToString(i)+"  :  " + ofToString(incoming[i])+"\n"; }
    ofSetColor(0);
    ofDrawBitmapString(info, 10, 10);
   
    for (int i = 0; i < mSystems.size(); i++){
        //draw particle systems
        mSystems[i].draw();
    }
    
    ParticleSystem system(pos+ofVec2f(ofRandom(-50,50),ofRandom(-50,50)));
    mSystems.push_back(system);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //create a new particle system after click
    ParticleSystem system(ofVec2f (x, y));
    mSystems.push_back(system);
    
    }

//-----------------------------------------0---------------------
void ofApp::mousePressed(int x, int y, int button){
//    //create a new particle system after click
//    ParticleSystem system(ofVec2f (x, y));
//    mSystems.push_back(system);

    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    //create a new particle system after click
//    ParticleSystem system(ofVec2f (x, y));
//    mSystems.push_back(system);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
