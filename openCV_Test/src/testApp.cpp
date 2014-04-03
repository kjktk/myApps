#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    videoGrabber.initGrabber(320, 240);
    colorImg.allocate(320, 240);
    grayImg.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
    bLearnBackground = true;
    threshold = 100;
}

//--------------------------------------------------------------
void testApp::update(){
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
        contourFinder.findContours(grayDiff, 20, 320*240 / 3, 10, true);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    colorImg.draw(10,10);
    grayImg.draw(340,10);
    grayBg.draw(10, 260);
    grayDiff.draw(340, 260);
    contourFinder.draw(340, 500);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bLearnBackground = true;
            break;
        
        case '+':
            threshold ++;
            if (threshold > 255) {
                threshold = 255;
            }
            break;
        case '-':
            threshold --;
            if (threshold < 0) {
                threshold = 0;
            }
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
