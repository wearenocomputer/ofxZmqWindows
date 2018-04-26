#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofxZmqPublisher videopublisher;
		ofxZmqSubscriber videoreceiver;

		ofVideoGrabber camera;
		
		ofImage image;
		
};
