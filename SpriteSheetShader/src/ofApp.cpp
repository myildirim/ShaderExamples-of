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


	numVertices = 5;

    for(int i=0; i<numVertices; i++){
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
        points.push_back(ofVec3f(x,y));
    }

    points[0].x = ofGetWidth()/2;
    points[0].y = ofGetHeight()/2;

    setupGui();
    counter = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
	shader.load("shaders/spriteShader");

    vbo.setVertexData(&points[0], numVertices, GL_STATIC_DRAW);
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

	ofDrawBitmapString("Use arrow keys to change the sprite", 20, 200);

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
    if(counter>=1-0.125){
        counter = 0;
    } else {
        counter += 0.125;
    }
    ofLogNotice("keyPressed") << counter;
    coordIn = ofVec2f(counter,0);

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
