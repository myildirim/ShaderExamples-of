#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	int rows = 10;
	int cols = 20;

	mesh.setMode(OF_PRIMITIVE_LINES);

	for(int i=0; i<rows; i++){
		ofVec2f point1(0, i * ofGetHeight()/rows);
		mesh.addVertex(point1);
		ofVec2f point2(ofGetWidth(), i * ofGetHeight()/rows);
		mesh.addVertex(point2);
	}

	for(int j=0; j<cols; j++){
		ofVec2f point1(j * ofGetWidth()/cols, 0);
		mesh.addVertex(point1);
		ofVec2f point2(j * ofGetWidth()/cols, ofGetHeight());
		mesh.addVertex(point2);
	}


	shader.load("shaders/gradientShader.vert",
				"shaders/gradientShader.frag",
				"shaders/gradientShader.geom");

	setupGui();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofSetColor(color);

	float x, y;
	x = ofGetMouseX();
	y = ofGetHeight()-ofGetMouseY();

	shader.begin();

	shader.setUniform2f("center", x, y);
	shader.setUniform1f("maxDistance", maxDistance);
	shader.setUniform1f("thickness", lineThickness);

	mesh.draw();
	shader.end();

	gui.draw();
}

void ofApp::setupGui()
{
	gui.setup("settings");

	gui.add(maxDistance.setup("maxDistance", 140, 0, ofGetWidth()/2));
	gui.add(lineThickness.setup("lineThickness", 5, 0, 10));

	gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));

	gui.loadFromFile("settings.xml");

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
