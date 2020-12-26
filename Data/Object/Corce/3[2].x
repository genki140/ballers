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
 277;
 408.79449;8.80590;-176.38541;,
 412.91620;8.80590;-174.67799;,
 412.91620;-0.29380;-174.67799;,
 408.79449;-0.29380;-176.38541;,
 414.62350;8.80590;-170.55640;,
 414.62350;-0.29380;-170.55640;,
 412.91620;8.80590;-166.43469;,
 412.91620;-0.29380;-166.43469;,
 408.79449;8.80590;-164.72740;,
 408.79449;-0.29380;-164.72740;,
 404.67261;8.80590;-166.43469;,
 404.67261;-0.29380;-166.43469;,
 402.96521;8.80590;-170.55640;,
 402.96521;-0.29380;-170.55640;,
 404.67261;8.80590;-174.67799;,
 404.67261;-0.29380;-174.67799;,
 408.79449;8.80590;-170.55640;,
 435.79721;9.75230;1.59370;,
 435.79721;7.69170;2.44720;,
 343.23111;7.69170;2.44720;,
 343.23111;9.75230;1.59370;,
 435.79721;6.83810;4.50780;,
 343.23111;6.83810;4.50780;,
 435.79721;7.69170;6.56840;,
 343.23111;7.69170;6.56840;,
 435.79721;9.75230;7.42200;,
 343.23111;9.75230;7.42200;,
 435.79721;11.81290;6.56840;,
 343.23111;11.81290;6.56840;,
 435.79721;12.66640;4.50780;,
 343.23111;12.66640;4.50780;,
 435.79721;11.81290;2.44720;,
 343.23111;11.81290;2.44720;,
 435.79721;9.75230;4.50780;,
 343.23111;9.75230;4.50780;,
 409.44131;3.02850;28.43460;,
 409.44131;0.96790;29.28820;,
 376.17569;0.96790;29.28820;,
 376.17569;3.02850;28.43460;,
 409.44131;0.11430;31.34880;,
 376.17569;0.11430;31.34880;,
 409.44131;0.96790;33.40940;,
 376.17569;0.96790;33.40940;,
 409.44131;3.02850;34.26290;,
 376.17569;3.02850;34.26290;,
 409.44131;5.08910;33.40940;,
 376.17569;5.08910;33.40940;,
 409.44131;5.94260;31.34880;,
 376.17569;5.94260;31.34880;,
 409.44131;5.08910;29.28820;,
 376.17569;5.08910;29.28820;,
 409.44131;3.02850;31.34880;,
 376.17569;3.02850;31.34880;,
 407.03049;4.04470;-16.86870;,
 406.28922;1.27840;-15.68240;,
 337.36920;19.74550;-15.68240;,
 338.11029;22.51180;-16.86870;,
 405.98239;0.13250;-12.81850;,
 337.06219;18.59970;-12.81850;,
 406.28922;1.27840;-9.95460;,
 337.36920;19.74550;-9.95460;,
 407.03049;4.04470;-8.76820;,
 338.11029;22.51180;-8.76820;,
 407.77170;6.81100;-9.95460;,
 338.85172;25.27810;-9.95460;,
 408.07870;7.95680;-12.81850;,
 339.15851;26.42390;-12.81850;,
 407.77170;6.81100;-15.68240;,
 338.85172;25.27810;-15.68240;,
 407.03049;4.04470;-12.81850;,
 338.11029;22.51180;-12.81850;,
 417.32101;24.82040;-55.51350;,
 418.61780;23.21890;-54.65990;,
 390.86938;0.74880;-54.65990;,
 389.57260;2.35010;-55.51350;,
 419.15500;22.55560;-52.59930;,
 391.40649;0.08540;-52.59930;,
 418.61780;23.21890;-50.53870;,
 390.86938;0.74880;-50.53870;,
 417.32101;24.82040;-49.68520;,
 389.57260;2.35010;-49.68520;,
 416.02420;26.42170;-50.53870;,
 388.27579;3.95160;-50.53870;,
 415.48709;27.08510;-52.59930;,
 387.73859;4.61480;-52.59930;,
 416.02420;26.42170;-54.65990;,
 388.27579;3.95160;-54.65990;,
 417.32101;24.82040;-52.59930;,
 389.57260;2.35010;-52.59930;,
 384.73721;2.19490;-80.78970;,
 388.35751;2.19490;-79.29010;,
 388.35751;0.01060;-79.29010;,
 384.73721;0.01060;-80.78970;,
 389.85739;2.19490;-75.66970;,
 389.85739;0.01060;-75.66970;,
 388.35751;2.19490;-72.04930;,
 388.35751;0.01060;-72.04930;,
 384.73721;2.19490;-70.54960;,
 384.73721;0.01060;-70.54960;,
 381.11679;2.19490;-72.04930;,
 381.11679;0.01060;-72.04930;,
 379.61700;2.19490;-75.66970;,
 379.61700;0.01060;-75.66970;,
 381.11679;2.19490;-79.29010;,
 381.11679;0.01060;-79.29010;,
 384.73721;2.19490;-75.66970;,
 407.06821;13.43060;-78.91620;,
 409.43759;13.43060;-77.93470;,
 409.43759;-1.40490;-77.93470;,
 407.06821;-1.40490;-78.91620;,
 410.41910;13.43060;-75.56530;,
 410.41910;-1.40490;-75.56530;,
 409.43759;13.43060;-73.19590;,
 409.43759;-1.40490;-73.19590;,
 407.06821;13.43060;-72.21440;,
 407.06821;-1.40490;-72.21440;,
 404.69870;13.43060;-73.19590;,
 404.69870;-1.40490;-73.19590;,
 403.71719;13.43060;-75.56530;,
 403.71719;-1.40490;-75.56530;,
 404.69870;13.43060;-77.93470;,
 404.69870;-1.40490;-77.93470;,
 407.06821;13.43060;-75.56530;,
 389.28189;5.10950;-100.42860;,
 392.90219;5.10950;-98.92890;,
 392.90219;0.01060;-98.92890;,
 389.28189;0.01060;-100.42860;,
 394.40201;5.10950;-95.30860;,
 394.40201;0.01060;-95.30860;,
 392.90219;5.10950;-91.68820;,
 392.90219;0.01060;-91.68820;,
 389.28189;5.10950;-90.18850;,
 389.28189;0.01060;-90.18850;,
 385.66141;5.10950;-91.68820;,
 385.66141;0.01060;-91.68820;,
 384.16171;5.10950;-95.30860;,
 384.16171;0.01060;-95.30860;,
 385.66141;5.10950;-98.92890;,
 385.66141;0.01060;-98.92890;,
 389.28189;5.10950;-95.30860;,
 411.08569;20.85570;-110.77790;,
 414.70609;20.85570;-109.27830;,
 414.70609;0.01060;-109.27830;,
 411.08569;0.01060;-110.77790;,
 416.20599;20.85570;-105.65790;,
 416.20599;0.01060;-105.65790;,
 414.70609;20.85570;-102.03750;,
 414.70609;0.01060;-102.03750;,
 411.08569;20.85570;-100.53780;,
 411.08569;0.01060;-100.53780;,
 407.46530;20.85570;-102.03750;,
 407.46530;0.01060;-102.03750;,
 405.96552;20.85570;-105.65790;,
 405.96552;0.01060;-105.65790;,
 407.46530;20.85570;-109.27830;,
 407.46530;0.01060;-109.27830;,
 411.08569;20.85570;-105.65790;,
 389.52780;8.57490;-120.49440;,
 393.14819;8.57490;-118.99480;,
 393.14819;0.01060;-118.99480;,
 389.52780;0.01060;-120.49440;,
 394.64789;8.57490;-115.37440;,
 394.64789;0.01060;-115.37440;,
 393.14819;8.57490;-111.75400;,
 393.14819;0.01060;-111.75400;,
 389.52780;8.57490;-110.25430;,
 389.52780;0.03290;-110.25430;,
 385.90750;8.57490;-111.75400;,
 385.90750;0.01060;-111.75400;,
 384.40759;8.57490;-115.37440;,
 384.40759;0.01060;-115.37440;,
 385.90750;8.57490;-118.99480;,
 385.90750;0.01060;-118.99480;,
 389.52780;8.57490;-115.37440;,
 389.79169;11.74190;-142.81340;,
 393.41220;11.74190;-141.31371;,
 393.41220;0.01060;-141.31371;,
 389.79169;0.01060;-142.81340;,
 394.91190;11.74190;-137.69341;,
 394.91190;0.01060;-137.69341;,
 393.41220;11.74190;-134.07291;,
 393.41220;0.01060;-134.07291;,
 389.79169;11.74190;-132.57330;,
 389.79169;0.03290;-132.57330;,
 386.17139;11.74190;-134.07291;,
 386.17139;0.01060;-134.07291;,
 384.67160;11.74190;-137.69341;,
 384.67160;0.01060;-137.69341;,
 386.17139;11.74190;-141.31371;,
 386.17139;0.01060;-141.31371;,
 389.79169;11.74190;-137.69341;,
 390.34119;8.80590;-45.88410;,
 394.46310;8.80590;-44.17670;,
 394.46310;-0.29380;-44.17670;,
 390.34119;-0.29380;-45.88410;,
 396.17041;8.80590;-40.05510;,
 396.17041;-0.29380;-40.05510;,
 394.46310;8.80590;-35.93340;,
 394.46310;-0.29380;-35.93340;,
 390.34119;8.80590;-34.22610;,
 390.34119;-0.29380;-34.22610;,
 386.21951;8.80590;-35.93340;,
 386.21951;-0.29380;-35.93340;,
 384.51230;8.80590;-40.05510;,
 384.51230;-0.29380;-40.05510;,
 386.21951;8.80590;-44.17670;,
 386.21951;-0.29380;-44.17670;,
 390.34119;8.80590;-40.05510;,
 407.60391;8.80590;-135.71370;,
 411.72559;8.80590;-134.00630;,
 411.72559;-0.29380;-134.00630;,
 407.60391;-0.29380;-135.71370;,
 413.43289;8.80590;-129.88470;,
 413.43289;-0.29380;-129.88470;,
 411.72559;8.80590;-125.76300;,
 411.72559;-0.29380;-125.76300;,
 407.60391;8.80590;-124.05570;,
 407.60391;-0.29380;-124.05570;,
 403.48199;8.80590;-125.76300;,
 403.48199;-0.29380;-125.76300;,
 401.77460;8.80590;-129.88470;,
 401.77460;-0.29380;-129.88470;,
 403.48199;8.80590;-134.00630;,
 403.48199;-0.29380;-134.00630;,
 407.60391;8.80590;-129.88470;,
 381.88919;14.54860;-158.72000;,
 385.50961;14.54860;-157.22040;,
 385.50961;0.01060;-157.22040;,
 381.88919;0.01060;-158.72000;,
 387.00931;14.54860;-153.60001;,
 387.00931;0.01060;-153.60001;,
 385.50961;14.54860;-149.97960;,
 385.50961;0.01060;-149.97960;,
 381.88919;14.54860;-148.47990;,
 381.88919;0.03290;-148.47990;,
 378.26871;14.54860;-149.97960;,
 378.26871;0.01060;-149.97960;,
 376.76889;14.54860;-153.60001;,
 376.76889;0.01060;-153.60001;,
 378.26871;14.54860;-157.22040;,
 378.26871;0.01060;-157.22040;,
 381.88919;14.54860;-153.60001;,
 395.24231;15.72180;-162.64281;,
 398.86270;15.72180;-161.14310;,
 398.86270;-1.16260;-161.14310;,
 395.24231;-1.16260;-162.64281;,
 400.36240;15.72180;-157.52280;,
 400.36240;-1.16260;-157.52280;,
 398.86270;15.72180;-153.90230;,
 398.86270;-1.16260;-153.90230;,
 395.24231;15.72180;-152.40260;,
 395.24231;-0.58100;-152.40260;,
 391.62189;15.72180;-153.90230;,
 391.62189;-1.16260;-153.90230;,
 390.12210;15.72180;-157.52280;,
 390.12210;-1.16260;-157.52280;,
 391.62189;15.72180;-161.14310;,
 391.62189;-1.16260;-161.14310;,
 395.24231;15.72180;-157.52280;,
 337.24219;25.05900;51.88320;,
 439.50031;61.27050;51.88320;,
 440.22690;59.21850;52.78490;,
 337.96881;23.00700;52.78490;,
 440.52802;58.36860;54.96170;,
 338.26990;22.15700;54.96170;,
 440.22690;59.21850;57.13840;,
 337.96881;23.00700;57.13840;,
 439.50031;61.27050;58.04010;,
 337.24219;25.05900;58.04010;,
 438.77371;63.32250;57.13840;,
 336.51550;27.11100;57.13840;,
 438.47269;64.17250;54.96170;,
 336.21439;27.96090;54.96170;,
 438.77371;63.32250;52.78490;,
 336.51550;27.11100;52.78490;,
 337.24219;25.05900;54.96170;,
 439.50031;61.27050;54.96170;;
 
 296;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 3;16,1,0;,
 3;16,4,1;,
 3;16,6,4;,
 3;16,8,6;,
 3;16,10,8;,
 3;16,12,10;,
 3;16,14,12;,
 3;16,0,14;,
 4;17,18,19,20;,
 4;18,21,22,19;,
 4;21,23,24,22;,
 4;23,25,26,24;,
 4;25,27,28,26;,
 4;27,29,30,28;,
 4;29,31,32,30;,
 4;31,17,20,32;,
 3;33,18,17;,
 3;33,21,18;,
 3;33,23,21;,
 3;33,25,23;,
 3;33,27,25;,
 3;33,29,27;,
 3;33,31,29;,
 3;33,17,31;,
 3;34,20,19;,
 3;34,19,22;,
 3;34,22,24;,
 3;34,24,26;,
 3;34,26,28;,
 3;34,28,30;,
 3;34,30,32;,
 3;34,32,20;,
 4;35,36,37,38;,
 4;36,39,40,37;,
 4;39,41,42,40;,
 4;41,43,44,42;,
 4;43,45,46,44;,
 4;45,47,48,46;,
 4;47,49,50,48;,
 4;49,35,38,50;,
 3;51,36,35;,
 3;51,39,36;,
 3;51,41,39;,
 3;51,43,41;,
 3;51,45,43;,
 3;51,47,45;,
 3;51,49,47;,
 3;51,35,49;,
 3;52,38,37;,
 3;52,37,40;,
 3;52,40,42;,
 3;52,42,44;,
 3;52,44,46;,
 3;52,46,48;,
 3;52,48,50;,
 3;52,50,38;,
 4;53,54,55,56;,
 4;54,57,58,55;,
 4;57,59,60,58;,
 4;59,61,62,60;,
 4;61,63,64,62;,
 4;63,65,66,64;,
 4;65,67,68,66;,
 4;67,53,56,68;,
 3;69,54,53;,
 3;69,57,54;,
 3;69,59,57;,
 3;69,61,59;,
 3;69,63,61;,
 3;69,65,63;,
 3;69,67,65;,
 3;69,53,67;,
 3;70,56,55;,
 3;70,55,58;,
 3;70,58,60;,
 3;70,60,62;,
 3;70,62,64;,
 3;70,64,66;,
 3;70,66,68;,
 3;70,68,56;,
 4;71,72,73,74;,
 4;72,75,76,73;,
 4;75,77,78,76;,
 4;77,79,80,78;,
 4;79,81,82,80;,
 4;81,83,84,82;,
 4;83,85,86,84;,
 4;85,71,74,86;,
 3;87,72,71;,
 3;87,75,72;,
 3;87,77,75;,
 3;87,79,77;,
 3;87,81,79;,
 3;87,83,81;,
 3;87,85,83;,
 3;87,71,85;,
 3;88,74,73;,
 3;88,73,76;,
 3;88,76,78;,
 3;88,78,80;,
 3;88,80,82;,
 3;88,82,84;,
 3;88,84,86;,
 3;88,86,74;,
 4;89,90,91,92;,
 4;90,93,94,91;,
 4;93,95,96,94;,
 4;95,97,98,96;,
 4;97,99,100,98;,
 4;99,101,102,100;,
 4;101,103,104,102;,
 4;103,89,92,104;,
 3;105,90,89;,
 3;105,93,90;,
 3;105,95,93;,
 3;105,97,95;,
 3;105,99,97;,
 3;105,101,99;,
 3;105,103,101;,
 3;105,89,103;,
 4;106,107,108,109;,
 4;107,110,111,108;,
 4;110,112,113,111;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 4;120,106,109,121;,
 3;122,107,106;,
 3;122,110,107;,
 3;122,112,110;,
 3;122,114,112;,
 3;122,116,114;,
 3;122,118,116;,
 3;122,120,118;,
 3;122,106,120;,
 4;123,124,125,126;,
 4;124,127,128,125;,
 4;127,129,130,128;,
 4;129,131,132,130;,
 4;131,133,134,132;,
 4;133,135,136,134;,
 4;135,137,138,136;,
 4;137,123,126,138;,
 3;139,124,123;,
 3;139,127,124;,
 3;139,129,127;,
 3;139,131,129;,
 3;139,133,131;,
 3;139,135,133;,
 3;139,137,135;,
 3;139,123,137;,
 4;140,141,142,143;,
 4;141,144,145,142;,
 4;144,146,147,145;,
 4;146,148,149,147;,
 4;148,150,151,149;,
 4;150,152,153,151;,
 4;152,154,155,153;,
 4;154,140,143,155;,
 3;156,141,140;,
 3;156,144,141;,
 3;156,146,144;,
 3;156,148,146;,
 3;156,150,148;,
 3;156,152,150;,
 3;156,154,152;,
 3;156,140,154;,
 4;157,158,159,160;,
 4;158,161,162,159;,
 4;161,163,164,162;,
 4;163,165,166,164;,
 4;165,167,168,166;,
 4;167,169,170,168;,
 4;169,171,172,170;,
 4;171,157,160,172;,
 3;173,158,157;,
 3;173,161,158;,
 3;173,163,161;,
 3;173,165,163;,
 3;173,167,165;,
 3;173,169,167;,
 3;173,171,169;,
 3;173,157,171;,
 4;174,175,176,177;,
 4;175,178,179,176;,
 4;178,180,181,179;,
 4;180,182,183,181;,
 4;182,184,185,183;,
 4;184,186,187,185;,
 4;186,188,189,187;,
 4;188,174,177,189;,
 3;190,175,174;,
 3;190,178,175;,
 3;190,180,178;,
 3;190,182,180;,
 3;190,184,182;,
 3;190,186,184;,
 3;190,188,186;,
 3;190,174,188;,
 4;191,192,193,194;,
 4;192,195,196,193;,
 4;195,197,198,196;,
 4;197,199,200,198;,
 4;199,201,202,200;,
 4;201,203,204,202;,
 4;203,205,206,204;,
 4;205,191,194,206;,
 3;207,192,191;,
 3;207,195,192;,
 3;207,197,195;,
 3;207,199,197;,
 3;207,201,199;,
 3;207,203,201;,
 3;207,205,203;,
 3;207,191,205;,
 4;208,209,210,211;,
 4;209,212,213,210;,
 4;212,214,215,213;,
 4;214,216,217,215;,
 4;216,218,219,217;,
 4;218,220,221,219;,
 4;220,222,223,221;,
 4;222,208,211,223;,
 3;224,209,208;,
 3;224,212,209;,
 3;224,214,212;,
 3;224,216,214;,
 3;224,218,216;,
 3;224,220,218;,
 3;224,222,220;,
 3;224,208,222;,
 4;225,226,227,228;,
 4;226,229,230,227;,
 4;229,231,232,230;,
 4;231,233,234,232;,
 4;233,235,236,234;,
 4;235,237,238,236;,
 4;237,239,240,238;,
 4;239,225,228,240;,
 3;241,226,225;,
 3;241,229,226;,
 3;241,231,229;,
 3;241,233,231;,
 3;241,235,233;,
 3;241,237,235;,
 3;241,239,237;,
 3;241,225,239;,
 4;242,243,244,245;,
 4;243,246,247,244;,
 4;246,248,249,247;,
 4;248,250,251,249;,
 4;250,252,253,251;,
 4;252,254,255,253;,
 4;254,256,257,255;,
 4;256,242,245,257;,
 3;258,243,242;,
 3;258,246,243;,
 3;258,248,246;,
 3;258,250,248;,
 3;258,252,250;,
 3;258,254,252;,
 3;258,256,254;,
 3;258,242,256;,
 4;259,260,261,262;,
 4;262,261,263,264;,
 4;264,263,265,266;,
 4;266,265,267,268;,
 4;268,267,269,270;,
 4;270,269,271,272;,
 4;272,271,273,274;,
 4;274,273,260,259;,
 3;275,259,262;,
 3;275,262,264;,
 3;275,264,266;,
 3;275,266,268;,
 3;275,268,270;,
 3;275,270,272;,
 3;275,272,274;,
 3;275,274,259;,
 3;276,261,260;,
 3;276,263,261;,
 3;276,265,263;,
 3;276,267,265;,
 3;276,269,267;,
 3;276,271,269;,
 3;276,273,271;,
 3;276,260,273;;
 
 MeshMaterialList {
  7;
  296;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ki.bmp";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ground1.bmp";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "��.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "�w�i1.bmp";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Maruta.bmp";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "tree.tga";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Maruta.bmp";
   }
  }
 }
 MeshNormals {
  172;
  0.000000;1.000000;0.000000;,
  0.000008;0.000000;-1.000000;,
  0.707111;0.000000;-0.707102;,
  1.000000;0.000000;-0.000005;,
  0.707106;0.000000;0.707108;,
  0.000008;0.000000;1.000000;,
  -0.707093;0.000000;0.707120;,
  -1.000000;0.000000;-0.000005;,
  -0.707099;0.000000;-0.707114;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-0.707092;-0.707121;,
  0.000000;-1.000000;0.000000;,
  0.000000;-0.707107;0.707107;,
  0.000000;0.000000;1.000000;,
  0.000000;0.707121;0.707092;,
  0.000000;1.000000;0.000000;,
  0.000000;0.707107;-0.707107;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-0.707107;-0.707107;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.707092;0.707121;,
  0.000000;0.000000;1.000000;,
  0.000000;0.707107;0.707107;,
  0.000000;0.707121;-0.707092;,
  0.965928;-0.258810;0.000000;,
  -0.000001;-0.000002;-1.000000;,
  -0.183015;-0.683020;-0.707099;,
  -0.258820;-0.965926;0.000000;,
  -0.183018;-0.683030;0.707089;,
  -0.000001;-0.000002;1.000000;,
  0.183019;0.683034;0.707085;,
  0.258819;0.965926;0.000000;,
  0.183016;0.683024;-0.707096;,
  -0.965927;0.258814;0.000000;,
  0.777145;0.629321;0.000000;,
  0.000001;-0.000001;-1.000000;,
  0.444999;-0.549529;-0.707102;,
  0.629319;-0.777147;-0.000000;,
  0.444989;-0.549518;0.707117;,
  0.000001;-0.000001;1.000000;,
  -0.444993;0.549521;0.707112;,
  -0.629319;0.777147;0.000000;,
  -0.445002;0.549533;-0.707098;,
  -0.777142;-0.629326;0.000000;,
  0.000006;0.000000;-1.000000;,
  0.707087;0.000000;-0.707126;,
  0.707096;0.000000;0.707118;,
  0.000006;0.000000;1.000000;,
  -0.707099;0.000000;0.707115;,
  -0.707091;0.000000;-0.707123;,
  0.000009;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  0.000009;0.000000;1.000000;,
  -0.707100;0.000000;0.707113;,
  -1.000000;0.000000;0.000000;,
  -0.707100;0.000000;-0.707113;,
  0.000009;0.000000;-1.000000;,
  0.707097;0.000000;-0.707117;,
  1.000000;0.000000;-0.000005;,
  0.707101;0.000000;0.707113;,
  0.000009;0.000000;1.000000;,
  -0.707105;0.000000;0.707109;,
  -1.000000;0.000000;-0.000005;,
  -0.707100;0.000000;-0.707113;,
  0.000000;0.000000;-1.000000;,
  0.707082;0.000000;-0.707132;,
  0.707089;0.000000;0.707124;,
  0.000000;0.000000;1.000000;,
  -0.707099;0.000000;0.707114;,
  -0.707092;0.000000;-0.707122;,
  -0.000004;0.000000;-1.000000;,
  0.707099;0.000000;-0.707114;,
  0.707107;0.000000;0.707106;,
  -0.000004;0.000000;1.000000;,
  -0.707092;0.000000;0.707121;,
  -0.707085;0.000000;-0.707129;,
  -0.000010;0.000000;-1.000000;,
  0.707099;0.000000;-0.707114;,
  1.000000;0.000000;-0.000010;,
  0.707099;0.000000;0.707115;,
  -0.000010;0.000000;1.000000;,
  -0.707098;0.000000;0.707115;,
  -1.000000;0.000000;-0.000010;,
  -0.707099;0.000000;-0.707114;,
  -0.000010;0.000000;-1.000000;,
  0.707104;0.000000;-0.707109;,
  1.000000;0.000000;-0.000004;,
  0.707100;0.000000;0.707114;,
  -0.000010;0.000000;1.000000;,
  -0.707114;0.000000;0.707100;,
  -1.000000;0.000000;-0.000004;,
  -0.707118;0.000000;-0.707095;,
  0.000010;0.000000;-1.000000;,
  0.707111;0.000000;-0.707102;,
  0.707107;0.000000;0.707106;,
  0.000010;0.000000;1.000000;,
  -0.707093;0.000000;0.707121;,
  -0.707097;0.000000;-0.707117;,
  0.000003;0.000000;-1.000000;,
  0.707098;0.000000;-0.707115;,
  1.000000;0.000000;-0.000001;,
  0.707106;0.000000;0.707107;,
  0.000003;0.000000;1.000000;,
  -0.707094;0.000000;0.707120;,
  -1.000000;0.000000;-0.000001;,
  -0.707086;0.000000;-0.707128;,
  0.000002;0.000000;-1.000000;,
  0.707105;0.000000;-0.707109;,
  1.000000;0.000000;-0.000010;,
  0.707110;0.000000;0.707103;,
  0.000001;0.000000;1.000000;,
  -0.707102;0.000000;0.707112;,
  -1.000000;0.000000;-0.000010;,
  -0.707096;0.000000;-0.707117;,
  -0.942635;-0.333825;0.000000;,
  0.000000;-0.000001;-1.000000;,
  0.236036;-0.666544;-0.707111;,
  0.333807;-0.942641;0.000008;,
  0.236034;-0.666539;0.707116;,
  0.000000;-0.000001;1.000000;,
  -0.236034;0.666540;0.707116;,
  -0.333807;0.942641;0.000008;,
  -0.236036;0.666545;-0.707110;,
  0.942644;0.333799;0.000000;,
  0.965929;-0.258806;-0.000028;,
  0.965925;-0.258823;-0.000000;,
  0.965937;-0.258779;0.000000;,
  0.965929;-0.258806;0.000028;,
  0.965925;-0.258824;-0.000000;,
  0.965927;-0.258813;-0.000000;,
  0.965928;-0.258813;-0.000000;,
  0.965927;-0.258813;0.000000;,
  -0.965923;0.258829;0.000000;,
  -0.965937;0.258779;-0.000006;,
  -0.965935;0.258785;0.000000;,
  -0.965937;0.258779;0.000006;,
  -0.965918;0.258848;0.000036;,
  -0.965928;0.258813;0.000000;,
  -0.965918;0.258848;-0.000036;,
  0.777157;0.629306;-0.000014;,
  0.777143;0.629324;0.000000;,
  0.777149;0.629317;0.000000;,
  0.777157;0.629306;0.000014;,
  0.777133;0.629337;0.000020;,
  0.777145;0.629322;0.000000;,
  0.777133;0.629337;-0.000020;,
  -0.777143;-0.629323;0.000000;,
  -0.777139;-0.629329;-0.000018;,
  -0.777150;-0.629315;0.000000;,
  -0.777139;-0.629329;0.000018;,
  -0.777144;-0.629322;0.000023;,
  -0.777130;-0.629341;0.000000;,
  -0.777144;-0.629322;-0.000023;,
  -0.942641;-0.333808;0.000000;,
  -0.942641;-0.333809;0.000015;,
  -0.942636;-0.333824;-0.000000;,
  -0.942641;-0.333810;-0.000015;,
  -0.942641;-0.333808;0.000000;,
  -0.942630;-0.333840;0.000021;,
  -0.942623;-0.333860;0.000000;,
  -0.942630;-0.333840;-0.000021;,
  0.942641;0.333808;-0.000027;,
  0.942650;0.333783;0.000000;,
  0.942632;0.333834;0.000000;,
  0.942641;0.333808;0.000027;,
  0.942647;0.333790;-0.000007;,
  0.942645;0.333797;-0.000000;,
  0.942647;0.333790;0.000007;;
  296;
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
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,10,10,17;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;22,23,23,22;,
  4;23,24,24,23;,
  4;24,0,0,24;,
  4;0,25,25,0;,
  4;25,19,19,25;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  3;18,18,18;,
  4;27,28,28,27;,
  4;28,29,29,28;,
  4;29,30,30,29;,
  4;30,31,31,30;,
  4;31,32,32,31;,
  4;32,33,33,32;,
  4;33,34,34,33;,
  4;34,27,27,34;,
  3;26,128,129;,
  3;26,130,128;,
  3;26,131,130;,
  3;26,132,131;,
  3;26,133,132;,
  3;26,134,133;,
  3;26,135,134;,
  3;26,129,135;,
  3;35,136,137;,
  3;35,137,138;,
  3;35,138,139;,
  3;35,139,136;,
  3;35,136,140;,
  3;35,140,141;,
  3;35,141,142;,
  3;35,142,136;,
  4;37,38,38,37;,
  4;38,39,39,38;,
  4;39,40,40,39;,
  4;40,41,41,40;,
  4;41,42,42,41;,
  4;42,43,43,42;,
  4;43,44,44,43;,
  4;44,37,37,44;,
  3;36,143,144;,
  3;36,145,143;,
  3;36,146,145;,
  3;36,144,146;,
  3;36,147,144;,
  3;36,148,147;,
  3;36,149,148;,
  3;36,144,149;,
  3;45,150,151;,
  3;45,151,152;,
  3;45,152,153;,
  3;45,153,150;,
  3;45,150,154;,
  3;45,154,155;,
  3;45,155,156;,
  3;45,156,150;,
  4;46,47,47,46;,
  4;47,9,9,47;,
  4;9,48,48,9;,
  4;48,49,49,48;,
  4;49,50,50,49;,
  4;50,18,18,50;,
  4;18,51,51,18;,
  4;51,46,46,51;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;52,53,53,52;,
  4;53,54,54,53;,
  4;54,55,55,54;,
  4;55,56,56,55;,
  4;56,57,57,56;,
  4;57,58,58,57;,
  4;58,59,59,58;,
  4;59,52,52,59;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;60,61,61,60;,
  4;61,62,62,61;,
  4;62,63,63,62;,
  4;63,64,64,63;,
  4;64,65,65,64;,
  4;65,66,66,65;,
  4;66,67,67,66;,
  4;67,60,60,67;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;68,69,69,68;,
  4;69,9,9,69;,
  4;9,70,70,9;,
  4;70,71,71,70;,
  4;71,72,72,71;,
  4;72,18,18,72;,
  4;18,73,73,18;,
  4;73,68,68,73;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;74,75,75,74;,
  4;75,9,9,75;,
  4;9,76,76,9;,
  4;76,77,77,76;,
  4;77,78,78,77;,
  4;78,18,18,78;,
  4;18,79,79,18;,
  4;79,74,74,79;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;80,81,81,80;,
  4;81,82,82,81;,
  4;82,83,83,82;,
  4;83,84,84,83;,
  4;84,85,85,84;,
  4;85,86,86,85;,
  4;86,87,87,86;,
  4;87,80,80,87;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;88,89,89,88;,
  4;89,90,90,89;,
  4;90,91,91,90;,
  4;91,92,92,91;,
  4;92,93,93,92;,
  4;93,94,94,93;,
  4;94,95,95,94;,
  4;95,88,88,95;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;96,97,97,96;,
  4;97,3,3,97;,
  4;3,98,98,3;,
  4;98,99,99,98;,
  4;99,100,100,99;,
  4;100,7,7,100;,
  4;7,101,101,7;,
  4;101,96,96,101;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;102,103,103,102;,
  4;103,104,104,103;,
  4;104,105,105,104;,
  4;105,106,106,105;,
  4;106,107,107,106;,
  4;107,108,108,107;,
  4;108,109,109,108;,
  4;109,102,102,109;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;110,111,111,110;,
  4;111,112,112,111;,
  4;112,113,113,112;,
  4;113,114,114,113;,
  4;114,115,115,114;,
  4;115,116,116,115;,
  4;116,117,117,116;,
  4;117,110,110,117;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;119,119,120,120;,
  4;120,120,121,121;,
  4;121,121,122,122;,
  4;122,122,123,123;,
  4;123,123,124,124;,
  4;124,124,125,125;,
  4;125,125,126,126;,
  4;126,126,119,119;,
  3;118,157,158;,
  3;118,158,159;,
  3;118,159,160;,
  3;118,160,161;,
  3;118,161,162;,
  3;118,162,163;,
  3;118,163,164;,
  3;118,164,157;,
  3;127,165,166;,
  3;127,167,165;,
  3;127,168,167;,
  3;127,166,168;,
  3;127,169,166;,
  3;127,170,169;,
  3;127,171,170;,
  3;127,166,171;;
 }
 MeshTextureCoords {
  277;
  23.257460;-4.281490;
  23.391649;-4.185420;
  23.590860;-3.834400;
  23.456671;-3.930480;
  23.352600;-4.006630;
  23.551809;-3.655610;
  23.163179;-3.849840;
  23.362391;-3.498830;
  22.934349;-3.806910;
  23.133560;-3.455890;
  22.800150;-3.902970;
  22.999359;-3.551960;
  22.839190;-4.081770;
  23.038401;-3.730750;
  23.028620;-4.238550;
  23.227831;-3.887530;
  23.095900;-4.044200;
  19.493019;3.101420;
  19.514469;3.215650;
  15.438040;2.619060;
  15.416590;2.504820;
  19.476049;3.332460;
  15.399620;2.735870;
  19.400249;3.383420;
  15.323820;2.786830;
  19.331480;3.338680;
  15.255050;2.742090;
  19.310030;3.224450;
  15.233600;2.627850;
  19.348459;3.107640;
  15.272030;2.511040;
  19.424259;3.056680;
  15.347820;2.460080;
  19.412251;3.220050;
  15.335820;2.623450;
  17.735630;4.283590;
  17.757080;4.397830;
  16.292130;4.183430;
  16.270679;4.069190;
  17.718660;4.514640;
  16.253700;4.300240;
  17.642860;4.565600;
  16.177910;4.351200;
  17.574089;4.520860;
  16.109140;4.306460;
  17.552641;4.406620;
  16.087681;4.192230;
  17.591070;4.289820;
  16.126110;4.075420;
  17.666861;4.238850;
  16.201910;4.024460;
  17.654860;4.402230;
  16.189911;4.187830;
  18.862841;2.384590;
  18.857880;2.534820;
  15.418500;1.378260;
  15.423450;1.228040;
  18.790079;2.693630;
  15.350680;1.537070;
  18.699129;2.767990;
  15.259740;1.611440;
  18.638330;2.714360;
  15.198940;1.557800;
  18.643290;2.564130;
  15.203910;1.407570;
  18.711109;2.405320;
  15.271720;1.248760;
  18.802050;2.330960;
  15.362660;1.174400;
  18.750589;2.549470;
  15.311200;1.392920;
  19.932280;0.076300;
  20.000790;0.181190;
  19.270710;0.869120;
  19.202209;0.764250;
  19.981859;0.294120;
  19.251780;0.982060;
  19.886570;0.348960;
  19.156490;1.036890;
  19.770741;0.313570;
  19.040670;1.001510;
  19.702230;0.208700;
  18.972160;0.896630;
  19.721170;0.095760;
  18.991091;0.783700;
  19.816460;0.040930;
  19.086380;0.728860;
  19.851509;0.194940;
  19.121441;0.882880;
  19.693220;-0.289900;
  19.811090;-0.205520;
  19.858910;-0.121270;
  19.741039;-0.205650;
  19.776800;-0.048470;
  19.824619;0.035790;
  19.610399;0.089240;
  19.658220;0.173500;
  19.409401;0.126960;
  19.457220;0.211220;
  19.291531;0.042580;
  19.339350;0.126840;
  19.325830;-0.114470;
  19.373650;-0.030210;
  19.492220;-0.252190;
  19.540039;-0.167930;
  19.551310;-0.081470;
  20.378740;-0.503120;
  20.455879;-0.447900;
  20.780649;0.124380;
  20.703510;0.069150;
  20.433430;-0.345110;
  20.758209;0.227160;
  20.324539;-0.254980;
  20.649309;0.317290;
  20.192989;-0.230300;
  20.517771;0.341970;
  20.115850;-0.285530;
  20.440620;0.286750;
  20.138290;-0.388310;
  20.463070;0.183970;
  20.247190;-0.478440;
  20.571960;0.093830;
  20.285870;-0.366710;
  20.373871;-1.172530;
  20.491730;-1.088140;
  20.603359;-0.891450;
  20.485491;-0.975840;
  20.457439;-0.931100;
  20.569059;-0.734410;
  20.291050;-0.793380;
  20.402670;-0.596690;
  20.090050;-0.755660;
  20.201670;-0.558970;
  19.972179;-0.840050;
  20.083799;-0.643360;
  20.006479;-0.997100;
  20.118099;-0.800410;
  20.172859;-1.134810;
  20.284479;-0.938120;
  20.231960;-0.964100;
  21.276190;-2.060720;
  21.394060;-1.976330;
  21.850401;-1.172240;
  21.732531;-1.256620;
  21.359770;-1.819280;
  21.816111;-1.015190;
  21.193380;-1.681570;
  21.649710;-0.877470;
  20.992380;-1.643850;
  21.448709;-0.839760;
  20.874510;-1.728230;
  21.330839;-0.924140;
  20.908800;-1.885280;
  21.365141;-1.081190;
  21.075190;-2.023000;
  21.531530;-1.218910;
  21.134279;-1.852280;
  20.864969;-2.121480;
  20.982849;-2.037100;
  21.170330;-1.706730;
  21.052460;-1.791120;
  20.948549;-1.880050;
  21.136040;-1.549690;
  20.782160;-1.742330;
  20.969650;-1.411970;
  20.581160;-1.704610;
  20.768160;-1.375110;
  20.463289;-1.789000;
  20.650780;-1.458630;
  20.497589;-1.946050;
  20.685070;-1.615680;
  20.663980;-2.083770;
  20.851471;-1.753400;
  20.723070;-1.913050;
  21.425859;-3.150530;
  21.543730;-3.066150;
  21.800550;-2.613620;
  21.682680;-2.698000;
  21.509439;-2.909100;
  21.766251;-2.456570;
  21.343050;-2.771380;
  21.599859;-2.318850;
  21.142040;-2.733670;
  21.398371;-2.282000;
  21.024179;-2.818050;
  21.280991;-2.365520;
  21.058470;-2.975100;
  21.315290;-2.522570;
  21.224859;-3.112820;
  21.481680;-2.660280;
  21.283951;-2.942100;
  18.827841;0.912180;
  18.962040;1.008250;
  19.161249;1.359270;
  19.027050;1.263190;
  18.922991;1.187040;
  19.122200;1.538060;
  18.733570;1.343830;
  18.932770;1.694840;
  18.504721;1.386760;
  18.703930;1.737780;
  18.370529;1.290700;
  18.569740;1.641710;
  18.409590;1.111900;
  18.608801;1.462920;
  18.599001;0.955120;
  18.798210;1.306140;
  18.666281;1.149470;
  22.077770;-2.633460;
  22.211960;-2.537380;
  22.411169;-2.186370;
  22.276979;-2.282440;
  22.172911;-2.358590;
  22.372120;-2.007580;
  21.983490;-2.201810;
  22.182699;-1.850790;
  21.754660;-2.158870;
  21.953871;-1.807850;
  21.620461;-2.254940;
  21.819670;-1.903920;
  21.659500;-2.433730;
  21.858709;-2.082710;
  21.848930;-2.590510;
  22.048140;-2.239500;
  21.916220;-2.396160;
  21.457270;-3.957280;
  21.575140;-3.872900;
  21.893410;-3.312100;
  21.775530;-3.396480;
  21.540850;-3.715850;
  21.859110;-3.155050;
  21.374460;-3.578130;
  21.692720;-3.017330;
  21.173460;-3.540410;
  21.491230;-2.980470;
  21.055580;-3.624800;
  21.373850;-3.064000;
  21.089880;-3.781850;
  21.408140;-3.221050;
  21.256269;-3.919570;
  21.574530;-3.358770;
  21.315359;-3.748850;
  22.128361;-4.076170;
  22.246229;-3.991780;
  22.615860;-3.340470;
  22.497990;-3.424860;
  22.211929;-3.834740;
  22.581560;-3.183430;
  22.045540;-3.697010;
  22.415171;-3.045700;
  21.844540;-3.659300;
  22.201441;-3.030420;
  21.726669;-3.743680;
  22.096300;-3.092370;
  21.760969;-3.900740;
  22.130600;-3.249430;
  21.927349;-4.038450;
  22.296989;-3.387140;
  21.986450;-3.867740;
  13.423930;3.923020;
  17.134451;3.185230;
  17.186380;3.305780;
  13.475860;4.043560;
  17.157909;3.429120;
  13.447400;4.166910;
  17.065710;3.483010;
  13.355200;4.220790;
  16.963800;3.435870;
  13.253290;4.173660;
  16.911869;3.315330;
  13.201350;4.053110;
  16.940340;3.191990;
  13.229820;3.929780;
  17.032539;3.138100;
  13.322020;3.875890;
  13.338610;4.048340;
  17.049120;3.310560;;
 }
}
