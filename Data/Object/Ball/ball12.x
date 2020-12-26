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
 107;
 -0.28868;0.28868;0.28868;,
 -0.16667;0.33333;0.33333;,
 -0.20412;0.40825;0.20412;,
 -0.33333;0.33333;0.16667;,
 0.00000;0.35355;0.35355;,
 0.00000;0.44721;0.22361;,
 0.16667;0.33333;0.33333;,
 0.20412;0.40825;0.20412;,
 0.28868;0.28868;0.28868;,
 0.33333;0.33333;0.16667;,
 -0.22361;0.44721;0.00000;,
 -0.35355;0.35355;0.00000;,
 0.00000;0.50000;0.00000;,
 0.22361;0.44721;0.00000;,
 0.35355;0.35355;0.00000;,
 -0.20412;0.40825;-0.20412;,
 -0.33333;0.33333;-0.16667;,
 0.00000;0.44721;-0.22361;,
 0.20412;0.40825;-0.20412;,
 0.33333;0.33333;-0.16667;,
 0.20412;0.40825;-0.20412;,
 -0.16667;0.33333;-0.33333;,
 -0.28868;0.28868;-0.28868;,
 0.00000;0.35355;-0.35355;,
 0.00000;0.44721;-0.22361;,
 0.16667;0.33333;-0.33333;,
 0.00000;0.35355;-0.35355;,
 0.28868;0.28868;-0.28868;,
 -0.20412;0.20412;-0.40825;,
 -0.33333;0.16667;-0.33333;,
 0.00000;0.22361;-0.44721;,
 0.20412;0.20412;-0.40825;,
 0.00000;0.22361;-0.44721;,
 0.33333;0.16667;-0.33333;,
 -0.22361;0.00000;-0.44721;,
 -0.35355;0.00000;-0.35355;,
 0.00000;0.00000;-0.50000;,
 0.22361;0.00000;-0.44721;,
 0.00000;0.00000;-0.50000;,
 0.35355;0.00000;-0.35355;,
 -0.20412;-0.20412;-0.40825;,
 -0.33333;-0.16667;-0.33333;,
 0.00000;-0.22361;-0.44721;,
 0.20412;-0.20412;-0.40825;,
 0.00000;-0.22361;-0.44721;,
 0.33333;-0.16667;-0.33333;,
 -0.16667;-0.33333;-0.33333;,
 -0.28868;-0.28868;-0.28868;,
 0.00000;-0.35355;-0.35355;,
 0.16667;-0.33333;-0.33333;,
 0.00000;-0.35355;-0.35355;,
 0.28868;-0.28868;-0.28868;,
 -0.20412;-0.40825;-0.20412;,
 -0.33333;-0.33333;-0.16667;,
 0.00000;-0.44721;-0.22361;,
 0.20412;-0.40825;-0.20412;,
 0.00000;-0.44721;-0.22361;,
 0.33333;-0.33333;-0.16667;,
 -0.22361;-0.44721;0.00000;,
 -0.35355;-0.35355;0.00000;,
 0.00000;-0.50000;-0.00000;,
 0.22361;-0.44721;-0.00000;,
 0.00000;-0.50000;-0.00000;,
 0.35355;-0.35355;-0.00000;,
 -0.20412;-0.40825;0.20412;,
 -0.33333;-0.33333;0.16667;,
 0.00000;-0.44721;0.22361;,
 0.20412;-0.40825;0.20412;,
 0.33333;-0.33333;0.16667;,
 -0.16667;-0.33333;0.33333;,
 -0.28868;-0.28868;0.28868;,
 0.00000;-0.35355;0.35355;,
 0.16667;-0.33333;0.33333;,
 0.28868;-0.28868;0.28868;,
 -0.20412;-0.20412;0.40825;,
 -0.33333;-0.16667;0.33333;,
 0.00000;-0.22361;0.44721;,
 0.20412;-0.20412;0.40825;,
 0.33333;-0.16667;0.33333;,
 -0.22361;0.00000;0.44721;,
 -0.35355;0.00000;0.35355;,
 0.00000;0.00000;0.50000;,
 0.22361;0.00000;0.44721;,
 0.35355;0.00000;0.35355;,
 -0.20412;0.20412;0.40825;,
 -0.33333;0.16667;0.33333;,
 0.00000;0.22361;0.44721;,
 0.20412;0.20412;0.40825;,
 0.33333;0.16667;0.33333;,
 0.40825;0.20412;0.20412;,
 0.44721;0.00000;0.22361;,
 0.40825;-0.20412;0.20412;,
 0.44721;0.22361;0.00000;,
 0.50000;0.00000;0.00000;,
 0.44721;-0.22361;-0.00000;,
 0.40825;0.20412;-0.20412;,
 0.44721;0.00000;-0.22361;,
 0.40825;-0.20412;-0.20412;,
 -0.40825;-0.20412;0.20412;,
 -0.44721;0.00000;0.22361;,
 -0.40825;0.20412;0.20412;,
 -0.44721;-0.22361;0.00000;,
 -0.50000;0.00000;0.00000;,
 -0.44721;0.22361;0.00000;,
 -0.40825;-0.20412;-0.20412;,
 -0.44721;0.00000;-0.22361;,
 -0.40825;0.20412;-0.20412;;
 
 96;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;3,2,10,11;,
 4;2,5,12,10;,
 4;5,7,13,12;,
 4;7,9,14,13;,
 4;11,10,15,16;,
 4;10,12,17,15;,
 4;12,13,18,17;,
 4;13,14,19,20;,
 4;16,15,21,22;,
 4;15,17,23,21;,
 4;24,20,25,26;,
 4;20,19,27,25;,
 4;22,21,28,29;,
 4;21,23,30,28;,
 4;26,25,31,32;,
 4;25,27,33,31;,
 4;29,28,34,35;,
 4;28,30,36,34;,
 4;32,31,37,38;,
 4;31,33,39,37;,
 4;35,34,40,41;,
 4;34,36,42,40;,
 4;38,37,43,44;,
 4;37,39,45,43;,
 4;41,40,46,47;,
 4;40,42,48,46;,
 4;44,43,49,50;,
 4;43,45,51,49;,
 4;47,46,52,53;,
 4;46,48,54,52;,
 4;50,49,55,56;,
 4;49,51,57,55;,
 4;53,52,58,59;,
 4;52,54,60,58;,
 4;56,55,61,62;,
 4;55,57,63,61;,
 4;59,58,64,65;,
 4;58,60,66,64;,
 4;60,61,67,66;,
 4;61,63,68,67;,
 4;65,64,69,70;,
 4;64,66,71,69;,
 4;66,67,72,71;,
 4;67,68,73,72;,
 4;70,69,74,75;,
 4;69,71,76,74;,
 4;71,72,77,76;,
 4;72,73,78,77;,
 4;75,74,79,80;,
 4;74,76,81,79;,
 4;76,77,82,81;,
 4;77,78,83,82;,
 4;80,79,84,85;,
 4;79,81,86,84;,
 4;81,82,87,86;,
 4;82,83,88,87;,
 4;85,84,1,0;,
 4;84,86,4,1;,
 4;86,87,6,4;,
 4;87,88,8,6;,
 4;8,88,89,9;,
 4;88,83,90,89;,
 4;83,78,91,90;,
 4;78,73,68,91;,
 4;9,89,92,14;,
 4;89,90,93,92;,
 4;90,91,94,93;,
 4;91,68,63,94;,
 4;14,92,95,19;,
 4;92,93,96,95;,
 4;93,94,97,96;,
 4;94,63,57,97;,
 4;19,95,33,27;,
 4;95,96,39,33;,
 4;96,97,45,39;,
 4;97,57,51,45;,
 4;70,75,98,65;,
 4;75,80,99,98;,
 4;80,85,100,99;,
 4;85,0,3,100;,
 4;65,98,101,59;,
 4;98,99,102,101;,
 4;99,100,103,102;,
 4;100,3,11,103;,
 4;59,101,104,53;,
 4;101,102,105,104;,
 4;102,103,106,105;,
 4;103,11,16,106;,
 4;53,104,41,47;,
 4;104,105,35,41;,
 4;105,106,29,35;,
 4;106,16,22,29;;
 
 MeshMaterialList {
  1;
  96;
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
  98;
  -0.577350;0.577350;0.577350;,
  -0.353390;0.661481;0.661481;,
  0.000000;0.707107;0.707107;,
  0.353390;0.661481;0.661481;,
  0.577350;0.577350;0.577350;,
  -0.661481;0.661481;0.353390;,
  -0.376252;0.846681;0.376252;,
  0.000000;0.916358;0.400361;,
  0.376252;0.846681;0.376252;,
  0.661481;0.661481;0.353390;,
  -0.707107;0.707107;0.000000;,
  -0.400361;0.916358;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.400361;0.916358;-0.000000;,
  0.707107;0.707107;0.000000;,
  -0.661481;0.661481;-0.353390;,
  -0.376252;0.846681;-0.376252;,
  0.000000;0.916358;-0.400361;,
  0.376252;0.846681;-0.376252;,
  0.661481;0.661481;-0.353390;,
  -0.577350;0.577350;-0.577350;,
  -0.353390;0.661481;-0.661481;,
  0.000000;0.707107;-0.707107;,
  0.353390;0.661481;-0.661481;,
  0.577350;0.577350;-0.577350;,
  -0.661481;0.353390;-0.661481;,
  -0.376252;0.376252;-0.846681;,
  0.000000;0.400361;-0.916358;,
  0.376252;0.376252;-0.846681;,
  0.661481;0.353390;-0.661481;,
  -0.707107;0.000000;-0.707107;,
  -0.400361;-0.000000;-0.916358;,
  0.000000;0.000000;-1.000000;,
  0.400361;-0.000000;-0.916358;,
  0.707107;0.000000;-0.707107;,
  -0.661481;-0.353390;-0.661481;,
  -0.376252;-0.376252;-0.846681;,
  0.000000;-0.400361;-0.916358;,
  0.376252;-0.376252;-0.846681;,
  0.661481;-0.353390;-0.661481;,
  -0.577350;-0.577350;-0.577350;,
  -0.353390;-0.661481;-0.661481;,
  0.000000;-0.707107;-0.707107;,
  0.353390;-0.661481;-0.661481;,
  0.577350;-0.577350;-0.577350;,
  -0.661481;-0.661481;-0.353390;,
  -0.376252;-0.846681;-0.376252;,
  0.000000;-0.916358;-0.400361;,
  0.376252;-0.846681;-0.376252;,
  0.661481;-0.661481;-0.353390;,
  -0.707107;-0.707107;0.000000;,
  -0.400361;-0.916358;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.400361;-0.916358;0.000000;,
  0.707107;-0.707107;-0.000000;,
  -0.661481;-0.661481;0.353390;,
  -0.376252;-0.846681;0.376252;,
  0.000000;-0.916358;0.400361;,
  0.376252;-0.846681;0.376252;,
  0.661481;-0.661481;0.353390;,
  -0.577350;-0.577350;0.577350;,
  -0.353390;-0.661481;0.661481;,
  0.000000;-0.707107;0.707107;,
  0.353390;-0.661481;0.661481;,
  0.577350;-0.577350;0.577350;,
  -0.661481;-0.353390;0.661481;,
  -0.376252;-0.376252;0.846681;,
  0.000000;-0.400361;0.916358;,
  0.376252;-0.376252;0.846681;,
  0.661481;-0.353390;0.661481;,
  -0.707107;0.000000;0.707107;,
  -0.400361;0.000000;0.916358;,
  0.000000;0.000000;1.000000;,
  0.400361;0.000000;0.916358;,
  0.707107;0.000000;0.707107;,
  -0.661481;0.353390;0.661481;,
  -0.376252;0.376252;0.846681;,
  0.000000;0.400361;0.916358;,
  0.376252;0.376252;0.846681;,
  0.661481;0.353390;0.661481;,
  0.846681;0.376252;0.376252;,
  0.916358;0.000000;0.400361;,
  0.846681;-0.376252;0.376252;,
  0.916358;0.400361;-0.000000;,
  1.000000;0.000000;0.000000;,
  0.916358;-0.400361;-0.000000;,
  0.846681;0.376252;-0.376252;,
  0.916358;0.000000;-0.400361;,
  0.846681;-0.376252;-0.376252;,
  -0.846681;-0.376252;0.376252;,
  -0.916358;0.000000;0.400361;,
  -0.846681;0.376252;0.376252;,
  -0.916358;-0.400361;-0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.916358;0.400361;-0.000000;,
  -0.846681;-0.376252;-0.376252;,
  -0.916358;0.000000;-0.400361;,
  -0.846681;0.376252;-0.376252;;
  96;
  4;0,1,6,5;,
  4;1,2,7,6;,
  4;2,3,8,7;,
  4;3,4,9,8;,
  4;5,6,11,10;,
  4;6,7,12,11;,
  4;7,8,13,12;,
  4;8,9,14,13;,
  4;10,11,16,15;,
  4;11,12,17,16;,
  4;12,13,18,17;,
  4;13,14,19,18;,
  4;15,16,21,20;,
  4;16,17,22,21;,
  4;17,18,23,22;,
  4;18,19,24,23;,
  4;20,21,26,25;,
  4;21,22,27,26;,
  4;22,23,28,27;,
  4;23,24,29,28;,
  4;25,26,31,30;,
  4;26,27,32,31;,
  4;27,28,33,32;,
  4;28,29,34,33;,
  4;30,31,36,35;,
  4;31,32,37,36;,
  4;32,33,38,37;,
  4;33,34,39,38;,
  4;35,36,41,40;,
  4;36,37,42,41;,
  4;37,38,43,42;,
  4;38,39,44,43;,
  4;40,41,46,45;,
  4;41,42,47,46;,
  4;42,43,48,47;,
  4;43,44,49,48;,
  4;45,46,51,50;,
  4;46,47,52,51;,
  4;47,48,53,52;,
  4;48,49,54,53;,
  4;50,51,56,55;,
  4;51,52,57,56;,
  4;52,53,58,57;,
  4;53,54,59,58;,
  4;55,56,61,60;,
  4;56,57,62,61;,
  4;57,58,63,62;,
  4;58,59,64,63;,
  4;60,61,66,65;,
  4;61,62,67,66;,
  4;62,63,68,67;,
  4;63,64,69,68;,
  4;65,66,71,70;,
  4;66,67,72,71;,
  4;67,68,73,72;,
  4;68,69,74,73;,
  4;70,71,76,75;,
  4;71,72,77,76;,
  4;72,73,78,77;,
  4;73,74,79,78;,
  4;75,76,1,0;,
  4;76,77,2,1;,
  4;77,78,3,2;,
  4;78,79,4,3;,
  4;4,79,80,9;,
  4;79,74,81,80;,
  4;74,69,82,81;,
  4;69,64,59,82;,
  4;9,80,83,14;,
  4;80,81,84,83;,
  4;81,82,85,84;,
  4;82,59,54,85;,
  4;14,83,86,19;,
  4;83,84,87,86;,
  4;84,85,88,87;,
  4;85,54,49,88;,
  4;19,86,29,24;,
  4;86,87,34,29;,
  4;87,88,39,34;,
  4;88,49,44,39;,
  4;60,65,89,55;,
  4;65,70,90,89;,
  4;70,75,91,90;,
  4;75,0,5,91;,
  4;55,89,92,50;,
  4;89,90,93,92;,
  4;90,91,94,93;,
  4;91,5,10,94;,
  4;50,92,95,45;,
  4;92,93,96,95;,
  4;93,94,97,96;,
  4;94,10,15,97;,
  4;45,95,35,40;,
  4;95,96,30,35;,
  4;96,97,25,30;,
  4;97,15,20,25;;
 }
 MeshTextureCoords {
  107;
  0.625000;0.304087;
  0.573792;0.267720;
  0.625000;0.195913;
  0.676208;0.267720;
  0.500000;0.250000;
  0.500000;0.147584;
  0.426208;0.267720;
  0.375000;0.195913;
  0.375000;0.304087;
  0.323792;0.267720;
  0.750000;0.147584;
  0.750000;0.250000;
  0.750000;0.000000;
  0.250000;0.147584;
  0.250000;0.250000;
  0.875000;0.195913;
  0.823792;0.267720;
  1.000000;0.147584;
  1.125000;0.195913;
  0.176208;0.267720;
  0.125000;0.195913;
  0.926208;0.267720;
  0.875000;0.304087;
  1.000000;0.250000;
  0.000000;0.147584;
  0.073792;0.267720;
  0.000000;0.250000;
  0.125000;0.304087;
  0.926208;0.366140;
  0.875000;0.391827;
  1.000000;0.352416;
  0.073792;0.366140;
  0.000000;0.352416;
  0.125000;0.391827;
  0.926208;0.500000;
  0.875000;0.500000;
  1.000000;0.500000;
  0.073792;0.500000;
  0.000000;0.500000;
  0.125000;0.500000;
  0.926208;0.633860;
  0.875000;0.608173;
  1.000000;0.647584;
  0.073792;0.633860;
  0.000000;0.647584;
  0.125000;0.608173;
  0.926208;0.732280;
  0.875000;0.695913;
  1.000000;0.750000;
  0.073792;0.732280;
  0.000000;0.750000;
  0.125000;0.695913;
  0.875000;0.804087;
  0.823792;0.732280;
  1.000000;0.852416;
  0.125000;0.804087;
  0.000000;0.852416;
  0.176208;0.732280;
  0.750000;0.852416;
  0.750000;0.750000;
  0.750000;1.000000;
  0.250000;0.852416;
  -0.250000;1.000000;
  0.250000;0.750000;
  0.625000;0.804087;
  0.676208;0.732280;
  0.500000;0.852416;
  0.375000;0.804087;
  0.323792;0.732280;
  0.573792;0.732280;
  0.625000;0.695913;
  0.500000;0.750000;
  0.426208;0.732280;
  0.375000;0.695913;
  0.573792;0.633860;
  0.625000;0.608173;
  0.500000;0.647584;
  0.426208;0.633860;
  0.375000;0.608173;
  0.573792;0.500000;
  0.625000;0.500000;
  0.500000;0.500000;
  0.426208;0.500000;
  0.375000;0.500000;
  0.573792;0.366140;
  0.625000;0.391827;
  0.500000;0.352416;
  0.426208;0.366140;
  0.375000;0.391827;
  0.323792;0.366140;
  0.323792;0.500000;
  0.323792;0.633860;
  0.250000;0.352416;
  0.250000;0.500000;
  0.250000;0.647584;
  0.176208;0.366140;
  0.176208;0.500000;
  0.176208;0.633860;
  0.676208;0.633860;
  0.676208;0.500000;
  0.676208;0.366140;
  0.750000;0.647584;
  0.750000;0.500000;
  0.750000;0.352416;
  0.823792;0.633860;
  0.823792;0.500000;
  0.823792;0.366140;;
 }
}
