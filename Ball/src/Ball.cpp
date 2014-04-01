#include "Ball.h"

Ball::Ball() {
    pos = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
    radius = 100.0;
    speed = ofPoint(0,0);
    phaseSpeed = ofRandom(0.05,0.3);
    phase = 0;
}

//コンストラクタ
void Ball::draw(){
    ofSetColor( 31, 63, 255,30);
    ofCircle(pos.x,pos.y, strechedRadius);
    
    ofSetColor(255, 255, 255, 100);
    ofCircle(pos.x, pos.y, radius/10.0);
    ofSetColor( 31, 63, 255);
}

//円のアニメーション
void Ball::update(){
    
    strechedRadius = radius + sin(phase)*radius / 4;
    phase += phaseSpeed;
    if (phase > TWO_PI) {
        phase -= TWO_PI;
    }
    
    pos += speed;
    if(pos.x < strechedRadius || pos.x > ofGetWidth() - strechedRadius){
        speed.x *= -1;
    }
    if(pos.y < strechedRadius || pos.y > ofGetHeight() - strechedRadius){
        speed.y *= -1;
    }
}

//posセッター
void Ball::setPos(ofPoint _pos){
    pos = _pos;
}
//posゲッター
ofPoint Ball::getPos() {
    return pos;
}
//radiusセッター
void Ball::setRadius(float _radius){
    radius = _radius;
}
//radiusゲッター
float Ball::getRadius(){
    return radius;
}
//speedセッター
void Ball::setSpeed(ofPoint _speed) {
    speed = _speed;
}
//speedゲッター
ofPoint Ball::getSpeed() {
    return speed;
}