#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    for(int i=0; i<circleNumber; i++)
    {
        myCircle[i].setup(ofVec2f(0,500), 0.005*(i+1));
    }



    ofSetBackgroundAuto(false);
    ofBackground(0,0,0);
    ofSetFrameRate(150);
    //pct = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

    myCircle[0].update(ofVec2f(ofGetMouseX(),ofGetMouseY()));

    for(int i=0; i<circleNumber; i++)
    {
        myCircle[i+1].update(ofVec2f(myCircle[i].currentPos));
    }



}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0,20);
    ofRect(0,0,ofGetWidth(),ofGetHeight());



    for(int i=0; i<circleNumber; i++)
    {
    myCircle[i].draw();
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
        //myCircle.swap(ofVec2f(ofGetMouseX(),ofGetMouseY()));


    for(int i=0; i<circleNumber; i++)
    {
        myCircle[i].colorChange();
    }


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
