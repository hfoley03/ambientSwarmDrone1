//
//  aFlock.hpp
//  swarmingAmbientDrone
//
//  Created by Harry Foley on 06/10/2023.
//

#ifndef aFlock_hpp
#define aFlock_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include "boid.hpp"
#include "ofMain.h"
#include "ofxOsc.h"
#define PORT 7331

class aFlock{

public:
    
    aFlock();
    vector <boid> boidz;
    void run();
    void addBoid(boid b);
    
    
    vector<boid> getFlock();
    
    boid getBoid(int index);
    
    void sendMsgs();
    
    void checkForMsg();
    ofxOscSender boidMsgSender;

    
};

#endif /* aFlock_hpp */
