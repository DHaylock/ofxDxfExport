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
    
    if (dragPtsLeft.size() >0) {
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(0);
        ofBeginShape();
        for (int i = 0; i < dragPtsLeft.size(); i++) {
            ofVertex(dragPtsLeft[i].x, dragPtsLeft[i].y,0);
            ofSetColor(255, 0, 0);
            ofCircle(dragPtsLeft[i].x, dragPtsLeft[i].y,5);
        }
        ofEndShape(true);
    }
    
    
    if (dragPtsRight.size() >0) {
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(0);
        ofBeginShape();
        for (int i = 0; i < dragPtsRight.size(); i++) {
            ofVertex(dragPtsRight[i].x, dragPtsRight[i].y,0);
            ofSetColor(0,255,0);
            ofCircle(dragPtsRight[i].x, dragPtsRight[i].y,5);
        }
        ofEndShape(true);
    }
    
    ofSetColor(0, 0, 0);
    ofFill();
    ofRect(0, ofGetHeight()-70, ofGetWidth(), 70);
    ofSetColor(255);
    stringstream s;
    s << "Click in window to start making points. Use Left and Right Clicks." << endl;
    s << "Number of Points Left " + ofToString(dragPtsLeft.size()) + "   Number of Points Right " + ofToString(dragPtsRight.size()) << endl;
    s << "Click 'r' to reset points" << endl;
    s << "Click 'w' to write points to File" <<endl;
    
    ofDrawBitmapString(s.str(), 10,ofGetHeight()-50);
}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key) {
        case 'w':
            dxf.writeFile(ofToString(ofGetTimestampString()));
            dxf.addPoints(dragPtsLeft, false);
            dxf.addPoints(dragPtsRight, true);
            dxf.endFile();
            break;
        case 'r':
            dragPtsLeft.clear();
            dragPtsRight.clear();//clear all points
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
    if (button == OF_MOUSE_BUTTON_LEFT)
    {
        dragPtsLeft.push_back(ofVec3f(x,y,0));
    }
    else if(button == OF_MOUSE_BUTTON_RIGHT) // Right Button
    {
        dragPtsRight.push_back(ofVec3f(x,y,0));
    }
    else
    {
        //Nothing
    }
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
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
