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
 52;
 -0.79197;0.71254;-0.04950;,
 0.90906;0.71254;-0.04950;,
 0.90906;0.71254;0.04950;,
 -0.79197;0.71254;0.04950;,
 0.97436;1.68034;-0.04950;,
 -0.89316;1.68034;-0.04950;,
 -0.97436;1.92102;-0.04950;,
 0.91453;1.92102;-0.04950;,
 -0.89316;1.68034;0.04950;,
 0.97436;1.68034;0.04950;,
 0.91453;1.92102;0.04950;,
 -0.97436;1.92102;0.04950;,
 0.92342;1.41778;-0.04950;,
 -0.93162;1.41778;-0.04950;,
 -0.93162;1.41778;0.04950;,
 0.92342;1.41778;0.04950;,
 0.91470;0.79419;-0.04950;,
 -0.88889;0.79419;-0.04950;,
 -0.88889;0.79419;0.04950;,
 0.91470;0.79419;0.04950;,
 -1.00427;2.10701;-0.04950;,
 1.00000;2.10701;-0.04950;,
 1.00000;2.10701;0.04950;,
 -1.00427;2.10701;0.04950;,
 0.83333;2.21054;-0.04950;,
 0.83333;2.21054;0.04950;,
 -0.42735;2.21054;0.04950;,
 -0.42735;2.21054;-0.04950;,
 -0.88462;1.37402;-0.04950;,
 0.86017;1.37402;-0.04950;,
 0.91453;1.13333;-0.04950;,
 -0.91026;1.13333;-0.04950;,
 0.86017;1.37402;0.04950;,
 -0.88462;1.37402;0.04950;,
 -0.91026;1.13333;0.04950;,
 0.91453;1.13333;0.04950;,
 -0.96154;1.04581;-0.04950;,
 1.00000;1.04581;-0.04950;,
 1.00000;1.04581;0.04950;,
 -0.96154;1.04581;0.04950;,
 0.33419;2.14644;0.04950;,
 0.33419;2.14644;-0.04950;,
 0.33419;2.10701;-0.04950;,
 0.33419;2.10701;0.04950;,
 -0.09900;0.71537;-0.02964;,
 0.09900;0.71537;-0.02964;,
 0.09900;0.15412;-0.02964;,
 -0.09900;0.15412;-0.02964;,
 -0.09900;0.15412;0.02964;,
 0.09900;0.15412;0.02964;,
 0.09900;0.71537;0.02964;,
 -0.09900;0.71537;0.02964;;
 
 45;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;9,4,7,10;,
 4;5,8,11,6;,
 4;12,13,5,4;,
 4;14,15,9,8;,
 4;15,12,4,9;,
 4;13,14,8,5;,
 4;16,1,0,17;,
 4;18,3,2,19;,
 4;19,2,1,16;,
 4;17,0,3,18;,
 4;20,21,7,6;,
 4;22,23,11,10;,
 4;21,24,25,22;,
 4;21,22,10,7;,
 4;23,26,27,20;,
 4;23,20,6,11;,
 4;28,13,12,29;,
 4;28,29,30,31;,
 4;32,15,14,33;,
 4;32,33,34,35;,
 4;29,12,15,32;,
 4;29,32,35,30;,
 4;33,14,13,28;,
 4;33,28,31,34;,
 4;36,31,30,37;,
 4;36,37,16,17;,
 4;38,35,34,39;,
 4;38,39,18,19;,
 4;37,30,35,38;,
 4;37,38,19,16;,
 4;39,34,31,36;,
 4;39,36,17,18;,
 4;40,25,24,41;,
 4;40,41,27,26;,
 4;41,24,21,42;,
 4;41,42,20,27;,
 4;40,26,23,43;,
 4;40,43,22,25;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;50,49,46,45;,
 4;48,51,44,47;;
 
 MeshMaterialList {
  2;
  45;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1;;
  Material {
   0.900000;0.900000;0.900000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Ki.bmp";
   }
  }
  Material {
   0.900000;0.900000;0.900000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Ki.bmp";
   }
  }
 }
 MeshNormals {
  30;
  -0.046776;0.998905;0.000000;,
  0.212430;0.977176;0.000000;,
  -0.342934;-0.939359;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.021872;0.999761;0.000000;,
  0.999662;0.026003;0.000000;,
  0.995626;-0.093430;-0.000000;,
  -0.995956;-0.089838;0.000000;,
  -0.970759;-0.240056;0.000000;,
  0.837240;-0.546836;-0.000000;,
  -0.943467;-0.331466;0.000000;,
  0.980480;-0.196618;-0.000000;,
  0.997622;-0.068924;-0.000000;,
  -0.838704;-0.544588;0.000000;,
  0.527663;0.849454;0.000000;,
  0.908643;-0.417574;-0.000000;,
  -0.176630;0.984277;0.000000;,
  -0.987311;-0.158802;0.000000;,
  0.568980;-0.822351;-0.000000;,
  0.975431;0.220303;0.000000;,
  0.878619;0.477524;0.000000;,
  -0.936769;-0.349948;0.000000;,
  -0.949839;0.312739;0.000000;,
  0.715440;0.698674;0.000000;,
  0.947063;-0.321048;-0.000000;,
  -0.992264;0.124149;0.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;;
  45;
  4;2,3,3,2;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;7,7,8,8;,
  4;9,9,10,10;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;11,11,7,7;,
  4;12,12,9,9;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;13,14,14,13;,
  4;15,2,2,15;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;16,1,1,16;,
  4;17,17,8,8;,
  4;18,0,0,18;,
  4;19,19,10,10;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;20,11,11,20;,
  4;21,21,22,22;,
  4;23,12,12,23;,
  4;23,23,24,24;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;25,22,22,25;,
  4;26,26,13,13;,
  4;27,24,24,27;,
  4;27,27,15,15;,
  4;6,1,1,6;,
  4;6,6,0,0;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;28,28,28,28;,
  4;29,29,29,29;;
 }
 MeshTextureCoords {
  52;
  0.097583;1.000001;
  0.879391;1.000001;
  0.958201;1.000001;
  0.176394;1.000001;
  0.909403;0.353937;
  0.051073;0.353937;
  0.013754;0.193268;
  0.881905;0.193268;
  0.129883;0.353937;
  0.988213;0.353937;
  0.960716;0.193268;
  0.092564;0.193268;
  0.885990;0.529214;
  0.033395;0.529214;
  0.112206;0.529214;
  0.964801;0.529214;
  0.881984;0.945495;
  0.053036;0.945495;
  0.131847;0.945495;
  0.960794;0.945495;
  0.000005;0.069113;
  0.921188;0.069113;
  0.999998;0.069113;
  0.078816;0.069113;
  0.844586;0.000001;
  0.923397;0.000001;
  0.343975;0.000001;
  0.265164;0.000001;
  0.055001;0.558427;
  0.856921;0.558427;
  0.881905;0.719097;
  0.043216;0.719097;
  0.935732;0.558427;
  0.133811;0.558427;
  0.122027;0.719097;
  0.960716;0.719097;
  0.019646;0.777522;
  0.921188;0.777522;
  0.999998;0.777522;
  0.098457;0.777522;
  0.693985;0.042793;
  0.615174;0.042793;
  0.615174;0.069113;
  0.693985;0.069113;
  -0.001150;0.018742;
  0.658850;0.018742;
  0.658850;0.691699;
  -0.001150;0.691699;
  0.341150;0.691699;
  1.001150;0.691699;
  1.001150;0.018742;
  0.341150;0.018742;;
 }
}