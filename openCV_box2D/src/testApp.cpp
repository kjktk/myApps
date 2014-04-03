#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    videoGrabber.initGrabber(320, 240);
    colorImg.allocate(320, 240);
    grayImg.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
    bLearnBackground = true;
    threshold = 100;
    
    box2d.init();
    box2d.setGravity(0, 1);
    box2d.createBounds(0, 0, colorImg.width, colorImg.height);
    box2d.setFPS(30);
    box2d.checkBounds(true);
    
    static const int NUM = 1000;
    for (int i = 0; i < NUM; i++) {
        ofPtr<CustomCircle> circle = ofPtr<CustomCircle>(new CustomCircle);
        circles.push_back(circle);
        circles.back().get() -> setPhysics(1.0, 0.8, 0.0);
        circles.back().get() -> setup(box2d.getWorld(), ofRandom(colorImg.width), ofRandom(colorImg.height), 3);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    
    bool bNewFrame = false;
    videoGrabber.update();
    bNewFrame = videoGrabber.isFrameNew();
    
    if (bNewFrame) {
        colorImg.setFromPixels(videoGrabber.getPixels(), 320, 240);
        grayImg = colorImg;
        if (bLearnBackground == true) {
            grayBg = grayImg;
            bLearnBackground = false;
        }
        grayDiff.absDiff(grayBg, grayImg);
        grayDiff.threshold(threshold);
        contourFinder.findContours(grayDiff, 20, 340*240/3, 10, false);
        for (int i = 0; i < contourFinder.nBlobs; i++) {
            for (int j = 0; j < contourFinder.blobs[i].pts.size();j+= 4) {
                ofPoint pos = contourFinder.blobs[i].pts[j];
                ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
                contourCircles.push_back(circle);
                contourCircles.back().get() -> setup(box2d.getWorld(), pos.x, pos.y, 4);
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    float ratioX = ofGetWidth()/320;
    float ratioY = ofGetHeight()/240;
    
    ofPushMatrix();
    ofScale((float)ofGetWidth() / (float)grayDiff.width, (float)ofGetHeight() / (float)grayDiff.height);
    ofSetColor(255, 255, 255);
    colorImg.draw(0, 0);
    contourFinder.draw();
    ofNoFill();
    ofSetColor(255, 0, 0);
    for (int i = 0; i < contourCircles.size(); i++) {
        contourCircles[i].get() -> draw();
    }
    for (int i = 0; i < circles.size(); i++) {
        circles[i].get() -> draw();
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bLearnBackground = true;
            break;
            
        case '+':
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
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
