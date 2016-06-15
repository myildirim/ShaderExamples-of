#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// sprite sheet variables start
	spriteSheetNumRows = 2.0;
	spriteSheetNumCols = 8.0;
	string spriteSheetFileName = "sprite.png";

//	spriteSheetNumRows = 5.0;
//	spriteSheetNumCols = 6.0;
//	string spriteSheetFileName = "walker.png";

	// sprite sheet variables end

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    ofDisableArbTex();
	spriteSheetImg.load(spriteSheetFileName);
	spriteSheetTexture = spriteSheetImg.getTexture();
    ofEnableArbTex();

	numVertices = 200;

	// what is the ratio of an individual sprite?
	// in our 'sprite.png' example, it is a 8x2 sprite sheet
	// texture coordinates point size needs to be (w,h) = 1/[num_cols] , 1/[num_rows]
	// texture point size needs to be 1/8 = 0.125 , 1/2 = 0.5
	textureCoordPointSize.set(1/spriteSheetNumCols, 1/spriteSheetNumRows);

	numSprites = spriteSheetNumRows * spriteSheetNumCols;
	types.resize(numVertices);

	for(int i=0; i<numVertices; i++){
		// set position of vertices
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
		points.push_back(ofVec3f(x,y));
		// randomize type
		types[i] = int(ofRandom(numSprites));
    }

	setupGui();
	shader.load("shaders/spriteShader");
	vbo.setVertexData(&points[0], numVertices, GL_STATIC_DRAW);

}

//--------------------------------------------------------------
void ofApp::update(){

	if(enableTypeSlider){
		// set image type from the slider
		for(int i=0; i<numVertices; i++){
			types[i] = imgType;
		}
	} else  if(enableTypeSlider != prevenableTypeSlider){
		// randomize types once when state changes from true to false
		for(int i=0; i<numVertices; i++){
			types[i] = int(ofRandom(numSprites));
		}
	}

	vbo.setAttributeData(shader.getAttributeLocation("imgType"),
						 &types[0], 1,
			types.size(), GL_STATIC_DRAW, sizeof(float));

	prevenableTypeSlider = enableTypeSlider;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

	shader.begin();
	// spriteSheet properties
	shader.setUniform1f("numCols", spriteSheetNumCols);
	shader.setUniform1f("numRows", spriteSheetNumRows);
	// pass the pointsize
	shader.setUniform1f("pointSize", pointSize);
	// this is calculated in the setup
	shader.setUniform2f("textureCoordPointSize", textureCoordPointSize.x, textureCoordPointSize.y);
	// pass the sprite sheet
	shader.setUniformTexture("textureIn", spriteSheetTexture, 1);


    vbo.draw(GL_POINTS, 0, (int)points.size());

	shader.end();
    gui.draw();

	ofSetColor(255);
	ofDrawBitmapString("Framerate : " + ofToString(ofGetFrameRate()), 20, 220);

}

void ofApp::setupGui()
{
    gui.setup("settings");

	gui.add(imgType.setup("imgType", 0, 0, numSprites-1));
	gui.add(enableTypeSlider.setup("enableTypeSlider", false));
	gui.add(pointSize.setup("pointSize", 60, 0, 1000));

    gui.loadFromFile("settings.xml");

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'a'){
		shader.load("shaders/spriteShader");
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
