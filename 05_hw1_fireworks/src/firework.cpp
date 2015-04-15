#include "firework.h"

firework::firework(ofVec2f _pos){

    pos.set(_pos);
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-1,-2);
    lifespan = ofRandom(100.0,255.0);


}





void firework::resetForces(){
    acc *= 0;

}


void firework::applyForce(ofVec2f force){

    acc += force;
}


void firework::update(){


    vel += acc;
    pos += vel;

    if (lifespan > 0){

        lifespan -=1.0;
    }





}


void firework::draw(){

    ofSetColor(255-lifespan);
    ofCircle(pos,5);

}
