#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackgroundHex(0x000000);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.setFPS(30.0);
    
    particleImg.loadImage("emitter.png");
    dacImg.loadImage("particle.png");
    
    dac.fixture.filter.groupIndex = -1;
    dac.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 1, 1);
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    for (int i = 0; i<particles.size(); i++) {
        particles[i].get() -> update();
        particles[i].get() -> addAttractionPoint(dac.getPosition(), 0.1);
        //引力の計算
        for (int j = i + 1; j < particles.size(); j++) {
            particles[j].get() -> addAttractionPoint(particles[i].get() -> getPosition(), 0.001);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<particles.size(); i++) {
        ofVec2f p1 (particles[i].get() ->getPosition());
        for (int j = i + 1; j < particles.size(); j++) {
            ofVec2f p2 (particles[j].get() ->getPosition());
            float dist = p2.distance(p1);
            if (dist < 300) {
                int col = (300 - dist);
                ofSetColor(255, 255, 255, col);
                ofLine(p1.x, p1.y, p2.x, p2.y);
            }
        }
    }
    ofSetColor(255, 255, 255);
    for (int i = 0; i < particles.size(); i++) {
        float radius = particles[i].get() -> radius;
        particleImg.draw(particles[i].get() -> getPosition() - radius /2.0, radius, radius);
    }
    float allAmp = 0;
    for (int i = 0; i < particles.size(); i++) {
        allAmp += particles[i].get() -> amp;
    }
    float dacRadius = sin(ofGetElapsedTimef() * 100.0) * allAmp * 20.0 + allAmp * 40.0 + 40.0;
    ofVec2f offset(dacRadius , dacRadius);
    dacImg.draw(dac.getPosition() - offset, dacRadius * 2.0, dacRadius * 2.0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
    if (key == 'c') {
        for (int i = 0; i < particles.size(); i++) {
            particles[i].get() -> destroy();
        }
        particles.clear();
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
    ofPtr<CustomRect> rect = ofPtr<CustomRect>(new CustomRect(particles.size()));
    particles.push_back(rect);
    particles.back().get()->setPhysics(10.0, 0.1, 0.5);
    particles.back().get()->fixture.filter.groupIndex = -1;
    particles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, 10);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    dac.setPosition(ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
