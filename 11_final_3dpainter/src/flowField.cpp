#include "flowField.h"

flowField::flowField()
{

}


void flowField::setup(float w, float h, float d, float res){

    screenWidth = w;
    screenHeight = h;
    screenDepth = d;
    resolution = res;

    fieldWidth = ceil(screenWidth/resolution);
    fieldHeight = ceil(screenHeight/resolution);
    fieldDepth = ceil(screenDepth/resolution);

    totalFlows = fieldWidth * fieldHeight * fieldDepth;

//    for(int i = 0; i< totalFlows; i++){
//
//        ofVec2f flow;
//        flow.set(0.0,0.0);
//
//        field.push_back(flow);
//    }



for (int z = 0; z < fieldDepth; z++) {
        vector< vector<ofVec3f> > myPlaneList;
        flowList.push_back ( myPlaneList );

        for (int y = 0; y < fieldHeight; y++) {
            vector<ofVec3f> myList;
            flowList[z].push_back ( myList );

            for (int x = 0; x < fieldWidth; x++) {
                ofVec3f dir( 5, 5, 5 );
                flowList[z][y].push_back ( dir );
            }
        }
    }


}


void flowField::setRandom(float scale){


//    for (int i = 0; i <totalFlows; i++){
//
//        float x = ofRandom(-1,1) * scale;
//        float y = ofRandom(-1,1) * scale;
//        field[i].set(x,y);
//    }


    for( int z = 0; z < flowList.size(); z++){
        for( int y=0; y<flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){

                float r1 = ofRandom(-1,1) * scale;
                float r2 = ofRandom(-1,1) * scale;
                float r3 = ofRandom(-1,1) * scale;

                flowList[z][y][x].set( ofVec3f(r1, r2, r3) );
            }
        }
    }




}




void flowField::setNoise(float scale){

     for( int z = 0; z < flowList.size(); z++){
        for( int y=0; y<flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                float noise = ofMap( ofNoise(x*0.1, y*0.1, z*0.1), 0, 1, 0, TWO_PI);
                float cotNoise = cos(noise)/sin(noise);
                flowList[z][y][x].set( ofVec3f( cos(noise) * scale, sin(noise) * scale, sin (noise) * scale ) );
            }
        }
    }

}




void flowField::setNoise2(float scale){

     for( int z = 0; z < flowList.size(); z++){
        for( int y=0; y<flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                float noise = ofMap( ofNoise(x*0.1, y*0.1, z*0.1), 0, 1, 0, PI);
                float cotNoise = cos(noise)/sin(noise);
                flowList[z][y][x].set( ofVec3f( cotNoise * scale, sin(noise) * scale, sin (noise) * scale ) );
            }
        }
    }

}





void flowField::setNoise3(float scale){

     for( int z = 0; z < flowList.size(); z++){
        for( int y=0; y<flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                float noise = ofMap( ofNoise(x*0.1, y*0.1, z*0.1), 0, 1, 0, HALF_PI);
                float cotNoise = cos(noise)/sin(noise);
                flowList[z][y][x].set( ofVec3f( sin(noise) * scale, cotNoise * scale, cos (noise) * scale ) );
            }
        }
    }

}









void flowField::draw(){

//    for (int y= 0; y < fieldHeight; y++){
//
//        for (int x = 0; x < fieldWidth; x++){
//
//            int index = (y * fieldWidth) + x;
//
//            float x0 = x * resolution;
//            float y0 = y * resolution;
//            float x1 = x0 + (field[index].x * 5);
//            float y1 = y0 + (field[index].y * 5);
//
//            ofLine(x0, y0, x1, y1);
//            ofCircle(x0, y0, 2);
//
//        }
//    }



for( int z = 0; z < flowList.size(); z++){
        for( int y = 0; y < flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                ofVec3f np( x*resolution, y*resolution, z*resolution );
                ofLine ( np, np+flowList[z][y][x] );
            }
        }
    }

}



ofVec3f flowField::getForceAt(ofVec3f pos) {

    float pctX = pos.x / screenWidth;
    float pctY = pos.y / screenHeight;
    float pctZ = pos.z / screenDepth;

    int fieldWidth = screenWidth / resolution;
    int fieldHeight = screenHeight / resolution;
    int fieldDepth = screenDepth / resolution;

    int xVal = ofClamp( pctX * fieldWidth, 0, fieldWidth-1 );
    int yVal = ofClamp( pctY * fieldHeight, 0, fieldHeight-1 );
    int zVal = ofClamp( pctZ * fieldDepth, 0, fieldDepth-1 );

    ofVec3f newPos;
    newPos.set( flowList[zVal][yVal][xVal] );

    return newPos;


 }


