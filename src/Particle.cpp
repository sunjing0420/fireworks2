//
//  Particle.cpp
//  class2
//
//  Created by 怂怂 on 2016/11/1.
//
//

#include "Particle.hpp"
//using the constructor to initialize all the variables
Particle::Particle(ofVec2f position)
:mPosition(position)
, mVelocity(ofRandom(-2.f,2.f),ofRandom(-2.f,2.f))
, mAcceleration(ofVec2f(0))
, mLifeSpan(255.f)
{
    
}

//-------------------------------------------
void Particle::resetForces(){
    //reset the acceleration
    mAcceleration *= 0;
    
}

//-------------------------------------------
void Particle::applyForce(ofVec2f force){
    //adding for to acceleration
    mAcceleration += force;
    
}

//-------------------------------------------
void Particle::update(float multiplier){
    //apply acceleration to velocity
    mVelocity += mAcceleration;
    mPosition += mVelocity * multiplier;
    
    //decreasing the particle life
    if(mLifeSpan>0){
        mLifeSpan -= 2.f;
    }
    
//    ofVec2f bo=ofVec2f(100,100);
//    ofSetLineWidth(5);
//    ofDrawLine(mPosition.x, mPosition.y, mPosition.x+bo.x, mPosition.y+bo.y);
}

//-------------------------------------
void Particle::draw() {
    if( mLifeSpan > 100 ){
    // new born partilce will be brighter
    ofSetColor(255);
}else if( mLifeSpan <= 100 ){
    // do some sparkle!
    ofSetColor(235,215,0,mLifeSpan);
};
    // closer particle is smaller
    ofDrawCircle(mPosition, 1.f * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));
    
//    ofVec2f bo=ofVec2f(100,100);
//    ofSetLineWidth(5);
//    ofDrawLine(mPosition.x, mPosition.y, mPosition.x+bo.x, mPosition.y+bo.y);
}


