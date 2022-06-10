#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    gui.setup();

    params->load();
    createWorld();
}

//--------------------------------------------------------------
void ofApp::createWorld() {
    world.allocate(params->worldWidth, params->worldHeight, GL_RGBA);

    population.clear();
    for (int i = 0; i < params->initialPopulation; i++) {
        InfectionState state = InfectionState::UNVACCINATED;
        if (ofRandom(1) < params->initialVaccinationRate) {
            state = InfectionState::VACCINATED;
        }
        if (ofRandom(1) < params->initialInfectionRate) {
            state = InfectionState::LATENT;
        }
        population.emplace_back(ofRandom(params->worldWidth), ofRandom(params->worldHeight), params->worldWidth, params->worldHeight, state);
    }
}
    
//--------------------------------------------------------------
void ofApp::update(){
    // reset world
    if (params->resetWorld) {
        createWorld();
    }

    // update position/state of population
    for (auto& person : population) {
        person.update();
    }

    // update contact information
    for (int i = 0; i < population.size(); i++) {
        for (int j = i + 1; j < population.size(); j++) {
            ofVec2f pos_i = population[i].getPosition();
            ofVec2f pos_j = population[j].getPosition();
            if (ofDist(pos_i.x, pos_i.y, pos_j.x, pos_j.y) < params->infectionRadius) {
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

    // draw gui
    drawGui();
}

//--------------------------------------------------------------
void ofApp::drawGui() {
    gui.begin();
    if (ImGui::Begin("Settings")) {
        params->drawGui();
        ImGui::End();
    }
    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        params->save();
    } else if (key == 'l') {
        params->load();
    }
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
