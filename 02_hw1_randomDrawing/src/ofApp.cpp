#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    brushOne.setup();
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

    brushColor = 1;

}

//--------------------------------------------------------------
void ofApp::update(){

    brushOne.update();
}
//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key==49){
        brushColor =1;
    }

    if(key==50){
    brushColor =2;
    }

    if(key==51){
    brushColor =3;
    }

    if(key==52){
    brushColor =4;
    }

    if(key==53){
    brushColor =5;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    if (brushColor == 1){
        ofSetColor(255,0,0,10);

    } else if
        (brushColor == 2){
        ofSetColor(0,255,0,10);
    } else if
        (brushColor == 3){
        ofSetColor(0,0,255,10);
    }else if
        (brushColor == 4){
        ofSetColor(255,255,0,10);
    }else if
        (brushColor == 5){
        ofSetColor(0,0,0,10);
    }

    brushOne.draw(ofGetMouseX(),ofGetMouseY());
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
