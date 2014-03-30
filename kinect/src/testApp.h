#pragma once

#include "ofMain.h"
#include "ofxKinect.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    ofxKinect kinect; //kinect インスタンス
    ofImage kinectImage;　//kinect カメラ映像
    ofImage depthImage;　//kinect 深度情報
};
