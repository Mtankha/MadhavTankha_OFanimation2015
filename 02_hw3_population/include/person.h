#pragma once
#include "ofMain.h"

class person
{
    public:
        //person();
    void setup();
    void update();
    void draw();


    float size;
    float color;
    float movement;

    ofVec2f pos;

    int randomOffset;
    float direction;

    float ofxGaussian();
    float x;



    private:
};


