#pragma once
#include "ofxBox2d.h"

class CustomRect : public ofxBox2dCircle {
public:
    CustomRect(int _num);
    void update();
    
    int num;
    ofSoundPlayer mySound;
    float soundSpeed;
    float amp;
    float lfo;
    float radius;
};