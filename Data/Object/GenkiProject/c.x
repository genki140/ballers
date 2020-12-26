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
 180;
 0.70961;-0.02039;-0.05673;,
 0.70550;-0.01612;-0.05673;,
 0.70536;-0.00903;-0.05673;,
 0.71004;-0.00379;-0.05673;,
 0.71390;-0.00026;-0.05673;,
 0.71698;-0.01952;-0.05673;,
 0.71773;0.00375;-0.05673;,
 0.71523;-0.04015;-0.05673;,
 0.71518;-0.03335;-0.05673;,
 0.71659;-0.02568;-0.05673;,
 0.71745;-0.04786;-0.05673;,
 0.72265;0.00917;-0.05673;,
 0.72063;-0.05478;-0.05673;,
 0.72352;-0.05959;-0.05673;,
 0.72863;0.01598;-0.05673;,
 0.72685;-0.06382;-0.05673;,
 0.73057;-0.06744;-0.05673;,
 0.73580;0.02426;-0.05673;,
 0.73467;-0.07045;-0.05673;,
 0.74036;-0.07343;-0.05673;,
 0.74350;0.03282;-0.05673;,
 0.74809;-0.07579;-0.05673;,
 0.75105;0.04079;-0.05673;,
 0.75437;-0.07656;-0.05673;,
 0.75849;0.04817;-0.05673;,
 0.76441;-0.07611;-0.05673;,
 0.76581;0.05492;-0.05673;,
 0.76782;-0.02785;-0.05673;,
 0.77359;0.06153;-0.05673;,
 0.76885;-0.02109;-0.05673;,
 0.77096;-0.01340;-0.05673;,
 0.77415;-0.00478;-0.05673;,
 0.78254;0.06789;-0.05673;,
 0.77843;0.00475;-0.05673;,
 0.78511;0.01752;-0.05673;,
 0.79166;0.07273;-0.05673;,
 0.79308;0.03059;-0.05673;,
 0.80094;0.07604;-0.05673;,
 0.80061;0.04042;-0.05673;,
 0.80818;0.04721;-0.05673;,
 0.81038;0.07783;-0.05673;,
 0.81648;0.05047;-0.05673;,
 0.82044;0.07803;-0.05673;,
 0.81171;0.02575;-0.05673;,
 0.81171;0.03420;-0.05673;,
 0.81567;0.04204;-0.05673;,
 0.81579;0.01851;-0.05673;,
 0.82178;0.04748;-0.05673;,
 0.82241;0.01547;-0.05673;,
 0.82897;0.07686;-0.05673;,
 0.83023;0.01531;-0.05673;,
 0.83517;0.07518;-0.05673;,
 0.83730;0.01784;-0.05673;,
 0.84006;0.07317;-0.05673;,
 0.84311;0.02210;-0.05673;,
 0.84594;0.06952;-0.05673;,
 0.84698;0.02628;-0.05673;,
 0.84992;0.03043;-0.05673;,
 0.85172;0.06192;-0.05673;,
 0.85298;0.03665;-0.05673;,
 0.85463;0.05384;-0.05673;,
 0.85506;0.04521;-0.05673;,
 0.76782;-0.03381;-0.05673;,
 0.76913;-0.03928;-0.05673;,
 0.77684;-0.07351;-0.05673;,
 0.77217;-0.04399;-0.05673;,
 0.77716;-0.04631;-0.05673;,
 0.79203;-0.06754;-0.05673;,
 0.78536;-0.04654;-0.05673;,
 0.79200;-0.04494;-0.05673;,
 0.79703;-0.04290;-0.05673;,
 0.80793;-0.05831;-0.05673;,
 0.80247;-0.04015;-0.05673;,
 0.80774;-0.03699;-0.05673;,
 0.81250;-0.03372;-0.05673;,
 0.82435;-0.04587;-0.05673;,
 0.81705;-0.03021;-0.05673;,
 0.82139;-0.02645;-0.05673;,
 0.82556;-0.02246;-0.05673;,
 0.83823;-0.03325;-0.05673;,
 0.83007;-0.01780;-0.05673;,
 0.83439;-0.01340;-0.05673;,
 0.83965;-0.00835;-0.05673;,
 0.84590;-0.02548;-0.05673;,
 0.84467;-0.00433;-0.05673;,
 0.85174;-0.00208;-0.05673;,
 0.85175;-0.01891;-0.05673;,
 0.85577;-0.01355;-0.05673;,
 0.85765;-0.00765;-0.05673;,
 0.70536;-0.00903;0.06027;,
 0.70550;-0.01612;0.06027;,
 0.70961;-0.02039;0.06027;,
 0.71004;-0.00379;0.06027;,
 0.71390;-0.00026;0.06027;,
 0.71698;-0.01952;0.06027;,
 0.71773;0.00375;0.06027;,
 0.71659;-0.02568;0.06027;,
 0.71518;-0.03335;0.06027;,
 0.71523;-0.04015;0.06027;,
 0.71745;-0.04786;0.06027;,
 0.72265;0.00917;0.06027;,
 0.72063;-0.05478;0.06027;,
 0.72352;-0.05959;0.06027;,
 0.72863;0.01598;0.06027;,
 0.72685;-0.06382;0.06027;,
 0.73057;-0.06744;0.06027;,
 0.73580;0.02426;0.06027;,
 0.73467;-0.07045;0.06027;,
 0.74036;-0.07343;0.06027;,
 0.74350;0.03282;0.06027;,
 0.74809;-0.07579;0.06027;,
 0.75105;0.04079;0.06027;,
 0.75437;-0.07656;0.06027;,
 0.75849;0.04817;0.06027;,
 0.76441;-0.07611;0.06027;,
 0.76581;0.05492;0.06027;,
 0.76913;-0.03928;0.06027;,
 0.77684;-0.07351;0.06027;,
 0.77217;-0.04399;0.06027;,
 0.77716;-0.04631;0.06027;,
 0.79203;-0.06754;0.06027;,
 0.78536;-0.04654;0.06027;,
 0.79200;-0.04494;0.06027;,
 0.79703;-0.04290;0.06027;,
 0.80793;-0.05831;0.06027;,
 0.80247;-0.04015;0.06027;,
 0.80774;-0.03699;0.06027;,
 0.81250;-0.03372;0.06027;,
 0.82435;-0.04587;0.06027;,
 0.81705;-0.03021;0.06027;,
 0.82139;-0.02645;0.06027;,
 0.82556;-0.02246;0.06027;,
 0.83823;-0.03325;0.06027;,
 0.83007;-0.01780;0.06027;,
 0.83439;-0.01340;0.06027;,
 0.83965;-0.00835;0.06027;,
 0.84590;-0.02548;0.06027;,
 0.84467;-0.00433;0.06027;,
 0.85174;-0.00208;0.06027;,
 0.85175;-0.01891;0.06027;,
 0.85577;-0.01355;0.06027;,
 0.85765;-0.00765;0.06027;,
 0.76782;-0.03381;0.06027;,
 0.76782;-0.02785;0.06027;,
 0.77359;0.06153;0.06027;,
 0.76885;-0.02109;0.06027;,
 0.77096;-0.01340;0.06027;,
 0.77415;-0.00478;0.06027;,
 0.78254;0.06789;0.06027;,
 0.77843;0.00475;0.06027;,
 0.78511;0.01752;0.06027;,
 0.79166;0.07273;0.06027;,
 0.79308;0.03059;0.06027;,
 0.80094;0.07604;0.06027;,
 0.80061;0.04042;0.06027;,
 0.80818;0.04721;0.06027;,
 0.81038;0.07783;0.06027;,
 0.81648;0.05047;0.06027;,
 0.82044;0.07803;0.06027;,
 0.81567;0.04204;0.06027;,
 0.81171;0.03420;0.06027;,
 0.81171;0.02575;0.06027;,
 0.81579;0.01851;0.06027;,
 0.82178;0.04748;0.06027;,
 0.82241;0.01547;0.06027;,
 0.82897;0.07686;0.06027;,
 0.83023;0.01531;0.06027;,
 0.83517;0.07518;0.06027;,
 0.83730;0.01784;0.06027;,
 0.84006;0.07317;0.06027;,
 0.84311;0.02210;0.06027;,
 0.84594;0.06952;0.06027;,
 0.84698;0.02628;0.06027;,
 0.84992;0.03043;0.06027;,
 0.85172;0.06192;0.06027;,
 0.85298;0.03665;0.06027;,
 0.85463;0.05384;0.06027;,
 0.85506;0.04521;0.06027;,
 0.72403;-0.01292;0.06027;,
 0.72403;-0.01292;-0.05673;;
 
 356;
 3;0,1,2;,
 3;0,2,3;,
 3;0,3,4;,
 3;5,0,4;,
 3;5,4,6;,
 3;7,8,9;,
 3;10,7,9;,
 3;10,9,5;,
 3;5,6,11;,
 3;12,10,5;,
 3;13,12,5;,
 3;13,5,11;,
 3;13,11,14;,
 3;15,13,14;,
 3;16,15,14;,
 3;16,14,17;,
 3;18,16,17;,
 3;19,18,17;,
 3;19,17,20;,
 3;21,19,20;,
 3;21,20,22;,
 3;23,21,22;,
 3;23,22,24;,
 3;25,23,24;,
 3;25,24,26;,
 3;27,25,26;,
 3;27,26,28;,
 3;29,27,28;,
 3;30,29,28;,
 3;31,30,28;,
 3;31,28,32;,
 3;33,31,32;,
 3;34,33,32;,
 3;34,32,35;,
 3;36,34,35;,
 3;36,35,37;,
 3;38,36,37;,
 3;39,38,37;,
 3;39,37,40;,
 3;41,39,40;,
 3;41,40,42;,
 3;43,44,45;,
 3;46,43,45;,
 3;46,45,47;,
 3;48,46,47;,
 3;47,41,42;,
 3;47,42,49;,
 3;50,48,47;,
 3;50,47,49;,
 3;50,49,51;,
 3;52,50,51;,
 3;52,51,53;,
 3;54,52,53;,
 3;54,53,55;,
 3;56,54,55;,
 3;57,56,55;,
 3;57,55,58;,
 3;59,57,58;,
 3;59,58,60;,
 3;61,59,60;,
 3;62,25,27;,
 3;63,25,62;,
 3;64,25,63;,
 3;64,63,65;,
 3;64,65,66;,
 3;67,64,66;,
 3;67,66,68;,
 3;67,68,69;,
 3;67,69,70;,
 3;71,67,70;,
 3;71,70,72;,
 3;71,72,73;,
 3;71,73,74;,
 3;75,71,74;,
 3;75,74,76;,
 3;75,76,77;,
 3;75,77,78;,
 3;79,75,78;,
 3;79,78,80;,
 3;79,80,81;,
 3;79,81,82;,
 3;83,79,82;,
 3;83,82,84;,
 3;83,84,85;,
 3;86,83,85;,
 3;87,86,85;,
 3;87,85,88;,
 3;89,90,91;,
 3;92,89,91;,
 3;93,92,91;,
 3;93,91,94;,
 3;95,93,94;,
 3;96,97,98;,
 3;96,98,99;,
 3;94,96,99;,
 3;100,95,94;,
 3;94,99,101;,
 3;94,101,102;,
 3;100,94,102;,
 3;103,100,102;,
 3;103,102,104;,
 3;103,104,105;,
 3;106,103,105;,
 3;106,105,107;,
 3;106,107,108;,
 3;109,106,108;,
 3;109,108,110;,
 3;111,109,110;,
 3;111,110,112;,
 3;113,111,112;,
 3;113,112,114;,
 3;115,113,114;,
 3;116,114,117;,
 3;118,116,117;,
 3;119,118,117;,
 3;119,117,120;,
 3;121,119,120;,
 3;122,121,120;,
 3;123,122,120;,
 3;123,120,124;,
 3;125,123,124;,
 3;126,125,124;,
 3;127,126,124;,
 3;127,124,128;,
 3;129,127,128;,
 3;130,129,128;,
 3;131,130,128;,
 3;131,128,132;,
 3;133,131,132;,
 3;134,133,132;,
 3;135,134,132;,
 3;135,132,136;,
 3;137,135,136;,
 3;138,137,136;,
 3;138,136,139;,
 3;138,139,140;,
 3;141,138,140;,
 3;114,116,142;,
 3;114,142,143;,
 3;115,114,143;,
 3;144,115,143;,
 3;144,143,145;,
 3;144,145,146;,
 3;144,146,147;,
 3;148,144,147;,
 3;148,147,149;,
 3;148,149,150;,
 3;151,148,150;,
 3;151,150,152;,
 3;153,151,152;,
 3;153,152,154;,
 3;153,154,155;,
 3;156,153,155;,
 3;156,155,157;,
 3;158,156,157;,
 3;159,160,161;,
 3;159,161,162;,
 3;163,159,162;,
 3;163,162,164;,
 3;158,157,163;,
 3;165,158,163;,
 3;163,164,166;,
 3;165,163,166;,
 3;167,165,166;,
 3;167,166,168;,
 3;169,167,168;,
 3;169,168,170;,
 3;171,169,170;,
 3;171,170,172;,
 3;171,172,173;,
 3;174,171,173;,
 3;174,173,175;,
 3;176,174,175;,
 3;176,175,177;,
 3;124,71,75;,
 3;124,75,128;,
 3;120,67,71;,
 3;120,71,124;,
 3;117,64,67;,
 3;117,67,120;,
 3;114,25,64;,
 3;114,64,117;,
 3;112,23,25;,
 3;112,25,114;,
 3;112,110,21;,
 3;112,21,23;,
 3;110,108,19;,
 3;110,19,21;,
 3;108,107,18;,
 3;108,18,19;,
 3;107,105,16;,
 3;107,16,18;,
 3;105,104,15;,
 3;105,15,16;,
 3;104,102,13;,
 3;104,13,15;,
 3;102,101,12;,
 3;102,12,13;,
 3;101,99,10;,
 3;101,10,12;,
 3;99,98,7;,
 3;99,7,10;,
 3;98,97,8;,
 3;98,8,7;,
 3;97,96,9;,
 3;97,9,8;,
 3;96,94,5;,
 3;96,5,9;,
 3;94,178,179;,
 3;94,179,5;,
 3;94,5,179;,
 3;94,179,178;,
 3;94,91,0;,
 3;94,0,5;,
 3;91,90,1;,
 3;91,1,0;,
 3;90,89,2;,
 3;90,2,1;,
 3;89,92,3;,
 3;89,3,2;,
 3;92,93,4;,
 3;92,4,3;,
 3;93,95,6;,
 3;93,6,4;,
 3;95,100,11;,
 3;95,11,6;,
 3;100,103,14;,
 3;100,14,11;,
 3;103,106,17;,
 3;103,17,14;,
 3;106,109,20;,
 3;106,20,17;,
 3;109,111,22;,
 3;109,22,20;,
 3;111,113,24;,
 3;111,24,22;,
 3;113,115,26;,
 3;113,26,24;,
 3;115,144,28;,
 3;115,28,26;,
 3;144,148,32;,
 3;144,32,28;,
 3;148,151,35;,
 3;148,35,32;,
 3;151,153,37;,
 3;151,37,35;,
 3;153,156,40;,
 3;153,40,37;,
 3;156,158,42;,
 3;156,42,40;,
 3;165,49,42;,
 3;165,42,158;,
 3;167,51,49;,
 3;167,49,165;,
 3;169,53,51;,
 3;169,51,167;,
 3;171,55,53;,
 3;171,53,169;,
 3;174,58,55;,
 3;174,55,171;,
 3;176,60,58;,
 3;176,58,174;,
 3;177,61,60;,
 3;177,60,176;,
 3;175,59,61;,
 3;175,61,177;,
 3;173,57,59;,
 3;173,59,175;,
 3;172,56,57;,
 3;172,57,173;,
 3;170,54,56;,
 3;170,56,172;,
 3;168,52,54;,
 3;168,54,170;,
 3;166,50,52;,
 3;166,52,168;,
 3;166,164,48;,
 3;166,48,50;,
 3;164,162,46;,
 3;164,46,48;,
 3;162,161,43;,
 3;162,43,46;,
 3;161,160,44;,
 3;161,44,43;,
 3;160,159,45;,
 3;160,45,44;,
 3;159,163,47;,
 3;159,47,45;,
 3;163,157,41;,
 3;163,41,47;,
 3;155,39,41;,
 3;155,41,157;,
 3;154,38,39;,
 3;154,39,155;,
 3;152,36,38;,
 3;152,38,154;,
 3;150,34,36;,
 3;150,36,152;,
 3;149,33,34;,
 3;149,34,150;,
 3;147,31,33;,
 3;147,33,149;,
 3;146,30,31;,
 3;146,31,147;,
 3;145,29,30;,
 3;145,30,146;,
 3;143,27,29;,
 3;143,29,145;,
 3;142,62,27;,
 3;142,27,143;,
 3;116,63,62;,
 3;116,62,142;,
 3;118,65,63;,
 3;118,63,116;,
 3;119,66,65;,
 3;119,65,118;,
 3;121,68,66;,
 3;121,66,119;,
 3;121,122,69;,
 3;121,69,68;,
 3;122,123,70;,
 3;122,70,69;,
 3;123,125,72;,
 3;123,72,70;,
 3;125,126,73;,
 3;125,73,72;,
 3;126,127,74;,
 3;126,74,73;,
 3;127,129,76;,
 3;127,76,74;,
 3;129,130,77;,
 3;129,77,76;,
 3;130,131,78;,
 3;130,78,77;,
 3;131,133,80;,
 3;131,80,78;,
 3;133,134,81;,
 3;133,81,80;,
 3;134,135,82;,
 3;134,82,81;,
 3;135,137,84;,
 3;135,84,82;,
 3;137,138,85;,
 3;137,85,84;,
 3;141,88,85;,
 3;141,85,138;,
 3;140,87,88;,
 3;140,88,141;,
 3;139,86,87;,
 3;139,87,140;,
 3;136,83,86;,
 3;136,86,139;,
 3;132,79,83;,
 3;132,83,136;,
 3;128,75,79;,
 3;128,79,132;;
 
 MeshMaterialList {
  1;
  356;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.784314;0.784314;0.784314;1.000000;;
   6.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Rogo.bmp";
   }
  }
 }
 MeshNormals {
  180;
  0.000000;0.000000;-1.000000;,
  -0.683309;0.730129;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.570769;-0.821111;-0.000000;,
  0.536904;-0.843644;-0.000000;,
  0.627304;-0.778774;-0.000000;,
  0.650428;-0.759568;-0.000000;,
  0.457830;-0.889040;-0.000000;,
  0.412162;-0.911111;-0.000000;,
  0.312852;-0.949802;-0.000000;,
  0.258997;-0.965878;-0.000000;,
  0.151806;-0.988410;-0.000000;,
  0.098525;-0.995135;-0.000000;,
  -0.038272;-0.999267;0.000000;,
  -0.236135;-0.971720;0.000000;,
  -0.178970;-0.983854;0.000000;,
  -0.408217;-0.912885;0.000000;,
  -0.350822;-0.936442;0.000000;,
  -0.550570;-0.834789;0.000000;,
  -0.507790;-0.861481;0.000000;,
  -0.663573;-0.748111;0.000000;,
  -0.628341;-0.777938;0.000000;,
  -0.757776;-0.652515;0.000000;,
  -0.728228;-0.685335;0.000000;,
  -0.834706;-0.550695;0.000000;,
  -0.810937;-0.585133;0.000000;,
  -0.892776;-0.450501;0.000000;,
  -0.875464;-0.483282;0.000000;,
  -0.945817;-0.324701;0.000000;,
  -0.928456;-0.371442;0.000000;,
  -0.995173;-0.098138;0.000000;,
  -0.982003;-0.188865;0.000000;,
  -0.992897;0.118977;0.000000;,
  -0.998442;0.055799;0.000000;,
  -0.994718;0.102641;0.000000;,
  -0.989841;0.142178;0.000000;,
  -0.840670;0.541548;0.000000;,
  -0.952553;0.304373;0.000000;,
  0.421678;-0.906746;-0.000000;,
  0.421678;-0.906746;-0.000000;,
  0.683309;-0.730129;-0.000000;,
  -0.485620;-0.874170;0.000000;,
  -0.177795;-0.984067;0.000000;,
  -0.965584;-0.260092;0.000000;,
  -0.866326;-0.499479;0.000000;,
  -0.884771;0.466026;0.000000;,
  -0.974896;0.222659;0.000000;,
  -0.698594;0.715518;0.000000;,
  -0.722731;0.691130;0.000000;,
  -0.707325;0.706888;0.000000;,
  -0.690678;0.723163;0.000000;,
  -0.735095;0.677964;0.000000;,
  -0.729364;0.684126;0.000000;,
  -0.747807;0.663916;0.000000;,
  -0.744301;0.667845;0.000000;,
  -0.754378;0.656441;0.000000;,
  -0.752837;0.658207;0.000000;,
  -0.747657;0.664085;0.000000;,
  -0.751800;0.659391;0.000000;,
  -0.731712;0.681614;0.000000;,
  -0.737627;0.675209;0.000000;,
  -0.711511;0.702675;0.000000;,
  -0.718665;0.695356;0.000000;,
  -0.686891;0.726760;0.000000;,
  -0.695639;0.718392;0.000000;,
  -0.657856;0.753144;0.000000;,
  -0.668013;0.744150;0.000000;,
  -0.602385;0.798206;0.000000;,
  -0.625255;0.780421;0.000000;,
  -0.506477;0.862253;0.000000;,
  -0.543295;0.839542;0.000000;,
  -0.381378;0.924419;0.000000;,
  -0.425628;0.904898;0.000000;,
  -0.236951;0.971522;0.000000;,
  -0.287100;0.957901;0.000000;,
  -0.075322;0.997159;0.000000;,
  -0.131103;0.991369;0.000000;,
  0.058481;0.998288;0.000000;,
  0.178291;0.983978;0.000000;,
  0.220246;0.975444;0.000000;,
  0.301366;0.953509;0.000000;,
  0.340561;0.940222;0.000000;,
  0.430063;0.902799;0.000000;,
  0.479836;0.877358;0.000000;,
  0.626487;0.779432;0.000000;,
  0.717138;0.696931;0.000000;,
  0.852996;0.521918;0.000000;,
  0.901804;0.432146;0.000000;,
  0.969558;0.244860;0.000000;,
  0.989055;0.147544;0.000000;,
  0.998948;-0.045867;-0.000000;,
  0.989876;-0.141936;-0.000000;,
  0.951963;-0.306213;-0.000000;,
  0.926889;-0.375336;-0.000000;,
  0.872601;-0.488434;-0.000000;,
  0.845753;-0.533574;-0.000000;,
  0.790562;-0.612383;-0.000000;,
  0.762891;-0.646527;-0.000000;,
  0.688960;-0.724799;-0.000000;,
  0.641106;-0.767452;-0.000000;,
  0.510946;-0.859613;-0.000000;,
  0.425568;-0.904926;-0.000000;,
  0.161149;-0.986930;-0.000000;,
  -0.289935;-0.957046;0.000000;,
  -0.155196;-0.987884;0.000000;,
  -0.752403;-0.658703;0.000000;,
  -0.594033;-0.804441;0.000000;,
  -0.985802;-0.167914;0.000000;,
  -0.941618;-0.336684;0.000000;,
  -0.951449;0.307808;0.000000;,
  -0.988019;0.154330;0.000000;,
  -0.752786;0.658265;0.000000;,
  -0.829960;0.557823;0.000000;,
  -0.665027;0.746819;0.000000;,
  -0.491299;-0.870991;0.000000;,
  -0.069450;-0.997586;0.000000;,
  0.472940;-0.881094;-0.000000;,
  0.574806;-0.818289;-0.000000;,
  0.712214;-0.701962;-0.000000;,
  0.754645;-0.656133;-0.000000;,
  0.814975;-0.579496;-0.000000;,
  0.834971;-0.550294;-0.000000;,
  0.865039;-0.501705;-0.000000;,
  0.875773;-0.482723;-0.000000;,
  0.895054;-0.445958;-0.000000;,
  0.903677;-0.428216;-0.000000;,
  0.921086;-0.389360;-0.000000;,
  0.929750;-0.368191;-0.000000;,
  0.947610;-0.319431;-0.000000;,
  0.956502;-0.291726;-0.000000;,
  0.973943;-0.226794;-0.000000;,
  0.981899;-0.189403;-0.000000;,
  0.994857;-0.101290;-0.000000;,
  0.998729;-0.050395;-0.000000;,
  0.996909;0.078560;0.000000;,
  0.987659;0.156617;0.000000;,
  0.940217;0.340576;0.000000;,
  0.895566;0.444930;0.000000;,
  0.725742;0.687967;0.000000;,
  0.580915;0.813964;0.000000;,
  0.295544;0.955329;0.000000;,
  0.162434;0.986719;0.000000;,
  -0.103966;0.994581;0.000000;,
  -0.329467;0.944167;0.000000;,
  -0.282463;0.959278;0.000000;,
  -0.426494;0.904491;0.000000;,
  -0.401171;0.916003;0.000000;,
  -0.493411;0.869796;0.000000;,
  -0.472567;0.881295;0.000000;,
  -0.549099;0.835758;0.000000;,
  -0.531642;0.846969;0.000000;,
  -0.596624;0.802521;0.000000;,
  -0.581566;0.813499;0.000000;,
  -0.639765;0.768570;0.000000;,
  -0.625718;0.780049;0.000000;,
  -0.679550;0.733629;0.000000;,
  -0.666673;0.745351;0.000000;,
  -0.709953;0.704249;0.000000;,
  -0.701139;0.713025;0.000000;,
  -0.715371;0.698745;0.000000;,
  -0.717016;0.697057;0.000000;,
  -0.699490;0.714643;0.000000;,
  -0.706642;0.707571;0.000000;,
  -0.648233;0.761442;0.000000;,
  -0.670555;0.741860;0.000000;,
  -0.416418;0.909173;0.000000;,
  -0.525652;0.850700;0.000000;,
  -0.302574;0.953126;0.000000;,
  0.685932;0.727666;0.000000;,
  0.913210;-0.407488;-0.000000;,
  0.861855;-0.507155;-0.000000;,
  0.952665;-0.304024;-0.000000;,
  0.783068;-0.621936;-0.000000;,
  0.764985;-0.644049;-0.000000;,
  0.735020;-0.678046;-0.000000;,
  0.723537;-0.690286;-0.000000;,
  0.699110;-0.715014;-0.000000;,
  0.686136;-0.727473;-0.000000;;
  356;
  3;0,2,0;,
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
  3;0,0,2;,
  3;3,4,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;4,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;3,3,3;,
  3;5,6,7;,
  3;5,7,8;,
  3;9,10,6;,
  3;9,6,5;,
  3;11,12,10;,
  3;11,10,9;,
  3;13,14,12;,
  3;13,12,11;,
  3;15,15,14;,
  3;15,14,13;,
  3;15,16,17;,
  3;15,17,15;,
  3;16,18,19;,
  3;16,19,17;,
  3;18,20,21;,
  3;18,21,19;,
  3;20,22,23;,
  3;20,23,21;,
  3;22,24,25;,
  3;22,25,23;,
  3;24,26,27;,
  3;24,27,25;,
  3;26,28,29;,
  3;26,29,27;,
  3;28,30,31;,
  3;28,31,29;,
  3;30,32,33;,
  3;30,33,31;,
  3;32,34,35;,
  3;32,35,33;,
  3;34,36,37;,
  3;34,37,35;,
  3;36,38,39;,
  3;36,39,37;,
  3;38,1,1;,
  3;38,1,39;,
  3;40,41,42;,
  3;40,42,42;,
  3;40,43,44;,
  3;40,44,41;,
  3;43,45,46;,
  3;43,46,44;,
  3;45,47,48;,
  3;45,48,46;,
  3;47,49,50;,
  3;47,50,48;,
  3;49,51,52;,
  3;49,52,50;,
  3;51,53,54;,
  3;51,54,52;,
  3;53,55,56;,
  3;53,56,54;,
  3;55,57,58;,
  3;55,58,56;,
  3;57,59,60;,
  3;57,60,58;,
  3;59,61,62;,
  3;59,62,60;,
  3;61,63,64;,
  3;61,64,62;,
  3;63,65,66;,
  3;63,66,64;,
  3;65,67,68;,
  3;65,68,66;,
  3;67,69,70;,
  3;67,70,68;,
  3;69,71,72;,
  3;69,72,70;,
  3;71,73,74;,
  3;71,74,72;,
  3;73,75,76;,
  3;73,76,74;,
  3;75,77,78;,
  3;75,78,76;,
  3;77,79,79;,
  3;77,79,78;,
  3;80,81,79;,
  3;80,79,79;,
  3;82,83,81;,
  3;82,81,80;,
  3;84,85,83;,
  3;84,83,82;,
  3;86,87,85;,
  3;86,85,84;,
  3;88,89,87;,
  3;88,87,86;,
  3;90,91,89;,
  3;90,89,88;,
  3;92,93,91;,
  3;92,91,90;,
  3;94,95,93;,
  3;94,93,92;,
  3;96,97,95;,
  3;96,95,94;,
  3;98,99,97;,
  3;98,97,96;,
  3;100,101,99;,
  3;100,99,98;,
  3;102,103,101;,
  3;102,101,100;,
  3;104,104,103;,
  3;104,103,102;,
  3;104,105,106;,
  3;104,106,104;,
  3;105,107,108;,
  3;105,108,106;,
  3;107,109,110;,
  3;107,110,108;,
  3;109,111,112;,
  3;109,112,110;,
  3;111,113,114;,
  3;111,114,112;,
  3;113,115,115;,
  3;113,115,114;,
  3;116,117,117;,
  3;116,117,116;,
  3;118,119,117;,
  3;118,117,117;,
  3;120,121,119;,
  3;120,119,118;,
  3;122,123,121;,
  3;122,121,120;,
  3;124,125,123;,
  3;124,123,122;,
  3;126,127,125;,
  3;126,125,124;,
  3;128,129,127;,
  3;128,127,126;,
  3;130,131,129;,
  3;130,129,128;,
  3;132,133,131;,
  3;132,131,130;,
  3;134,135,133;,
  3;134,133,132;,
  3;136,137,135;,
  3;136,135,134;,
  3;138,139,137;,
  3;138,137,136;,
  3;140,141,139;,
  3;140,139,138;,
  3;142,143,141;,
  3;142,141,140;,
  3;144,144,143;,
  3;144,143,142;,
  3;144,145,146;,
  3;144,146,144;,
  3;145,147,148;,
  3;145,148,146;,
  3;147,149,150;,
  3;147,150,148;,
  3;149,151,152;,
  3;149,152,150;,
  3;151,153,154;,
  3;151,154,152;,
  3;153,155,156;,
  3;153,156,154;,
  3;155,157,158;,
  3;155,158,156;,
  3;157,159,160;,
  3;157,160,158;,
  3;159,161,162;,
  3;159,162,160;,
  3;161,163,164;,
  3;161,164,162;,
  3;163,165,166;,
  3;163,166,164;,
  3;165,167,168;,
  3;165,168,166;,
  3;167,169,169;,
  3;167,169,168;,
  3;170,170,170;,
  3;170,170,170;,
  3;171,172,173;,
  3;171,173,173;,
  3;174,175,172;,
  3;174,172,171;,
  3;176,177,175;,
  3;176,175,174;,
  3;178,179,177;,
  3;178,177,176;,
  3;8,7,179;,
  3;8,179,178;;
 }
 MeshTextureCoords {
  180;
  1.984726;0.542671;
  1.976120;0.533736;
  1.975832;0.518885;
  1.985615;0.507926;
  1.993704;0.500552;
  2.000146;0.540838;
  2.001716;0.492154;
  1.996477;0.584002;
  1.996372;0.569777;
  1.999333;0.553729;
  2.001136;0.600149;
  2.012000;0.480814;
  2.007775;0.614613;
  2.013832;0.624685;
  2.024520;0.466561;
  2.020793;0.633529;
  2.028589;0.641114;
  2.039524;0.449236;
  2.037155;0.647403;
  2.049056;0.653634;
  2.055626;0.431334;
  2.065232;0.658579;
  2.071440;0.414652;
  2.078388;0.660187;
  2.086992;0.399224;
  2.099376;0.659240;
  2.102323;0.385082;
  2.106511;0.558277;
  2.118584;0.371262;
  2.108683;0.544135;
  2.113087;0.528031;
  2.119758;0.509993;
  2.137327;0.357951;
  2.128727;0.490057;
  2.142700;0.463347;
  2.156404;0.347826;
  2.159367;0.436000;
  2.175819;0.340892;
  2.175127;0.415418;
  2.190972;0.401226;
  2.195570;0.337147;
  2.208327;0.394403;
  2.216619;0.336737;
  2.198343;0.446121;
  2.198358;0.428453;
  2.206635;0.412037;
  2.206880;0.461278;
  2.219414;0.400657;
  2.220747;0.467636;
  2.234471;0.339189;
  2.237105;0.467965;
  2.247441;0.342706;
  2.251891;0.462671;
  2.257670;0.346897;
  2.264054;0.453764;
  2.269975;0.354547;
  2.272149;0.445020;
  2.278294;0.436325;
  2.282069;0.370446;
  2.284707;0.423313;
  2.288153;0.387339;
  2.289053;0.405404;
  2.106518;0.570745;
  2.109261;0.582182;
  2.125386;0.653806;
  2.115628;0.592045;
  2.126072;0.596891;
  2.157181;0.641319;
  2.143217;0.597385;
  2.157122;0.594024;
  2.167630;0.589767;
  2.190434;0.622007;
  2.179027;0.584000;
  2.190041;0.577401;
  2.200004;0.570555;
  2.224809;0.595981;
  2.209516;0.563205;
  2.218611;0.555350;
  2.227324;0.546993;
  2.253837;0.569571;
  2.236758;0.537243;
  2.245800;0.528029;
  2.256802;0.517475;
  2.269879;0.553312;
  2.267305;0.509058;
  2.282109;0.504358;
  2.282136;0.539570;
  2.290539;0.528347;
  2.294474;0.516015;
  1.975832;0.518885;
  1.976120;0.533736;
  1.984726;0.542671;
  1.985615;0.507926;
  1.993704;0.500552;
  2.000146;0.540838;
  2.001716;0.492154;
  1.999333;0.553729;
  1.996372;0.569777;
  1.996477;0.584002;
  2.001136;0.600149;
  2.012000;0.480814;
  2.007775;0.614613;
  2.013832;0.624685;
  2.024520;0.466561;
  2.020793;0.633529;
  2.028589;0.641114;
  2.039524;0.449236;
  2.037155;0.647403;
  2.049056;0.653634;
  2.055626;0.431334;
  2.065232;0.658579;
  2.071440;0.414652;
  2.078388;0.660187;
  2.086992;0.399224;
  2.099376;0.659240;
  2.102323;0.385082;
  2.109261;0.582182;
  2.125386;0.653806;
  2.115628;0.592045;
  2.126072;0.596891;
  2.157181;0.641319;
  2.143217;0.597385;
  2.157122;0.594024;
  2.167630;0.589767;
  2.190434;0.622007;
  2.179027;0.584000;
  2.190041;0.577401;
  2.200004;0.570555;
  2.224809;0.595981;
  2.209516;0.563205;
  2.218611;0.555350;
  2.227324;0.546993;
  2.253837;0.569571;
  2.236758;0.537243;
  2.245800;0.528029;
  2.256802;0.517475;
  2.269879;0.553312;
  2.267305;0.509058;
  2.282109;0.504358;
  2.282136;0.539570;
  2.290539;0.528347;
  2.294474;0.516015;
  2.106518;0.570745;
  2.106511;0.558277;
  2.118584;0.371262;
  2.108683;0.544135;
  2.113087;0.528031;
  2.119758;0.509993;
  2.137327;0.357951;
  2.128727;0.490057;
  2.142700;0.463347;
  2.156404;0.347826;
  2.159367;0.436000;
  2.175819;0.340892;
  2.175127;0.415418;
  2.190972;0.401226;
  2.195570;0.337147;
  2.208327;0.394403;
  2.216619;0.336737;
  2.206635;0.412037;
  2.198358;0.428453;
  2.198343;0.446121;
  2.206880;0.461278;
  2.219414;0.400657;
  2.220747;0.467636;
  2.234471;0.339189;
  2.237105;0.467965;
  2.247441;0.342706;
  2.251891;0.462671;
  2.257670;0.346897;
  2.264054;0.453764;
  2.269975;0.354547;
  2.272149;0.445020;
  2.278294;0.436325;
  2.282069;0.370446;
  2.284707;0.423313;
  2.288153;0.387339;
  2.289053;0.405404;
  2.014895;0.527035;
  2.014895;0.527035;;
 }
}