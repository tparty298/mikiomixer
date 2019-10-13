#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofSetWindowShape(ofGetWindowHeight(),ofGetWindowWidth());
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	gakuchoMovie.load("movies/test.mov");
	//gakuchoMovie.load("fingers.mov");
	//gakuchoMovie.play();

	camWidth = 1920;
	camHeight = 1080;

	vector<ofVideoDevice> devices = vidGrabber.listDevices();

	for (size_t i = 0; i < devices.size(); i++) {
		if (devices[i].bAvailable) {
			ofLogNotice() << devices[i].id << ":" << devices[i].deviceName;
		}
		else {
			ofLogNotice() << devices[i].id << ";" << devices[i].deviceName << " - unavailable ";
		}
	}

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	//videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	//videoTexture.allocate(videoInverted);
	ofSetVerticalSync(true);
}
//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	
	//gakuchoMovie.update();
	//cout << gakuchoMovie.isPlaying() << endl;
	vidGrabber.update();

	/*if (vidGrabber.isFrameNew()) {
		ofPixels& pixels = vidGrabber.getPixels();
		for (size_t i = 0; i < pixels.size(); i++) {
			videoInverted[i] = 255 - pixels[i];
		}
		videoTexture.loadData(videoInverted);
		}*/
	}
			
//--------------------------------------------------------------
void ofApp::draw(){
	gakuchoMovie.draw(0, 0, 400, 300);
	vidGrabber.draw(402,0,400,300);
	gakuchoMovie.draw(200, 302, 400, 300);

	ofSetColor(255, 255, 255,127);
	cout << mouseX  << endl;
	vidGrabber.draw(200, 302, 400, 300);
	ofSetColor(255, 255, 255);
	
	
	//videoTexture.draw(20 + camWidth, 20, camWidth, camHeight);
}

/*//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
*/
void ofApp::mouseMoved(int x, int y ){

}

/*//--------------------------------------------------------------
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

}*/
