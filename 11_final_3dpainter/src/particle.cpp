#include "particle.h"

particle::particle() {
        mass = ofRandom(10);

        blackWhite = ofRandom(3);

        if (blackWhite == 0){
            colour = 0;
            opacity= ofRandom(1,20);

        }else{
            colour = ofRandom(255);
            opacity=ofRandom(1,20);
        }

        size = ofRandom(5);
        offsetmult = ofRandom(0,2);
        speed = ofRandom(1,100);


        brush = ofRandom(3);
}

void particle::applyForce(ofVec3f force){
    accel += (force / mass);
}

void particle::update(){
    vel += accel;
    pos += vel;

    vel*= 0.97;

    accel.set(0);

    if (pos.x > 1000) pos.x = 0;
    if (pos.y > 1000) pos.y = 0;
    if (pos.z > 1000) pos.z = 0;

    if (pos.x < 0) pos.x = 1000;
    if (pos.y < 0) pos.x = 1000;
    if (pos.z < 0) pos.x = 1000;



    opacity: ofMap(ofNoise(ofGetElapsedTimef()+1000*mass), 0, 1, 0, 30);

    size = size+ ofMap(ofNoise(ofGetElapsedTimef()+1000*speed), 0, 1, -1, 1);


    offset.set(ofRandom(-1,1) *offsetmult,ofRandom(-1,1)*offsetmult, ofRandom(-1,1)*offsetmult);
}

void particle::draw() {
//    ofCircle( pos, 2 );
//    ofVertex(pos);
    //glVertex3fv(&pos.x);

    ofSetColor(colour,opacity);

    if (brush==0){
        ofDrawSphere(pos, size);

    }

    if (brush==1){
        ofDrawCone(pos, size,size*2);

    }

    if (brush==2){
        ofDrawBox(pos, size,size,size);

    }

    if (brush==3){
        ofDrawBox(pos, size,size*2,size/2);

    }

}
