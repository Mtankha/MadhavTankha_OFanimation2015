#pragma once
#include "ofMain.h"


class circles
{
    public:
        //circles();
    void setup(int _initPosX, int _initPosY, float _size, float _volatility, float _swarmNum);
    void update();
    void draw();

    ofVec2f pos;
    int initPosX;
    int initPosY;

    float size;
    float volatility;

    float swarmNum;

    float color;



    private:
};


