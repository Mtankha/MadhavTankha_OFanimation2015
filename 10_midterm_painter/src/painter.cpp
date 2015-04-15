#include "painter.h"

    painter::painter(int _initPosX, int _initPosY, int _targetPosX, int _targetPosY){

    initPos.set (_initPosX, _initPosY);
    targetPos.set ( _targetPosX, _targetPosY);
    pct = 0.0;
    blackWhite = ofRandom(5);

    if (blackWhite == 0){
    colour = 0;
    opacity= ofRandom(2,10);

    }else{
    colour = ofRandom(255);
    opacity=ofRandom(1,3);
    }

    size = ofRandom(100);
    brush = ofRandom(4);
    alpha = 0;
    bool colourtrigger = false;

    offsetmult = ofRandom(1,3);

    speed = ofRandom(1,100);



}



void painter::update(){




    if(pct <= 1.0){

        pct += 0.00001 *speed;

    }

    currentPos = initPos * (1 - pct) + targetPos * pct;

    if ((alpha < 1.0 ) && (colourtrigger == false)){

        alpha += 0.001;
    } else {

     alpha -= 0.001;
    }

    if (alpha >= 1.0){

        colourtrigger = true;

    };


    //int randOffX = ofRandom(-1,1);
    //int randOffY = ofRandom(-1,1);
    offset.set(ofRandom(-10,10) *offsetmult,ofRandom(-10,10)*offsetmult);





}



void painter::draw(){

if (pct < 1.0){

    ofSetColor(colour*alpha,opacity);

    if (brush == 0){
        ofCircle(currentPos +offset, size);
    } else if (brush == 1){
        ofCircle(currentPos +offset, size/4);
        ofCircle(currentPos.x - size + offset.x, currentPos.y -size + offset.y, size/4);
        ofCircle(currentPos.x - size + offset.x, currentPos.y +size + offset.y, size/4);
        ofCircle(currentPos.x + size + offset.x, currentPos.y -size + offset.y, size/4);
        ofCircle(currentPos.x + size + offset.x, currentPos.y +size + offset.y, size/4);
    } else if (brush == 2){

        ofTriangle(currentPos.x + offset.x, currentPos.y - size + offset.y, currentPos.x+size + offset.x, currentPos.y + offset.y, currentPos.x-size + offset.x, currentPos.y +offset.y);

    } else if (brush == 3){

        ofRect(currentPos +offset ,size,size);

    }

}

}


