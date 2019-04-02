#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,5,0,0,0,1,0,0,0,
30,0,2,0,0,0,2,0,0,0,95,0,0,0,92,0,
2,0,0,0,3,0,0,0,92,0,0,0,8,0,0,0,
0,0,1,0,0,0,0,0,0,0,246,0,2,0,0,0,
1,0,0,0,79,0,0,1,50,0,2,0,0,0,61,0,
0,0,6,0,0,2,238,0,0,0,0,0,1,0,0,0,
0,0,0,3,212,0,0,0,0,0,1,0,0,0,0,0,
0,4,12,0,0,0,0,0,1,0,0,0,0,0,0,4,
252,0,0,0,0,0,1,0,0,0,0,0,0,6,128,0,
0,0,0,0,1,0,0,0,0,0,0,8,36,0,0,0,
0,0,1,0,0,0,0,0,0,3,28,0,0,0,0,0,
1,0,0,0,0,0,0,11,156,0,0,0,0,0,1,0,
0,0,0,0,0,8,104,0,0,0,0,0,1,0,0,0,
0,0,0,7,84,0,0,0,0,0,1,0,0,0,0,0,
0,3,164,0,0,0,0,0,1,0,0,0,0,0,0,3,
232,0,0,0,0,0,1,0,0,0,0,0,0,11,188,0,
0,0,0,0,1,0,0,0,0,0,0,6,244,0,0,0,
0,0,1,0,0,0,0,0,0,9,92,0,2,0,0,0,
5,0,0,0,74,0,0,7,208,0,0,0,0,0,1,0,
0,0,0,0,0,5,244,0,0,0,0,0,1,0,0,0,
0,0,0,8,186,0,0,0,0,0,1,0,0,0,0,0,
0,3,84,0,0,0,0,0,1,0,0,0,0,0,0,5,
96,0,0,0,0,0,1,0,0,0,0,0,0,5,48,0,
0,0,0,0,1,0,0,0,0,0,0,6,92,0,0,0,
0,0,1,0,0,0,0,0,0,4,42,0,0,0,0,0,
1,0,0,0,0,0,0,5,194,0,0,0,0,0,1,0,
0,0,0,0,0,4,224,0,0,0,0,0,1,0,0,0,
0,0,0,8,218,0,0,0,0,0,1,0,0,0,0,0,
0,3,62,0,0,0,0,0,1,0,0,0,0,0,0,5,
22,0,0,0,0,0,1,0,0,0,0,0,0,0,40,0,
0,0,0,0,1,0,0,0,0,0,0,3,190,0,0,0,
0,0,1,0,0,0,0,0,0,9,16,0,0,0,0,0,
1,0,0,0,0,0,0,8,14,0,0,0,0,0,1,0,
0,0,0,0,0,8,246,0,0,0,0,0,1,0,0,0,
0,0,0,9,72,0,0,0,0,0,1,0,0,0,0,0,
0,6,18,0,0,0,0,0,1,0,0,0,0,0,0,10,
48,0,2,0,0,0,7,0,0,0,67,0,0,7,48,0,
0,0,0,0,1,0,0,0,0,0,0,10,22,0,0,0,
0,0,1,0,0,0,0,0,0,11,96,0,0,0,0,0,
1,0,0,0,0,0,0,5,216,0,0,0,0,0,1,0,
0,0,0,0,0,5,132,0,0,0,0,0,1,0,0,0,
0,0,0,7,182,0,0,0,0,0,1,0,0,0,0,0,
0,7,238,0,0,0,0,0,1,0,0,0,0,0,0,7,
156,0,0,0,0,0,1,0,0,0,0,0,0,3,126,0,
0,0,0,0,1,0,0,0,0,0,0,0,64,0,0,0,
0,0,1,0,0,0,0,0,0,4,156,0,0,0,0,0,
1,0,0,0,0,0,0,7,24,0,0,0,0,0,1,0,
0,0,0,0,0,4,128,0,0,0,0,0,1,0,0,0,
0,0,0,4,188,0,0,0,0,0,1,0,0,0,0,0,
0,5,158,0,0,0,0,0,1,0,0,0,0,0,0,6,
206,0,0,0,0,0,1,0,0,0,0,0,0,7,120,0,
0,0,0,0,1,0,0,0,0,0,0,11,118,0,0,0,
0,0,1,0,0,0,0,0,0,11,50,0,0,0,0,0,
1,0,0,0,0,0,0,6,44,0,0,0,0,0,1,0,
0,0,0,0,0,8,70,0,0,0,0,0,1,0,0,0,
0,0,0,8,154,0,0,0,0,0,1,0,0,0,0,0,
0,9,50,0,0,0,0,0,1,0,0,0,0,0,0,4,
74,0,0,0,0,0,1,0,0,0,0,0,0,6,176,0,
0,0,0,0,1,0,0,0,0,0,0,10,248,0,0,0,
0,0,1,0,0,0,0,0,0,10,142,0,0,0,0,0,
1,0,0,0,0,0,0,10,174,0,0,0,0,0,1,0,
0,0,0,0,0,11,22,0,0,0,0,0,1,0,0,0,
0,0,0,10,214,0,0,0,0,0,1,0,0,0,0,0,
0,10,72,0,0,0,0,0,1,0,0,0,0,0,0,10,
110,0,0,0,0,0,1,0,0,0,0,0,0,9,110,0,
0,0,0,0,1,0,0,0,0,0,0,9,254,0,0,0,
0,0,1,0,0,0,0,0,0,9,220,0,0,0,0,0,
1,0,0,0,0,0,0,9,180,0,0,0,0,0,1,0,
0,0,0,0,0,9,146,0,0,0,0,0,1,0,0,0,
0,0,0,1,10,0,2,0,0,0,1,0,0,0,80,0,
0,1,32,0,2,0,0,0,1,0,0,0,81,0,0,1,
50,0,2,0,0,0,10,0,0,0,82,0,0,1,72,0,
0,0,0,0,1,0,0,0,0,0,0,2,160,0,0,0,
0,0,1,0,0,0,0,0,0,2,120,0,0,0,0,0,
1,0,0,0,0,0,0,1,212,0,0,0,0,0,1,0,
0,0,0,0,0,2,196,0,0,0,0,0,1,0,0,0,
0,0,0,2,74,0,0,0,0,0,1,0,0,0,0,0,
0,1,168,0,0,0,0,0,1,0,0,0,0,0,0,1,
248,0,0,0,0,0,1,0,0,0,0,0,0,1,110,0,
0,0,0,0,1,0,0,0,0,0,0,2,38,0,0,0,
0,0,1,0,0,0,0,0,0,0,204,0,0,0,0,0,
1,0,0,0,0,0,0,0,154,0,0,0,0,0,1,0,
0,0,0,0,0,0,104,0,0,0,0,0,1,0,0,0,
0,0,0,0,40,0,0,0,0,0,1,0,0,0,0,0,
0,0,64,0,0,0,0,0,1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,8,8,1,90,92,0,109,0,
97,0,105,0,110,0,46,0,113,0,109,0,108,0,2,0,
0,5,153,0,85,0,73,0,9,8,191,244,220,0,76,0,
97,0,98,0,101,0,108,0,46,0,113,0,109,0,108,0,
11,11,181,156,92,0,84,0,111,0,111,0,108,0,116,0,
105,0,112,0,46,0,113,0,109,0,108,0,3,0,0,120,
60,0,113,0,109,0,108,0,22,11,59,156,28,0,83,0,
101,0,116,0,116,0,105,0,110,0,103,0,115,0,68,0,
105,0,97,0,108,0,111,0,103,0,68,0,101,0,109,0,
111,0,46,0,113,0,109,0,108,0,22,5,67,196,252,0,
68,0,97,0,116,0,97,0,66,0,97,0,115,0,101,0,
68,0,105,0,97,0,108,0,111,0,103,0,68,0,101,0,
109,0,111,0,46,0,113,0,109,0,108,0,18,2,104,237,
252,0,77,0,97,0,105,0,110,0,68,0,105,0,97,0,
108,0,111,0,103,0,68,0,101,0,109,0,111,0,46,0,
113,0,109,0,108,0,7,8,152,191,59,0,81,0,116,0,
81,0,117,0,105,0,99,0,107,0,8,6,91,159,115,0,
67,0,111,0,110,0,116,0,114,0,111,0,108,0,115,0,
6,5,172,2,195,0,83,0,116,0,121,0,108,0,101,0,
115,0,8,8,172,133,28,0,77,0,97,0,116,0,101,0,
114,0,105,0,97,0,108,0,16,1,34,125,60,0,84,0,
111,0,111,0,108,0,66,0,97,0,114,0,83,0,116,0,
121,0,108,0,101,0,46,0,113,0,109,0,108,0,26,9,
198,185,124,0,65,0,112,0,112,0,108,0,105,0,99,0,
97,0,116,0,105,0,111,0,110,0,87,0,105,0,110,0,
100,0,111,0,119,0,83,0,116,0,121,0,108,0,101,0,
46,0,113,0,109,0,108,0,19,6,212,8,188,0,84,0,
111,0,111,0,108,0,66,0,117,0,116,0,116,0,111,0,
110,0,83,0,116,0,121,0,108,0,101,0,46,0,113,0,
109,0,108,0,15,3,129,205,252,0,83,0,108,0,105,0,
100,0,101,0,114,0,83,0,116,0,121,0,108,0,101,0,
46,0,113,0,109,0,108,0,20,9,140,234,92,0,82,0,
97,0,100,0,105,0,111,0,66,0,117,0,116,0,116,0,
111,0,110,0,83,0,116,0,121,0,108,0,101,0,46,0,
113,0,109,0,108,0,15,11,77,6,124,0,66,0,117,0,
116,0,116,0,111,0,110,0,83,0,116,0,121,0,108,0,
101,0,46,0,113,0,109,0,108,0,20,6,78,188,28,0,
80,0,114,0,111,0,103,0,114,0,101,0,115,0,115,0,
66,0,97,0,114,0,83,0,116,0,121,0,108,0,101,0,
46,0,113,0,109,0,108,0,17,2,46,79,60,0,67,0,
104,0,101,0,99,0,107,0,66,0,111,0,120,0,83,0,
116,0,121,0,108,0,101,0,46,0,113,0,109,0,108,0,
15,1,118,139,60,0,83,0,119,0,105,0,116,0,99,0,
104,0,83,0,116,0,121,0,108,0,101,0,46,0,113,0,
109,0,108,0,18,6,18,130,92,0,84,0,101,0,120,0,
116,0,70,0,105,0,101,0,108,0,100,0,83,0,116,0,
121,0,108,0,101,0,46,0,113,0,109,0,108,0,20,0,
62,159,60,0,84,0,105,0,109,0,101,0,80,0,105,0,
99,0,107,0,101,0,114,0,68,0,105,0,97,0,108,0,
111,0,103,0,46,0,113,0,109,0,108,0,14,1,177,158,
60,0,84,0,105,0,109,0,101,0,80,0,105,0,99,0,
107,0,101,0,114,0,46,0,113,0,109,0,108,0,8,8,
135,97,28,0,67,0,97,0,114,0,100,0,46,0,113,0,
109,0,108,0,18,6,142,239,60,0,80,0,114,0,111,0,
103,0,114,0,101,0,115,0,115,0,67,0,105,0,114,0,
99,0,108,0,101,0,46,0,113,0,109,0,108,0,16,11,
181,135,156,0,65,0,99,0,116,0,105,0,111,0,110,0,
66,0,117,0,116,0,116,0,111,0,110,0,46,0,113,0,
109,0,108,0,10,3,83,11,60,0,68,0,105,0,97,0,
108,0,111,0,103,0,46,0,113,0,109,0,108,0,8,8,
200,95,156,0,87,0,97,0,118,0,101,0,46,0,113,0,
109,0,108,0,7,0,78,88,156,0,73,0,110,0,107,0,
46,0,113,0,109,0,108,0,15,3,85,158,156,0,80,0,
114,0,111,0,103,0,114,0,101,0,115,0,115,0,66,0,
97,0,114,0,46,0,113,0,109,0,108,0,12,0,86,39,
220,0,67,0,104,0,101,0,99,0,107,0,66,0,111,0,
120,0,46,0,113,0,109,0,108,0,13,7,211,93,124,0,
65,0,99,0,116,0,105,0,111,0,110,0,66,0,97,0,
114,0,46,0,113,0,109,0,108,0,24,15,204,46,156,0,
78,0,97,0,118,0,105,0,103,0,97,0,116,0,105,0,
111,0,110,0,68,0,114,0,97,0,119,0,101,0,114,0,
80,0,97,0,103,0,101,0,46,0,113,0,109,0,108,0,
11,12,107,154,252,0,80,0,111,0,112,0,111,0,118,0,
101,0,114,0,46,0,113,0,109,0,108,0,13,11,215,147,
28,0,83,0,99,0,114,0,111,0,108,0,108,0,98,0,
97,0,114,0,46,0,113,0,109,0,108,0,15,12,170,34,
92,0,66,0,111,0,116,0,116,0,111,0,109,0,83,0,
104,0,101,0,101,0,116,0,46,0,113,0,109,0,108,0,
11,8,51,156,124,0,84,0,111,0,111,0,108,0,98,0,
97,0,114,0,46,0,113,0,109,0,108,0,10,0,105,165,
92,0,65,0,99,0,116,0,105,0,111,0,110,0,46,0,
113,0,109,0,108,0,10,8,142,26,252,0,84,0,97,0,
98,0,66,0,97,0,114,0,46,0,113,0,109,0,108,0,
21,7,160,109,60,0,77,0,97,0,116,0,101,0,114,0,
105,0,97,0,108,0,65,0,110,0,105,0,109,0,97,0,
116,0,105,0,111,0,110,0,46,0,113,0,109,0,108,0,
15,6,238,18,156,0,79,0,118,0,101,0,114,0,108,0,
97,0,121,0,86,0,105,0,101,0,119,0,46,0,113,0,
109,0,108,0,10,11,101,152,188,0,87,0,105,0,110,0,
100,0,111,0,119,0,46,0,113,0,109,0,108,0,15,12,
202,75,252,0,73,0,110,0,112,0,117,0,116,0,68,0,
105,0,97,0,108,0,111,0,103,0,46,0,113,0,109,0,
108,0,8,7,216,94,252,0,80,0,97,0,103,0,101,0,
46,0,113,0,109,0,108,0,11,11,13,85,188,0,80,0,
97,0,108,0,101,0,116,0,116,0,101,0,46,0,113,0,
109,0,108,0,12,5,186,83,188,0,77,0,97,0,105,0,
110,0,86,0,105,0,101,0,119,0,46,0,113,0,109,0,
108,0,10,10,144,12,60,0,83,0,119,0,105,0,116,0,
99,0,104,0,46,0,113,0,109,0,108,0,21,15,21,249,
188,0,65,0,112,0,112,0,108,0,105,0,99,0,97,0,
116,0,105,0,111,0,110,0,87,0,105,0,110,0,100,0,
111,0,119,0,46,0,113,0,109,0,108,0,15,7,172,1,
28,0,85,0,110,0,105,0,116,0,115,0,72,0,101,0,
108,0,112,0,101,0,114,0,46,0,113,0,109,0,108,0,
21,0,145,50,28,0,66,0,111,0,116,0,116,0,111,0,
109,0,65,0,99,0,116,0,105,0,111,0,110,0,83,0,
104,0,101,0,101,0,116,0,46,0,113,0,109,0,108,0,
12,15,211,157,92,0,68,0,114,0,111,0,112,0,100,0,
111,0,119,0,110,0,46,0,113,0,109,0,108,0,16,12,
254,234,188,0,84,0,104,0,101,0,109,0,101,0,80,0,
97,0,108,0,101,0,116,0,116,0,101,0,46,0,113,0,
109,0,108,0,15,3,215,252,188,0,80,0,97,0,103,0,
101,0,83,0,105,0,100,0,101,0,98,0,97,0,114,0,
46,0,113,0,109,0,108,0,9,12,56,229,252,0,84,0,
104,0,101,0,109,0,101,0,46,0,113,0,109,0,108,0,
15,10,146,38,28,0,84,0,104,0,105,0,110,0,68,0,
105,0,118,0,105,0,100,0,101,0,114,0,46,0,113,0,
109,0,108,0,15,3,44,8,188,0,65,0,119,0,101,0,
115,0,111,0,109,0,101,0,73,0,99,0,111,0,110,0,
46,0,113,0,109,0,108,0,15,13,103,16,188,0,82,0,
97,0,100,0,105,0,111,0,66,0,117,0,116,0,116,0,
111,0,110,0,46,0,113,0,109,0,108,0,10,11,173,230,
60,0,79,0,98,0,106,0,101,0,99,0,116,0,46,0,
113,0,109,0,108,0,10,11,104,113,92,0,66,0,117,0,
116,0,116,0,111,0,110,0,46,0,113,0,109,0,108,0,
12,5,58,229,252,0,65,0,112,0,112,0,84,0,104,0,
101,0,109,0,101,0,46,0,113,0,109,0,108,0,13,11,
105,4,60,0,80,0,97,0,103,0,101,0,83,0,116,0,
97,0,99,0,107,0,46,0,113,0,109,0,108,0,8,10,
97,97,220,0,73,0,99,0,111,0,110,0,46,0,113,0,
109,0,108,0,14,0,145,157,220,0,68,0,97,0,116,0,
101,0,80,0,105,0,99,0,107,0,101,0,114,0,46,0,
113,0,109,0,108,0,14,15,164,126,188,0,73,0,99,0,
111,0,110,0,66,0,117,0,116,0,116,0,111,0,110,0,
46,0,113,0,109,0,108,0,22,2,127,56,220,0,80,0,
108,0,97,0,116,0,102,0,111,0,114,0,109,0,69,0,
120,0,116,0,101,0,110,0,115,0,105,0,111,0,110,0,
115,0,46,0,113,0,109,0,108,0,13,15,172,112,156,0,
77,0,101,0,110,0,117,0,70,0,105,0,101,0,108,0,
100,0,46,0,113,0,109,0,108,0,13,6,91,224,124,0,
80,0,111,0,112,0,117,0,112,0,66,0,97,0,115,0,
101,0,46,0,113,0,109,0,108,0,11,8,54,165,92,0,
83,0,105,0,100,0,101,0,98,0,97,0,114,0,46,0,
113,0,109,0,108,0,10,10,110,158,147,0,97,0,119,0,
101,0,115,0,111,0,109,0,101,0,46,0,106,0,115,0,
14,8,201,52,124,0,84,0,97,0,98,0,98,0,101,0,
100,0,80,0,97,0,103,0,101,0,46,0,113,0,109,0,
108,0,8,15,202,95,188,0,86,0,105,0,101,0,119,0,
46,0,113,0,109,0,108,0,7,10,117,88,156,0,84,0,
97,0,98,0,46,0,113,0,109,0,108,0,6,4,207,184,
131,0,69,0,120,0,116,0,114,0,97,0,115,0,15,6,
148,80,124,0,67,0,105,0,114,0,99,0,108,0,101,0,
73,0,109,0,97,0,103,0,101,0,46,0,113,0,109,0,
108,0,14,15,18,195,28,0,67,0,111,0,108,0,117,0,
109,0,110,0,70,0,108,0,111,0,119,0,46,0,113,0,
109,0,108,0,17,14,193,150,124,0,65,0,117,0,116,0,
111,0,109,0,97,0,116,0,105,0,99,0,71,0,114,0,
105,0,100,0,46,0,113,0,109,0,108,0,14,9,138,18,
220,0,67,0,105,0,114,0,99,0,108,0,101,0,77,0,
97,0,115,0,107,0,46,0,113,0,109,0,108,0,9,7,
216,248,92,0,73,0,109,0,97,0,103,0,101,0,46,0,
113,0,109,0,108,0,10,10,206,21,220,0,83,0,108,0,
105,0,100,0,101,0,114,0,46,0,113,0,109,0,108,0,
9,10,144,14,67,0,76,0,105,0,115,0,116,0,73,0,
116,0,101,0,109,0,115,0,16,14,207,40,92,0,66,0,
97,0,115,0,101,0,76,0,105,0,115,0,116,0,73,0,
116,0,101,0,109,0,46,0,113,0,109,0,108,0,13,15,
180,131,188,0,83,0,117,0,98,0,104,0,101,0,97,0,
100,0,101,0,114,0,46,0,113,0,109,0,108,0,13,7,
196,56,60,0,83,0,117,0,98,0,116,0,105,0,116,0,
108,0,101,0,100,0,46,0,113,0,109,0,108,0,17,8,
230,108,28,0,83,0,101,0,99,0,116,0,105,0,111,0,
110,0,72,0,101,0,97,0,100,0,101,0,114,0,46,0,
113,0,109,0,108,0,14,12,218,30,220,0,83,0,105,0,
109,0,112,0,108,0,101,0,77,0,101,0,110,0,117,0,
46,0,113,0,109,0,108,0,12,3,210,97,124,0,83,0,
116,0,97,0,110,0,100,0,97,0,114,0,100,0,46,0,
113,0,109,0,108,0,11,10,83,81,220,0,68,0,105,0,
118,0,105,0,100,0,101,0,114,0,46,0,113,0,109,0,
108,0,20,14,63,112,60,0,78,0,97,0,118,0,105,0,
103,0,97,0,116,0,105,0,111,0,110,0,68,0,114,0,
97,0,119,0,101,0,114,0,46,0,113,0,109,0,108,0,
8,11,3,106,147,0,117,0,116,0,105,0,108,0,115,0,
46,0,106,0,115,0,16,13,129,34,28,0,79,0,118,0,
101,0,114,0,108,0,97,0,121,0,76,0,97,0,121,0,
101,0,114,0,46,0,113,0,109,0,108,0,13,1,184,80,
156,0,84,0,101,0,120,0,116,0,70,0,105,0,101,0,
108,0,100,0,46,0,113,0,109,0,108,0,12,3,205,164,
28,0,83,0,110,0,97,0,99,0,107,0,98,0,97,0,
114,0,46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f_Material_Snackbar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_TextFieldStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_TextField_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_OverlayLayer_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_utils_js { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_SwitchStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_NavigationDrawer_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_Divider_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Slider_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Extras_Image_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_MainDialogDemo_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Tab_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_View_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_TabbedPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_awesome_js { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_CheckBoxStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Sidebar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_PopupBase_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_ProgressBarStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_MenuField_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_PlatformExtensions_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_IconButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_DatePicker_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_ButtonStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Icon_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_PageStack_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_AppTheme_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Extras_CircleMask_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Button_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Object_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Extras_AutomaticGrid_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_RadioButtonStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Tooltip_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_RadioButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_Standard_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_AwesomeIcon_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ThinDivider_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_DataBaseDialogDemo_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Theme_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_PageSidebar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_SimpleMenu_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_SectionHeader_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ThemePalette_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Dropdown_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_BottomActionSheet_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_UnitsHelper_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_Subtitled_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_SliderStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_UI_Tooltip_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ApplicationWindow_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Switch_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_MainView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Palette_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Extras_ColumnFlow_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Page_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_InputDialog_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Window_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_OverlayView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_ToolButtonStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Label_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Extras_CircleImage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_MaterialAnimation_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_TabBar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Action_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Toolbar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_BottomSheet_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Scrollbar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Popover_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_UI_Label_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_NavigationDrawerPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ActionBar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_CheckBox_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_SettingsDialogDemo_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ProgressBar_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Ink_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Wave_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Dialog_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_ApplicationWindowStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_QtQuick_Controls_Styles_Material_ToolBarStyle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ActionButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_Subheader_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ProgressCircle_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_Card_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_ListItems_BaseListItem_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_TimePicker_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Material_TimePickerDialog_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Snackbar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Snackbar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/TextFieldStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_TextFieldStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/TextField.qml"), &QmlCacheGeneratedCode::_0x5f_Material_TextField_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/OverlayLayer.qml"), &QmlCacheGeneratedCode::_0x5f_Material_OverlayLayer_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/utils.js"), &QmlCacheGeneratedCode::_0x5f_Material_utils_js::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/SwitchStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_SwitchStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/NavigationDrawer.qml"), &QmlCacheGeneratedCode::_0x5f_Material_NavigationDrawer_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/Divider.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_Divider_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Slider.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Slider_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Extras/Image.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Extras_Image_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/MainDialogDemo.qml"), &QmlCacheGeneratedCode::_qml_MainDialogDemo_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Tab.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Tab_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/View.qml"), &QmlCacheGeneratedCode::_0x5f_Material_View_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/TabbedPage.qml"), &QmlCacheGeneratedCode::_0x5f_Material_TabbedPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/awesome.js"), &QmlCacheGeneratedCode::_0x5f_Material_awesome_js::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/CheckBoxStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_CheckBoxStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Sidebar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Sidebar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/PopupBase.qml"), &QmlCacheGeneratedCode::_0x5f_Material_PopupBase_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/ProgressBarStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_ProgressBarStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/MenuField.qml"), &QmlCacheGeneratedCode::_0x5f_Material_MenuField_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/PlatformExtensions.qml"), &QmlCacheGeneratedCode::_0x5f_Material_PlatformExtensions_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/IconButton.qml"), &QmlCacheGeneratedCode::_0x5f_Material_IconButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/DatePicker.qml"), &QmlCacheGeneratedCode::_0x5f_Material_DatePicker_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/ButtonStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_ButtonStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Icon.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Icon_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/PageStack.qml"), &QmlCacheGeneratedCode::_0x5f_Material_PageStack_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/AppTheme.qml"), &QmlCacheGeneratedCode::_0x5f_Material_AppTheme_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Extras/CircleMask.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Extras_CircleMask_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Button.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Button_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Object.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Object_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Extras/AutomaticGrid.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Extras_AutomaticGrid_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/RadioButtonStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_RadioButtonStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Tooltip.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Tooltip_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/RadioButton.qml"), &QmlCacheGeneratedCode::_0x5f_Material_RadioButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/Standard.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_Standard_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/AwesomeIcon.qml"), &QmlCacheGeneratedCode::_0x5f_Material_AwesomeIcon_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ThinDivider.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ThinDivider_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/DataBaseDialogDemo.qml"), &QmlCacheGeneratedCode::_qml_DataBaseDialogDemo_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Theme.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Theme_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/PageSidebar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_PageSidebar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/SimpleMenu.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_SimpleMenu_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/SectionHeader.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_SectionHeader_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ThemePalette.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ThemePalette_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Dropdown.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Dropdown_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/BottomActionSheet.qml"), &QmlCacheGeneratedCode::_0x5f_Material_BottomActionSheet_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/UnitsHelper.qml"), &QmlCacheGeneratedCode::_0x5f_Material_UnitsHelper_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/Subtitled.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_Subtitled_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/SliderStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_SliderStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/UI/Tooltip.qml"), &QmlCacheGeneratedCode::_0x5f_UI_Tooltip_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ApplicationWindow.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ApplicationWindow_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Switch.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Switch_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/MainView.qml"), &QmlCacheGeneratedCode::_0x5f_Material_MainView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Palette.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Palette_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Extras/ColumnFlow.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Extras_ColumnFlow_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Page.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Page_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/InputDialog.qml"), &QmlCacheGeneratedCode::_0x5f_Material_InputDialog_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Window.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Window_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/OverlayView.qml"), &QmlCacheGeneratedCode::_0x5f_Material_OverlayView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/ToolButtonStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_ToolButtonStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Label.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Label_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Extras/CircleImage.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Extras_CircleImage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/MaterialAnimation.qml"), &QmlCacheGeneratedCode::_0x5f_Material_MaterialAnimation_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/TabBar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_TabBar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Action.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Action_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Toolbar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Toolbar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/BottomSheet.qml"), &QmlCacheGeneratedCode::_0x5f_Material_BottomSheet_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Scrollbar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Scrollbar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Popover.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Popover_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/UI/Label.qml"), &QmlCacheGeneratedCode::_0x5f_UI_Label_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/main.qml"), &QmlCacheGeneratedCode::_0x5f__main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/NavigationDrawerPage.qml"), &QmlCacheGeneratedCode::_0x5f_Material_NavigationDrawerPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ActionBar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ActionBar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/CheckBox.qml"), &QmlCacheGeneratedCode::_0x5f_Material_CheckBox_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/SettingsDialogDemo.qml"), &QmlCacheGeneratedCode::_qml_SettingsDialogDemo_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ProgressBar.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ProgressBar_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Ink.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Ink_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Wave.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Wave_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Dialog.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Dialog_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/ApplicationWindowStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_ApplicationWindowStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QtQuick/Controls/Styles/Material/ToolBarStyle.qml"), &QmlCacheGeneratedCode::_0x5f_QtQuick_Controls_Styles_Material_ToolBarStyle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ActionButton.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ActionButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/Subheader.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_Subheader_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ProgressCircle.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ProgressCircle_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/Card.qml"), &QmlCacheGeneratedCode::_0x5f_Material_Card_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/ListItems/BaseListItem.qml"), &QmlCacheGeneratedCode::_0x5f_Material_ListItems_BaseListItem_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/TimePicker.qml"), &QmlCacheGeneratedCode::_0x5f_Material_TimePicker_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Material/TimePickerDialog.qml"), &QmlCacheGeneratedCode::_0x5f_Material_TimePickerDialog_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}
const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_main)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_main))
int QT_MANGLE_NAMESPACE(qCleanupResources_main)() {
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_components)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_components))
int QT_MANGLE_NAMESPACE(qCleanupResources_components)() {
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_controls)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_controls))
int QT_MANGLE_NAMESPACE(qCleanupResources_controls)() {
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_core)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(material_src_core_core_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_core))
int QT_MANGLE_NAMESPACE(qCleanupResources_core)() {
    Q_CLEANUP_RESOURCE(material_src_core_core_qmlcache);
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_extras)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(material_src_extras_extras_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_extras))
int QT_MANGLE_NAMESPACE(qCleanupResources_extras)() {
    Q_CLEANUP_RESOURCE(material_src_extras_extras_qmlcache);
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_listitems)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(material_src_listitems_listitems_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_listitems))
int QT_MANGLE_NAMESPACE(qCleanupResources_listitems)() {
    Q_CLEANUP_RESOURCE(material_src_listitems_listitems_qmlcache);
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_popups)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_popups))
int QT_MANGLE_NAMESPACE(qCleanupResources_popups)() {
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_styles)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(material_src_styles_styles_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_styles))
int QT_MANGLE_NAMESPACE(qCleanupResources_styles)() {
    Q_CLEANUP_RESOURCE(material_src_styles_styles_qmlcache);
    return 1;
}
int QT_MANGLE_NAMESPACE(qInitResources_window)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_window))
int QT_MANGLE_NAMESPACE(qCleanupResources_window)() {
    return 1;
}
