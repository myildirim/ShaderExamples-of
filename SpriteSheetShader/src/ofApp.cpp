#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    ofDisableArbTex();

    img.load("sprite.png");
	texture = img.getTexture();

    shader.load("shaders/spriteShader");

    ofEnableArbTex();


	numVertices = 500;

	types.resize(numVertices);
    for(int i=0; i<numVertices; i++){
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
        points.push_back(ofVec3f(x,y));
		types.at(i) = 0.125 * int(ofRandom(8));
    }

	points[0].x = ofGetWidth()/2;
    points[0].y = ofGetHeight()/2;

    setupGui();
    counter = 0.0;
	shader.load("shaders/spriteShader");
	vbo.setVertexData(&points[0], numVertices, GL_STATIC_DRAW);

}

//--------------------------------------------------------------
void ofApp::update(){

	vbo.setAttributeData(shader.getAttributeLocation("t"),
						 &types[0], 1,
			types.size(), GL_STATIC_DRAW, sizeof(float));

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

	// get mouse position relative to center of screen
	float mousePositionX = ofMap(mouseX, 0, ofGetWidth(), 0, -ofGetWidth(), true);
	float mousePositionY = ofMap(mouseY, 0, ofGetHeight(), 0, -ofGetHeight(), true);

	shader.begin();
    shader.setUniform1f("PointSize", pSize);
    shader.setUniform2f("TextureCoordPointSize", coordPSize->x, coordPSize->y);
	shader.setUniform2f("TextureCoordIn", coordIn->x, coordIn->y);
    shader.setUniformTexture("Sampler", texture, 1);

    vbo.draw(GL_POINTS, 0, (int)points.size());

	shader.end();

    gui.draw();


	ofSetColor(255);
	ofDrawBitmapString("Use 'l' key to change the sprite", 20, 200);
	ofDrawBitmapString("Framerate : " + ofToString(ofGetFrameRate()), 20, 220);

}

void ofApp::setupGui()
{
    gui.setup("settings");

    gui.add(pSize.setup("pointSize", 60, 0, 1000));
    gui.add(coordPSize.setup("textureCoordPointSize", ofVec2f(0,0),
                          ofVec2f(0,0),
                          ofVec2f(1,1)));
    gui.add(coordIn.setup("TextureCoordIn", ofVec2f(0,0),
                          ofVec2f(0,0),
                          ofVec2f(1,1)));

    gui.loadFromFile("settings.xml");

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'a'){
		shader.load("shaders/spriteShader");
	} else if (key == 'l'){
		for(int i=0; i<numVertices; i++){
			float value = types.at(i);
			if(value >= 1 - 0.125){
				types.at(i) = 0;
			} else {
				types.at(i) += 0.125;
			}
		}
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
