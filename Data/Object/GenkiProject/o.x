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
 186;
 0.32062;-0.01930;-0.05673;,
 0.31896;-0.01174;-0.05673;,
 0.32478;-0.00296;-0.05673;,
 0.32680;-0.02058;-0.05673;,
 0.33153;0.00525;-0.05673;,
 0.32705;-0.04714;-0.05673;,
 0.32621;-0.04025;-0.05673;,
 0.32617;-0.03310;-0.05673;,
 0.32680;-0.02654;-0.05673;,
 0.32870;-0.05334;-0.05673;,
 0.33115;-0.05891;-0.05673;,
 0.33440;-0.06387;-0.05673;,
 0.33856;0.01343;-0.05673;,
 0.33842;-0.06821;-0.05673;,
 0.34284;-0.07158;-0.05673;,
 0.34582;0.02158;-0.05673;,
 0.34780;-0.07414;-0.05673;,
 0.35329;0.02967;-0.05673;,
 0.35348;-0.07592;-0.05673;,
 0.36330;0.04023;-0.05673;,
 0.35973;-0.07682;-0.05673;,
 0.36940;-0.07665;-0.05673;,
 0.37439;0.05098;-0.05673;,
 0.38104;-0.07448;-0.05673;,
 0.37948;-0.02895;-0.05673;,
 0.38500;0.06005;-0.05673;,
 0.38157;-0.01990;-0.05673;,
 0.38480;-0.01137;-0.05673;,
 0.38945;-0.00129;-0.05673;,
 0.39514;0.06742;-0.05673;,
 0.39553;0.01034;-0.05673;,
 0.40479;0.07312;-0.05673;,
 0.40396;0.02517;-0.05673;,
 0.41664;-0.05220;-0.05673;,
 0.40231;-0.03756;-0.05673;,
 0.40597;-0.03230;-0.05673;,
 0.41202;0.03739;-0.05673;,
 0.41143;0.07624;-0.05673;,
 0.40572;-0.01421;-0.05673;,
 0.40537;-0.00806;-0.05673;,
 0.40676;-0.00143;-0.05673;,
 0.40966;-0.02512;-0.05673;,
 0.40744;-0.02052;-0.05673;,
 0.41173;0.00515;-0.05673;,
 0.41644;0.07811;-0.05673;,
 0.41935;0.04629;-0.05673;,
 0.41934;0.00777;-0.05673;,
 0.42141;0.07949;-0.05673;,
 0.43047;-0.03890;-0.05673;,
 0.42410;0.05056;-0.05673;,
 0.42757;0.00748;-0.05673;,
 0.42879;0.08061;-0.05673;,
 0.43036;0.05358;-0.05673;,
 0.43341;0.01682;-0.05673;,
 0.43825;0.08052;-0.05673;,
 0.43828;0.05203;-0.05673;,
 0.43721;-0.04037;-0.05673;,
 0.43706;0.02530;-0.05673;,
 0.43966;0.03277;-0.05673;,
 0.44351;0.07938;-0.05673;,
 0.44225;-0.04007;-0.05673;,
 0.44123;0.03925;-0.05673;,
 0.44167;0.04576;-0.05673;,
 0.45033;-0.01156;-0.05673;,
 0.45003;0.07626;-0.05673;,
 0.45062;-0.00494;-0.05673;,
 0.45615;0.00756;-0.05673;,
 0.45573;0.07156;-0.05673;,
 0.45904;0.06718;-0.05673;,
 0.46038;0.01920;-0.05673;,
 0.46232;0.06083;-0.05673;,
 0.46329;0.03000;-0.05673;,
 0.46411;0.05534;-0.05673;,
 0.46486;0.03997;-0.05673;,
 0.46501;0.04885;-0.05673;,
 0.45009;-0.03862;-0.05673;,
 0.45448;-0.01713;-0.05673;,
 0.45770;-0.03574;-0.05673;,
 0.46219;-0.01372;-0.05673;,
 0.46517;-0.03128;-0.05673;,
 0.46730;-0.00876;-0.05673;,
 0.47272;-0.02487;-0.05673;,
 0.47150;-0.00319;-0.05673;,
 0.47699;-0.00075;-0.05673;,
 0.47982;-0.01670;-0.05673;,
 0.48324;-0.01216;-0.05673;,
 0.48466;-0.00492;-0.05673;,
 0.37971;-0.03569;-0.05673;,
 0.38227;-0.04048;-0.05673;,
 0.39231;-0.07016;-0.05673;,
 0.38867;-0.04389;-0.05673;,
 0.39589;-0.04260;-0.05673;,
 0.40406;-0.06307;-0.05673;,
 0.32478;-0.00296;0.06027;,
 0.31896;-0.01174;0.06027;,
 0.32062;-0.01930;0.06027;,
 0.32680;-0.02058;0.06027;,
 0.33153;0.00525;0.06027;,
 0.32617;-0.03310;0.06027;,
 0.32621;-0.04025;0.06027;,
 0.32705;-0.04714;0.06027;,
 0.32680;-0.02654;0.06027;,
 0.32870;-0.05334;0.06027;,
 0.33115;-0.05891;0.06027;,
 0.33440;-0.06387;0.06027;,
 0.33856;0.01343;0.06027;,
 0.33842;-0.06821;0.06027;,
 0.34284;-0.07158;0.06027;,
 0.34582;0.02158;0.06027;,
 0.34780;-0.07414;0.06027;,
 0.35329;0.02967;0.06027;,
 0.35348;-0.07592;0.06027;,
 0.36330;0.04023;0.06027;,
 0.35973;-0.07682;0.06027;,
 0.36940;-0.07665;0.06027;,
 0.37439;0.05098;0.06027;,
 0.38104;-0.07448;0.06027;,
 0.37948;-0.02895;0.06027;,
 0.37971;-0.03569;0.06027;,
 0.38227;-0.04048;0.06027;,
 0.39231;-0.07016;0.06027;,
 0.38867;-0.04389;0.06027;,
 0.39589;-0.04260;0.06027;,
 0.40406;-0.06307;0.06027;,
 0.40231;-0.03756;0.06027;,
 0.41664;-0.05220;0.06027;,
 0.38500;0.06005;0.06027;,
 0.38157;-0.01990;0.06027;,
 0.38480;-0.01137;0.06027;,
 0.38945;-0.00129;0.06027;,
 0.39514;0.06742;0.06027;,
 0.39553;0.01034;0.06027;,
 0.40479;0.07312;0.06027;,
 0.40396;0.02517;0.06027;,
 0.40597;-0.03230;0.06027;,
 0.41202;0.03739;0.06027;,
 0.41143;0.07624;0.06027;,
 0.40676;-0.00143;0.06027;,
 0.40537;-0.00806;0.06027;,
 0.40572;-0.01421;0.06027;,
 0.40966;-0.02512;0.06027;,
 0.40744;-0.02052;0.06027;,
 0.41173;0.00515;0.06027;,
 0.41644;0.07811;0.06027;,
 0.41935;0.04629;0.06027;,
 0.41934;0.00777;0.06027;,
 0.42141;0.07949;0.06027;,
 0.43047;-0.03890;0.06027;,
 0.42410;0.05056;0.06027;,
 0.42757;0.00748;0.06027;,
 0.42879;0.08061;0.06027;,
 0.43036;0.05358;0.06027;,
 0.43341;0.01682;0.06027;,
 0.43825;0.08052;0.06027;,
 0.43828;0.05203;0.06027;,
 0.43721;-0.04037;0.06027;,
 0.43706;0.02530;0.06027;,
 0.43966;0.03277;0.06027;,
 0.44351;0.07938;0.06027;,
 0.44225;-0.04007;0.06027;,
 0.44123;0.03925;0.06027;,
 0.44167;0.04576;0.06027;,
 0.45033;-0.01156;0.06027;,
 0.45009;-0.03862;0.06027;,
 0.45448;-0.01713;0.06027;,
 0.45770;-0.03574;0.06027;,
 0.46219;-0.01372;0.06027;,
 0.46517;-0.03128;0.06027;,
 0.46730;-0.00876;0.06027;,
 0.47272;-0.02487;0.06027;,
 0.47150;-0.00319;0.06027;,
 0.47699;-0.00075;0.06027;,
 0.47982;-0.01670;0.06027;,
 0.48324;-0.01216;0.06027;,
 0.48466;-0.00492;0.06027;,
 0.45003;0.07626;0.06027;,
 0.45062;-0.00494;0.06027;,
 0.45615;0.00756;0.06027;,
 0.45573;0.07156;0.06027;,
 0.45904;0.06718;0.06027;,
 0.46038;0.01920;0.06027;,
 0.46232;0.06083;0.06027;,
 0.46329;0.03000;0.06027;,
 0.46411;0.05534;0.06027;,
 0.46486;0.03997;0.06027;,
 0.46501;0.04885;0.06027;;
 
 372;
 3;0,1,2;,
 3;3,0,2;,
 3;3,2,4;,
 3;5,6,7;,
 3;5,7,8;,
 3;5,8,3;,
 3;9,5,3;,
 3;9,3,4;,
 3;10,9,4;,
 3;11,10,4;,
 3;11,4,12;,
 3;13,11,12;,
 3;14,13,12;,
 3;14,12,15;,
 3;16,14,15;,
 3;16,15,17;,
 3;18,16,17;,
 3;18,17,19;,
 3;20,18,19;,
 3;21,20,19;,
 3;21,19,22;,
 3;23,21,22;,
 3;24,22,25;,
 3;26,24,25;,
 3;27,26,25;,
 3;28,27,25;,
 3;28,25,29;,
 3;30,28,29;,
 3;30,29,31;,
 3;32,30,31;,
 3;33,34,35;,
 3;36,32,31;,
 3;36,31,37;,
 3;38,39,40;,
 3;33,35,41;,
 3;42,38,40;,
 3;42,40,43;,
 3;41,42,43;,
 3;33,41,43;,
 3;36,37,44;,
 3;45,36,44;,
 3;33,43,46;,
 3;45,44,47;,
 3;48,33,46;,
 3;49,45,47;,
 3;48,46,50;,
 3;49,47,51;,
 3;52,49,51;,
 3;48,50,53;,
 3;52,51,54;,
 3;55,52,54;,
 3;56,48,53;,
 3;56,53,57;,
 3;56,57,58;,
 3;55,54,59;,
 3;60,56,58;,
 3;60,58,61;,
 3;62,55,59;,
 3;60,61,62;,
 3;60,62,59;,
 3;63,60,59;,
 3;63,59,64;,
 3;65,63,64;,
 3;66,65,64;,
 3;66,64,67;,
 3;66,67,68;,
 3;69,66,68;,
 3;69,68,70;,
 3;71,69,70;,
 3;71,70,72;,
 3;73,71,72;,
 3;73,72,74;,
 3;75,60,63;,
 3;76,75,63;,
 3;77,75,76;,
 3;77,76,78;,
 3;79,77,78;,
 3;79,78,80;,
 3;81,79,80;,
 3;81,80,82;,
 3;81,82,83;,
 3;84,81,83;,
 3;85,84,83;,
 3;85,83,86;,
 3;23,22,24;,
 3;23,24,87;,
 3;23,87,88;,
 3;89,23,88;,
 3;89,88,90;,
 3;89,90,91;,
 3;92,89,91;,
 3;92,91,34;,
 3;92,34,33;,
 3;93,94,95;,
 3;93,95,96;,
 3;97,93,96;,
 3;98,99,100;,
 3;101,98,100;,
 3;96,101,100;,
 3;96,100,102;,
 3;97,96,102;,
 3;97,102,103;,
 3;97,103,104;,
 3;105,97,104;,
 3;105,104,106;,
 3;105,106,107;,
 3;108,105,107;,
 3;108,107,109;,
 3;110,108,109;,
 3;110,109,111;,
 3;112,110,111;,
 3;112,111,113;,
 3;112,113,114;,
 3;115,112,114;,
 3;115,114,116;,
 3;117,115,116;,
 3;118,117,116;,
 3;119,118,116;,
 3;119,116,120;,
 3;121,119,120;,
 3;122,121,120;,
 3;122,120,123;,
 3;124,122,123;,
 3;124,123,125;,
 3;126,115,117;,
 3;126,117,127;,
 3;126,127,128;,
 3;126,128,129;,
 3;130,126,129;,
 3;130,129,131;,
 3;132,130,131;,
 3;132,131,133;,
 3;134,124,125;,
 3;132,133,135;,
 3;136,132,135;,
 3;137,138,139;,
 3;140,134,125;,
 3;137,139,141;,
 3;142,137,141;,
 3;142,141,140;,
 3;142,140,125;,
 3;143,136,135;,
 3;143,135,144;,
 3;145,142,125;,
 3;146,143,144;,
 3;145,125,147;,
 3;146,144,148;,
 3;149,145,147;,
 3;150,146,148;,
 3;150,148,151;,
 3;152,149,147;,
 3;153,150,151;,
 3;153,151,154;,
 3;152,147,155;,
 3;156,152,155;,
 3;157,156,155;,
 3;158,153,154;,
 3;157,155,159;,
 3;160,157,159;,
 3;158,154,161;,
 3;161,160,159;,
 3;158,161,159;,
 3;162,159,163;,
 3;164,163,165;,
 3;166,164,165;,
 3;166,165,167;,
 3;168,166,167;,
 3;168,167,169;,
 3;170,168,169;,
 3;171,170,169;,
 3;171,169,172;,
 3;171,172,173;,
 3;174,171,173;,
 3;162,163,164;,
 3;158,159,162;,
 3;175,158,162;,
 3;175,162,176;,
 3;175,176,177;,
 3;178,175,177;,
 3;179,178,177;,
 3;179,177,180;,
 3;181,179,180;,
 3;181,180,182;,
 3;183,181,182;,
 3;183,182,184;,
 3;185,183,184;,
 3;125,33,48;,
 3;125,48,147;,
 3;124,134,35;,
 3;124,35,34;,
 3;134,140,41;,
 3;134,41,35;,
 3;140,141,42;,
 3;140,42,41;,
 3;141,139,38;,
 3;141,38,42;,
 3;139,138,39;,
 3;139,39,38;,
 3;138,137,40;,
 3;138,40,39;,
 3;137,142,43;,
 3;137,43,40;,
 3;142,145,46;,
 3;142,46,43;,
 3;149,50,46;,
 3;149,46,145;,
 3;149,152,53;,
 3;149,53,50;,
 3;152,156,57;,
 3;152,57,53;,
 3;156,157,58;,
 3;156,58,57;,
 3;157,160,61;,
 3;157,61,58;,
 3;160,161,62;,
 3;160,62,61;,
 3;161,154,55;,
 3;161,55,62;,
 3;154,151,52;,
 3;154,52,55;,
 3;148,49,52;,
 3;148,52,151;,
 3;144,45,49;,
 3;144,49,148;,
 3;135,36,45;,
 3;135,45,144;,
 3;133,32,36;,
 3;133,36,135;,
 3;131,30,32;,
 3;131,32,133;,
 3;129,28,30;,
 3;129,30,131;,
 3;128,27,28;,
 3;128,28,129;,
 3;127,26,27;,
 3;127,27,128;,
 3;117,24,26;,
 3;117,26,127;,
 3;118,87,24;,
 3;118,24,117;,
 3;119,88,87;,
 3;119,87,118;,
 3;121,90,88;,
 3;121,88,119;,
 3;121,122,91;,
 3;121,91,90;,
 3;122,124,34;,
 3;122,34,91;,
 3;123,92,33;,
 3;123,33,125;,
 3;120,89,92;,
 3;120,92,123;,
 3;116,23,89;,
 3;116,89,120;,
 3;114,21,23;,
 3;114,23,116;,
 3;113,20,21;,
 3;113,21,114;,
 3;113,111,18;,
 3;113,18,20;,
 3;111,109,16;,
 3;111,16,18;,
 3;109,107,14;,
 3;109,14,16;,
 3;107,106,13;,
 3;107,13,14;,
 3;106,104,11;,
 3;106,11,13;,
 3;104,103,10;,
 3;104,10,11;,
 3;103,102,9;,
 3;103,9,10;,
 3;102,100,5;,
 3;102,5,9;,
 3;100,99,6;,
 3;100,6,5;,
 3;99,98,7;,
 3;99,7,6;,
 3;98,101,8;,
 3;98,8,7;,
 3;101,96,3;,
 3;101,3,8;,
 3;96,95,0;,
 3;96,0,3;,
 3;95,94,1;,
 3;95,1,0;,
 3;94,93,2;,
 3;94,2,1;,
 3;93,97,4;,
 3;93,4,2;,
 3;97,105,12;,
 3;97,12,4;,
 3;105,108,15;,
 3;105,15,12;,
 3;108,110,17;,
 3;108,17,15;,
 3;110,112,19;,
 3;110,19,17;,
 3;112,115,22;,
 3;112,22,19;,
 3;115,126,25;,
 3;115,25,22;,
 3;126,130,29;,
 3;126,29,25;,
 3;130,132,31;,
 3;130,31,29;,
 3;132,136,37;,
 3;132,37,31;,
 3;136,143,44;,
 3;136,44,37;,
 3;143,146,47;,
 3;143,47,44;,
 3;146,150,51;,
 3;146,51,47;,
 3;153,54,51;,
 3;153,51,150;,
 3;158,59,54;,
 3;158,54,153;,
 3;175,64,59;,
 3;175,59,158;,
 3;178,67,64;,
 3;178,64,175;,
 3;179,68,67;,
 3;179,67,178;,
 3;181,70,68;,
 3;181,68,179;,
 3;183,72,70;,
 3;183,70,181;,
 3;185,74,72;,
 3;185,72,183;,
 3;184,73,74;,
 3;184,74,185;,
 3;182,71,73;,
 3;182,73,184;,
 3;180,69,71;,
 3;180,71,182;,
 3;177,66,69;,
 3;177,69,180;,
 3;176,65,66;,
 3;176,66,177;,
 3;162,63,65;,
 3;162,65,176;,
 3;164,76,63;,
 3;164,63,162;,
 3;164,166,78;,
 3;164,78,76;,
 3;166,168,80;,
 3;166,80,78;,
 3;168,170,82;,
 3;168,82,80;,
 3;170,171,83;,
 3;170,83,82;,
 3;174,86,83;,
 3;174,83,171;,
 3;173,85,86;,
 3;173,86,174;,
 3;172,84,85;,
 3;172,85,173;,
 3;169,81,84;,
 3;169,84,172;,
 3;167,79,81;,
 3;167,81,169;,
 3;165,77,79;,
 3;165,79,167;,
 3;163,75,77;,
 3;163,77,165;,
 3;159,60,75;,
 3;159,75,163;,
 3;155,56,60;,
 3;155,60,159;,
 3;155,147,48;,
 3;155,48,56;;
 
 MeshMaterialList {
  1;
  372;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  186;
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.680099;-0.733121;-0.000000;,
  0.667111;-0.744959;-0.000000;,
  0.272154;-0.962254;-0.000000;,
  0.272154;-0.962254;-0.000000;,
  -0.760225;0.649660;0.000000;,
  -0.868552;0.495599;0.000000;,
  -0.845350;0.534214;0.000000;,
  -0.691878;0.722014;0.000000;,
  -0.988444;-0.151588;0.000000;,
  -0.984489;0.175446;0.000000;,
  -0.947150;-0.320792;0.000000;,
  -0.925634;-0.378419;0.000000;,
  -0.992032;-0.125984;0.000000;,
  -0.980860;-0.194714;0.000000;,
  -0.992914;0.118832;0.000000;,
  -0.999528;0.030705;0.000000;,
  -0.876921;0.480635;0.000000;,
  -0.938512;0.345245;0.000000;,
  -0.502571;0.864536;0.000000;,
  -0.666209;0.745765;0.000000;,
  -0.147944;0.988996;0.000000;,
  0.034947;0.999389;0.000000;,
  -0.848166;0.529730;0.000000;,
  -0.897379;0.441261;0.000000;,
  -0.873861;0.486175;0.000000;,
  -0.936154;0.351591;0.000000;,
  -0.927602;0.373571;0.000000;,
  -0.963787;0.266672;0.000000;,
  -0.954495;0.298228;0.000000;,
  -0.992313;0.123755;0.000000;,
  -0.983724;0.179684;0.000000;,
  -0.952369;-0.304948;0.000000;,
  -0.993079;-0.117446;0.000000;,
  -0.459690;-0.888079;0.000000;,
  -0.710515;-0.703682;0.000000;,
  0.127644;-0.991820;-0.000000;,
  0.516833;-0.856086;-0.000000;,
  0.596259;-0.802792;-0.000000;,
  0.705347;-0.708862;-0.000000;,
  0.739477;-0.673181;-0.000000;,
  0.793752;-0.608241;-0.000000;,
  0.814807;-0.579732;-0.000000;,
  0.846694;-0.532080;-0.000000;,
  0.858172;-0.513363;-0.000000;,
  0.875064;-0.484007;-0.000000;,
  0.880775;-0.473535;-0.000000;,
  0.893884;-0.448299;-0.000000;,
  0.901166;-0.433474;-0.000000;,
  0.917560;-0.397597;-0.000000;,
  0.926441;-0.376440;-0.000000;,
  0.950018;-0.312195;-0.000000;,
  0.963264;-0.268556;-0.000000;,
  0.990200;-0.139660;-0.000000;,
  0.998585;-0.053181;-0.000000;,
  0.982999;0.183610;0.000000;,
  0.942791;0.333385;0.000000;,
  0.774179;0.632966;0.000000;,
  0.631682;0.775228;0.000000;,
  0.155776;0.987792;0.000000;,
  0.155776;0.987792;0.000000;,
  -0.483047;0.875594;0.000000;,
  -0.331949;0.943297;0.000000;,
  0.610087;-0.792334;-0.000000;,
  0.564151;-0.825672;-0.000000;,
  0.465234;-0.885188;-0.000000;,
  0.412138;-0.911122;0.000003;,
  0.300728;-0.953710;0.000005;,
  0.242346;-0.970190;0.000005;,
  0.128408;-0.991722;0.000003;,
  0.072954;-0.997335;-0.000000;,
  -0.062674;-0.998034;0.000000;,
  -0.247453;-0.968900;0.000000;,
  -0.195141;-0.980775;0.000000;,
  -0.406612;-0.913601;0.000000;,
  -0.353256;-0.935527;0.000000;,
  -0.558682;-0.829382;0.000000;,
  -0.509344;-0.860563;0.000000;,
  -0.693276;-0.720672;0.000000;,
  -0.650622;-0.759402;0.000000;,
  -0.804511;-0.593937;0.000000;,
  -0.770144;-0.637870;0.000000;,
  -0.891755;-0.452520;0.000000;,
  -0.865301;-0.501252;0.000000;,
  -0.952046;-0.305954;0.000000;,
  -0.934946;-0.354790;0.000000;,
  -0.985943;-0.167083;0.000000;,
  -0.977264;-0.212025;0.000000;,
  -0.999050;-0.043586;0.000000;,
  -0.996564;-0.082830;0.000000;,
  -0.998085;0.061862;0.000000;,
  -0.999586;0.028761;0.000000;,
  -0.999488;0.031988;0.000000;,
  -0.997984;0.063471;0.000000;,
  -1.000000;0.000505;0.000000;,
  -1.000000;0.000505;0.000000;,
  -0.202144;-0.979356;0.000000;,
  -0.202144;-0.979356;0.000000;,
  -0.976764;-0.214316;0.000000;,
  -0.947646;0.319323;0.000000;,
  -0.999013;0.044427;0.000000;,
  -0.793611;0.608425;0.000000;,
  -0.814029;0.580825;0.000000;,
  -0.763375;0.645956;0.000000;,
  -0.767848;0.640632;0.000000;,
  -0.750563;0.660799;0.000000;,
  -0.754729;0.656037;0.000000;,
  -0.738589;0.674156;0.000000;,
  -0.742490;0.669857;0.000000;,
  -0.728979;0.684537;0.000000;,
  -0.731827;0.681490;0.000000;,
  -0.706063;0.708149;0.000000;,
  -0.716165;0.697931;0.000000;,
  -0.665186;0.746678;0.000000;,
  -0.680654;0.732605;0.000000;,
  -0.609346;0.792904;0.000000;,
  -0.629606;0.776914;0.000000;,
  -0.535572;0.844490;0.000000;,
  -0.562437;0.826840;0.000000;,
  -0.453145;0.891437;0.000000;,
  -0.480914;0.876768;0.000000;,
  -0.375082;0.926992;0.000000;,
  -0.400177;0.916438;0.000000;,
  -0.295633;0.955302;0.000000;,
  -0.322823;0.946459;0.000000;,
  -0.189476;0.981885;0.000000;,
  -0.229070;0.973410;0.000000;,
  -0.070602;0.997505;0.000000;,
  0.077036;0.997028;0.000000;,
  0.145149;0.989410;0.000000;,
  0.287140;0.957889;0.000000;,
  0.360732;0.932669;0.000000;,
  0.503182;0.864180;0.000000;,
  0.571795;0.820397;0.000000;,
  0.694252;0.719732;0.000000;,
  0.748412;0.663234;0.000000;,
  0.830720;0.556691;0.000000;,
  0.861142;0.508365;0.000000;,
  0.912014;0.410160;0.000000;,
  0.932781;0.360444;0.000000;,
  0.967366;0.253382;0.000000;,
  0.980633;0.195856;0.000000;,
  0.996268;0.086316;0.000000;,
  0.999408;0.034409;0.000000;,
  0.997975;-0.063599;-0.000000;,
  0.993964;-0.109710;-0.000000;,
  0.981679;-0.190541;-0.000000;,
  0.974267;-0.225396;-0.000000;,
  0.957838;-0.287308;-0.000000;,
  0.949263;-0.314483;-0.000000;,
  0.931915;-0.362677;-0.000000;,
  0.923418;-0.383796;-0.000000;,
  0.957405;-0.288749;-0.000000;,
  0.986049;-0.166457;-0.000000;,
  0.983815;0.179185;0.000000;,
  0.914670;0.404201;0.000000;,
  0.802238;0.597004;0.000000;,
  -0.404543;0.914519;0.000000;,
  -0.607713;0.794156;0.000000;,
  -0.508978;0.860780;0.000000;,
  -0.404543;0.914519;0.000000;,
  -0.766482;0.642265;0.000000;,
  -0.732477;0.680792;0.000000;,
  -0.552905;0.833244;0.000000;,
  -0.687232;0.726438;0.000000;,
  0.039781;0.999209;0.000000;,
  0.478106;0.878302;0.000000;,
  0.478106;0.878302;0.000000;,
  0.941771;-0.336255;-0.000000;,
  0.879477;-0.475942;-0.000000;,
  0.981370;-0.192126;-0.000000;,
  0.981370;-0.192126;-0.000000;,
  0.784407;-0.620246;-0.000000;,
  0.769665;-0.638448;-0.000000;,
  0.720722;-0.693224;-0.000000;,
  0.685039;-0.728507;-0.000000;,
  0.604349;-0.796719;-0.000000;,
  0.558958;-0.829196;-0.000000;,
  0.460972;-0.887415;-0.000000;,
  0.408216;-0.912885;-0.000000;,
  0.297766;-0.954639;-0.000000;,
  0.240013;-0.970770;-0.000000;,
  0.141332;-0.989962;-0.000000;,
  0.100751;-0.994912;-0.000000;,
  -0.076972;-0.997033;0.000000;;
  372;
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
  3;1,1,1;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;0,0,0;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;1,1,1;,
  3;2,3,4;,
  3;2,4,5;,
  3;6,7,8;,
  3;6,8,9;,
  3;7,10,11;,
  3;7,11,8;,
  3;10,12,13;,
  3;10,13,11;,
  3;12,14,15;,
  3;12,15,13;,
  3;14,16,17;,
  3;14,17,15;,
  3;16,18,19;,
  3;16,19,17;,
  3;18,20,21;,
  3;18,21,19;,
  3;20,22,22;,
  3;20,22,21;,
  3;23,23,22;,
  3;23,22,22;,
  3;24,25,26;,
  3;24,26,24;,
  3;25,27,28;,
  3;25,28,26;,
  3;27,29,30;,
  3;27,30,28;,
  3;29,31,32;,
  3;29,32,30;,
  3;31,33,34;,
  3;31,34,32;,
  3;33,35,36;,
  3;33,36,34;,
  3;35,37,37;,
  3;35,37,36;,
  3;38,39,37;,
  3;38,37,37;,
  3;40,41,39;,
  3;40,39,38;,
  3;42,43,41;,
  3;42,41,40;,
  3;44,45,43;,
  3;44,43,42;,
  3;46,47,45;,
  3;46,45,44;,
  3;48,49,47;,
  3;48,47,46;,
  3;50,51,49;,
  3;50,49,48;,
  3;52,53,51;,
  3;52,51,50;,
  3;54,55,53;,
  3;54,53,52;,
  3;56,57,55;,
  3;56,55,54;,
  3;58,59,57;,
  3;58,57,56;,
  3;60,61,59;,
  3;60,59,58;,
  3;60,62,63;,
  3;60,63,61;,
  3;62,6,9;,
  3;62,9,63;,
  3;64,65,3;,
  3;64,3,2;,
  3;66,67,65;,
  3;66,65,64;,
  3;68,69,67;,
  3;68,67,66;,
  3;70,71,69;,
  3;70,69,68;,
  3;72,72,71;,
  3;72,71,70;,
  3;72,73,74;,
  3;72,74,72;,
  3;73,75,76;,
  3;73,76,74;,
  3;75,77,78;,
  3;75,78,76;,
  3;77,79,80;,
  3;77,80,78;,
  3;79,81,82;,
  3;79,82,80;,
  3;81,83,84;,
  3;81,84,82;,
  3;83,85,86;,
  3;83,86,84;,
  3;85,87,88;,
  3;85,88,86;,
  3;87,89,90;,
  3;87,90,88;,
  3;89,91,92;,
  3;89,92,90;,
  3;91,93,94;,
  3;91,94,92;,
  3;93,95,96;,
  3;93,96,94;,
  3;97,98,97;,
  3;97,97,98;,
  3;99,100,101;,
  3;99,101,99;,
  3;100,102,103;,
  3;100,103,101;,
  3;102,104,105;,
  3;102,105,103;,
  3;104,106,107;,
  3;104,107,105;,
  3;106,108,109;,
  3;106,109,107;,
  3;108,110,111;,
  3;108,111,109;,
  3;110,112,113;,
  3;110,113,111;,
  3;112,114,115;,
  3;112,115,113;,
  3;114,116,117;,
  3;114,117,115;,
  3;116,118,119;,
  3;116,119,117;,
  3;118,120,121;,
  3;118,121,119;,
  3;120,122,123;,
  3;120,123,121;,
  3;122,124,125;,
  3;122,125,123;,
  3;124,126,127;,
  3;124,127,125;,
  3;126,128,128;,
  3;126,128,127;,
  3;129,130,128;,
  3;129,128,128;,
  3;131,132,130;,
  3;131,130,129;,
  3;133,134,132;,
  3;133,132,131;,
  3;135,136,134;,
  3;135,134,133;,
  3;137,138,136;,
  3;137,136,135;,
  3;139,140,138;,
  3;139,138,137;,
  3;141,142,140;,
  3;141,140,139;,
  3;143,144,142;,
  3;143,142,141;,
  3;145,146,144;,
  3;145,144,143;,
  3;147,148,146;,
  3;147,146,145;,
  3;149,150,148;,
  3;149,148,147;,
  3;151,152,150;,
  3;151,150,149;,
  3;153,154,152;,
  3;153,152,151;,
  3;155,156,154;,
  3;155,154,153;,
  3;157,157,156;,
  3;157,156,155;,
  3;158,159,160;,
  3;158,160,161;,
  3;159,162,163;,
  3;159,163,160;,
  3;162,164,165;,
  3;162,165,163;,
  3;164,166,166;,
  3;164,166,165;,
  3;167,168,166;,
  3;167,166,166;,
  3;169,170,171;,
  3;169,171,172;,
  3;173,174,170;,
  3;173,170,169;,
  3;175,176,174;,
  3;175,174,173;,
  3;177,178,176;,
  3;177,176,175;,
  3;179,180,178;,
  3;179,178,177;,
  3;181,182,180;,
  3;181,180,179;,
  3;183,184,182;,
  3;183,182,181;,
  3;185,185,184;,
  3;185,184,183;,
  3;185,5,4;,
  3;185,4,185;;
 }
 MeshTextureCoords {
  186;
  1.170839;0.540382;
  1.167368;0.524562;
  1.179539;0.506204;
  1.183774;0.543051;
  1.193675;0.489020;
  1.184293;0.598623;
  1.182525;0.584226;
  1.182460;0.569260;
  1.183768;0.555536;
  1.187739;0.611612;
  1.192863;0.623264;
  1.199667;0.633642;
  1.208375;0.471890;
  1.208072;0.642712;
  1.217337;0.649770;
  1.223570;0.454850;
  1.227700;0.655116;
  1.239195;0.437929;
  1.239597;0.658842;
  1.260133;0.415818;
  1.252670;0.660723;
  1.272902;0.660370;
  1.283345;0.393330;
  1.297261;0.655829;
  1.293995;0.560568;
  1.305551;0.374365;
  1.298355;0.541637;
  1.305132;0.523796;
  1.314857;0.502693;
  1.326748;0.358928;
  1.327566;0.478363;
  1.346939;0.347014;
  1.345213;0.447339;
  1.371731;0.609223;
  1.341769;0.578583;
  1.349427;0.567592;
  1.362073;0.421773;
  1.360844;0.340486;
  1.348904;0.529728;
  1.348169;0.516860;
  1.351080;0.502990;
  1.357133;0.552555;
  1.352490;0.542928;
  1.361472;0.489235;
  1.371314;0.336578;
  1.377420;0.403149;
  1.377382;0.483751;
  1.381730;0.333678;
  1.400686;0.581399;
  1.387341;0.394204;
  1.394614;0.484354;
  1.397159;0.331343;
  1.400444;0.387902;
  1.406821;0.464809;
  1.416948;0.331519;
  1.417021;0.391131;
  1.414786;0.584467;
  1.414460;0.447060;
  1.419915;0.431427;
  1.427958;0.333910;
  1.425321;0.583833;
  1.423189;0.417875;
  1.424112;0.404258;
  1.442235;0.524181;
  1.441610;0.340444;
  1.442838;0.510336;
  1.454415;0.484178;
  1.453528;0.350272;
  1.460464;0.359447;
  1.463261;0.459821;
  1.467316;0.372727;
  1.469341;0.437233;
  1.471057;0.384207;
  1.472624;0.416377;
  1.472948;0.397797;
  1.441737;0.580801;
  1.450921;0.535852;
  1.457656;0.574771;
  1.467054;0.528715;
  1.473281;0.565458;
  1.477742;0.518337;
  1.489076;0.552030;
  1.486532;0.506683;
  1.498021;0.501567;
  1.503938;0.534944;
  1.511096;0.525443;
  1.514060;0.510298;
  1.294462;0.574679;
  1.299822;0.584693;
  1.320833;0.646797;
  1.313223;0.591838;
  1.328324;0.589137;
  1.345420;0.631964;
  1.179539;0.506204;
  1.167368;0.524562;
  1.170839;0.540382;
  1.183774;0.543051;
  1.193675;0.489020;
  1.182460;0.569260;
  1.182525;0.584226;
  1.184293;0.598623;
  1.183768;0.555536;
  1.187739;0.611612;
  1.192863;0.623264;
  1.199667;0.633642;
  1.208375;0.471890;
  1.208072;0.642712;
  1.217337;0.649770;
  1.223570;0.454850;
  1.227700;0.655116;
  1.239195;0.437929;
  1.239597;0.658842;
  1.260133;0.415818;
  1.252670;0.660723;
  1.272902;0.660370;
  1.283345;0.393330;
  1.297261;0.655827;
  1.293995;0.560568;
  1.294462;0.574679;
  1.299822;0.584693;
  1.320833;0.646797;
  1.313223;0.591838;
  1.328324;0.589137;
  1.345420;0.631964;
  1.341769;0.578583;
  1.371731;0.609223;
  1.305551;0.374365;
  1.298355;0.541637;
  1.305132;0.523796;
  1.314857;0.502693;
  1.326748;0.358928;
  1.327566;0.478363;
  1.346939;0.347014;
  1.345213;0.447339;
  1.349427;0.567592;
  1.362073;0.421773;
  1.360844;0.340486;
  1.351080;0.502990;
  1.348169;0.516860;
  1.348904;0.529728;
  1.357133;0.552555;
  1.352490;0.542928;
  1.361472;0.489235;
  1.371314;0.336578;
  1.377420;0.403149;
  1.377382;0.483751;
  1.381730;0.333678;
  1.400686;0.581399;
  1.387341;0.394204;
  1.394614;0.484354;
  1.397159;0.331343;
  1.400444;0.387902;
  1.406821;0.464809;
  1.416948;0.331519;
  1.417021;0.391131;
  1.414786;0.584467;
  1.414460;0.447060;
  1.419915;0.431427;
  1.427958;0.333910;
  1.425321;0.583833;
  1.423189;0.417875;
  1.424112;0.404258;
  1.442235;0.524181;
  1.441737;0.580801;
  1.450921;0.535852;
  1.457656;0.574771;
  1.467054;0.528715;
  1.473281;0.565458;
  1.477742;0.518337;
  1.489076;0.552030;
  1.486532;0.506683;
  1.498021;0.501567;
  1.503938;0.534944;
  1.511096;0.525443;
  1.514060;0.510298;
  1.441610;0.340444;
  1.442838;0.510336;
  1.454415;0.484178;
  1.453528;0.350272;
  1.460464;0.359447;
  1.463261;0.459821;
  1.467316;0.372727;
  1.469341;0.437233;
  1.471057;0.384207;
  1.472624;0.416377;
  1.472948;0.397797;;
 }
}
