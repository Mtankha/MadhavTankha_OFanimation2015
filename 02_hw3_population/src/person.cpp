#include "person.h"

void person::setup(){



float num = ofxGaussian();
float sd = 120;
float mean = ofGetWidth()/2;

x = (sd * num)+ mean ;



color = (x/10,x/10,x/10);
size = ofRandom(x/10);
movement = ofRandom(x/100);
randomOffset = ofRandom(0,100000);





}


void person::update(){



 pos.x += movement;
pos.y = ofMap(ofNoise(ofGetElapsedTimef() + randomOffset), 0, 1, 0, ofGetWindowHeight());

if ((pos.x < 0) || (pos.x >ofGetWindowWidth())){
    movement *= -1;



}


}


void person::draw(){


    ofSetColor(color);
    ofCircle(pos, size);





}



bool haveNextNextGaussian = false;
float nextNextGaussian;


float person::ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
     }
     else {
         float v1, v2, s;
         do {
            v1 = 2 * ofRandomf() - 1;
             v2 = 2 * ofRandomf() - 1;
             s = v1 * v1 + v2 * v2;
         }
         while (s >= 1 || s == 0);

         float multiplier = sqrt(-2 * log(s)/s);
         nextNextGaussian = v2 * multiplier;
         haveNextNextGaussian = true;

         return v1 * multiplier;
     }
 }
