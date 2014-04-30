ofxDxfExport
============

A .dxf export addon for openFrameworks.

ofxDxfExport is an addon for openFrameworks (v0.8.0+) that allows users to export .dxf files inside their openFrameworks application. Provide a filename and a list of ofVec3f points to the ofxDxfExport object, the addon then pushes the data into the specified file. 

## Requirements
- openFrameworks v0.8.0+

## Getting Started

- After downloading ofxDxfExport, place it inside your openFrameworks addon folder.

- Create a new openFrameworks project

- Drag and drop the addon folder into the projects addon folder.

- In your testApp.h or ofApp.h file, link the addon's .h file, by adding  ```#include "ofxDxfExport.h"``` underneath ```#include "ofMain.h"```.

- Create a ofxDxfExport object in your testApp.h/ofApp.h file:
```ofxDxfExport dxfExport;``` (choose your own name)

- When you are ready to export the file simply call:
```dxfExport.writeFile("<YourFileName>,<YourListOfPoints");```

- The examples will provide clearer instructions

## Updates and Contributing

If you would like to contribute or redo the whole addon feel free to hack and mod the code as much as you want.
Also drop me a line and Let me know how you end up using the addon.

@david_haylock