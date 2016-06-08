#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
	ofImage img;
	ofTexture texture;

    ofVbo vbo;
    vector <ofVec3f> points;
    vector <ofFloatColor> colors;
    vector <ofVec3f> normals;
    int numVertices;

    void setupGui();
    ofxPanel gui;
    ofxFloatSlider pSize;
    ofxVec2Slider coordPSize;
    ofxVec2Slider coordIn;


    float counter;
};
