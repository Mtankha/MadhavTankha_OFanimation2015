#pragma once
#include "ofMain.h"

class flowField
{
    public:
        flowField();

        void setup(float w, float h, float d, float res);
        void setRandom(float scale);
        void setNoise(float scale);
        void setNoise2(float scale);
        void setNoise3(float scale);

        //to be called from the particle, so it knows the force of the flow where it stands on
        ofVec3f getForceAt(ofVec3f pos);

        void update();
        void draw();

        //The size of the field in pixels, e.g. 1024x768
        int screenWidth;
        int screenHeight;
        int screenDepth;

        //The size of the field in number of flows, e.g. 52 x 40
        int fieldWidth;
        int fieldHeight;
        int fieldDepth;

        //What is the area covered by each flow, e.g. 20x20 pixels
        float resolution;

        //Total number of flows in a field
        int totalFlows;

        vector < vector< vector<ofVec3f> > > flowList;






};

