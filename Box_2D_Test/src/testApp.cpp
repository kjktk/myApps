#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    box2d.init();
    box2d.setGravity(0, 5);
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight());
    box2d.setFPS(30);
    box2d.registerGrabbing();
    ofSetLogLevel(OF_LOG_NOTICE);
    
    for (int i=0; i<100; i++) {
        ofPtr<ofxBox2dRect> rect = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
        float w = 10;
        float h = 10;
        float x = ofRandom(50, ofGetWidth() -50);
        float y = ofRandom(50, ofGetHeight() -50);
        rects.push_back(rect);
        rects.back().get() -> setup(box2d.getWorld(), x, y, w, h);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i < circles.size(); i++) {
        ofFill();
        circles[i].get()->draw();
    }
    for (int i=0; i < rects.size(); i++) {
        ofSetColor(255, 63, 63);
        rects[i].get() -> draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'C') {
        for (int i = 0; i < circles.size(); i++) {
            circles[i].get() ->destroy();
        }
        circles.clear();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    float r = ofRandom(5, 20);
    float weight = 1.0;
    float repulsion = 0.8;
    float friction = 0.5;
    
    ofPtr<CustomCircle> circle = ofPtr<CustomCircle>(new CustomCircle);
    circles.push_back(circle);
    circles.back().get() -> setPhysics(weight, repulsion, friction);
    circles.back().get() -> setup(box2d.getWorld(), mouseX, mouseY, r);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    float r = ofRandom(5, 20);
    float weight = 1.0;
    float repulsion = 0.8;
    float friction = 0.5;
    
    ofPtr<CustomCircle> circle = ofPtr<CustomCircle>(new CustomCircle);
    circles.push_back(circle);
    circles.back().get() -> setPhysics(weight, repulsion, friction);
    circles.back().get() -> setup(box2d.getWorld(), mouseX, mouseY, r);
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
