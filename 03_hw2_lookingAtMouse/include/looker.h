#pragma once
#include "ofMain.h"


class looker
{
    public:
        //looker();

        void setup();
        void update(float _x, float _y);
        void draw();

        int r;
        int b;
        int g;




    private:

        ofVec2f pos;
        float rot;




};

