#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

    myCircles.setup(0, 0, 7, 80, 20);
    myCircles2.setup(0, 0, 3, 40, 40);
    myCircles3.setup(0, 0, 5, 50, 40);
    myCircles4.setup(0, 0, 5, 100, 20);

    for (int i =0; i<20; i++){

        bezierBrush tree;
        tree.setup(ofRandom(200));
        bezierList.push_back(tree);
    }


}

//--------------------------------------------------------------
void ofApp::update(){


    myCircles.update();
    myCircles2.update();
    myCircles3.update();
    myCircles4.update();

    for (int i =1; i<bezierList.size(); i++){


         bezierList[i].update();

    }


}

//--------------------------------------------------------------
void ofApp::draw(){

    myCircles.draw();


    myCircles4.draw();

    myCircles2.draw();
    myCircles3.draw();


    for (int i =1; i<bezierList.size(); i++){


         bezierList[i].draw();

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
