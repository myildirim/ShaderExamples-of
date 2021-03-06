#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofShader shader;
	ofVbo vbo;

    vector<ofTexture> textureVector;

	vector <ofVec3f> points;
	vector <ofFloatColor> colors;
	vector <ofVec3f> normals;

	int numVertices;

	void setUniformTexture(const ofTexture& tex, int textureLocation);
    void initVbo();
    void bindMultipleTextures(ofShader &shader, vector<ofTexture> &textureVector);
};
