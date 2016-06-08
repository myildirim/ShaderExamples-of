#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 1; i < 10; i++ )
	{
		ofPoint v = ofPoint(i*90,
							ofRandom(-100+ofGetHeight()/2,100+ofGetHeight()/2),
							0);
		polyline.addVertex(v);
		polylineToDraw.addVertex(v);
	}

	setupGui();

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();

	shader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom.glsl");

	doShader = true;
	generateMesh();
	prevSpacing = spacing;
	prevThickness= thickness;
}

//--------------------------------------------------------------
void ofApp::update(){
	polylineToDraw = polyline.getResampledBySpacing(spacing);
	if (prevSpacing != spacing || prevThickness != thickness){
		generateMesh();
	}
	prevSpacing = spacing;
}

//--------------------------------------------------------------
void ofApp::draw(){

	if(drawDebug){
		drawPolygonAndNormals();
	}

	ofPushMatrix();
	if(doShader) {
		shader.begin();
	}
	ofSetColor(color);

	shader.setUniform1f("thickness", thickness);
	mesh.draw();
	if(doShader) shader.end();

	ofPopMatrix();

	gui.draw();
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate())
					   + "\nPress 's' to toggle shader: " + (doShader ? "ON" : "OFF")
					   + "\nPress 'a' to reload shader."
					   + "\nNumber of vertices: " + ofToString(polyline.getVertices().size()),
					   20, 200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if( key == 's' ){
		doShader = !doShader;
	}
	else if( key == 'a' ){
		shader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom.glsl");
	}
	else if( key == 'a' ){
		generateMesh();
	}
}

void ofApp::generateMesh(){
	mesh.clear();
	meshUp.clear();
	meshDown.clear();
	mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
	meshUp.setMode(OF_PRIMITIVE_LINE_STRIP);
	meshDown.setMode(OF_PRIMITIVE_LINE_STRIP);
	for(int i=0; i<polylineToDraw.getVertices().size(); i++){
		ofVec3f n0 =  polylineToDraw.getNormalAtIndex(i);
		ofPoint p0 = polylineToDraw.getVertices()[i];
//		ofPoint p1 = polyline.getVertices()[i+1];
//		ofVec2f n1 = polyline.getNormalAtIndex(i+1); // miter

		mesh.addVertex(p0);
		mesh.addIndex(i);
		mesh.addNormal(n0);

		mesh.addColor(ofFloatColor(1.0, 0, 0, 1.0));
//		float length = thickness / n0.dot(n0);
		float length = thickness;

		meshUp.addVertex(p0+n0*length);
		meshDown.addVertex(p0-n0*length);
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
	polyline.addVertex(x,y);
	polylineToDraw.addVertex(x,y);
	generateMesh();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	polyline.addVertex(x,y);
	polylineToDraw.addVertex(x,y);
	generateMesh();
}

void ofApp::drawPolygonAndNormals()
{
	ofPushMatrix();
	ofSetColor(0,255,0);
	mesh.draw();
	for(int i=0; i<polylineToDraw.getVertices().size(); i++){
		ofVec3f normal =  polylineToDraw.getNormalAtIndex(i);
		ofPoint p = polylineToDraw.getVertices()[i];
		normal *= thickness;
		ofLine(p.x, p.y, p.x+normal.x, p.y+normal.y);
		normal *=-1;
		ofLine(p.x, p.y, p.x+normal.x, p.y+normal.y);
	}
	ofSetColor(0,255,255);
	meshUp.draw();
	ofSetColor(0,255,255);
	meshDown.draw();
	ofPopMatrix();
}

void ofApp::setupGui()
{
	gui.setup("settings");
	gui.add(thickness.setup("thickness", 10, 0, 100));
	gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));\
	gui.add(spacing.setup("spacing", 5, 1, 100));
	gui.add(drawDebug.setup("debug", true));
	gui.loadFromFile("settings.xml");
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
