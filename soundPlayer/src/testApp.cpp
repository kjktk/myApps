#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    radius = 0;
    mySound.loadSound("music.wav");
    mySound.setLoop(true);
}

//--------------------------------------------------------------
void testApp::update(){
    float * val = ofSoundGetSpectrum(1);
    radius = val[0] * 800.0;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 63, 255,180);
    ofCircle(mouseX, mouseY, radius);
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
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    mySound.setSpeed( 0.5f + ((float)ofGetHeight() - (float)y) / (float)ofGetHeight() * 1.0f);
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    mySound.setSpeed( 0.5f + ((float)ofGetHeight() - (float)y) / (float)ofGetHeight() * 1.0f);
    mySound.play();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mySound.stop();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

