#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetFullscreen(true);
    scale = 20;


    timer = 0;
    majorTimer = 0;
    minorTimer = 0;
    majorStyle = 0;
    minorStyle = 0;
    noiseScale = 0;
    rotateScale =1;
    sinScale=0;
    cameraTimer = 0;
    cameraDepth = 500;

    ofSetSmoothLighting(true);
    light.setPointLight();
    light.setDiffuseColor(ofFloatColor(1.f, 1.f, 1.f));
    light.setPosition(300,300,200);


    flowfield.setup( 1000, 1000, 1000, 50 );
    flowfield.setNoise(20);

    particles.clear();

    for( int i=0; i<10000; i++ ){
        particle part;
        part.pos = ofVec3f( ofRandom(flowfield.screenWidth), ofRandom(flowfield.screenHeight), ofRandom(flowfield.screenHeight) );

        particles.push_back( part );
    }



    bDrawField = true;
    bDrawBackground = false;





}

//--------------------------------------------------------------
void ofApp::update(){

    while (particles.size() > 10000) {
         particles.erase(particles.begin());
    }



    for( int i=0; i<particles.size(); i++ ){
        particles[i].applyForce( flowfield.getForceAt(particles[i].pos ) * 0.005 );
        particles[i].update();
    }


    timer++;

    if (timer>= 2){


     particle part;
     part.pos = ofVec3f( ofRandom(flowfield.screenWidth), ofRandom(flowfield.screenHeight), ofRandom(flowfield.screenHeight) );

     particles.push_back( part );

    timer = 0;


    }


    majorTimer ++;
    if(majorTimer>= 1200){
        majorStyle = ofRandom(3);
        majorTimer = 0;
    }

    minorTimer ++;
    if(cameraTimer>= 600){
        minorStyle = ofRandom(2);
        minorTimer = 0;
    }

    cameraTimer ++;
    if(cameraTimer>= 900){
        //cameraDepth = ofRandom(0,500);
        cameraStyle = ofRandom(2);
        cameraTimer = 0;
    }


    if(cameraStyle==0){

            noiseScale = 0;
            rotateScale = 1;
            sinScale = 0;
        }

    if(cameraStyle==1){

            noiseScale = 1;
            rotateScale = 0;
            sinScale = 0;
        }

    if(cameraStyle==2){

            noiseScale = 0;
            rotateScale = 0;
            sinScale = 1;
        }





    if(minorStyle==0){

           scale = 1;
        }


    if(minorStyle==1){

            scale = 20;;
        }


    if(minorStyle==2){
            scale = 100;
        }




        if(majorStyle==0){

            flowfield.setNoise(scale);
        }


    if(majorStyle==1){

            flowfield.setRandom(scale);
        }


    if(majorStyle==2){
            flowfield.setNoise2(scale);
        }



    if(majorStyle==3){

            flowfield.setNoise3(scale);
        }




}

//--------------------------------------------------------------
void ofApp::draw(){

    //cam.setPosition(ofPoint(0, 0, cameraDepth));
    //cam.lookAt(ofPoint(0, 0, 0));

    //ofEnableDepthTest();
    cam.begin();


    ofEnableLighting();
    light.enable();






    float sinOfTime = sin(ofGetElapsedTimef()*0.3);
    float sinRotation = ofMap(sinOfTime, -1, 1, 0, 360);


    float sinOfTime2 = sin(ofGetElapsedTimef()*0.1);
    float sinRotation2 = ofMap(sinOfTime, -1, 1, 0, 360);

    float sinOfTime3 = sin(ofGetElapsedTimef()*0.5);
    float sinRotation3 = ofMap(sinOfTime, -1, 1, 0, 360);


    float noiseOfTime = ofNoise(ofGetElapsedTimef()*0.08);
    float noiseRotation1 = ofMap(noiseOfTime, 0, 1, 0, 360);

    float noiseOfTime2 = ofNoise(ofGetElapsedTimef()*0.05);
    float noiseRotation2 = ofMap(noiseOfTime2, 0, 1, 0, 360);

    float noiseOfTime3 = ofNoise(ofGetElapsedTimef()*0.06);
    float noiseRotation3 = ofMap(noiseOfTime3, 0, 1, 0, 360);



    ofRotateX(noiseRotation1 * noiseScale + ofGetElapsedTimeMillis()*rotateScale * 0.005 + sinRotation*sinScale);
    ofRotateY(noiseRotation2 * noiseScale + ofGetElapsedTimeMillis()*rotateScale * 0.008 + sinRotation2*sinScale);
    ofRotateZ(noiseRotation3 * noiseScale + ofGetElapsedTimeMillis()*rotateScale * 0.003 + sinRotation3*sinScale);





    ofPushMatrix(); {
        ofTranslate(flowfield.screenWidth*0.5*-1, flowfield.screenHeight*0.5*-1, flowfield.screenDepth*0.5*-1);


  ofSetColor(255,30);
    if(bDrawBackground) ofBackground(0);
    if (bDrawField) flowfield.draw();






        //ofSetColor(255,10);
        //glPointSize(50.0f);
        //glBegin(GL_POINTS);
        for( int i=0; i<particles.size(); i++ ){
            particles[i].draw();
        }
        //glEnd();

    } ofPopMatrix();
    cam.end();
    ofDisableLighting();



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            break;

        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
            break;


        default:
            break;

    }


     if (key == 'z'){
        flowfield.setRandom(scale);
    }


    if (key == 'x'){
        flowfield.setNoise(scale);
    }


    if (key == 'c'){
        flowfield.setNoise2(scale);
    }


    if (key == 'v'){
        flowfield.setNoise3(scale);
    }


    if (key == '+'){
        scale+=10;

    }

    if (key == '-'){
        scale-=10;

    }



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
