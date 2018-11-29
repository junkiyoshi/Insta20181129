#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}


//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(90);

	for (int y = -ofGetWidth() * 0.5; y < ofGetHeight() * 0.5; y += 144) {

		this->draw_shelf(y, 120, 30);
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_shelf(int y, int height, int span) {

	for (int z = -300; z <= 300; z += 600) {

		ofSetColor(39);
		ofDrawLine(glm::vec3(-ofGetWidth(), y, z), glm::vec3(ofGetWidth() * 2, y, z));

		for (int x = -ofGetWidth(); x < ofGetWidth() * 2; x += span) {

			int y_max = y + ofNoise(ofRandom(39), ofGetFrameNum() * 0.005) * height;
			for (int tmp_y = y; tmp_y <= y_max; tmp_y += span) {

				if (x > ofGetWidth()) {

					ofSetColor(39, ofMap(x, ofGetWidth(), ofGetWidth() * 2, 255, 0));
				}
				ofDrawRectangle(glm::vec3(x, tmp_y, z), span * 0.8, span * 0.8);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}