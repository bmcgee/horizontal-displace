#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cam.setFarClip(10000);
    cam.setNearClip(0);
    
	ofBackground(ofColor::white);
	
	imageMap.load("joel2.png");
	imageMap.resize(100,100);
	
	cols = 100;
	rows = 100;
	height = 1000;
	width = 1000;
	
	int xScalar = height / rows;
	int yScalar = width / cols;
	
	for (int y=0; y<(rows); y++) {
		ofPath path;
		path.moveTo(0, y*yScalar, 0);
		for (int x=1; x<(cols); x++) {
			//ofColor c = imageMap.getColor((x*xScalar),(y*yScalar));
			ofColor c = imageMap.getColor(x,y);

			float z = c.getLightness();
			z = ofMap(z, 0, 255, 0, 10);
			path.lineTo(x*xScalar, y*yScalar, (z));
		}
		path.setStrokeColor(ofColor::black);
		path.setFilled(false);
		path.setStrokeWidth(1);
		paths.push_back(path);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
	cam.begin();
        ofPushMatrix();
            ofTranslate(-500, -500);
                for (int i=0; i < paths.size(); i++) {
                    paths[i].draw();
                }
        ofPopMatrix();
	cam.end();
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
