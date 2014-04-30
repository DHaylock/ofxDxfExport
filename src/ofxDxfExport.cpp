/*
 Name: ofxDxfExport.cpp
 Project: DXF Exporter
 Author: David Haylock
 Creation Date: 2014-28-04
 Copyright: (c) 2014 by Watershed Arts Trust Ltd.
 */

#include "ofxDxfExport.h"

//--------------------------------------------------------------
ofxDxfExport::ofxDxfExport()
{
    
}
//--------------------------------------------------------------
void ofxDxfExport::writeFile(string path,vector<ofVec3f> pts)
{

    os.open(path+".dxf",ofFile::WriteOnly);
    writeHOF();
    writeTable();
    writeBlock();
    addPoints(pts);
    writeDictionary();
    writeEOF();
    ofSystemAlertDialog("DXF " + path + " Created");
}
//----------------------------------------------------------------
void ofxDxfExport::addPoints(vector<ofVec3f> pts)
{
    os << "SECTION" << endl;
    os << "  2" << endl;
    os << "ENTITIES" << endl;
    os << "  0" << endl;

    if (pts.size() > 0) {
        os << "LWPOLYLINE" << endl;
        os << "5" << endl;
        os << "100" << endl;
        os << "100" << endl;
        os << "AcDbEntity" << endl;
        os << "8" << endl;
        os << "0" << endl;
        os << "62" << endl;
        os << "7" << endl;
        os << "100" << endl;
        os << "AcDbPolyline" << endl;
        os << "90" << endl;
        os << pts.size() << endl; // Our point size
        os << "70" << endl;
        os << "0" << endl;
        int pointCount = pts.size();
        cout << pointCount << endl;
        for(int i =0; i < pts.size(); i++)
        {
            os << "10" << endl;
            os << ofToString(pts[i].x) << endl;
            os << "20" << endl;
            os << ofToString(pts[i].y) << endl;
            os << "30" << endl;
            os << "0.0" << endl;
            
        }
        // Close the loop
        os << "10" << endl;
        os << ofToString(pts[0].x) << endl;
        os << "20" << endl;
        os << ofToString(pts[0].y) << endl;
        os << "30" << endl;
        os << "0.0" << endl;
        os << "0" << endl;
    }
    
    os << "ENDSEC" << endl;
    os << "0" << endl;
    
}
//----------------------------------------------------------------
void ofxDxfExport::writeHOF()
{
    os << "999" << endl;
    os << "DXF created with openFrameworks" << endl;
    os << "  0" << endl;
    os << "SECTION" << endl;
    os << "  2" << endl;
    os << "HEADER" << endl;
    os << "  9" << endl;
    os << "$ACADVER" << endl;
    os << "  1" << endl;
    os << "AC1014" << endl;
    os << "  9" << endl;
    os << "$HANDSEED" << endl;
    os << "  5" << endl;
    os << "FFFF" << endl;
    os << "  9" << endl;
    os << "$MEASUREMENT" << endl;
    os << " 70" << endl;
    os << "     1" << endl;
    os << "  0" << endl;
    os << "ENDSEC" << endl;
    os << "  0" << endl;
}
//----------------------------------------------------------------
void ofxDxfExport::writeTable()
{
    os << "SECTION" << endl;
    os << "  2" << endl;
    os << "TABLES" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "VPORT" << endl;
    os << "  5" << endl;
    os << "8" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "     4" << endl;
    os << "  0" << endl;
    os << "VPORT" << endl;
    os << "  5" << endl;
    os << "2E" << endl;
    os << "330" << endl;
    os << "8" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbViewportTableRecord" << endl;
    os << "  2" << endl;
    os << "*ACTIVE" << endl;
    os << " 70" << endl;
    os << "     0" << endl;
    os << " 10" << endl;
    os << "0.0" << endl;
    os << " 20" << endl;
    os << "0.0" << endl;
    os << " 11" << endl;
    os << "1.0" << endl;
    os << " 21" << endl;
    os << "1.0" << endl;
    os << " 12" << endl;
    os << "210.0" << endl;
    os << " 22" << endl;
    os << "148.5" << endl;
    os << " 13" << endl;
    os << "0.0" << endl;
    os << " 23" << endl;
    os << "0.0" << endl;
    os << " 14" << endl;
    os << "10.0" << endl;
    os << " 24" << endl;
    os << "10.0" << endl;
    os << " 15" << endl;
    os << "10.0" << endl;
    os << " 25" << endl;
    os << "10.0" << endl;
    os << " 16" << endl;
    os << "0.0" << endl;
    os << " 26" << endl;
    os << "0.0" << endl;
    os << " 36" << endl;
    os << "1.0" << endl;
    os << " 17" << endl;
    os << "0.0" << endl;
    os << " 27" << endl;
    os << "0.0" << endl;
    os << " 37" << endl;
    os << "0.0" << endl;
    os << " 40" << endl;
    os << "341.0" << endl;
    os << " 41" << endl;
    os << "1.24" << endl;
    os << " 42" << endl;
    os << "50.0" << endl;
    os << " 43" << endl;
    os << "0.0" << endl;
    os << " 44" << endl;
    os << "0.0" << endl;
    os << " 50" << endl;
    os << "0.0" << endl;
    os << " 51" << endl;
    os << "0.0" << endl;
    os << " 71" << endl;
    os << " 0" << endl;
    os << " 72" << endl;
    os << " 100" << endl;
    os << " 73" << endl;
    os << " 1" << endl;
    os << " 74" << endl;
    os << " 3" << endl;
    os << " 75" << endl;
    os << " 0" << endl;
    os << " 76" << endl;
    os << " 0 " << endl;
    os << " 77" << endl;
    os << " 0 " << endl;
    os << " 78" << endl;
    os << " 0 " << endl;
    os << " 0 " << endl;
    os << "ENDTAB" << endl;
    os << " 0 " << endl;
    os << "TABLE" << endl;
    os << " 2" << endl;
    os << "LTYPE" << endl;
    os << " 5" << endl;
    os << " 5" << endl;
    os << " 330" << endl;
    os << " 0" << endl;
    os << " 100" << endl;
    os << " AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << " 1" << endl;
    os << " 0" << endl;
    os << "LTYPE" << endl;
    os << " 5" << endl;
    os << "14" << endl;
    os << "330" << endl;
    os << "5" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbLinetypeTableRecord" << endl;
    os << " 2" << endl;
    os << "BYBLOCK" << endl;
    os << " 70" << endl;
    os << " 0" << endl;
    os << "  3" << endl;
    os << " 72" << endl;
    os << " 65" << endl;
    os << " 73" << endl;
    os << " 0" << endl;
    os << " 40" << endl;
    os << "0.0" << endl;
    os << "  0" << endl;
    os << "LTYPE" << endl;
    os << "  5" << endl;
    os << "15" << endl;
    os << "330" << endl;
    os << "5" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbLinetypeTableRecord" << endl;
    os << "  2" << endl;
    os << "BYLAYER" << endl;
    os << " 70" << endl;
    os << "     0" << endl;
    os << "  3" << endl;
    os << " 72" << endl;
    os << "    65" << endl;
    os << " 73" << endl;
    os << "     0" << endl;
    os << " 40" << endl;
    os << "0.0" << endl;
    os << "  0" << endl;
    os << "LTYPE" << endl;
    os << "  5" << endl;
    os << "16" << endl;
    os << "330" << endl;
    os << "5" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbLinetypeTableRecord" << endl;
    os << "  2" << endl;
    os << "CONTINUOUS" << endl;
    os << " 70" << endl;
    os << " 0" << endl;
    os << "  3" << endl;
    os << "Solid line" << endl;
    os << " 72" << endl;
    os << " 65" << endl;
    os << " 73" << endl;
    os << "     0" << endl;
    os << " 40" << endl;
    os << "0.0" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "LAYER" << endl;
    os << "  5" << endl;
    os << "2" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "1" << endl;
    os << "  0" << endl;
    os << "LAYER" << endl;
    os << "  5" << endl;
    os << "50" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbLayerTableRecord" << endl;
    os << "  2" << endl;
    os << "0" << endl;
    os << " 70" << endl;
    os << "0" << endl;
    os << "  6" << endl;
    os << "CONTINUOUS" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "STYLE" << endl;
    os << "  5" << endl;
    os << "3" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "     1" << endl;
    os << "  0" << endl;
    os << "STYLE" << endl;
    os << "  5" << endl;
    os << "11" << endl;
    os << "330" << endl;
    os << "3" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbTextStyleTableRecord" << endl;
    os << "  2" << endl;
    os << "STANDARD" << endl;
    os << " 70" << endl;
    os << " 0" << endl;
    os << " 40" << endl;
    os << "0.0" << endl;
    os << " 41" << endl;
    os << "1.0" << endl;
    os << " 50" << endl;
    os << "0.0" << endl;
    os << " 71" << endl;
    os << " 0" << endl;
    os << " 42" << endl;
    os << "2.5" << endl;
    os << "  3" << endl;
    os << "txt" << endl;
    os << "  4" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "VIEW" << endl;
    os << "  5" << endl;
    os << "6" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "     0" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "UCS" << endl;
    os << "  5" << endl;
    os << "7" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << " 0" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "APPID" << endl;
    os << "  5" << endl;
    os << "9" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "     2" << endl;
    os << "  0" << endl;
    os << "APPID" << endl;
    os << "  5" << endl;
    os << "12" << endl;
    os << "330" << endl;
    os << "9" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbRegAppTableRecord" << endl;
    os << "  2" << endl;
    os << "ACAD" << endl;
    os << " 70" << endl;
    os << "     0" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "DIMSTYLE" << endl;
    os << "  5" << endl;
    os << "A" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "     1" << endl;
    os << "  0" << endl;
    os << "DIMSTYLE" << endl;
    os << "105" << endl;
    os << "27" << endl;
    os << "330" << endl;
    os << "A" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbDimStyleTableRecord" << endl;
    os << "  2" << endl;
    os << "ISO-25" << endl;
    os << " 70" << endl;
    os << " 0" << endl;
    os << "  3" << endl;
    os << "  4" << endl;
    os << "  5" << endl;
    os << "  6" << endl;
    os << "  7" << endl;
    os << " 40" << endl;
    os << "1.0" << endl;
    os << " 41" << endl;
    os << "2.5" << endl;
    os << " 42" << endl;
    os << "0.625" << endl;
    os << " 43" << endl;
    os << "3.75" << endl;
    os << " 44" << endl;
    os << "1.25" << endl;
    os << " 45" << endl;
    os << "0.0" << endl;
    os << " 46" << endl;
    os << "0.0" << endl;
    os << " 47" << endl;
    os << "0.0" << endl;
    os << " 48" << endl;
    os << "0.0" << endl;
    os << "140" << endl;
    os << "2.5" << endl;
    os << "141" << endl;
    os << "2.5" << endl;
    os << "142" << endl;
    os << "0.0" << endl;
    os << "143" << endl;
    os << "0.03937007874016" << endl;
    os << "144" << endl;
    os << "1.0" << endl;
    os << "145" << endl;
    os << "0.0" << endl;
    os << "146" << endl;
    os << "1.0" << endl;
    os << "147" << endl;
    os << "0.625" << endl;
    os << " 71" << endl;
    os << "     0" << endl;
    os << " 72" << endl;
    os << "     0" << endl;
    os << " 73" << endl;
    os << "     0" << endl;
    os << " 74" << endl;
    os << "     0" << endl;
    os << " 75" << endl;
    os << "     0" << endl;
    os << " 76" << endl;
    os << "     0" << endl;
    os << " 77" << endl;
    os << "     1" << endl;
    os << " 78" << endl;
    os << "     8" << endl;
    os << "170" << endl;
    os << "     0" << endl;
    os << "171" << endl;
    os << "     3" << endl;
    os << "172" << endl;
    os << "     1" << endl;
    os << "173" << endl;
    os << "     0" << endl;
    os << "174" << endl;
    os << "     0" << endl;
    os << "175" << endl;
    os << "     0" << endl;
    os << "176" << endl;
    os << "     0" << endl;
    os << "177" << endl;
    os << "     0" << endl;
    os << "178" << endl;
    os << "     0" << endl;
    os << "270" << endl;
    os << "     2" << endl;
    os << "271" << endl;
    os << "     2" << endl;
    os << "272" << endl;
    os << "     2" << endl;
    os << "273" << endl;
    os << "     2" << endl;
    os << "274" << endl;
    os << "     3" << endl;
    os << "340" << endl;
    os << "11" << endl;
    os << "275" << endl;
    os << "     0" << endl;
    os << "280" << endl;
    os << "     0" << endl;
    os << "281" << endl;
    os << "     0" << endl;
    os << "282" << endl;
    os << "     0" << endl;
    os << "283" << endl;
    os << "     0" << endl;
    os << "284" << endl;
    os << "     8" << endl;
    os << "285" << endl;
    os << "     0" << endl;
    os << "286" << endl;
    os << "     0" << endl;
    os << "287" << endl;
    os << "     3" << endl;
    os << "288" << endl;
    os << "     0" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "TABLE" << endl;
    os << "  2" << endl;
    os << "BLOCK_RECORD" << endl;
    os << "  5" << endl;
    os << "1" << endl;
    os << "330" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTable" << endl;
    os << " 70" << endl;
    os << "     1" << endl;
    os << "  0" << endl;
    os << "BLOCK_RECORD" << endl;
    os << "  5" << endl;
    os << "1F" << endl;
    os << "330" << endl;
    os << "1" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbBlockTableRecord" << endl;
    os << "  2" << endl;
    os << "*MODEL_SPACE" << endl;
    os << "  0" << endl;
    os << "BLOCK_RECORD" << endl;
    os << "  5" << endl;
    os << "1B" << endl;
    os << "330" << endl;
    os << "1" << endl;
    os << "100" << endl;
    os << "AcDbSymbolTableRecord" << endl;
    os << "100" << endl;
    os << "AcDbBlockTableRecord" << endl;
    os << "  2" << endl;
    os << "*PAPER_SPACE" << endl;
    os << "  0" << endl;
    os << "ENDTAB" << endl;
    os << "  0" << endl;
    os << "ENDSEC" << endl;
    os << "  0" << endl;
}
//----------------------------------------------------------------
void ofxDxfExport::writeBlock()
{
    os << "SECTION" << endl;
    os << "  2" << endl;
    os << "BLOCKS" << endl;
    os << "  0" << endl;
    os << "BLOCK" << endl;
    os << "  5" << endl;
    os << "20" << endl;
    os << "330" << endl;
    os << "1F" << endl;
    os << "100" << endl;
    os << "AcDbEntity" << endl;
    os << "  8" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbBlockBegin" << endl;
    os << "  2" << endl;
    os << "*MODEL_SPACE" << endl;
    os << " 70" << endl;
    os << "     0" << endl;
    os << " 10" << endl;
    os << "0.0" << endl;
    os << " 20" << endl;
    os << "0.0" << endl;
    os << " 30" << endl;
    os << "0.0" << endl;
    os << "  3" << endl;
    os << "*MODEL_SPACE" << endl;
    os << "  1" << endl;
    os << "  0" << endl;
    os << "ENDBLK" << endl;
    os << "  5" << endl;
    os << "21" << endl;
    os << "330" << endl;
    os << "1F" << endl;
    os << "100" << endl;
    os << "AcDbEntity" << endl;
    os << "  8" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbBlockEnd" << endl;
    os << "  0" << endl;
    os << "BLOCK" << endl;
    os << "  5" << endl;
    os << "1C" << endl;
    os << "330" << endl;
    os << "1B" << endl;
    os << "100" << endl;
    os << "AcDbEntity" << endl;
    os << " 67" << endl;
    os << "     1" << endl;
    os << "  8" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbBlockBegin" << endl;
    os << "  2" << endl;
    os << "*PAPER_SPACE" << endl;
    os << "  1" << endl;
    os << "  0" << endl;
    os << "ENDBLK" << endl;
    os << "  5" << endl;
    os << "1D" << endl;
    os << "330" << endl;
    os << "1B" << endl;
    os << "100" << endl;
    os << "AcDbEntity" << endl;
    os << " 67" << endl;
    os << "     1" << endl;
    os << "  8" << endl;
    os << "0" << endl;
    os << "100" << endl;
    os << "AcDbBlockEnd" << endl;
    os << "  0" << endl;
    os << "ENDSEC" << endl;
    os << "  0" << endl;
}

//--------------------------------------------------------------
void ofxDxfExport::writeEOF()
{
    os << "EOF" << endl;
}
















