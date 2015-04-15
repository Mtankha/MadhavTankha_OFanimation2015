#include "particle.h"

void particle::setup(){

    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();

}




void particle::resetForces() {
     acc *= 0;
}


void particle::applyForce(ofVec2f force) {
     acc += force;
}


void particle::applyDampingForce(float damping) {
     acc -= vel.getNormalized() * damping;
}


void particle::update() {
     vel += acc;
     pos += vel;

}


void particle::draw(float size) {
     ofCircle(pos, size);
}
