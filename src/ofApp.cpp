#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
	ofBackground(255);
	float clearAlpha = 100;
	float timeScale = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
	//ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//// Loop and draw a row
	//ofBackground(255);

	//for (int rows = 0; rows < 4; rows++) {
	//	ofPushMatrix();
	//	for (int cols = 0; cols < 4; cols++) {
	//		ofSetColor(255, 102, 204);
	//		ofDrawCircle(30, 30, 30);
	//		ofDrawRectangle(5, 70, 50, 100);
	//		ofDrawCircle(95, 30, 30);
	//		ofDrawRectangle(70, 70, 50, 100);
	//		ofSetColor(242, 13, 225);
	//		ofDrawCircle(45, 90, 15);
	//		ofDrawRectangle(30, 110, 30, 60);
	//		ofDrawCircle(80, 90, 15);
	//		ofDrawRectangle(65, 110, 30, 60);

	//		ofTranslate(150, 0);
	//	}
	//	ofPopMatrix();
	//	ofTranslate(0, 200);
	//ofBackground(255);
	//ofBackground(255);

	//float clearAlpha = 10;
	ofColor darkColor(0, 0, 0, 255);  // Opaque black
	ofColor lightColor(255, 255, 255, 255);  // Opaque white
	float time = ofGetElapsedTimef();  // Time in seconds
	float percent = ofMap(cos(time / 2.0), -1, 1, 0, 1);  // Create a value that oscillates between 0 to 1
	ofColor bgColor = darkColor;  // Color for the transparent rectangle we use to clear the screen
	bgColor.lerp(lightColor, percent);  // This modifies our color "in place", check out the documentation page
	bgColor.a = clearAlpha;  // Our initial colors were opaque, but our rectangle needs to be transparent
	ofColor fgColor = lightColor;  // Color for the rectangle outlines
	fgColor.lerp(darkColor, percent);  // Modifies color in place

	ofSetColor(bgColor);
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(0);
	ofNoFill();
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);  
	ofSetColor(fgColor);
	for (int i = 0; i<100; i++) {
		ofScale(1.1, 1.1);
		float time = ofGetElapsedTimef();
//		float timeScale = 0.5;
		float noise = ofSignedNoise(time * timeScale) * 20.0;
		ofRotate(noise);
		ofDrawRectangle(0, 0, 50, 50);
	}
	ofPopMatrix();
	//}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255);  // clearAlpha goes from 0 to 255 as the mouse moves from left to right
	timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);  // timeScale goes from 0 to 1 as the mouse moves from top to bottom

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
