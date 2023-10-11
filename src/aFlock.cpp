//
//  aFlock.cpp
//  swarmingAmbientDrone
//
//  Created by Harry Foley on 06/10/2023.
//

#include "aFlock.hpp"


aFlock::aFlock(){
    boidMsgSender.setup("localhost", PORT);
}


void aFlock::run(){
    for (int i = 0; i < boidz.size(); i++){
        boidz[i].run(boidz);
    }
    checkForMsg();
}


void aFlock::addBoid(boid b){
    boidz.push_back(b);
}


vector<boid> aFlock::getFlock(){
    return boidz;
}


boid aFlock::getBoid(int index){
    return boidz[index];
}

void aFlock::checkForMsg(){
    for (int i = 0; i < boidz.size(); i++){
        if (boidz[i].checkforMsg()){
            boidMsgSender.sendMessage(boidz[i].getBoidNoteMessage());
        }
    }
}


void aFlock::sendMsgs(){}


