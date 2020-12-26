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
 319;
 -5.70500;-0.10490;19.91360;,
 5.70500;-0.10490;19.91360;,
 5.70500;-0.10490;-4.85030;,
 -5.70500;-0.10490;-4.85030;,
 -5.70500;-0.10490;-4.85030;,
 5.70500;-0.10490;-4.85030;,
 5.70500;-2.91440;-4.85030;,
 -5.70500;-2.91440;-4.85030;,
 -5.70500;-2.91440;-4.85030;,
 5.70500;-2.91440;-4.85030;,
 5.70500;-2.91440;19.91360;,
 -5.70500;-2.91440;19.91360;,
 5.70500;-0.10490;19.91360;,
 5.70500;-2.91440;19.91360;,
 5.70500;-2.91440;-4.85030;,
 5.70500;-0.10490;-4.85030;,
 -5.70500;-2.91440;19.91360;,
 -5.70500;-0.10490;19.91360;,
 -5.70500;-0.10490;31.02000;,
 5.70500;-0.10490;31.02000;,
 5.70500;-0.10490;19.91360;,
 -5.70500;-0.10490;19.91360;,
 5.70500;-2.91440;31.02000;,
 -5.70500;-2.91440;31.02000;,
 -5.70500;-2.91440;19.91360;,
 5.70500;-2.91440;19.91360;,
 5.70500;-0.10490;31.02000;,
 5.70500;-2.91440;31.02000;,
 -5.70500;-0.10490;31.02000;,
 -5.70500;-2.91440;31.02000;,
 -20.73590;-0.10490;31.02000;,
 -20.73590;-2.91440;31.02000;,
 -20.73590;-0.10490;19.91360;,
 -20.73590;-0.10490;31.02000;,
 -5.70500;-0.10490;31.02000;,
 -5.70500;-0.10490;19.91360;,
 -20.73590;-2.91440;19.91360;,
 -20.73590;-0.10490;19.91360;,
 -20.73590;-2.91440;31.02000;,
 -20.73590;-2.91440;19.91360;,
 -5.70500;-2.91440;19.91360;,
 -5.70500;-2.91440;31.02000;,
 -30.01250;-0.10490;19.91360;,
 -30.01250;-0.10490;31.02000;,
 -20.73590;-0.10490;31.02000;,
 -20.73590;-0.10490;19.91360;,
 -30.01250;-2.91440;19.91360;,
 -30.01250;-0.10490;19.91360;,
 -30.01250;-2.91440;31.02000;,
 -30.01250;-2.91440;19.91360;,
 -20.73590;-2.91440;19.91360;,
 -20.73590;-2.91440;31.02000;,
 -30.01250;-2.91440;31.02000;,
 -30.01250;-0.10490;31.02000;,
 -30.01250;-2.91440;50.71370;,
 -30.01250;-0.10490;50.71370;,
 -20.73590;-2.91440;50.71370;,
 -30.01250;-2.91440;50.71370;,
 -30.01250;-2.91440;31.02000;,
 -20.73590;-2.91440;31.02000;,
 -20.73590;-0.10490;50.71370;,
 -20.73590;-2.91440;50.71370;,
 -30.01250;-0.10490;50.71370;,
 -20.73590;-0.10490;50.71370;,
 -20.73590;-0.10490;31.02000;,
 -30.01250;-0.10490;31.02000;,
 -30.01250;-2.91440;53.24360;,
 -30.01250;-0.10490;53.24360;,
 -20.73590;-2.91440;53.24360;,
 -30.01250;-2.91440;53.24360;,
 -20.73590;-0.10490;53.24360;,
 -20.73590;-2.91440;53.24360;,
 -30.01250;-0.10490;53.24360;,
 -30.01250;-2.91440;53.24360;,
 -20.73590;-0.10490;53.24360;,
 -20.73590;9.42030;53.24360;,
 -30.01250;9.42030;53.24360;,
 -30.01250;-0.10490;53.24360;,
 -20.73590;-0.10490;53.24360;,
 -20.73590;9.42030;50.71370;,
 -20.73590;9.42030;53.24360;,
 -20.73590;-0.10490;53.24360;,
 -20.73590;-0.10490;50.71370;,
 -30.01250;9.42030;50.71370;,
 -20.73590;9.42030;50.71370;,
 -20.73590;-0.10490;50.71370;,
 -30.01250;-0.10490;50.71370;,
 -30.01250;9.42030;53.24360;,
 -30.01250;9.42030;50.71370;,
 -49.26120;9.42030;50.71370;,
 -49.26120;9.42030;53.24360;,
 -49.26120;-0.10490;50.71370;,
 -49.26120;9.42030;50.71370;,
 -30.01250;9.42030;50.71370;,
 -30.01250;-0.10490;50.71370;,
 -49.26120;-0.10490;53.24360;,
 -49.26120;-0.10490;50.71370;,
 -30.01250;-0.10490;50.71370;,
 -30.01250;-0.10490;53.24360;,
 -49.26120;9.42030;53.24360;,
 -49.26120;-0.10490;53.24360;,
 -30.01250;-0.10490;53.24360;,
 -30.01250;9.42030;53.24360;,
 -57.20610;9.42030;50.71370;,
 -57.20610;9.42030;53.24360;,
 -57.20610;-0.10490;50.71370;,
 -57.20610;9.42030;50.71370;,
 -49.26120;9.42030;50.71370;,
 -49.26120;-0.10490;50.71370;,
 -57.20610;9.42030;53.24360;,
 -57.20610;-0.10490;53.24360;,
 -57.20610;9.42030;53.24360;,
 -57.20610;9.42030;50.71370;,
 -57.20610;-0.10490;50.71370;,
 -57.20610;-0.10490;53.24360;,
 -57.20610;-18.04220;53.24360;,
 -57.20610;-18.04220;50.71370;,
 -49.26120;-18.04220;50.71370;,
 -49.26120;-18.04220;53.24360;,
 -62.10360;-14.59840;78.70340;,
 -43.90360;-14.59840;78.70340;,
 -43.90360;-14.59840;60.50340;,
 -62.10360;-14.59840;60.50340;,
 -62.10360;-14.59840;60.50340;,
 -43.90360;-14.59840;60.50340;,
 -43.90360;-32.79840;60.50340;,
 -62.10360;-32.79840;60.50340;,
 -62.10360;-32.79840;60.50340;,
 -43.90360;-32.79840;60.50340;,
 -43.90360;-32.79840;78.70340;,
 -62.10360;-32.79840;78.70340;,
 -62.10360;-32.79840;78.70340;,
 -43.90360;-32.79840;78.70340;,
 -43.90360;-14.59840;78.70340;,
 -62.10360;-14.59840;78.70340;,
 -43.90360;-14.59840;78.70340;,
 -43.90360;-14.59840;60.50340;,
 -62.10360;-14.59840;78.70340;,
 -62.10360;-14.59840;60.50340;,
 -57.20610;-2.95400;53.24360;,
 -57.20610;-0.10490;53.24360;,
 -57.20610;-0.10490;50.71370;,
 -57.20610;-2.95400;50.71370;,
 -57.20610;-2.95400;53.24360;,
 -57.20610;-2.95400;50.71370;,
 -57.20610;-18.04220;50.71370;,
 -57.20610;-18.04220;53.24360;,
 -57.20610;-2.95400;50.71370;,
 -57.20610;-0.10490;50.71370;,
 -49.26120;-0.10490;50.71370;,
 -49.26120;-2.95400;50.71370;,
 -49.26120;-18.04220;50.71370;,
 -57.20610;-18.04220;50.71370;,
 -49.26120;-2.95400;50.71370;,
 -49.26120;-2.95400;53.24360;,
 -49.26120;-2.95400;53.24360;,
 -57.20610;-2.95400;53.24360;,
 -57.20610;-18.04220;53.24360;,
 -49.26120;-18.04220;53.24360;,
 -49.26120;-0.10490;72.67880;,
 -49.26120;-2.95400;72.67880;,
 -49.26120;-2.95400;53.24360;,
 -49.26120;-0.10490;53.24360;,
 -57.20610;-0.10490;72.67880;,
 -49.26120;-0.10490;72.67880;,
 -49.26120;-0.10490;53.24360;,
 -57.20610;-0.10490;53.24360;,
 -57.20610;-2.95400;72.67880;,
 -57.20610;-0.10490;72.67880;,
 -57.20610;-0.10490;53.24360;,
 -57.20610;-2.95400;53.24360;,
 -49.26120;-2.95400;72.67880;,
 -57.20610;-2.95400;72.67880;,
 -57.20610;-2.95400;53.24360;,
 -49.26120;-0.10490;79.66360;,
 -49.26120;-2.95400;79.66360;,
 -57.20610;-0.10490;79.66360;,
 -49.26120;-0.10490;79.66360;,
 -49.26120;-0.10490;72.67880;,
 -57.20610;-0.10490;72.67880;,
 -49.26120;-2.95400;79.66360;,
 -57.20610;-2.95400;79.66360;,
 -57.20610;-2.95400;72.67880;,
 -49.26120;-2.95400;72.67880;,
 -49.26120;-2.95400;79.66360;,
 -49.26120;-0.10490;79.66360;,
 -57.20610;-0.10490;79.66360;,
 -57.20610;-2.95400;79.66360;,
 -79.34210;-0.10490;79.66360;,
 -79.34210;-2.95400;79.66360;,
 -79.34210;-0.10490;72.67880;,
 -79.34210;-0.10490;79.66360;,
 -57.20610;-0.10490;79.66360;,
 -57.20610;-0.10490;72.67880;,
 -79.34210;-2.95400;72.67880;,
 -79.34210;-0.10490;72.67880;,
 -57.20610;-0.10490;72.67880;,
 -57.20610;-2.95400;72.67880;,
 -79.34210;-2.95400;79.66360;,
 -79.34210;-2.95400;72.67880;,
 -57.20610;-2.95400;72.67880;,
 -57.20610;-2.95400;79.66360;,
 -96.30750;-0.10490;79.66360;,
 -96.30750;-2.95400;79.66360;,
 -96.30750;-0.10490;72.67880;,
 -96.30750;-0.10490;79.66360;,
 -79.34210;-0.10490;79.66360;,
 -79.34210;-0.10490;72.67880;,
 -96.30750;-2.95400;79.66360;,
 -96.30750;-2.95400;72.67880;,
 -79.34210;-2.95400;72.67880;,
 -79.34210;-2.95400;79.66360;,
 -96.30750;-2.95400;79.66360;,
 -96.30750;-0.10490;79.66360;,
 -96.30750;-0.10490;72.67880;,
 -96.30750;-2.95400;72.67880;,
 -96.30750;-0.10490;70.54570;,
 -96.30750;-2.95400;70.54570;,
 -96.30750;-2.95400;72.67880;,
 -96.30750;-0.10490;72.67880;,
 -79.34210;-0.10490;70.54570;,
 -96.30750;-0.10490;70.54570;,
 -96.30750;-0.10490;72.67880;,
 -79.34210;-0.10490;72.67880;,
 -79.34210;-2.95400;70.54570;,
 -79.34210;-0.10490;70.54570;,
 -96.30750;-2.95400;70.54570;,
 -96.30750;-0.10490;70.54570;,
 -79.34210;-0.10490;70.54570;,
 -79.34210;-2.95400;70.54570;,
 -79.34210;-19.82020;70.54570;,
 -96.30750;-19.82020;70.54570;,
 -79.34210;-19.82020;72.67880;,
 -79.34210;-19.82020;70.54570;,
 -96.30750;-19.82020;72.67880;,
 -79.34210;-19.82020;72.67880;,
 -79.34210;-2.95400;72.67880;,
 -96.30750;-2.95400;72.67880;,
 -96.30750;-19.82020;70.54570;,
 -96.30750;-19.82020;72.67880;,
 -96.30750;-2.95400;72.67880;,
 -96.30750;-2.95400;70.54570;,
 -79.34210;-19.82020;70.54570;,
 -79.34210;-19.82020;72.67880;,
 -96.30750;-19.82020;72.67880;,
 11.40950;11.36750;60.81350;,
 12.02000;19.41580;77.12570;,
 29.15730;13.69020;79.30940;,
 28.54690;5.64190;62.99710;,
 28.54690;5.64190;62.99710;,
 29.15730;13.69020;79.30940;,
 23.06000;-1.59650;87.07990;,
 22.44960;-9.64480;70.76760;,
 22.44960;-9.64480;70.76760;,
 23.06000;-1.59650;87.07990;,
 5.92260;4.12910;84.89620;,
 5.31220;-3.91920;68.58390;,
 5.31220;-3.91920;68.58390;,
 5.92260;4.12910;84.89620;,
 12.02000;19.41580;77.12570;,
 11.40950;11.36750;60.81350;,
 12.02000;19.41580;77.12570;,
 29.15730;13.69020;79.30940;,
 11.40950;11.36750;60.81350;,
 28.54690;5.64190;62.99710;,
 -60.63530;9.64410;-14.79110;,
 -48.32910;2.71420;-3.31190;,
 -38.20510;-2.70030;-17.43380;,
 -50.51130;4.22970;-28.91310;,
 -50.51130;4.22970;-28.91310;,
 -38.20510;-2.70030;-17.43380;,
 -46.99730;-18.63450;-17.62770;,
 -59.30350;-11.70460;-29.10690;,
 -59.30350;-11.70460;-29.10690;,
 -46.99730;-18.63450;-17.62770;,
 -57.12130;-13.22010;-3.50570;,
 -69.42750;-6.29010;-14.98500;,
 -69.42750;-6.29010;-14.98500;,
 -57.12130;-13.22010;-3.50570;,
 -48.32910;2.71420;-3.31190;,
 -60.63530;9.64410;-14.79110;,
 -48.32910;2.71420;-3.31190;,
 -38.20510;-2.70030;-17.43380;,
 -60.63530;9.64410;-14.79110;,
 -50.51130;4.22970;-28.91310;,
 -63.02410;-25.35620;111.25800;,
 -59.05970;-28.31650;118.62490;,
 -78.50730;-39.43200;124.62390;,
 -82.47170;-36.47170;117.25690;,
 -58.21180;-25.31590;126.93340;,
 -77.65950;-36.43140;132.93230;,
 -60.97730;-18.11210;131.31630;,
 -80.42490;-29.22760;137.31531;,
 -65.73600;-10.92500;129.20621;,
 -85.18370;-22.04050;135.20509;,
 -69.70040;-7.96470;121.83930;,
 -89.14810;-19.08020;127.83820;,
 -70.54830;-10.96530;113.53100;,
 -89.99590;-22.08080;119.52980;,
 -67.78280;-18.16910;109.14800;,
 -87.23050;-29.28460;115.14690;,
 -64.38010;-18.14060;120.23210;,
 -59.05970;-28.31650;118.62490;,
 -63.02410;-25.35620;111.25800;,
 -58.21180;-25.31590;126.93340;,
 -60.97730;-18.11210;131.31630;,
 -65.73600;-10.92500;129.20621;,
 -69.70040;-7.96470;121.83930;,
 -70.54830;-10.96530;113.53100;,
 -67.78280;-18.16910;109.14800;,
 -83.82770;-29.25610;126.23120;,
 -82.47170;-36.47170;117.25690;,
 -78.50730;-39.43200;124.62390;,
 -77.65950;-36.43140;132.93230;,
 -80.42490;-29.22760;137.31531;,
 -85.18370;-22.04050;135.20509;,
 -89.14810;-19.08020;127.83820;,
 -89.99590;-22.08080;119.52980;,
 -87.23050;-29.28460;115.14690;;
 
 112;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,4,7;,
 4;18,19,20,21;,
 4;22,23,24,25;,
 4;26,27,13,12;,
 4;26,28,29,27;,
 4;30,31,29,28;,
 4;32,33,34,35;,
 4;36,37,17,16;,
 4;38,39,40,41;,
 4;42,43,44,45;,
 4;46,47,37,36;,
 4;48,49,50,51;,
 4;52,53,47,46;,
 4;54,55,53,52;,
 4;56,57,58,59;,
 4;60,61,31,30;,
 4;62,63,64,65;,
 4;66,67,55,54;,
 4;68,69,57,56;,
 4;70,71,61,60;,
 4;72,73,71,74;,
 4;75,76,77,78;,
 4;79,80,81,82;,
 4;83,84,85,86;,
 4;87,80,79,88;,
 4;89,90,87,88;,
 4;91,92,93,94;,
 4;95,96,97,98;,
 4;99,100,101,102;,
 4;103,104,90,89;,
 4;105,106,107,108;,
 4;109,110,100,99;,
 4;111,112,113,114;,
 4;115,116,117,118;,
 4;119,120,121,122;,
 4;123,124,125,126;,
 4;127,128,129,130;,
 4;131,132,133,134;,
 4;135,132,125,136;,
 4;131,137,138,126;,
 4;139,140,141,142;,
 4;143,144,145,146;,
 4;147,148,149,150;,
 4;147,150,151,152;,
 4;153,96,95,154;,
 4;153,154,118,117;,
 4;155,156,157,158;,
 4;159,160,161,162;,
 4;163,164,165,166;,
 4;167,168,169,170;,
 4;171,172,173,155;,
 4;174,175,160,159;,
 4;176,177,178,179;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;188,189,187,186;,
 4;190,191,192,193;,
 4;194,195,196,197;,
 4;198,199,200,201;,
 4;202,203,189,188;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;216,217,218,219;,
 4;220,221,222,223;,
 4;224,225,195,194;,
 4;226,227,228,229;,
 4;230,231,226,229;,
 4;232,233,224,194;,
 4;234,235,236,237;,
 4;238,239,240,241;,
 4;231,242,243,244;,
 4;245,246,247,248;,
 4;249,250,251,252;,
 4;253,254,255,256;,
 4;257,258,259,260;,
 4;261,258,251,262;,
 4;257,263,264,252;,
 4;265,266,267,268;,
 4;269,270,271,272;,
 4;273,274,275,276;,
 4;277,278,279,280;,
 4;281,278,271,282;,
 4;277,283,284,272;,
 4;285,286,287,288;,
 4;286,289,290,287;,
 4;289,291,292,290;,
 4;291,293,294,292;,
 4;293,295,296,294;,
 4;295,297,298,296;,
 4;297,299,300,298;,
 4;299,285,288,300;,
 3;301,302,303;,
 3;301,304,302;,
 3;301,305,304;,
 3;301,306,305;,
 3;301,307,306;,
 3;301,308,307;,
 3;301,309,308;,
 3;301,303,309;,
 3;310,311,312;,
 3;310,312,313;,
 3;310,313,314;,
 3;310,314,315;,
 3;310,315,316;,
 3;310,316,317;,
 3;310,317,318;,
 3;310,318,311;;
 
 MeshMaterialList {
  3;
  112;
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
  2,
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
  2,
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
  2,
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
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
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "Gurabi.bmp";
   }
  }
 }
 MeshNormals {
  44;
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.335022;0.839926;-0.426948;,
  0.941615;-0.314588;0.119979;,
  -0.335022;-0.839927;0.426946;,
  0.483088;0.875507;0.010649;,
  0.556263;-0.297495;-0.775931;,
  -0.483088;-0.875507;-0.010649;,
  0.838640;0.479334;-0.258691;,
  0.116944;-0.622315;-0.773982;,
  0.458861;-0.877629;-0.138613;,
  0.531984;-0.618841;0.577953;,
  0.293475;0.002463;0.955964;,
  -0.116947;0.622319;0.773978;,
  -0.458860;0.877630;0.138613;,
  -0.531981;0.618841;-0.577955;,
  -0.293476;-0.002455;-0.955963;,
  -0.838641;-0.479335;0.258690;,
  -0.941614;0.314591;-0.119978;,
  0.033538;0.442218;0.896280;,
  -0.033540;-0.442215;-0.896282;,
  -0.556263;0.297495;0.775931;,
  0.676164;-0.380767;0.630729;,
  -0.676164;0.380767;-0.630729;,
  0.838640;0.479335;-0.258692;,
  0.838642;0.479334;-0.258688;,
  0.838638;0.479337;-0.258693;,
  0.838640;0.479334;-0.258691;,
  0.838643;0.479329;-0.258692;,
  0.838642;0.479329;-0.258696;,
  0.838639;0.479335;-0.258693;,
  0.838640;0.479337;-0.258686;,
  -0.838639;-0.479339;0.258686;,
  -0.838640;-0.479337;0.258687;,
  -0.838639;-0.479336;0.258692;,
  -0.838640;-0.479334;0.258693;,
  -0.838641;-0.479333;0.258692;,
  -0.838642;-0.479332;0.258689;,
  -0.838643;-0.479331;0.258689;,
  -0.838640;-0.479336;0.258689;;
  112;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;20,13,13,20;,
  3;12,28,29;,
  3;12,30,28;,
  3;12,31,30;,
  3;12,32,31;,
  3;12,33,32;,
  3;12,34,33;,
  3;12,35,34;,
  3;12,29,35;,
  3;21,36,37;,
  3;21,37,38;,
  3;21,38,39;,
  3;21,39,40;,
  3;21,40,41;,
  3;21,41,42;,
  3;21,42,43;,
  3;21,43,36;;
 }
 MeshTextureCoords {
  319;
  0.000000;0.126520;
  1.000000;0.126520;
  1.000000;1.000530;
  -0.000000;1.000530;
  0.000000;1.000000;
  1.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.000000;
  -0.000000;1.000530;
  1.000000;1.000530;
  1.000000;0.126520;
  0.000000;0.126520;
  0.690370;1.000000;
  0.690370;0.000000;
  0.000000;0.000000;
  0.000000;1.000000;
  1.000000;-0.000000;
  1.000000;1.000000;
  0.089450;0.000790;
  0.999040;0.000790;
  0.999040;0.910380;
  0.089450;0.910380;
  0.999040;0.000790;
  0.089450;0.000790;
  0.089450;0.910380;
  0.999040;0.910380;
  1.000000;1.000000;
  1.000000;-0.000000;
  0.568470;1.000000;
  0.568470;0.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  0.086320;1.000000;
  0.086320;-0.000000;
  0.913680;0.000000;
  0.913680;1.000000;
  0.381630;0.000000;
  0.381630;1.000000;
  0.086320;0.000000;
  0.086320;1.000000;
  0.913680;1.000000;
  0.913680;0.000000;
  0.001070;0.999010;
  0.001070;0.084880;
  0.915210;0.084880;
  0.915210;0.999010;
  0.000000;0.000000;
  0.000000;1.000000;
  0.001070;0.084880;
  0.001070;0.999010;
  0.915210;0.999010;
  0.915210;0.084880;
  0.333220;0.000000;
  0.333220;1.000000;
  0.924090;0.000000;
  0.924090;1.000000;
  1.000000;0.113450;
  0.000000;0.113450;
  0.000000;0.964940;
  1.000000;0.964940;
  0.886160;1.000000;
  0.886160;0.000000;
  0.000000;0.113450;
  1.000000;0.113450;
  1.000000;0.964940;
  0.000000;0.964940;
  1.000000;0.000000;
  1.000000;1.000000;
  1.000000;0.004060;
  0.000000;0.004060;
  1.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.227770;
  0.000000;0.000000;
  1.000000;0.227770;
  0.997870;0.997560;
  0.051260;0.997560;
  0.051260;0.050940;
  0.997870;0.050940;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  0.048730;0.000000;
  0.048730;1.000000;
  0.684330;1.000000;
  0.684330;0.000000;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  0.291750;1.000000;
  0.291750;0.000000;
  0.982160;-0.000000;
  0.982160;1.000000;
  -8.760270;2.973380;
  -8.760270;2.973380;
  0.005850;0.102260;
  0.005850;0.998340;
  0.901930;0.998340;
  0.901930;0.102260;
  0.006790;1.000000;
  0.006790;0.000000;
  1.000000;0.992570;
  0.000000;0.992570;
  0.000000;0.650880;
  1.000000;0.650880;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.933170;0.033720;
  0.933170;0.966280;
  0.000610;0.966280;
  0.000610;0.033720;
  1.000000;0.548680;
  0.000000;0.548680;
  0.000000;0.007430;
  1.000000;0.007430;
  0.000000;0.814710;
  0.000000;0.967330;
  1.000000;0.967330;
  1.000000;0.814710;
  1.000000;0.006440;
  0.000000;0.006440;
  -8.760270;2.973380;
  -8.760270;2.973380;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;-0.000000;
  0.741590;1.000000;
  0.741590;0.000000;
  0.034740;0.000000;
  0.034740;1.000000;
  0.955490;0.000000;
  0.955490;1.000000;
  0.032190;1.000000;
  0.032190;-0.000000;
  0.996300;-0.000000;
  0.996300;1.000000;
  0.016060;1.000000;
  0.016060;0.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;-0.000000;
  0.995630;1.000000;
  0.995630;-0.000000;
  0.998740;0.080480;
  0.998740;0.999190;
  0.080030;0.999190;
  0.080030;0.080480;
  0.998740;0.999190;
  0.998740;0.080480;
  0.080030;0.080480;
  0.080030;0.999190;
  0.990120;-0.000000;
  0.990120;1.000000;
  0.824580;1.000000;
  0.824580;0.000000;
  0.363360;1.000000;
  0.363360;0.000000;
  0.000000;0.038350;
  1.000000;0.038350;
  1.000000;0.961650;
  0.000000;0.961650;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  -8.760270;2.973380;
  1.000000;0.038350;
  0.000000;0.038350;
  0.000000;0.961650;
  1.000000;0.961650;
  0.009880;1.000000;
  0.009880;0.000000;
  0.057360;0.001110;
  0.999270;0.001110;
  0.999270;0.943010;
  0.057360;0.943010;
  1.000000;0.000640;
  0.000000;0.000640;
  0.000000;0.976010;
  1.000000;0.976010;
  0.994830;-0.000000;
  0.994830;1.000000;
  0.080690;1.000000;
  0.080690;0.000000;
  0.009580;0.997760;
  0.009580;0.051150;
  0.853600;0.051150;
  0.853600;0.997760;
  -0.007780;1.000000;
  -0.007780;0.000000;
  0.787200;0.000000;
  0.787200;1.000000;
  -8.760270;2.973380;
  -8.760270;2.973380;
  0.000000;0.855490;
  0.000000;1.000000;
  1.000000;1.000000;
  1.000000;0.855490;
  1.000000;-0.000000;
  0.000000;0.000000;
  -8.760270;2.973380;
  -8.760270;2.973380;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.003350;
  1.000000;0.003350;
  1.000000;0.969040;
  0.000000;0.969040;
  -0.000000;1.000000;
  1.000000;1.000000;
  1.000000;0.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.000000;0.000000;
  0.000000;1.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;0.500000;
  0.000000;0.771430;
  1.000000;0.771430;
  1.000000;0.500000;
  0.000000;0.883860;
  1.000000;0.883860;
  0.000000;0.771430;
  1.000000;0.771430;
  0.000000;0.500000;
  1.000000;0.500000;
  0.000000;0.228570;
  1.000000;0.228570;
  0.000000;0.116140;
  1.000000;0.116140;
  0.000000;0.228570;
  1.000000;0.228570;
  0.241150;0.500000;
  0.241150;0.683030;
  0.241150;0.500000;
  0.241150;0.758850;
  0.241150;0.683040;
  0.241150;0.500000;
  0.241150;0.316960;
  0.241150;0.241150;
  0.241150;0.316960;
  0.758850;0.500000;
  0.758850;0.500000;
  0.758850;0.683040;
  0.758850;0.758850;
  0.758850;0.683040;
  0.758850;0.500000;
  0.758850;0.316960;
  0.758850;0.241150;
  0.758850;0.316960;;
 }
}