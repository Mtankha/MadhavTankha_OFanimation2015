#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);

    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

    timer = 0;
    paintToggle = false;
}

//--------------------------------------------------------------
void ofApp::update(){



    while (painterList.size() > 500) {
         painterList.erase(painterList.begin());
    }


    for (int i = 0; i < painterList.size(); i++) {
         painterList[i].update();
     }


if (paintToggle==true){

    timer++;

    if (timer>= 2){


    painter myPainter(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    painterList.push_back(myPainter);

    timer = 0;


    }

}



}

//--------------------------------------------------------------
void ofApp::draw(){



    for (int i = 0; i < painterList.size(); i++) {
         painterList[i].draw();
     }

    if(paintToggle == false){
    ofSetColor(0,0,255);
    stringstream buf;
    buf << "Press spacebar to start painting" << endl;


    ofDrawBitmapString(buf.str(), 40, 40);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    paintToggle = !paintToggle;

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){



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
