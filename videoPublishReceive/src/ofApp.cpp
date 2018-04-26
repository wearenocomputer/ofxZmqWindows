#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	videopublisher.bind("tcp://*:14000");
	//videopublisher.setHighWaterMark(2);
	//videopublisher.setSendHighWaterMark(2);
	videoreceiver.connect("tcp://localhost:14000");
	//videoreceiver.setReceiveHighWaterMark(2);

	camera.setup(1280, 720);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();

	if (camera.isFrameNew()) {
		videopublisher.send(camera.getPixels().getData(), 3*1280*720* sizeof(unsigned char));
	}

	while (videoreceiver.hasWaitingMessage())
	{
		ofBuffer data;
		videoreceiver.getNextMessage(data);
		image.setFromPixels((unsigned char*)data.getData(), 1280, 720,OF_IMAGE_COLOR,true);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (image.isAllocated()) {
		image.draw(0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
