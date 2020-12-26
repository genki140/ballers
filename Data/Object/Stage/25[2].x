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
 40;
 25.53160;8.80880;-17.15700;,
 25.53160;6.52250;-16.77550;,
 24.17260;6.52250;-16.77550;,
 24.17260;8.80880;-17.15700;,
 25.53160;4.48390;-15.67230;,
 24.17260;4.48390;-15.67230;,
 25.53160;2.91400;-13.96690;,
 24.17260;2.91400;-13.96690;,
 25.53160;1.98290;-11.84420;,
 24.17260;1.98290;-11.84420;,
 25.53160;1.79150;-9.53420;,
 24.17260;1.79150;-9.53420;,
 25.53160;2.36050;-7.28720;,
 24.17260;2.36050;-7.28720;,
 25.53160;3.62830;-5.34670;,
 24.17260;3.62830;-5.34670;,
 25.53160;5.45750;-3.92300;,
 24.17260;5.45750;-3.92300;,
 25.53160;7.64980;-3.17040;,
 24.17260;7.64980;-3.17040;,
 25.53160;9.96770;-3.17040;,
 24.17260;9.96770;-3.17040;,
 25.53160;12.16010;-3.92300;,
 24.17260;12.16010;-3.92300;,
 25.53160;13.98930;-5.34670;,
 24.17260;13.98930;-5.34670;,
 25.53160;15.25700;-7.28720;,
 24.17260;15.25700;-7.28720;,
 25.53160;15.82610;-9.53420;,
 24.17260;15.82610;-9.53420;,
 25.53160;15.63460;-11.84420;,
 24.17260;15.63460;-11.84420;,
 25.53160;14.70350;-13.96690;,
 24.17260;14.70350;-13.96690;,
 25.53160;13.13360;-15.67230;,
 24.17260;13.13360;-15.67230;,
 25.53160;11.09510;-16.77550;,
 24.17260;11.09510;-16.77550;,
 25.53160;8.80880;-10.11570;,
 24.17260;8.80880;-10.11570;;
 
 57;
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
 4;36,0,3,37;,
 3;38,1,0;,
 3;38,4,1;,
 3;38,6,4;,
 3;38,8,6;,
 3;38,10,8;,
 3;38,12,10;,
 3;38,14,12;,
 3;38,16,14;,
 3;38,18,16;,
 3;38,20,18;,
 3;38,22,20;,
 3;38,24,22;,
 3;38,26,24;,
 3;38,28,26;,
 3;38,30,28;,
 3;38,32,30;,
 3;38,34,32;,
 3;38,36,34;,
 3;38,0,36;,
 3;39,3,2;,
 3;39,2,5;,
 3;39,5,7;,
 3;39,7,9;,
 3;39,9,11;,
 3;39,11,13;,
 3;39,13,15;,
 3;39,15,17;,
 3;39,17,19;,
 3;39,19,21;,
 3;39,21,23;,
 3;39,23,25;,
 3;39,25,27;,
 3;39,27,29;,
 3;39,29,31;,
 3;39,31,33;,
 3;39,33,35;,
 3;39,35,37;,
 3;39,37,3;;
 
 MeshMaterialList {
  11;
  57;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
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
   0.256050;0.256050;0.256050;1.000000;;
   8.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "konbea.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "konbea.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
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
 }
 MeshNormals {
  21;
  1.000000;0.000000;0.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;-0.324690;-0.945821;,
  0.000000;-0.614211;-0.789142;,
  0.000000;-0.837169;-0.546944;,
  0.000000;-0.969401;-0.245483;,
  0.000000;-0.996585;0.082578;,
  0.000000;-0.915774;0.401693;,
  0.000000;-0.735720;0.677286;,
  0.000000;-0.475941;0.879477;,
  0.000000;-0.164591;0.986362;,
  0.000000;0.164584;0.986363;,
  0.000000;0.475935;0.879481;,
  0.000000;0.735732;0.677272;,
  0.000000;0.915773;0.401696;,
  0.000000;0.996585;0.082578;,
  0.000000;0.969396;-0.245503;,
  0.000000;0.837170;-0.546943;,
  0.000000;0.614219;-0.789135;,
  0.000000;0.324700;-0.945817;,
  -1.000000;0.000000;0.000000;;
  57;
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
  4;19,1,1,19;,
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
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;;
 }
 MeshTextureCoords {
  40;
  -27.710630;52.090424;
  -28.272371;52.233360;
  -28.504526;51.889912;
  -27.942785;51.746975;
  -28.697609;52.217827;
  -28.929764;51.874378;
  -28.940235;52.045490;
  -29.172390;51.702038;
  -28.973970;51.735043;
  -29.206125;51.391590;
  -28.795158;51.320122;
  -29.027313;50.976669;
  -28.423185;50.845692;
  -28.655340;50.502239;
  -27.898342;50.363155;
  -28.130495;50.019703;
  -27.277510;49.924812;
  -27.509665;49.581360;
  -26.627987;49.578171;
  -26.860142;49.234718;
  -26.020140;49.360779;
  -26.252293;49.017330;
  -25.519812;49.296192;
  -25.751966;48.952740;
  -25.181259;49.391422;
  -25.413414;49.047970;
  -25.041191;49.636158;
  -25.273346;49.292706;
  -25.114708;50.003849;
  -25.346863;49.660400;
  -25.393932;50.454681;
  -25.626087;50.111229;
  -25.848541;50.939781;
  -26.080696;50.596329;
  -26.429300;51.406593;
  -26.661455;51.063141;
  -27.073246;51.804508;
  -27.305401;51.461056;
  -27.012581;50.770954;
  -27.244736;50.427502;;
 }
}