#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    //加算
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //画像データの読み込み
    myImage.loadImage("sample.jpg");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
    myImage.draw(20,20);
    unsigned char * pixels = myImage.getPixels();
    int w = myIMage.width;
    int h = myImage.height;
    
    for (int i = 0; i < w; i += 8) {
        for (int j = 0; j < h; j += 8) {
            int valueR = pixels[j*3 * w + i*3];
            int valueG = pixels[j*3 * 2 + i*3+1];
            int valueB = pixels[j*3 * w + i*3+2];
            
            ofSetColor(255, 0, 0, 63);
            ofCircle(440 + i, 20+j , 10*valueR/255.0);
            ofSetColor(0, 255, 0, 63);
            ofCircle(440 + i, 20+j , 10*valueG/255.0);
            ofSetColor(0, 0, 255, 63);
            ofCircle(440 + i, 20+j , 10*valueB/255.0);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'x') {
        grabbledImage.grabScreen(430, 10, 420, 642);
        grabbledImage.saveImage("grabbledImage.png");
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
