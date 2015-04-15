#pragma once
#include "ofMain.h"

class painter
{
    public:
        painter(int _initPosX, int _initPosY, int _targetPosX, int _targetPosY );
        void update();
        void draw();

        int colour;
        float size;
        int brush;

        ofVec2f currentPos, initPos, targetPos, offset;

        float pct;
        int opacity;
        float alpha;
        bool colourtrigger;
        int blackWhite;
        int offsetmult;
        float speed;






    private:
};


