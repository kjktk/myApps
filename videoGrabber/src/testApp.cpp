#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    camWidth = 480;
    camHeight = 320;
    videoGrabber.setVerbose(true);
    videoGrabber.initGrabber(camWidth,camHeight);
}

//--------------------------------------------------------------
void testApp::update(){
    //キャプチャする
    videoGrabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0xffffff);
    videoGrabber.draw(20,20);
    unsigned char * pixels = videoGrabber.getPixels();
    
    for (int i = 0; i < camWidth ; i += 10) {
        for (int j = 0; j < camHeight; j += 10) {
            //それぞれの色の明度を取得
            unsigned char r = pixels[(j * camWidth + i) * 3];
            unsigned char g = pixels[(j * camWidth + i) * 3+1];
            unsigned char b = pixels[(j * camWidth + i) * 3+2];
            //取得したRGB値を元に、円を描画
            ofSetColor(255, 0, 0,100);
            ofCircle(camWidth + 40 + i, 20 + j, 20.0*(float)r/255.0);
            ofSetColor(0, 255, 0,100);
            ofCircle(camWidth + 40 + i, 20 + j, 20.0*(float)g/255.0);
            ofSetColor(0, 0, 255,100);
            ofCircle(camWidth + 40 + i, 20 + j, 20.0*(float)b/255.0);
        }
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
