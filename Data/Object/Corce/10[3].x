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
 144;
 -30.02350;-203.55321;352.18991;,
 18.23100;-203.55321;352.18991;,
 18.23100;-203.55321;303.93561;,
 -30.02350;-203.55321;303.93561;,
 -30.02350;-203.55321;303.93561;,
 18.23100;-203.55321;303.93561;,
 18.23100;-324.49039;303.93561;,
 -30.02350;-324.49039;303.93561;,
 -30.02350;-324.49039;352.18991;,
 18.23100;-324.49039;352.18991;,
 18.23100;-203.55321;352.18991;,
 -30.02350;-203.55321;352.18991;,
 18.23100;-203.55321;352.18991;,
 18.23100;-324.49039;352.18991;,
 18.23100;-324.49039;303.93561;,
 18.23100;-203.55321;303.93561;,
 -30.02350;-324.49039;352.18991;,
 -30.02350;-203.55321;352.18991;,
 -30.02350;-203.55321;303.93561;,
 -30.02350;-324.49039;303.93561;,
 18.23100;-373.08310;303.93561;,
 -30.02350;-373.08310;303.93561;,
 -30.02350;-373.08310;352.18991;,
 18.23100;-373.08310;352.18991;,
 -30.02350;-373.08310;303.93561;,
 -30.02350;-373.08310;352.18991;,
 -30.02350;-373.08310;303.93561;,
 18.23100;-373.08310;303.93561;,
 18.23100;-373.08310;352.18991;,
 -30.02350;-373.08310;352.18991;,
 114.77740;-373.08310;303.93561;,
 114.77740;-373.08310;352.18991;,
 114.77740;-324.49039;303.93561;,
 114.77740;-373.08310;303.93561;,
 114.77740;-324.49039;352.18991;,
 114.77740;-324.49039;303.93561;,
 18.23100;-324.49039;303.93561;,
 18.23100;-324.49039;352.18991;,
 114.77740;-373.08310;352.18991;,
 114.77740;-324.49039;352.18991;,
 162.89590;-373.08310;303.93561;,
 162.89590;-373.08310;352.18991;,
 162.89590;-324.49039;303.93561;,
 162.89590;-373.08310;303.93561;,
 162.89590;-324.49039;352.18991;,
 162.89590;-324.49039;303.93561;,
 162.89590;-373.08310;352.18991;,
 162.89590;-373.08310;303.93561;,
 162.89590;-324.49039;303.93561;,
 162.89590;-324.49039;352.18991;,
 162.89590;-324.49039;460.69910;,
 162.89590;-373.08310;460.69910;,
 114.77740;-324.49039;460.69910;,
 162.89590;-324.49039;460.69910;,
 114.77740;-373.08310;460.69910;,
 114.77740;-324.49039;460.69910;,
 114.77740;-324.49039;352.18991;,
 114.77740;-373.08310;352.18991;,
 162.89590;-373.08310;460.69910;,
 114.77740;-373.08310;460.69910;,
 162.89590;-324.49039;509.44421;,
 162.89590;-373.08310;509.44421;,
 114.77740;-373.08310;509.44421;,
 114.77740;-324.49039;509.44421;,
 162.89590;-373.08310;509.44421;,
 114.77740;-373.08310;509.44421;,
 162.89590;-373.08310;509.44421;,
 162.89590;-324.49039;509.44421;,
 114.77740;-324.49039;509.44421;,
 114.77740;-373.08310;509.44421;,
 162.89590;-252.26041;509.44421;,
 114.77740;-252.26041;509.44421;,
 162.89590;-252.26041;460.69910;,
 162.89590;-252.26041;509.44421;,
 114.77740;-252.26041;460.69910;,
 162.89590;-252.26041;460.69910;,
 162.89590;-324.49039;460.69910;,
 114.77740;-324.49039;460.69910;,
 114.77740;-252.26041;509.44421;,
 114.77740;-252.26041;460.69910;,
 162.89590;-203.26430;460.69910;,
 162.89590;-203.26430;509.44421;,
 114.77740;-203.26430;460.69910;,
 162.89590;-203.26430;460.69910;,
 114.77740;-203.26430;509.44421;,
 114.77740;-203.26430;460.69910;,
 114.77740;-203.26430;509.44421;,
 162.89590;-203.26430;509.44421;,
 162.89590;-203.26430;460.69910;,
 114.77740;-203.26430;460.69910;,
 114.77740;-203.26430;605.41138;,
 162.89590;-203.26430;605.41138;,
 114.77740;-252.26041;605.41138;,
 114.77740;-203.26430;605.41138;,
 162.89590;-252.26041;605.41138;,
 114.77740;-252.26041;605.41138;,
 114.77740;-252.26041;509.44421;,
 162.89590;-252.26041;509.44421;,
 162.89590;-203.26430;605.41138;,
 162.89590;-252.26041;605.41138;,
 114.77740;-203.26430;654.00769;,
 162.89590;-203.26430;654.00769;,
 114.77740;-252.26041;654.00769;,
 114.77740;-203.26430;654.00769;,
 162.89590;-252.26041;654.00769;,
 114.77740;-252.26041;654.00769;,
 162.89590;-203.26430;654.00769;,
 114.77740;-203.26430;654.00769;,
 114.77740;-252.26041;654.00769;,
 162.89590;-252.26041;654.00769;,
 259.83560;-252.26041;654.00769;,
 259.83560;-203.26430;654.00769;,
 259.83560;-252.26041;605.41138;,
 259.83560;-252.26041;654.00769;,
 259.83560;-203.26430;605.41138;,
 259.83560;-252.26041;605.41138;,
 162.89590;-252.26041;605.41138;,
 162.89590;-203.26430;605.41138;,
 259.83560;-203.26430;654.00769;,
 259.83560;-203.26430;605.41138;,
 307.81671;-252.26041;654.00769;,
 307.81671;-203.26430;654.00769;,
 307.81671;-252.26041;605.41138;,
 307.81671;-252.26041;654.00769;,
 307.81671;-203.26430;605.41138;,
 307.81671;-252.26041;605.41138;,
 307.81671;-203.26430;654.00769;,
 307.81671;-252.26041;654.00769;,
 307.81671;-252.26041;605.41138;,
 307.81671;-203.26430;605.41138;,
 307.81671;-70.23370;605.41138;,
 307.81671;-70.23370;654.00769;,
 259.83560;-70.23370;605.41138;,
 307.81671;-70.23370;605.41138;,
 259.83560;-70.23370;654.00769;,
 259.83560;-70.23370;605.41138;,
 259.83560;-203.26430;605.41138;,
 259.83560;-203.26430;654.00769;,
 307.81671;-70.23370;654.00769;,
 259.83560;-70.23370;654.00769;,
 307.81671;-70.23370;654.00769;,
 307.81671;-70.23370;605.41138;,
 259.83560;-70.23370;605.41138;,
 259.83560;-70.23370;654.00769;;
 
 54;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,7,6;,
 4;22,23,9,8;,
 4;24,25,16,19;,
 4;26,27,28,29;,
 4;30,31,28,27;,
 4;32,33,20,6;,
 4;34,35,36,37;,
 4;38,39,9,23;,
 4;40,41,31,30;,
 4;42,43,33,32;,
 4;44,45,35,34;,
 4;46,47,48,49;,
 4;50,51,46,49;,
 4;52,53,44,34;,
 4;54,55,56,57;,
 4;58,59,31,41;,
 4;60,61,51,50;,
 4;62,63,55,54;,
 4;64,65,59,58;,
 4;66,67,68,69;,
 4;70,71,68,67;,
 4;72,73,60,50;,
 4;74,75,76,77;,
 4;78,79,55,63;,
 4;80,81,73,72;,
 4;82,83,75,74;,
 4;84,85,79,78;,
 4;86,87,88,89;,
 4;90,91,87,86;,
 4;92,93,84,78;,
 4;94,95,96,97;,
 4;98,99,73,81;,
 4;100,101,91,90;,
 4;102,103,93,92;,
 4;104,105,95,94;,
 4;106,107,108,109;,
 4;110,111,106,109;,
 4;112,113,104,94;,
 4;114,115,116,117;,
 4;118,119,91,101;,
 4;120,121,111,110;,
 4;122,123,113,112;,
 4;124,125,115,114;,
 4;126,127,128,129;,
 4;130,131,126,129;,
 4;132,133,124,114;,
 4;134,135,136,137;,
 4;138,139,111,121;,
 4;140,141,142,143;;
 
 MeshMaterialList {
  6;
  54;
  4,
  4,
  5,
  4,
  4,
  4,
  5,
  4,
  4,
  4,
  4,
  4,
  5,
  4,
  4,
  4,
  4,
  4,
  4,
  5,
  4,
  4,
  5,
  4,
  4,
  4,
  4,
  5,
  5,
  4,
  5,
  5,
  4,
  4,
  4,
  5,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  5,
  4,
  4,
  4,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "Izigen.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "�w�i2.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "Izigen.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.984314;0.968627;1.000000;;
   TextureFilename {
    "Gurabi.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "Izigen.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.984000;0.969000;1.000000;;
   TextureFilename {
    "Gurabi.bmp";
   }
  }
 }
 MeshNormals {
  6;
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;;
  54;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;0,0,0,0;;
 }
 MeshTextureCoords {
  144;
  -19.985220;21.980659;
  -15.988980;21.980659;
  -15.988980;25.976879;
  -19.985220;25.976879;
  -9.007370;-2.997980;
  -5.011140;-2.997980;
  -5.011140;7.017530;
  -9.007370;7.017530;
  -9.007370;7.017530;
  -5.011140;7.017530;
  -5.011140;-2.997980;
  -9.007370;-2.997980;
  -18.991920;0.979000;
  -18.991920;10.994500;
  -22.988140;10.994500;
  -22.988140;0.979000;
  -18.991920;10.994500;
  -18.991920;0.979000;
  -22.988140;0.979000;
  -22.988140;10.994500;
  -5.011140;11.041780;
  -9.007370;11.041780;
  -9.007370;11.041780;
  -5.011140;11.041780;
  -22.988140;15.018750;
  -18.991920;15.018750;
  -19.985220;25.976879;
  -15.988980;25.976879;
  -15.988980;21.980659;
  -19.985220;21.980659;
  -7.993410;25.976879;
  -7.993410;21.980659;
  2.984440;7.017530;
  2.984440;11.041780;
  -7.993410;21.980659;
  -7.993410;25.976879;
  -15.988980;25.976879;
  -15.988980;21.980659;
  2.984440;11.041780;
  2.984440;7.017530;
  -4.008440;25.976879;
  -4.008440;21.980659;
  6.969400;7.017530;
  6.969400;11.041780;
  -4.008440;21.980659;
  -4.008440;25.976879;
  -18.991920;15.018750;
  -22.988140;15.018750;
  -22.988140;10.994500;
  -18.991920;10.994500;
  -10.005640;10.994500;
  -10.005640;15.018750;
  -7.993410;12.994380;
  -4.008440;12.994380;
  -10.005640;15.018750;
  -10.005640;10.994500;
  -18.991920;10.994500;
  -18.991920;15.018750;
  -4.008440;12.994380;
  -7.993410;12.994380;
  -5.968770;10.994500;
  -5.968770;15.018750;
  -5.968770;15.018750;
  -5.968770;10.994500;
  -4.008440;8.957510;
  -7.993410;8.957510;
  6.969400;11.041780;
  6.969400;7.017530;
  2.984440;7.017530;
  2.984440;11.041780;
  6.969400;1.035750;
  2.984440;1.035750;
  -10.005640;5.012720;
  -5.968770;5.012720;
  2.984440;1.035750;
  6.969400;1.035750;
  6.969400;7.017530;
  2.984440;7.017530;
  -5.968770;5.012720;
  -10.005640;5.012720;
  -10.005640;0.955070;
  -5.968770;0.955070;
  2.984440;-3.021910;
  6.969400;-3.021910;
  -5.968770;0.955070;
  -10.005640;0.955070;
  -7.993410;8.957510;
  -4.008440;8.957510;
  -4.008440;12.994380;
  -7.993410;12.994380;
  -7.993410;1.009910;
  -4.008440;1.009910;
  1.978830;5.012720;
  1.978830;0.955070;
  -4.008440;1.009910;
  -7.993410;1.009910;
  -7.993410;8.957510;
  -4.008440;8.957510;
  1.978830;0.955070;
  1.978830;5.012720;
  -7.993410;-3.014630;
  -4.008440;-3.014630;
  6.003370;5.012720;
  6.003370;0.955070;
  -4.008440;-3.014630;
  -7.993410;-3.014630;
  6.969400;-3.021910;
  2.984440;-3.021910;
  2.984440;1.035750;
  6.969400;1.035750;
  14.997550;1.035750;
  14.997550;-3.021910;
  4.019700;1.009910;
  4.019700;-3.014630;
  14.997550;-3.021910;
  14.997550;1.035750;
  6.969400;1.035750;
  6.969400;-3.021910;
  4.019700;-3.014630;
  4.019700;1.009910;
  18.971140;1.035750;
  18.971140;-3.021910;
  7.993300;1.009910;
  7.993300;-3.014630;
  18.971140;-3.021910;
  18.971140;1.035750;
  10.019760;2.953310;
  10.019760;6.990160;
  6.015850;6.990160;
  6.015850;2.953310;
  6.015850;-8.007250;
  10.019760;-8.007250;
  14.997550;-14.038940;
  18.971140;-14.038940;
  6.003370;-10.061960;
  1.978830;-10.061960;
  1.978830;0.955070;
  6.003370;0.955070;
  18.971140;-14.038940;
  14.997550;-14.038940;
  7.993300;-3.014630;
  7.993300;1.009910;
  4.019700;1.009910;
  4.019700;-3.014630;;
 }
}