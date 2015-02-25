#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    myWave.setup(1,1);
    myWave2.setup(2,2);
    myWave3.setup(4,4);
    myWave4.setup(8,8);
    myWave5.setup(0.5,0.5);





}


//--------------------------------------------------------------
void ofApp::update(){

    myWave.update();
    myWave2.update();
    myWave3.update();
    myWave4.update();
    myWave5.update();

}

//--------------------------------------------------------------
void ofApp::draw(){



    myWave.draw();
    myWave2.draw();
    myWave3.draw();
    myWave4.draw();
    myWave5.draw();










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
