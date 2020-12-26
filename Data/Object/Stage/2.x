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
 326;
 0.19280;2020.87158;0.20580;,
 0.19280;1952.21191;-521.31500;,
 260.95270;1952.21191;-451.44409;,
 451.84250;1952.21191;-260.55441;,
 521.71332;1952.21191;0.20580;,
 451.84250;1952.21191;260.96600;,
 260.95270;1952.21191;451.85559;,
 0.19290;1952.21191;521.72583;,
 -260.56741;1952.21191;451.85580;,
 -451.45721;1952.21191;260.96609;,
 -521.32770;1952.21191;0.20600;,
 -451.45749;1952.21191;-260.55411;,
 -260.56769;1952.21191;-451.44391;,
 0.19280;1750.91260;-1007.29462;,
 503.94269;1750.91260;-872.31519;,
 872.71350;1750.91260;-503.54419;,
 1007.69299;1750.91260;0.20580;,
 872.71350;1750.91260;503.95590;,
 503.94269;1750.91260;872.72601;,
 260.95270;1952.21191;451.85559;,
 0.19290;1750.91260;1007.70508;,
 0.19290;1952.21191;521.72583;,
 -503.55731;1750.91260;872.72601;,
 -260.56741;1952.21191;451.85580;,
 -872.32751;1750.91260;503.95609;,
 -451.45721;1952.21191;260.96609;,
 -1007.30713;1750.91260;0.20630;,
 -521.32770;1952.21191;0.20600;,
 -872.32800;1750.91260;-503.54370;,
 -451.45749;1952.21191;-260.55411;,
 -872.32800;1750.91260;-503.54370;,
 -503.55811;1750.91260;-872.31500;,
 0.19280;1430.69165;-1424.61536;,
 712.60291;1430.69165;-1233.72546;,
 1234.12366;1430.69165;-712.20471;,
 1425.01331;1430.69165;0.20590;,
 1234.12354;1430.69165;712.61548;,
 712.60291;1430.69165;1234.13538;,
 0.19300;1430.69165;1425.02502;,
 -712.21692;1430.69165;1234.13562;,
 -1233.73706;1430.69165;712.61591;,
 -1424.62708;1430.69165;0.20650;,
 -1233.73779;1430.69165;-712.20398;,
 -1233.73779;1430.69165;-712.20398;,
 -712.21802;1430.69165;-1233.72498;,
 0.19280;1013.37299;-1744.83630;,
 872.71350;1013.37299;-1511.04529;,
 1511.44324;1013.37299;-872.31519;,
 1745.23438;1013.37299;0.20590;,
 1511.44312;1013.37299;872.72601;,
 872.71362;1013.37299;1511.45496;,
 0.19310;1013.37299;1745.24622;,
 -872.32739;1013.37299;1511.45520;,
 -1511.05664;1013.37299;872.72650;,
 -1744.84814;1013.37299;0.20660;,
 -1511.05750;1013.37299;-872.31439;,
 -1511.05750;1013.37299;-872.31439;,
 -872.32892;1013.37299;-1511.04456;,
 0.19280;527.39349;-1946.13562;,
 973.36328;527.39349;-1685.37537;,
 1685.77356;527.39349;-972.96490;,
 1946.53357;527.39349;0.20590;,
 1685.77344;527.39349;973.37567;,
 973.36328;527.39349;1685.78528;,
 0.19310;527.39349;1946.54553;,
 -972.97711;527.39349;1685.78552;,
 -1685.38696;527.39349;973.37622;,
 -1946.14734;527.39349;0.20670;,
 -1685.38770;527.39349;-972.96393;,
 -1685.38770;527.39349;-972.96393;,
 -972.97852;527.39349;-1685.37488;,
 0.19280;5.87410;-2014.79504;,
 1007.69299;5.87410;-1744.83630;,
 1745.23438;5.87410;-1007.29449;,
 2015.19336;5.87410;0.20590;,
 1745.23425;5.87410;1007.70508;,
 1007.69312;5.87410;1745.24597;,
 0.19310;5.87410;2015.20569;,
 -1007.30682;5.87410;1745.24622;,
 -1744.84766;5.87410;1007.70563;,
 -2014.80688;5.87410;0.20670;,
 -1744.84863;5.87410;-1007.29358;,
 -1744.84863;5.87410;-1007.29358;,
 -1007.30829;5.87410;-1744.83557;,
 0.19280;-515.64697;-1946.13562;,
 973.36328;-515.64697;-1685.37561;,
 1685.77368;-515.64697;-972.96490;,
 1946.53357;-515.64697;0.20590;,
 1685.77356;-515.64697;973.37567;,
 973.36340;-515.64697;1685.78528;,
 0.19310;-515.64697;1946.54602;,
 -972.97711;-515.64697;1685.78552;,
 -1685.38696;-515.64697;973.37622;,
 -1946.14746;-515.64697;0.20670;,
 -1685.38782;-515.64697;-972.96411;,
 -1685.38782;-515.64697;-972.96411;,
 -972.97858;-515.64697;-1685.37488;,
 70.93240;23.60809;271.95490;,
 95.63640;23.60809;260.17139;,
 95.63650;-3.76221;260.17169;,
 70.93240;-3.76221;271.95490;,
 34.69180;9.94679;138.64751;,
 38.18630;11.16779;139.86850;,
 36.84820;13.39699;136.49130;,
 33.47100;11.16779;135.15340;,
 42.98440;11.16779;141.52541;,
 44.32250;13.39699;138.14810;,
 36.84820;13.39699;136.49130;,
 46.47860;9.94679;140.30431;,
 49.07120;11.16779;135.15340;,
 38.33010;13.39699;128.59630;,
 34.38990;11.16779;131.27420;,
 45.69390;13.39699;129.93610;,
 38.33010;13.39699;128.59630;,
 49.07120;11.16779;131.27420;,
 39.66800;11.16779;125.21880;,
 36.17370;9.94679;126.43990;,
 45.69390;13.39699;129.93610;,
 43.54730;11.16779;125.21880;,
 47.85010;9.94679;127.77980;,
 43.54730;11.16779;125.21880;,
 38.33010;7.79049;122.98970;,
 34.95270;6.45249;125.21880;,
 45.69390;7.79049;124.32970;,
 47.85010;9.94679;127.77980;,
 49.07120;6.45249;126.55870;,
 38.33010;1.23529;122.98970;,
 34.95270;2.57329;125.21880;,
 45.69390;1.23529;124.32970;,
 49.07120;2.57329;126.55870;,
 38.91680;-3.30511;123.86270;,
 34.98180;-3.13801;124.85250;,
 44.51110;-3.30511;123.86270;,
 50.34380;-3.13801;126.61510;,
 33.03240;-3.13801;140.91319;,
 36.96710;-3.30511;140.70171;,
 36.84820;1.23529;142.09790;,
 33.47100;2.57329;139.86850;,
 43.77050;-3.30511;142.88150;,
 44.32250;1.23529;143.75459;,
 48.53930;-3.13801;143.09280;,
 47.69970;2.57329;141.52541;,
 36.84820;7.79049;142.09790;,
 33.47100;6.45249;139.86850;,
 44.32250;7.79049;143.75459;,
 47.69970;6.45249;141.52541;,
 51.30030;7.79049;136.49130;,
 51.30030;1.23529;136.49130;,
 50.31600;-3.30511;138.14050;,
 51.30030;7.79049;129.93610;,
 51.30030;1.23529;129.93610;,
 50.31600;-3.30511;130.36650;,
 49.07120;6.45249;126.55870;,
 49.07120;2.57329;126.55870;,
 50.34380;-3.13801;126.61510;,
 32.16070;1.23529;136.49130;,
 32.22610;-3.30511;135.96069;,
 32.16070;7.79049;136.49130;,
 32.16070;1.23529;129.93610;,
 33.43520;-3.30511;130.36650;,
 32.16070;7.79049;129.93610;,
 -590.28998;-3.61381;590.28998;,
 590.28998;-3.61381;590.28998;,
 590.28998;-3.61381;-590.28998;,
 -590.28998;-3.61381;-590.28998;,
 -193.87640;23.60809;258.60330;,
 -175.74010;23.60809;279.10239;,
 -175.74030;-3.76221;279.10260;,
 -193.87640;-3.76221;258.60330;,
 20.68630;23.60809;-159.20979;,
 -6.50820;23.60809;-162.30791;,
 -6.50820;-3.76221;-162.30820;,
 20.68630;-3.76221;-159.20979;,
 137.59210;23.60809;63.37560;,
 134.01910;23.60809;36.23930;,
 134.01950;-3.76221;36.23930;,
 137.59210;-3.76221;63.37560;,
 -216.06160;23.60809;169.84590;,
 -209.43980;23.60809;196.40331;,
 -209.44020;-3.76221;196.40331;,
 -216.06160;-3.76221;169.84590;,
 -76.48700;23.60809;-112.90340;,
 -102.28750;23.60809;-103.76670;,
 -102.28750;-3.76221;-103.76690;,
 -76.48700;-3.76221;-112.90340;,
 -6.20000;0.05599;5.57160;,
 6.20000;0.05599;5.57160;,
 6.20000;0.05599;-6.20000;,
 -6.20000;0.05599;-6.20000;,
 6.20000;-3.74401;-6.20000;,
 -6.20000;-3.74401;-6.20000;,
 6.20000;-3.74401;5.57160;,
 -6.20000;-3.74401;5.57160;,
 6.20000;-3.74401;18.53520;,
 -6.20000;-3.74401;18.53520;,
 6.20000;0.05599;18.53520;,
 -6.20000;0.05599;18.53520;,
 -18.71890;0.05599;5.57160;,
 -18.71890;0.05599;18.53520;,
 -18.71890;-3.74401;5.57160;,
 -18.71890;-3.74401;18.53520;,
 -18.71890;-3.74401;32.31640;,
 -18.71890;0.05599;32.31640;,
 -6.20000;-3.74401;32.31640;,
 -6.20000;0.05599;32.31640;,
 -18.71890;-3.74401;46.01870;,
 -18.71890;0.05599;46.01870;,
 -6.20000;-3.74401;46.01870;,
 -6.20000;0.05599;46.01870;,
 15.66040;-3.74401;46.01870;,
 15.66040;0.05599;46.01870;,
 15.66040;-3.74401;32.31640;,
 15.66040;0.05599;32.31640;,
 29.28380;-3.74401;32.31640;,
 29.28380;-3.74401;46.01870;,
 29.28380;0.05599;32.31640;,
 29.28380;0.05599;46.01870;,
 29.28380;0.05599;60.82990;,
 29.28380;-3.74401;60.82990;,
 15.66040;0.05599;60.82990;,
 15.66040;-3.74401;60.82990;,
 29.28380;0.05599;75.07350;,
 29.28380;-3.74401;75.07350;,
 15.66040;0.05599;75.07350;,
 15.66040;-3.74401;75.07350;,
 2.51360;0.05599;60.82990;,
 2.51360;0.05599;75.07350;,
 2.51360;-3.74401;60.82990;,
 2.51360;-3.74401;75.07350;,
 15.66040;-3.74401;89.72510;,
 2.51360;-3.74401;89.72510;,
 15.66040;0.05599;89.72510;,
 2.51360;0.05599;89.72510;,
 -24.22220;0.05769;89.72510;,
 -24.22220;-3.96031;89.72510;,
 -24.22220;0.05769;75.07350;,
 -24.22220;-3.96031;75.07350;,
 -40.05590;0.05769;75.07350;,
 -40.05590;0.05769;89.72510;,
 -40.05590;-3.96031;75.07350;,
 -40.05590;-3.96031;89.72510;,
 -40.05590;-3.96031;108.60650;,
 -40.05590;0.05769;108.60650;,
 -24.22220;-3.96031;108.60650;,
 -24.22220;0.05769;108.60650;,
 -40.05590;-3.96031;131.28610;,
 -40.05590;0.05769;131.28610;,
 -24.22220;-3.96031;131.28610;,
 -24.22220;0.05769;131.28610;,
 -40.05590;1.45259;108.60650;,
 -24.22220;1.45259;108.60650;,
 -40.05590;1.45259;131.28610;,
 -24.22220;1.45259;131.28610;,
 -40.05590;0.05769;149.02440;,
 -40.05590;1.45259;149.02440;,
 -24.22220;0.05769;149.02440;,
 -24.22220;1.45259;149.02440;,
 -40.05590;2.70789;131.28610;,
 -24.22220;2.70789;131.28610;,
 -40.05590;2.70789;149.02440;,
 -24.22220;2.70789;149.02440;,
 -40.05590;1.45259;169.03619;,
 -40.05590;2.70789;169.03619;,
 -24.22220;1.45259;169.03619;,
 -24.22220;2.70789;169.03619;,
 -40.05590;3.97609;149.02440;,
 -24.22220;3.97609;149.02440;,
 -40.05590;3.97609;169.03619;,
 -24.22220;3.97609;169.03619;,
 -40.05590;3.97609;178.79050;,
 -24.22220;3.97609;178.79050;,
 -24.22220;2.70789;178.79050;,
 -40.05590;2.70789;178.79050;,
 -64.47040;3.97609;178.79050;,
 -64.47040;2.70789;178.79050;,
 -64.47040;3.97609;169.03619;,
 -64.47040;2.70789;169.03619;,
 -98.91240;-1.60831;181.53770;,
 28.60370;-1.60831;181.53770;,
 28.60370;-1.60831;166.62460;,
 -98.91240;-1.60831;166.62460;,
 28.60370;-3.69241;166.62460;,
 -97.65960;-3.69241;166.62460;,
 28.60370;-3.69241;181.53770;,
 -97.65960;-3.69241;181.53770;,
 -22.07480;-3.96031;108.60650;,
 -22.07480;0.05769;108.60650;,
 -22.07480;-3.96031;89.72510;,
 -22.07480;0.05769;89.72510;,
 -22.07480;0.05769;131.28610;,
 -22.07480;1.45259;131.28610;,
 -22.07480;1.45259;108.60650;,
 -22.07480;1.45259;149.02440;,
 -22.07480;2.70789;149.02440;,
 -22.07480;2.70789;131.28610;,
 -22.07480;2.70789;169.03619;,
 -22.07480;3.97609;149.02440;,
 -22.07480;3.97609;169.03619;,
 -22.07480;2.70789;178.79050;,
 -22.07480;3.97609;178.79050;,
 -22.07480;5.71299;89.72510;,
 -22.07480;5.71299;108.60650;,
 -24.22220;5.71299;89.72510;,
 -24.22220;5.71299;108.60650;,
 -22.07480;7.48769;108.60650;,
 -22.07480;7.48769;131.28610;,
 -24.22220;7.48769;108.60650;,
 -24.22220;7.48769;131.28610;,
 -22.07480;9.12289;131.28610;,
 -22.07480;9.12289;149.02440;,
 -24.22220;9.12289;131.28610;,
 -24.22220;9.12289;149.02440;,
 -22.07480;10.77089;149.02440;,
 -22.07480;10.77089;169.03619;,
 -24.22220;10.77089;149.02440;,
 -24.22220;10.77089;169.03619;,
 -22.07480;10.77089;178.79050;,
 -24.22220;10.77089;178.79050;,
 -100.70090;0.05119;181.53770;,
 -100.70090;-3.69241;181.53770;,
 -100.70090;-3.69241;166.62460;,
 -100.70090;0.05119;166.62460;,
 -100.70090;15.66349;181.53770;,
 -100.70090;15.66349;166.62460;,
 -98.91240;15.66349;181.53770;,
 -98.91240;15.66349;166.62460;;
 
 276;
 3;0,1,2;,
 3;0,2,3;,
 3;0,3,4;,
 3;0,4,5;,
 3;0,5,6;,
 3;0,6,7;,
 3;0,7,8;,
 3;0,8,9;,
 3;0,9,10;,
 3;0,10,11;,
 3;0,11,12;,
 3;0,12,1;,
 4;1,13,14,2;,
 4;2,14,15,3;,
 4;3,15,16,4;,
 4;4,16,17,5;,
 4;5,17,18,19;,
 4;19,18,20,21;,
 4;21,20,22,23;,
 4;23,22,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;11,30,31,12;,
 4;12,31,13,1;,
 4;13,32,33,14;,
 4;14,33,34,15;,
 4;15,34,35,16;,
 4;16,35,36,17;,
 4;17,36,37,18;,
 4;18,37,38,20;,
 4;20,38,39,22;,
 4;22,39,40,24;,
 4;24,40,41,26;,
 4;26,41,42,28;,
 4;30,43,44,31;,
 4;31,44,32,13;,
 4;32,45,46,33;,
 4;33,46,47,34;,
 4;34,47,48,35;,
 4;35,48,49,36;,
 4;36,49,50,37;,
 4;37,50,51,38;,
 4;38,51,52,39;,
 4;39,52,53,40;,
 4;40,53,54,41;,
 4;41,54,55,42;,
 4;43,56,57,44;,
 4;44,57,45,32;,
 4;45,58,59,46;,
 4;46,59,60,47;,
 4;47,60,61,48;,
 4;48,61,62,49;,
 4;49,62,63,50;,
 4;50,63,64,51;,
 4;51,64,65,52;,
 4;52,65,66,53;,
 4;53,66,67,54;,
 4;54,67,68,55;,
 4;56,69,70,57;,
 4;57,70,58,45;,
 4;58,71,72,59;,
 4;59,72,73,60;,
 4;60,73,74,61;,
 4;61,74,75,62;,
 4;62,75,76,63;,
 4;63,76,77,64;,
 4;64,77,78,65;,
 4;65,78,79,66;,
 4;66,79,80,67;,
 4;67,80,81,68;,
 4;69,82,83,70;,
 4;70,83,71,58;,
 4;71,84,85,72;,
 4;72,85,86,73;,
 4;73,86,87,74;,
 4;74,87,88,75;,
 4;75,88,89,76;,
 4;76,89,90,77;,
 4;77,90,91,78;,
 4;78,91,92,79;,
 4;79,92,93,80;,
 4;80,93,94,81;,
 4;82,95,96,83;,
 4;83,96,84,71;,
 4;97,98,99,100;,
 4;101,102,103,104;,
 4;102,105,106,107;,
 4;105,108,109,106;,
 4;104,103,110,111;,
 4;107,106,112,113;,
 4;106,109,114,112;,
 4;111,110,115,116;,
 4;110,117,118,115;,
 4;112,114,119,120;,
 4;116,115,121,122;,
 4;115,118,123,121;,
 4;118,124,125,123;,
 4;122,121,126,127;,
 4;121,123,128,126;,
 4;123,125,129,128;,
 4;127,126,130,131;,
 4;126,128,132,130;,
 4;128,129,133,132;,
 4;134,135,136,137;,
 4;135,138,139,136;,
 4;138,140,141,139;,
 4;137,136,142,143;,
 4;136,139,144,142;,
 4;139,141,145,144;,
 4;143,142,102,101;,
 4;142,144,105,102;,
 4;144,145,108,105;,
 4;108,145,146,109;,
 4;145,141,147,146;,
 4;141,140,148,147;,
 4;109,146,149,114;,
 4;146,147,150,149;,
 4;147,148,151,150;,
 4;114,149,152,119;,
 4;149,150,153,152;,
 4;150,151,154,153;,
 4;134,137,155,156;,
 4;137,143,157,155;,
 4;143,101,104,157;,
 4;156,155,158,159;,
 4;155,157,160,158;,
 4;157,104,111,160;,
 4;159,158,127,131;,
 4;158,160,122,127;,
 4;160,111,116,122;,
 4;161,162,163,164;,
 4;165,166,167,168;,
 4;169,170,171,172;,
 4;173,174,175,176;,
 4;177,178,179,180;,
 4;181,182,183,184;,
 4;185,186,187,188;,
 4;188,187,189,190;,
 4;190,189,191,192;,
 4;186,191,189,187;,
 4;192,185,188,190;,
 4;193,194,192,191;,
 4;195,193,191,186;,
 4;196,195,186,185;,
 4;194,193,195,196;,
 4;197,198,196,185;,
 4;199,197,185,192;,
 4;200,199,192,194;,
 4;200,198,197,199;,
 4;201,202,198,200;,
 4;203,201,200,194;,
 4;204,203,194,196;,
 4;202,204,196,198;,
 4;205,206,202,201;,
 4;207,205,201,203;,
 4;206,208,204,202;,
 4;206,205,207,208;,
 4;209,210,208,207;,
 4;211,209,207,203;,
 4;212,211,203,204;,
 4;210,212,204,208;,
 4;213,214,209,211;,
 4;215,213,211,212;,
 4;216,215,212,210;,
 4;216,214,213,215;,
 4;217,218,214,216;,
 4;219,217,216,210;,
 4;220,219,210,209;,
 4;218,220,209,214;,
 4;221,222,218,217;,
 4;223,221,217,219;,
 4;222,224,220,218;,
 4;222,221,223,224;,
 4;225,226,223,219;,
 4;227,225,219,220;,
 4;228,227,220,224;,
 4;228,226,225,227;,
 4;229,230,228,224;,
 4;231,229,224,223;,
 4;232,231,223,226;,
 4;232,230,229,231;,
 4;233,234,230,232;,
 4;235,233,232,226;,
 4;236,235,226,228;,
 4;234,236,228,230;,
 4;237,238,233,235;,
 4;239,237,235,236;,
 4;240,239,236,234;,
 4;240,238,237,239;,
 4;241,242,238,240;,
 4;243,241,240,234;,
 4;242,244,233,238;,
 4;245,246,242,241;,
 4;247,245,241,243;,
 4;248,247,243,244;,
 4;246,245,247,248;,
 4;249,250,244,242;,
 4;251,249,242,246;,
 4;251,252,250,249;,
 4;253,254,251,246;,
 4;255,253,246,248;,
 4;256,255,248,252;,
 4;256,254,253,255;,
 4;257,258,252,251;,
 4;259,257,251,254;,
 4;259,260,258,257;,
 4;261,262,259,254;,
 4;263,261,254,256;,
 4;264,263,256,260;,
 4;264,262,261,263;,
 4;265,266,260,259;,
 4;267,265,259,262;,
 4;267,268,266,265;,
 4;269,270,268,267;,
 4;271,272,262,264;,
 4;270,269,272,271;,
 4;273,274,272,269;,
 4;275,273,269,267;,
 4;276,275,267,262;,
 4;274,276,262,272;,
 4;274,273,275,276;,
 4;277,278,279,280;,
 4;280,279,281,282;,
 4;282,281,283,284;,
 4;284,283,278,277;,
 4;278,283,281,279;,
 4;285,286,244,243;,
 4;287,285,243,234;,
 4;288,287,234,233;,
 4;286,285,287,288;,
 4;289,290,252,248;,
 4;286,289,248,244;,
 4;291,286,244,250;,
 4;291,290,289,286;,
 4;292,293,260,256;,
 4;290,292,256,252;,
 4;294,290,252,258;,
 4;294,293,292,290;,
 4;293,295,264,260;,
 4;296,293,260,266;,
 4;296,297,295,293;,
 4;298,299,270,271;,
 4;295,298,271,264;,
 4;299,298,295,297;,
 4;300,301,286,288;,
 4;302,300,288,233;,
 4;303,302,233,244;,
 4;301,303,244,286;,
 4;301,300,302,303;,
 4;304,305,290,291;,
 4;306,304,291,250;,
 4;307,306,250,252;,
 4;305,307,252,290;,
 4;305,304,306,307;,
 4;308,309,293,294;,
 4;310,308,294,258;,
 4;311,310,258,260;,
 4;309,311,260,293;,
 4;309,308,310,311;,
 4;312,313,297,296;,
 4;314,312,296,266;,
 4;315,314,266,268;,
 4;313,312,314,315;,
 4;313,316,299,297;,
 4;317,315,268,270;,
 4;316,317,270,299;,
 4;316,313,315,317;,
 4;318,319,284,277;,
 4;320,321,280,282;,
 4;319,320,282,284;,
 4;319,318,321,320;,
 4;322,323,321,318;,
 4;324,322,318,277;,
 4;325,324,277,280;,
 4;323,325,280,321;,
 4;323,322,324,325;;
 
 MeshMaterialList {
  6;
  276;
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  4,
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
  2,
  2,
  2,
  1,
  4,
  4,
  4,
  4,
  4,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
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
   0.770000;0.770000;0.770000;;
   TextureFilename {
    "tree.tga";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  155;
  -0.000000;-1.000000;-0.000000;,
  0.000000;-0.966005;0.258525;,
  -0.129263;-0.966004;0.223890;,
  -0.223890;-0.966004;0.129263;,
  -0.258525;-0.966004;0.000000;,
  -0.223890;-0.966004;-0.129263;,
  -0.129263;-0.966004;-0.223890;,
  -0.000000;-0.966004;-0.258526;,
  0.129263;-0.966004;-0.223890;,
  0.223890;-0.966004;-0.129263;,
  0.258526;-0.966004;-0.000000;,
  0.223890;-0.966004;0.129263;,
  0.129263;-0.966004;0.223889;,
  0.000000;-0.866286;0.499549;,
  -0.249775;-0.866286;0.432622;,
  -0.432622;-0.866286;0.249775;,
  -0.499549;-0.866285;-0.000000;,
  -0.432622;-0.866285;-0.249775;,
  -0.249775;-0.866285;-0.432623;,
  -0.000000;-0.866285;-0.499550;,
  0.249775;-0.866285;-0.432623;,
  0.432623;-0.866285;-0.249775;,
  0.499550;-0.866285;-0.000000;,
  0.432623;-0.866285;0.249774;,
  0.249775;-0.866286;0.432622;,
  0.000000;-0.707525;0.706688;,
  -0.353344;-0.707525;0.612010;,
  -0.612010;-0.707525;0.353344;,
  -0.706688;-0.707525;-0.000000;,
  -0.612010;-0.707525;-0.353345;,
  -0.353344;-0.707525;-0.612010;,
  -0.000000;-0.707525;-0.706689;,
  0.353344;-0.707525;-0.612010;,
  0.612010;-0.707525;-0.353345;,
  0.706689;-0.707525;-0.000000;,
  0.612011;-0.707525;0.353344;,
  0.353345;-0.707525;0.612010;,
  0.000000;-0.500436;0.865773;,
  -0.432887;-0.500436;0.749782;,
  -0.749782;-0.500436;0.432887;,
  -0.865773;-0.500436;-0.000000;,
  -0.749782;-0.500436;-0.432887;,
  -0.432887;-0.500436;-0.749782;,
  -0.000000;-0.500436;-0.865773;,
  0.432886;-0.500436;-0.749782;,
  0.749782;-0.500436;-0.432887;,
  0.865773;-0.500436;-0.000001;,
  0.749782;-0.500436;0.432886;,
  0.432887;-0.500436;0.749781;,
  0.000000;-0.259096;0.965852;,
  -0.482926;-0.259096;0.836452;,
  -0.836452;-0.259096;0.482926;,
  -0.965851;-0.259096;-0.000000;,
  -0.836452;-0.259096;-0.482926;,
  -0.482926;-0.259096;-0.836452;,
  -0.000000;-0.259097;-0.965851;,
  0.482926;-0.259096;-0.836452;,
  0.836452;-0.259096;-0.482926;,
  0.965851;-0.259096;-0.000001;,
  0.836452;-0.259096;0.482925;,
  0.482926;-0.259096;0.836452;,
  0.000000;-0.000000;1.000000;,
  -0.500000;-0.000000;0.866025;,
  -0.866026;-0.000000;0.500000;,
  -1.000000;-0.000000;-0.000000;,
  -0.866025;-0.000000;-0.500000;,
  -0.500000;-0.000000;-0.866025;,
  -0.000000;-0.000000;-1.000000;,
  0.500000;-0.000000;-0.866025;,
  0.866025;-0.000000;-0.500000;,
  1.000000;-0.000000;-0.000001;,
  0.866026;-0.000000;0.499999;,
  0.500001;-0.000000;0.866025;,
  0.000000;0.130526;0.991445;,
  -0.495723;0.130526;0.858616;,
  -0.858617;0.130526;0.495722;,
  -0.991445;0.130526;-0.000000;,
  -0.858616;0.130526;-0.495723;,
  -0.495723;0.130526;-0.858616;,
  -0.000000;0.130526;-0.991445;,
  0.495723;0.130526;-0.858616;,
  0.858616;0.130526;-0.495723;,
  0.991445;0.130526;-0.000001;,
  0.858617;0.130526;0.495722;,
  0.495723;0.130526;0.858616;,
  -0.430515;-0.000006;-0.902583;,
  -0.618385;0.555696;0.555699;,
  -0.369480;0.660956;0.653163;,
  0.184212;0.698218;0.691778;,
  0.574077;0.576800;0.581152;,
  -0.725284;0.656083;0.208609;,
  -0.328686;0.907767;0.260624;,
  0.242087;0.920729;0.306025;,
  0.665936;0.686178;0.292726;,
  -0.688826;0.654752;-0.311157;,
  -0.279569;0.910440;-0.304862;,
  0.301464;0.917154;-0.260668;,
  0.678033;0.687285;-0.260598;,
  -0.597932;0.578089;-0.555238;,
  -0.256428;0.675844;-0.690999;,
  0.336406;0.653992;-0.677589;,
  0.604218;0.561108;-0.565755;,
  -0.699300;0.280032;-0.657694;,
  -0.226789;0.273238;-0.934830;,
  0.369833;0.248823;-0.895159;,
  0.688036;0.265117;-0.675514;,
  -0.715345;-0.056102;-0.696515;,
  -0.179709;-0.039799;-0.982915;,
  0.330882;-0.005993;-0.943653;,
  0.745689;0.007988;-0.666246;,
  -0.703564;-0.114631;-0.701325;,
  -0.159618;-0.077855;-0.984104;,
  0.288544;-0.011984;-0.957392;,
  0.784217;0.016484;-0.620267;,
  -0.957572;-0.142190;-0.250676;,
  0.984678;-0.114589;-0.131448;,
  -0.996219;-0.052058;0.069558;,
  0.970344;-0.042914;0.237889;,
  -0.239783;-0.053379;0.969358;,
  -0.247689;-0.139436;0.958753;,
  -0.019948;-0.085430;0.996145;,
  0.604945;0.104781;0.789343;,
  -0.745855;-0.001333;0.666107;,
  -0.320110;-0.070535;0.944751;,
  0.079139;-0.043904;0.995896;,
  0.653089;0.050395;0.755603;,
  -0.742536;0.261904;0.616480;,
  -0.403629;0.285321;0.869296;,
  0.181957;0.306649;0.934269;,
  0.671252;0.278212;0.687036;,
  0.905175;0.295400;0.305609;,
  0.962107;-0.021534;0.271821;,
  0.908922;0.294844;-0.294835;,
  0.976093;-0.058424;-0.209353;,
  -0.991546;-0.026045;0.127112;,
  -0.949579;0.248510;0.191162;,
  -0.963464;-0.072160;-0.257935;,
  -0.918110;0.270596;-0.289571;,
  0.000000;1.000000;0.000000;,
  0.748955;-0.000005;-0.662621;,
  -0.113197;-0.000005;0.993573;,
  -0.991444;-0.000007;0.130535;,
  0.970295;-0.000007;-0.241925;,
  0.333812;-0.000003;0.942640;,
  0.000000;0.000000;-1.000000;,
  0.000000;-1.000000;-0.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000021;1.000000;0.000000;,
  0.002697;-0.999996;-0.000000;,
  0.000032;1.000000;0.000000;,
  0.004045;-0.999992;-0.000000;,
  -0.969755;0.048566;0.239202;,
  0.002023;-0.999998;-0.000000;;
  276;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;0,4,5;,
  3;0,5,6;,
  3;0,6,7;,
  3;0,7,8;,
  3;0,8,9;,
  3;0,9,10;,
  3;0,10,11;,
  3;0,11,12;,
  3;0,12,1;,
  4;1,13,14,2;,
  4;2,14,15,3;,
  4;3,15,16,4;,
  4;4,16,17,5;,
  4;5,17,18,6;,
  4;6,18,19,7;,
  4;7,19,20,8;,
  4;8,20,21,9;,
  4;9,21,22,10;,
  4;10,22,23,11;,
  4;11,23,24,12;,
  4;12,24,13,1;,
  4;13,25,26,14;,
  4;14,26,27,15;,
  4;15,27,28,16;,
  4;16,28,29,17;,
  4;17,29,30,18;,
  4;18,30,31,19;,
  4;19,31,32,20;,
  4;20,32,33,21;,
  4;21,33,34,22;,
  4;22,34,35,23;,
  4;23,35,36,24;,
  4;24,36,25,13;,
  4;25,37,38,26;,
  4;26,38,39,27;,
  4;27,39,40,28;,
  4;28,40,41,29;,
  4;29,41,42,30;,
  4;30,42,43,31;,
  4;31,43,44,32;,
  4;32,44,45,33;,
  4;33,45,46,34;,
  4;34,46,47,35;,
  4;35,47,48,36;,
  4;36,48,37,25;,
  4;37,49,50,38;,
  4;38,50,51,39;,
  4;39,51,52,40;,
  4;40,52,53,41;,
  4;41,53,54,42;,
  4;42,54,55,43;,
  4;43,55,56,44;,
  4;44,56,57,45;,
  4;45,57,58,46;,
  4;46,58,59,47;,
  4;47,59,60,48;,
  4;48,60,49,37;,
  4;49,61,62,50;,
  4;50,62,63,51;,
  4;51,63,64,52;,
  4;52,64,65,53;,
  4;53,65,66,54;,
  4;54,66,67,55;,
  4;55,67,68,56;,
  4;56,68,69,57;,
  4;57,69,70,58;,
  4;58,70,71,59;,
  4;59,71,72,60;,
  4;60,72,61,49;,
  4;61,73,74,62;,
  4;62,74,75,63;,
  4;63,75,76,64;,
  4;64,76,77,65;,
  4;65,77,78,66;,
  4;66,78,79,67;,
  4;67,79,80,68;,
  4;68,80,81,69;,
  4;69,81,82,70;,
  4;70,82,83,71;,
  4;71,83,84,72;,
  4;72,84,73,61;,
  4;85,85,85,85;,
  4;86,87,91,90;,
  4;87,88,92,91;,
  4;88,89,93,92;,
  4;90,91,95,94;,
  4;91,92,96,95;,
  4;92,93,97,96;,
  4;94,95,99,98;,
  4;95,96,100,99;,
  4;96,97,101,100;,
  4;98,99,103,102;,
  4;99,100,104,103;,
  4;100,101,105,104;,
  4;102,103,107,106;,
  4;103,104,108,107;,
  4;104,105,109,108;,
  4;106,107,111,110;,
  4;107,108,112,111;,
  4;108,109,113,112;,
  4;118,119,123,122;,
  4;119,120,124,123;,
  4;120,121,125,124;,
  4;122,123,127,126;,
  4;123,124,128,127;,
  4;124,125,129,128;,
  4;126,127,87,86;,
  4;127,128,88,87;,
  4;128,129,89,88;,
  4;89,129,130,93;,
  4;129,125,131,130;,
  4;125,121,117,131;,
  4;93,130,132,97;,
  4;130,131,133,132;,
  4;131,117,115,133;,
  4;97,132,105,101;,
  4;132,133,109,105;,
  4;133,115,113,109;,
  4;153,122,134,116;,
  4;122,126,135,134;,
  4;126,86,90,135;,
  4;116,134,136,114;,
  4;134,135,137,136;,
  4;135,90,94,137;,
  4;114,136,106,110;,
  4;136,137,102,106;,
  4;137,94,98,102;,
  4;138,138,138,138;,
  4;139,139,139,139;,
  4;140,140,140,140;,
  4;141,141,141,141;,
  4;142,142,142,142;,
  4;143,143,143,143;,
  4;138,138,138,138;,
  4;144,144,144,144;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;138,138,138,138;,
  4;148,148,148,148;,
  4;138,138,138,138;,
  4;144,144,144,144;,
  4;145,145,145,145;,
  4;147,147,147,147;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;138,138,138,138;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;138,138,138,138;,
  4;148,148,148,148;,
  4;148,148,148,148;,
  4;145,145,145,145;,
  4;144,144,144,144;,
  4;138,138,138,138;,
  4;145,145,145,145;,
  4;144,144,144,144;,
  4;138,138,138,138;,
  4;146,146,146,146;,
  4;146,146,146,146;,
  4;138,138,138,138;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;138,138,138,138;,
  4;145,145,145,145;,
  4;148,148,148,148;,
  4;138,149,138,138;,
  4;144,144,144,144;,
  4;150,145,145,145;,
  4;147,147,147,147;,
  4;145,152,150,145;,
  4;146,146,146,146;,
  4;151,138,138,149;,
  4;148,148,148,148;,
  4;148,148,148,148;,
  4;151,149,151,149;,
  4;144,144,144,144;,
  4;154,152,150,152;,
  4;138,138,149,151;,
  4;144,144,144,144;,
  4;145,145,152,154;,
  4;147,147,147,147;,
  4;147,147,147,147;,
  4;145,145,145,154;,
  4;138,138,149,138;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;138,138,138,138;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;138,138,138,138;,
  4;147,147,147,147;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;138,138,138,138;,
  4;138,138,138,138;,
  4;145,145,145,145;,
  4;148,148,148,148;,
  4;148,148,148,148;,
  4;138,138,138,138;,
  4;144,144,144,144;,
  4;145,145,145,145;,
  4;147,147,147,147;,
  4;138,138,138,138;,
  4;144,144,144,144;,
  4;145,145,145,145;,
  4;148,148,148,148;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;145,145,145,154;,
  4;144,144,144,144;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;145,145,145,145;,
  4;144,144,144,144;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;145,145,145,145;,
  4;144,144,144,144;,
  4;146,146,146,146;,
  4;145,145,145,145;,
  4;144,144,144,144;,
  4;146,146,146,146;,
  4;148,148,148,148;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;146,146,146,146;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;148,148,148,148;,
  4;138,138,138,138;,
  4;146,146,146,146;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;148,148,148,148;,
  4;138,138,138,138;,
  4;146,146,146,146;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;148,148,148,148;,
  4;138,138,138,138;,
  4;146,146,146,146;,
  4;144,144,144,144;,
  4;147,147,147,147;,
  4;138,138,138,138;,
  4;146,146,146,146;,
  4;147,147,147,147;,
  4;148,148,148,148;,
  4;138,138,138,138;,
  4;148,148,148,148;,
  4;144,144,144,144;,
  4;145,145,145,145;,
  4;147,147,147,147;,
  4;147,147,147,147;,
  4;148,148,148,148;,
  4;146,146,146,146;,
  4;144,144,144,144;,
  4;138,138,138,138;;
 }
 MeshTextureCoords {
  326;
  0.083806;0.293544;
  0.178705;0.314777;
  0.243135;0.314777;
  0.315920;0.314777;
  0.405855;0.314777;
  0.525346;0.314777;
  -0.337074;0.314777;
  -0.222618;0.314777;
  -0.136170;0.314777;
  -0.065117;0.314777;
  -0.001510;0.314777;
  0.058742;0.314777;
  0.118118;0.314777;
  0.193898;0.377028;
  0.267834;0.377028;
  0.348422;0.377028;
  0.438743;0.377028;
  0.539404;0.377028;
  0.644368;0.377028;
  0.662926;0.314777;
  0.743620;0.377028;
  0.777382;0.314777;
  0.832276;0.377028;
  0.863830;0.314777;
  0.911617;0.377028;
  0.934883;0.314777;
  0.984799;0.377028;
  0.998490;0.314777;
  1.054691;0.377028;
  1.058742;0.314777;
  0.054691;0.377028;
  0.123660;0.377028;
  0.199544;0.476056;
  0.276430;0.476056;
  0.358515;0.476056;
  0.447376;0.476056;
  0.542553;0.476056;
  0.640138;0.476056;
  0.734501;0.476056;
  0.822265;0.476056;
  0.903414;0.476056;
  0.979677;0.476056;
  1.053137;0.476056;
  0.053137;0.476056;
  0.125783;0.476056;
  0.202199;0.605111;
  0.280356;0.605111;
  0.362929;0.605111;
  0.450961;0.605111;
  0.543813;0.605111;
  0.638440;0.605111;
  0.730685;0.605111;
  0.817854;0.605111;
  0.899646;0.605111;
  0.977261;0.605111;
  1.052394;0.605111;
  0.052394;0.605111;
  0.126795;0.605111;
  0.203454;0.755399;
  0.282186;0.755399;
  0.364945;0.755399;
  0.452563;0.755399;
  0.544368;0.755399;
  0.637691;0.755399;
  0.728973;0.755399;
  0.815832;0.755399;
  0.897885;0.755399;
  0.976117;0.755399;
  1.052041;0.755399;
  0.052041;0.755399;
  0.127278;0.755399;
  0.203829;0.916679;
  0.282730;0.916679;
  0.365538;0.916679;
  0.453031;0.916679;
  0.544529;0.916679;
  0.637473;0.916679;
  0.728473;0.916679;
  0.815236;0.916679;
  0.897362;0.916679;
  0.975775;0.916679;
  1.051935;0.916679;
  0.051935;0.916679;
  0.127422;0.916679;
  0.203454;1.077958;
  0.282186;1.077958;
  0.364945;1.077958;
  0.452563;1.077958;
  0.544368;1.077958;
  0.637691;1.077958;
  0.728973;1.077958;
  0.815832;1.077958;
  0.897885;1.077958;
  0.976117;1.077958;
  1.052041;1.077958;
  0.052041;1.077958;
  0.127278;1.077958;
  0.000000;0.000000;
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  0.582800;-0.063770;
  0.381960;-0.038820;
  1.024280;-0.105400;
  0.749440;-0.077890;
  0.304790;0.072650;
  0.217760;0.089330;
  0.024280;-0.105400;
  0.275430;0.265130;
  0.188770;0.407490;
  0.946570;0.120940;
  0.835250;0.039260;
  0.079430;0.319460;
  -0.053430;0.120940;
  0.131460;0.496050;
  0.935720;0.341710;
  0.874590;0.261010;
  1.079430;0.319460;
  0.991380;0.462410;
  0.071350;0.593720;
  -0.008620;0.462410;
  0.888370;0.505570;
  0.831900;0.410850;
  0.995450;0.704100;
  1.071350;0.593720;
  1.064500;0.819540;
  0.828010;0.805650;
  0.796660;0.588430;
  0.936530;1.004180;
  1.055240;0.997120;
  0.782040;1.011830;
  0.755320;0.859150;
  0.841950;1.185880;
  1.068000;1.296880;
  0.575910;0.431860;
  0.543220;0.566760;
  0.516560;0.323340;
  0.580900;0.207910;
  0.448410;0.728680;
  0.406790;0.518080;
  0.393880;0.864580;
  0.350100;0.612790;
  0.471820;0.023260;
  0.578760;0.030330;
  0.346400;0.218000;
  0.312490;0.435210;
  0.229100;0.600910;
  0.289350;0.900990;
  0.364120;1.040560;
  0.136120;0.750550;
  0.170360;1.050630;
  0.259540;1.218030;
  0.064500;0.819540;
  0.055240;0.997120;
  0.068000;1.296880;
  0.637360;0.305490;
  0.631960;0.527480;
  0.669140;0.005410;
  0.725340;0.455130;
  0.693300;0.692800;
  0.781530;0.155050;
  -51.189140;-51.189140;
  52.189140;-51.189140;
  52.189140;52.189140;
  -51.189140;52.189140;
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
  1.000000;0.000000;
  1.000000;1.000000;
  0.000000;1.000000;
  1.057784;0.086763;
  0.877295;0.900149;
  -0.112589;0.907193;
  0.067899;0.093807;
  -0.045974;1.125066;
  0.134514;0.311680;
  0.943910;1.118022;
  1.124398;0.304637;
  2.034031;1.110265;
  2.214519;0.296880;
  1.967416;0.892392;
  2.147904;0.079006;
  1.240002;-0.734422;
  2.330123;-0.742179;
  1.306617;-0.516549;
  2.396738;-0.524305;
  3.555611;-0.532551;
  3.488997;-0.750425;
  3.373393;0.288634;
  3.306778;0.070760;
  4.707850;-0.540750;
  4.641235;-0.758623;
  4.525631;0.280435;
  4.459017;0.062562;
  4.207442;1.714381;
  4.140828;1.496508;
  3.055203;1.722580;
  2.988589;1.504707;
  2.856908;2.616215;
  4.009147;2.608016;
  2.790293;2.398342;
  3.942532;2.390143;
  5.188019;2.381281;
  5.254634;2.599154;
  5.386315;1.487646;
  5.452929;1.705519;
  6.385777;2.372758;
  6.452391;2.590631;
  6.584072;1.479123;
  6.650687;1.696996;
  5.577673;0.625273;
  6.775430;0.616750;
  5.644288;0.843146;
  6.842045;0.834624;
  7.882753;1.688229;
  8.074111;0.825857;
  7.816138;1.470356;
  8.007496;0.607984;
  8.396620;-1.145865;
  8.467056;-0.915493;
  7.164554;-1.137098;
  7.234990;-0.906726;
  7.395021;-2.175720;
  8.627087;-2.184487;
  7.465457;-1.945348;
  8.697523;-1.954114;
  10.285277;-1.965412;
  10.214841;-2.195785;
  10.054810;-0.926791;
  9.984374;-1.157163;
  12.192426;-1.978983;
  12.121989;-2.209355;
  11.961958;-0.940361;
  11.891522;-1.170734;
  10.190389;-2.275761;
  9.959921;-1.237140;
  12.097537;-2.289332;
  11.867069;-1.250710;
  13.613619;-2.219969;
  13.589166;-2.299945;
  13.383151;-1.181347;
  13.358699;-1.261324;
  12.075531;-2.361304;
  11.845063;-1.322683;
  13.567161;-2.371918;
  13.336693;-1.333297;
  15.271976;-2.311919;
  15.249970;-2.383892;
  15.041509;-1.273298;
  15.019503;-1.345271;
  13.544929;-2.444630;
  13.314461;-1.406009;
  15.227738;-2.456604;
  14.997272;-1.417983;
  16.047987;-2.462441;
  15.817519;-1.423820;
  15.839751;-1.351107;
  16.070217;-2.389729;
  16.403351;-4.063925;
  16.425583;-3.991213;
  15.583104;-4.058089;
  15.605335;-3.985376;
  17.233583;-6.004632;
  15.377522;2.359866;
  14.123466;2.368789;
  15.979527;-5.995708;
  14.160001;2.488281;
  15.997827;-5.794038;
  15.414057;2.479358;
  17.251883;-5.802961;
  10.023554;-0.785931;
  9.953117;-1.016303;
  8.435799;-0.774633;
  8.365363;-1.005005;
  11.860266;-1.029873;
  11.835813;-1.109850;
  9.928664;-1.096280;
  13.327442;-1.120464;
  13.305436;-1.192437;
  11.813807;-1.181823;
  14.988246;-1.204411;
  13.283205;-1.265149;
  14.966015;-1.277123;
  15.808495;-1.210247;
  15.786263;-1.282960;
  8.266225;-1.329252;
  9.853979;-1.340550;
  8.297482;-1.470112;
  9.885235;-1.481410;
  9.822868;-1.442302;
  11.730017;-1.455873;
  9.854124;-1.583163;
  11.761272;-1.596733;
  11.701351;-1.549627;
  13.192981;-1.560241;
  11.732608;-1.690487;
  13.224236;-1.701101;
  13.164090;-1.654729;
  14.846901;-1.666703;
  13.195347;-1.795589;
  14.878157;-1.807563;
  15.667149;-1.672540;
  15.698405;-1.813400;
  17.230524;-6.217097;
  17.296150;-6.002457;
  16.042095;-5.993534;
  15.976468;-6.208173;
  16.956839;-7.112228;
  15.702782;-7.103305;
  16.930805;-6.994911;
  15.676749;-6.985988;;
 }
}