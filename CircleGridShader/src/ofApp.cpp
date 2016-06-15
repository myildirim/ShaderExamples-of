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

	// init data
	data.assign(numPoints, 0);

    mesh = initMesh(numPoints);

}

//--------------------------------------------------------------
void ofApp::update() {

    int maxIndex = rows * cols;

    // increase point size if the mouse is hovered
    for ( int index = 0; index < maxIndex; index++ ) {
        ofVec3f point = mesh.getVertices()[index];
        if ( ofDist( ofGetMouseX(), ofGetMouseY(), point.x, point.y ) < 100 ) {
            data.at( index ) += 5;
        }
    }

    // decrease point size automatically overtime
    for ( int index = 0; index < maxIndex; index++ ) {
        float dataValue = data.at( index );
        if ( dataValue > 0 ) {
            data.at( index )--;
        }
    }

    // pass the pointsizes as data array to the VBO
    mesh.getVbo().setAttributeData( shader.getAttributeLocation( "pointsize" ),
                                    &data[0],
                                    1,
                                    data.size(),
                                    GL_STATIC_DRAW,
                                    sizeof( float ) );
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
ofVboMesh ofApp::initMesh(int numPoints){
    ofVboMesh mesh;
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
    return mesh;
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
