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
 194;
 197.18060;5.56310;57.54770;,
 200.15520;4.48210;56.95630;,
 200.15520;29.29270;16.71750;,
 197.18060;30.37370;17.30890;,
 201.38741;1.87260;55.52840;,
 201.38741;26.68330;15.28960;,
 200.15520;-0.73690;54.10050;,
 200.15520;24.07380;13.86170;,
 197.18060;-1.81770;53.50900;,
 197.18060;22.99290;13.27020;,
 194.20599;-0.73690;54.10050;,
 194.20599;24.07380;13.86170;,
 192.97380;1.87260;55.52840;,
 192.97380;26.68330;15.28960;,
 194.20599;4.48210;56.95630;,
 194.20599;29.29270;16.71750;,
 197.18060;1.87260;55.52840;,
 197.18060;26.68330;15.28960;,
 234.09720;17.04350;63.12510;,
 236.90669;16.48990;61.65330;,
 213.05000;4.94600;22.50830;,
 210.24049;5.49970;23.98020;,
 238.87650;13.95710;61.38580;,
 215.01981;2.41330;22.24090;,
 238.85260;10.92890;62.47940;,
 214.99590;-0.61490;23.33460;,
 236.84900;9.17920;64.29350;,
 212.99240;-2.36460;25.14860;,
 234.03960;9.73290;65.76540;,
 210.18291;-1.81090;26.62060;,
 232.06990;12.26570;66.03290;,
 208.21300;0.72190;26.88800;,
 232.09370;15.29390;64.93920;,
 208.23689;3.75000;25.79430;,
 235.47321;13.11140;63.70940;,
 211.61639;1.56750;24.56450;,
 240.78349;40.73010;30.64480;,
 243.87869;41.41230;31.21140;,
 250.69960;-3.83090;43.09620;,
 247.60451;-4.51320;42.52980;,
 245.54539;42.49050;33.74630;,
 252.36620;-2.75280;45.63130;,
 244.80721;43.33320;36.76480;,
 251.62790;-1.91010;48.64980;,
 242.09650;43.44670;38.49860;,
 248.91740;-1.79650;50.38360;,
 239.00140;42.76450;37.93210;,
 245.82220;-2.47870;49.81700;,
 237.33470;41.68630;35.39710;,
 244.15550;-3.55690;47.28210;,
 238.07300;40.84360;32.37860;,
 244.89371;-4.39970;44.26350;,
 241.44009;42.08850;34.57170;,
 248.26089;-3.15490;46.45660;,
 259.68729;-6.72740;11.39940;,
 262.78259;-6.08730;10.78570;,
 269.60349;0.59960;57.08350;,
 266.50830;-0.04050;57.69720;,
 264.44919;-3.44650;10.00140;,
 271.27011;3.24030;56.29920;,
 263.71100;-0.35210;9.50580;,
 270.53180;6.33490;55.80360;,
 261.00031;1.38350;9.58940;,
 267.82120;8.07030;55.88720;,
 257.90521;0.74340;10.20300;,
 264.72601;7.43030;56.50080;,
 256.23859;-1.89740;10.98720;,
 263.05939;4.78950;57.28510;,
 256.97681;-4.99190;11.48290;,
 263.79749;1.69500;57.78060;,
 260.34390;-2.67200;10.49430;,
 267.16470;4.01490;56.79220;,
 296.68829;45.28870;11.43370;,
 299.84521;44.86580;11.90580;,
 291.39581;-0.70940;21.19230;,
 288.23901;-0.28660;20.72020;,
 301.83179;45.16990;14.42130;,
 293.38229;-0.40510;23.70770;,
 301.48459;46.02280;17.50650;,
 293.03500;0.44780;26.79300;,
 299.00671;46.92490;19.35410;,
 290.55731;1.34960;28.64060;,
 295.85010;47.34770;18.88190;,
 287.40060;1.77260;28.16840;,
 293.86349;47.04360;16.36650;,
 285.41409;1.46830;25.65300;,
 294.21078;46.19070;13.28130;,
 285.76111;0.61560;22.56780;,
 297.84769;46.10680;15.39380;,
 289.39810;0.53150;24.68040;,
 271.32639;0.44560;34.89360;,
 273.39011;-1.26150;33.10630;,
 309.05179;21.20590;54.51140;,
 306.98840;22.91290;56.29860;,
 274.71161;-0.90660;30.19190;,
 310.37341;21.56070;51.59700;,
 274.51691;1.30210;27.85740;,
 310.17859;23.76950;49.26250;,
 272.92001;4.07110;27.47060;,
 308.58191;26.53840;48.87560;,
 270.85651;5.77810;29.25780;,
 306.51819;28.24550;50.66290;,
 269.53500;5.42330;32.17220;,
 305.19681;27.89070;53.57740;,
 269.72980;3.21440;34.50670;,
 305.39139;25.68190;55.91180;,
 272.12329;2.25830;31.18200;,
 307.78500;24.72570;52.58720;,
 261.58740;20.49290;-7.81850;,
 263.31421;21.00440;-10.48760;,
 300.05960;-0.21870;10.34690;,
 298.33301;-0.73040;13.01580;,
 265.13620;23.41790;-11.59260;,
 301.88171;2.19480;9.24200;,
 265.98679;26.31960;-10.48620;,
 302.73190;5.09640;10.34840;,
 265.36691;28.00950;-7.81650;,
 302.11249;6.78630;13.01790;,
 263.64020;27.49790;-5.14760;,
 300.38559;6.27470;15.68700;,
 261.81812;25.08440;-4.04260;,
 298.56381;3.86110;16.79190;,
 260.96790;22.18280;-5.14900;,
 297.71301;0.95960;15.68570;,
 263.47711;24.25120;-7.81760;,
 300.22269;3.02800;13.01700;,
 391.60269;42.26980;-99.56000;,
 394.78220;42.33520;-99.05550;,
 394.76349;-4.93690;-98.78260;,
 391.58429;-5.00250;-99.28710;,
 396.67139;42.50360;-96.45390;,
 396.65271;-4.76840;-96.18100;,
 396.16422;42.67630;-93.27900;,
 396.14520;-4.59570;-93.00610;,
 393.55710;42.75200;-91.39090;,
 393.53860;-4.52010;-91.11810;,
 390.37799;42.68660;-91.89550;,
 390.35919;-4.58550;-91.62260;,
 388.48859;42.51820;-94.49720;,
 388.47000;-4.75410;-94.22430;,
 388.99600;42.34550;-97.67200;,
 388.97720;-4.92660;-97.39900;,
 392.57999;42.51100;-95.47550;,
 360.00809;42.26980;-56.29210;,
 363.18759;42.33520;-55.78750;,
 363.16891;-4.93690;-55.51460;,
 359.98969;-5.00250;-56.01920;,
 365.07681;42.50360;-53.18590;,
 365.05801;-4.76840;-52.91300;,
 364.56949;42.67630;-50.01110;,
 364.55060;-4.59570;-49.73810;,
 361.96249;42.75200;-48.12300;,
 361.94391;-4.52010;-47.85010;,
 358.78329;42.68660;-48.62750;,
 358.76459;-4.58550;-48.35460;,
 356.89401;42.51820;-51.22920;,
 356.87540;-4.75410;-50.95630;,
 357.40140;42.34550;-54.40400;,
 357.38251;-4.92660;-54.13110;,
 360.98541;42.51100;-52.20750;,
 349.51450;42.26980;-25.48010;,
 352.69391;42.33520;-24.97550;,
 352.67529;-4.93690;-24.70260;,
 349.49609;-5.00250;-25.20720;,
 354.58310;42.50360;-22.37390;,
 354.56439;-4.76840;-22.10100;,
 354.07590;42.67630;-19.19910;,
 354.05701;-4.59570;-18.92620;,
 351.46881;42.75200;-17.31100;,
 351.45029;-4.52010;-17.03820;,
 348.28970;42.68660;-17.81550;,
 348.27100;-4.58550;-17.54260;,
 346.40039;42.51820;-20.41720;,
 346.38181;-4.75410;-20.14430;,
 346.90781;42.34550;-23.59200;,
 346.88901;-4.92660;-23.31910;,
 350.49179;42.51100;-21.39550;,
 373.66830;42.26980;-84.87600;,
 376.84781;42.33520;-84.37150;,
 376.82910;-4.93690;-84.09860;,
 373.64990;-5.00250;-84.60320;,
 378.73700;42.50360;-81.76990;,
 378.71820;-4.76840;-81.49700;,
 378.22971;42.67630;-78.59500;,
 378.21078;-4.59570;-78.32210;,
 375.62271;42.75200;-76.70690;,
 375.60410;-4.52010;-76.43410;,
 372.44351;42.68660;-77.21150;,
 372.42480;-4.58550;-76.93860;,
 370.55420;42.51820;-79.81320;,
 370.53561;-4.75410;-79.54030;,
 371.06161;42.34550;-82.98800;,
 371.04269;-4.92660;-82.71510;,
 374.64560;42.51100;-80.79150;;
 
 232;
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
 3;17,3,2;,
 3;17,2,5;,
 3;17,5,7;,
 3;17,7,9;,
 3;17,9,11;,
 3;17,11,13;,
 3;17,13,15;,
 3;17,15,3;,
 4;18,19,20,21;,
 4;19,22,23,20;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,18,21,33;,
 3;34,19,18;,
 3;34,22,19;,
 3;34,24,22;,
 3;34,26,24;,
 3;34,28,26;,
 3;34,30,28;,
 3;34,32,30;,
 3;34,18,32;,
 3;35,21,20;,
 3;35,20,23;,
 3;35,23,25;,
 3;35,25,27;,
 3;35,27,29;,
 3;35,29,31;,
 3;35,31,33;,
 3;35,33,21;,
 4;36,37,38,39;,
 4;37,40,41,38;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 4;50,36,39,51;,
 3;52,37,36;,
 3;52,40,37;,
 3;52,42,40;,
 3;52,44,42;,
 3;52,46,44;,
 3;52,48,46;,
 3;52,50,48;,
 3;52,36,50;,
 3;53,39,38;,
 3;53,38,41;,
 3;53,41,43;,
 3;53,43,45;,
 3;53,45,47;,
 3;53,47,49;,
 3;53,49,51;,
 3;53,51,39;,
 4;54,55,56,57;,
 4;55,58,59,56;,
 4;58,60,61,59;,
 4;60,62,63,61;,
 4;62,64,65,63;,
 4;64,66,67,65;,
 4;66,68,69,67;,
 4;68,54,57,69;,
 3;70,55,54;,
 3;70,58,55;,
 3;70,60,58;,
 3;70,62,60;,
 3;70,64,62;,
 3;70,66,64;,
 3;70,68,66;,
 3;70,54,68;,
 3;71,57,56;,
 3;71,56,59;,
 3;71,59,61;,
 3;71,61,63;,
 3;71,63,65;,
 3;71,65,67;,
 3;71,67,69;,
 3;71,69,57;,
 4;72,73,74,75;,
 4;73,76,77,74;,
 4;76,78,79,77;,
 4;78,80,81,79;,
 4;80,82,83,81;,
 4;82,84,85,83;,
 4;84,86,87,85;,
 4;86,72,75,87;,
 3;88,73,72;,
 3;88,76,73;,
 3;88,78,76;,
 3;88,80,78;,
 3;88,82,80;,
 3;88,84,82;,
 3;88,86,84;,
 3;88,72,86;,
 3;89,75,74;,
 3;89,74,77;,
 3;89,77,79;,
 3;89,79,81;,
 3;89,81,83;,
 3;89,83,85;,
 3;89,85,87;,
 3;89,87,75;,
 4;90,91,92,93;,
 4;91,94,95,92;,
 4;94,96,97,95;,
 4;96,98,99,97;,
 4;98,100,101,99;,
 4;100,102,103,101;,
 4;102,104,105,103;,
 4;104,90,93,105;,
 3;106,91,90;,
 3;106,94,91;,
 3;106,96,94;,
 3;106,98,96;,
 3;106,100,98;,
 3;106,102,100;,
 3;106,104,102;,
 3;106,90,104;,
 3;107,93,92;,
 3;107,92,95;,
 3;107,95,97;,
 3;107,97,99;,
 3;107,99,101;,
 3;107,101,103;,
 3;107,103,105;,
 3;107,105,93;,
 4;108,109,110,111;,
 4;109,112,113,110;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 4;120,122,123,121;,
 4;122,108,111,123;,
 3;124,109,108;,
 3;124,112,109;,
 3;124,114,112;,
 3;124,116,114;,
 3;124,118,116;,
 3;124,120,118;,
 3;124,122,120;,
 3;124,108,122;,
 3;125,111,110;,
 3;125,110,113;,
 3;125,113,115;,
 3;125,115,117;,
 3;125,117,119;,
 3;125,119,121;,
 3;125,121,123;,
 3;125,123,111;,
 4;126,127,128,129;,
 4;127,130,131,128;,
 4;130,132,133,131;,
 4;132,134,135,133;,
 4;134,136,137,135;,
 4;136,138,139,137;,
 4;138,140,141,139;,
 4;140,126,129,141;,
 3;142,127,126;,
 3;142,130,127;,
 3;142,132,130;,
 3;142,134,132;,
 3;142,136,134;,
 3;142,138,136;,
 3;142,140,138;,
 3;142,126,140;,
 4;143,144,145,146;,
 4;144,147,148,145;,
 4;147,149,150,148;,
 4;149,151,152,150;,
 4;151,153,154,152;,
 4;153,155,156,154;,
 4;155,157,158,156;,
 4;157,143,146,158;,
 3;159,144,143;,
 3;159,147,144;,
 3;159,149,147;,
 3;159,151,149;,
 3;159,153,151;,
 3;159,155,153;,
 3;159,157,155;,
 3;159,143,157;,
 4;160,161,162,163;,
 4;161,164,165,162;,
 4;164,166,167,165;,
 4;166,168,169,167;,
 4;168,170,171,169;,
 4;170,172,173,171;,
 4;172,174,175,173;,
 4;174,160,163,175;,
 3;176,161,160;,
 3;176,164,161;,
 3;176,166,164;,
 3;176,168,166;,
 3;176,170,168;,
 3;176,172,170;,
 3;176,174,172;,
 3;176,160,174;,
 4;177,178,179,180;,
 4;178,181,182,179;,
 4;181,183,184,182;,
 4;183,185,186,184;,
 4;185,187,188,186;,
 4;187,189,190,188;,
 4;189,191,192,190;,
 4;191,177,180,192;,
 3;193,178,177;,
 3;193,181,178;,
 3;193,183,181;,
 3;193,185,183;,
 3;193,187,185;,
 3;193,189,187;,
 3;193,191,189;,
 3;193,177,191;;
 
 MeshMaterialList {
  5;
  232;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "tree.tga";
   }
  }
 }
 MeshNormals {
  248;
  -0.000000;-0.480026;0.877254;,
  0.000001;0.851202;0.524838;,
  0.706769;0.602179;0.371294;,
  1.000000;0.000002;0.000001;,
  0.706763;-0.602183;-0.371298;,
  0.000001;-0.851202;-0.524839;,
  -0.706764;-0.602182;-0.371297;,
  -1.000000;0.000002;0.000001;,
  -0.706770;0.602178;0.371293;,
  0.000000;0.480030;-0.877252;,
  0.488374;0.293006;0.821972;,
  -0.301344;0.948660;-0.096107;,
  0.358594;0.813214;-0.458360;,
  0.809017;0.201033;-0.552337;,
  0.784972;-0.529045;-0.322383;,
  0.301347;-0.948659;0.096104;,
  -0.358599;-0.813210;0.458363;,
  -0.809017;-0.201031;0.552339;,
  -0.784969;0.529050;0.322382;,
  -0.488364;-0.293022;-0.821972;,
  -0.152583;0.941599;-0.300185;,
  -0.163743;-0.273659;-0.947786;,
  0.573884;-0.126043;-0.809178;,
  0.975893;0.095583;-0.196206;,
  0.805577;0.261154;0.531831;,
  0.163749;0.273661;0.947785;,
  -0.573880;0.126046;0.809181;,
  -0.975891;-0.095579;0.196218;,
  -0.805571;-0.261155;-0.531840;,
  0.152577;-0.941598;0.300190;,
  -0.152579;-0.191661;-0.969529;,
  -0.163752;-0.972671;0.164610;,
  0.573886;-0.818244;0.033632;,
  0.975893;-0.184121;-0.117182;,
  0.805571;0.557984;-0.199272;,
  0.163753;0.972671;-0.164610;,
  -0.573884;0.818246;-0.033633;,
  -0.975892;0.184131;0.117178;,
  -0.805582;-0.557969;0.199270;,
  0.152578;0.191658;0.969529;,
  0.164687;0.955292;-0.245552;,
  -0.266653;-0.144721;-0.952865;,
  0.480719;-0.259776;-0.837511;,
  0.947077;-0.222695;-0.231199;,
  0.857994;-0.055008;0.510705;,
  0.266629;0.144727;0.952871;,
  -0.480726;0.259777;0.837507;,
  -0.947070;0.222698;0.231221;,
  -0.858006;0.055014;-0.510685;,
  -0.164668;-0.955295;0.245554;,
  -0.765225;-0.498262;-0.407635;,
  -0.228793;-0.456163;0.859982;,
  0.272991;-0.854447;0.442037;,
  0.615271;-0.752357;-0.235372;,
  0.596716;-0.209031;-0.774749;,
  0.228795;0.456162;-0.859982;,
  -0.272993;0.854447;-0.442034;,
  -0.615274;0.752353;0.235378;,
  -0.596715;0.209025;0.774752;,
  0.765228;0.498261;0.407629;,
  -0.801660;0.403199;-0.441329;,
  -0.490152;-0.871331;-0.023117;,
  -0.068016;-0.756406;-0.650557;,
  0.394394;-0.198068;-0.897342;,
  0.625504;0.476434;-0.617863;,
  0.490153;0.871330;0.023113;,
  0.068009;0.756400;0.650565;,
  -0.394386;0.198079;0.897343;,
  -0.625504;-0.476426;0.617871;,
  0.801667;-0.403203;0.441314;,
  -0.011648;0.998354;-0.056154;,
  -0.232568;-0.005523;-0.972565;,
  0.522853;-0.005127;-0.852407;,
  0.972577;-0.001729;-0.232575;,
  0.851922;0.002684;0.523662;,
  0.232561;0.005521;0.972566;,
  -0.522859;0.005127;0.852404;,
  -0.972576;0.001727;0.232578;,
  -0.851921;-0.002687;-0.523663;,
  -0.011648;0.998354;-0.056155;,
  -0.232555;-0.005523;-0.972568;,
  0.522871;-0.005128;-0.852397;,
  0.972580;-0.001729;-0.232563;,
  0.851919;0.002685;0.523666;,
  0.232570;0.005523;0.972564;,
  -0.522859;0.005127;0.852404;,
  -0.972576;0.001728;0.232581;,
  -0.851928;-0.002686;-0.523653;,
  -0.011649;0.998354;-0.056155;,
  -0.232558;-0.005523;-0.972567;,
  0.522874;-0.005127;-0.852395;,
  0.972578;-0.001728;-0.232571;,
  0.851922;0.002684;0.523662;,
  0.232570;0.005521;0.972564;,
  -0.522852;0.005127;0.852408;,
  -0.972577;0.001727;0.232573;,
  -0.851925;-0.002687;-0.523657;,
  -0.011648;0.998354;-0.056155;,
  -0.232555;-0.005521;-0.972568;,
  0.522866;-0.005127;-0.852399;,
  0.972579;-0.001730;-0.232565;,
  0.851921;0.002683;0.523663;,
  0.232562;0.005521;0.972566;,
  -0.522865;0.005127;0.852400;,
  -0.972575;0.001728;0.232582;,
  -0.851924;-0.002685;-0.523659;,
  -0.000012;-0.480016;0.877260;,
  -0.000000;-0.480006;0.877266;,
  0.000000;-0.480027;0.877254;,
  -0.000010;-0.480036;0.877249;,
  -0.000000;-0.480045;0.877244;,
  0.000010;-0.480036;0.877249;,
  0.000012;-0.480016;0.877260;,
  0.000000;0.480016;-0.877260;,
  0.000014;0.480029;-0.877253;,
  0.000000;0.480034;-0.877250;,
  0.000004;0.480031;-0.877252;,
  0.000000;0.480034;-0.877250;,
  -0.000004;0.480031;-0.877252;,
  -0.000014;0.480029;-0.877253;,
  0.488366;0.293025;0.821970;,
  0.488354;0.293039;0.821972;,
  0.488388;0.293002;0.821965;,
  0.488389;0.292983;0.821972;,
  0.488388;0.292976;0.821975;,
  0.488382;0.292981;0.821976;,
  0.488366;0.293010;0.821975;,
  0.488360;0.293037;0.821970;,
  -0.488364;-0.293022;-0.821973;,
  -0.488367;-0.293030;-0.821968;,
  -0.488361;-0.293027;-0.821972;,
  -0.488360;-0.293008;-0.821980;,
  -0.488378;-0.293005;-0.821970;,
  -0.488376;-0.293026;-0.821964;,
  -0.488355;-0.293036;-0.821973;,
  -0.488354;-0.293024;-0.821978;,
  -0.152569;0.941596;-0.300200;,
  -0.152588;0.941592;-0.300204;,
  -0.152559;0.941601;-0.300188;,
  -0.152562;0.941604;-0.300177;,
  -0.152584;0.941604;-0.300168;,
  -0.152599;0.941603;-0.300162;,
  -0.152599;0.941598;-0.300178;,
  -0.152600;0.941591;-0.300199;,
  0.152603;-0.941593;0.300193;,
  0.152601;-0.941602;0.300164;,
  0.152570;-0.941606;0.300167;,
  0.152570;-0.941596;0.300198;,
  0.152572;-0.941594;0.300203;,
  0.152571;-0.941597;0.300197;,
  0.152564;-0.941597;0.300199;,
  0.152567;-0.941595;0.300203;,
  -0.152576;-0.191669;-0.969527;,
  -0.152591;-0.191676;-0.969524;,
  -0.152566;-0.191668;-0.969529;,
  -0.152583;-0.191654;-0.969529;,
  -0.152588;-0.191634;-0.969533;,
  -0.152570;-0.191631;-0.969536;,
  -0.152569;-0.191665;-0.969529;,
  -0.152585;-0.191689;-0.969522;,
  0.152568;0.191666;0.969530;,
  0.152592;0.191656;0.969527;,
  0.152589;0.191663;0.969527;,
  0.152597;0.191664;0.969525;,
  0.152589;0.191658;0.969528;,
  0.152571;0.191659;0.969530;,
  0.152566;0.191646;0.969534;,
  0.152552;0.191653;0.969534;,
  0.164699;0.955287;-0.245562;,
  0.164683;0.955290;-0.245563;,
  0.164706;0.955287;-0.245556;,
  0.164704;0.955290;-0.245547;,
  0.164692;0.955294;-0.245539;,
  0.164677;0.955297;-0.245540;,
  0.164669;0.955296;-0.245549;,
  0.164670;0.955294;-0.245557;,
  -0.164695;-0.955291;0.245548;,
  -0.164642;-0.955299;0.245556;,
  -0.164620;-0.955301;0.245562;,
  -0.164616;-0.955306;0.245543;,
  -0.164675;-0.955295;0.245548;,
  -0.164703;-0.955280;0.245586;,
  -0.164681;-0.955292;0.245557;,
  -0.164710;-0.955293;0.245530;,
  -0.765210;-0.498273;-0.407649;,
  -0.765230;-0.498251;-0.407639;,
  -0.765212;-0.498282;-0.407635;,
  -0.765222;-0.498272;-0.407628;,
  -0.765228;-0.498254;-0.407638;,
  -0.765227;-0.498255;-0.407640;,
  -0.765229;-0.498263;-0.407626;,
  -0.765240;-0.498250;-0.407622;,
  0.765232;0.498263;0.407619;,
  0.765227;0.498255;0.407640;,
  0.765215;0.498278;0.407634;,
  0.765232;0.498264;0.407618;,
  0.765228;0.498253;0.407640;,
  0.765228;0.498265;0.407625;,
  0.765239;0.498249;0.407625;,
  0.765227;0.498259;0.407635;,
  -0.801666;0.403165;-0.441349;,
  -0.801665;0.403191;-0.441329;,
  -0.801658;0.403204;-0.441328;,
  -0.801631;0.403239;-0.441345;,
  -0.801636;0.403219;-0.441356;,
  -0.801660;0.403203;-0.441326;,
  -0.801683;0.403183;-0.441304;,
  -0.801684;0.403190;-0.441295;,
  0.801652;-0.403202;0.441342;,
  0.801667;-0.403205;0.441312;,
  0.801677;-0.403188;0.441309;,
  0.801683;-0.403196;0.441290;,
  0.801660;-0.403207;0.441323;,
  0.801680;-0.403161;0.441329;,
  0.801678;-0.403214;0.441283;,
  0.801637;-0.403248;0.441327;,
  -0.011626;0.998353;-0.056177;,
  -0.011653;0.998353;-0.056168;,
  -0.011627;0.998353;-0.056171;,
  -0.011639;0.998355;-0.056140;,
  -0.011641;0.998356;-0.056120;,
  -0.011649;0.998355;-0.056134;,
  -0.011672;0.998354;-0.056160;,
  -0.011679;0.998353;-0.056167;,
  -0.011625;0.998353;-0.056176;,
  -0.011653;0.998353;-0.056167;,
  -0.011627;0.998353;-0.056172;,
  -0.011640;0.998355;-0.056141;,
  -0.011643;0.998356;-0.056121;,
  -0.011650;0.998355;-0.056135;,
  -0.011672;0.998354;-0.056160;,
  -0.011679;0.998353;-0.056166;,
  -0.011625;0.998353;-0.056176;,
  -0.011653;0.998353;-0.056167;,
  -0.011627;0.998353;-0.056171;,
  -0.011640;0.998355;-0.056141;,
  -0.011643;0.998356;-0.056121;,
  -0.011650;0.998355;-0.056135;,
  -0.011672;0.998354;-0.056160;,
  -0.011680;0.998353;-0.056166;,
  -0.011626;0.998353;-0.056177;,
  -0.011653;0.998353;-0.056168;,
  -0.011627;0.998353;-0.056171;,
  -0.011639;0.998355;-0.056140;,
  -0.011641;0.998356;-0.056120;,
  -0.011649;0.998355;-0.056135;,
  -0.011672;0.998354;-0.056160;,
  -0.011679;0.998353;-0.056167;;
  232;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,1,1,8;,
  3;0,106,107;,
  3;0,108,106;,
  3;0,109,108;,
  3;0,110,109;,
  3;0,111,110;,
  3;0,108,111;,
  3;0,112,108;,
  3;0,107,112;,
  3;9,113,114;,
  3;9,114,115;,
  3;9,115,116;,
  3;9,116,117;,
  3;9,117,118;,
  3;9,118,115;,
  3;9,115,119;,
  3;9,119,113;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,11,11,18;,
  3;10,120,121;,
  3;10,122,120;,
  3;10,123,122;,
  3;10,124,123;,
  3;10,125,124;,
  3;10,126,125;,
  3;10,127,126;,
  3;10,121,127;,
  3;19,128,129;,
  3;19,129,130;,
  3;19,130,131;,
  3;19,131,132;,
  3;19,132,133;,
  3;19,133,134;,
  3;19,134,135;,
  3;19,135,128;,
  4;21,22,22,21;,
  4;22,23,23,22;,
  4;23,24,24,23;,
  4;24,25,25,24;,
  4;25,26,26,25;,
  4;26,27,27,26;,
  4;27,28,28,27;,
  4;28,21,21,28;,
  3;20,136,137;,
  3;20,138,136;,
  3;20,139,138;,
  3;20,140,139;,
  3;20,141,140;,
  3;20,142,141;,
  3;20,143,142;,
  3;20,137,143;,
  3;29,144,145;,
  3;29,145,146;,
  3;29,146,147;,
  3;29,147,148;,
  3;29,148,149;,
  3;29,149,150;,
  3;29,150,151;,
  3;29,151,144;,
  4;31,32,32,31;,
  4;32,33,33,32;,
  4;33,34,34,33;,
  4;34,35,35,34;,
  4;35,36,36,35;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;38,31,31,38;,
  3;30,152,153;,
  3;30,154,152;,
  3;30,155,154;,
  3;30,156,155;,
  3;30,157,156;,
  3;30,158,157;,
  3;30,159,158;,
  3;30,153,159;,
  3;39,160,161;,
  3;39,161,162;,
  3;39,162,163;,
  3;39,163,164;,
  3;39,164,165;,
  3;39,165,166;,
  3;39,166,167;,
  3;39,167,160;,
  4;41,42,42,41;,
  4;42,43,43,42;,
  4;43,44,44,43;,
  4;44,45,45,44;,
  4;45,46,46,45;,
  4;46,47,47,46;,
  4;47,48,48,47;,
  4;48,41,41,48;,
  3;40,168,169;,
  3;40,170,168;,
  3;40,171,170;,
  3;40,172,171;,
  3;40,173,172;,
  3;40,174,173;,
  3;40,175,174;,
  3;40,169,175;,
  3;49,176,177;,
  3;49,177,178;,
  3;49,178,179;,
  3;49,179,180;,
  3;49,180,181;,
  3;49,181,182;,
  3;49,182,183;,
  3;49,183,176;,
  4;51,52,52,51;,
  4;52,53,53,52;,
  4;53,54,54,53;,
  4;54,55,55,54;,
  4;55,56,56,55;,
  4;56,57,57,56;,
  4;57,58,58,57;,
  4;58,51,51,58;,
  3;50,184,185;,
  3;50,186,184;,
  3;50,187,186;,
  3;50,188,187;,
  3;50,189,188;,
  3;50,190,189;,
  3;50,191,190;,
  3;50,185,191;,
  3;59,192,193;,
  3;59,193,194;,
  3;59,194,195;,
  3;59,195,196;,
  3;59,196,197;,
  3;59,197,198;,
  3;59,198,199;,
  3;59,199,192;,
  4;61,62,62,61;,
  4;62,63,63,62;,
  4;63,64,64,63;,
  4;64,65,65,64;,
  4;65,66,66,65;,
  4;66,67,67,66;,
  4;67,68,68,67;,
  4;68,61,61,68;,
  3;60,200,201;,
  3;60,202,200;,
  3;60,203,202;,
  3;60,204,203;,
  3;60,205,204;,
  3;60,206,205;,
  3;60,207,206;,
  3;60,201,207;,
  3;69,208,209;,
  3;69,209,210;,
  3;69,210,211;,
  3;69,211,212;,
  3;69,212,213;,
  3;69,213,214;,
  3;69,214,215;,
  3;69,215,208;,
  4;71,72,72,71;,
  4;72,73,73,72;,
  4;73,74,74,73;,
  4;74,75,75,74;,
  4;75,76,76,75;,
  4;76,77,77,76;,
  4;77,78,78,77;,
  4;78,71,71,78;,
  3;70,216,217;,
  3;70,218,216;,
  3;70,219,218;,
  3;70,220,219;,
  3;70,221,220;,
  3;70,222,221;,
  3;70,223,222;,
  3;70,217,223;,
  4;80,81,81,80;,
  4;81,82,82,81;,
  4;82,83,83,82;,
  4;83,84,84,83;,
  4;84,85,85,84;,
  4;85,86,86,85;,
  4;86,87,87,86;,
  4;87,80,80,87;,
  3;79,224,225;,
  3;79,226,224;,
  3;79,227,226;,
  3;79,228,227;,
  3;79,229,228;,
  3;79,230,229;,
  3;79,231,230;,
  3;79,225,231;,
  4;89,90,90,89;,
  4;90,91,91,90;,
  4;91,92,92,91;,
  4;92,93,93,92;,
  4;93,94,94,93;,
  4;94,95,95,94;,
  4;95,96,96,95;,
  4;96,89,89,96;,
  3;88,232,233;,
  3;88,234,232;,
  3;88,235,234;,
  3;88,236,235;,
  3;88,237,236;,
  3;88,238,237;,
  3;88,239,238;,
  3;88,233,239;,
  4;98,99,99,98;,
  4;99,100,100,99;,
  4;100,101,101,100;,
  4;101,102,102,101;,
  4;102,103,103,102;,
  4;103,104,104,103;,
  4;104,105,105,104;,
  4;105,98,98,105;,
  3;97,240,241;,
  3;97,242,240;,
  3;97,243,242;,
  3;97,244,243;,
  3;97,245,244;,
  3;97,246,245;,
  3;97,247,246;,
  3;97,241,247;;
 }
 MeshTextureCoords {
  194;
  1.754775;6.249509;
  1.723653;6.367166;
  0.003567;5.728064;
  0.034688;5.610408;
  1.677474;6.472867;
  -0.042613;5.833763;
  1.643291;6.504692;
  -0.076796;5.865588;
  1.641126;6.444001;
  -0.078960;5.804900;
  1.672253;6.326350;
  -0.047834;5.687246;
  1.718432;6.220648;
  -0.001655;5.581545;
  1.752615;6.188823;
  0.032528;5.549722;
  1.697953;6.346757;
  -0.022134;5.707654;
  1.724311;7.053846;
  1.656452;7.152975;
  0.312500;6.750964;
  0.380363;6.651833;
  1.651550;7.278461;
  0.307602;6.876448;
  1.712483;7.356791;
  0.368539;6.954777;
  1.803556;7.342078;
  0.459607;6.940067;
  1.871419;7.242950;
  0.527475;6.840936;
  1.876319;7.117466;
  0.532372;6.715446;
  1.815384;7.039135;
  0.471437;6.637120;
  1.763937;7.197964;
  0.419990;6.795949;
  0.281455;6.642518;
  0.284442;6.717274;
  0.985875;8.103956;
  0.982896;8.029205;
  0.368903;6.738295;
  1.070345;8.124976;
  0.485369;6.693262;
  1.186811;8.079941;
  0.565612;6.608555;
  1.267053;7.995237;
  0.562628;6.533802;
  1.264066;7.920480;
  0.478164;6.512781;
  1.179605;7.899459;
  0.361697;6.557817;
  1.063136;7.944495;
  0.423533;6.625536;
  1.124971;8.012220;
  -0.278707;8.457927;
  -0.321573;8.534112;
  1.413741;8.550743;
  1.456607;8.474562;
  -0.376105;8.515093;
  1.359209;8.531727;
  -0.410365;8.412020;
  1.324950;8.428646;
  -0.404276;8.285261;
  1.331039;8.301895;
  -0.361414;8.209084;
  1.373901;8.225712;
  -0.306886;8.228102;
  1.428433;8.244730;
  -0.272622;8.331177;
  1.462689;8.347802;
  -0.341495;8.371599;
  1.393823;8.388227;
  -0.768366;8.204201;
  -0.762766;8.309790;
  -0.086505;9.248114;
  -0.092105;9.142531;
  -0.675993;8.360687;
  0.000262;9.299004;
  -0.558887;8.327089;
  0.117373;9.265404;
  -0.480044;8.228668;
  0.196217;9.166996;
  -0.485649;8.123092;
  0.190611;9.061411;
  -0.572417;8.072193;
  0.103844;9.010520;
  -0.689525;8.105793;
  -0.013264;9.044106;
  -0.624210;8.216440;
  0.052056;9.154761;
  0.539493;8.612481;
  0.469833;8.719563;
  0.998077;9.194084;
  1.067731;9.087014;
  0.347437;8.750674;
  0.875680;9.225202;
  0.243994;8.687603;
  0.772238;9.162124;
  0.220110;8.567286;
  0.748349;9.041815;
  0.289765;8.460213;
  0.818009;8.934733;
  0.412161;8.429098;
  0.940408;8.903623;
  0.515604;8.492178;
  1.043848;8.966693;
  0.379797;8.589888;
  0.908045;9.064409;
  -1.201327;7.806911;
  -1.317051;7.846003;
  -0.555257;9.497934;
  -0.439541;9.458855;
  -1.383508;7.837686;
  -0.621711;9.489620;
  -1.361773;7.786852;
  -0.599973;9.438778;
  -1.264571;7.723263;
  -0.502781;9.375202;
  -1.148855;7.684177;
  -0.387057;9.336111;
  -1.082397;7.692492;
  -0.320604;9.344438;
  -1.104135;7.743334;
  -0.342332;9.395259;
  -1.232953;7.765086;
  -0.471155;9.417026;
  -5.548014;11.158882;
  -5.544176;11.252344;
  -5.250906;12.490321;
  -5.254743;12.396873;
  -5.452756;11.303855;
  -5.159486;12.541830;
  -5.327301;11.283260;
  -5.034029;12.521225;
  -5.241309;11.202606;
  -4.948043;12.440590;
  -5.245152;11.109157;
  -4.951881;12.347130;
  -5.336576;11.057639;
  -5.043304;12.295625;
  -5.462028;11.078241;
  -5.168752;12.316216;
  -5.394664;11.180744;
  -3.704077;10.199949;
  -3.700235;10.293411;
  -3.406965;11.531389;
  -3.410806;11.437940;
  -3.608815;10.344923;
  -3.315544;11.582894;
  -3.483364;10.324324;
  -3.190089;11.562292;
  -3.397372;10.243673;
  -3.104102;11.481654;
  -3.401211;10.150221;
  -3.107940;11.388197;
  -3.492635;10.098707;
  -3.199363;11.336692;
  -3.618087;10.119308;
  -3.324815;11.357280;
  -3.550724;10.221812;
  -2.449415;9.876970;
  -2.445573;9.970429;
  -2.152303;11.208408;
  -2.156144;11.114961;
  -2.354153;10.021940;
  -2.060882;11.259914;
  -2.228702;10.001344;
  -1.935431;11.239313;
  -2.142710;9.920691;
  -1.849443;11.158674;
  -2.146549;9.827241;
  -1.853278;11.065218;
  -2.237973;9.775726;
  -1.944701;11.013712;
  -2.363425;9.796329;
  -2.070153;11.034303;
  -2.296062;9.898832;
  -4.887121;10.617248;
  -4.883283;10.710710;
  -4.590012;11.948687;
  -4.593854;11.855239;
  -4.791862;10.762220;
  -4.498592;12.000192;
  -4.666408;10.741622;
  -4.373136;11.979589;
  -4.580416;10.660972;
  -4.287149;11.898952;
  -4.584259;10.567519;
  -4.290987;11.805495;
  -4.675683;10.516005;
  -4.382411;11.753990;
  -4.801134;10.536607;
  -4.507863;11.774577;
  -4.733771;10.639110;;
 }
}
