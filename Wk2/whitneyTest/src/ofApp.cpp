#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int CIRCLE_WIDTH = 15; // space between circles
    int CIRCLE_DR = 1; //used to thicken up the line when drawing circles
    int N_CIRCLES = 20;
    int BREATHING_RATE = 2.5;
    int INNER_BREATHING = 2;
    
    float x_orig = 400;
    float y_orig = 400;
//    float theta = ofGetElapsedTimef() * 10;
    
    ofNoFill();
    ofBackground(0,0,0);
    ofSetCircleResolution(100);
    
    
    for(int i = 0; i < N_CIRCLES; i++){
        bool draw_circle = true;
        float radius = 50 + (i * CIRCLE_WIDTH);
        float sine_time = sin(.1*BREATHING_RATE * ofGetElapsedTimef());
        
        float sine_deriv = cos(.1*BREATHING_RATE * ofGetElapsedTimef()); // can track whether we are going up or down!! Cos is first deriv of sine
        
        float breathing_index = ofMap(sine_time, -1, 1, 0, N_CIRCLES);
//        int drawing_index = ofMap(sin(.1*BREATHING_RATE * ofGetElapsedTimef() - 1.57), -1, 1, 0, N_CIRCLES);
        
        // (NON-ACTIVE) CIRCLE COLORING
        int r = 225;
        int g = 33;
        int b = 0;
        
        if ((i >= N_CIRCLES / 3) && (i < 2*N_CIRCLES / 3)) { //middle sixth
            r = 255;
            g = 66;
            b = 147;
        }
        
        if (sine_deriv < 0) { //change default color to green on the way down
            r = 0;
            g = 255;
            b = 0;
        }
        
        ofLogNotice() << "i, sine_deriv, breathing index: " << i << "," << sine_deriv << ", " << breathing_index;

        if (i < breathing_index) {
            
            if (sine_deriv < 0 && breathing_index < N_CIRCLES) { //change default color to yellow orange for inner circles on way down
                r = 225;
                g = 221;
                b = 66;
            } else if (i < N_CIRCLES / 3) { // first third
                r = 0;
                g = 0;
                b = 255;
            } else if ((i >= N_CIRCLES / 3) && (i < N_CIRCLES / 2)) { //middle sixth
                r = 255;
                g = 66;
                b = 147;
            } else { //last half
                r = 0;
                g = 255;
                b = 0;
            }
            
            //perturb radius slightly just to give sense of multiple circles
            radius += (breathing_index - i - 1) * CIRCLE_WIDTH - .5*i;
        }
        
//        if (i <= drawing_index) {
//            draw_circle = false;
//        }
        
        ofSetColor(r,g,b);
        
        if(draw_circle) {
            ofDrawCircle(x_orig, y_orig, radius); //3 calls to fatten up the lines
            ofDrawCircle(x_orig, y_orig, radius + CIRCLE_DR);
            ofDrawCircle(x_orig, y_orig, radius - CIRCLE_DR);
        }
        
        
        float theta = ofGetElapsedTimef();// * 10*(i+1);
        float x_actual = x_orig + radius * cos(theta);
        float y_actual = y_orig + radius * sin(theta);
        float orbit_radius = 100 + (i+1 * 100) * sin(ofGetElapsedTimef());
        
//        trail.addVertex(x_actual,y_actual);
//        trail.draw();
//
//        if (trail.size() > 200) {
//            trail.getVertices().erase(trail.getVertices().begin());
//        }
//        ofLogNotice() << "r,g,b: " << r << "," << g << ", " << b;

    }
    
    
    
    
    
    
//    for(int i = 0; i < 80; i++){
//        float amp = ofMap(i, 0,80, 0, 400); // map index of circle to larger range
//        float x_pos = ofMap(sin(ofGetElapsedTimef()) + 0.1*i, -1, 1, 0, ofGetWidth());
//        ofDrawCircle(x_pos, i*10, 5);
//    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        trail.clear();
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
