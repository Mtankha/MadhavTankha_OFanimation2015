#include "flowField.h"

flowField::flowField()
{

}


void flowField::setup(float w, float h, float res){

    screenWidth = w;
    screenHeight = h;
    resolution = res;

    fieldWidth = ceil(screenWidth/resolution);
    fieldHeight = ceil(screenHeight/resolution);

    totalFlows = fieldWidth * fieldHeight;

    for(int i = 0; i< totalFlows; i++){

        ofVec2f flow;
        flow.set(0.0,0.0);

        field.push_back(flow);
    }

}


void flowField::setRandom(float scale){


    for (int i = 0; i <totalFlows; i++){

        float x = ofRandom(-1,1) * scale;
        float y = ofRandom(-1,1) * scale;
        field[i].set(x,y);
    }


}




void flowField::setNoise(){




    for (int y=0; y < fieldHeight; y++){

        for(int x=0; x<fieldWidth; x++){


            float xSin = ofGetElapsedTimef()+x*1000;
        float ySin = ofGetElapsedTimef()+y*1000;
        //float xSin = ofMap( sinOfTime1, -1, 1, -0.1, 0.1);
       // float ySin = ofMap( sinOfTime2, -1, 1, -0.1, 0.1);

            int index = (y*fieldWidth) +x;
            float noise = ofNoise(x*0.1, y*0.1);
            noise = ofMap(noise, 0,1,0,TWO_PI);
            field[index].set(ofVec2f(sin(noise*xSin) * 2.5, cos(noise*ySin)*2.5));
        }

    }


}





void flowField::draw(){

    for (int y= 0; y < fieldHeight; y++){

        for (int x = 0; x < fieldWidth; x++){

            int index = (y * fieldWidth) + x;

            float x0 = x * resolution;
            float y0 = y * resolution;
            float x1 = x0 + (field[index].x * 5);
            float y1 = y0 + (field[index].y * 5);

            ofLine(x0, y0, x1, y1);
            ofCircle(x0, y0, 2);

        }
    }

}



ofVec2f flowField::getForceAt(float x, float y) {

    //create a vector force to apply to the particle and set it to zero.
    ofVec2f frc;
    frc.set(0, 0);


    //make sure the particle is within the flow. If not, just return force as zero. When you return from a function, nothing else
    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight) {
            return frc;
    }

    //convert the X and Y position from pixels to the size in number of flows
    int xIndex = ceil (ofMap (x, 0, ofGetWidth(), 0, fieldWidth));
    float yIndex = ceil (ofMap (y, 0, ofGetHeight(), 0, fieldHeight));

    //finding the position of the flow in the vector container
    int index = (yIndex * fieldWidth) + xIndex;

    //set the force from the flow. Scale it down otherwise it will be too strong
    frc.set(field[index].x * 0.01, field[index].y * 0.01);

    return frc;


 }


