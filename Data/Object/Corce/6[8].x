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
 8;
 -202.55611;-2.88300;-496.01111;,
 -198.30630;-2.88300;-494.25089;,
 -198.30630;-41.49080;-494.25089;,
 -202.55611;-41.49080;-496.01111;,
 -218.39920;-41.49080;-457.76251;,
 -214.14940;-41.49080;-456.00220;,
 -214.14940;-2.88300;-456.00220;,
 -218.39920;-2.88300;-457.76251;;
 
 4;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;6,5,2,1;,
 4;4,7,0,3;;
 
 MeshMaterialList {
  9;
  4;
  1,
  1,
  1,
  1;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ŽR.bmp";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Šâ.bmp";
   }
  }
  Material {
   0.170000;0.170000;0.170000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.220000;0.220000;0.220000;;
   TextureFilename {
    "ŽR.bmp";
   }
  }
  Material {
   0.190000;0.190000;0.190000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.310000;0.310000;0.310000;;
   TextureFilename {
    "Šâ.bmp";
   }
  }
  Material {
   0.350000;0.350000;0.350000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.310000;0.310000;0.310000;;
   TextureFilename {
    "Šâ.bmp";
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
    "”wŒi1.bmp";
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
    "Šâ.bmp";
   }
  }
 }
 MeshNormals {
  4;
  -0.382681;0.000000;0.923880;,
  0.382664;0.000000;-0.923887;,
  0.923880;0.000000;0.382683;,
  -0.923879;0.000000;-0.382684;;
  4;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;3,3,3,3;;
 }
 MeshTextureCoords {
  8;
  -18.761587;-3.919261;
  -18.690956;-3.785065;
  -19.014854;-4.556379;
  -19.085485;-4.690576;
  -17.623106;-5.412066;
  -17.552469;-5.277870;
  -17.228571;-4.506556;
  -17.299208;-4.640751;;
 }
}
