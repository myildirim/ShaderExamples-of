#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	ofDisableArbTex();
	carImage.load("car.png");
	bikeImage.load("bike.png");
	busImage.load("bus.png");
	carTexture = carImage.getTexture();
	bikeTexture = bikeImage.getTexture();
	busTexture = busImage.getTexture();
	textureArray = {carTexture, bikeTexture, busTexture};

	ofEnableArbTex();

	shader.load("shaders/vertexRotationShader");

	numVertices = 100;

	initVbo();
}

//--------------------------------------------------------------
void ofApp::update(){
	// calculate the angle of each vertex to the mouseposition
	// set the x value of the normal as the angle
	for(int i=0; i<numVertices; i++){
		ofVec3f point = points.at(i);
		ofVec3f diff = ofVec3f(ofGetMouseX(), ofGetMouseY()) - point;
		float angle = atan2(diff.x, diff.y);
		normals.at(i).x = angle;
	}

	// set data of VBO to pass to shader
	vbo.setVertexData(&points[0], numVertices, GL_STATIC_DRAW);
	vbo.setNormalData(&normals[0], numVertices, GL_STATIC_DRAW);
	vbo.setColorData(&colors[0], numVertices, GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	shader.begin();

	int numTextures = textureArray.size();

	vector<int> locations;
	locations.resize(numTextures);

	for(int i=0; i<numTextures; i++){
		// set texture location
		locations[i] = i+1;
		// bind the texture
		setUniformTexture(textureArray[i],locations[i]);
	}

	// pass the textures to the shader
	const int * l = &locations[0];
	shader.setUniform1iv("textureArray", l, numTextures);

	vbo.draw(GL_POINTS, 0, (int)points.size());
	shader.end();

}

void ofApp::setUniformTexture(const ofTexture& tex, int textureLocation){
	ofTextureData texData = tex.getTextureData();
	glActiveTexture(GL_TEXTURE0 + textureLocation);
	glEnable(texData.textureTarget);
	glBindTexture(texData.textureTarget, texData.textureID);
	glDisable(texData.textureTarget);
}

void ofApp::initVbo(){
	for(int i=0; i<numVertices; i++){
		// set vertex position
		float x = ofRandom(0, ofGetWidth());
		float y = ofRandom(0, ofGetHeight());
		points.push_back(ofVec3f(x,y));

		// use the normal to pass angle, size and the type
		float angle = 0;
		float size = 100;
		float type = ofRandom(0,3);
		normals.push_back(ofVec3f(angle,size,type));

		// set vertex color
		ofColor color(255,0,0);
		color.set(color.r, color.g, color.b, 255);

		ofFloatColor normalizedColor = color.getNormalized();
		colors.push_back(normalizedColor);
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
