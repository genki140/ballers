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
 128;
 -192.78020;176.75800;63.35630;,
 -191.41960;176.48730;63.35630;,
 -192.64709;173.52390;-127.29150;,
 -192.78020;173.55040;-127.29150;,
 -190.26601;175.71671;63.35630;,
 -192.53419;173.44850;-127.29150;,
 -189.49530;174.56310;63.35630;,
 -192.45880;173.33560;-127.29150;,
 -189.22470;173.20250;63.35630;,
 -192.43230;173.20250;-127.29150;,
 -189.49530;171.84180;63.35630;,
 -192.45880;173.06940;-127.29150;,
 -190.26601;170.68829;63.35630;,
 -192.53419;172.95650;-127.29150;,
 -191.41960;169.91760;63.35640;,
 -192.64709;172.88100;-127.29150;,
 -192.78020;169.64700;63.35640;,
 -192.78020;172.85451;-127.29150;,
 -194.14090;169.91760;63.35640;,
 -192.91330;172.88100;-127.29150;,
 -195.29440;170.68829;63.35640;,
 -193.02620;172.95650;-127.29150;,
 -196.06509;171.84180;63.35640;,
 -193.10170;173.06940;-127.29150;,
 -196.33569;173.20250;63.35640;,
 -193.12820;173.20250;-127.29150;,
 -196.06509;174.56310;63.35640;,
 -193.10170;173.33560;-127.29150;,
 -195.29440;175.71671;63.35630;,
 -193.02620;173.44850;-127.29150;,
 -194.14090;176.48730;63.35630;,
 -192.91330;173.52390;-127.29150;,
 -181.67470;165.92461;63.35630;,
 -180.31400;165.65401;63.35630;,
 -181.54150;162.69060;-127.29150;,
 -181.67470;162.71710;-127.29150;,
 -179.16051;164.88330;63.35630;,
 -181.42860;162.61510;-127.29150;,
 -178.38980;163.72971;63.35630;,
 -181.35320;162.50220;-127.29150;,
 -178.11920;162.36909;63.35630;,
 -181.32671;162.36909;-127.29150;,
 -178.38980;161.00850;63.35630;,
 -181.35320;162.23599;-127.29150;,
 -179.16051;159.85490;63.35630;,
 -181.42860;162.12309;-127.29150;,
 -180.31400;159.08420;63.35640;,
 -181.54150;162.04761;-127.29150;,
 -181.67461;158.81360;63.35640;,
 -181.67461;162.02119;-127.29150;,
 -183.03529;159.08420;63.35640;,
 -181.80780;162.04761;-127.29150;,
 -184.18880;159.85490;63.35640;,
 -181.92070;162.12309;-127.29150;,
 -184.95950;161.00850;63.35640;,
 -181.99609;162.23599;-127.29150;,
 -185.23019;162.36909;63.35640;,
 -182.02260;162.36909;-127.29150;,
 -184.95950;163.72971;63.35640;,
 -181.99609;162.50220;-127.29150;,
 -184.18880;164.88330;63.35630;,
 -181.92070;162.61510;-127.29150;,
 -183.03529;165.65401;63.35630;,
 -181.80780;162.69060;-127.29150;,
 -203.83130;165.92461;63.35630;,
 -202.47070;165.65401;63.35630;,
 -203.69820;162.69060;-127.29150;,
 -203.83130;162.71710;-127.29150;,
 -201.31709;164.88330;63.35630;,
 -203.58530;162.61510;-127.29150;,
 -200.54649;163.72971;63.35630;,
 -203.50990;162.50220;-127.29150;,
 -200.27580;162.36909;63.35630;,
 -203.48340;162.36909;-127.29150;,
 -200.54649;161.00850;63.35630;,
 -203.50990;162.23599;-127.29150;,
 -201.31709;159.85490;63.35630;,
 -203.58530;162.12309;-127.29150;,
 -202.47070;159.08420;63.35640;,
 -203.69820;162.04761;-127.29150;,
 -203.83130;158.81360;63.35640;,
 -203.83130;162.02119;-127.29150;,
 -205.19200;159.08420;63.35640;,
 -203.96449;162.04761;-127.29150;,
 -206.34550;159.85490;63.35640;,
 -204.07739;162.12309;-127.29150;,
 -207.11620;161.00850;63.35640;,
 -204.15280;162.23599;-127.29150;,
 -207.38680;162.36909;63.35640;,
 -204.17931;162.36909;-127.29150;,
 -207.11620;163.72971;63.35640;,
 -204.15280;162.50220;-127.29150;,
 -206.34550;164.88330;63.35630;,
 -204.07739;162.61510;-127.29150;,
 -205.19200;165.65401;63.35630;,
 -203.96449;162.69060;-127.29150;,
 -192.78020;154.45970;63.35630;,
 -191.41960;154.18910;63.35630;,
 -192.64709;151.22569;-127.29150;,
 -192.78020;151.25220;-127.29150;,
 -190.26601;153.41840;63.35630;,
 -192.53419;151.15030;-127.29150;,
 -189.49530;152.26489;63.35630;,
 -192.45880;151.03740;-127.29150;,
 -189.22470;150.90421;63.35630;,
 -192.43230;150.90421;-127.29150;,
 -189.49530;149.54359;63.35630;,
 -192.45880;150.77110;-127.29150;,
 -190.26601;148.39000;63.35630;,
 -192.53419;150.65820;-127.29150;,
 -191.41960;147.61940;63.35640;,
 -192.64709;150.58279;-127.29150;,
 -192.78020;147.34869;63.35640;,
 -192.78020;150.55630;-127.29150;,
 -194.14090;147.61940;63.35640;,
 -192.91330;150.58279;-127.29150;,
 -195.29440;148.39000;63.35640;,
 -193.02620;150.65820;-127.29150;,
 -196.06509;149.54359;63.35640;,
 -193.10170;150.77110;-127.29150;,
 -196.33569;150.90421;63.35640;,
 -193.12820;150.90421;-127.29150;,
 -196.06509;152.26489;63.35640;,
 -193.10170;151.03740;-127.29150;,
 -195.29440;153.41840;63.35630;,
 -193.02620;151.15030;-127.29150;,
 -194.14090;154.18910;63.35630;,
 -192.91330;151.22569;-127.29150;;
 
 64;
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
 4;30,0,3,31;,
 4;32,33,34,35;,
 4;33,36,37,34;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 4;50,52,53,51;,
 4;52,54,55,53;,
 4;54,56,57,55;,
 4;56,58,59,57;,
 4;58,60,61,59;,
 4;60,62,63,61;,
 4;62,32,35,63;,
 4;64,65,66,67;,
 4;65,68,69,66;,
 4;68,70,71,69;,
 4;70,72,73,71;,
 4;72,74,75,73;,
 4;74,76,77,75;,
 4;76,78,79,77;,
 4;78,80,81,79;,
 4;80,82,83,81;,
 4;82,84,85,83;,
 4;84,86,87,85;,
 4;86,88,89,87;,
 4;88,90,91,89;,
 4;90,92,93,91;,
 4;92,94,95,93;,
 4;94,64,67,95;,
 4;96,97,98,99;,
 4;97,100,101,98;,
 4;100,102,103,101;,
 4;102,104,105,103;,
 4;104,106,107,105;,
 4;106,108,109,107;,
 4;108,110,111,109;,
 4;110,112,113,111;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 4;120,122,123,121;,
 4;122,124,125,123;,
 4;124,126,127,125;,
 4;126,96,99,127;;
 
 MeshMaterialList {
  10;
  64;
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
  5,
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
   0.984000;0.969000;1.000000;;
   TextureFilename {
    "Gurabi.bmp";
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
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Izigen.bmp";
   }
  }
 }
 MeshNormals {
  64;
  0.000004;0.999858;-0.016822;,
  0.382595;0.923763;-0.016822;,
  0.706997;0.707017;-0.016824;,
  0.923763;0.382594;-0.016822;,
  0.999858;0.000004;-0.016822;,
  0.923761;-0.382600;-0.016822;,
  0.707114;-0.706899;-0.016823;,
  0.382718;-0.923712;-0.016823;,
  0.000004;-0.999858;-0.016822;,
  -0.382724;-0.923710;-0.016823;,
  -0.707007;-0.707007;-0.016823;,
  -0.923699;-0.382749;-0.016823;,
  -0.999858;0.000004;-0.016823;,
  -0.923702;0.382742;-0.016823;,
  -0.706889;0.707124;-0.016823;,
  -0.382600;0.923761;-0.016822;,
  -0.000037;0.999859;-0.016822;,
  0.382722;0.923710;-0.016822;,
  0.707113;0.706900;-0.016822;,
  0.923765;0.382591;-0.016822;,
  0.999858;-0.000001;-0.016822;,
  0.923765;-0.382591;-0.016822;,
  0.707097;-0.706917;-0.016822;,
  0.382581;-0.923769;-0.016822;,
  0.000035;-0.999858;-0.016821;,
  -0.382547;-0.923783;-0.016823;,
  -0.707112;-0.706901;-0.016822;,
  -0.923757;-0.382610;-0.016822;,
  -0.999858;-0.000001;-0.016823;,
  -0.923757;0.382609;-0.016822;,
  -0.707129;0.706884;-0.016822;,
  -0.382755;0.923697;-0.016822;,
  0.000037;0.999859;-0.016822;,
  0.382745;0.923701;-0.016822;,
  0.707133;0.706881;-0.016822;,
  0.923763;0.382595;-0.016822;,
  0.999858;-0.000001;-0.016822;,
  0.923763;-0.382595;-0.016822;,
  0.707116;-0.706898;-0.016823;,
  0.382570;-0.923773;-0.016822;,
  0.000037;-0.999859;-0.016821;,
  -0.382547;-0.923783;-0.016822;,
  -0.707097;-0.706916;-0.016822;,
  -0.923755;-0.382615;-0.016822;,
  -0.999859;-0.000001;-0.016823;,
  -0.923755;0.382614;-0.016822;,
  -0.707114;0.706899;-0.016822;,
  -0.382721;0.923711;-0.016822;,
  0.000004;0.999859;-0.016822;,
  0.382595;0.923763;-0.016822;,
  0.707000;0.707013;-0.016823;,
  0.923773;0.382570;-0.016823;,
  0.999858;-0.000036;-0.016823;,
  0.923763;-0.382595;-0.016822;,
  0.707012;-0.707002;-0.016823;,
  0.382594;-0.923764;-0.016822;,
  0.000004;-0.999858;-0.016823;,
  -0.382599;-0.923761;-0.016822;,
  -0.706904;-0.707109;-0.016823;,
  -0.923701;-0.382744;-0.016823;,
  -0.999859;-0.000036;-0.016822;,
  -0.923712;0.382719;-0.016822;,
  -0.706893;0.707120;-0.016822;,
  -0.382600;0.923761;-0.016822;;
  64;
  4;0,1,1,0;,
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
  4;15,0,0,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;22,23,23,22;,
  4;23,24,24,23;,
  4;24,25,25,24;,
  4;25,26,26,25;,
  4;26,27,27,26;,
  4;27,28,28,27;,
  4;28,29,29,28;,
  4;29,30,30,29;,
  4;30,31,31,30;,
  4;31,16,16,31;,
  4;32,33,33,32;,
  4;33,34,34,33;,
  4;34,35,35,34;,
  4;35,36,36,35;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;38,39,39,38;,
  4;39,40,40,39;,
  4;40,41,41,40;,
  4;41,42,42,41;,
  4;42,43,43,42;,
  4;43,44,44,43;,
  4;44,45,45,44;,
  4;45,46,46,45;,
  4;46,47,47,46;,
  4;47,32,32,47;,
  4;48,49,49,48;,
  4;49,50,50,49;,
  4;50,51,51,50;,
  4;51,52,52,51;,
  4;52,53,53,52;,
  4;53,54,54,53;,
  4;54,55,55,54;,
  4;55,56,56,55;,
  4;56,57,57,56;,
  4;57,58,58,57;,
  4;58,59,59,58;,
  4;59,60,60,59;,
  4;60,61,61,60;,
  4;61,62,62,61;,
  4;62,63,63,62;,
  4;63,48,48,63;;
 }
 MeshTextureCoords {
  128;
  -1.416430;-7.485830;
  -1.403550;-7.485320;
  -1.423750;5.005090;
  -1.425010;5.005040;
  -1.392610;-7.484810;
  -1.422680;5.005140;
  -1.385260;-7.484370;
  -1.421960;5.005180;
  -1.382630;-7.484070;
  -1.421700;5.005210;
  -1.385110;-7.483940;
  -1.421940;5.005220;
  -1.392330;-7.484020;
  -1.422650;5.005210;
  -1.403190;-7.484290;
  -1.423710;5.005190;
  -1.416030;-7.484710;
  -1.424970;5.005150;
  -1.428900;-7.485220;
  -1.426230;5.005100;
  -1.439850;-7.485730;
  -1.427300;5.005050;
  -1.447190;-7.486170;
  -1.428020;5.005000;
  -1.449830;-7.486470;
  -1.428280;5.004970;
  -1.447350;-7.486600;
  -1.428030;5.004960;
  -1.440130;-7.486520;
  -1.427330;5.004970;
  -1.429270;-7.486250;
  -1.426270;5.005000;
  -1.416430;-7.485830;
  -1.403550;-7.485320;
  -1.423750;5.005090;
  -1.425010;5.005040;
  -1.392610;-7.484810;
  -1.422680;5.005140;
  -1.385260;-7.484370;
  -1.421960;5.005180;
  -1.382630;-7.484070;
  -1.421700;5.005210;
  -1.385110;-7.483940;
  -1.421940;5.005220;
  -1.392330;-7.484020;
  -1.422650;5.005210;
  -1.403190;-7.484290;
  -1.423710;5.005190;
  -1.416030;-7.484710;
  -1.424970;5.005150;
  -1.428900;-7.485220;
  -1.426230;5.005100;
  -1.439850;-7.485730;
  -1.427300;5.005050;
  -1.447190;-7.486170;
  -1.428020;5.005000;
  -1.449830;-7.486470;
  -1.428280;5.004970;
  -1.447350;-7.486600;
  -1.428030;5.004960;
  -1.440130;-7.486520;
  -1.427330;5.004970;
  -1.429270;-7.486250;
  -1.426270;5.005000;
  -1.416430;-7.485830;
  -1.403550;-7.485320;
  -1.423750;5.005090;
  -1.425010;5.005040;
  -1.392610;-7.484810;
  -1.422680;5.005140;
  -1.385260;-7.484370;
  -1.421960;5.005180;
  -1.382630;-7.484070;
  -1.421700;5.005210;
  -1.385110;-7.483940;
  -1.421940;5.005220;
  -1.392330;-7.484020;
  -1.422650;5.005210;
  -1.403190;-7.484290;
  -1.423710;5.005190;
  -1.416030;-7.484710;
  -1.424970;5.005150;
  -1.428900;-7.485220;
  -1.426230;5.005100;
  -1.439850;-7.485730;
  -1.427300;5.005050;
  -1.447190;-7.486170;
  -1.428020;5.005000;
  -1.449830;-7.486470;
  -1.428280;5.004970;
  -1.447350;-7.486600;
  -1.428030;5.004960;
  -1.440130;-7.486520;
  -1.427330;5.004970;
  -1.429270;-7.486250;
  -1.426270;5.005000;
  -1.416430;-7.485830;
  -1.403550;-7.485320;
  -1.423750;5.005090;
  -1.425010;5.005040;
  -1.392610;-7.484810;
  -1.422680;5.005140;
  -1.385260;-7.484370;
  -1.421960;5.005180;
  -1.382630;-7.484070;
  -1.421700;5.005210;
  -1.385110;-7.483940;
  -1.421940;5.005220;
  -1.392330;-7.484020;
  -1.422650;5.005210;
  -1.403190;-7.484290;
  -1.423710;5.005190;
  -1.416030;-7.484710;
  -1.424970;5.005150;
  -1.428900;-7.485220;
  -1.426230;5.005100;
  -1.439850;-7.485730;
  -1.427300;5.005050;
  -1.447190;-7.486170;
  -1.428020;5.005000;
  -1.449830;-7.486470;
  -1.428280;5.004970;
  -1.447350;-7.486600;
  -1.428030;5.004960;
  -1.440130;-7.486520;
  -1.427330;5.004970;
  -1.429270;-7.486250;
  -1.426270;5.005000;;
 }
}
