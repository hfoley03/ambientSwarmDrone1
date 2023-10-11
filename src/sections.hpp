//
//  sections.hpp
//  swarmingAmbientDrone
//
//  Created by Harry Foley on 08/10/2023.
//

#ifndef sections_hpp
#define sections_hpp

#include "ofMain.h"
#include <stdio.h>
#include <iostream>
#include "aFlock.hpp"
#include "boid.hpp"



class sections {
public:
    
    sections();
    void draw();
    int numberBoidsInSection(vector<boid> boids);
    int maxIndex; 
    float countQ1;
    float countQ2;
    float countQ3;
    float countQ4;
    
    float q1;
    float q2;
    float q3;
    float q4;
    
    vector<float> counts;
    
    int getIndex(vector<float> v, float K);
    
    vector<float> getCounts();
    
};


#endif /* sections_hpp */
