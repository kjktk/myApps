#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxOpenCv.h"
#include "CustomCircle.h"


class testApp : public ofBaseApp{

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
    
        ofVideoGrabber videoGrabber;
        ofxCvColorImage colorImg;
        ofxCvGrayscaleImage grayImg;
        ofxCvGrayscaleImage grayBg;
        ofxCvGrayscaleImage grayDiff;
        ofxCvContourFinder contourFinder;
        ofxBox2d box2d;
        vector<ofPtr<ofxBox2dCircle> > contourCircles;
    
        vector<ofPtr<CustomCircle> > circles;
    
        bool bLearnBackground;
        int threshold;
};
