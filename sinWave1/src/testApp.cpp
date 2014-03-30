#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    sampleRate = 44100;
    bufSize = 256;
    amp = 0.5;  //音量
    pan = 0.5;  //左右の定位
    phase = 0;  //位相
    frequency = 440;    //周波数
    waveShape = 1;      //波形
    ofSetFrameRate(30);
    ofBackground(32, 32, 32);
    ofSoundStreamSetup(2, 0);   //サウンドストリームの準備
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float audioHeight = ofGetHeight() / 2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    
    ofSetColor(0, 255, 0);
    ofNoFill();
    ofSetLineWidth(2);
    
    ofBeginShape();
    for (int i = 0; i < bufSize; i++) {
        ofVertex(i * phaseDiff, audioHeight/2 + lAudio[i] * audioHeight);
    }
    ofEndShape();
    
    ofBeginShape();
    for (int  i = 0 ; i < bufSize ; i++) {
        ofVertex(i * phaseDiff, audioHeight/2 * 3 + rAudio[i] * audioHeight);
    }
    ofEndShape();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key) {
            case '-':
                amp -= 0.05;
                amp = MAX(amp, 0);
                break;
            case '+':
                amp += 0.05;
                amp = MAX(amp, 1);
            case '1':
                waveShape = 1;
                break;
            case '2':
                waveShape = 2;
                break;
            case '3':
                waveShape = 3;
                break;
            case '4':
                waveShape = 4;
                break;
            case '5':
                waveShape = 5;
                break;
            
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    pan = (float)x / (float)ofGetWidth();
    float heightPct = ((float)ofGetHeight()-(float)y) / (float)ofGetHeight();
    frequency = 4000.0f * heightPct;
    if (frequency < 20) {
        frequency = 20;
    }
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

void testApp::audioRequested(float * output, int bufferSize, int nChannels) {
    
    float sample;
    float phaseDiff;
    
    phaseDiff = TWO_PI * frequency / sampleRate;
    
    for (int i = 0; i < bufferSize; i++) {
        //位相を更新
        phase += phaseDiff;
        while (phase > TWO_PI) {
            phase -= TWO_PI;
        }
        switch (waveShape) {
            case 1: //Sin波
                sample = sin(phase);
                break;
            case 2: //ノコギリ波
                sample = - phase / PI + 1;
                break;
            case 3: //矩形波
                sample = (phase < PI) ? -1 : 1;
                break;
            case 4: //三角波
                sample = (phase < PI) ? -2 / PI * phase + 1 : 2 / PI * phase - 3;
            case 5: //ホワイトノイズ
                sample = ofRandom(-1,1);
        }
        //オーディオアウト, 左右2ch
        lAudio[i] = output[i * nChannels] = sample * pan * amp;
        rAudio[i] = output[i * nChannels + 1] = sample * pan * amp;
    }
}

