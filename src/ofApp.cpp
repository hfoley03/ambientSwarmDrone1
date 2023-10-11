#include "ofApp.h"
//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(0);
    ofBackground(0, 0, 0);
    maxQuad = -1;

    
    
    oscIn.setup(PORT);
    oscOut.setup("localhost", PORT);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    maxQuad = section.numberBoidsInSection(flock.getFlock());
    vector<float> counts = section.getCounts();
    ofxOscMessage m0Sent;
//    m0Sent.setAddress("/signal1");
//    m0Sent.addFloatArg(counts[0]);
//    oscOut.sendMessage(m0Sent);
//
//    m0Sent.clear();
//    m0Sent.setAddress("/signal2");
//    m0Sent.addFloatArg(counts[1]);
//    oscOut.sendMessage(m0Sent);
//
//    m0Sent.clear();
//    m0Sent.setAddress("/signal3");
//    m0Sent.addFloatArg(counts[2]);
//    oscOut.sendMessage(m0Sent);
//
//    m0Sent.clear();
//    m0Sent.setAddress("/signal4");
//    m0Sent.addFloatArg(counts[3]);
//    oscOut.sendMessage(m0Sent);

//    boid tempBoid = flock.getFlock()[0];
//    oscOut.sendMessage(tempBoid.getBoidNoteMessage());
//
    
//    while(oscIn.hasWaitingMessages()){
//        ofxOscMessage m;
//        oscIn.getNextMessage(&m);
//        if(m.getAddress() == "/boid/note"){
//            oscDataValue0 = m.getArgAsFloat(0);
//            std::cout<< oscDataValue0 << std::endl;
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    flock.run();
    //section.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    boid bb(0);
//    flock.addBoid(bb);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i = 0; i < 10; i++){
        boid b(i);
        flock.addBoid(b);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
