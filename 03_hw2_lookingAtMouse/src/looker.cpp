#include "looker.h"


void looker::setup(){

    pos.set(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);


}

void looker::update(float _x, float _y){

    ofVec2f newPos;
    newPos.set(_x, _y);
    //pos = pos*0.97 + newPos* 0.03;


    ofVec2f diff;
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x);

    rot = ofRadToDeg(rot);


}


void looker::draw(){

    float x1 = 0;
    float y1 = -10;

    float x2 = 0;
    float y2 = 10;

    float x3 = 30;
    float y3=0;

    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(rot);
    ofSetColor(r,g,b);
    ofTriangle(x1, y1, x2, y2, x3, y3);
    ofPopMatrix();



}
