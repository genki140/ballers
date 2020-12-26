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
 132;
 0.65781;-1.13937;1.10585;,
 0.55799;-0.96646;2.06559;,
 0.00000;-1.11597;2.06559;,
 0.00000;-1.31563;1.10585;,
 1.13937;-0.65781;1.10585;,
 0.96646;-0.55799;2.06559;,
 1.31563;0.00000;1.10585;,
 1.11597;0.00000;2.06559;,
 1.13937;0.65781;1.10585;,
 0.96646;0.55798;2.06559;,
 0.65781;1.13937;1.10585;,
 0.55799;0.96646;2.06559;,
 0.00000;1.31563;1.10585;,
 0.00000;1.11597;2.06559;,
 -0.65781;1.13937;1.10585;,
 -0.55798;0.96646;2.06559;,
 -1.13937;0.65781;1.10585;,
 -0.96646;0.55799;2.06559;,
 -1.31563;0.00000;1.10585;,
 -1.11597;0.00000;2.06559;,
 -1.13937;-0.65781;1.10585;,
 -0.96646;-0.55799;2.06559;,
 -0.65781;-1.13937;1.10585;,
 -0.55799;-0.96646;2.06559;,
 0.00000;-1.49779;0.22107;,
 0.74889;-1.29712;0.22107;,
 1.29712;-0.74890;0.22107;,
 1.49779;0.00000;0.22107;,
 1.29712;0.74889;0.22107;,
 0.74889;1.29712;0.22107;,
 0.00000;1.49779;0.22107;,
 -0.74889;1.29712;0.22107;,
 -1.29712;0.74889;0.22107;,
 -1.49779;0.00000;0.22107;,
 -1.29712;-0.74889;0.22107;,
 -0.74890;-1.29712;0.22107;,
 0.00000;-1.49779;-0.51874;,
 0.74889;-1.29712;-0.51874;,
 1.29712;-0.74890;-0.51874;,
 1.49779;0.00000;-0.51874;,
 1.29712;0.74889;-0.51874;,
 0.74889;1.29712;-0.51874;,
 0.00000;1.49779;-0.51874;,
 -0.74889;1.29712;-0.51874;,
 -1.29712;0.74890;-0.51874;,
 -1.49779;0.00000;-0.51874;,
 -1.29712;-0.74889;-0.51874;,
 -0.74890;-1.29712;-0.51874;,
 0.00000;-1.33546;-1.24359;,
 0.66773;-1.15654;-1.24359;,
 1.15654;-0.66773;-1.24359;,
 1.33546;0.00000;-1.24359;,
 1.15654;0.66773;-1.24359;,
 0.66773;1.15654;-1.24359;,
 0.00000;1.33546;-1.24359;,
 -0.66773;1.15654;-1.24359;,
 -1.15654;0.66773;-1.24359;,
 -1.33546;0.00000;-1.24359;,
 -1.15654;-0.66773;-1.24359;,
 -0.66773;-1.15654;-1.24359;,
 0.00000;-1.16721;-1.72492;,
 0.58360;-1.01083;-1.72492;,
 1.01083;-0.58360;-1.72492;,
 1.16721;0.00000;-1.72492;,
 1.01083;0.58360;-1.72492;,
 0.58360;1.01083;-1.72492;,
 0.00000;1.16721;-1.72492;,
 -0.58360;1.01083;-1.72492;,
 -1.01083;0.58360;-1.72492;,
 -1.16721;0.00000;-1.72492;,
 -1.01083;-0.58360;-1.72492;,
 -0.58360;-1.01083;-1.72492;,
 0.00000;-0.84824;-2.08191;,
 0.42412;-0.73460;-2.08191;,
 0.73460;-0.42412;-2.08191;,
 0.84824;0.00000;-2.08191;,
 0.73460;0.42412;-2.08191;,
 0.42412;0.73460;-2.08191;,
 0.00000;0.84824;-2.08191;,
 -0.42412;0.73460;-2.08191;,
 -0.73460;0.42412;-2.08191;,
 -0.84824;0.00000;-2.08191;,
 -0.73460;-0.42412;-2.08191;,
 -0.42412;-0.73460;-2.08191;,
 0.00000;-0.42619;-1.26547;,
 0.21309;-0.36909;-1.26547;,
 0.36909;-0.21310;-1.26547;,
 0.42619;-0.00000;-1.26547;,
 0.36909;0.21309;-1.26547;,
 0.21309;0.36909;-1.26547;,
 0.00000;0.42619;-1.26547;,
 -0.21309;0.36909;-1.26547;,
 -0.36909;0.21309;-1.26547;,
 -0.42619;0.00000;-1.26547;,
 -0.36909;-0.21309;-1.26547;,
 -0.21310;-0.36909;-1.26547;,
 0.00000;-0.19575;0.01180;,
 0.09787;-0.16952;0.01180;,
 0.16952;-0.09787;0.01180;,
 0.19575;-0.00000;0.01180;,
 0.16952;0.09787;0.01180;,
 0.09787;0.16952;0.01180;,
 0.00000;0.19575;0.01180;,
 -0.09787;0.16952;0.01180;,
 -0.16952;0.09787;0.01180;,
 -0.19575;-0.00000;0.01180;,
 -0.16952;-0.09787;0.01180;,
 -0.09787;-0.16952;0.01180;,
 0.00000;-0.05515;1.24125;,
 0.00000;-0.00000;2.45255;,
 0.00000;-0.00000;2.45255;,
 0.02757;-0.04776;1.24125;,
 0.00000;-0.00000;2.45254;,
 0.04776;-0.02757;1.24125;,
 0.00000;-0.00000;2.45255;,
 0.05515;-0.00000;1.24125;,
 0.00000;-0.00000;2.45254;,
 0.04776;0.02757;1.24125;,
 0.00000;-0.00000;2.45254;,
 0.02757;0.04776;1.24125;,
 0.00000;-0.00000;2.45254;,
 0.00000;0.05515;1.24125;,
 -0.00000;-0.00000;2.45254;,
 -0.02757;0.04776;1.24125;,
 -0.00000;-0.00000;2.45254;,
 -0.04776;0.02757;1.24125;,
 -0.00000;-0.00000;2.45255;,
 -0.05515;-0.00000;1.24125;,
 -0.00000;-0.00000;2.45255;,
 -0.04776;-0.02757;1.24125;,
 -0.00000;-0.00000;2.45255;,
 -0.02757;-0.04776;1.24125;;
 
 120;
 4;0,1,2,3;,
 4;4,5,1,0;,
 4;6,7,5,4;,
 4;8,9,7,6;,
 4;10,11,9,8;,
 4;12,13,11,10;,
 4;14,15,13,12;,
 4;16,17,15,14;,
 4;18,19,17,16;,
 4;20,21,19,18;,
 4;22,23,21,20;,
 4;3,2,23,22;,
 4;24,25,0,3;,
 4;25,26,4,0;,
 4;26,27,6,4;,
 4;27,28,8,6;,
 4;28,29,10,8;,
 4;29,30,12,10;,
 4;30,31,14,12;,
 4;31,32,16,14;,
 4;32,33,18,16;,
 4;33,34,20,18;,
 4;34,35,22,20;,
 4;35,24,3,22;,
 4;36,37,25,24;,
 4;37,38,26,25;,
 4;38,39,27,26;,
 4;39,40,28,27;,
 4;40,41,29,28;,
 4;41,42,30,29;,
 4;42,43,31,30;,
 4;43,44,32,31;,
 4;44,45,33,32;,
 4;45,46,34,33;,
 4;46,47,35,34;,
 4;47,36,24,35;,
 4;48,49,37,36;,
 4;49,50,38,37;,
 4;50,51,39,38;,
 4;51,52,40,39;,
 4;52,53,41,40;,
 4;53,54,42,41;,
 4;54,55,43,42;,
 4;55,56,44,43;,
 4;56,57,45,44;,
 4;57,58,46,45;,
 4;58,59,47,46;,
 4;59,48,36,47;,
 4;60,61,49,48;,
 4;61,62,50,49;,
 4;62,63,51,50;,
 4;63,64,52,51;,
 4;64,65,53,52;,
 4;65,66,54,53;,
 4;66,67,55,54;,
 4;67,68,56,55;,
 4;68,69,57,56;,
 4;69,70,58,57;,
 4;70,71,59,58;,
 4;71,60,48,59;,
 4;72,73,61,60;,
 4;73,74,62,61;,
 4;74,75,63,62;,
 4;75,76,64,63;,
 4;76,77,65,64;,
 4;77,78,66,65;,
 4;78,79,67,66;,
 4;79,80,68,67;,
 4;80,81,69,68;,
 4;81,82,70,69;,
 4;82,83,71,70;,
 4;83,72,60,71;,
 4;84,85,73,72;,
 4;85,86,74,73;,
 4;86,87,75,74;,
 4;87,88,76,75;,
 4;88,89,77,76;,
 4;89,90,78,77;,
 4;90,91,79,78;,
 4;91,92,80,79;,
 4;92,93,81,80;,
 4;93,94,82,81;,
 4;94,95,83,82;,
 4;95,84,72,83;,
 4;96,97,85,84;,
 4;97,98,86,85;,
 4;98,99,87,86;,
 4;99,100,88,87;,
 4;100,101,89,88;,
 4;101,102,90,89;,
 4;102,103,91,90;,
 4;103,104,92,91;,
 4;104,105,93,92;,
 4;105,106,94,93;,
 4;106,107,95,94;,
 4;107,96,84,95;,
 4;108,109,110,111;,
 4;108,111,97,96;,
 4;111,110,112,113;,
 4;111,113,98,97;,
 4;113,112,114,115;,
 4;113,115,99,98;,
 4;115,114,116,117;,
 4;115,117,100,99;,
 4;117,116,118,119;,
 4;117,119,101,100;,
 4;119,118,120,121;,
 4;119,121,102,101;,
 4;121,120,122,123;,
 4;121,123,103,102;,
 4;123,122,124,125;,
 4;123,125,104,103;,
 4;125,124,126,127;,
 4;125,127,105,104;,
 4;127,126,128,129;,
 4;127,129,106,105;,
 4;129,128,130,131;,
 4;129,131,107,106;,
 4;131,130,109,108;,
 4;131,108,96,107;;
 
 MeshMaterialList {
  1;
  120;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "Taihou3.bmp";
   }
  }
 }
 MeshNormals {
  144;
  -0.000000;0.998965;-0.045479;,
  -0.569800;0.820533;-0.045321;,
  -0.865277;0.499567;-0.041562;,
  -0.998965;-0.000000;-0.045479;,
  -0.820622;-0.569826;-0.043341;,
  -0.499482;-0.865130;-0.045480;,
  -0.000001;-0.998965;-0.045480;,
  0.525730;-0.849436;-0.045458;,
  0.825573;-0.562718;-0.042153;,
  0.993441;-0.105020;-0.045228;,
  0.865130;0.499481;-0.045479;,
  0.499484;0.865129;-0.045479;,
  0.000000;-0.979039;0.203672;,
  0.489519;-0.847874;0.203672;,
  0.847873;-0.489519;0.203672;,
  0.979039;0.000000;0.203671;,
  0.847873;0.489519;0.203672;,
  0.489519;0.847873;0.203672;,
  0.000000;0.979039;0.203672;,
  -0.489519;0.847873;0.203672;,
  -0.847873;0.489519;0.203672;,
  -0.979039;0.000000;0.203671;,
  -0.847874;-0.489519;0.203672;,
  -0.489519;-0.847873;0.203672;,
  0.000000;-0.979249;0.202663;,
  0.489623;-0.848055;0.202663;,
  0.848054;-0.489624;0.202663;,
  0.979249;0.000000;0.202663;,
  0.848055;0.489624;0.202663;,
  0.489624;0.848054;0.202663;,
  0.000000;0.979249;0.202663;,
  -0.489624;0.848054;0.202663;,
  -0.848054;0.489624;0.202663;,
  -0.979249;0.000000;0.202663;,
  -0.848055;-0.489623;0.202663;,
  -0.489624;-0.848054;0.202663;,
  0.000000;-0.994844;0.101418;,
  0.497421;-0.861560;0.101418;,
  0.861560;-0.497422;0.101418;,
  0.994844;0.000000;0.101418;,
  0.861560;0.497422;0.101418;,
  0.497422;0.861560;0.101418;,
  0.000000;0.994844;0.101418;,
  -0.497422;0.861560;0.101418;,
  -0.861560;0.497422;0.101418;,
  -0.994844;0.000000;0.101418;,
  -0.861561;-0.497421;0.101418;,
  -0.497422;-0.861560;0.101418;,
  0.000000;-0.993929;-0.110022;,
  0.496964;-0.860768;-0.110022;,
  0.860768;-0.496964;-0.110022;,
  0.993929;0.000000;-0.110022;,
  0.860768;0.496964;-0.110022;,
  0.496965;0.860768;-0.110022;,
  0.000000;0.993929;-0.110022;,
  -0.496964;0.860768;-0.110022;,
  -0.860768;0.496964;-0.110022;,
  -0.993929;0.000000;-0.110022;,
  -0.860768;-0.496964;-0.110022;,
  -0.496965;-0.860768;-0.110022;,
  0.000000;-0.961508;-0.274777;,
  0.480754;-0.832691;-0.274777;,
  0.832691;-0.480754;-0.274777;,
  0.961508;0.000000;-0.274777;,
  0.832691;0.480754;-0.274777;,
  0.480754;0.832690;-0.274777;,
  0.000000;0.961508;-0.274777;,
  -0.480753;0.832691;-0.274777;,
  -0.832691;0.480754;-0.274777;,
  -0.961508;0.000000;-0.274777;,
  -0.832691;-0.480753;-0.274777;,
  -0.480754;-0.832690;-0.274777;,
  0.000000;-0.860839;-0.508877;,
  0.430419;-0.745509;-0.508877;,
  0.745509;-0.430419;-0.508877;,
  0.860839;0.000000;-0.508877;,
  0.745509;0.430419;-0.508877;,
  0.430420;0.745509;-0.508877;,
  0.000000;0.860839;-0.508877;,
  -0.430419;0.745509;-0.508877;,
  -0.745509;0.430419;-0.508877;,
  -0.860839;0.000000;-0.508877;,
  -0.745509;-0.430419;-0.508877;,
  -0.430420;-0.745509;-0.508877;,
  0.000000;-0.745707;-0.666274;,
  0.372853;-0.645801;-0.666274;,
  0.645801;-0.372853;-0.666274;,
  0.745707;0.000000;-0.666274;,
  0.645801;0.372853;-0.666274;,
  0.372853;0.645801;-0.666274;,
  0.000000;0.745707;-0.666274;,
  -0.372853;0.645801;-0.666274;,
  -0.645801;0.372853;-0.666274;,
  -0.745707;0.000000;-0.666274;,
  -0.645802;-0.372853;-0.666274;,
  -0.372854;-0.645801;-0.666274;,
  -0.000000;0.946606;-0.322394;,
  -0.473303;0.819785;-0.322394;,
  -0.819785;0.473303;-0.322394;,
  -0.946606;-0.000000;-0.322394;,
  -0.819785;-0.473303;-0.322394;,
  -0.473303;-0.819785;-0.322394;,
  -0.000001;-0.946606;-0.322394;,
  0.473303;-0.819785;-0.322394;,
  0.819785;-0.473302;-0.322394;,
  0.946606;-0.000000;-0.322394;,
  0.819785;0.473302;-0.322394;,
  0.473303;0.819784;-0.322394;,
  -0.000000;0.989333;-0.145672;,
  -0.494666;0.856788;-0.145672;,
  -0.856788;0.494666;-0.145672;,
  -0.989333;-0.000000;-0.145672;,
  -0.856788;-0.494666;-0.145672;,
  -0.494666;-0.856788;-0.145672;,
  -0.000001;-0.989333;-0.145672;,
  0.494666;-0.856788;-0.145672;,
  0.856788;-0.494666;-0.145672;,
  0.989333;-0.000000;-0.145672;,
  0.856788;0.494665;-0.145672;,
  0.494667;0.856787;-0.145672;,
  -0.000000;0.996827;-0.079603;,
  -0.533572;0.841959;-0.080039;,
  -0.863447;0.498511;-0.077107;,
  -0.996744;-0.000000;-0.080625;,
  -0.841587;-0.534420;-0.078276;,
  -0.498413;-0.863278;-0.079603;,
  -0.000001;-0.996827;-0.079603;,
  0.511539;-0.855551;-0.079750;,
  0.843893;-0.530882;-0.077521;,
  0.995439;-0.051704;-0.080173;,
  0.863278;0.498412;-0.079603;,
  0.498414;0.863277;-0.079603;,
  -0.444164;0.769314;-0.459210;,
  -0.000000;0.888328;-0.459210;,
  -0.769314;0.444164;-0.459210;,
  -0.888328;-0.000000;-0.459210;,
  -0.769314;-0.444164;-0.459210;,
  -0.444164;-0.769314;-0.459210;,
  -0.000001;-0.888328;-0.459210;,
  0.444164;-0.769314;-0.459210;,
  0.769314;-0.444164;-0.459210;,
  0.888328;-0.000000;-0.459210;,
  0.769315;0.444163;-0.459210;,
  0.444164;0.769314;-0.459210;;
  120;
  4;25,13,12,24;,
  4;26,14,13,25;,
  4;27,15,14,26;,
  4;28,16,15,27;,
  4;29,17,16,28;,
  4;30,18,17,29;,
  4;31,19,18,30;,
  4;32,20,19,31;,
  4;33,21,20,32;,
  4;34,22,21,33;,
  4;35,23,22,34;,
  4;24,12,23,35;,
  4;36,37,25,24;,
  4;37,38,26,25;,
  4;38,39,27,26;,
  4;39,40,28,27;,
  4;40,41,29,28;,
  4;41,42,30,29;,
  4;42,43,31,30;,
  4;43,44,32,31;,
  4;44,45,33,32;,
  4;45,46,34,33;,
  4;46,47,35,34;,
  4;47,36,24,35;,
  4;48,49,37,36;,
  4;49,50,38,37;,
  4;50,51,39,38;,
  4;51,52,40,39;,
  4;52,53,41,40;,
  4;53,54,42,41;,
  4;54,55,43,42;,
  4;55,56,44,43;,
  4;56,57,45,44;,
  4;57,58,46,45;,
  4;58,59,47,46;,
  4;59,48,36,47;,
  4;60,61,49,48;,
  4;61,62,50,49;,
  4;62,63,51,50;,
  4;63,64,52,51;,
  4;64,65,53,52;,
  4;65,66,54,53;,
  4;66,67,55,54;,
  4;67,68,56,55;,
  4;68,69,57,56;,
  4;69,70,58,57;,
  4;70,71,59,58;,
  4;71,60,48,59;,
  4;72,73,61,60;,
  4;73,74,62,61;,
  4;74,75,63,62;,
  4;75,76,64,63;,
  4;76,77,65,64;,
  4;77,78,66,65;,
  4;78,79,67,66;,
  4;79,80,68,67;,
  4;80,81,69,68;,
  4;81,82,70,69;,
  4;82,83,71,70;,
  4;83,72,60,71;,
  4;84,85,73,72;,
  4;85,86,74,73;,
  4;86,87,75,74;,
  4;87,88,76,75;,
  4;88,89,77,76;,
  4;89,90,78,77;,
  4;90,91,79,78;,
  4;91,92,80,79;,
  4;92,93,81,80;,
  4;93,94,82,81;,
  4;94,95,83,82;,
  4;95,84,72,83;,
  4;96,97,132,133;,
  4;97,98,134,132;,
  4;98,99,135,134;,
  4;99,100,136,135;,
  4;100,101,137,136;,
  4;101,102,138,137;,
  4;102,103,139,138;,
  4;103,104,140,139;,
  4;104,105,141,140;,
  4;105,106,142,141;,
  4;106,107,143,142;,
  4;107,96,133,143;,
  4;108,109,97,96;,
  4;109,110,98,97;,
  4;110,111,99,98;,
  4;111,112,100,99;,
  4;112,113,101,100;,
  4;113,114,102,101;,
  4;114,115,103,102;,
  4;115,116,104,103;,
  4;116,117,105,104;,
  4;117,118,106,105;,
  4;118,119,107,106;,
  4;119,108,96,107;,
  4;120,0,1,121;,
  4;120,121,109,108;,
  4;121,1,2,122;,
  4;121,122,110,109;,
  4;122,2,3,123;,
  4;122,123,111,110;,
  4;123,3,4,124;,
  4;123,124,112,111;,
  4;124,4,5,125;,
  4;124,125,113,112;,
  4;125,5,6,126;,
  4;125,126,114,113;,
  4;126,6,7,127;,
  4;126,127,115,114;,
  4;127,7,8,128;,
  4;127,128,116,115;,
  4;128,8,9,129;,
  4;128,129,117,116;,
  4;129,9,10,130;,
  4;129,130,118,117;,
  4;130,10,11,131;,
  4;130,131,119,118;,
  4;131,11,0,120;,
  4;131,120,108,119;;
 }
 MeshTextureCoords {
  132;
  0.081943;1.148562;
  -0.001689;1.148562;
  -0.001689;1.248895;
  0.081943;1.248895;
  0.081943;0.874448;
  -0.001689;0.874448;
  0.081943;0.500000;
  -0.001689;0.500000;
  0.081943;0.125553;
  -0.001689;0.125553;
  0.081943;-0.148562;
  -0.001689;-0.148562;
  0.081943;-0.248895;
  -0.001689;-0.248895;
  0.081943;-0.148562;
  -0.001689;-0.148562;
  0.081943;0.125553;
  -0.001689;0.125553;
  0.081943;0.499999;
  -0.001689;0.499999;
  0.081943;0.874447;
  -0.001689;0.874447;
  0.081943;1.148562;
  -0.001689;1.148562;
  0.191520;1.248895;
  0.191520;1.148562;
  0.191520;0.874448;
  0.191520;0.500000;
  0.191520;0.125553;
  0.191520;-0.148562;
  0.191520;-0.248895;
  0.191520;-0.148562;
  0.191520;0.125553;
  0.191520;0.500000;
  0.191520;0.874447;
  0.191520;1.148562;
  0.357365;1.248895;
  0.357365;1.148562;
  0.357366;0.874448;
  0.357365;0.500000;
  0.357366;0.125553;
  0.357365;-0.148562;
  0.357365;-0.248895;
  0.357365;-0.148562;
  0.357366;0.125553;
  0.357366;0.500000;
  0.357366;0.874447;
  0.357365;1.148562;
  0.446212;1.248895;
  0.446212;1.148562;
  0.446211;0.874448;
  0.446212;0.500000;
  0.446211;0.125553;
  0.446211;-0.148562;
  0.446212;-0.248895;
  0.446212;-0.148562;
  0.446212;0.125553;
  0.446212;0.500000;
  0.446212;0.874447;
  0.446212;1.148562;
  0.508404;1.248895;
  0.508404;1.148562;
  0.508404;0.874448;
  0.508404;0.500000;
  0.508404;0.125553;
  0.508404;-0.148562;
  0.508404;-0.248895;
  0.508404;-0.148562;
  0.508404;0.125552;
  0.508404;0.500000;
  0.508404;0.874447;
  0.508404;1.148562;
  0.561711;1.248895;
  0.561711;1.148562;
  0.561711;0.874448;
  0.561711;0.500000;
  0.561711;0.125553;
  0.561711;-0.148562;
  0.561711;-0.248895;
  0.561711;-0.148562;
  0.561711;0.125552;
  0.561711;0.500000;
  0.561711;0.874447;
  0.561711;1.148562;
  0.610577;1.248895;
  0.610577;1.148562;
  0.610577;0.874448;
  0.610577;0.500000;
  0.610577;0.125553;
  0.610577;-0.148562;
  0.610577;-0.248895;
  0.610577;-0.148563;
  0.610577;0.125552;
  0.610577;0.500000;
  0.610577;0.874447;
  0.610577;1.148562;
  0.692019;1.248895;
  0.692019;1.148562;
  0.692019;0.874448;
  0.692019;0.500000;
  0.692019;0.125553;
  0.692019;-0.148562;
  0.692019;-0.248895;
  0.692019;-0.148563;
  0.692019;0.125552;
  0.692019;0.500000;
  0.692019;0.874447;
  0.692019;1.148562;
  0.811961;1.248895;
  0.998310;1.248895;
  0.998310;1.148562;
  0.811961;1.148562;
  0.998311;0.874447;
  0.811961;0.874448;
  0.998310;0.500000;
  0.811961;0.500000;
  0.998311;0.125552;
  0.811961;0.125553;
  0.998311;-0.148562;
  0.811961;-0.148562;
  0.998311;-0.248895;
  0.811961;-0.248895;
  0.998311;-0.148563;
  0.811961;-0.148563;
  0.998311;0.125552;
  0.811961;0.125552;
  0.998310;0.500000;
  0.811961;0.500000;
  0.998310;0.874447;
  0.811961;0.874447;
  0.998310;1.148562;
  0.811961;1.148562;;
 }
}
