#include "wave.h"

void wave::setup(float _offsetX, float _offsetY){
offsetX = _offsetX;
offsetY = _offsetY;
r= ofRandom(50);
g= ofRandom(50);
b= ofRandom(50,255);



};

void wave::update(){


    float sinOfTime1 = sin(ofGetElapsedTimef()+offsetX);
    float sinOfTime2 = sin(ofGetElapsedTimef()+offsetY);
    xSin = ofMap( sinOfTime1, -1, 1, -10, 10)*offsetX;
    ySin = ofMap( sinOfTime2, -1, 1, -100, 100)*offsetY;
    alpha = ofMap( sinOfTime1, -1, 1, 30, 200);


};


void wave::draw(){

ofSetColor(r,g,b,alpha);
    ofBeginShape();

        ofVertex(0,600);
        ofBezierVertex(50+ySin*0.5,50 +xSin*0.5,100+xSin,100+ySin,150+ySin*0.5,180+xSin*0.5);
        ofBezierVertex(150+ySin*0.5,180 +xSin*0.5,300+xSin,550+ySin,400+ySin*0.5,400+xSin*0.5);
        ofBezierVertex(400+ySin*0.5,400+xSin*0.5,600+xSin,50+ySin,650+ySin*0.5,600+xSin*0.5);
        ofBezierVertex(650+ySin*0.5,600+xSin*0.5,700+xSin,700+ySin,850+ySin*0.5,400+xSin*0.5);
        ofBezierVertex(850+ySin*0.5,400+xSin*0.5,950+xSin,300+ySin,1200+ySin*0.5,150+xSin*0.5);
        ofVertex(1200,800);
        ofVertex(0,800);

    ofEndShape(true);


};
