#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    // Lets make a Square
    pts.push_back(ofVec3f(200,200,0));
    pts.push_back(ofVec3f(400,200,0));
    pts.push_back(ofVec3f(400,400,0));
    pts.push_back(ofVec3f(200,400.0,0));
    
}
//--------------------------------------------------------------
void testApp::update()
{
   
}
//--------------------------------------------------------------
void testApp::draw()
{
    ofBackground(255);
    ofSetColor(0);
    if (pts.size() >0) {
        ofNoFill();
        ofSetLineWidth(1);
        ofBeginShape();
        for (int i = 0; i < pts.size(); i++) {
            ofVertex(pts[i].x, pts[i].y,0);
            ofCircle(clickPts[i].x, clickPts[i].y,5);
        }
        ofEndShape(true);
    }
    
    ofSetColor(0, 0, 0);
    ofFill();
    ofRect(0, ofGetHeight()-15, ofGetWidth(), 15);
    ofSetColor(255);
    ofDrawBitmapString("Num of Points " + ofToString(pts.size()), 10, ofGetHeight()-5);
}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key) {
        case 'w':
            dxf.writeFile(ofToString(ofGetTimestampString()), pts);
        break;
    }
}
//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    
}
//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}
//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}
//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}
