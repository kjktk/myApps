#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bufSize = 256;
    ofBackground(0, 0, 0);
    ofSetColor(0,0,255);
    ofSoundStreamSetup(0, 2);
    left = new float[bufSize];
    right = new float[bufSize];
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/(float)bufSize;
    
    ofSetColor(0,0,255);
    ofNoFill();
    ofSetLineWidth(2);
    
    ofBeginShape();
    for (int i = 0; i < bufSize; i++) {
        ofVertex(i * phaseDiff, audioHeight / 2 + left[i] * audioHeight);
    }
    ofEndShape();
    
    ofBeginShape();
    for (int i = 0; i < bufSize; i++) {
        ofVertex(i * phaseDiff, audioHeight / 2 * 3 + right[i] * audioHeight);
    }
    ofEndShape();
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

void testApp::audioReceived(float *input, int bufferSize, int nChannels) {
    for (int i = 0; i < bufferSize; i++) {
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
}