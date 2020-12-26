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
 -278.44760;-275.25540;55.90540;,
 -283.28091;-297.57339;74.64510;,
 -271.73209;-295.08560;115.79250;,
 -273.17130;-279.08069;111.13430;,
 -277.45761;-249.80020;52.06880;,
 -273.42349;-257.00589;110.15080;,
 -278.68759;-228.42200;56.83970;,
 -273.10770;-248.07430;111.37250;,
 -288.13089;-219.45419;93.45060;,
 -269.95969;-244.32800;120.20610;,
 -282.61691;-299.18030;97.70420;,
 -270.01520;-299.13010;123.00230;,
 -304.02621;-219.99120;134.39020;,
 -265.50879;-244.55260;128.11169;,
 -275.62369;-326.13339;139.24870;,
 -263.89160;-303.38831;130.79900;,
 -323.56509;-236.21671;165.15630;,
 -262.46121;-251.33130;133.17619;,
 -295.33160;-206.08681;-14.03970;,
 -306.67969;-244.33279;-29.13480;,
 -293.01349;-181.97360;-2.97260;,
 -295.91171;-162.92770;7.28480;,
 -318.10620;-160.15540;15.75590;,
 -325.96191;-258.76270;-31.97480;,
 -351.42209;-166.47110;24.06660;,
 -354.65039;-258.34409;-27.47240;,
 -381.10431;-258.63809;-9.18820;,
 -334.87759;-333.56250;174.03760;,
 -375.92200;-185.34360;23.32880;,
 -391.95609;-236.04739;7.70390;,
 -383.46359;-209.77921;13.92390;,
 -333.63141;-259.39319;176.30710;,
 -333.72360;-282.45010;189.76019;,
 -330.83099;-349.10110;209.99831;,
 -262.40930;-345.41891;187.69560;,
 -253.87370;-341.29611;185.68970;,
 -247.54860;-338.27811;178.94659;,
 -260.98071;-300.50021;135.63631;,
 -313.12549;-273.49991;204.75960;,
 -333.88229;-301.03470;212.93050;,
 -246.24181;-312.68231;178.43230;,
 -247.46220;-288.90891;178.91251;,
 -261.37271;-261.74799;134.98489;,
 -259.56689;-283.46860;137.98570;,
 -287.97440;-262.17599;194.85941;,
 -254.35629;-272.39151;181.62621;,
 -315.35361;-375.11230;265.07620;,
 -278.54929;-378.89249;250.58839;,
 -243.23100;-375.34909;236.68629;,
 -232.28619;-359.65189;232.37849;,
 -297.86292;-303.92499;258.19141;,
 -318.62021;-331.46069;266.36200;,
 -230.97920;-334.05359;231.86430;,
 -232.19971;-319.33450;232.34430;,
 -272.71179;-292.60120;248.29131;,
 -239.09360;-302.81671;235.05800;,
 -334.31430;-158.87230;-122.20850;,
 -342.99969;-199.79491;-130.53410;,
 -333.67401;-133.13150;-115.40410;,
 -337.89731;-112.85860;-108.50800;,
 -366.21661;-110.17760;-98.16460;,
 -360.99460;-213.16859;-130.09930;,
 -402.08121;-117.20170;-87.53340;,
 -383.64331;-222.19080;-124.27630;,
 -415.69559;-215.56190;-112.15620;,
 -418.31891;-137.51880;-87.65360;,
 -429.64651;-190.46471;-98.39540;,
 -422.17471;-163.64360;-93.51710;,
 -374.29330;-105.53040;-244.39330;,
 -383.10818;-146.35580;-253.05110;,
 -373.57089;-79.84780;-237.38000;,
 -377.72809;-59.61820;-230.31970;,
 -405.82932;-56.92420;-219.97009;,
 -401.16559;-160.80040;-252.77769;,
 -441.71640;-63.91940;-209.39571;,
 -422.02051;-172.30460;-248.06900;,
 -456.47580;-168.61099;-235.74750;,
 -458.23160;-84.18910;-209.66409;,
 -469.73251;-137.00990;-220.83380;,
 -462.17480;-110.25320;-215.73820;,
 -415.62369;-118.11580;-353.11490;,
 -430.91119;-126.35960;-346.62979;,
 -453.36481;-133.60220;-343.37271;,
 -471.91791;-129.92740;-334.49829;,
 -502.25339;-108.76970;-320.89581;,
 -498.06451;-82.04220;-334.57211;,
 -413.14569;-117.68020;-346.54660;,
 -411.11609;-99.88180;-345.40729;,
 -406.81021;-77.29080;-344.45670;,
 -406.28821;-125.55200;-326.17419;,
 -402.31390;-108.89560;-320.14041;,
 -407.73541;-91.80100;-336.09949;,
 -400.83289;-82.48180;-326.06299;,
 -403.63159;-94.33590;-324.44821;,
 -397.12961;-85.69790;-314.66711;,
 -400.87250;-101.03610;-343.90070;,
 -396.91339;-89.67960;-333.07629;,
 -401.36539;-112.78970;-341.72409;,
 -400.06769;-114.29100;-337.88739;,
 -411.50269;-119.56630;-341.66589;,
 -395.27530;-116.90780;-328.10861;,
 -397.14899;-116.27430;-331.40961;,
 -408.05850;-123.51990;-331.43341;,
 -393.99771;-108.87680;-323.98880;,
 -393.73071;-91.91050;-323.96149;,
 -404.64951;-51.80360;-332.48441;,
 -406.02579;-50.95610;-336.89569;,
 -406.18961;-56.01530;-338.45831;,
 -410.64291;-40.57730;-323.43741;,
 -417.03711;-43.08090;-343.66379;,
 -416.54770;-63.76550;-347.84479;,
 -423.64969;-32.84850;-299.21649;,
 -436.59241;-74.56790;-362.91681;,
 -437.83090;-43.62390;-367.40479;,
 -453.56299;-27.66520;-289.10980;,
 -460.52240;-78.48860;-365.34381;,
 -463.94861;-43.68490;-371.82101;,
 -477.43790;-33.99450;-312.80319;,
 -482.32840;-75.90590;-351.00671;,
 -484.59940;-42.61360;-351.77829;,
 -493.74100;-73.12230;-339.98981;,
 -424.64499;8.01790;-308.04239;,
 -410.93231;7.97880;-325.99689;,
 -417.08871;7.97890;-344.11951;,
 -437.83099;7.97890;-367.40460;,
 -455.04291;7.97880;-302.23099;,
 -463.34320;8.38590;-372.13031;,
 -478.49551;8.01210;-322.04001;,
 -484.73318;7.97850;-352.92599;,
 -426.67929;89.81100;-310.57599;,
 -414.22470;89.77550;-327.02701;,
 -419.85269;89.77580;-343.59381;,
 -438.73318;89.77540;-364.84079;,
 -454.64359;89.77420;-305.18799;,
 -462.23129;90.14640;-369.08539;,
 -476.33969;89.80410;-323.25931;,
 -482.04199;89.77340;-351.49319;,
 -436.36389;105.15990;-321.93271;,
 -429.15411;105.13950;-331.49539;,
 -432.42181;105.13960;-341.11459;,
 -443.36261;105.13940;-353.44061;,
 -452.64871;105.13850;-318.78381;,
 -454.54639;105.35440;-346.36780;,
 -465.31570;105.15560;-329.26660;,
 -468.62650;105.13780;-345.66019;,
 -189.96330;-462.74100;531.30109;,
 -226.82739;-458.90350;545.59943;,
 -143.62550;-443.57071;513.32843;,
 -154.58791;-459.25180;517.58038;,
 -230.09930;-415.24631;546.86853;,
 -209.30850;-387.74219;538.80438;,
 -143.53880;-403.25229;513.29492;,
 -142.31641;-417.97360;512.82068;,
 -186.25020;-376.45370;529.86102;,
 -150.44380;-386.72409;515.97302;,
 -97.62110;-495.65881;773.34509;,
 -262.88760;-320.66830;206.55231;,
 -232.21761;-333.50281;197.18370;,
 -407.66180;-113.49850;-376.47531;,
 -438.33179;-100.66390;-367.10660;,
 -268.78281;-351.08899;187.44580;,
 -238.11290;-351.08899;178.07730;,
 -437.31400;-133.98891;-368.65039;,
 -336.81750;-329.34201;232.94479;,
 -304.61890;-321.08801;222.19209;,
 -478.89529;-101.08360;-348.40341;,
 -509.56549;-113.91810;-339.03491;,
 -339.97241;-351.08899;215.46780;,
 -309.30219;-351.08899;206.09950;,
 -477.83359;-133.98891;-349.99680;,
 -317.87949;-151.44250;27.06480;,
 -288.01300;-151.44250;17.74540;,
 -288.01300;-266.68549;17.74540;,
 -317.87949;-266.68549;27.06480;,
 -315.39050;-266.68549;35.40610;,
 -285.52411;-266.68549;26.08650;,
 -285.52411;-151.44250;26.08650;,
 -315.39050;-151.44250;35.40610;,
 -401.61130;-95.29630;-94.89410;,
 -431.47760;-95.29630;-85.57470;,
 -431.47760;-210.53960;-85.57470;,
 -401.61130;-210.53960;-94.89410;,
 -404.10001;-210.53960;-103.23530;,
 -433.96649;-210.53960;-93.91580;,
 -433.96649;-95.29630;-93.91580;,
 -404.10001;-95.29630;-103.23530;,
 -399.86221;-49.40670;-243.40280;,
 -369.99591;-49.40670;-252.72211;,
 -369.99591;-164.64999;-252.72211;,
 -399.86221;-164.64999;-243.40280;,
 -397.37341;-164.64999;-235.06149;,
 -367.50699;-164.64999;-244.38080;,
 -367.50699;-49.40670;-244.38080;,
 -397.37341;-49.40670;-235.06149;;
 
 170;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;8,6,7,9;,
 4;1,10,11,2;,
 4;12,8,9,13;,
 4;10,14,15,11;,
 4;16,12,13,17;,
 4;18,19,1,0;,
 4;20,18,0,4;,
 4;21,20,4,6;,
 4;22,21,6,8;,
 4;19,23,10,1;,
 4;24,22,8,12;,
 4;23,25,14,10;,
 4;25,26,27,14;,
 4;28,24,12,16;,
 4;29,30,31,32;,
 4;26,29,32,27;,
 4;30,28,16,31;,
 4;33,34,14,27;,
 4;35,36,37,15;,
 4;34,35,15,14;,
 4;38,39,32,31;,
 4;40,41,42,43;,
 4;39,33,27,32;,
 4;36,40,43,37;,
 4;44,38,31,16;,
 4;45,44,16,17;,
 4;41,45,17,42;,
 4;46,47,34,33;,
 4;48,49,36,35;,
 4;47,48,35,34;,
 4;50,51,39,38;,
 4;52,53,41,40;,
 4;51,46,33,39;,
 4;49,52,40,36;,
 4;54,50,38,44;,
 4;55,54,44,45;,
 4;53,55,45,41;,
 4;56,57,19,18;,
 4;58,56,18,20;,
 4;59,58,20,21;,
 4;60,59,21,22;,
 4;57,61,23,19;,
 4;62,60,22,24;,
 4;61,63,25,23;,
 4;63,64,26,25;,
 4;65,62,24,28;,
 4;66,67,30,29;,
 4;64,66,29,26;,
 4;67,65,28,30;,
 4;68,69,57,56;,
 4;70,68,56,58;,
 4;71,70,58,59;,
 4;72,71,59,60;,
 4;69,73,61,57;,
 4;74,72,60,62;,
 4;73,75,63,61;,
 4;75,76,64,63;,
 4;77,74,62,65;,
 4;78,79,67,66;,
 4;76,78,66,64;,
 4;79,77,65,67;,
 4;80,81,73,69;,
 4;81,82,75,73;,
 4;82,83,76,75;,
 4;84,85,79,78;,
 4;83,84,78,76;,
 4;86,87,88,80;,
 4;89,86,80,69;,
 4;90,89,69,68;,
 4;91,92,88,87;,
 4;93,90,68,94;,
 4;93,94,92,91;,
 4;95,96,91,87;,
 4;97,95,87,86;,
 4;98,97,86,99;,
 4;100,101,102,89;,
 4;103,100,89,90;,
 4;104,103,90,93;,
 4;96,104,93,91;,
 4;101,98,99,102;,
 3;105,106,107;,
 4;105,107,88,68;,
 3;105,68,70;,
 4;105,70,71,108;,
 4;105,108,109,106;,
 4;107,106,109,110;,
 4;107,110,80,88;,
 4;108,71,72,111;,
 4;112,81,80,110;,
 4;112,110,109,113;,
 4;111,72,74,114;,
 4;115,82,81,112;,
 4;115,112,113,116;,
 4;114,74,77,117;,
 4;118,83,82,115;,
 4;118,115,116,119;,
 3;120,119,117;,
 4;120,117,77,79;,
 3;120,79,85;,
 3;118,119,120;,
 4;118,120,85,84;,
 3;118,84,83;,
 4;121,122,108,111;,
 4;123,124,113,109;,
 4;122,123,109,108;,
 4;125,121,111,114;,
 4;124,126,116,113;,
 4;127,125,114,117;,
 4;128,127,117,119;,
 4;126,128,119,116;,
 4;129,130,122,121;,
 4;131,132,124,123;,
 4;130,131,123,122;,
 4;133,129,121,125;,
 4;132,134,126,124;,
 4;135,133,125,127;,
 4;136,135,127,128;,
 4;134,136,128,126;,
 4;137,138,130,129;,
 4;139,140,132,131;,
 4;138,139,131,130;,
 4;138,137,140,139;,
 4;141,137,129,133;,
 4;140,142,134,132;,
 4;137,141,142,140;,
 4;143,141,133,135;,
 4;144,143,135,136;,
 4;142,144,136,134;,
 4;141,143,144,142;,
 4;145,47,46,146;,
 4;147,49,48,148;,
 4;148,48,47,145;,
 4;149,51,50,150;,
 4;151,53,52,152;,
 4;146,46,51,149;,
 4;152,52,49,147;,
 4;150,50,54,153;,
 4;153,54,55,154;,
 4;154,55,53,151;,
 3;155,147,148;,
 3;155,152,147;,
 3;155,151,152;,
 3;155,154,151;,
 3;155,145,146;,
 3;155,148,145;,
 3;155,146,149;,
 3;155,149,150;,
 3;155,150,153;,
 3;155,153,154;,
 4;156,157,158,159;,
 4;160,161,157,156;,
 4;160,156,159,162;,
 4;163,164,165,166;,
 4;167,168,164,163;,
 4;164,168,169,165;,
 4;170,171,172,173;,
 4;174,175,176,177;,
 4;176,175,172,171;,
 4;174,177,170,173;,
 4;178,179,180,181;,
 4;182,183,184,185;,
 4;184,183,180,179;,
 4;182,185,178,181;,
 4;186,187,188,189;,
 4;190,191,192,193;,
 4;192,191,188,187;,
 4;190,193,186,189;;
 
 MeshMaterialList {
  9;
  170;
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
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "�R.bmp";
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
   0.170000;0.170000;0.170000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.220000;0.220000;0.220000;;
   TextureFilename {
    "�R.bmp";
   }
  }
  Material {
   0.190000;0.190000;0.190000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.310000;0.310000;0.310000;;
   TextureFilename {
    "��.bmp";
   }
  }
  Material {
   0.350000;0.350000;0.350000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.310000;0.310000;0.310000;;
   TextureFilename {
    "��.bmp";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
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
   0.706000;0.706000;0.706000;1.000000;;
   13.000000;
   0.540000;0.540000;0.540000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.320000;0.320000;0.320000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.310000;0.310000;0.310000;;
   TextureFilename {
    "��.bmp";
   }
  }
 }
 MeshNormals {
  189;
  -0.764605;0.375573;0.523760;,
  -0.554936;0.618284;0.556570;,
  -0.694580;0.587054;0.415844;,
  -0.869277;0.433190;0.238126;,
  -0.951592;-0.002307;0.307355;,
  -0.986514;0.084875;0.139950;,
  -0.971832;-0.145019;0.185771;,
  -0.996837;-0.001432;0.079458;,
  -0.688336;-0.654521;-0.312725;,
  -0.560766;-0.762356;-0.323040;,
  -0.779174;-0.621116;0.084275;,
  -0.971508;-0.204240;0.120240;,
  0.112153;0.931338;0.346455;,
  -0.263064;0.845771;0.464187;,
  -0.427013;0.798451;0.424425;,
  -0.866360;0.401733;0.296699;,
  0.944932;-0.113625;-0.306909;,
  -0.959835;0.136649;0.245039;,
  0.706220;-0.463626;-0.535074;,
  -0.989511;-0.028914;0.141533;,
  -0.076110;-0.818756;-0.569075;,
  -0.270146;-0.866012;-0.420766;,
  -0.653610;-0.732832;-0.189083;,
  -0.948736;-0.315523;-0.018579;,
  0.459354;0.866904;0.193575;,
  0.013342;0.929194;0.369352;,
  -0.217548;0.876728;0.428977;,
  -0.802068;0.395380;0.447618;,
  0.959213;0.099460;-0.264610;,
  -0.930259;0.108951;0.350355;,
  0.900533;-0.206224;-0.382769;,
  -0.964949;-0.110164;0.238198;,
  0.729636;-0.492241;-0.474689;,
  0.200033;-0.847765;-0.491204;,
  -0.277528;-0.866214;-0.415513;,
  -0.811513;-0.572691;-0.116064;,
  -0.759216;0.433255;0.485676;,
  -0.354661;0.764409;0.538419;,
  -0.957482;-0.005339;0.288445;,
  -0.967724;-0.190145;0.165392;,
  -0.742948;-0.651926;-0.151726;,
  0.128540;0.908332;0.398008;,
  -0.085150;0.877813;0.471375;,
  0.882874;-0.277929;-0.378536;,
  0.425861;-0.681300;-0.595376;,
  -0.099871;-0.859864;-0.500660;,
  -0.812656;0.414884;0.409220;,
  -0.292524;0.844358;0.448876;,
  -0.959070;-0.012623;0.282888;,
  -0.952580;-0.242408;0.183930;,
  -0.704136;-0.704206;-0.091030;,
  0.181923;0.926871;0.328349;,
  0.077731;0.924061;0.374259;,
  0.872975;-0.293186;-0.389815;,
  0.446008;-0.765371;-0.463988;,
  -0.076287;-0.924372;-0.373786;,
  0.616462;0.779972;0.107784;,
  0.030442;0.929930;0.366475;,
  -0.370509;0.802692;0.467342;,
  -0.776582;0.433226;0.457422;,
  0.952357;0.162826;-0.257882;,
  -0.940600;0.033477;0.337864;,
  0.917801;-0.131938;-0.374478;,
  -0.952669;-0.161010;0.257869;,
  0.826154;-0.344512;-0.445850;,
  0.374373;-0.790277;-0.485085;,
  -0.079771;-0.923205;-0.375937;,
  -0.941342;-0.264937;0.209007;,
  0.587245;0.797685;0.137266;,
  -0.018788;0.925395;0.378537;,
  -0.393220;0.807551;0.439590;,
  -0.757980;0.497688;0.421631;,
  0.957914;0.182999;-0.221162;,
  -0.942142;0.029570;0.333906;,
  0.906086;-0.248132;-0.342692;,
  -0.948520;-0.198747;0.246595;,
  0.849956;-0.361085;-0.383656;,
  0.358300;-0.823189;-0.440432;,
  -0.153483;-0.939442;-0.306418;,
  -0.802342;-0.589047;0.096284;,
  0.588367;0.623339;0.515047;,
  0.117202;0.703936;0.700527;,
  -0.276229;0.586997;0.761007;,
  -0.655490;0.347822;0.670338;,
  0.897303;0.272135;0.347547;,
  -0.894290;0.038466;0.445832;,
  0.833054;-0.420833;-0.359055;,
  -0.829356;-0.314450;0.461833;,
  0.828077;0.054955;0.557914;,
  0.275321;0.082482;0.957807;,
  -0.465288;0.033360;0.884530;,
  -0.798741;-0.179172;0.574378;,
  -0.754064;0.508431;0.415794;,
  -0.918665;0.109188;0.379647;,
  -0.681984;0.436865;0.586555;,
  -0.808883;0.166308;0.563959;,
  -0.914004;0.241971;0.325648;,
  -0.493355;0.742416;0.453233;,
  -0.899409;0.181447;0.397669;,
  -0.497487;0.743404;0.447053;,
  -0.501388;0.743559;0.442414;,
  -0.315023;0.149210;-0.937282;,
  -0.412670;0.458719;0.786943;,
  -0.207550;-0.333965;0.919451;,
  -0.126792;-0.693401;0.709309;,
  -0.183187;-0.152054;-0.971248;,
  -0.930640;-0.250034;0.267194;,
  0.895418;-0.270842;-0.353370;,
  0.301953;-0.618877;-0.725131;,
  -0.268359;-0.809942;-0.521515;,
  -0.879022;-0.476521;0.015741;,
  0.622345;0.217257;0.751988;,
  0.248297;0.261965;0.932589;,
  -0.286253;0.150366;0.946282;,
  -0.514226;-0.064792;0.855204;,
  -0.801754;-0.122816;0.584899;,
  0.901666;-0.354972;-0.246968;,
  0.949662;-0.018762;0.312715;,
  0.277270;-0.016200;0.960655;,
  -0.489814;-0.014881;0.871700;,
  -0.865885;-0.013840;0.500052;,
  0.867826;-0.065885;-0.492481;,
  0.246444;-0.148678;-0.957685;,
  -0.560938;-0.118784;-0.819292;,
  -0.988887;-0.043768;-0.142078;,
  0.922202;-0.339104;-0.185881;,
  0.242222;-0.463184;0.852520;,
  -0.420645;-0.403322;0.812644;,
  -0.810596;-0.343433;0.474329;,
  0.803140;-0.354076;-0.479163;,
  0.235385;-0.378603;-0.895128;,
  -0.481198;-0.396919;-0.781604;,
  -0.900158;-0.412750;-0.139119;,
  0.403020;-0.901965;0.155030;,
  0.094211;-0.941762;0.322814;,
  -0.153011;-0.931467;0.330086;,
  -0.493958;-0.819416;0.290796;,
  0.481109;-0.827950;-0.288154;,
  0.103153;-0.916641;-0.386171;,
  -0.202796;-0.922477;-0.328497;,
  -0.489694;-0.869077;-0.070040;,
  -0.985305;0.048120;0.163883;,
  -0.889409;0.342520;0.302709;,
  -0.407038;0.863500;0.297806;,
  -0.972847;-0.016655;0.230849;,
  -0.956983;-0.245651;0.154401;,
  -0.695569;-0.714346;-0.076770;,
  0.161600;0.974595;0.155082;,
  0.074893;0.979603;0.186464;,
  0.836854;-0.289329;-0.464719;,
  0.451849;-0.762498;-0.463066;,
  -0.054398;-0.936135;-0.347407;,
  0.430534;0.878894;0.205393;,
  -0.958544;-0.019765;0.284258;,
  0.114781;-0.653119;0.748505;,
  -0.175734;0.900949;0.396748;,
  0.959028;0.024737;-0.282231;,
  0.308448;-0.559440;0.769341;,
  0.297878;0.000000;0.954604;,
  -0.297871;0.000000;-0.954606;,
  -0.297874;0.000000;-0.954605;,
  0.297872;0.000000;0.954606;,
  0.297869;0.000000;0.954607;,
  -0.297870;0.000000;-0.954607;,
  0.031814;0.943231;0.330610;,
  0.948448;0.268830;-0.167861;,
  0.983092;0.147959;-0.107882;,
  0.855162;-0.333331;-0.396974;,
  0.988728;0.051161;-0.140712;,
  0.963387;0.078735;-0.256294;,
  -0.214630;-0.921084;-0.324868;,
  -0.209835;-0.919149;-0.333367;,
  -0.412428;0.434166;-0.800876;,
  0.251299;-0.919979;-0.300811;,
  0.941425;-0.321459;-0.101894;,
  0.690159;0.121155;0.713444;,
  0.676834;0.177617;0.714386;,
  -0.839709;-0.089741;-0.535570;,
  0.523918;-0.445221;0.726146;,
  0.920463;0.080105;-0.382533;,
  0.047918;0.992018;0.116633;,
  0.633002;-0.515403;-0.577640;,
  -0.368026;-0.880987;-0.297351;,
  0.958250;0.000000;-0.285931;,
  -0.958249;0.000000;0.285935;,
  -0.958250;0.000000;0.285931;,
  0.958257;0.000000;-0.285909;,
  0.958251;0.000000;-0.285928;,
  -0.958255;0.000000;0.285915;;
  170;
  4;17,15,3,5;,
  4;19,17,5,7;,
  4;23,19,7,11;,
  4;22,23,11,10;,
  4;15,14,2,3;,
  4;21,22,10,9;,
  4;14,13,1,2;,
  4;20,21,9,8;,
  4;29,27,15,17;,
  4;31,29,17,19;,
  4;35,31,19,23;,
  4;34,35,23,22;,
  4;164,26,14,164;,
  4;33,34,22,21;,
  4;26,25,13,14;,
  4;25,24,12,13;,
  4;32,33,21,20;,
  4;28,30,18,16;,
  4;165,28,16,166;,
  4;30,32,167,18;,
  4;41,42,13,12;,
  4;37,36,0,1;,
  4;42,37,1,13;,
  4;44,43,16,18;,
  4;38,39,6,4;,
  4;43,168,166,16;,
  4;36,38,4,0;,
  4;45,44,18,20;,
  4;40,45,20,8;,
  4;39,40,8,6;,
  4;51,52,42,41;,
  4;47,46,36,37;,
  4;52,47,37,42;,
  4;54,53,43,44;,
  4;48,49,39,38;,
  4;53,169,168,43;,
  4;46,48,38,36;,
  4;55,54,44,45;,
  4;50,55,45,40;,
  4;49,50,40,39;,
  4;61,59,27,29;,
  4;63,61,29,31;,
  4;67,63,31,35;,
  4;66,170,35,34;,
  4;59,58,26,27;,
  4;65,66,34,33;,
  4;58,57,25,26;,
  4;57,56,24,25;,
  4;64,65,33,32;,
  4;60,62,30,28;,
  4;56,60,28,24;,
  4;62,64,32,30;,
  4;73,71,59,61;,
  4;75,73,61,63;,
  4;79,75,63,67;,
  4;78,171,170,66;,
  4;71,70,58,59;,
  4;77,78,66,65;,
  4;70,69,57,58;,
  4;69,68,56,57;,
  4;76,77,65,64;,
  4;72,74,62,60;,
  4;68,72,60,56;,
  4;74,76,64,62;,
  4;83,82,70,71;,
  4;82,81,69,70;,
  4;81,80,68,69;,
  4;84,86,74,72;,
  4;80,84,72,68;,
  4;94,95,85,83;,
  4;92,94,83,71;,
  4;93,92,71,73;,
  4;96,96,85,95;,
  4;98,93,73,98;,
  4;98,98,96,96;,
  4;103,104,104,104;,
  4;102,103,95,94;,
  4;97,102,94,97;,
  4;100,99,99,92;,
  4;101,172,172,101;,
  4;105,101,101,105;,
  4;173,173,173,173;,
  4;99,97,97,99;,
  3;106,87,115;,
  4;106,115,85,73;,
  3;106,73,75;,
  4;106,75,79,110;,
  4;106,110,91,87;,
  4;115,87,91,114;,
  4;115,114,83,85;,
  4;110,79,78,109;,
  4;113,82,83,114;,
  4;113,114,91,90;,
  4;109,78,77,108;,
  4;112,81,82,113;,
  4;112,113,90,89;,
  4;108,77,76,107;,
  4;111,80,81,112;,
  4;111,112,89,88;,
  3;116,174,107;,
  4;116,107,76,74;,
  3;116,74,86;,
  3;111,88,175;,
  4;111,175,176,84;,
  3;111,84,80;,
  4;123,124,110,177;,
  4;120,119,90,91;,
  4;124,120,91,110;,
  4;122,123,109,108;,
  4;119,118,89,90;,
  4;121,122,108,107;,
  4;117,121,107,88;,
  4;118,117,88,89;,
  4;131,132,124,123;,
  4;128,127,119,120;,
  4;132,128,120,124;,
  4;130,131,123,122;,
  4;127,126,118,119;,
  4;129,130,122,121;,
  4;125,129,121,117;,
  4;126,178,117,118;,
  4;139,140,132,131;,
  4;136,135,127,128;,
  4;140,136,128,132;,
  4;140,139,135,136;,
  4;138,139,131,130;,
  4;135,134,126,127;,
  4;139,138,134,135;,
  4;137,138,130,129;,
  4;133,137,129,125;,
  4;134,133,178,126;,
  4;138,137,133,134;,
  4;148,52,51,147;,
  4;142,46,47,143;,
  4;143,47,52,148;,
  4;149,53,54,150;,
  4;145,49,48,144;,
  4;179,169,53,149;,
  4;144,48,46,142;,
  4;150,54,55,151;,
  4;151,55,50,146;,
  4;146,50,49,145;,
  3;141,142,143;,
  3;141,144,142;,
  3;141,145,144;,
  3;141,146,145;,
  3;180,148,147;,
  3;180,143,148;,
  3;181,179,149;,
  3;181,149,150;,
  3;181,150,151;,
  3;182,151,146;,
  4;152,152,152,152;,
  4;154,154,154,154;,
  4;153,153,153,153;,
  4;155,155,155,155;,
  4;157,157,157,157;,
  4;156,156,156,156;,
  4;159,159,159,159;,
  4;158,158,158,158;,
  4;183,183,183,183;,
  4;184,184,184,184;,
  4;161,161,161,161;,
  4;160,160,160,160;,
  4;185,185,185,185;,
  4;186,186,186,186;,
  4;163,163,163,163;,
  4;162,162,162,162;,
  4;187,187,187,187;,
  4;188,188,188,188;;
 }
 MeshTextureCoords {
  194;
  -1.930851;-11.403784;
  -1.807267;-12.162887;
  -0.733058;-12.331227;
  -0.582119;-11.984422;
  -1.607076;-10.824595;
  -0.237916;-11.530817;
  -1.123347;-10.468808;
  -0.057908;-11.356651;
  -0.003287;-10.885239;
  0.224650;-11.313928;
  -1.240299;-12.437018;
  -0.618920;-12.457908;
  1.086529;-11.674497;
  0.413476;-11.314831;
  -0.636019;-13.300357;
  -0.504682;-12.505201;
  1.660878;-12.744102;
  0.423040;-11.446009;
  -2.537298;-9.572182;
  -3.536811;-10.413486;
  -1.854490;-9.157925;
  -1.263691;-8.944312;
  -0.940724;-9.436159;
  -3.801078;-11.069591;
  -0.744805;-10.338303;
  -3.603024;-11.698231;
  -3.066757;-12.448062;
  0.292757;-15.049052;
  -1.015430;-11.214622;
  -2.224626;-12.398760;
  -1.647081;-11.760748;
  1.587751;-13.543792;
  1.550088;-14.162334;
  0.951277;-15.679342;
  0.258468;-13.957129;
  0.253321;-13.676543;
  0.113120;-13.411216;
  -0.339063;-12.440530;
  2.033387;-13.724999;
  1.838317;-14.799007;
  0.524225;-12.859447;
  0.937145;-12.407394;
  0.292818;-11.655086;
  0.002588;-12.092016;
  1.901400;-12.870809;
  1.301264;-12.243426;
  1.898719;-16.499611;
  1.365432;-15.662550;
  0.973548;-14.713799;
  1.096117;-14.123584;
  2.865103;-14.621010;
  2.670011;-15.695044;
  1.507267;-13.571761;
  1.768852;-13.303416;
  2.733116;-13.766821;
  2.132977;-13.139436;
  -4.440295;-8.215528;
  -5.316645;-9.131523;
  -3.836006;-7.755434;
  -3.308059;-7.506866;
  -2.922298;-8.146668;
  -5.482035;-9.776076;
  -2.671643;-9.141036;
  -5.423404;-10.487228;
  -4.916042;-11.143010;
  -2.971996;-9.884354;
  -4.104815;-11.071655;
  -3.550021;-10.428476;
  -6.600282;-6.599878;
  -7.483250;-7.512877;
  -5.991784;-6.141595;
  -5.460493;-5.894368;
  -5.074922;-6.529511;
  -7.670544;-8.178652;
  -4.825193;-7.523126;
  -7.686851;-8.891110;
  -7.217083;-9.657871;
  -5.127858;-8.269522;
  -6.269186;-9.453099;
  -5.710080;-8.811872;
  -9.510900;-6.498480;
  -9.441345;-7.050463;
  -9.419750;-7.693125;
  -9.080773;-8.096575;
  -8.296773;-8.438828;
  -8.214205;-7.659472;
  -9.340437;-6.511582;
  -9.018828;-6.121516;
  -8.627926;-5.585522;
  -8.963709;-6.756305;
  -8.539845;-6.403749;
  -8.652185;-5.991331;
  -8.255203;-5.771980;
  -8.404326;-6.087655;
  -8.024282;-5.887500;
  -9.025908;-5.951895;
  -8.566854;-5.760185;
  -9.164850;-6.224542;
  -9.094233;-6.270884;
  -9.250187;-6.570213;
  -8.897899;-6.334057;
  -8.967684;-6.323040;
  -9.060964;-6.693130;
  -8.660599;-6.190538;
  -8.377024;-5.841136;
  -7.898365;-5.156624;
  -7.994545;-5.118799;
  -8.119033;-5.207513;
  -7.461453;-5.151642;
  -8.009026;-5.109561;
  -8.463997;-5.472964;
  -6.672815;-5.529083;
  -8.981570;-5.935746;
  -8.577073;-5.283609;
  -6.247190;-6.148129;
  -9.047412;-6.478345;
  -8.624081;-5.770676;
  -6.902687;-6.503182;
  -8.577123;-7.030986;
  -8.034701;-6.393458;
  -8.216316;-7.330040;
  -6.215151;-4.622653;
  -6.715263;-4.144070;
  -7.167275;-4.069598;
  -7.714607;-4.236618;
  -5.986484;-5.310058;
  -7.763364;-4.698370;
  -6.436417;-5.570347;
  -7.218426;-5.357011;
  -4.908239;-2.976728;
  -5.366180;-2.540462;
  -5.779384;-2.472382;
  -6.278935;-2.623844;
  -4.696812;-3.609580;
  -6.321117;-3.050416;
  -5.106499;-3.853204;
  -5.821358;-3.658192;
  -4.919779;-2.737924;
  -5.185890;-2.484937;
  -5.425810;-2.445407;
  -5.715647;-2.533021;
  -4.796365;-3.106584;
  -5.500233;-2.835869;
  -5.033807;-3.249580;
  -5.448879;-3.136345;
  6.983222;-18.655993;
  7.512729;-19.491018;
  6.718665;-17.119549;
  6.594968;-17.709179;
  8.283697;-18.686260;
  8.480923;-17.613359;
  7.391434;-16.299362;
  7.129956;-16.567778;
  8.378511;-16.813318;
  7.754843;-16.135006;
  12.443740;-20.111355;
  5.588292;-15.764767;
  5.140356;-14.943751;
  -15.223468;-13.615260;
  -14.775527;-14.436275;
  4.593325;-16.476402;
  4.253067;-15.398980;
  -15.113876;-15.060206;
  6.482431;-18.553989;
  6.159136;-17.253437;
  -14.085926;-15.900803;
  -13.853343;-17.234646;
  5.624821;-19.008251;
  5.284571;-17.930819;
  -14.422635;-16.514629;
  0.058975;-13.346801;
  -0.279930;-12.296633;
  -1.246755;-14.598980;
  -0.907850;-15.649147;
  -0.584953;-15.606642;
  -0.923866;-14.556476;
  0.042959;-12.254128;
  0.381872;-13.304295;
  -4.222781;-14.438241;
  -3.883876;-15.488403;
  -4.850704;-17.790756;
  -5.189609;-16.740595;
  -5.512501;-16.783092;
  -5.173593;-17.833260;
  -4.206765;-15.530907;
  -4.545674;-14.480739;
  -9.555818;-12.729513;
  -9.894718;-11.679352;
  -10.861547;-13.981706;
  -10.522645;-15.031867;
  -10.199748;-14.989367;
  -10.538650;-13.939201;
  -9.571821;-11.636847;
  -9.232921;-12.687014;;
 }
}