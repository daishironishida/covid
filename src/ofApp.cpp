#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);

    int width = 1000;
    int height = 1000;
    world.allocate(width, height, GL_RGBA);

    for (int i = 0; i < 100; i++) {
        population.emplace_back(ofRandom(width), ofRandom(height), width, height);
    }
    population.emplace_back(width / 2, height / 2, width, height, InfectionState::INFECTED);
}

//--------------------------------------------------------------
void ofApp::update(){
    // update position of population
    for (auto& person : population) {
        person.update();
    }

    // update states
    int infectionRadius = 10;
    for (int i = 0; i < population.size(); i++) {
        for (int j = i + 1; j < population.size(); j++) {
            ofVec2f pos_i = population[i].getPosition();
            ofVec2f pos_j = population[j].getPosition();
            if (ofDist(pos_i.x, pos_i.y, pos_j.x, pos_j.y) < infectionRadius) {
                Person::contact(population[i], population[j]);
            }
        }
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
