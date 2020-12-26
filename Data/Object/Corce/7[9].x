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
 24;
 -0.15890;41.58670;-96.94710;,
 0.23780;41.58670;-96.84090;,
 0.23780;89.19150;-96.84090;,
 -0.15890;89.19150;-96.94710;,
 -0.44940;41.58670;-97.23760;,
 -0.44940;89.19150;-97.23760;,
 -0.55560;41.58670;-97.63420;,
 -0.55560;89.19150;-97.63420;,
 -0.44940;41.58670;-98.03100;,
 -0.44940;89.19150;-98.03100;,
 -0.15890;41.58670;-98.32140;,
 -0.15890;89.19150;-98.32140;,
 0.23780;41.58670;-98.42770;,
 0.23780;89.19150;-98.42770;,
 0.63450;41.58670;-98.32140;,
 0.63450;89.19150;-98.32140;,
 0.92490;41.58670;-98.03100;,
 0.92490;89.19150;-98.03100;,
 1.03120;41.58670;-97.63420;,
 1.03120;89.19150;-97.63420;,
 0.92490;41.58670;-97.23760;,
 0.92490;89.19150;-97.23760;,
 0.63450;41.58670;-96.94710;,
 0.63450;89.19150;-96.94710;;
 
 12;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;8,6,7,9;,
 4;10,8,9,11;,
 4;12,10,11,13;,
 4;14,12,13,15;,
 4;16,14,15,17;,
 4;18,16,17,19;,
 4;20,18,19,21;,
 4;22,20,21,23;,
 4;1,22,23,2;;
 
 MeshMaterialList {
  7;
  12;
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6;;
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
   0.271800;0.271800;0.271800;1.000000;;
   8.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  12;
  0.000000;0.000000;1.000000;,
  -0.499907;0.000000;0.866079;,
  -0.866067;0.000000;0.499927;,
  -1.000000;0.000000;0.000062;,
  -0.866056;0.000000;-0.499947;,
  -0.499927;0.000000;-0.866068;,
  0.000000;0.000000;-1.000000;,
  0.500001;0.000000;-0.866025;,
  0.866040;0.000000;-0.499974;,
  1.000000;0.000000;0.000063;,
  0.866052;0.000000;0.499954;,
  0.499982;0.000000;0.866036;;
  12;
  4;1,0,0,1;,
  4;2,1,1,2;,
  4;3,2,2,3;,
  4;4,3,3,4;,
  4;5,4,4,5;,
  4;6,5,5,6;,
  4;7,6,6,7;,
  4;8,7,7,8;,
  4;9,8,8,9;,
  4;10,9,9,10;,
  4;11,10,10,11;,
  4;0,11,11,0;;
 }
 MeshTextureCoords {
  24;
  0.104340;0.669760;
  0.006330;0.696020;
  0.006330;0.696020;
  0.104340;0.669760;
  0.176090;0.598010;
  0.176090;0.598010;
  0.202350;0.500000;
  0.202350;0.500000;
  0.176090;0.401990;
  0.176090;0.401990;
  0.104340;0.330240;
  0.104340;0.330240;
  0.006330;0.303980;
  0.006330;0.303980;
  -0.091680;0.330240;
  -0.091680;0.330240;
  -0.163420;0.401990;
  -0.163420;0.401990;
  -0.189690;0.500000;
  -0.189690;0.500000;
  -0.163420;0.598010;
  -0.163420;0.598010;
  -0.091680;0.669760;
  -0.091680;0.669760;;
 }
}
