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
 240;
 15.55000;15.55000;-15.55000;,
 15.55000;15.55000;24.34181;,
 -15.55000;15.55000;24.34181;,
 -15.55000;15.55000;-15.55000;,
 15.55000;-23.22170;24.34181;,
 15.55000;-23.22170;-15.55000;,
 -15.55000;-23.22170;-15.55000;,
 -15.55000;-23.22170;24.34181;,
 15.55000;-23.22170;-15.55000;,
 15.55000;15.55000;-15.55000;,
 -15.55000;15.55000;-15.55000;,
 -15.55000;-23.22170;-15.55000;,
 -15.55000;15.55000;-15.55000;,
 -15.55000;15.55000;24.34181;,
 -15.55000;-23.22170;24.34181;,
 -15.55000;-23.22170;-15.55000;,
 15.55000;-23.22170;-15.55000;,
 15.55000;-23.22170;24.34181;,
 15.55000;15.55000;24.34181;,
 15.55000;15.55000;-15.55000;,
 6.69370;-2.11920;24.26501;,
 6.69370;11.26820;24.26501;,
 15.55000;15.55000;24.34181;,
 15.55000;-23.22170;24.34181;,
 -6.69370;-2.11920;24.26501;,
 -15.55000;-23.22170;24.34181;,
 -6.69370;11.26820;24.26501;,
 -15.55000;15.55000;24.34181;,
 6.69370;-2.11920;49.00850;,
 6.69370;11.26820;49.00850;,
 6.69370;11.26820;24.26501;,
 6.69370;-2.11920;24.26501;,
 -6.69370;-2.11920;49.00850;,
 6.69370;-2.11920;49.00850;,
 6.69370;-2.11920;24.26501;,
 -6.69370;-2.11920;24.26501;,
 -6.69370;11.26820;49.00850;,
 -6.69370;-2.11920;49.00850;,
 -6.69370;-2.11920;24.26501;,
 -6.69370;11.26820;24.26501;,
 6.69370;11.26820;49.00850;,
 -6.69370;11.26820;49.00850;,
 -6.69370;11.26820;24.26501;,
 6.69370;11.26820;24.26501;,
 17.01050;-24.21590;48.99780;,
 17.01050;20.81650;48.99780;,
 6.69370;11.26820;49.00850;,
 6.69370;-2.11920;49.00850;,
 -17.20220;-24.21590;48.99780;,
 -6.69370;-2.11920;49.00850;,
 -17.20220;20.81650;48.99780;,
 -6.69370;11.26820;49.00850;,
 17.01050;-24.21590;132.26140;,
 17.01050;20.81650;132.26140;,
 17.01050;20.81650;48.99780;,
 17.01050;-24.21590;48.99780;,
 -17.20220;20.81650;132.26140;,
 -17.20220;-24.21590;132.26140;,
 -17.20220;-24.21590;48.99780;,
 -17.20220;20.81650;48.99780;,
 17.01050;20.81650;132.26140;,
 -17.20220;20.81650;132.26140;,
 -17.20220;20.81650;48.99780;,
 17.01050;20.81650;48.99780;,
 17.01050;20.81650;132.26140;,
 17.01050;-24.21590;132.26140;,
 -17.20220;-24.21590;132.26140;,
 -17.20220;20.81650;132.26140;,
 1.94780;-24.21590;118.73420;,
 -2.13960;-24.21590;118.73420;,
 -17.20220;-24.21590;132.26140;,
 17.01050;-24.21590;132.26140;,
 1.94780;-24.21590;114.95000;,
 17.01050;-24.21590;48.99780;,
 -2.13960;-24.21590;114.95000;,
 -17.20220;-24.21590;48.99780;,
 -63.80920;-42.75670;128.97960;,
 -63.80920;-42.75670;104.58290;,
 -26.86580;-42.75670;104.58290;,
 -26.86580;-42.75670;128.97960;,
 -26.86580;-42.75670;128.97960;,
 -26.86580;-42.75670;104.58290;,
 -26.86580;-79.98390;104.58290;,
 -26.86580;-79.98390;128.97960;,
 -63.80920;-79.98390;128.97960;,
 -63.80920;-79.98390;104.58290;,
 -63.80920;-42.75670;104.58290;,
 -63.80920;-42.75670;128.97960;,
 -33.46770;-79.98390;118.77940;,
 -33.46770;-79.98390;115.22690;,
 -63.80920;-79.98390;104.58290;,
 -63.80920;-79.98390;128.97960;,
 -29.91530;-79.98390;118.77940;,
 -26.86580;-79.98390;128.97960;,
 -29.91530;-79.98390;115.22690;,
 -26.86580;-79.98390;104.58290;,
 -63.80920;-42.75680;129.10139;,
 -63.80920;-55.71330;129.10139;,
 -26.86580;-42.75680;129.10139;,
 -26.86580;-55.71330;129.10139;,
 -63.80920;-55.71330;129.10139;,
 -26.86580;-55.71330;129.10139;,
 -26.86580;-79.98390;128.97960;,
 -63.80920;-79.98390;128.97960;,
 -63.80920;-42.75680;139.13200;,
 -63.80920;-55.71330;139.13200;,
 -26.86580;-42.75680;139.13200;,
 -63.80920;-42.75680;139.13200;,
 -63.80920;-42.75680;129.10139;,
 -26.86580;-42.75680;129.10139;,
 -26.86580;-55.71330;139.13200;,
 -26.86580;-42.75680;139.13200;,
 -63.80920;-55.71330;139.13200;,
 -26.86580;-55.71330;139.13200;,
 -26.86580;-55.71330;129.10139;,
 -63.80920;-55.71330;129.10139;,
 -63.80920;-55.71330;139.13200;,
 -63.80920;-42.75680;139.13200;,
 -26.86580;-42.75680;139.13200;,
 -26.86580;-55.71330;139.13200;,
 -55.55680;-58.74508;104.58290;,
 -55.55680;-47.88608;104.58290;,
 -63.80920;-42.75670;104.58290;,
 -63.80920;-79.98390;104.58290;,
 -39.77430;-47.88608;104.58290;,
 -39.77430;-58.74508;104.58290;,
 -26.86580;-79.98390;104.58290;,
 -26.86580;-42.75670;104.58290;,
 -55.55680;-58.74508;80.89980;,
 -55.55680;-47.88608;80.89980;,
 -55.55680;-47.88608;104.58290;,
 -55.55680;-58.74508;104.58290;,
 -39.77430;-58.74508;80.89980;,
 -55.55680;-58.74508;80.89980;,
 -55.55680;-58.74508;104.58290;,
 -39.77430;-58.74508;104.58290;,
 -39.77430;-47.88608;80.89980;,
 -39.77430;-58.74508;80.89980;,
 -39.77430;-58.74508;104.58290;,
 -39.77430;-47.88608;104.58290;,
 -55.55680;-47.88608;80.89980;,
 -39.77430;-47.88608;80.89980;,
 -39.77430;-47.88608;104.58290;,
 -55.55680;-47.88608;104.58290;,
 -60.28380;-80.06660;80.89980;,
 -60.28380;-40.15348;80.89980;,
 -55.55680;-47.88608;80.89980;,
 -55.55680;-58.74508;80.89980;,
 -35.22810;-40.15348;80.89980;,
 -35.22810;-80.06660;80.89980;,
 -39.77430;-58.74508;80.89980;,
 -39.77430;-47.88608;80.89980;,
 -60.28380;-80.06660;41.46845;,
 -60.28380;-40.15348;41.46845;,
 -60.28380;-40.15348;80.89980;,
 -60.28380;-80.06660;80.89980;,
 -35.22810;-80.06660;41.46845;,
 -60.28380;-80.06660;41.46845;,
 -60.28380;-80.06660;80.89980;,
 -35.22810;-80.06660;80.89980;,
 -35.22810;-40.15348;41.46845;,
 -35.22810;-80.06660;41.46845;,
 -35.22810;-80.06660;80.89980;,
 -35.22810;-40.15348;80.89980;,
 -60.28380;-40.15348;41.46845;,
 -35.22810;-40.15348;41.46845;,
 -35.22810;-40.15348;80.89980;,
 -60.28380;-40.15348;80.89980;,
 -60.28380;-56.23148;41.31615;,
 -60.28380;-40.11768;41.31615;,
 -35.22810;-56.23148;41.31615;,
 -60.28380;-56.23148;41.31615;,
 -60.28380;-80.06660;41.46845;,
 -35.22810;-80.06660;41.46845;,
 -35.22810;-40.11768;41.31615;,
 -35.22810;-56.23148;41.31615;,
 -60.28380;-40.11768;41.31615;,
 -35.22810;-40.11768;41.31615;,
 -60.28380;-56.23148;22.26706;,
 -60.28380;-40.11768;22.26706;,
 -35.22810;-56.23148;22.26706;,
 -60.28380;-56.23148;22.26706;,
 -60.28380;-56.23148;41.31615;,
 -35.22810;-56.23148;41.31615;,
 -35.22810;-40.11768;22.26706;,
 -35.22810;-56.23148;22.26706;,
 -60.28380;-40.11768;22.26706;,
 -35.22810;-40.11768;22.26706;,
 -50.89750;-79.25810;80.89980;,
 -44.57310;-79.25810;80.89980;,
 -50.89740;-75.63000;80.89980;,
 -44.57320;-75.63000;80.89980;,
 -50.89750;-79.25810;104.56640;,
 -44.57310;-79.25810;104.56640;,
 -44.57310;-79.25810;80.89980;,
 -50.89750;-79.25810;80.89980;,
 -50.89740;-75.63000;104.56640;,
 -50.89750;-79.25810;104.56640;,
 -50.89750;-79.25810;80.89980;,
 -50.89740;-75.63000;80.89980;,
 -44.57320;-75.63000;104.56640;,
 -50.89740;-75.63000;104.56640;,
 -50.89740;-75.63000;80.89980;,
 -44.57320;-75.63000;80.89980;,
 -44.57310;-79.25810;104.56640;,
 -44.57320;-75.63000;104.56640;,
 -44.57320;-75.63000;80.89980;,
 -44.57310;-79.25810;80.89980;,
 -50.89740;-75.63000;104.56640;,
 -44.57320;-75.63000;104.56640;,
 -50.89750;-79.25810;104.56640;,
 -44.57310;-79.25810;104.56640;,
 -60.28380;-40.11768;22.26706;,
 -60.28380;-56.23148;22.26706;,
 -84.11340;-56.22428;22.11346;,
 -84.11340;-24.51788;22.11346;,
 -32.98620;-56.22428;22.11346;,
 -84.11340;-56.22428;22.11346;,
 -35.22810;-56.23148;22.26706;,
 -35.22810;-40.11768;22.26706;,
 -32.98620;-24.51788;22.11346;,
 -32.98620;-56.22428;22.11346;,
 -84.11340;-56.22428;-29.72445;,
 -84.11340;-24.51788;-29.72445;,
 -84.11340;-24.51788;22.11346;,
 -84.11340;-56.22428;22.11346;,
 -32.98620;-56.22428;-29.72445;,
 -84.11340;-56.22428;-29.72445;,
 -32.98620;-24.51788;-29.72445;,
 -32.98620;-56.22428;-29.72445;,
 -32.98620;-56.22428;22.11346;,
 -32.98620;-24.51788;22.11346;,
 -84.11340;-24.51788;-29.72445;,
 -32.98620;-24.51788;-29.72445;,
 -32.98620;-24.51788;22.11346;,
 -84.11340;-24.51788;22.11346;,
 -84.11340;-24.51788;-29.72445;,
 -84.11340;-56.22428;-29.72445;,
 -32.98620;-56.22428;-29.72445;,
 -32.98620;-24.51788;-29.72445;;
 
 84;
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
 4;92,88,91,93;,
 4;94,92,93,95;,
 4;89,94,95,90;,
 4;96,97,84,87;,
 4;98,96,87,80;,
 4;99,98,80,83;,
 4;100,101,102,103;,
 4;104,105,97,96;,
 4;106,107,108,109;,
 4;110,111,98,99;,
 4;112,113,114,115;,
 4;116,117,118,119;,
 4;120,121,122,123;,
 4;124,125,126,127;,
 4;121,124,127,122;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;140,141,142,143;,
 4;144,145,146,147;,
 4;148,149,150,151;,
 4;145,148,151,146;,
 4;152,153,154,155;,
 4;156,157,158,159;,
 4;160,161,162,163;,
 4;164,165,166,167;,
 4;168,169,153,152;,
 4;170,171,172,173;,
 4;174,175,161,160;,
 4;176,177,165,164;,
 4;178,179,169,168;,
 4;180,181,182,183;,
 4;184,185,175,174;,
 4;186,187,177,176;,
 4;188,189,149,144;,
 4;190,188,144,147;,
 4;191,190,147,150;,
 4;189,191,150,149;,
 4;192,193,194,195;,
 4;196,197,198,199;,
 4;200,201,202,203;,
 4;204,205,206,207;,
 4;125,120,208,209;,
 4;120,123,210,208;,
 4;123,126,211,210;,
 4;126,125,209,211;,
 4;212,213,214,215;,
 4;181,180,216,217;,
 4;218,219,220,221;,
 4;219,212,215,220;,
 4;222,223,224,225;,
 4;226,227,217,216;,
 4;228,229,230,231;,
 4;232,233,234,235;,
 4;236,237,238,239;;
 
 MeshMaterialList {
  7;
  84;
  0,
  0,
  1,
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
  2,
  2,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  1,
  2,
  0,
  2,
  0,
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
  2,
  0,
  2,
  0,
  2,
  1,
  2,
  0,
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
  2,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  2,
  0,
  2,
  0,
  1;;
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
 }
 MeshNormals {
  33;
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.004336;0.008967;-0.999950;,
  -0.004336;0.008967;-0.999950;,
  0.004336;-0.001820;-0.999989;,
  -0.004336;-0.001820;-0.999989;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000518;0.000560;1.000000;,
  -0.000509;0.000560;1.000000;,
  0.000518;-0.000242;1.000000;,
  -0.000509;-0.000242;1.000000;,
  0.000000;-1.000000;-0.000423;,
  0.000000;0.000000;1.000000;,
  0.000458;-0.000421;1.000000;,
  -0.000338;-0.000437;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.006390;0.999980;,
  0.000000;0.999726;0.023425;,
  1.000000;-0.000027;-0.000000;,
  0.003223;-0.004923;-0.999983;,
  0.006446;0.000000;-0.999979;,
  -0.034198;-0.004926;-0.999403;,
  0.000000;0.005018;-0.999987;,
  0.000458;0.007482;0.999972;,
  -0.000338;0.007466;0.999972;,
  0.000000;-0.993343;-0.115195;,
  -1.000000;-0.000027;0.000000;,
  0.000687;-0.000632;1.000000;,
  -0.000507;-0.000655;1.000000;,
  0.000687;0.011223;0.999937;,
  -0.000507;0.011200;0.999937;,
  -0.068354;0.000000;-0.997661;;
  84;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;13,13,13,13;,
  4;7,7,7,7;,
  4;6,6,6,6;,
  4;4,2,2,4;,
  4;5,4,4,5;,
  4;3,5,5,3;,
  4;2,3,3,2;,
  4;6,6,6,6;,
  4;1,1,1,1;,
  4;7,7,7,7;,
  4;0,0,0,0;,
  4;10,8,8,10;,
  4;11,10,10,11;,
  4;9,11,11,9;,
  4;8,9,9,8;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;0,0,0,0;,
  4;16,16,16,16;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;12,0,0,12;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;7,7,7,7;,
  4;12,12,12,12;,
  4;6,6,6,6;,
  4;23,23,23,23;,
  4;7,7,7,7;,
  4;0,0,12,12;,
  4;6,6,6,6;,
  4;1,1,1,1;,
  4;16,16,16,16;,
  4;14,13,13,24;,
  4;13,15,25,13;,
  4;13,13,13,13;,
  4;7,7,7,7;,
  4;1,1,1,1;,
  4;6,6,6,6;,
  4;0,0,0,0;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;7,7,7,7;,
  4;1,1,1,1;,
  4;6,6,6,6;,
  4;26,26,0,0;,
  4;7,7,7,7;,
  4;17,17,17,17;,
  4;6,6,6,6;,
  4;26,26,26,26;,
  4;7,7,7,7;,
  4;18,18,1,1;,
  4;6,6,6,6;,
  4;0,0,26,26;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;1,1,1,1;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;27,27,27,27;,
  4;15,14,28,29;,
  4;14,24,30,28;,
  4;24,25,31,30;,
  4;25,15,29,31;,
  4;20,21,21,20;,
  4;18,18,18,18;,
  4;32,22,22,32;,
  4;22,20,20,22;,
  4;7,7,7,7;,
  4;1,1,18,18;,
  4;6,6,6,6;,
  4;0,0,0,0;,
  4;13,13,13,13;;
 }
 MeshTextureCoords {
  240;
  2.351025;2.844692;
  2.351025;-3.170357;
  -2.338359;-3.170357;
  -2.338359;2.844692;
  2.351025;-3.170357;
  2.351025;2.844692;
  -2.338359;2.844692;
  -2.338359;-3.170357;
  3.353287;4.825498;
  3.353287;-1.020657;
  -1.336098;-1.020657;
  -1.336098;4.825498;
  -1.844692;-1.034982;
  4.170358;-1.034982;
  4.170358;4.811173;
  -1.844692;4.811173;
  -1.844692;4.811173;
  4.170357;4.811173;
  4.170357;-1.034982;
  -1.844692;-1.034982;
  2.017898;1.643577;
  2.017898;-0.375030;
  3.353287;-1.020657;
  3.353287;4.825498;
  -0.000709;1.643577;
  -1.336098;4.825498;
  -0.000709;-0.375030;
  -1.336098;-1.020657;
  7.889701;1.629252;
  7.889701;-0.389355;
  4.158777;-0.389355;
  4.158777;1.629252;
  -1.002970;-6.889700;
  1.015636;-6.889700;
  1.015636;-3.158777;
  -1.002970;-3.158777;
  7.889701;-0.389355;
  7.889701;1.629252;
  4.158777;1.629252;
  4.158777;-0.389355;
  1.015636;-6.889700;
  -1.002970;-6.889700;
  -1.002970;-3.158777;
  1.015636;-3.158777;
  3.573507;4.975407;
  3.573507;-1.814762;
  2.017898;-0.375030;
  2.017898;1.643577;
  -1.585223;4.975407;
  -0.000709;1.643577;
  -1.585223;-1.814762;
  -0.000709;-0.375030;
  20.442913;4.961082;
  20.442913;-1.829086;
  7.888088;-1.829086;
  7.888088;4.961082;
  20.442913;-1.829086;
  20.442913;4.961082;
  7.888089;4.961082;
  7.888089;-1.829086;
  2.571245;-19.442911;
  -2.587485;-19.442911;
  -2.587485;-6.888088;
  2.571245;-6.888088;
  3.573507;-1.814762;
  3.573507;4.975407;
  -1.585223;4.975407;
  -1.585223;-1.814762;
  0.300030;-17.403225;
  -0.316285;-17.403225;
  -2.587485;-19.442911;
  2.571245;-19.442911;
  0.300030;-16.832626;
  2.571245;-6.888087;
  -0.316285;-16.832626;
  -2.587485;-6.888087;
  -9.615077;-18.948067;
  -9.615077;-15.269434;
  -4.044601;-15.269434;
  -4.044601;-18.948067;
  19.948071;7.756740;
  16.269436;7.756740;
  16.269436;13.370009;
  19.948071;13.370009;
  19.948071;13.370009;
  16.269436;13.370009;
  16.269436;7.756740;
  19.948071;7.756740;
  -5.040063;-17.410040;
  -5.040063;-16.874378;
  -9.615077;-15.269434;
  -9.615077;-18.948067;
  -4.504417;-17.410040;
  -4.044601;-18.948067;
  -4.504417;-16.874378;
  -4.044601;-15.269434;
  19.966434;7.756755;
  19.966434;9.710389;
  19.966434;7.756755;
  19.966434;9.710389;
  -8.612817;9.724713;
  -3.042340;9.724713;
  -3.042340;13.384334;
  -8.612817;13.384334;
  21.478891;7.756755;
  21.478891;9.710389;
  -4.044601;-20.478888;
  -9.615077;-20.478888;
  -9.615077;-18.966433;
  -4.044601;-18.966433;
  21.478891;9.710389;
  21.478891;7.756755;
  -9.615077;-20.478888;
  -4.044601;-20.478888;
  -4.044601;-18.966433;
  -9.615077;-18.966433;
  -8.612817;9.724713;
  -8.612817;7.771080;
  -3.042340;7.771080;
  -3.042340;9.724713;
  -7.368486;10.181858;
  -7.368486;8.544494;
  -8.612817;7.771064;
  -8.612817;13.384334;
  -4.988736;8.544494;
  -4.988736;10.181858;
  -3.042340;13.384334;
  -3.042340;7.771064;
  12.698402;10.167534;
  12.698402;8.530169;
  16.269436;8.530169;
  16.269436;10.167534;
  -5.990997;-11.698400;
  -8.370747;-11.698400;
  -8.370747;-15.269434;
  -5.990997;-15.269434;
  12.698402;8.530169;
  12.698402;10.167534;
  16.269436;10.167534;
  16.269436;8.530169;
  -8.370747;-11.698400;
  -5.990997;-11.698400;
  -5.990997;-15.269434;
  -8.370747;-15.269434;
  -8.081242;13.396803;
  -8.081242;7.378541;
  -7.368486;8.544494;
  -7.368486;10.181858;
  -4.303242;7.378541;
  -4.303242;13.396803;
  -4.988736;10.181858;
  -4.988736;8.544494;
  6.752783;13.382478;
  6.752783;7.364216;
  12.698402;7.364216;
  12.698402;13.382478;
  -5.305503;-5.752781;
  -9.083503;-5.752781;
  -9.083503;-11.698400;
  -5.305503;-11.698400;
  6.752782;7.364216;
  6.752782;13.382478;
  12.698402;13.382478;
  12.698402;7.364216;
  -9.083503;-5.752781;
  -5.305503;-5.752781;
  -5.305503;-11.698400;
  -9.083503;-11.698400;
  6.729818;9.788522;
  6.729818;7.358818;
  -4.303242;9.802847;
  -8.081242;9.802847;
  -8.081242;13.396803;
  -4.303242;13.396803;
  6.729818;7.358818;
  6.729818;9.788522;
  -9.083503;-5.729817;
  -5.305503;-5.729817;
  3.857519;9.788522;
  3.857519;7.358818;
  -5.305503;-2.857518;
  -9.083503;-2.857518;
  -9.083503;-5.729817;
  -5.305503;-5.729817;
  3.857519;7.358818;
  3.857519;9.788522;
  -9.083503;-2.857518;
  -5.305503;-2.857518;
  -6.665937;13.274895;
  -5.712319;13.274895;
  -6.665923;12.727834;
  -5.712334;12.727834;
  -7.668199;-15.266946;
  -6.714580;-15.266946;
  -6.714580;-11.698400;
  -7.668199;-11.698400;
  16.266949;12.713510;
  16.266949;13.260571;
  12.698402;13.260571;
  12.698402;12.713510;
  -6.714595;-15.266946;
  -7.668183;-15.266946;
  -7.668183;-11.698400;
  -6.714595;-11.698400;
  16.266949;13.260571;
  16.266949;12.713510;
  12.698402;12.713510;
  12.698402;13.260571;
  -6.665923;12.727834;
  -5.712334;12.727834;
  -6.665937;13.274895;
  -5.712319;13.274895;
  -8.081242;7.373142;
  -8.081242;9.802847;
  -11.674367;9.801761;
  -11.674367;5.020941;
  -4.967460;-2.834357;
  -12.676627;-2.834357;
  -4.303242;9.802847;
  -4.303242;7.373142;
  -3.965199;5.020941;
  -3.965199;9.801761;
  -3.981972;9.787436;
  -3.981972;5.006617;
  3.834358;5.006617;
  3.834358;9.787436;
  -4.967460;4.981973;
  -12.676627;4.981973;
  -3.981973;5.006617;
  -3.981973;9.787436;
  3.834358;9.787436;
  3.834358;5.006617;
  -12.676627;4.981973;
  -4.967460;4.981973;
  -4.967460;-2.834357;
  -12.676627;-2.834357;
  -11.674367;5.020941;
  -11.674367;9.801761;
  -3.965199;9.801761;
  -3.965199;5.020941;;
 }
}