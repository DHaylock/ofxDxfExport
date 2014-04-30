#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{

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
    if (clickPts.size() >0) {
        ofNoFill();
        ofSetLineWidth(1);
        ofBeginShape();
        for (int i = 0; i < clickPts.size(); i++) {
            ofVertex(clickPts[i].x, clickPts[i].y,0);
            ofCircle(clickPts[i].x, clickPts[i].y,5);
        }
        ofEndShape(true);
    }
    
    ofSetColor(0, 0, 0);
    ofFill();
    ofRect(0, ofGetHeight()-20, ofGetWidth(), 20);
    ofSetColor(255);
    ofDrawBitmapString("Click in window to start making points. Number of Points " + ofToString(clickPts.size()) +  "  Click 'r' to reset points : Click 'w' to write points to File", 10, ofGetHeight()-5);

}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key) {
        case 'w':
            dxf.writeFile(ofToString(ofGetTimestampString()), clickPts);
            break;
        case 'r':
            clickPts.clear(); //clear all points
            break;
        case '<':
            clickPts.erase(clickPts.end()-1); // delete last point
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
    clickPts.push_back(ofVec3f(x,y,0));
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