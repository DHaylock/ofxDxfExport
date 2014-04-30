/*
Name: ofxDxfExport.h
Project: DXF Exporter
Author: David Haylock
Creation Date: 2014-28-04
Copyright: (c) 2014 by Watershed Arts Trust Ltd.
*/


#include <iostream>
#include <fstream>
#include "ofMain.h"

class ofxDxfExport {
    public:
    
        ofxDxfExport();
    
        ofFile os;
        void writeFile(string path,vector <ofVec3f> pts);

    private:
    
        void writeHOF();
        void writeTable();
        void writeBlock();
        void addPoints(vector <ofVec3f> pts);
        void writeDictionary();
        void writeEOF();
};


