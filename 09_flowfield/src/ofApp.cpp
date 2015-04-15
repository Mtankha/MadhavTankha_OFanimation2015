#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    flowfield.setup(ofGetWidth(), ofGetHeight(), 20.0);
    //flowfield.setRandom(2.0);
    //flowfield.setNoise();


    for (int i = 0; i < 5000; i++) {
    particle myParticle;
    myParticle.setup();
    particles.push_back(myParticle);
    }



    bDrawField = false;
    bDrawBackground = true;
}

//--------------------------------------------------------------
void ofApp::update(){

    flowfield.setNoise();

    for (int i = 0; i < particles.size(); i++){
    particles[i].resetForces();

    //get the force of the flowfield at the particle position
    ofVec2f frc = flowfield.getForceAt(particles[i].pos.x, particles[i].pos.y);

    //apply force to the particle
    particles[i].applyForce(frc);
    particles[i].applyDampingForce(0.01);
    particles[i].update();

    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(0,0,255);
    if(bDrawBackground) ofBackground(0);
    if (bDrawField) flowfield.draw();




    for (int i = 0; i < particles.size(); i++){

        //(ofMap (x, 0, ofGetWidth(), 0, fieldWidth));
    float colorTemp =flowfield.getForceAt(particles[i].pos.x, particles[i].pos.y).x;
    float colorX =  ceil(ofMap(colorTemp, -0.005, 0.005, 0, 255));

    float colorTemp2 =flowfield.getForceAt(particles[i].pos.x, particles[i].pos.y).y;
    float colorY =  ceil(ofMap(colorTemp2, -0.005, 0.005, 0, 255));


    float size = 1;
    //float size = ceil(ofMap(colorTemp, -0.008, 0.008, 0.001, 3));

    ofSetColor(ofRandom(255),colorX, colorY);
    particles[i].draw(size);
    }


    ofSetColor(0,0,255);
    stringstream buf;
    buf << "Press 'f' to toggle flowfield draw" << endl <<
    "Press 'b' to toggle background draw" << endl;

    ofDrawBitmapString(buf.str(), 20, 20);



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            flowfield.setRandom(2.0);
            break;

        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
            break;


        default:
            break;

    }

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
