#pragma once
#include "ofMain.h"


class customCircle{
public:
    customCircle();
    void setup(ofVec2f _initPos, float _pct);
    void update(ofVec2f _mouse);
    void draw();
    void swap(ofVec2f _mouse);
    void colorChange();
    ofVec2f currentPos;


private:

    float pct;
    bool clickCounter;
    float size;

    //color
    float r, g, b;

};
