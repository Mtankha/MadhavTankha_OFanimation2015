#pragma once
#include "ofMain.h"


class Mover
{
    public:

        void setup(float _mass);
        void update();
        void resetForces();
        void applyForce(ofVec2f force);
        void applyDampingForce(float damping);
        void draw();

        ofVec2f pos, vel, acc;
        float mass;



    private:
};


