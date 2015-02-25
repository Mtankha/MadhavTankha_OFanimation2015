#include "customCircle.h"


customCircle::customCircle() {


}


void customCircle::setup(ofVec2f _initPos, float _pct){
    currentPos=_initPos;
    clickCounter = false;
    r = ofRandom( 0, 255 );
    g = ofRandom( 0, 255 );
    b = ofRandom( 0, 255 );
    pct = _pct;

}


void customCircle::update(ofVec2f _mouse){
    currentPos = currentPos * (1-pct) + _mouse*pct;
    size = ( (currentPos * (1-pct) + _mouse*pct).x +  (currentPos * (1-pct) + _mouse*pct).y ) * 0.05;
    r= (currentPos = currentPos * (1-pct) + _mouse*pct).x;
    g= (currentPos = currentPos * (1-pct) + _mouse*pct).y;
}



void customCircle::draw(){

    ofSetColor(r,g,b);
    ofFill();
    ofCircle(currentPos,size);
    ofDrawBitmapString( "Move your mouse around", 30, 30);
}


void customCircle::swap(ofVec2f _mouse){

    if (clickCounter == true){
        currentPos.x = _mouse.x;
        clickCounter = false;
    } else{
        currentPos.y = _mouse.y;
        clickCounter = true;
    }

}


void customCircle::colorChange(){

    r = ofRandom( 128, 255 );
    g = ofRandom( 128, 255 );
    b = ofRandom( 128, 255 );

}
