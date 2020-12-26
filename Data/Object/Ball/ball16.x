xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 230;
 -0.44456;0.44456;0.44456;,
 -0.32833;0.49249;0.49249;,
 -0.37350;0.56026;0.37350;,
 -0.49249;0.49249;0.32833;,
 -0.17665;0.52995;0.52995;,
 -0.20579;0.61737;0.41158;,
 0.00000;0.54447;0.54447;,
 0.00000;0.64068;0.42712;,
 0.17665;0.52995;0.52995;,
 0.20579;0.61737;0.41158;,
 0.32833;0.49249;0.49249;,
 0.37350;0.56026;0.37350;,
 0.44456;0.44456;0.44456;,
 0.49249;0.49249;0.32833;,
 -0.41158;0.61737;0.20579;,
 -0.52995;0.52995;0.17665;,
 -0.23216;0.69649;0.23216;,
 0.00000;0.73049;0.24350;,
 0.23216;0.69649;0.23216;,
 0.41158;0.61737;0.20579;,
 0.52995;0.52995;0.17665;,
 -0.42712;0.64068;-0.00000;,
 -0.54447;0.54447;-0.00000;,
 -0.24350;0.73049;-0.00000;,
 0.00000;0.77000;-0.00000;,
 0.24350;0.73049;-0.00000;,
 0.42712;0.64068;-0.00000;,
 0.54447;0.54447;-0.00000;,
 -0.41158;0.61737;-0.20579;,
 -0.52995;0.52995;-0.17665;,
 -0.23216;0.69649;-0.23216;,
 0.00000;0.77000;-0.00000;,
 0.00000;0.73049;-0.24350;,
 0.23216;0.69649;-0.23216;,
 0.00000;0.73049;-0.24350;,
 0.41158;0.61737;-0.20579;,
 0.52995;0.52995;-0.17665;,
 -0.37350;0.56026;-0.37350;,
 -0.49249;0.49249;-0.32833;,
 -0.20579;0.61737;-0.41158;,
 0.00000;0.64068;-0.42712;,
 0.20579;0.61737;-0.41158;,
 0.00000;0.64068;-0.42712;,
 0.37350;0.56026;-0.37350;,
 0.49249;0.49249;-0.32833;,
 -0.32833;0.49249;-0.49249;,
 -0.44456;0.44456;-0.44456;,
 -0.17665;0.52995;-0.52995;,
 0.00000;0.54447;-0.54447;,
 0.17665;0.52995;-0.52995;,
 0.00000;0.54447;-0.54447;,
 0.32833;0.49249;-0.49249;,
 0.44456;0.44456;-0.44456;,
 -0.37350;0.37350;-0.56026;,
 -0.49249;0.32833;-0.49249;,
 -0.20579;0.41158;-0.61737;,
 0.00000;0.42712;-0.64068;,
 0.20579;0.41158;-0.61737;,
 0.00000;0.42712;-0.64068;,
 0.37350;0.37350;-0.56026;,
 0.49249;0.32833;-0.49249;,
 -0.41158;0.20579;-0.61737;,
 -0.52995;0.17665;-0.52995;,
 -0.23216;0.23216;-0.69649;,
 0.00000;0.24350;-0.73049;,
 0.23216;0.23216;-0.69649;,
 0.00000;0.24350;-0.73049;,
 0.41158;0.20579;-0.61737;,
 0.52995;0.17665;-0.52995;,
 -0.42712;-0.00000;-0.64068;,
 -0.54447;-0.00000;-0.54447;,
 -0.24350;-0.00000;-0.73049;,
 0.00000;-0.00000;-0.77000;,
 0.24350;-0.00000;-0.73049;,
 0.00000;-0.00000;-0.77000;,
 0.42712;-0.00000;-0.64068;,
 0.54447;-0.00000;-0.54447;,
 -0.41158;-0.20579;-0.61737;,
 -0.52995;-0.17665;-0.52995;,
 -0.23216;-0.23216;-0.69649;,
 0.00000;-0.24350;-0.73049;,
 0.23216;-0.23216;-0.69649;,
 0.00000;-0.24350;-0.73049;,
 0.41158;-0.20579;-0.61737;,
 0.52995;-0.17665;-0.52995;,
 -0.37350;-0.37350;-0.56026;,
 -0.49249;-0.32833;-0.49249;,
 -0.20579;-0.41158;-0.61737;,
 0.00000;-0.42712;-0.64068;,
 0.20579;-0.41158;-0.61737;,
 0.00000;-0.42712;-0.64068;,
 0.37350;-0.37350;-0.56026;,
 0.49249;-0.32833;-0.49249;,
 -0.32833;-0.49249;-0.49249;,
 -0.44456;-0.44456;-0.44456;,
 -0.17665;-0.52995;-0.52995;,
 0.00000;-0.54447;-0.54447;,
 0.17665;-0.52995;-0.52995;,
 0.00000;-0.54447;-0.54447;,
 0.32833;-0.49249;-0.49249;,
 0.44456;-0.44456;-0.44456;,
 -0.37350;-0.56026;-0.37350;,
 -0.49249;-0.49249;-0.32833;,
 -0.20579;-0.61737;-0.41158;,
 0.00000;-0.64068;-0.42712;,
 0.20579;-0.61737;-0.41158;,
 0.00000;-0.64068;-0.42712;,
 0.37350;-0.56026;-0.37350;,
 0.49249;-0.49249;-0.32833;,
 -0.41158;-0.61737;-0.20579;,
 -0.52995;-0.52995;-0.17665;,
 -0.23216;-0.69649;-0.23216;,
 0.00000;-0.73049;-0.24350;,
 0.23216;-0.69649;-0.23216;,
 0.00000;-0.73049;-0.24350;,
 0.41158;-0.61737;-0.20579;,
 0.52995;-0.52995;-0.17665;,
 -0.42712;-0.64068;0.00000;,
 -0.54447;-0.54447;0.00000;,
 -0.24350;-0.73049;0.00000;,
 0.00000;-0.77000;0.00000;,
 0.24350;-0.73049;0.00000;,
 0.42712;-0.64068;0.00000;,
 0.54447;-0.54447;0.00000;,
 -0.41158;-0.61737;0.20579;,
 -0.52995;-0.52995;0.17665;,
 -0.23216;-0.69649;0.23216;,
 0.00000;-0.73049;0.24350;,
 0.23216;-0.69649;0.23216;,
 0.41158;-0.61737;0.20579;,
 0.52995;-0.52995;0.17665;,
 -0.37350;-0.56026;0.37350;,
 -0.49249;-0.49249;0.32833;,
 -0.20579;-0.61737;0.41158;,
 0.00000;-0.64068;0.42712;,
 0.20579;-0.61737;0.41158;,
 0.37350;-0.56026;0.37350;,
 0.49249;-0.49249;0.32833;,
 -0.32833;-0.49249;0.49249;,
 -0.44456;-0.44456;0.44456;,
 -0.17665;-0.52995;0.52995;,
 0.00000;-0.54447;0.54447;,
 0.17665;-0.52995;0.52995;,
 0.32833;-0.49249;0.49249;,
 0.44456;-0.44456;0.44456;,
 -0.37350;-0.37350;0.56026;,
 -0.49249;-0.32833;0.49249;,
 -0.20579;-0.41158;0.61737;,
 0.00000;-0.42712;0.64068;,
 0.20579;-0.41158;0.61737;,
 0.37350;-0.37350;0.56026;,
 0.49249;-0.32833;0.49249;,
 -0.41158;-0.20579;0.61737;,
 -0.52995;-0.17665;0.52995;,
 -0.23216;-0.23216;0.69649;,
 0.00000;-0.24350;0.73049;,
 0.23216;-0.23216;0.69649;,
 0.41158;-0.20579;0.61737;,
 0.52995;-0.17665;0.52995;,
 -0.42712;0.00000;0.64068;,
 -0.54447;0.00000;0.54447;,
 -0.24350;0.00000;0.73049;,
 0.00000;0.00000;0.77000;,
 0.24350;0.00000;0.73049;,
 0.42712;0.00000;0.64068;,
 0.54447;0.00000;0.54447;,
 -0.41158;0.20579;0.61737;,
 -0.52995;0.17665;0.52995;,
 -0.23216;0.23216;0.69649;,
 0.00000;0.24350;0.73049;,
 0.23216;0.23216;0.69649;,
 0.41158;0.20579;0.61737;,
 0.52995;0.17665;0.52995;,
 -0.37350;0.37350;0.56026;,
 -0.49249;0.32833;0.49249;,
 -0.20579;0.41158;0.61737;,
 0.00000;0.42712;0.64068;,
 0.20579;0.41158;0.61737;,
 0.37350;0.37350;0.56026;,
 0.49249;0.32833;0.49249;,
 0.56026;0.37350;0.37350;,
 0.61737;0.20579;0.41158;,
 0.64068;-0.00000;0.42712;,
 0.61737;-0.20579;0.41158;,
 0.56026;-0.37350;0.37350;,
 0.61737;0.41158;0.20579;,
 0.69649;0.23216;0.23216;,
 0.73049;-0.00000;0.24350;,
 0.69649;-0.23216;0.23216;,
 0.61737;-0.41158;0.20579;,
 0.64068;0.42712;-0.00000;,
 0.73049;0.24350;-0.00000;,
 0.77000;-0.00000;-0.00000;,
 0.73049;-0.24350;-0.00000;,
 0.64068;-0.42712;-0.00000;,
 0.61737;0.41158;-0.20579;,
 0.69649;0.23216;-0.23216;,
 0.73049;-0.00000;-0.24350;,
 0.69649;-0.23216;-0.23216;,
 0.61737;-0.41158;-0.20579;,
 0.56026;0.37350;-0.37350;,
 0.61737;0.20579;-0.41158;,
 0.64068;-0.00000;-0.42712;,
 0.61737;-0.20579;-0.41158;,
 0.56026;-0.37350;-0.37350;,
 -0.56026;-0.37350;0.37350;,
 -0.61737;-0.20579;0.41158;,
 -0.64068;0.00000;0.42712;,
 -0.61737;0.20579;0.41158;,
 -0.56026;0.37350;0.37350;,
 -0.61737;-0.41158;0.20579;,
 -0.69649;-0.23216;0.23216;,
 -0.73049;0.00000;0.24350;,
 -0.69649;0.23216;0.23216;,
 -0.61737;0.41158;0.20579;,
 -0.64068;-0.42712;-0.00000;,
 -0.73049;-0.24350;-0.00000;,
 -0.77000;0.00000;-0.00000;,
 -0.73049;0.24350;-0.00000;,
 -0.64068;0.42712;-0.00000;,
 -0.61737;-0.41158;-0.20579;,
 -0.69649;-0.23216;-0.23216;,
 -0.73049;0.00000;-0.24350;,
 -0.69649;0.23216;-0.23216;,
 -0.61737;0.41158;-0.20579;,
 -0.56026;-0.37350;-0.37350;,
 -0.61737;-0.20579;-0.41158;,
 -0.64068;0.00000;-0.42712;,
 -0.61737;0.20579;-0.41158;,
 -0.56026;0.37350;-0.37350;;
 
 216;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;3,2,14,15;,
 4;2,5,16,14;,
 4;5,7,17,16;,
 4;7,9,18,17;,
 4;9,11,19,18;,
 4;11,13,20,19;,
 4;15,14,21,22;,
 4;14,16,23,21;,
 4;16,17,24,23;,
 4;17,18,25,24;,
 4;18,19,26,25;,
 4;19,20,27,26;,
 4;22,21,28,29;,
 4;21,23,30,28;,
 4;23,31,32,30;,
 4;24,25,33,34;,
 4;25,26,35,33;,
 4;26,27,36,35;,
 4;29,28,37,38;,
 4;28,30,39,37;,
 4;30,32,40,39;,
 4;34,33,41,42;,
 4;33,35,43,41;,
 4;35,36,44,43;,
 4;38,37,45,46;,
 4;37,39,47,45;,
 4;39,40,48,47;,
 4;42,41,49,50;,
 4;41,43,51,49;,
 4;43,44,52,51;,
 4;46,45,53,54;,
 4;45,47,55,53;,
 4;47,48,56,55;,
 4;50,49,57,58;,
 4;49,51,59,57;,
 4;51,52,60,59;,
 4;54,53,61,62;,
 4;53,55,63,61;,
 4;55,56,64,63;,
 4;58,57,65,66;,
 4;57,59,67,65;,
 4;59,60,68,67;,
 4;62,61,69,70;,
 4;61,63,71,69;,
 4;63,64,72,71;,
 4;66,65,73,74;,
 4;65,67,75,73;,
 4;67,68,76,75;,
 4;70,69,77,78;,
 4;69,71,79,77;,
 4;71,72,80,79;,
 4;74,73,81,82;,
 4;73,75,83,81;,
 4;75,76,84,83;,
 4;78,77,85,86;,
 4;77,79,87,85;,
 4;79,80,88,87;,
 4;82,81,89,90;,
 4;81,83,91,89;,
 4;83,84,92,91;,
 4;86,85,93,94;,
 4;85,87,95,93;,
 4;87,88,96,95;,
 4;90,89,97,98;,
 4;89,91,99,97;,
 4;91,92,100,99;,
 4;94,93,101,102;,
 4;93,95,103,101;,
 4;95,96,104,103;,
 4;98,97,105,106;,
 4;97,99,107,105;,
 4;99,100,108,107;,
 4;102,101,109,110;,
 4;101,103,111,109;,
 4;103,104,112,111;,
 4;106,105,113,114;,
 4;105,107,115,113;,
 4;107,108,116,115;,
 4;110,109,117,118;,
 4;109,111,119,117;,
 4;111,112,120,119;,
 4;114,113,121,120;,
 4;113,115,122,121;,
 4;115,116,123,122;,
 4;118,117,124,125;,
 4;117,119,126,124;,
 4;119,120,127,126;,
 4;120,121,128,127;,
 4;121,122,129,128;,
 4;122,123,130,129;,
 4;125,124,131,132;,
 4;124,126,133,131;,
 4;126,127,134,133;,
 4;127,128,135,134;,
 4;128,129,136,135;,
 4;129,130,137,136;,
 4;132,131,138,139;,
 4;131,133,140,138;,
 4;133,134,141,140;,
 4;134,135,142,141;,
 4;135,136,143,142;,
 4;136,137,144,143;,
 4;139,138,145,146;,
 4;138,140,147,145;,
 4;140,141,148,147;,
 4;141,142,149,148;,
 4;142,143,150,149;,
 4;143,144,151,150;,
 4;146,145,152,153;,
 4;145,147,154,152;,
 4;147,148,155,154;,
 4;148,149,156,155;,
 4;149,150,157,156;,
 4;150,151,158,157;,
 4;153,152,159,160;,
 4;152,154,161,159;,
 4;154,155,162,161;,
 4;155,156,163,162;,
 4;156,157,164,163;,
 4;157,158,165,164;,
 4;160,159,166,167;,
 4;159,161,168,166;,
 4;161,162,169,168;,
 4;162,163,170,169;,
 4;163,164,171,170;,
 4;164,165,172,171;,
 4;167,166,173,174;,
 4;166,168,175,173;,
 4;168,169,176,175;,
 4;169,170,177,176;,
 4;170,171,178,177;,
 4;171,172,179,178;,
 4;174,173,1,0;,
 4;173,175,4,1;,
 4;175,176,6,4;,
 4;176,177,8,6;,
 4;177,178,10,8;,
 4;178,179,12,10;,
 4;12,179,180,13;,
 4;179,172,181,180;,
 4;172,165,182,181;,
 4;165,158,183,182;,
 4;158,151,184,183;,
 4;151,144,137,184;,
 4;13,180,185,20;,
 4;180,181,186,185;,
 4;181,182,187,186;,
 4;182,183,188,187;,
 4;183,184,189,188;,
 4;184,137,130,189;,
 4;20,185,190,27;,
 4;185,186,191,190;,
 4;186,187,192,191;,
 4;187,188,193,192;,
 4;188,189,194,193;,
 4;189,130,123,194;,
 4;27,190,195,36;,
 4;190,191,196,195;,
 4;191,192,197,196;,
 4;192,193,198,197;,
 4;193,194,199,198;,
 4;194,123,116,199;,
 4;36,195,200,44;,
 4;195,196,201,200;,
 4;196,197,202,201;,
 4;197,198,203,202;,
 4;198,199,204,203;,
 4;199,116,108,204;,
 4;44,200,60,52;,
 4;200,201,68,60;,
 4;201,202,76,68;,
 4;202,203,84,76;,
 4;203,204,92,84;,
 4;204,108,100,92;,
 4;139,146,205,132;,
 4;146,153,206,205;,
 4;153,160,207,206;,
 4;160,167,208,207;,
 4;167,174,209,208;,
 4;174,0,3,209;,
 4;132,205,210,125;,
 4;205,206,211,210;,
 4;206,207,212,211;,
 4;207,208,213,212;,
 4;208,209,214,213;,
 4;209,3,15,214;,
 4;125,210,215,118;,
 4;210,211,216,215;,
 4;211,212,217,216;,
 4;212,213,218,217;,
 4;213,214,219,218;,
 4;214,15,22,219;,
 4;118,215,220,110;,
 4;215,216,221,220;,
 4;216,217,222,221;,
 4;217,218,223,222;,
 4;218,219,224,223;,
 4;219,22,29,224;,
 4;110,220,225,102;,
 4;220,221,226,225;,
 4;221,222,227,226;,
 4;222,223,228,227;,
 4;223,224,229,228;,
 4;224,29,38,229;,
 4;102,225,86,94;,
 4;225,226,78,86;,
 4;226,227,70,78;,
 4;227,228,62,70;,
 4;228,229,54,62;,
 4;229,38,46,54;;
 
 MeshMaterialList {
  1;
  216;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.180000;0.180000;0.180000;1.000000;;
   10.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  218;
  -0.577350;0.577350;0.577350;,
  -0.447976;0.632186;0.632185;,
  -0.242216;0.686051;0.686051;,
  0.000000;0.707107;0.707107;,
  0.242216;0.686051;0.686051;,
  0.447976;0.632185;0.632186;,
  0.577350;0.577350;0.577350;,
  -0.632185;0.632186;0.447976;,
  -0.473576;0.742598;0.473576;,
  -0.258479;0.817069;0.515352;,
  0.000000;0.847101;0.531432;,
  0.258479;0.817069;0.515352;,
  0.473576;0.742598;0.473576;,
  0.632186;0.632186;0.447976;,
  -0.686051;0.686051;0.242216;,
  -0.515352;0.817069;0.258479;,
  -0.285910;0.914610;0.285910;,
  -0.000000;0.954938;0.296806;,
  0.285910;0.914610;0.285910;,
  0.515352;0.817069;0.258479;,
  0.686051;0.686051;0.242216;,
  -0.707107;0.707107;0.000000;,
  -0.531432;0.847101;-0.000000;,
  -0.296806;0.954938;0.000000;,
  -0.000000;1.000000;0.000000;,
  0.296806;0.954938;0.000000;,
  0.531433;0.847101;0.000000;,
  0.707107;0.707107;0.000000;,
  -0.686051;0.686051;-0.242216;,
  -0.515352;0.817069;-0.258479;,
  -0.285910;0.914610;-0.285910;,
  -0.000000;0.954938;-0.296806;,
  0.285910;0.914610;-0.285910;,
  0.515352;0.817069;-0.258479;,
  0.686051;0.686051;-0.242216;,
  -0.632186;0.632185;-0.447976;,
  -0.473576;0.742598;-0.473576;,
  -0.258479;0.817069;-0.515352;,
  -0.000000;0.847101;-0.531433;,
  0.258479;0.817069;-0.515352;,
  0.473576;0.742598;-0.473576;,
  0.632185;0.632186;-0.447976;,
  -0.577350;0.577350;-0.577350;,
  -0.447976;0.632185;-0.632186;,
  -0.242216;0.686051;-0.686051;,
  0.000000;0.707107;-0.707107;,
  0.242216;0.686051;-0.686051;,
  0.447976;0.632186;-0.632185;,
  0.577350;0.577350;-0.577350;,
  -0.632186;0.447976;-0.632186;,
  -0.473576;0.473576;-0.742598;,
  -0.258479;0.515352;-0.817069;,
  0.000000;0.531432;-0.847101;,
  0.258479;0.515352;-0.817069;,
  0.473576;0.473576;-0.742598;,
  0.632186;0.447976;-0.632186;,
  -0.686051;0.242216;-0.686051;,
  -0.515352;0.258479;-0.817069;,
  -0.285910;0.285910;-0.914610;,
  -0.000000;0.296806;-0.954938;,
  0.285910;0.285910;-0.914610;,
  0.515352;0.258479;-0.817069;,
  0.686051;0.242216;-0.686051;,
  -0.707107;-0.000000;-0.707107;,
  -0.531432;-0.000000;-0.847101;,
  -0.296806;0.000000;-0.954938;,
  -0.000000;0.000000;-1.000000;,
  0.296806;0.000000;-0.954938;,
  0.531433;0.000000;-0.847101;,
  0.707107;0.000000;-0.707107;,
  -0.686051;-0.242216;-0.686051;,
  -0.515352;-0.258479;-0.817069;,
  -0.285910;-0.285910;-0.914610;,
  -0.000000;-0.296806;-0.954938;,
  0.285910;-0.285910;-0.914610;,
  0.515352;-0.258479;-0.817069;,
  0.686051;-0.242216;-0.686051;,
  -0.632185;-0.447976;-0.632186;,
  -0.473576;-0.473576;-0.742598;,
  -0.258479;-0.515352;-0.817069;,
  -0.000000;-0.531433;-0.847101;,
  0.258479;-0.515352;-0.817069;,
  0.473576;-0.473576;-0.742598;,
  0.632186;-0.447976;-0.632186;,
  -0.577350;-0.577350;-0.577350;,
  -0.447976;-0.632186;-0.632185;,
  -0.242216;-0.686051;-0.686051;,
  0.000000;-0.707107;-0.707107;,
  0.242216;-0.686051;-0.686051;,
  0.447976;-0.632185;-0.632186;,
  0.577350;-0.577350;-0.577350;,
  -0.632185;-0.632186;-0.447976;,
  -0.473576;-0.742598;-0.473576;,
  -0.258479;-0.817069;-0.515352;,
  0.000000;-0.847101;-0.531432;,
  0.258479;-0.817069;-0.515352;,
  0.473576;-0.742598;-0.473576;,
  0.632186;-0.632185;-0.447976;,
  -0.686051;-0.686051;-0.242216;,
  -0.515352;-0.817069;-0.258479;,
  -0.285910;-0.914610;-0.285910;,
  -0.000000;-0.954938;-0.296806;,
  0.285910;-0.914610;-0.285910;,
  0.515352;-0.817069;-0.258479;,
  0.686051;-0.686051;-0.242216;,
  -0.707107;-0.707107;0.000000;,
  -0.531432;-0.847101;0.000000;,
  -0.296806;-0.954938;-0.000000;,
  -0.000000;-1.000000;-0.000000;,
  0.296806;-0.954938;-0.000000;,
  0.531433;-0.847101;-0.000000;,
  0.707107;-0.707107;-0.000000;,
  -0.686051;-0.686051;0.242216;,
  -0.515352;-0.817069;0.258479;,
  -0.285910;-0.914610;0.285910;,
  -0.000000;-0.954938;0.296806;,
  0.285910;-0.914610;0.285910;,
  0.515352;-0.817069;0.258479;,
  0.686051;-0.686051;0.242216;,
  -0.632186;-0.632185;0.447976;,
  -0.473576;-0.742598;0.473576;,
  -0.258479;-0.817069;0.515352;,
  -0.000000;-0.847101;0.531433;,
  0.258479;-0.817069;0.515352;,
  0.473576;-0.742598;0.473576;,
  0.632185;-0.632186;0.447976;,
  -0.577350;-0.577350;0.577350;,
  -0.447976;-0.632185;0.632186;,
  -0.242216;-0.686051;0.686051;,
  0.000000;-0.707107;0.707107;,
  0.242216;-0.686051;0.686051;,
  0.447976;-0.632186;0.632185;,
  0.577350;-0.577350;0.577350;,
  -0.632186;-0.447976;0.632186;,
  -0.473576;-0.473576;0.742598;,
  -0.258479;-0.515352;0.817069;,
  0.000000;-0.531432;0.847101;,
  0.258479;-0.515352;0.817069;,
  0.473576;-0.473576;0.742598;,
  0.632186;-0.447976;0.632186;,
  -0.686051;-0.242216;0.686051;,
  -0.515352;-0.258479;0.817069;,
  -0.285910;-0.285910;0.914610;,
  -0.000000;-0.296806;0.954938;,
  0.285910;-0.285910;0.914610;,
  0.515352;-0.258479;0.817069;,
  0.686051;-0.242216;0.686051;,
  -0.707107;0.000000;0.707107;,
  -0.531432;0.000000;0.847101;,
  -0.296806;-0.000000;0.954938;,
  -0.000000;-0.000000;1.000000;,
  0.296806;-0.000000;0.954938;,
  0.531433;-0.000000;0.847101;,
  0.707107;-0.000000;0.707107;,
  -0.686051;0.242216;0.686051;,
  -0.515352;0.258479;0.817069;,
  -0.285910;0.285910;0.914610;,
  -0.000000;0.296806;0.954938;,
  0.285910;0.285910;0.914610;,
  0.515352;0.258479;0.817069;,
  0.686051;0.242216;0.686051;,
  -0.632186;0.447977;0.632186;,
  -0.473576;0.473576;0.742598;,
  -0.258479;0.515352;0.817069;,
  -0.000000;0.531433;0.847101;,
  0.258479;0.515352;0.817069;,
  0.473576;0.473576;0.742598;,
  0.632186;0.447976;0.632186;,
  0.742598;0.473576;0.473576;,
  0.817069;0.258479;0.515352;,
  0.847101;0.000000;0.531432;,
  0.817069;-0.258479;0.515352;,
  0.742598;-0.473576;0.473576;,
  0.817069;0.515352;0.258479;,
  0.914610;0.285910;0.285910;,
  0.954938;0.000000;0.296806;,
  0.914610;-0.285910;0.285910;,
  0.817069;-0.515352;0.258479;,
  0.847101;0.531432;-0.000000;,
  0.954938;0.296806;0.000000;,
  1.000000;0.000000;0.000000;,
  0.954938;-0.296806;0.000000;,
  0.847101;-0.531433;0.000000;,
  0.817069;0.515352;-0.258479;,
  0.914610;0.285910;-0.285910;,
  0.954938;0.000000;-0.296806;,
  0.914610;-0.285910;-0.285910;,
  0.817069;-0.515352;-0.258479;,
  0.742598;0.473576;-0.473576;,
  0.817069;0.258479;-0.515352;,
  0.847101;0.000000;-0.531433;,
  0.817069;-0.258479;-0.515352;,
  0.742598;-0.473576;-0.473576;,
  -0.742598;-0.473576;0.473576;,
  -0.817069;-0.258479;0.515352;,
  -0.847101;0.000000;0.531432;,
  -0.817069;0.258479;0.515352;,
  -0.742598;0.473576;0.473576;,
  -0.817069;-0.515352;0.258479;,
  -0.914610;-0.285910;0.285910;,
  -0.954938;-0.000000;0.296806;,
  -0.914610;0.285910;0.285910;,
  -0.817069;0.515352;0.258479;,
  -0.847101;-0.531432;0.000000;,
  -0.954938;-0.296806;0.000000;,
  -1.000000;-0.000000;0.000000;,
  -0.954938;0.296806;0.000000;,
  -0.847101;0.531433;0.000000;,
  -0.817069;-0.515352;-0.258479;,
  -0.914610;-0.285910;-0.285910;,
  -0.954938;-0.000000;-0.296806;,
  -0.914610;0.285910;-0.285910;,
  -0.817069;0.515352;-0.258479;,
  -0.742598;-0.473576;-0.473576;,
  -0.817069;-0.258479;-0.515352;,
  -0.847101;0.000000;-0.531433;,
  -0.817069;0.258479;-0.515352;,
  -0.742598;0.473576;-0.473576;;
  216;
  4;0,1,8,7;,
  4;1,2,9,8;,
  4;2,3,10,9;,
  4;3,4,11,10;,
  4;4,5,12,11;,
  4;5,6,13,12;,
  4;7,8,15,14;,
  4;8,9,16,15;,
  4;9,10,17,16;,
  4;10,11,18,17;,
  4;11,12,19,18;,
  4;12,13,20,19;,
  4;14,15,22,21;,
  4;15,16,23,22;,
  4;16,17,24,23;,
  4;17,18,25,24;,
  4;18,19,26,25;,
  4;19,20,27,26;,
  4;21,22,29,28;,
  4;22,23,30,29;,
  4;23,24,31,30;,
  4;24,25,32,31;,
  4;25,26,33,32;,
  4;26,27,34,33;,
  4;28,29,36,35;,
  4;29,30,37,36;,
  4;30,31,38,37;,
  4;31,32,39,38;,
  4;32,33,40,39;,
  4;33,34,41,40;,
  4;35,36,43,42;,
  4;36,37,44,43;,
  4;37,38,45,44;,
  4;38,39,46,45;,
  4;39,40,47,46;,
  4;40,41,48,47;,
  4;42,43,50,49;,
  4;43,44,51,50;,
  4;44,45,52,51;,
  4;45,46,53,52;,
  4;46,47,54,53;,
  4;47,48,55,54;,
  4;49,50,57,56;,
  4;50,51,58,57;,
  4;51,52,59,58;,
  4;52,53,60,59;,
  4;53,54,61,60;,
  4;54,55,62,61;,
  4;56,57,64,63;,
  4;57,58,65,64;,
  4;58,59,66,65;,
  4;59,60,67,66;,
  4;60,61,68,67;,
  4;61,62,69,68;,
  4;63,64,71,70;,
  4;64,65,72,71;,
  4;65,66,73,72;,
  4;66,67,74,73;,
  4;67,68,75,74;,
  4;68,69,76,75;,
  4;70,71,78,77;,
  4;71,72,79,78;,
  4;72,73,80,79;,
  4;73,74,81,80;,
  4;74,75,82,81;,
  4;75,76,83,82;,
  4;77,78,85,84;,
  4;78,79,86,85;,
  4;79,80,87,86;,
  4;80,81,88,87;,
  4;81,82,89,88;,
  4;82,83,90,89;,
  4;84,85,92,91;,
  4;85,86,93,92;,
  4;86,87,94,93;,
  4;87,88,95,94;,
  4;88,89,96,95;,
  4;89,90,97,96;,
  4;91,92,99,98;,
  4;92,93,100,99;,
  4;93,94,101,100;,
  4;94,95,102,101;,
  4;95,96,103,102;,
  4;96,97,104,103;,
  4;98,99,106,105;,
  4;99,100,107,106;,
  4;100,101,108,107;,
  4;101,102,109,108;,
  4;102,103,110,109;,
  4;103,104,111,110;,
  4;105,106,113,112;,
  4;106,107,114,113;,
  4;107,108,115,114;,
  4;108,109,116,115;,
  4;109,110,117,116;,
  4;110,111,118,117;,
  4;112,113,120,119;,
  4;113,114,121,120;,
  4;114,115,122,121;,
  4;115,116,123,122;,
  4;116,117,124,123;,
  4;117,118,125,124;,
  4;119,120,127,126;,
  4;120,121,128,127;,
  4;121,122,129,128;,
  4;122,123,130,129;,
  4;123,124,131,130;,
  4;124,125,132,131;,
  4;126,127,134,133;,
  4;127,128,135,134;,
  4;128,129,136,135;,
  4;129,130,137,136;,
  4;130,131,138,137;,
  4;131,132,139,138;,
  4;133,134,141,140;,
  4;134,135,142,141;,
  4;135,136,143,142;,
  4;136,137,144,143;,
  4;137,138,145,144;,
  4;138,139,146,145;,
  4;140,141,148,147;,
  4;141,142,149,148;,
  4;142,143,150,149;,
  4;143,144,151,150;,
  4;144,145,152,151;,
  4;145,146,153,152;,
  4;147,148,155,154;,
  4;148,149,156,155;,
  4;149,150,157,156;,
  4;150,151,158,157;,
  4;151,152,159,158;,
  4;152,153,160,159;,
  4;154,155,162,161;,
  4;155,156,163,162;,
  4;156,157,164,163;,
  4;157,158,165,164;,
  4;158,159,166,165;,
  4;159,160,167,166;,
  4;161,162,1,0;,
  4;162,163,2,1;,
  4;163,164,3,2;,
  4;164,165,4,3;,
  4;165,166,5,4;,
  4;166,167,6,5;,
  4;6,167,168,13;,
  4;167,160,169,168;,
  4;160,153,170,169;,
  4;153,146,171,170;,
  4;146,139,172,171;,
  4;139,132,125,172;,
  4;13,168,173,20;,
  4;168,169,174,173;,
  4;169,170,175,174;,
  4;170,171,176,175;,
  4;171,172,177,176;,
  4;172,125,118,177;,
  4;20,173,178,27;,
  4;173,174,179,178;,
  4;174,175,180,179;,
  4;175,176,181,180;,
  4;176,177,182,181;,
  4;177,118,111,182;,
  4;27,178,183,34;,
  4;178,179,184,183;,
  4;179,180,185,184;,
  4;180,181,186,185;,
  4;181,182,187,186;,
  4;182,111,104,187;,
  4;34,183,188,41;,
  4;183,184,189,188;,
  4;184,185,190,189;,
  4;185,186,191,190;,
  4;186,187,192,191;,
  4;187,104,97,192;,
  4;41,188,55,48;,
  4;188,189,62,55;,
  4;189,190,69,62;,
  4;190,191,76,69;,
  4;191,192,83,76;,
  4;192,97,90,83;,
  4;126,133,193,119;,
  4;133,140,194,193;,
  4;140,147,195,194;,
  4;147,154,196,195;,
  4;154,161,197,196;,
  4;161,0,7,197;,
  4;119,193,198,112;,
  4;193,194,199,198;,
  4;194,195,200,199;,
  4;195,196,201,200;,
  4;196,197,202,201;,
  4;197,7,14,202;,
  4;112,198,203,105;,
  4;198,199,204,203;,
  4;199,200,205,204;,
  4;200,201,206,205;,
  4;201,202,207,206;,
  4;202,14,21,207;,
  4;105,203,208,98;,
  4;203,204,209,208;,
  4;204,205,210,209;,
  4;205,206,211,210;,
  4;206,207,212,211;,
  4;207,21,28,212;,
  4;98,208,213,91;,
  4;208,209,214,213;,
  4;209,210,215,214;,
  4;210,211,216,215;,
  4;211,212,217,216;,
  4;212,28,35,217;,
  4;91,213,77,84;,
  4;213,214,70,77;,
  4;214,215,63,70;,
  4;215,216,56,63;,
  4;216,217,49,56;,
  4;217,35,42,49;;
 }
 MeshTextureCoords {
  230;
  0.625000;0.304087;
  0.593584;0.279099;
  0.625000;0.240633;
  0.656416;0.279099;
  0.551208;0.258380;
  0.573792;0.203885;
  0.500000;0.250000;
  0.500000;0.187167;
  0.448792;0.258380;
  0.426208;0.203885;
  0.406416;0.279099;
  0.375000;0.240633;
  0.375000;0.304087;
  0.343584;0.279099;
  0.676208;0.203885;
  0.698792;0.258380;
  0.625000;0.140219;
  0.500000;0.102416;
  0.375000;0.140219;
  0.323792;0.203885;
  0.301208;0.258380;
  0.750000;0.187167;
  0.750000;0.250000;
  0.750000;0.102416;
  0.125000;0.000000;
  0.250000;0.102416;
  0.250000;0.187167;
  0.250000;0.250000;
  0.823792;0.203885;
  0.801208;0.258380;
  0.875000;0.140219;
  1.125000;0.000000;
  1.000000;0.102416;
  0.125000;0.140219;
  0.000000;0.102416;
  0.176208;0.203885;
  0.198792;0.258380;
  0.875000;0.240633;
  0.843584;0.279099;
  0.926208;0.203885;
  1.000000;0.187167;
  0.073792;0.203885;
  0.000000;0.187167;
  0.125000;0.240633;
  0.156416;0.279099;
  0.906416;0.279099;
  0.875000;0.304087;
  0.948792;0.258380;
  1.000000;0.250000;
  0.051208;0.258380;
  0.000000;0.250000;
  0.093584;0.279099;
  0.125000;0.304087;
  0.906416;0.338794;
  0.875000;0.359781;
  0.948792;0.320491;
  1.000000;0.312833;
  0.051208;0.320491;
  0.000000;0.312833;
  0.093584;0.338794;
  0.125000;0.359781;
  0.906416;0.413881;
  0.875000;0.426318;
  0.948792;0.402509;
  1.000000;0.397584;
  0.051208;0.402509;
  0.000000;0.397584;
  0.093584;0.413881;
  0.125000;0.426318;
  0.906416;0.500000;
  0.875000;0.500000;
  0.948792;0.500000;
  1.000000;0.500000;
  0.051208;0.500000;
  0.000000;0.500000;
  0.093584;0.500000;
  0.125000;0.500000;
  0.906416;0.586119;
  0.875000;0.573682;
  0.948792;0.597491;
  1.000000;0.602416;
  0.051208;0.597491;
  0.000000;0.602416;
  0.093584;0.586119;
  0.125000;0.573682;
  0.906416;0.661206;
  0.875000;0.640219;
  0.948792;0.679509;
  1.000000;0.687167;
  0.051208;0.679509;
  0.000000;0.687167;
  0.093584;0.661206;
  0.125000;0.640219;
  0.906416;0.720901;
  0.875000;0.695913;
  0.948792;0.741620;
  1.000000;0.750000;
  0.051208;0.741620;
  0.000000;0.750000;
  0.093584;0.720901;
  0.125000;0.695913;
  0.875000;0.759367;
  0.843584;0.720901;
  0.926208;0.796115;
  1.000000;0.812833;
  0.073792;0.796115;
  0.000000;0.812833;
  0.125000;0.759367;
  0.156416;0.720901;
  0.823792;0.796115;
  0.801208;0.741620;
  0.875000;0.859781;
  1.000000;0.897584;
  0.125000;0.859781;
  0.000000;0.897584;
  0.176208;0.796115;
  0.198792;0.741620;
  0.750000;0.812833;
  0.750000;0.750000;
  0.750000;0.897584;
  0.375000;1.000000;
  0.250000;0.897584;
  0.250000;0.812833;
  0.250000;0.750000;
  0.676208;0.796115;
  0.698792;0.741620;
  0.625000;0.859781;
  0.500000;0.897584;
  0.375000;0.859781;
  0.323792;0.796115;
  0.301208;0.741620;
  0.625000;0.759367;
  0.656416;0.720901;
  0.573792;0.796115;
  0.500000;0.812833;
  0.426208;0.796115;
  0.375000;0.759367;
  0.343584;0.720901;
  0.593584;0.720901;
  0.625000;0.695913;
  0.551208;0.741620;
  0.500000;0.750000;
  0.448792;0.741620;
  0.406416;0.720901;
  0.375000;0.695913;
  0.593584;0.661206;
  0.625000;0.640219;
  0.551208;0.679509;
  0.500000;0.687167;
  0.448792;0.679509;
  0.406416;0.661206;
  0.375000;0.640219;
  0.593584;0.586119;
  0.625000;0.573682;
  0.551208;0.597491;
  0.500000;0.602416;
  0.448792;0.597491;
  0.406416;0.586119;
  0.375000;0.573682;
  0.593584;0.500000;
  0.625000;0.500000;
  0.551208;0.500000;
  0.500000;0.500000;
  0.448792;0.500000;
  0.406416;0.500000;
  0.375000;0.500000;
  0.593584;0.413881;
  0.625000;0.426318;
  0.551208;0.402509;
  0.500000;0.397584;
  0.448792;0.402509;
  0.406416;0.413881;
  0.375000;0.426318;
  0.593584;0.338794;
  0.625000;0.359781;
  0.551208;0.320491;
  0.500000;0.312833;
  0.448792;0.320491;
  0.406416;0.338794;
  0.375000;0.359781;
  0.343584;0.338794;
  0.343584;0.413881;
  0.343584;0.500000;
  0.343584;0.586119;
  0.343584;0.661206;
  0.301208;0.320491;
  0.301208;0.402509;
  0.301208;0.500000;
  0.301208;0.597491;
  0.301208;0.679509;
  0.250000;0.312833;
  0.250000;0.397584;
  0.250000;0.500000;
  0.250000;0.602416;
  0.250000;0.687167;
  0.198792;0.320491;
  0.198792;0.402509;
  0.198792;0.500000;
  0.198792;0.597491;
  0.198792;0.679509;
  0.156416;0.338794;
  0.156416;0.413881;
  0.156416;0.500000;
  0.156416;0.586119;
  0.156416;0.661206;
  0.656416;0.661206;
  0.656416;0.586119;
  0.656416;0.500000;
  0.656416;0.413881;
  0.656416;0.338794;
  0.698792;0.679509;
  0.698792;0.597491;
  0.698792;0.500000;
  0.698792;0.402509;
  0.698792;0.320491;
  0.750000;0.687167;
  0.750000;0.602416;
  0.750000;0.500000;
  0.750000;0.397584;
  0.750000;0.312833;
  0.801208;0.679509;
  0.801208;0.597491;
  0.801208;0.500000;
  0.801208;0.402509;
  0.801208;0.320491;
  0.843584;0.661206;
  0.843584;0.586119;
  0.843584;0.500000;
  0.843584;0.413881;
  0.843584;0.338794;;
 }
}
