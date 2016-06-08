#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

	shader.load("shaders/circleShader");

	ofDisableArbTex();
	dotImg.load("dot.png");
	ofEnableArbTex();

	rows = 10;
	cols = 10;
	int numPoints = rows*cols;

	data.resize(numPoints);

	// initialize data
	for(int i=0; i<rows*cols; i++){
		data.at(i) = ofRandom(5,20);
	}

	initMesh(numPoints);

}

//--------------------------------------------------------------
void ofApp::update(){

	// increase point size if the mouse is hovered
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int index = i + j*cols;
			ofVec3f point = mesh.getVertices()[index];

			if(ofDist(ofGetMouseX(), ofGetMouseY(), point.x, point.y) < 100){
				data.at(index)+=5;
			}
		}
	}

	// decrease point size automatically overtime
	for(int i=0; i<rows*cols; i++){
		float dataValue = data.at(i);
		if(dataValue>0){
			data.at(i)--;
		}
	}

	// pass the pointsizes as data array to the VBO
	mesh.getVbo().setAttributeData(shader.getAttributeLocation("pointsize"),
									   &data[0], 1,
									   data.size(), GL_STATIC_DRAW, sizeof(float));

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofSetColor(255,0,0);

	shader.begin();
	dotImg.bind();
	mesh.draw();

	dotImg.unbind();
	shader.end();

}

//--------------------------------------------------------------
void ofApp::initMesh(int numPoints){
	mesh.setMode(OF_PRIMITIVE_POINTS);
	mesh.getVertices().resize(numPoints);
	mesh.getColors().resize(numPoints);

	float xOffset = ofGetWidth()/cols/2;
	float yOffset = ofGetHeight()/rows/2;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int index = i + j*cols;

			ofVec3f point;
			point.x = i * ofGetWidth()/cols + xOffset;
			point.y = j * ofGetHeight()/rows + yOffset;

			mesh.getVertices()[index].x = point.x;
			mesh.getVertices()[index].y = point.y;

			mesh.getColors()[index].r = ofRandom(0,1);
			mesh.getColors()[index].g = ofRandom(0,1);
			mesh.getColors()[index].b = ofRandom(0,1);

		}
	}
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
