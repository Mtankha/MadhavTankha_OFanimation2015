#pragma once
#include "ofMain.h"

class firework
{
    public:


        firework(ofVec2f _pos);
        void resetForces();
        void applyForce(ofVec2f force);


        void update();
        void draw();

        ofVec2f pos, vel, acc;
        float lifespan;





    private:
};


