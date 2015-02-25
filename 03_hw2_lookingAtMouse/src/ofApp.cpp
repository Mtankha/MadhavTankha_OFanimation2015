#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (float i = 0; i<100; i++){

        looker myLooker;
        myLooker.setup();
        lookerList.push_back(myLooker);
    }
}

//--------------------------------------------------------------
void ofApp::update(){


     for (int i = 0; i<lookerList.size(); i++){
        lookerList[i].update(ofGetMouseX(), ofGetMouseY());

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
     for (int i = 0; i<lookerList.size(); i++){
        lookerList[i].draw();

    }
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
