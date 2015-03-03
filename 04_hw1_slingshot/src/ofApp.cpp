#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


    ofBackground(0);
    mover.setup(1.0);
    //slingForce.set(0,0.5);

}

//--------------------------------------------------------------
void ofApp::update(){



    mover.resetForces();
    mover.applyForce(slingForce*mover.mass);
    //mover.applyDampingForce(.01*mover.mass);
    mover.update();







}

//--------------------------------------------------------------
void ofApp::draw(){


    ofSetColor(200);
    mover.draw();


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


    mover.resetForces();
    slingForce.x = 0;
    slingForce.y = 0 ;
    mover.acc.set(0);
    mover.vel.set(0);

    mover.pos.x = ofGetMouseX();
    mover.pos.y = ofGetMouseY();

    slingForce.x = (ofGetMouseX() - ofGetPreviousMouseX() ) * 0.1 ;
    slingForce.y = (ofGetMouseY() - ofGetPreviousMouseY() ) * 0.1  ;


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
