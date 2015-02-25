#pragma once
#include "ofMain.h"

class wave
{
    public:
        //wave();
        void setup(float _offsetX, float _offsetY);
        void update();
        void draw();

        float xSin;
        float ySin;

        float offsetX;
        float offsetY;
        int r;
        int g;
        int b;
        float alpha;


    private:
};

