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
 94;
 0.00000;6309.54639;0.00000;,
 0.00000;6053.95947;-1777.60352;,
 1256.95703;6053.95947;-1256.95703;,
 1777.60352;6053.95947;0.00000;,
 1256.95703;6053.95947;1256.95703;,
 0.00000;6053.95947;1777.60352;,
 -1256.95703;6053.95947;1256.95703;,
 -1777.60352;6053.95947;0.00000;,
 -1256.95703;6053.95947;-1256.95703;,
 0.00000;6053.95947;-1777.60352;,
 0.00000;5307.92285;-3411.19678;,
 2412.08081;5307.92285;-2412.08081;,
 1256.95703;6053.95947;-1256.95703;,
 3411.19678;5307.92285;0.00000;,
 2412.08081;5307.92285;2412.08081;,
 0.00000;5307.92285;3411.19678;,
 -2412.08081;5307.92285;2412.08081;,
 -3411.19678;5307.92285;0.00000;,
 -2412.08081;5307.92285;-2412.08081;,
 0.00000;5307.92285;-3411.19678;,
 0.00000;4131.87598;-4768.43359;,
 3371.79370;4131.87598;-3371.79370;,
 4768.43359;4131.87598;0.00000;,
 3371.79370;4131.87598;3371.79370;,
 0.00000;4131.87598;4768.43359;,
 -3371.79443;4131.87598;3371.79321;,
 -4768.43359;4131.87598;0.00000;,
 -3371.79443;4131.87598;-3371.79321;,
 0.00000;4131.87598;-4768.43359;,
 0.00000;2621.07910;-5739.36230;,
 4058.33838;2621.07910;-4058.33838;,
 5739.36230;2621.07910;0.00000;,
 4058.33838;2621.07910;4058.33838;,
 -0.00080;2621.07910;5739.36230;,
 -4058.34424;2621.07910;4058.33838;,
 -5739.36230;2621.07910;0.00000;,
 -4058.34424;2621.07910;-4058.33838;,
 0.00000;2621.07910;-5739.36230;,
 0.00000;897.94110;-6245.32080;,
 4416.10693;897.94110;-4416.10693;,
 6245.32080;897.94110;0.00000;,
 4416.10693;897.94110;4416.10693;,
 -0.00080;897.94110;6245.32080;,
 -4416.10938;897.94110;4416.10693;,
 -6245.32080;897.94110;0.00000;,
 -4416.10938;897.94110;-4416.10693;,
 0.00000;897.94110;-6245.32080;,
 0.00000;-897.94232;-6245.32080;,
 4416.10693;-897.94232;-4416.10693;,
 6245.32080;-897.94232;-0.00000;,
 4416.10693;-897.94232;4416.10693;,
 -0.00080;-897.94232;6245.32080;,
 -4416.10938;-897.94232;4416.10693;,
 -6245.32080;-897.94232;0.00000;,
 -4416.10938;-897.94232;-4416.10693;,
 0.00000;-897.94232;-6245.32080;,
 0.00000;-2621.07983;-5739.36230;,
 4058.33838;-2621.07983;-4058.33838;,
 5739.36230;-2621.07983;-0.00000;,
 4058.33838;-2621.07983;4058.33838;,
 -0.00080;-2621.07983;5739.36230;,
 -4058.33838;-2621.07983;4058.33838;,
 -5739.36230;-2621.07983;0.00000;,
 -4058.33838;-2621.07983;-4058.33838;,
 0.00000;-2621.07983;-5739.36230;,
 0.00000;-4131.87598;-4768.43359;,
 3371.79321;-4131.87598;-3371.79321;,
 4768.43359;-4131.87598;-0.00000;,
 3371.79321;-4131.87598;3371.79321;,
 0.00000;-4131.87598;4768.43359;,
 -3371.79370;-4131.87598;3371.79321;,
 -4768.43359;-4131.87598;0.00000;,
 -3371.79370;-4131.87598;-3371.79321;,
 0.00000;-4131.87598;-4768.43359;,
 0.00000;-5307.92578;-3411.19678;,
 2412.08081;-5307.92578;-2412.08081;,
 3411.19678;-5307.92578;-0.00000;,
 2412.08081;-5307.92578;2412.08081;,
 0.00000;-5307.92578;3411.19678;,
 -2412.08081;-5307.92578;2412.08081;,
 -3411.19678;-5307.92578;0.00000;,
 -2412.08081;-5307.92578;-2412.08081;,
 0.00000;-5307.92578;-3411.19678;,
 0.00000;-6053.95947;-1777.60352;,
 1256.95703;-6053.95947;-1256.95703;,
 1777.60352;-6053.95947;-0.00000;,
 1256.95703;-6053.95947;1256.95703;,
 0.00000;-6053.95947;1777.60352;,
 -1256.95703;-6053.95947;1256.95703;,
 -1777.60352;-6053.95947;0.00000;,
 -1256.95703;-6053.95947;-1256.95703;,
 0.00000;-6053.95947;-1777.60352;,
 0.00000;-6309.54639;-0.00000;,
 0.00000;-6309.54639;-0.00000;;
 
 88;
 3;0,1,2;,
 3;0,2,3;,
 3;0,3,4;,
 3;0,4,5;,
 3;0,5,6;,
 3;0,6,7;,
 3;0,7,8;,
 3;0,8,1;,
 4;9,10,11,12;,
 4;12,11,13,3;,
 4;3,13,14,4;,
 4;4,14,15,5;,
 4;5,15,16,6;,
 4;6,16,17,7;,
 4;7,17,18,8;,
 4;8,18,19,1;,
 4;10,20,21,11;,
 4;11,21,22,13;,
 4;13,22,23,14;,
 4;14,23,24,15;,
 4;15,24,25,16;,
 4;16,25,26,17;,
 4;17,26,27,18;,
 4;18,27,28,19;,
 4;20,29,30,21;,
 4;21,30,31,22;,
 4;22,31,32,23;,
 4;23,32,33,24;,
 4;24,33,34,25;,
 4;25,34,35,26;,
 4;26,35,36,27;,
 4;27,36,37,28;,
 4;29,38,39,30;,
 4;30,39,40,31;,
 4;31,40,41,32;,
 4;32,41,42,33;,
 4;33,42,43,34;,
 4;34,43,44,35;,
 4;35,44,45,36;,
 4;36,45,46,37;,
 4;38,47,48,39;,
 4;39,48,49,40;,
 4;40,49,50,41;,
 4;41,50,51,42;,
 4;42,51,52,43;,
 4;43,52,53,44;,
 4;44,53,54,45;,
 4;45,54,55,46;,
 4;47,56,57,48;,
 4;48,57,58,49;,
 4;49,58,59,50;,
 4;50,59,60,51;,
 4;51,60,61,52;,
 4;52,61,62,53;,
 4;53,62,63,54;,
 4;54,63,64,55;,
 4;56,65,66,57;,
 4;57,66,67,58;,
 4;58,67,68,59;,
 4;59,68,69,60;,
 4;60,69,70,61;,
 4;61,70,71,62;,
 4;62,71,72,63;,
 4;63,72,73,64;,
 4;65,74,75,66;,
 4;66,75,76,67;,
 4;67,76,77,68;,
 4;68,77,78,69;,
 4;69,78,79,70;,
 4;70,79,80,71;,
 4;71,80,81,72;,
 4;72,81,82,73;,
 4;74,83,84,75;,
 4;75,84,85,76;,
 4;76,85,86,77;,
 4;77,86,87,78;,
 4;78,87,88,79;,
 4;79,88,89,80;,
 4;80,89,90,81;,
 4;81,90,91,82;,
 3;83,92,84;,
 3;84,92,85;,
 3;85,93,86;,
 3;86,93,87;,
 3;87,93,88;,
 3;88,93,89;,
 3;89,93,90;,
 3;90,93,91;;
 
 MeshMaterialList {
  6;
  88;
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
  1;;
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
   0.984000;0.969000;1.000000;;
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
  82;
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.959752;0.280848;,
  -0.198589;-0.959752;0.198589;,
  -0.280848;-0.959752;0.000000;,
  -0.198589;-0.959752;-0.198589;,
  0.000000;-0.959752;-0.280848;,
  0.198589;-0.959752;-0.198589;,
  0.280848;-0.959752;-0.000000;,
  0.198589;-0.959752;0.198589;,
  0.000000;-0.842066;0.539375;,
  -0.381395;-0.842066;0.381395;,
  -0.539375;-0.842066;0.000000;,
  -0.381395;-0.842066;-0.381395;,
  0.000000;-0.842066;-0.539375;,
  0.381395;-0.842066;-0.381395;,
  0.539375;-0.842066;-0.000000;,
  0.381395;-0.842066;0.381395;,
  -0.000000;-0.656045;0.754722;,
  -0.533669;-0.656045;0.533669;,
  -0.754722;-0.656045;0.000000;,
  -0.533669;-0.656045;-0.533669;,
  -0.000000;-0.656044;-0.754722;,
  0.533669;-0.656045;-0.533669;,
  0.754722;-0.656045;-0.000000;,
  0.533669;-0.656045;0.533669;,
  -0.000000;-0.416462;0.909153;,
  -0.642868;-0.416462;0.642868;,
  -0.909153;-0.416462;0.000000;,
  -0.642868;-0.416462;-0.642868;,
  -0.000000;-0.416462;-0.909153;,
  0.642869;-0.416462;-0.642868;,
  0.909153;-0.416462;-0.000000;,
  0.642868;-0.416462;0.642868;,
  -0.000000;-0.142731;0.989762;,
  -0.699867;-0.142731;0.699867;,
  -0.989762;-0.142731;0.000000;,
  -0.699867;-0.142731;-0.699867;,
  -0.000000;-0.142731;-0.989762;,
  0.699867;-0.142731;-0.699867;,
  0.989762;-0.142731;-0.000000;,
  0.699867;-0.142731;0.699867;,
  -0.000000;0.142731;0.989761;,
  -0.699867;0.142731;0.699867;,
  -0.989761;0.142731;0.000000;,
  -0.699867;0.142731;-0.699867;,
  -0.000000;0.142731;-0.989762;,
  0.699867;0.142731;-0.699867;,
  0.989761;0.142731;0.000000;,
  0.699867;0.142731;0.699867;,
  -0.000000;0.416462;0.909153;,
  -0.642868;0.416462;0.642868;,
  -0.909153;0.416462;0.000000;,
  -0.642868;0.416462;-0.642868;,
  -0.000000;0.416462;-0.909153;,
  0.642868;0.416462;-0.642868;,
  0.909153;0.416462;0.000000;,
  0.642868;0.416462;0.642868;,
  -0.000000;0.656044;0.754723;,
  -0.533669;0.656044;0.533669;,
  -0.754723;0.656044;0.000000;,
  -0.533669;0.656044;-0.533669;,
  -0.000000;0.656044;-0.754723;,
  0.533669;0.656044;-0.533669;,
  0.754723;0.656044;0.000000;,
  0.533669;0.656044;0.533669;,
  0.000000;0.842066;0.539375;,
  -0.381395;0.842066;0.381395;,
  -0.539375;0.842066;0.000000;,
  -0.381395;0.842066;-0.381395;,
  0.000000;0.842066;-0.539375;,
  0.381395;0.842066;-0.381395;,
  0.539375;0.842066;0.000000;,
  0.381395;0.842066;0.381395;,
  0.000000;0.959753;0.280847;,
  -0.198589;0.959753;0.198589;,
  -0.280847;0.959753;0.000000;,
  -0.198589;0.959753;-0.198589;,
  0.000000;0.959753;-0.280847;,
  0.198589;0.959753;-0.198589;,
  0.280847;0.959753;0.000000;,
  0.198589;0.959753;0.198589;,
  0.000000;1.000000;0.000000;;
  88;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;0,4,5;,
  3;0,5,6;,
  3;0,6,7;,
  3;0,7,8;,
  3;0,8,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;7,15,16,8;,
  4;8,16,9,1;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;15,23,24,16;,
  4;16,24,17,9;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,32,24;,
  4;24,32,25,17;,
  4;25,33,34,26;,
  4;26,34,35,27;,
  4;27,35,36,28;,
  4;28,36,37,29;,
  4;29,37,38,30;,
  4;30,38,39,31;,
  4;31,39,40,32;,
  4;32,40,33,25;,
  4;33,41,42,34;,
  4;34,42,43,35;,
  4;35,43,44,36;,
  4;36,44,45,37;,
  4;37,45,46,38;,
  4;38,46,47,39;,
  4;39,47,48,40;,
  4;40,48,41,33;,
  4;41,49,50,42;,
  4;42,50,51,43;,
  4;43,51,52,44;,
  4;44,52,53,45;,
  4;45,53,54,46;,
  4;46,54,55,47;,
  4;47,55,56,48;,
  4;48,56,49,41;,
  4;49,57,58,50;,
  4;50,58,59,51;,
  4;51,59,60,52;,
  4;52,60,61,53;,
  4;53,61,62,54;,
  4;54,62,63,55;,
  4;55,63,64,56;,
  4;56,64,57,49;,
  4;57,65,66,58;,
  4;58,66,67,59;,
  4;59,67,68,60;,
  4;60,68,69,61;,
  4;61,69,70,62;,
  4;62,70,71,63;,
  4;63,71,72,64;,
  4;64,72,65,57;,
  4;65,73,74,66;,
  4;66,74,75,67;,
  4;67,75,76,68;,
  4;68,76,77,69;,
  4;69,77,78,70;,
  4;70,78,79,71;,
  4;71,79,80,72;,
  4;72,80,73,65;,
  3;73,81,74;,
  3;74,81,75;,
  3;75,81,76;,
  3;76,81,77;,
  3;77,81,78;,
  3;78,81,79;,
  3;79,81,80;,
  3;80,81,73;;
 }
 MeshTextureCoords {
  94;
  0.750000;0.054189;
  1.000000;0.072248;
  1.125000;0.072248;
  0.250000;0.072248;
  0.375000;0.072248;
  0.500000;0.072248;
  0.625000;0.072248;
  0.750000;0.072248;
  0.875000;0.072248;
  0.000000;0.072248;
  0.000000;0.124960;
  0.125000;0.124960;
  0.125000;0.072248;
  0.250000;0.124960;
  0.375000;0.124960;
  0.500000;0.124960;
  0.625000;0.124960;
  0.750000;0.124960;
  0.875000;0.124960;
  1.000000;0.124960;
  0.000000;0.208056;
  0.125000;0.208056;
  0.250000;0.208056;
  0.375000;0.208056;
  0.500000;0.208056;
  0.625000;0.208056;
  0.750000;0.208056;
  0.875000;0.208056;
  1.000000;0.208056;
  0.000000;0.314804;
  0.125000;0.314804;
  0.250000;0.314804;
  0.375000;0.314804;
  0.500000;0.314804;
  0.625000;0.314804;
  0.750000;0.314804;
  0.875000;0.314804;
  1.000000;0.314804;
  0.000000;0.436555;
  0.125000;0.436555;
  0.250000;0.436555;
  0.375000;0.436555;
  0.500000;0.436555;
  0.625000;0.436555;
  0.750000;0.436555;
  0.875000;0.436555;
  1.000000;0.436555;
  0.000000;0.563446;
  0.125000;0.563446;
  0.250000;0.563446;
  0.375000;0.563446;
  0.500000;0.563446;
  0.625000;0.563446;
  0.750000;0.563446;
  0.875000;0.563446;
  1.000000;0.563446;
  0.000000;0.685197;
  0.125000;0.685197;
  0.250000;0.685197;
  0.375000;0.685197;
  0.500000;0.685197;
  0.625000;0.685197;
  0.750000;0.685197;
  0.875000;0.685197;
  1.000000;0.685197;
  0.000000;0.791944;
  0.125000;0.791944;
  0.250000;0.791944;
  0.375000;0.791944;
  0.500000;0.791944;
  0.625000;0.791944;
  0.750000;0.791944;
  0.875000;0.791944;
  1.000000;0.791944;
  0.000000;0.875040;
  0.125000;0.875040;
  0.250000;0.875040;
  0.375000;0.875040;
  0.500000;0.875040;
  0.625000;0.875040;
  0.750000;0.875040;
  0.875000;0.875040;
  1.000000;0.875040;
  0.000000;0.927752;
  0.125000;0.927752;
  0.250000;0.927752;
  0.375000;0.927752;
  0.500000;0.927752;
  0.625000;0.927752;
  0.750000;0.927752;
  0.875000;0.927752;
  1.000000;0.927752;
  -0.250000;0.945811;
  0.750000;0.945811;;
 }
}
