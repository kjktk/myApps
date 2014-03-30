#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //画面設定
    ofSetFrameRate(60);
    kinect.init(); //初期化
    kinect.open(); //起動
}

//--------------------------------------------------------------
void testApp::update(){
    kinect.update(); //更新
}

//--------------------------------------------------------------
void testApp::draw(){
    kinect.draw(0,0, kinect.width, kinect.height); //カメラ映像
    kinect.drawDepth(kinect.width,0,kinect.width,kinect.height); //深度情報
}
