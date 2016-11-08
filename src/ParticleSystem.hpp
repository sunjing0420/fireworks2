//
//  ParticleSystem.hpp
//  class2
//
//  Created by 怂怂 on 2016/11/1.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem{
public:
    ParticleSystem(ofVec2f position);
    void update(ofVec2f force);
    void draw();
    
    vector<Particle> mParticleList;
    ofVec2f mPosition;
    int mEmitRate;
    bool mIsAddingParticles;
};
