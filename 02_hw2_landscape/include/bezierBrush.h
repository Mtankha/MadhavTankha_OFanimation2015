#pragma once
#include "ofMain.h"

class bezierBrush
{
    public:
        //bezierBrush();
        void setup(float _size);
        void update();
        void draw();

        float size;
        float offset1;
        float offset2;
        float offset3;

        float noiseX;
        float noiseY;
        float noiseX2;
        float noiseY2;
        float noiseX3;
        float noiseY3;

        float posX;
        float posY;

        int randomOffset;


        int direction;

    private:
};


