ofxDxfExport
============

A .dxf export addon for openFrameworks.

ofxDxfExport is an addon for openFrameworks (v0.8.0+) that allows users to export .dxf files inside their openFrameworks application. Provide a filename and a list of ofVec3f points to the ofxDxfExport object, the addon then pushes the data into the specified file. 

If you would like to contribute or redo the whole addon feel free to hack and mod the code as much as you want.
Also drop me a line and Let me know how you end up using the addon.

@david_haylock

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
 
	<code>	 
		dxfExport.writeFile("YourFileName");
		dxfExport.addPoints("YourPoints",true);
		dxfExport.endFile();
	</code>

- The examples will provide clearer instructions.

## Updates

- You are now able to export more than one set of points.
- Simply call:
	
	<code>
		dxfExport.addPoints("YourPoints1",false);
		dxfExport.addPoints("YourPoints2",true);
	</code>
	
- The bool value tells the addon to close the Entities section.

- Examples 2 now exports two sets of points.

## To Do

- Time Permitting I will hack around the viewport and scaling of the points.