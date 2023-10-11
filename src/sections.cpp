//
//  sections.cpp
//  swarmingAmbientDrone
//
//  Created by Harry Foley on 08/10/2023.
//

#include "sections.hpp"
#include <iostream>
//#include <bits/stdc++.h>


sections::sections(){
    std::cout << "sections" << std::endl;
    maxIndex = -1;
}


void sections::draw(){
    ofSetColor(255, 0, 0, 255);
    //ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    //ofDrawLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    ofSetColor(0, 0, 255, 100);
//    switch(maxIndex){
//        case 0:
////          cout << "one" << endl;
//          ofDrawCircle(0, 0, ofGetHeight()/4);
//          break;
//        case 1:
////          cout << "two" << endl;
//            ofDrawCircle(ofGetWidth(), 0, ofGetHeight()/4);
//          break;
//        case 2:
////          cout << "three" << endl;
//            ofDrawCircle(0, ofGetHeight(), ofGetHeight()/4);
//          break;
//        case 3:
////          cout << "four" << endl;
//            ofDrawCircle(ofGetWidth(), ofGetHeight(), ofGetHeight()/4);
//          break;
//    }
    
    ofSetColor(255, 204, 13, 100);
    ofDrawCircle(0, 0, ofGetHeight()/2 *counts[0]);
    ofSetColor(255, 115, 38,100);
    ofDrawCircle(ofGetWidth(), 0, ofGetHeight()/2 * counts[1]);
    ofSetColor(255, 25, 77, 100);
    ofDrawCircle(0, ofGetHeight(), ofGetHeight()/2 * counts[2]);
    ofSetColor(191, 38, 105, 100);
    ofDrawCircle(ofGetWidth(), ofGetHeight(), ofGetHeight()/2 * counts[3]);

    
    
    
    
}

int sections::numberBoidsInSection(vector<boid> boids){
    float w = ofGetWidth();
    float h = ofGetHeight();
    float total = boids.size();
    
    counts.clear();
    
    countQ1 = 0;
    countQ2 = 0;
    countQ3 = 0;
    countQ4 = 0;

    for (int i = 0; i < boids.size(); i++){
        float xx = boids[i].pos.x;
        float yy = boids[i].pos.y;

        if ((xx < w/2.0) && (yy < h/2.0)){
            countQ1++;
        }
        if ((xx > w/2.0) && (yy < h/2.0)){
            countQ2++;
        }
        if ((xx < w/2.0) && (yy > h/2.0)){
            countQ3++;
        }
        if ((xx > w/2.0) && (yy > h/2.0)){
            countQ4++;
        }
    }
    
    q1 = countQ1/total;
    q2 = countQ2/total;
    q3 = countQ3/total;
    q4 = countQ4/total;

//    std::cout << "Q1: " << q1 << std::endl;
//    std::cout << "Q2: " << q2 << std::endl;
//    std::cout << "Q3: " << q3 << std::endl;
//    std::cout << "Q4: " << q4 << std::endl;
//    std::cout << "_________ " << std::endl;
    
    counts.push_back(q1);
    counts.push_back(q2);
    counts.push_back(q3);
    counts.push_back(q4);
    
    //get max count value
    float max = *max_element(counts.begin(), counts.end());
//    std::cout << max << std::endl;

    //get index of max count value
    maxIndex = getIndex(counts, max);
//    std::cout << maxIndex << std::endl;
    return maxIndex;
}



int sections::getIndex(vector<float> v, float K)
{
    auto it = find(v.begin(), v.end(), K);
  
    // If element was found
    if (it != v.end())
    {
        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}



vector<float> sections::getCounts(){
    return counts;
}
