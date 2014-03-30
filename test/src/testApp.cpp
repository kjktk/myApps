#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    rotation = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    rotation = rotation + mouseX / 4.0;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(rotation);
    
    ofSetColor(0, 127, 255,200);
    ofCircle(-100,0,mouseY/2.0);
    ofSetColor(255, 255, 0,200);
    ofCircle(100,0,mouseY/2.0);
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
