//
//  Particle.hpp
//  class2
//
//  Created by 怂怂 on 2016/11/1.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle(ofVec2f pos);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void update(float multiplier);
    void draw();
    
    ofVec2f mPosition, mVelocity, mAcceleration;
    float mLifeSpan;
};
