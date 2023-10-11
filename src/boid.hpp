//
//  boid.hpp
//  swarmingAmbientDrone
//
//  Created by Harry Foley on 06/10/2023.
//

#ifndef boid_hpp
#define boid_hpp

#include "ofMain.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include "ofxOsc.h"
#include <stack>
#define PORT 7331


class boid {
    
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float r;
    float mass;
    float maxForce;
    float maxSpeed;
    float desiredSeparation;
    float align_region;
    float cohesion_region;
    int index;
    string prefixName = "/boid/";
    boid(int index_);
    
    void draw();
    
    void draw2();
    
    void run(vector<boid> boids);
    void applyForce(ofVec2f force);
    void flock(vector<boid> boids);
    void update();
    ofVec2f seek(ofVec2f target);
    void render();
    void bordersWrapAround();
    void bordersBounceBack();

    ofVec2f separate(vector<boid> boids);
    ofVec2f align(vector<boid> boids);
    ofVec2f cohesion(vector<boid> boids);
    
    ofxOscMessage boidNoteMessage;
    
    ofxOscMessage getBoidNoteMessage();
    
    ofxOscSender boidMsgSender;
    
    void sendBoidMsg(float vol, string pan);
    
    std::stack<ofxOscMessage> msgStack;
    
    bool checkforMsg();
    
    ofColor boidColor;
    
    
    
};



#endif /* boid_hpp */
