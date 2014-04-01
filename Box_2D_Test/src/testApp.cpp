#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    box2d.init(); //Box2Dを初期化
    box2d.setGravity(0, 5); //重力の設定
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight()); //画面を壁で囲む
    box2d.setFPS(30);
    box2d.registerGrabbing();
    ofSetLogLevel(OF_LOG_NOTICE);
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i < circles.size(); i++) {
        ofFill();
        ofSetColor(0,127, 255);
        circles[i].get()->draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    float r = ofRandom(10, 40);
    float weight = 1.0;
    float repulsion = 0.8;
    float friction = 0.5;
    circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
    circles.back().get() -> setPhysics(weight, repulsion, friction); //物理パラメータ
    circles.back().get() -> setup(box2d.getWorld(), mouseX, mouseY, r); //マウスの位置に円を設定
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
