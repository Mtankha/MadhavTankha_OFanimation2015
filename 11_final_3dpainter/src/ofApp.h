#pragma once

#include "ofMain.h"
#include "flowField.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();



		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		flowField flowfield;
		vector <particle> particles;
		bool bDrawField;
		bool bDrawBackground;


        float scale;

		ofEasyCam cam;
		ofLight light;


        int timer;


        int majorTimer;
        int minorTimer;

        int majorStyle;
        int minorStyle;

        float noiseScale;
        float rotateScale;
        float sinScale;

        int cameraDepth;
        int cameraTimer;
        int cameraStyle;


};
