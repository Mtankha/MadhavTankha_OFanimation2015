#pragma once
#include "ofMain.h"

class flowField
{
    public:
        flowField();

        void setup(float w, float h, float res);
        void setRandom(float scale);
        void setNoise();




        //detect force at particle pos
        ofVec2f getForceAt(float x, float y);


        void draw();


        //container
        vector<ofVec2f> field;


        int screenWidth;
        int screenHeight;


        int fieldWidth;
        int fieldHeight;


        float resolution;


        int totalFlows;




};

