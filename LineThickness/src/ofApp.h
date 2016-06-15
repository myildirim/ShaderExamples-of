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
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofShader shader;
		bool doShader;

		ofPath path;
		ofPolyline polyline;
		ofPolyline polylineToDraw;

		ofMesh mesh;
		ofMesh meshUp; // expand the line to one direction for debug
		ofMesh meshDown; // expand the line to other direction for debug


		ofxPanel gui;
		ofxFloatSlider thickness;
		ofxColorSlider color;
		ofxFloatSlider spacing;
		ofxToggle drawDebug;

		float prevSpacing;
		float prevThickness;

		void generateMesh();
		void drawPolygonAndNormals();
		void setupGui();
};
