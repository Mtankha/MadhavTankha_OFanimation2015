#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gravity.set(0.0, 0.01);

}

//--------------------------------------------------------------
void ofApp::update(){



     for (int i = 0; i < fireworkList.size(); i++) {
         fireworkList[i].resetForces();
         fireworkList[i].applyForce(gravity);
         fireworkList[i].update();



         if(fireworkList[i].lifespan <= 0){

           fireworkList.erase(fireworkList.begin()+i);

           for (int i = 0; i < 5; i++) {
                firework myFirework(fireworkList[i].pos);
                fireworkList.push_back(myFirework);

                }




         };


     }

     while (fireworkList.size() > 1000) {
         fireworkList.erase(fireworkList.begin());
    }


}

//--------------------------------------------------------------
void ofApp::draw(){

     for (int i = 0; i < fireworkList.size(); i++) {
         fireworkList[i].draw();
     }


    ofSetColor(255,0,255);
    stringstream buf;
    buf << "Click to launch firework" << endl<<
      "Launch many fireworks" << endl;


    ofDrawBitmapString(buf.str(), 40, 40);

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

    firework myFirework(ofVec2f(x,y));

     fireworkList.push_back(myFirework);




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
