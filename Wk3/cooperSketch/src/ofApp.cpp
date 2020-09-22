#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    font.load("framd.ttf", 100, true, true, true);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    int TEXT_OFFSET = 100;
    
    vector<std::string> names;
    vector<std::string> groups;
    
    names.push_back("Ted Adelson");
    groups.push_back("Mid-level Vision");
    
    names.push_back("Aaron Bobick");
    groups.push_back("Scene-level Vision");
    
    names.push_back("Richard Bolt");
    groups.push_back("Muti-modal Interaction");
    
    names.push_back("Alex Pentland");
    groups.push_back("Looking at People");
    
    names.push_back("Rosalind Picard");
    groups.push_back("Vision Texture");
    
    names.push_back("Chris Schmandt");
    groups.push_back("Speech");
    
    names.push_back("Barry Vercoe");
    groups.push_back("Synthetic Listeners \n & performers");

    
    ofEnableDepthTest();

    cam.begin(); //use 3d cam
//    ofDrawAxis(200); //show the axes of our 3d world
    
    for (int i=0; i < names.size(); i++) {
        ofPushMatrix(); //store the coordinate system we drew 'hello' in on a stack
        ofScale(1,-1);

        ofSetColor(255,255,255); //change color to red to draw 'hello'
        vector<ofPath> namePath = font.getStringAsPoints(names[i]);
        vector<ofPath> groupPath = font.getStringAsPoints(groups[i]);
        ofTranslate(0, i * TEXT_OFFSET);
        
        for(int j =0; j < namePath.size(); j++) {
            namePath[j].draw();

            /* Makes wiggly transparent outlines */
//            namePath[j].setPolyWindingMode(OF_POLY_WINDING_ODD);
//            vector <ofPolyline> lines = namePath[j].getOutline();
//
//            for (int k = 0; k < lines.size(); k++) {
//                lines[k].setClosed(true);
//                lines[k] = lines[k].getResampledBySpacing(3);
//
//                for (int l = 0; l < lines[k].size(); l++) {
//                    lines[k][l].x += 10*sin(2*(ofGetElapsedTimef() + .05*lines[k][l].y + 10*j));
//                }
//                lines[k].draw();
//            }
            
        }
        ofPopMatrix();
        
        ofPushMatrix(); //switch coordinate frame to draw group names
        ofScale(1,-1);

        ofRotateYDeg(70); //rotate coordinate system 90 degree in Y.
        ofSetColor(152, 251,152); //now change to green to draw group names
        ofTranslate(0, i * TEXT_OFFSET);

        for(int j=0; j < groupPath.size(); j++) {
            groupPath[j].draw();
        }
        ofPopMatrix();
    }
        

            
        
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
