#include "circles.h"

void circles::setup(int _initPosX, int _initPosY, float _size, float _volatility, float _swarmNum)
{

initPosX = _initPosX;
initPosY = _initPosY;
size = _size;
volatility = _volatility;
swarmNum = _swarmNum;


}


void circles::update()
{


    float noiseX = ofNoise(ofGetElapsedTimef());
    float noiseY = ofNoise(ofGetElapsedTimef()+ 10000);
    float noiseSize = ofNoise(ofGetElapsedTimef()+ 20000);

    pos.x =  ofMap(noiseX, 0, 1, 0 , volatility);
    pos.y =  ofMap(noiseY, 0, 1, 0, volatility);

    size =  ofMap(noiseSize, 0, 1, 0, 10);

    color = ofMap ( ofNoise(ofGetElapsedTimef()), 0,1,0,volatility );






}


void circles::draw()
{

    ofSetColor(color,size*3.5);
    for (int i=0; i< swarmNum; i++){
         for(int j=0;j<swarmNum; j++){

        ofCircle(pos.x*i+j + ofMap( ofNoise(ofGetElapsedTimef()*20*j*i),0,1,0,20)*i, pos.y*j+i + ofMap( ofNoise(ofGetElapsedTimef()*20*i+10000),0,1,0,20)*j*i , size+(i+j)/3);


        }
    }




}
