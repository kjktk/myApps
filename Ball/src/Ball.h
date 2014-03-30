#pragma once

#include "ofMain.h"

class Ball {

private:
    ofPoint pos;
    float radius;
    ofPoint speed;
    float phase; //円の伸縮運動の位相
    float phaseSpeed; //円の伸縮スピード
    float strechedRadius; //伸縮した結果の半径

public:
    Ball();
    void draw();
    void update();
    void setRadius(float radius);   //radiusセッター
    float getRadius();  //radiusゲッター
    void setPos(ofPoint pos); //posセッター
    ofPoint getPos();   //posゲッター
    void setSpeed(ofPoint speed);  //speedセッター
    ofPoint getSpeed(); //speedゲッター
};

