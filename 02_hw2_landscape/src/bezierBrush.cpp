#include "bezierBrush.h"

void bezierBrush::setup(float _size)
{
    size = _size;

    noiseX=0;
    noiseY=0;

    offset1 = 10000.0;
    offset2 = 5000.0;
    offset1 = 20000.0;

    posX = ofRandom(ofGetWindowWidth());
    posY = ofRandom(ofGetWindowHeight());

    randomOffset = ofRandom(0,100000);



    direction = ofRandom(30);

}

void bezierBrush::update()
{




noiseX= ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, 100);
noiseY= ofMap(ofNoise(ofGetElapsedTimef()+ offset1), 0, 1, 0, 100);

noiseX2= ofMap(ofNoise(ofGetElapsedTimef()+ offset3), 0, 1, 0, 100);
noiseY2= ofMap(ofNoise(ofGetElapsedTimef()+ offset2), 0, 1, 0, 100);

noiseX3= ofMap(ofNoise(ofGetElapsedTimef()+ offset2), 0, 1, 0, 100);
noiseY3= ofMap(ofNoise(ofGetElapsedTimef()+ offset3), 0, 1, 0, 100);




posX += direction;
posY = ofMap(ofNoise(ofGetElapsedTimef() + randomOffset), 0, 1, 0, ofGetWindowHeight()*0.5);

if ((posX < 0) || (posX >ofGetWindowWidth())){
    direction *= -1;
}






}



void bezierBrush::draw()
{


ofSetColor(0,30);


ofBeginShape();
ofVertex(posX-30, posY-30);
//ofBezierVertex(_mouseX+ noiseX3 + ofRandom(10,size), _mouseY+ noiseY3 + ofRandom(10,size), _mouseX+ noiseX + ofRandom(10,size),_mouseY+ noiseY + ofRandom(10,size),_mouseX+ noiseX2 - ofRandom(10,size),_mouseY+ noiseY2 + ofRandom(10,size));
ofBezierVertex(posX+ noiseX2 + ofRandom(10,size), posY+ noiseY2 - ofRandom(10,size), posX+ noiseX3 + ofRandom(10,size),posY+ noiseY3 - ofRandom(0,size),posX+ noiseX + ofRandom(0,size),posY+ noiseY - ofRandom(0,size));
//ofBezierVertex(_mouseX+ noiseX - ofRandom(10,size), _mouseY+ noiseY - ofRandom(10,size), _mouseX+ noiseX2 - ofRandom(10,size),_mouseY + noiseY2 - ofRandom(10,size),_mouseX + noiseX3 - ofRandom(10,size),_mouseY+ noiseY3 - ofRandom(10,size));

ofBezierVertex(posX+ noiseX3 - ofRandom(10,size), posY+ noiseY3 + ofRandom(10,size), posX+ noiseX - ofRandom(10,size),posY+ noiseY + ofRandom(10,size),posX+ noiseX2 - ofRandom(10,size),posY+ noiseY2 + ofRandom(10,size));

ofEndShape(true);

//ofCircle(_mouseX, _mouseY, 10);



}

