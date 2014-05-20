#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofMesh mesh1;
    for (int i = 0; i < 12; i++ )
    {
        mesh1.addVertex(ofPoint(ofRandom(-100,100), ofRandom(-100,100), ofRandom(-100,100)));
        mesh1.addColor(ofFloatColor(0,0,0));
    }
    vbo1.setMesh(mesh1, GL_STATIC_DRAW);

    ofMesh mesh2;
    for (int i = 0; i < 12; i++ )
    {
        mesh2.addVertex(ofPoint(ofRandom(-100,100), ofRandom(-100,100), ofRandom(-100,100)));
        mesh2.addColor(ofFloatColor(0,0,0));
    }
    vbo2.setMesh(mesh2, GL_STATIC_DRAW);
    
    ofMesh mesh3;
    for (int i = 0; i < 12; i++ )
    {
        mesh3.addVertex(ofPoint(ofRandom(-100,100), ofRandom(-100,100), ofRandom(-100,100)));
        mesh3.addColor(ofFloatColor(0,0,0));
    }
    vbo3.setMesh(mesh3, GL_STATIC_DRAW);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	   
	shader.load("vert.glsl", "frag.glsl", "geom.glsl");

    doShader = true;
	ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
	if(doShader) {
		shader.begin();
	}

    ofTranslate(ofGetWidth()/2 - 300, ofGetHeight()/2, 0);
    ofSetColor(ofColor(255,0,0,150));
    shader.setUniform1f("thickness", 20);
    vbo1.draw(GL_LINE_STRIP, 0, 60);

    ofTranslate(300, 0, 0);
    ofSetColor(ofColor(0,255,0,150));
    shader.setUniform1f("thickness", 10);
    vbo2.draw(GL_LINE_STRIP, 0, 60);

    ofTranslate(300, 0, 0);
    ofSetColor(ofColor(0,0,255,150));
    shader.setUniform1f("thickness", 3);
    vbo3.draw(GL_LINE_STRIP, 0, 60);

	if(doShader) shader.end();
    

	ofPopMatrix();
	
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()) + "\nPress 's' to toggle shader: " + (doShader ? "ON" : "OFF"), 20, 20);

    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 's' ){
		doShader = !doShader;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}