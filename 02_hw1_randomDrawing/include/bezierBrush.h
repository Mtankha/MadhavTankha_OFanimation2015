#pragma once
#include "ofMain.h"

class bezierBrush
{
    public:
        //bezierBrush();
        void setup();
        void update();
        void draw(int _mouseX, int _mouseY);

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

    private:
};


