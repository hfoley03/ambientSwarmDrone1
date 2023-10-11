#pragma once

#include "ofMain.h"
#include "boid.hpp"
#include "aFlock.hpp"
#include "sections.hpp"
#include "ofxOsc.h"
#define PORT 7331

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
    
    ofxOscReceiver oscIn;
    ofxOscSender oscOut;
    float oscDataValue0 = -1.0;
    float oscDataValue1 = -1.0;
    float oscDataValue2 = -1.0;
    float oscDataValue3 = -1.0;

    
    aFlock flock;
    sections section;
    int init_num = 0;
    float x;
    float y;
    int maxQuad;

};
