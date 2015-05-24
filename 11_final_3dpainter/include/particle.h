
#pragma once

#include "ofMain.h"

class particle {
  public:
    particle();

    ofVec3f pos;
    ofVec3f vel;
    ofVec3f accel;
    float mass;

    void applyForce( ofVec3f force );
    void update();
    void draw();


    int brush;
    int opacity;

    bool colourtrigger;
    int blackWhite;
    int offsetmult;
    ofVec3f offset;
    float speed;
    float colour;
    float size;
    float alpha;
};


