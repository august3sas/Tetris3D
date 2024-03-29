#pragma once
#include<vector>
int blockVertexCount=180;
float blockVertices[] = {
	//wall faces - red (XY) z=0/1
0.125f,0.125f,0.0f,1,	0.875f,0.125f,0.0f,1,	0.875f,0.875f,0.0f,1,
0.125f,0.125f,0.0f,1,	0.125f,0.875f,0.0f,1,	0.875f,0.875f,0.0f,1,

0.125f,0.125f,1.0f,1,	0.875f,0.125f,1.0f,1, 	0.875f,0.875f,1.0f,1,
0.125f,0.125f,1.0f,1,	0.125f,0.875f,1.0f,1, 	0.875f,0.875f,1.0f,1,

//wall faces - red (XZ) y=0/1
0.125f,0.0f,0.125f,1,	0.875f,0.0f,0.125f,1, 	0.875f,0.0f,0.875f,1,
0.125f,0.0f,0.125f,1,	0.125f,0.0f,0.875f,1,	0.875f,0.0f,0.875f,1,

0.125f,1.0f,0.125f,1,	0.875f,1.0f,0.125f,1, 	0.875f,1.0f,0.875f,1,
0.125f,1.0f,0.125f,1,	0.125f,1.0f,0.875f,1,	0.875f,1.0f,0.875f,1,

//wall faces - red (YZ) x=0/1
0.0f,0.125f,0.125f,1,	0.0f,0.875f,0.125f,1,	0.0f,0.875f,0.875f,1,
0.0f,0.125f,0.125f,1,	0.0f,0.125f,0.875f,1, 	0.0f,0.875f,0.875f,1,

1.0f,0.125f,0.125f,1,	1.0f,0.875f,0.125f,1,	1.0f,0.875f,0.875f,1,
1.0f,0.125f,0.125f,1,	1.0f,0.125f,0.875f,1, 	1.0f,0.875f,0.875f,1,

//wall incissions - light gray z=0.125/0.875 (XY)
0.125f,0.0f,0.125f,1,	0.875f,0.0f,  0.125f,1, 	0.875f,0.125f,0.125f,1,
0.125f,0.0f,0.125f,1,	0.125f,0.125f,0.125f,1, 	0.875f,0.125f,0.125f,1,

0.0f,0.125f,0.125f,1,	0.125f,0.125f,0.125f,1,		0.125f,0.875f,0.125f,1,
0.0f,0.125f,0.125f,1,	0.0f  ,0.875f,0.125f,1,		0.125f,0.875f,0.125f,1,

0.125f,0.875f,0.125f,1,	0.875f,0.875f,0.125f,1, 	0.875f,1.0f  ,0.125f,1,
0.125f,0.875f,0.125f,1,	0.125f,1.0f  ,0.125f,1, 	0.875f,1.0f  ,0.125f,1,

0.875f,0.125f,0.125f,1,	1.0f  ,0.125f,0.125f,1,		1.0f  ,0.875f,0.125f,1,
0.875f,0.125f,0.125f,1,	0.875f,0.875f,0.125f,1,		1.0f  ,0.875f,0.125f,1,


0.125f,0.0f,0.875f,1,	0.875f,0.0f,  0.875f,1, 	0.875f,0.125f,0.875f,1,
0.125f,0.0f,0.875f,1,	0.125f,0.125f,0.875f,1,		0.875f,0.125f,0.875f,1,

0.0f,0.125f,0.875f,1,	0.125f,0.125f,0.875f,1,		0.125f,0.875f,0.875f,1,
0.0f,0.125f,0.875f,1,	0.0f  ,0.875f,0.875f,1,		0.125f,0.875f,0.875f,1,

0.125f,0.875f,0.875f,1,	0.875f,0.875f,0.875f,1, 	0.875f,1.0f  ,0.875f,1,
0.125f,0.875f,0.875f,1,	0.125f,1.0f  ,0.875f,1, 	0.875f,1.0f  ,0.875f,1,

0.875f,0.125f,0.875f,1,	1.0f  ,0.125f,0.875f,1,		1.0f  ,0.875f,0.875f,1,
0.875f,0.125f,0.875f,1,	0.875f,0.875f,0.875f,1,		1.0f  ,0.875f,0.875f,1,


//wall incissions - gray y=0.125/0.875 (XZ)
0.125f,0.125f,0.0f,1,		0.875f,0.125f,0.0f,1,   	0.875f,0.125f,0.125f,1,
0.125f,0.125f,0.0f,1,		0.125f,0.125f,0.125f,1, 	0.875f,0.125f,0.125f,1,

0.0f,0.125f,0.125f,1,		0.125f,0.125f,0.125f,1,		0.125f,0.125f,0.875f,1,
0.0f,0.125f,0.125f,1,		0.0f  ,0.125f,0.875f,1,		0.125f,0.125f,0.875f,1,

0.125f,0.125f,0.875f,1,		0.875f,0.125f,0.875f,1, 	0.875f,0.125f,1.0f  ,1,
0.125f,0.125f,0.875f,1,		0.125f,0.125f,1.0f  ,1,		0.875f,0.125f,1.0f  ,1,

0.875f,0.125f,0.125f,1,		1.0f  ,0.125f,0.125f,1,		1.0f  ,0.125f,0.875f,1,
0.875f,0.125f,0.125f,1,		0.875f,0.125f,0.875f,1,		1.0f  ,0.125f,0.875f,1,


0.125f,0.875f,0.0f,1,		0.875f,0.875f,0.0f,1,   	0.875f,0.875f,0.125f,1,
0.125f,0.875f,0.0f,1,		0.125f,0.875f,0.125f,1, 	0.875f,0.875f,0.125f,1,

0.0f,0.875f,0.125f,1,		0.125f,0.875f,0.125f,1,		0.125f,0.875f,0.875f,1,
0.0f,0.875f,0.125f,1,		0.0f  ,0.875f,0.875f,1,		0.125f,0.875f,0.875f,1,

0.125f,0.875f,0.875f,1,		0.875f,0.875f,0.875f,1,		0.875f,0.875f,1.0f  ,1,
0.125f,0.875f,0.875f,1,		0.125f,0.875f,1.0f  ,1,		0.875f,0.875f,1.0f  ,1,

0.875f,0.875f,0.125f,1,		1.0f  ,0.875f,0.125f,1,		1.0f  ,0.875f,0.875f,1,
0.875f,0.875f,0.125f,1,		0.875f,0.875f,0.875f,1,		1.0f  ,0.875f,0.875f,1,

//wall incissions - white x=0.125/0.875 (YZ)
0.125f,0.125f,0.0f,1,		0.125f,0.875f,0.0f,1,  		0.125f,0.875f,0.125f,1,
0.125f,0.125f,0.0f,1,		0.125f,0.125f,0.125f,1, 	0.125f,0.875f,0.125f,1,

0.125f,0.0f,0.125f,1,		0.125f,0.125f,0.125f,1,		0.125f,0.125f,0.875f,1,
0.125f,0.0f,0.125f,1,		0.125f,0.0f  ,0.875f,1,		0.125f,0.125f,0.875f,1,

0.125f,0.125f,0.875f,1,		0.125f,0.875f,0.875f,1, 	0.125f,0.875f,1.0f  ,1,
0.125f,0.125f,0.875f,1,		0.125f,0.125f,1.0f  ,1, 	0.125f,0.875f,1.0f  ,1,

0.125f,0.875f,0.125f,1,		0.125f,1.0f  ,0.125f,1,		0.125f,1.0f  ,0.875f,1,
0.125f,0.875f,0.125f,1,		0.125f,0.875f,0.875f,1,		0.125f,1.0f  ,0.875f,1,


0.875f,0.125f,0.0f,1,		0.875f,0.875f,0.0f,1,  		0.875f,0.875f,0.125f,1,
0.875f,0.125f,0.0f,1,		0.875f,0.125f,0.125f,1, 	0.875f,0.875f,0.125f,1,

0.875f,0.0f,0.125f,1,		0.875f,0.125f,0.125f,1,		0.875f,0.125f,0.875f,1,
0.875f,0.0f,0.125f,1,		0.875f,0.0f  ,0.875f,1,		0.875f,0.125f,0.875f,1,

0.875f,0.125f,0.875f,1,		0.875f,0.875f,0.875f,1, 	0.875f,0.875f,1.0f  ,1,
0.875f,0.125f,0.875f,1,		0.875f,0.125f,1.0f  ,1, 	0.875f,0.875f,1.0f  ,1,

0.875f,0.875f,0.125f,1,		0.875f,1.0f  ,0.125f,1,		0.875f,1.0f  ,0.875f,1,
0.875f,0.875f,0.125f,1,		0.875f,0.875f,0.875f,1,		0.875f,1.0f  ,0.875f,1
};
float blockColors[] = {
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,
	1,0,0,1,	1,0,0,1,	1,0,0,1,

	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,
	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,	0.25f,0.25f,0.0f,1,

	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,
	0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,		0.0f,0.75f,0.75f,1,

	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1,
	0,1,0,1,	0,1,0,1,	0,1,0,1
};
float blockVerticesNormals[] = {
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,

0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f,1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,

-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
//end of red faces

0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,
0.0f, 0.0f, -1.0f, 0.0f,

0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
//XZ
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,
0.0f, -1.0f, 0.0f, 0.0f,

0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,


-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,
-1.0f, 0.0f, 0.0f, 0.0f,

1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f, 0.0f


};
float blockTexCoords[] = {
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	/*
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f,1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f,1.0f, 0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f, 0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	0.0, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0, 0.0f,
	1.0f, 1.0f,
	*/
};

