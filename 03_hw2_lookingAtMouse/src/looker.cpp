#include "looker.h"


void looker::setup(){

    pos.set(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
    int r = ofRandom(50,255);
    int g = ofRandom(50,255);
    int b = ofRandom(50,255);


}

void looker::update(float _x, float _y){

    ofVec2f newPos;
    newPos.set(_x, _y);
    pos = pos*0.97 + newPos* 0.03;


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

    ofTranslate(pos);
    ofRotate(rot);
    ofSetColor(r,g,b,255);
    ofTriangle(x1, y1, x2, y2, x3, y3);



}
