#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);

    world.allocate(1000, 1000, GL_RGBA);

    population.emplace_back(ofGetWindowWidth(), ofGetWindowHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    // update position and state of population
    for (auto& person : population) {
        person.update();
    }

    // draw population into fbo
    world.begin();
    ofClear(255,255,255, 0);
    for (const auto& person : population) {
        person.draw();
    }
    world.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw fbo (keep aspect ratio intact)
    int windowWidth = ofGetWindowWidth();
    int windowHeight = ofGetWindowHeight();

    int drawWidth, drawHeight;
    if (windowWidth * world.getHeight() < windowHeight * world.getWidth()) {
        drawWidth = windowWidth;
        drawHeight = windowWidth * world.getHeight() / world.getWidth();
    } else {
        drawWidth = windowHeight * world.getWidth() / world.getHeight();
        drawHeight = windowHeight;
    }

    world.draw(0, 0, drawWidth, drawHeight);
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
