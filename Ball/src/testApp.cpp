#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < balls.size(); i++) {
      balls[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0,30);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < balls.size(); i++) {
      balls[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch (key) {
            case 'f':
                ofToggleFullscreen();
                break;
            case 'r':
            balls.clear();
    }
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
    int bSize = balls.size();
    if (bSize < 1) {
        Ball b;
        float radius = ofGetHeight()/3;
        b.setRadius(radius);
        b.setSpeed(ofPoint(0,0));
        b.setPos(ofPoint(ofGetWidth()/2,ofGetHeight()/2));
        balls.push_back(b);
    }
    else {
        for (int i = 0; i < bSize; i++) {
            ofPoint pos = balls[i].getPos();
            float dim = balls[i].getRadius();
            float dist = ofDist(pos.x, pos.y, mouseX, mouseY);
            if (dist < dim) {
                balls[i].setRadius(dim*0.6);
                balls[i].setPos(ofPoint(ofRandom(pos.x - dim/10,pos.x + dim/10),ofRandom(pos.y - dim/10,pos.y + dim/10)));
                balls[i].setSpeed(ofPoint(ofRandom(-dim/150, dim/150),ofRandom(-dim/150, dim/150)));
                
                Ball b1;
                b1.setRadius(dim*0.6);
                b1.setSpeed(ofPoint(ofRandom(-dim/150, dim/150),ofRandom(-dim/150, dim/150)));
                b1.setPos(ofPoint(ofRandom(pos.x - dim/10,pos.x + dim/10),ofRandom(pos.y - dim/10,pos.y + dim/10)));
                balls.push_back(b1);
                
                Ball b2;
                b2.setRadius(dim*0.6);
                b2.setSpeed(ofPoint(ofRandom(-dim/150, dim/150),ofRandom(-dim/150, dim/150)));
                b2.setPos(ofPoint(ofRandom(pos.x - dim/10,pos.x + dim/10),ofRandom(pos.y - dim/10,pos.y + dim/10)));
                balls.push_back(b2);
                
                Ball b3;
                b3.setRadius(dim*0.6);
                b3.setSpeed(ofPoint(ofRandom(-dim/150, dim/150),ofRandom(-dim/150, dim/150)));
                b3.setPos(ofPoint(ofRandom(pos.x - dim/10,pos.x + dim/10),ofRandom(pos.y - dim/10,pos.y + dim/10)));
                balls.push_back(b3);
            }
        }
    }
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
