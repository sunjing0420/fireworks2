//
//  ParticleSystem.cpp
//  class2
//
//  Created by 怂怂 on 2016/11/1.
//
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(ofVec2f position):mPosition(position),mEmitRate(10),mIsAddingParticles(true){
    
}

void ParticleSystem::update(ofVec2f force){
    if(mIsAddingParticles){
        //pushing particles into the array
        
        for (int i=0; i<mEmitRate; i++){
            Particle particle(mPosition);
            mParticleList.push_back(particle);
            cout<<mParticleList.size()<<endl;
        }
    }
    for(int i=0; i<mParticleList.size(); i++){
        //calculating the difference between center and particle position
        ofVec2f diff=ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x),abs(mParticleList[i].mPosition.y - mPosition.y));
        
        mParticleList[i].resetForces();
        //force in here is passed from ofApp
        mParticleList[i].applyForce(force);
        //apply to the random velocity to the particle
        mParticleList[i].update(ofMap(diff.length(), 0, 200, 2, 0.5));
        
        if (diff.length()*diff.length() >= 300){
            //stop adding particle if the particle's diff is higher than a certain number
            mIsAddingParticles=false;
            //erase the particle if it is too far from the center
            if(mParticleList.size()>0){
               mParticleList.erase(mParticleList.begin()+i);
            }
//            ofVec2f direction=ofVec2f(ofRandom(-5,5),ofRandom(-5,5));
//            if(diff.length()>10){
//                ofDrawLine(mParticleList[i].mPosition.x, mParticleList[i].mPosition.y, mParticleList[i].mPosition.x+direction.x, mParticleList[i].mPosition.y+direction.y);
//            }

            
        }
        
    }
}

//---------------------------------
void ParticleSystem::draw(){
    for(int i=0; i<mParticleList.size(); i++){
        mParticleList[i].draw();
        for(int j=i+1; j<mParticleList.size() ; j++){
            float dis = ofDist(mParticleList[i].mPosition.x, mParticleList[i].mPosition.y, mParticleList[j].mPosition.x, mParticleList[j].mPosition.y);
            if(dis<25){
                ofSetColor(255);
                ofSetLineWidth(0.5);
                ofDrawLine(mParticleList[i].mPosition.x, mParticleList[i].mPosition.y, mParticleList[j].mPosition.x, mParticleList[j].mPosition.y);
            }
                    }
        ofVec2f diff=ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x),abs(mParticleList[i].mPosition.y - mPosition.y));
        ofVec2f direction=ofVec2f(ofRandom(-15,15),ofRandom(-15,15));
        if(diff.length()>10){
            ofDrawLine(mParticleList[i].mPosition.x, mParticleList[i].mPosition.y, mParticleList[i].mPosition.x+direction.x, mParticleList[i].mPosition.y+direction.y);
        }

    }
}
