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
 308;
 -11.05000;22.13150;11.05000;,
 -11.05000;22.13150;-11.05000;,
 11.05000;22.13150;-11.05000;,
 11.05000;22.13150;11.05000;,
 -11.05000;22.13150;-11.05000;,
 -11.05000;0.03150;-11.05000;,
 11.05000;0.03150;-11.05000;,
 11.05000;22.13150;-11.05000;,
 -11.05000;0.03150;-11.05000;,
 -11.05000;0.03150;11.05000;,
 11.05000;0.03150;11.05000;,
 11.05000;0.03150;-11.05000;,
 11.05000;22.13150;11.05000;,
 11.05000;22.13150;-11.05000;,
 11.05000;0.03150;-11.05000;,
 11.05000;0.03150;11.05000;,
 -11.05000;0.03150;11.05000;,
 -11.05000;0.03150;-11.05000;,
 -11.05000;22.13150;-11.05000;,
 -11.05000;22.13150;11.05000;,
 -4.78040;11.86780;11.05000;,
 -4.78040;2.30700;11.05000;,
 -11.05000;0.03150;11.05000;,
 -11.05000;22.13150;11.05000;,
 4.78040;11.86780;11.05000;,
 11.05000;22.13150;11.05000;,
 4.78040;2.30700;11.05000;,
 11.05000;0.03150;11.05000;,
 -4.78040;11.86780;22.86490;,
 -4.78040;2.30700;22.86490;,
 -4.78040;2.30700;11.05000;,
 -4.78040;11.86780;11.05000;,
 4.78040;11.86780;22.86490;,
 -4.78040;11.86780;22.86490;,
 -4.78040;11.86780;11.05000;,
 4.78040;11.86780;11.05000;,
 4.78040;2.30700;22.86490;,
 4.78040;11.86780;22.86490;,
 4.78040;11.86780;11.05000;,
 4.78040;2.30700;11.05000;,
 -4.78040;2.30700;22.86490;,
 4.78040;2.30700;22.86490;,
 4.78040;2.30700;11.05000;,
 -4.78040;2.30700;11.05000;,
 -11.44450;21.85290;22.81690;,
 -11.44450;-40.48660;22.81690;,
 -4.78040;2.30700;22.86490;,
 -4.78040;11.86780;22.86490;,
 15.13430;21.85290;22.81690;,
 4.78040;11.86780;22.86490;,
 15.13430;-40.48660;22.81690;,
 4.78040;2.30700;22.86490;,
 15.13430;21.85290;47.88920;,
 -11.44450;21.85290;47.88920;,
 -11.44450;21.85290;22.81690;,
 15.13430;21.85290;22.81690;,
 15.13430;-40.48660;47.88920;,
 15.13430;21.85290;47.88920;,
 15.13430;21.85290;22.81690;,
 15.13430;-40.48660;22.81690;,
 -11.44450;-40.48660;47.88920;,
 15.13430;-40.48660;47.88920;,
 15.13430;-40.48660;22.81690;,
 -11.44450;-40.48660;22.81690;,
 -11.44450;-40.48660;47.88920;,
 -11.44450;21.85290;47.88920;,
 15.13430;21.85290;47.88920;,
 15.13430;-40.48660;47.88920;,
 -11.44450;1.90850;38.12930;,
 -11.44450;11.56130;38.12930;,
 -11.44450;21.85290;47.88920;,
 -11.44450;-40.48660;47.88920;,
 -11.44450;1.90850;29.15530;,
 -11.44450;-40.48660;22.81690;,
 -11.44450;11.56130;29.15530;,
 -11.44450;21.85290;22.81690;,
 -33.49880;1.90850;38.12930;,
 -33.49880;11.56130;38.12930;,
 -11.44450;11.56130;38.12930;,
 -11.44450;1.90850;38.12930;,
 -33.49880;1.90850;29.15530;,
 -33.49880;1.90850;38.12930;,
 -11.44450;1.90850;38.12930;,
 -11.44450;1.90850;29.15530;,
 -33.49880;11.56130;29.15530;,
 -33.49880;1.90850;29.15530;,
 -11.44450;1.90850;29.15530;,
 -11.44450;11.56130;29.15530;,
 -33.49880;11.56130;38.12930;,
 -33.49880;11.56130;29.15530;,
 -11.44450;11.56130;29.15530;,
 -11.44450;11.56130;38.12930;,
 -33.42200;-28.88710;55.12550;,
 -33.42200;29.84320;55.12550;,
 -33.49880;11.56130;38.12930;,
 -33.49880;1.90850;38.12930;,
 -33.42200;-28.88710;12.15910;,
 -33.49880;1.90850;29.15530;,
 -33.42200;29.84320;12.15910;,
 -33.49880;11.56130;29.15530;,
 -75.99000;-28.88710;55.12550;,
 -75.99000;29.84320;55.12550;,
 -33.42200;29.84320;55.12550;,
 -33.42200;-28.88710;55.12550;,
 -75.99000;-28.88710;12.15910;,
 -75.99000;-28.88710;55.12550;,
 -33.42200;-28.88710;55.12550;,
 -33.42200;-28.88710;12.15910;,
 -75.99000;29.84320;12.15910;,
 -75.99000;-28.88710;12.15910;,
 -33.42200;-28.88710;12.15910;,
 -33.42200;29.84320;12.15910;,
 -75.99000;29.84320;55.12550;,
 -75.99000;29.84320;12.15910;,
 -33.42200;29.84320;12.15910;,
 -33.42200;29.84320;55.12550;,
 -75.99000;1.50490;38.26560;,
 -75.99000;10.92200;38.26560;,
 -75.99000;29.84320;55.12550;,
 -75.99000;-28.88710;55.12550;,
 -75.99000;1.50490;29.01900;,
 -75.99000;-28.88710;12.15910;,
 -75.99000;10.92200;29.01900;,
 -75.99000;29.84320;12.15910;,
 -102.66470;1.50490;38.26560;,
 -102.66470;10.92200;38.26560;,
 -75.99000;10.92200;38.26560;,
 -75.99000;1.50490;38.26560;,
 -102.66470;1.50490;29.01900;,
 -102.66470;1.50490;38.26560;,
 -75.99000;1.50490;38.26560;,
 -75.99000;1.50490;29.01900;,
 -102.66470;10.92200;29.01900;,
 -102.66470;1.50490;29.01900;,
 -75.99000;1.50490;29.01900;,
 -75.99000;10.92200;29.01900;,
 -102.66470;10.92200;38.26560;,
 -102.66470;10.92200;29.01900;,
 -75.99000;10.92200;29.01900;,
 -75.99000;10.92200;38.26560;,
 -112.34520;1.50490;38.26560;,
 -112.34520;10.92200;38.26560;,
 -112.34520;1.50490;29.01900;,
 -112.34520;1.50490;38.26560;,
 -112.34520;10.92200;29.01900;,
 -112.34520;1.50490;29.01900;,
 -112.34520;10.92200;38.26560;,
 -112.34520;1.50490;38.26560;,
 -112.34520;1.50490;29.01900;,
 -112.34520;10.92200;29.01900;,
 -112.34520;26.07660;29.01900;,
 -112.34520;26.07660;38.26560;,
 -102.66470;26.07660;29.01900;,
 -112.34520;26.07660;29.01900;,
 -102.66470;26.07660;38.26560;,
 -102.66470;26.07660;29.01900;,
 -102.66470;10.92200;29.01900;,
 -102.66470;10.92200;38.26560;,
 -112.34520;26.07660;38.26560;,
 -102.66470;26.07660;38.26560;,
 -121.57840;26.07660;20.19950;,
 -121.57840;26.07660;47.08510;,
 -112.34520;26.07660;38.26560;,
 -112.34520;26.07660;29.01900;,
 -93.43150;26.07660;20.19950;,
 -102.66470;26.07660;29.01900;,
 -93.43150;26.07660;47.08510;,
 -102.66470;26.07660;38.26560;,
 -121.57840;45.78250;20.19950;,
 -121.57840;45.78250;47.08510;,
 -121.57840;26.07660;47.08510;,
 -121.57840;26.07660;20.19950;,
 -93.43150;45.78250;20.19950;,
 -121.57840;45.78250;20.19950;,
 -121.57840;26.07660;20.19950;,
 -93.43150;26.07660;20.19950;,
 -93.43150;45.78250;47.08510;,
 -93.43150;45.78250;20.19950;,
 -93.43150;26.07660;20.19950;,
 -93.43150;26.07660;47.08510;,
 -121.57840;45.78250;47.08510;,
 -121.57840;45.78250;20.19950;,
 -93.43150;45.78250;20.19950;,
 -93.43150;45.78250;47.08510;,
 -103.94620;44.97230;46.91970;,
 -111.41510;44.97230;46.91970;,
 -121.57840;45.78250;47.08510;,
 -93.43150;45.78250;47.08510;,
 -103.94620;38.64270;46.91970;,
 -93.43150;26.07660;47.08510;,
 -111.41510;38.64270;46.91970;,
 -121.57840;26.07660;47.08510;,
 -103.94620;44.97230;68.14980;,
 -111.41510;44.97230;68.14980;,
 -111.41510;44.97230;46.91970;,
 -103.94620;44.97230;46.91970;,
 -103.94620;38.64270;68.14980;,
 -103.94620;44.97230;68.14980;,
 -103.94620;44.97230;46.91970;,
 -103.94620;38.64270;46.91970;,
 -111.41510;38.64270;68.14980;,
 -103.94620;38.64270;68.14980;,
 -103.94620;38.64270;46.91970;,
 -111.41510;38.64270;46.91970;,
 -111.41510;44.97230;68.14980;,
 -111.41510;38.64270;68.14980;,
 -111.41510;38.64270;46.91970;,
 -111.41510;44.97230;46.91970;,
 -85.85270;55.83750;68.14980;,
 -139.49730;55.83750;68.14980;,
 -111.41510;44.97230;68.14980;,
 -103.94620;44.97230;68.14980;,
 -85.85270;-1.54440;68.14980;,
 -103.94620;38.64270;68.14980;,
 -139.49730;-1.54440;68.14980;,
 -111.41510;38.64270;68.14980;,
 -85.85270;55.83750;157.77600;,
 -139.49730;55.83750;157.77600;,
 -139.49730;55.83750;68.14980;,
 -85.85270;55.83750;68.14980;,
 -85.85270;-1.54440;157.77600;,
 -85.85270;55.83750;157.77600;,
 -85.85270;55.83750;68.14980;,
 -85.85270;-1.54440;68.14980;,
 -139.49730;-1.54440;157.77600;,
 -85.85270;-1.54440;157.77600;,
 -85.85270;-1.54440;68.14980;,
 -139.49730;-1.54440;68.14980;,
 -139.49730;55.83750;157.77600;,
 -85.85270;55.83750;157.77600;,
 -85.85270;-1.54440;157.77600;,
 -139.49730;-1.54440;157.77600;,
 -139.49730;34.94200;157.76981;,
 -139.49730;36.56390;157.76981;,
 -139.49730;34.94200;144.56680;,
 -139.49730;34.94200;157.76981;,
 -139.49730;-1.54440;157.77600;,
 -139.49730;-1.54440;68.14980;,
 -139.49730;36.56390;144.56680;,
 -139.49730;55.83750;68.14980;,
 -139.49730;36.56390;157.76981;,
 -139.49730;55.83750;157.77600;,
 -129.89580;34.94200;157.76981;,
 -129.89580;36.56390;157.76981;,
 -129.89580;34.94200;144.56680;,
 -129.89580;34.94200;157.76981;,
 -139.49730;34.94200;157.76981;,
 -139.49730;34.94200;144.56680;,
 -129.89580;36.56390;144.56680;,
 -129.89580;34.94200;144.56680;,
 -139.49730;34.94200;144.56680;,
 -139.49730;36.56390;144.56680;,
 -129.89580;36.56390;157.76981;,
 -129.89580;36.56390;144.56680;,
 -139.49730;36.56390;144.56680;,
 -139.49730;36.56390;157.76981;,
 -129.89580;36.56390;157.76981;,
 -129.89580;34.94200;157.76981;,
 -129.89580;34.94200;144.56680;,
 -129.89580;36.56390;144.56680;,
 -109.52470;56.22210;126.90330;,
 -101.58900;56.22210;126.90330;,
 -101.58900;56.22210;118.64460;,
 -109.52470;56.22210;118.64460;,
 -109.52470;56.22210;118.64460;,
 -101.58900;56.22210;118.64460;,
 -101.58900;-1.83380;118.64460;,
 -109.52470;-1.83380;118.64460;,
 -109.52470;-1.83380;118.64460;,
 -101.58900;-1.83380;118.64460;,
 -101.58900;-1.83380;126.90330;,
 -109.52470;-1.83380;126.90330;,
 -109.52470;-1.83380;126.90330;,
 -101.58900;-1.83380;126.90330;,
 -101.58900;56.22210;126.90330;,
 -109.52470;56.22210;126.90330;,
 -101.58900;56.22210;126.90330;,
 -101.58900;-1.83380;126.90330;,
 -101.58900;-1.83380;118.64460;,
 -101.58900;56.22210;118.64460;,
 -109.52470;-1.83380;126.90330;,
 -109.52470;56.22210;126.90330;,
 -109.52470;56.22210;118.64460;,
 -109.52470;-1.83380;118.64460;,
 -123.91990;56.22210;106.84300;,
 -115.98420;56.22210;106.84300;,
 -115.98420;56.22210;98.58430;,
 -123.91990;56.22210;98.58430;,
 -123.91990;56.22210;98.58430;,
 -115.98420;56.22210;98.58430;,
 -115.98420;-1.83380;98.58430;,
 -123.91990;-1.83380;98.58430;,
 -123.91990;-1.83380;98.58430;,
 -115.98420;-1.83380;98.58430;,
 -115.98420;-1.83380;106.84300;,
 -123.91990;-1.83380;106.84300;,
 -123.91990;-1.83380;106.84300;,
 -115.98420;-1.83380;106.84300;,
 -115.98420;56.22210;106.84300;,
 -123.91990;56.22210;106.84300;,
 -115.98420;56.22210;106.84300;,
 -115.98420;-1.83380;106.84300;,
 -115.98420;-1.83380;98.58430;,
 -115.98420;56.22210;98.58430;,
 -123.91990;-1.83380;106.84300;,
 -123.91990;56.22210;106.84300;,
 -123.91990;56.22210;98.58430;,
 -123.91990;-1.83380;98.58430;;
 
 99;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,20,23,25;,
 4;26,24,25,27;,
 4;21,26,27,22;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,44,47,49;,
 4;50,48,49,51;,
 4;45,50,51,46;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,68,71,73;,
 4;74,72,73,75;,
 4;69,74,75,70;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,92,95,97;,
 4;98,96,97,99;,
 4;93,98,99,94;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;116,117,118,119;,
 4;120,116,119,121;,
 4;122,120,121,123;,
 4;117,122,123,118;,
 4;124,125,126,127;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;140,141,125,124;,
 4;142,143,129,128;,
 4;144,145,133,132;,
 4;146,147,148,149;,
 4;150,151,146,149;,
 4;152,153,144,132;,
 4;154,155,156,157;,
 4;158,159,125,141;,
 4;160,161,162,163;,
 4;164,160,163,165;,
 4;166,164,165,167;,
 4;161,166,167,162;,
 4;168,169,170,171;,
 4;172,173,174,175;,
 4;176,177,178,179;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;188,184,187,189;,
 4;190,188,189,191;,
 4;185,190,191,186;,
 4;192,193,194,195;,
 4;196,197,198,199;,
 4;200,201,202,203;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,208,211,213;,
 4;214,212,213,215;,
 4;209,214,215,210;,
 4;216,217,218,219;,
 4;220,221,222,223;,
 4;224,225,226,227;,
 4;228,229,230,231;,
 4;232,233,228,231;,
 4;234,235,236,237;,
 4;238,234,237,239;,
 4;240,238,239,241;,
 4;242,243,233,232;,
 4;244,245,246,247;,
 4;248,249,250,251;,
 4;252,253,254,255;,
 4;256,257,258,259;,
 4;260,261,262,263;,
 4;264,265,266,267;,
 4;268,269,270,271;,
 4;272,273,274,275;,
 4;276,277,278,279;,
 4;280,281,282,283;,
 4;240,238,234,235;,
 4;284,285,286,287;,
 4;288,289,290,291;,
 4;292,293,294,295;,
 4;296,297,298,299;,
 4;300,301,302,303;,
 4;304,305,306,307;;
 
 MeshMaterialList {
  7;
  99;
  0,
  1,
  0,
  2,
  2,
  1,
  1,
  1,
  1,
  2,
  0,
  2,
  0,
  1,
  1,
  1,
  1,
  0,
  2,
  0,
  1,
  2,
  2,
  2,
  2,
  1,
  0,
  1,
  0,
  2,
  2,
  2,
  2,
  1,
  0,
  1,
  0,
  2,
  2,
  2,
  2,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  2,
  2,
  1,
  2,
  1,
  0,
  0,
  0,
  0,
  2,
  1,
  2,
  0,
  1,
  1,
  1,
  1,
  0,
  2,
  0,
  2,
  1,
  1,
  1,
  1,
  0,
  2,
  0,
  1,
  1,
  2,
  2,
  2,
  1,
  0,
  1,
  0,
  2,
  0,
  1,
  0,
  1,
  2,
  2,
  2,
  0,
  1,
  0,
  1,
  2,
  2;;
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
   0.450000;0.450000;0.450000;1.000000;;
   8.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  18;
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.003601;0.002404;0.999991;,
  0.002318;0.002404;0.999994;,
  -0.003601;-0.000561;0.999993;,
  0.002318;-0.000561;0.999997;,
  -0.999995;0.002100;-0.002259;,
  -0.999997;-0.001247;-0.002259;,
  -0.999995;0.002100;0.002259;,
  -0.999997;-0.001247;0.002259;,
  0.007865;-0.006581;-0.999947;,
  -0.008136;-0.006581;-0.999945;,
  0.007904;0.100522;-0.994903;,
  -0.008178;0.100522;-0.994901;;
  99;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;6,8,8,6;,
  4;7,6,6,7;,
  4;9,7,7,9;,
  4;8,9,9,8;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;13,12,12,13;,
  4;11,13,13,11;,
  4;10,11,11,10;,
  4;12,10,10,12;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;5,5,5,5;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;16,17,17,16;,
  4;14,16,16,14;,
  4;15,14,14,15;,
  4;17,15,15,17;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;5,5,5,5;;
 }
 MeshTextureCoords {
  308;
  -1.659831;-1.166164;
  -1.659831;2.166164;
  1.672497;2.166164;
  1.672497;-1.166164;
  -0.657569;-2.013043;
  -0.657569;1.319285;
  2.674759;1.319285;
  2.674759;-2.013043;
  -1.659831;2.166164;
  -1.659831;-1.166164;
  1.672497;-1.166164;
  1.672497;2.166164;
  2.166164;-2.027367;
  -1.166164;-2.027367;
  -1.166164;1.304961;
  2.166164;1.304961;
  2.166164;1.304961;
  -1.166164;1.304961;
  -1.166164;-2.027367;
  2.166164;-2.027367;
  0.287787;-0.465440;
  0.287787;0.976176;
  -0.657569;1.319285;
  -0.657569;-2.013043;
  1.729403;-0.465440;
  2.674759;-2.013043;
  1.729403;0.976176;
  2.674759;1.319285;
  3.947663;-0.479765;
  3.947663;0.961852;
  2.166164;0.961852;
  2.166164;-0.479765;
  0.727141;-2.947663;
  -0.714475;-2.947663;
  -0.714475;-1.166164;
  0.727141;-1.166164;
  3.947663;0.961852;
  3.947663;-0.479765;
  2.166164;-0.479765;
  2.166164;0.961852;
  -0.714475;-2.947663;
  0.727141;-2.947663;
  0.727141;-1.166164;
  -0.714475;-1.166164;
  -0.717054;-1.971034;
  -0.717054;7.428770;
  0.287787;0.976176;
  0.287787;-0.465440;
  3.290606;-1.971034;
  1.729403;-0.465440;
  3.290606;7.428770;
  1.729403;0.976176;
  2.288344;-6.720928;
  -1.719315;-6.720928;
  -1.719315;-2.940425;
  2.288344;-2.940425;
  7.720928;7.414445;
  7.720928;-1.985359;
  3.940425;-1.985359;
  3.940425;7.414445;
  -1.719315;-6.720928;
  2.288344;-6.720928;
  2.288344;-2.940425;
  -1.719315;-2.940425;
  -0.717054;7.428770;
  -0.717054;-1.971034;
  3.290606;-1.971034;
  3.290606;7.428770;
  6.249291;1.021939;
  6.249291;-0.433550;
  7.720929;-1.985359;
  7.720929;7.414445;
  4.896155;1.021939;
  3.940425;7.414445;
  4.896155;-0.433550;
  3.940425;-1.985359;
  -4.042490;1.036264;
  -4.042490;-0.419225;
  -0.717054;-0.419225;
  -0.717054;1.036264;
  -5.044752;-3.896154;
  -5.044752;-5.249290;
  -1.719315;-5.249290;
  -1.719315;-3.896154;
  -4.042490;-0.419225;
  -4.042490;1.036264;
  -0.717054;1.036264;
  -0.717054;-0.419225;
  -5.044752;-5.249290;
  -5.044752;-3.896154;
  -1.719315;-3.896154;
  -1.719315;-5.249290;
  8.812048;5.665425;
  8.812048;-3.190169;
  6.249291;-0.433550;
  6.249291;1.021939;
  2.333399;5.665425;
  4.896155;1.021939;
  2.333399;-3.190169;
  4.896155;-0.433550;
  -10.449487;5.679749;
  -10.449487;-3.175844;
  -4.030911;-3.175844;
  -4.030911;5.679749;
  -11.451747;-1.333398;
  -11.451747;-7.812046;
  -5.033172;-7.812046;
  -5.033172;-1.333398;
  -10.449487;-3.175844;
  -10.449487;5.679749;
  -4.030911;5.679749;
  -4.030911;-3.175844;
  -11.451748;-7.812047;
  -11.451748;-1.333399;
  -5.033172;-1.333399;
  -5.033172;-7.812047;
  6.269844;1.082796;
  6.269844;-0.337153;
  8.812048;-3.190169;
  8.812048;5.665425;
  4.875604;1.082796;
  2.333399;5.665425;
  4.875604;-0.337153;
  2.333399;-3.190169;
  -14.471607;1.097120;
  -14.471607;-0.322829;
  -10.449487;-0.322829;
  -10.449487;1.097120;
  -15.473867;-3.875603;
  -15.473867;-5.269842;
  -11.451748;-5.269842;
  -11.451748;-3.875603;
  -14.471607;-0.322829;
  -14.471607;1.097120;
  -10.449487;1.097120;
  -10.449487;-0.322829;
  -15.473867;-5.269842;
  -15.473867;-3.875603;
  -11.451748;-3.875603;
  -11.451748;-5.269842;
  -15.931273;1.097120;
  -15.931273;-0.322829;
  -16.933533;-3.875603;
  -16.933533;-5.269842;
  -15.931273;-0.322829;
  -15.931273;1.097120;
  6.269844;-0.337153;
  6.269844;1.082796;
  4.875604;1.082796;
  4.875604;-0.337153;
  4.875604;-2.622226;
  6.269844;-2.622226;
  -14.471607;-2.607901;
  -15.931273;-2.607901;
  6.269844;-2.622226;
  4.875604;-2.622226;
  4.875604;-0.337153;
  6.269844;-0.337153;
  -15.931273;-2.607901;
  -14.471607;-2.607901;
  -18.325752;-2.545763;
  -18.325752;-6.599682;
  -16.933533;-5.269843;
  -16.933533;-3.875603;
  -14.081649;-2.545763;
  -15.473867;-3.875603;
  -14.081649;-6.599682;
  -15.473867;-5.269843;
  3.545763;-5.593562;
  7.599684;-5.593562;
  7.599684;-2.622226;
  3.545763;-2.622226;
  -13.079388;-5.579237;
  -17.323492;-5.579237;
  -17.323492;-2.607901;
  -13.079388;-2.607901;
  7.599684;-5.593562;
  3.545763;-5.593562;
  3.545763;-2.622226;
  7.599684;-2.622226;
  -18.325752;-6.599683;
  -18.325752;-2.545763;
  -14.081649;-2.545763;
  -14.081649;-6.599683;
  -14.664837;-5.457072;
  -15.791029;-5.457072;
  -17.323492;-5.579237;
  -13.079388;-5.579237;
  -14.664837;-4.502669;
  -13.079388;-2.607901;
  -15.791029;-4.502669;
  -17.323492;-2.607901;
  -15.667097;-9.775905;
  -16.793289;-9.775905;
  -16.793289;-6.574743;
  -15.667097;-6.574743;
  10.775906;-4.516994;
  10.775906;-5.471396;
  7.574744;-5.471396;
  7.574744;-4.516994;
  -16.793289;-9.775905;
  -15.667097;-9.775905;
  -15.667097;-6.574743;
  -16.793289;-6.574743;
  10.775906;-5.471396;
  10.775906;-4.516994;
  7.574744;-4.516994;
  7.574744;-5.471396;
  -11.936625;-7.095371;
  -20.025377;-7.095371;
  -15.791029;-5.457072;
  -14.664837;-5.457072;
  -11.936625;1.556906;
  -14.664837;-4.502669;
  -20.025377;1.556906;
  -15.791029;-4.502669;
  -12.938886;-23.290106;
  -21.027636;-23.290106;
  -21.027636;-9.775905;
  -12.938886;-9.775905;
  24.290110;1.542581;
  24.290110;-7.109695;
  10.775906;-7.109695;
  10.775906;1.542581;
  -21.027636;-23.290106;
  -12.938886;-23.290106;
  -12.938886;-9.775904;
  -21.027636;-9.775904;
  -20.025377;-7.095371;
  -11.936625;-7.095371;
  -11.936625;1.556906;
  -20.025377;1.556906;
  -20.025377;-3.944663;
  -20.025377;-4.189219;
  22.298372;-3.958987;
  24.289175;-3.958987;
  24.290110;1.542581;
  10.775906;1.542581;
  22.298372;-4.203543;
  10.775906;-7.109695;
  24.289175;-4.203543;
  24.290110;-7.109695;
  -18.577623;-3.944663;
  -18.577623;-4.189219;
  -19.579884;-21.298370;
  -19.579884;-23.289171;
  -21.027636;-23.289171;
  -21.027636;-21.298370;
  -18.577623;-4.189219;
  -18.577623;-3.944663;
  -20.025377;-3.944663;
  -20.025377;-4.189219;
  -19.579884;-23.289171;
  -19.579884;-21.298370;
  -21.027636;-21.298370;
  -21.027636;-23.289171;
  24.289175;-4.203543;
  24.289175;-3.958987;
  22.298372;-3.958987;
  22.298372;-4.203543;
  -16.508245;-18.634995;
  -15.311668;-18.634995;
  -15.311668;-17.389715;
  -16.508245;-17.389715;
  -15.505985;-7.153362;
  -14.309408;-7.153362;
  -14.309408;1.600543;
  -15.505985;1.600543;
  -16.508245;-17.389715;
  -15.311668;-17.389715;
  -15.311668;-18.634995;
  -16.508245;-18.634995;
  -15.505985;1.600543;
  -14.309408;1.600543;
  -14.309408;-7.153362;
  -15.505985;-7.153362;
  19.634996;-7.167687;
  19.634996;1.586218;
  18.389717;1.586218;
  18.389717;-7.167687;
  19.634996;1.586218;
  19.634996;-7.167687;
  18.389717;-7.167687;
  18.389717;1.586218;
  -18.678812;-15.610222;
  -17.482235;-15.610222;
  -17.482235;-14.364941;
  -18.678812;-14.364941;
  -17.676552;-7.153362;
  -16.479975;-7.153362;
  -16.479975;1.600543;
  -17.676552;1.600543;
  -18.678812;-14.364941;
  -17.482235;-14.364941;
  -17.482235;-15.610222;
  -18.678812;-15.610222;
  -17.676552;1.600543;
  -16.479975;1.600543;
  -16.479975;-7.153362;
  -17.676552;-7.153362;
  16.610224;-7.167687;
  16.610224;1.586218;
  15.364943;1.586218;
  15.364943;-7.167687;
  16.610224;1.586218;
  16.610224;-7.167687;
  15.364943;-7.167687;
  15.364943;1.586218;;
 }
}