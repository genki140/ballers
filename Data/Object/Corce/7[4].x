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
 68;
 161.94020;-38.50170;222.68550;,
 161.94020;-47.05530;223.91530;,
 89.09270;-47.05530;223.91530;,
 89.09270;-38.50170;222.68550;,
 161.94020;-54.91590;227.50510;,
 89.09270;-54.91590;227.50510;,
 161.94020;-61.44680;233.16409;,
 89.09270;-61.44680;233.16409;,
 161.94020;-66.11880;240.43390;,
 89.09270;-66.11880;240.43390;,
 161.94020;-68.55340;248.72540;,
 89.09270;-68.55340;248.72540;,
 161.94020;-68.55340;257.36679;,
 89.09270;-68.55340;257.36679;,
 161.94020;-66.11880;265.65829;,
 89.09270;-66.11880;265.65829;,
 161.94020;-61.44680;272.92810;,
 89.09270;-61.44680;272.92810;,
 161.94020;-54.91590;278.58701;,
 89.09270;-54.91590;278.58701;,
 161.94020;-47.05530;282.17691;,
 89.09270;-47.05530;282.17691;,
 161.94020;-38.50170;283.40680;,
 89.09270;-38.50170;283.40680;,
 161.94020;-29.94820;282.17691;,
 89.09270;-29.94820;282.17691;,
 161.94020;-22.08750;278.58701;,
 89.09270;-22.08750;278.58701;,
 161.94020;-15.55670;272.92819;,
 89.09270;-15.55670;272.92819;,
 161.94020;-10.88470;265.65829;,
 89.09270;-10.88470;265.65829;,
 161.94020;-8.45010;257.36679;,
 89.09270;-8.45010;257.36679;,
 161.94020;-8.45010;248.72540;,
 89.09270;-8.45010;248.72540;,
 161.94020;-10.88470;240.43390;,
 89.09270;-10.88470;240.43390;,
 161.94020;-15.55670;233.16420;,
 89.09270;-15.55670;233.16420;,
 161.94020;-22.08750;227.50510;,
 89.09270;-22.08750;227.50510;,
 161.94020;-29.94810;223.91530;,
 89.09270;-29.94810;223.91530;,
 161.94020;-38.50170;253.04620;,
 89.09270;-38.50170;253.04620;,
 89.09270;-38.50170;222.68550;,
 89.09270;-47.05530;223.91530;,
 89.09270;-54.91590;227.50510;,
 89.09270;-61.44680;233.16409;,
 89.09270;-66.11880;240.43390;,
 89.09270;-68.55340;248.72540;,
 89.09270;-68.55340;257.36679;,
 89.09270;-66.11880;265.65829;,
 89.09270;-61.44680;272.92810;,
 89.09270;-54.91590;278.58701;,
 89.09270;-47.05530;282.17691;,
 89.09270;-38.50170;283.40680;,
 89.09270;-29.94820;282.17691;,
 89.09270;-22.08750;278.58701;,
 89.09270;-15.55670;272.92819;,
 89.09270;-10.88470;265.65829;,
 89.09270;-8.45010;257.36679;,
 89.09270;-8.45010;248.72540;,
 89.09270;-10.88470;240.43390;,
 89.09270;-15.55670;233.16420;,
 89.09270;-22.08750;227.50510;,
 89.09270;-29.94810;223.91530;;
 
 66;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,0,3,43;,
 3;44,1,0;,
 3;44,4,1;,
 3;44,6,4;,
 3;44,8,6;,
 3;44,10,8;,
 3;44,12,10;,
 3;44,14,12;,
 3;44,16,14;,
 3;44,18,16;,
 3;44,20,18;,
 3;44,22,20;,
 3;44,24,22;,
 3;44,26,24;,
 3;44,28,26;,
 3;44,30,28;,
 3;44,32,30;,
 3;44,34,32;,
 3;44,36,34;,
 3;44,38,36;,
 3;44,40,38;,
 3;44,42,40;,
 3;44,0,42;,
 3;45,46,47;,
 3;45,47,48;,
 3;45,48,49;,
 3;45,49,50;,
 3;45,50,51;,
 3;45,51,52;,
 3;45,52,53;,
 3;45,53,54;,
 3;45,54,55;,
 3;45,55,56;,
 3;45,56,57;,
 3;45,57,58;,
 3;45,58,59;,
 3;45,59,60;,
 3;45,60,61;,
 3;45,61,62;,
 3;45,62,63;,
 3;45,63,64;,
 3;45,64,65;,
 3;45,65,66;,
 3;45,66,67;,
 3;45,67,46;;
 
 MeshMaterialList {
  7;
  66;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Teppan.bmp";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Teppan.bmp";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Teppan.bmp";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Teppan.bmp";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Tetu.bmp";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Tetu.bmp";
   }
  }
  Material {
   0.450000;0.450000;0.450000;1.000000;;
   8.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  24;
  1.000000;0.000000;0.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;-0.281730;-0.959494;,
  0.000000;-0.540638;-0.841255;,
  0.000000;-0.755749;-0.654862;,
  0.000000;-0.909633;-0.415414;,
  0.000000;-0.989822;-0.142315;,
  0.000000;-0.989822;0.142315;,
  0.000000;-0.909633;0.415414;,
  0.000000;-0.755746;0.654865;,
  0.000000;-0.540639;0.841255;,
  0.000000;-0.281741;0.959491;,
  0.000000;0.000001;1.000000;,
  0.000000;0.281739;0.959491;,
  0.000000;0.540637;0.841256;,
  0.000000;0.755748;0.654863;,
  0.000000;0.909634;0.415411;,
  0.000000;0.989822;0.142315;,
  0.000000;0.989822;-0.142315;,
  0.000000;0.909631;-0.415417;,
  0.000000;0.755752;-0.654858;,
  0.000000;0.540645;-0.841251;,
  0.000000;0.281730;-0.959494;,
  -1.000000;0.000000;0.000000;;
  66;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;22,1,1,22;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;,
  3;23,23,23;;
 }
 MeshTextureCoords {
  68;
  24.424334;-33.077423;
  24.424334;-33.262859;
  13.440092;-33.262859;
  13.440092;-33.077423;
  24.424334;-33.804142;
  13.440092;-33.804142;
  24.424334;-34.657429;
  13.440092;-34.657429;
  24.424334;-35.753597;
  13.440092;-35.753597;
  24.424334;-37.003826;
  13.440092;-37.003826;
  24.424334;-38.306808;
  13.440092;-38.306808;
  24.424334;-39.557037;
  13.440092;-39.557037;
  24.424334;-40.653206;
  13.440092;-40.653206;
  24.424334;-41.506481;
  13.440092;-41.506481;
  24.424334;-42.047779;
  13.440092;-42.047779;
  24.424334;-42.233227;
  13.440092;-42.233227;
  24.424334;-42.047779;
  13.440092;-42.047779;
  24.424334;-41.506481;
  13.440092;-41.506481;
  24.424334;-40.653221;
  13.440092;-40.653221;
  24.424334;-39.557037;
  13.440092;-39.557037;
  24.424334;-38.306808;
  13.440092;-38.306808;
  24.424334;-37.003826;
  13.440092;-37.003826;
  24.424334;-35.753601;
  13.440092;-35.753601;
  24.424334;-34.657444;
  13.440092;-34.657444;
  24.424334;-33.804142;
  13.440092;-33.804142;
  24.424334;-33.262859;
  13.440092;-33.262859;
  24.424334;-37.655334;
  38.655338;7.115154;
  34.077427;7.115154;
  34.262859;8.404901;
  34.804146;9.590154;
  35.657433;10.574909;
  36.753601;11.279372;
  38.003830;11.646471;
  39.306812;11.646471;
  40.557041;11.279372;
  41.653210;10.574909;
  42.506485;9.590154;
  43.047783;8.404901;
  43.233231;7.115154;
  43.047783;5.825422;
  42.506485;4.640154;
  41.653225;3.655413;
  40.557041;2.950950;
  39.306812;2.583851;
  38.003830;2.583851;
  36.753601;2.950950;
  35.657448;3.655413;
  34.804146;4.640154;
  34.262859;5.825407;;
 }
}