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
 32;
 99.64590;130.64371;270.17761;,
 207.32520;116.21610;307.76331;,
 224.02060;34.55790;228.58681;,
 116.34130;48.98570;191.00130;,
 185.27090;8.09360;238.46600;,
 292.95001;48.35320;238.46600;,
 276.25461;93.00710;133.85730;,
 168.57550;52.74740;133.85730;,
 274.01379;29.53970;199.65739;,
 350.93661;-9.90810;123.87880;,
 386.36469;97.61040;103.87090;,
 309.44171;137.05820;179.64951;,
 436.98230;-9.66560;124.41000;,
 492.14410;56.89560;48.63150;,
 394.84229;114.75520;28.62360;,
 339.68030;48.19370;104.40210;,
 419.12070;72.45810;-53.00420;,
 493.02399;159.36990;-38.85440;,
 433.31149;195.25790;52.59030;,
 359.40790;108.34590;38.44040;,
 490.69980;157.43761;-176.71640;,
 564.60309;244.34940;-162.56660;,
 504.89059;280.23749;-71.12190;,
 430.98691;193.32539;-85.27190;,
 357.46570;163.55580;-152.69569;,
 431.36899;250.46770;-138.54590;,
 371.65649;286.35590;-47.10110;,
 297.75281;199.44360;-61.25110;,
 412.78210;238.90041;-239.52470;,
 476.21350;265.32501;-178.90021;,
 424.80069;368.14429;-178.13600;,
 361.36890;341.71951;-238.76100;;
 
 8;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;;
 
 MeshMaterialList {
  6;
  8;
  4,
  5,
  4,
  5,
  5,
  4,
  4,
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
    "îwåi2.bmp";
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
   0.984314;0.968627;1.000000;;
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
 }
 MeshNormals {
  8;
  0.318675;0.692599;-0.647111;,
  -0.318676;0.852335;0.414693;,
  0.676233;-0.086686;0.731570;,
  0.230995;0.641441;0.731570;,
  0.562956;-0.575303;0.593386;,
  0.562955;-0.575303;0.593387;,
  0.562956;-0.575303;0.593387;,
  -0.590459;-0.300813;0.748912;;
  8;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;;
 }
 MeshTextureCoords {
  32;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;
  -4.031790;-1.027610;
  0.018960;-1.027610;
  0.018960;3.023150;
  -4.031790;3.023150;;
 }
}
