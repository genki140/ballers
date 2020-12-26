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
 118;
 0.00000;-0.29700;-0.40546;,
 0.28670;-0.29700;-0.28670;,
 0.28670;-0.35242;-0.28670;,
 0.00000;-0.35242;-0.40546;,
 0.40546;-0.29700;0.00000;,
 0.40546;-0.35242;0.00000;,
 0.28670;-0.29700;0.28670;,
 0.28670;-0.35242;0.28670;,
 -0.00000;-0.29700;0.40546;,
 -0.00000;-0.35242;0.40546;,
 -0.28670;-0.29700;0.28670;,
 -0.28670;-0.35242;0.28670;,
 -0.40546;-0.29700;0.00000;,
 -0.40546;-0.35242;0.00000;,
 -0.28670;-0.29700;-0.28670;,
 -0.28670;-0.35242;-0.28670;,
 0.00000;-0.29700;-0.40546;,
 0.00000;-0.35242;-0.40546;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.29700;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.00000;-0.35242;-0.00000;,
 0.14474;0.40395;0.02094;,
 0.28884;0.40395;0.02094;,
 0.28884;0.40395;-0.02094;,
 -0.14379;0.40395;0.02094;,
 -0.28884;0.40395;-0.02094;,
 -0.28884;0.40395;0.02094;,
 0.14474;0.40395;-0.02094;,
 -0.24233;0.35744;-0.02094;,
 -0.14379;0.40395;-0.02094;,
 0.28884;0.25958;-0.02094;,
 0.24233;0.25958;-0.02094;,
 0.24233;0.35744;-0.02094;,
 0.24233;-0.02895;-0.02094;,
 0.28884;-0.17372;-0.02094;,
 0.24233;-0.12722;-0.02094;,
 -0.14379;0.35744;-0.02094;,
 0.14474;0.35744;-0.02094;,
 0.28884;-0.17372;0.02094;,
 0.14474;-0.17372;-0.02094;,
 -0.28884;-0.17372;0.02094;,
 -0.28884;-0.02895;-0.02094;,
 -0.28884;-0.17372;-0.02094;,
 -0.28884;0.25958;-0.02094;,
 -0.24233;-0.02895;-0.02094;,
 -0.24233;-0.12722;-0.02094;,
 -0.14379;-0.12722;-0.02094;,
 -0.14379;-0.17372;-0.02094;,
 0.14474;-0.17372;0.02094;,
 0.24233;0.35744;0.02094;,
 -0.24233;-0.12722;0.02094;,
 -0.14379;-0.17372;0.02094;,
 0.28884;-0.02895;0.02094;,
 0.24233;0.25958;0.02094;,
 0.24233;-0.12722;0.02094;,
 -0.14379;-0.12722;0.02094;,
 -0.28884;0.25958;0.02094;,
 -0.24233;0.35744;0.02094;,
 -0.24233;-0.02895;0.02094;,
 0.14474;0.35744;0.02094;,
 0.28884;-0.02895;-0.02094;,
 0.28884;0.25958;0.02094;,
 -0.28884;-0.02895;0.02094;,
 -0.24233;0.25958;-0.02094;,
 0.14474;-0.12722;-0.02094;,
 0.24233;-0.02895;0.02094;,
 0.14474;-0.12722;0.02094;,
 -0.14379;0.35744;0.02094;,
 -0.24233;0.25958;0.02094;,
 -0.02340;0.13851;-0.02101;,
 0.02340;0.13851;-0.02101;,
 0.02340;0.09172;-0.02101;,
 -0.02340;0.09172;-0.02101;,
 -0.02340;0.09172;0.02101;,
 0.02340;0.09172;0.02101;,
 0.02340;0.13851;0.02101;,
 -0.02340;0.13851;0.02101;,
 0.09560;0.09172;0.02101;,
 0.09560;0.13851;0.02101;,
 0.02340;0.13851;0.02101;,
 0.09560;0.09172;-0.02101;,
 0.09560;0.13851;-0.02101;,
 0.02340;0.13851;-0.02101;,
 -0.09560;0.13851;0.02101;,
 -0.09560;0.09172;0.02101;,
 -0.02340;0.13851;0.02101;,
 -0.09560;0.13851;-0.02101;,
 -0.02340;0.13851;-0.02101;,
 -0.09560;0.09172;-0.02101;,
 0.02340;0.21072;0.02101;,
 -0.02340;0.21072;0.02101;,
 -0.02340;0.13851;0.02101;,
 0.02340;0.13851;0.02101;,
 0.02340;0.21072;-0.02101;,
 0.02340;0.13851;-0.02101;,
 -0.02340;0.21072;-0.02101;,
 -0.02340;0.13851;-0.02101;,
 0.02340;0.01951;-0.02101;,
 -0.02340;0.01951;-0.02101;,
 -0.02340;0.09172;-0.02101;,
 0.02340;0.09172;-0.02101;,
 0.02340;0.01951;0.02101;,
 0.02340;0.09172;0.02101;,
 -0.02340;0.01951;0.02101;,
 -0.02340;0.09172;0.02101;;
 
 126;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 3;18,1,0;,
 3;19,4,1;,
 3;20,6,4;,
 3;21,8,6;,
 3;22,10,8;,
 3;23,12,10;,
 3;24,14,12;,
 3;25,16,14;,
 3;26,3,2;,
 3;27,2,5;,
 3;28,5,7;,
 3;29,7,9;,
 3;30,9,11;,
 3;31,11,13;,
 3;32,13,15;,
 3;33,15,17;,
 3;34,35,36;,
 3;37,38,39;,
 3;34,36,40;,
 3;41,38,42;,
 3;35,43,36;,
 3;36,43,44;,
 3;40,36,45;,
 3;36,44,45;,
 3;46,47,48;,
 3;41,42,49;,
 3;40,45,50;,
 3;51,52,47;,
 3;48,47,52;,
 3;53,54,55;,
 3;56,38,41;,
 3;57,58,55;,
 3;55,58,59;,
 3;60,53,55;,
 3;52,51,61;,
 3;34,62,35;,
 3;63,53,64;,
 3;47,65,51;,
 3;66,35,62;,
 3;61,51,67;,
 3;51,65,67;,
 3;63,64,68;,
 3;38,69,39;,
 3;37,39,70;,
 3;39,69,70;,
 3;71,53,63;,
 3;62,34,72;,
 3;65,47,73;,
 3;43,35,74;,
 3;54,53,75;,
 3;69,38,56;,
 3;42,38,37;,
 3;73,47,46;,
 3;41,76,56;,
 3;77,48,52;,
 3;60,55,59;,
 3;57,55,54;,
 3;64,53,60;,
 3;74,35,66;,
 3;67,65,78;,
 3;79,61,67;,
 3;75,53,71;,
 3;80,37,70;,
 3;69,81,70;,
 3;34,50,72;,
 3;37,80,49;,
 3;67,78,46;,
 3;73,46,78;,
 3;70,81,76;,
 3;56,76,81;,
 3;45,44,62;,
 3;62,72,50;,
 3;62,50,45;,
 3;43,66,44;,
 3;62,44,66;,
 3;54,71,57;,
 3;58,57,71;,
 3;68,64,59;,
 3;48,77,79;,
 3;52,79,77;,
 3;40,50,34;,
 3;49,42,37;,
 3;70,41,80;,
 3;78,65,73;,
 3;81,69,56;,
 3;58,63,59;,
 3;43,74,66;,
 3;54,75,71;,
 3;41,70,76;,
 3;48,67,46;,
 3;63,58,71;,
 3;49,80,41;,
 3;68,59,63;,
 3;67,48,79;,
 3;79,52,61;,
 3;59,64,60;,
 4;82,83,84,85;,
 4;86,87,88,89;,
 4;90,91,92,87;,
 4;93,90,87,84;,
 4;94,93,84,95;,
 4;91,94,95,92;,
 4;91,90,93,94;,
 4;96,97,86,98;,
 4;99,96,98,100;,
 4;101,99,100,85;,
 4;97,101,85,86;,
 4;97,96,99,101;,
 4;102,103,104,105;,
 4;106,102,105,107;,
 4;108,106,107,109;,
 4;103,108,109,104;,
 4;103,102,106,108;,
 4;110,111,112,113;,
 4;114,110,113,115;,
 4;116,114,115,117;,
 4;111,116,117,112;,
 4;111,110,114,116;;
 
 MeshMaterialList {
  2;
  126;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.473040;0.000000;0.016200;1.000000;;
   3.000000;
   0.410000;0.410000;0.410000;;
   0.274480;0.000000;0.009400;;
  }
  Material {
   0.560000;0.560000;0.560000;1.000000;;
   2.000000;
   0.350000;0.350000;0.350000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  12;
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  126;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,1,1,8;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;0,0,0;,
  3;0,0,10;,
  3;0,0,0;,
  3;1,1,1;,
  3;3,3,3;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;9,9,9;,
  3;1,1,1;,
  3;7,7,7;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;9,9,11;,
  3;9,9,9;,
  3;5,5,5;,
  3;5,5,5;,
  3;3,3,3;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;7,7,7;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;3,3,3;,
  3;3,3,3;,
  3;7,7,7;,
  3;7,7,7;,
  3;10,0,0;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;11,9,9;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;5,5,5;,
  3;7,7,7;,
  3;3,3,3;,
  3;7,7,7;,
  3;0,0,0;,
  3;3,3,3;,
  3;9,9,9;,
  3;7,7,7;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;7,7,7;,
  3;0,0,0;,
  3;3,3,3;,
  3;3,3,3;,
  3;0,0,0;,
  3;7,7,7;,
  3;7,7,7;,
  3;3,3,3;,
  3;9,9,9;,
  3;0,0,0;,
  3;9,9,9;,
  3;0,0,0;,
  3;9,9,9;,
  3;0,0,0;,
  3;3,3,3;,
  3;7,7,7;,
  3;3,3,3;,
  3;9,9,9;,
  3;0,0,0;,
  3;0,0,0;,
  3;7,7,7;,
  3;3,3,3;,
  4;1,1,1,1;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;9,9,9,9;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;9,9,9,9;,
  4;7,7,7,7;,
  4;5,5,5,5;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;7,7,7,7;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;5,5,5,5;,
  4;7,7,7,7;,
  4;9,9,9,9;;
 }
 MeshTextureCoords {
  118;
  0.000000;0.000000;
  0.125000;0.000000;
  0.125000;1.000000;
  0.000000;1.000000;
  0.250000;0.000000;
  0.250000;1.000000;
  0.375000;0.000000;
  0.375000;1.000000;
  0.500000;0.000000;
  0.500000;1.000000;
  0.625000;0.000000;
  0.625000;1.000000;
  0.750000;0.000000;
  0.750000;1.000000;
  0.875000;0.000000;
  0.875000;1.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.062500;0.000000;
  0.187500;0.000000;
  0.312500;0.000000;
  0.437500;0.000000;
  0.562500;0.000000;
  0.687500;0.000000;
  0.812500;0.000000;
  0.937500;0.000000;
  0.062500;1.000000;
  0.187500;1.000000;
  0.312500;1.000000;
  0.437500;1.000000;
  0.562500;1.000000;
  0.687500;1.000000;
  0.812500;1.000000;
  0.937500;1.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;1.000000;;
 }
}