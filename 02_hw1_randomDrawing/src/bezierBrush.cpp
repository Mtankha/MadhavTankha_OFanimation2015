#include "bezierBrush.h"

void bezierBrush::setup()
{
    size = 100.0;

    noiseX=0;
    noiseY=0;

    offset1 = 10000.0;
    offset2 = 5000.0;
    offset1 = 20000.0;

}

void bezierBrush::update()
{

noiseX= ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, 100);
noiseY= ofMap(ofNoise(ofGetElapsedTimef()+ offset1), 0, 1, 0, 100);

noiseX2= ofMap(ofNoise(ofGetElapsedTimef()+ offset3), 0, 1, 0, 100);
noiseY2= ofMap(ofNoise(ofGetElapsedTimef()+ offset2), 0, 1, 0, 100);

noiseX3= ofMap(ofNoise(ofGetElapsedTimef()+ offset2), 0, 1, 0, 100);
noiseY3= ofMap(ofNoise(ofGetElapsedTimef()+ offset3), 0, 1, 0, 100);



}



void bezierBrush::draw(int _mouseX, int _mouseY)
{




ofBeginShape();
ofVertex(_mouseX-30, _mouseY-30);
//ofBezierVertex(_mouseX+ noiseX3 + ofRandom(10,size), _mouseY+ noiseY3 + ofRandom(10,size), _mouseX+ noiseX + ofRandom(10,size),_mouseY+ noiseY + ofRandom(10,size),_mouseX+ noiseX2 - ofRandom(10,size),_mouseY+ noiseY2 + ofRandom(10,size));
ofBezierVertex(_mouseX+ noiseX2 + ofRandom(10,size), _mouseY+ noiseY2 - ofRandom(10,size), _mouseX+ noiseX3 + ofRandom(10,size),_mouseY+ noiseY3 - ofRandom(0,size),_mouseX+ noiseX + ofRandom(0,size),_mouseY+ noiseY - ofRandom(0,size));
//ofBezierVertex(_mouseX+ noiseX - ofRandom(10,size), _mouseY+ noiseY - ofRandom(10,size), _mouseX+ noiseX2 - ofRandom(10,size),_mouseY + noiseY2 - ofRandom(10,size),_mouseX + noiseX3 - ofRandom(10,size),_mouseY+ noiseY3 - ofRandom(10,size));

ofBezierVertex(_mouseX+ noiseX3 - ofRandom(10,size), _mouseY+ noiseY3 + ofRandom(10,size), _mouseX+ noiseX - ofRandom(10,size),_mouseY+ noiseY + ofRandom(10,size),_mouseX+ noiseX2 - ofRandom(10,size),_mouseY+ noiseY2 + ofRandom(10,size));

ofEndShape(true);

//ofCircle(_mouseX, _mouseY, 10);



}

