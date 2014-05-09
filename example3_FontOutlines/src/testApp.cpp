#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    text.loadFont("MarkerFelt.ttc", 100,true,true,true); // You can change the font and size simply drag and drop the font into the data folder and Replace the MarkerFelt.ttc
    words = "Hello World";
    showPtsline = false;
    bFirst = true;
    chars = text.getStringAsPoints(words);
    
    if (chars.size() > 0)
    {
        for (int p = 0; p < chars.size(); p++) {
            charSet s;
            for(int k = 0; k <(int)chars[p].getOutline().size(); k++){
                if( k!= 0)ofNextContour(true);
                for(int i = 0; i < (int)chars[p].getOutline()[k].size(); i++){
                    s.pts.push_back(ofVec3f(chars[p].getOutline()[k].getVertices()[i].x, chars[p].getOutline()[k].getVertices()[i].y,0));
                }
                stringPts.push_back(s);
            }
        }
    }
    cout << stringPts.size() << endl;
}
//--------------------------------------------------------------
void testApp::update()
{

}
//--------------------------------------------------------------
void testApp::draw()
{
    ofBackground(100, 100, 100);
    // Plain Text Output
    ofSetColor(255, 255, 255);
    ofDrawBitmapStringHighlight("Plain Draw String", 60,30);
    text.drawString(words, 50,150);
    
    // Contours String Points
    ofNoFill();
	ofPushMatrix();
    ofTranslate(60, 300, 0);
    ofDrawBitmapStringHighlight("Contours Draw String", 0,-120);
    ofBeginShape();
    if (chars.size() > 0)
    {
        for (int p = 0; p < chars.size(); p++) {
            for(int k = 0; k <(int)chars[p].getOutline().size(); k++){
                if( k!= 0)ofNextContour(true) ;
                for(int i = 0; i < (int)chars[p].getOutline()[k].size(); i++){
                    ofVertex(chars[p].getOutline()[k].getVertices()[i].x, chars[p].getOutline()[k].getVertices()[i].y);
                }
            }
            ofEndShape(true);
        }
    }
    ofPopMatrix();
    
    // Points Output
    ofNoFill();
	ofPushMatrix();
    ofScale(1,1);
    ofTranslate(60, 450, 0);
    ofDrawBitmapStringHighlight("Pts Draw String", 0,-120);
    ofBeginShape();
    if (chars.size() > 0)
    {
        for (int p = 0; p < chars.size(); p++) {
            for(int k = 0; k <(int)chars[p].getOutline().size(); k++){
                if( k!= 0)ofNextContour(true) ;
                
                if (showPtsline == true) {
                    for(int i = 0; i < (int)chars[p].getOutline()[k].size(); i++){
                        ofVertex(chars[p].getOutline()[k].getVertices()[i].x, chars[p].getOutline()[k].getVertices()[i].y);
                    }
                }
                else
                {
                    //Don't Draw Lines
                }
                
                for(int i = 0; i < (int)chars[p].getOutline()[k].size(); i+=7){
                    ofPushStyle();
                    ofFill();
                    ofSetColor(ofColor::red);
                    ofCircle(chars[p].getOutline()[k].getVertices()[i].x, chars[p].getOutline()[k].getVertices()[i].y, 2);
                    ofPopStyle();
                }
            }
            ofEndShape(true);
        }
    }
    ofPopMatrix();
    
    
    // Dxf Points Output
    ofNoFill();
	ofPushMatrix();
    ofTranslate(60,600);
    ofDrawBitmapStringHighlight("DXF Output", 0,-120);
    ofSetColor(255, 0, 0);
    ofBeginShape();
    if (stringPts.size() > 0)
    {
        for (int p = 0; p < stringPts.size(); p++) {
            for(int k = 0; k <(int)stringPts[p].pts.size(); k++){
                ofVertex(stringPts[p].pts[k].x, stringPts[p].pts[k].y);
            }
            ofEndShape(true);
        }
    }
    ofPopMatrix();
    
    stringstream info;
    info << "Press 'ENTER' to Save File" << endl;
    info << "Press '=' to push the new string" << endl;
    info << "Press ']' to clear the points" << endl;
    info << "Number of Characters: " << chars.size() << endl;
    
    ofDrawBitmapStringHighlight(info.str(), 0,ofGetHeight()-60);

}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		words = words.substr(0, words.length()-1);
	}
	else if(key == OF_KEY_RETURN ){

        dxf.writeFile(ofToString(ofGetTimestampString()));
        if (stringPts.size() > 0)
        {
            for (int p = 0; p < stringPts.size(); p++) {
                if (p <= stringPts.size()) {
                    dxf.addPoints(stringPts[p].pts, false);
                }
                else
                {
                    dxf.addPoints(stringPts.back().pts, true);
                }
            }
            
        }
        dxf.endFile();
	}
    else if (key == '=')
    {
        chars = text.getStringAsPoints(words);
        
        if (chars.size() > 0)
        {
            for (int p = 0; p < chars.size(); p++) {
                charSet s;
                for(int k = 0; k <(int)chars[p].getOutline().size(); k++){
                    if( k!= 0)ofNextContour(true);
                    for(int i = 0; i < (int)chars[p].getOutline()[k].size(); i++){
                        s.pts.push_back(ofVec3f(chars[p].getOutline()[k].getVertices()[i].x, chars[p].getOutline()[k].getVertices()[i].y,0));
                    }
                    stringPts.push_back(s);
                }
            }
        }
        cout << stringPts.size() << endl;
    }
    else if(key == ']')
    {
        stringPts.clear();
        chars.clear();
        words.clear();
    }
    else{
		if( bFirst ){
			words.clear();
			bFirst = false;
		}
		words.append(1, (char)key);
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
//-------------------------------------------------------------
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