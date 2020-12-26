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
 60;
 0.00000;0.54758;0.00000;,
 0.02643;0.42088;-0.02643;,
 0.00000;0.42088;-0.03737;,
 0.03737;0.42088;0.00000;,
 0.02643;0.42088;0.02643;,
 0.00000;0.42088;0.03737;,
 -0.02643;0.42088;0.02643;,
 -0.03737;0.42088;0.00000;,
 -0.02643;0.42088;-0.02643;,
 0.00000;-0.00179;-0.00000;,
 0.00000;-0.00179;-1.03553;,
 0.73223;-0.00179;-0.73223;,
 1.03553;-0.00179;0.00000;,
 0.73223;-0.00179;0.73223;,
 -0.00000;-0.00179;1.03553;,
 -0.73223;-0.00179;0.73223;,
 -1.03553;-0.00179;0.00000;,
 -0.73223;-0.00179;-0.73223;,
 0.06112;0.32214;-0.06112;,
 0.00000;0.32214;-0.08644;,
 0.00000;0.42088;-0.03737;,
 0.02643;0.42088;-0.02643;,
 0.08644;0.32214;0.00000;,
 0.06112;0.32214;0.06112;,
 0.00000;0.32214;0.08644;,
 -0.06112;0.32214;0.06112;,
 -0.08644;0.32214;0.00000;,
 -0.06112;0.32214;-0.06112;,
 -0.06112;0.32214;-0.06112;,
 -0.02643;0.42088;-0.02643;,
 0.12984;0.20046;-0.12984;,
 0.00000;0.20046;-0.18363;,
 0.18363;0.20046;0.00000;,
 0.12984;0.20046;0.12984;,
 0.00000;0.20046;0.18363;,
 -0.12984;0.20046;0.12984;,
 -0.18363;0.20046;0.00000;,
 -0.12984;0.20046;-0.12984;,
 -0.12984;0.20046;-0.12984;,
 0.24274;0.11524;-0.24274;,
 0.00000;0.11524;-0.34329;,
 0.34329;0.11524;0.00000;,
 0.24274;0.11524;0.24274;,
 0.00000;0.11524;0.34329;,
 -0.24274;0.11524;0.24274;,
 -0.34329;0.11524;0.00000;,
 -0.24274;0.11524;-0.24274;,
 -0.24274;0.11524;-0.24274;,
 0.38418;0.06119;-0.38418;,
 0.73223;-0.00179;-0.73223;,
 0.00000;-0.00179;-1.03553;,
 0.00000;0.06119;-0.54331;,
 0.54331;0.06119;0.00000;,
 0.38418;0.06119;0.38418;,
 0.00000;0.06119;0.54331;,
 -0.38418;0.06119;0.38418;,
 -0.54331;0.06119;0.00000;,
 -0.38418;0.06119;-0.38418;,
 -0.73223;-0.00179;-0.73223;,
 -0.38418;0.06119;-0.38418;;
 
 56;
 3;0,1,2;,
 3;0,3,1;,
 3;0,4,3;,
 3;0,5,4;,
 3;0,6,5;,
 3;0,7,6;,
 3;0,8,7;,
 3;0,2,8;,
 3;9,10,11;,
 3;9,11,12;,
 3;9,12,13;,
 3;9,13,14;,
 3;9,14,15;,
 3;9,15,16;,
 3;9,16,17;,
 3;9,17,10;,
 4;18,19,20,21;,
 4;22,18,21,3;,
 4;23,22,3,4;,
 4;24,23,4,5;,
 4;25,24,5,6;,
 4;26,25,6,7;,
 4;27,26,7,8;,
 4;19,28,29,20;,
 4;30,31,19,18;,
 4;32,30,18,22;,
 4;33,32,22,23;,
 4;34,33,23,24;,
 4;35,34,24,25;,
 4;36,35,25,26;,
 4;37,36,26,27;,
 4;31,38,28,19;,
 4;39,40,31,30;,
 4;41,39,30,32;,
 4;42,41,32,33;,
 4;43,42,33,34;,
 4;44,43,34,35;,
 4;45,44,35,36;,
 4;46,45,36,37;,
 4;40,47,38,31;,
 4;48,49,50,51;,
 4;48,51,40,39;,
 4;52,12,49,48;,
 4;52,48,39,41;,
 4;53,13,12,52;,
 4;53,52,41,42;,
 4;54,14,13,53;,
 4;54,53,42,43;,
 4;55,15,14,54;,
 4;55,54,43,44;,
 4;56,16,15,55;,
 4;56,55,44,45;,
 4;57,17,16,56;,
 4;57,56,45,46;,
 4;51,50,58,59;,
 4;51,59,47,40;;
 
 MeshMaterialList {
  2;
  56;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.984000;0.984000;;
   TextureFilename {
    "Wind4.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  53;
  0.678217;0.282922;-0.678217;,
  0.000000;0.365718;-0.930726;,
  0.658124;0.365714;-0.658123;,
  0.930726;0.365718;0.000000;,
  0.658123;0.365714;0.658124;,
  0.000000;0.365718;0.930726;,
  -0.658124;0.365714;0.658123;,
  -0.930726;0.365718;0.000000;,
  -0.658123;0.365714;-0.658124;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.538243;-0.842790;,
  0.595943;0.538242;-0.595943;,
  0.842790;0.538243;0.000000;,
  0.595943;0.538242;0.595943;,
  0.000000;0.538243;0.842790;,
  -0.595943;0.538242;0.595943;,
  -0.842790;0.538243;0.000000;,
  -0.595943;0.538242;-0.595943;,
  0.000000;0.771017;-0.636814;,
  0.450296;0.771017;-0.450296;,
  0.636814;0.771017;0.000000;,
  0.450296;0.771017;0.450296;,
  0.000000;0.771017;0.636814;,
  -0.450296;0.771017;0.450296;,
  -0.636814;0.771017;0.000000;,
  -0.450296;0.771017;-0.450296;,
  0.000000;0.930007;-0.367542;,
  0.259892;0.930007;-0.259892;,
  0.367542;0.930007;0.000000;,
  0.259892;0.930007;0.259892;,
  0.000000;0.930007;0.367542;,
  -0.259892;0.930007;0.259892;,
  -0.367542;0.930007;0.000000;,
  -0.259892;0.930007;-0.259892;,
  0.000000;0.980963;-0.194195;,
  0.137317;0.980963;-0.137317;,
  0.194195;0.980963;0.000000;,
  0.137317;0.980963;0.137317;,
  0.000000;0.980963;0.194195;,
  -0.137317;0.980963;0.137317;,
  -0.194196;0.980963;-0.000000;,
  -0.137317;0.980963;-0.137317;,
  0.678217;0.282922;0.678217;,
  -0.678217;0.282922;0.678217;,
  -0.678217;0.282922;-0.678217;,
  0.089751;0.991912;-0.089751;,
  0.000000;0.991912;-0.126927;,
  0.126927;0.991912;0.000000;,
  0.089751;0.991912;0.089751;,
  0.000000;0.991912;0.126927;,
  -0.089751;0.991912;0.089751;,
  -0.126927;0.991912;0.000000;,
  -0.089751;0.991912;-0.089751;;
  56;
  3;0,2,1;,
  3;0,3,2;,
  3;42,4,3;,
  3;42,5,4;,
  3;43,6,5;,
  3;43,7,6;,
  3;44,8,7;,
  3;44,1,8;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  4;11,10,1,2;,
  4;12,11,2,3;,
  4;13,12,3,4;,
  4;14,13,4,5;,
  4;15,14,5,6;,
  4;16,15,6,7;,
  4;17,16,7,8;,
  4;10,17,8,1;,
  4;19,18,10,11;,
  4;20,19,11,12;,
  4;21,20,12,13;,
  4;22,21,13,14;,
  4;23,22,14,15;,
  4;24,23,15,16;,
  4;25,24,16,17;,
  4;18,25,17,10;,
  4;27,26,18,19;,
  4;28,27,19,20;,
  4;29,28,20,21;,
  4;30,29,21,22;,
  4;31,30,22,23;,
  4;32,31,23,24;,
  4;33,32,24,25;,
  4;26,33,25,18;,
  4;35,45,46,34;,
  4;35,34,26,27;,
  4;36,47,45,35;,
  4;36,35,27,28;,
  4;37,48,47,36;,
  4;37,36,28,29;,
  4;38,49,48,37;,
  4;38,37,29,30;,
  4;39,50,49,38;,
  4;39,38,30,31;,
  4;40,51,50,39;,
  4;40,39,31,32;,
  4;41,52,51,40;,
  4;41,40,32,33;,
  4;34,46,52,41;,
  4;34,41,33,26;;
 }
 MeshTextureCoords {
  60;
  0.750000;0.042111;
  1.125000;0.236764;
  1.000000;0.236764;
  0.250000;0.236764;
  0.375000;0.236764;
  0.500000;0.236764;
  0.625000;0.236764;
  0.750000;0.236764;
  0.875000;0.236764;
  0.750000;0.886134;
  1.000000;0.886134;
  1.125000;0.886134;
  0.250000;0.886134;
  0.375000;0.886134;
  0.500000;0.886134;
  0.625000;0.886134;
  0.750000;0.886134;
  0.875000;0.886134;
  0.125000;0.388464;
  0.000000;0.388464;
  0.000000;0.236764;
  0.125000;0.236764;
  0.250000;0.388464;
  0.375000;0.388464;
  0.500000;0.388464;
  0.625000;0.388464;
  0.750000;0.388464;
  0.875000;0.388464;
  -0.125000;0.388464;
  -0.125000;0.236764;
  0.125000;0.575406;
  0.000000;0.575406;
  0.250000;0.575406;
  0.375000;0.575406;
  0.500000;0.575406;
  0.625000;0.575406;
  0.750000;0.575406;
  0.875000;0.575406;
  -0.125000;0.575406;
  0.125000;0.706333;
  0.000000;0.706333;
  0.250000;0.706333;
  0.375000;0.706333;
  0.500000;0.706333;
  0.625000;0.706333;
  0.750000;0.706333;
  0.875000;0.706333;
  -0.125000;0.706333;
  0.125000;0.789368;
  0.125000;0.886134;
  0.000000;0.886134;
  0.000000;0.789368;
  0.250000;0.789368;
  0.375000;0.789368;
  0.500000;0.789368;
  0.625000;0.789368;
  0.750000;0.789368;
  0.875000;0.789368;
  -0.125000;0.886134;
  -0.125000;0.789368;;
 }
}
