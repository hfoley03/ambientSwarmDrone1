//
//  boid.cpp
//  swarmingAmbientDrone
//
//  Created by Harry Foley on 06/10/2023.
//

#include "boid.hpp"
#include <iostream>

boid::boid(int index_){

    index = index_;
    float size = 40;//ofRandom(10, 20);
    r = static_cast<int>(size);
    mass = static_cast<int>(size/5.0);
    maxSpeed = 3;
    maxForce = 0.05;
    desiredSeparation = 5*r;
    align_region = 10*r;
    cohesion_region = 6*r;
    acc = ofVec2f(0,0);
    vel = ofVec2f(ofRandom(-1*maxSpeed, maxSpeed), ofRandom(-1*maxSpeed, maxSpeed));
    float w = ofGetWidth();
    float h = ofGetHeight();
    pos.set(ofRandom(w/4.0, 3.0*(w/4.0)),ofRandom(h/4.0, 3.0*(h/4.0)));
    //pos.set(ofGetMouseX(), ofGetMouseY());

    
    boidColor.setHsb(index*20, 200, 255,200);

    std::cout << "acc: " << acc << std:: endl;
    std::cout << "vel: " << vel << std:: endl;
    std::cout << "pos: " << pos << std:: endl;
    std::cout << "align_region: " << align_region << std::endl;
    std::cout << "cohesion_region: " << cohesion_region << std::endl;
    std::cout << "desiredSeparation: " << desiredSeparation << std::endl;
    std::cout << "index: " << index << std::endl;

//    boidMsgSender.setup("localhost", PORT);

    
}


void boid::run(vector<boid> boids){
    flock(boids);
    update();
    bordersBounceBack();     //bordersWrapAround();
    draw();
}


void boid::applyForce(ofVec2f force){
    ofVec2f f = force / mass;
    acc = f + acc;
}

void boid::flock(vector<boid> boids){
    ofVec2f sep = separate(boids);
    ofVec2f ali = align(boids);
    ofVec2f coh = cohesion(boids);

    sep *= 5.0;
    ali *= 1.0;
    coh *= 1.0;

    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}


void boid::update(){
    vel = vel + acc;
    vel.limit(maxSpeed);
    pos =  pos + vel;
    acc.set(0,0);
}

ofVec2f boid::seek(ofVec2f target){
    ofVec2f desired = target - pos;
    desired.normalize();
    desired *= maxSpeed;

    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
    return steer;
}

void boid::draw(){
    ofSetColor(boidColor);
    ofFill();
    ofDrawCircle(pos.x, pos.y, r);
}

void boid::draw2(){
    ofSetColor(112, 42, 100, 255);
    ofFill();
    ofDrawCircle(pos.x, pos.y, r);
}

void boid::bordersWrapAround(){
    if (pos.x < -r){
        pos.x = ofGetWidth() + r;
        std::cout << "1" << std:: endl;
    }
    if (pos.y < -r){
        pos.y = ofGetHeight() + r;
        std::cout << "2" << std:: endl;

    }
    if (pos.x > ofGetWidth() + r){
        pos.x = -r;
        std::cout << "3" << std:: endl;

    }
    if (pos.y > ofGetHeight() + r){
        pos.y = -r;
        std::cout << "4" << std:: endl;

    }
}

void boid::bordersBounceBack(){
    if (pos.x < r){
        vel.x = vel.x * -1;
        pos.x = r;
        sendBoidMsg((vel.x)/maxSpeed, "/l");
    }
    if (pos.y < r){
        vel.y = vel.y * -1;
        pos.y = r;
        sendBoidMsg((vel.y)/maxSpeed, "");
    }
    if (pos.x > ofGetWidth() - r){
        vel.x = vel.x * -1;
        pos.x = ofGetWidth() - r;
        sendBoidMsg((vel.x)/maxSpeed, "/r");
    }
    if (pos.y > ofGetHeight() - r){
        vel.y = vel.y * -1;
        pos.y = ofGetHeight() - r;
        sendBoidMsg((vel.y)/maxSpeed, "");
    }
}

ofVec2f boid::align(vector<boid> boids){
    ofVec2f sum = ofVec2f(0.0, 0.0);
    int count = 0;
    for (int i = 0; i < boids.size(); i++){
        float d = pos.distance(boids[i].pos);
        if ((d > 0) && (d < align_region)) {
           sum += boids[i].vel;
           count++;
         }
    }

    if (count > 0) {
        sum = sum/ static_cast<float>(count);
        sum.normalize();
        sum *= maxSpeed;
        ofVec2f steer = sum - vel;
        steer.limit(maxForce);
        return steer;
    } else {

        return ofVec2f(0,0);
    }
}

ofVec2f boid::separate(vector<boid> boids){
    ofVec2f steer = ofVec2f(0.0, 0.0);
    int count = 0;
    for (int i = 0; i < boids.size(); i++){
        float d = pos.distance(boids[i].pos);
        if ((d > 0) && (d < desiredSeparation)) {
            ofVec2f diff = pos - boids[i].pos;
            ofSetColor(boidColor);
            ofDrawLine(pos.x, pos.y,boids[i].pos.x, boids[i].pos.y);
            diff.normalize();
            diff = diff/d;
            steer = steer + diff;
            count++;
         }
    }

    if (count > 0) {
        steer = steer / static_cast<float>(count);
    }
    
    if(steer.length() > 0){
        steer.normalize();

        steer *= maxSpeed;
        steer = steer - vel;
        steer.limit(maxForce);
    }
    return steer;
}


ofVec2f boid::cohesion(vector<boid> boids){
    ofVec2f sum = ofVec2f(0.0, 0.0);
    int count = 0;
    for (int i = 0; i < boids.size(); i++){
        float d = pos.distance(boids[i].pos);
        if ((d > 0) && (d < cohesion_region)) {
            sum = sum + boids[i].pos;
            ofSetColor(boidColor);
            ofDrawLine(pos.x, pos.y,boids[i].pos.x, boids[i].pos.y);
            count++;
         }
    }
    if (count > 0 ){
        sum = sum / static_cast<float>(count);
        return seek(sum);
    } else {
        return ofVec2f(0,0);
    }
}

ofxOscMessage boid::getBoidNoteMessage(){
    ofxOscMessage tempMsg = msgStack.top();
    msgStack.pop();
    return tempMsg;
}


void boid::sendBoidMsg(float vol, string pan){
    string result = prefixName + std::to_string(index) + pan;
    std::cout << " 'I've been hit' said " << result;
    std::cout << "  " << abs(vol) << std::endl;
    boidColor.setHsb(ofRandom(1.0)*255, 200, 255, 200);
    boidNoteMessage.setAddress(result);
    boidNoteMessage.addFloatArg(abs(vol));
    msgStack.push(boidNoteMessage);
    boidNoteMessage.clear();
}

bool boid::checkforMsg(){
    if (msgStack.empty()){
        return false;
    } else {
        return true;
    }
}
