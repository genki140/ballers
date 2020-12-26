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
 0.00000;1.00000;0.00000;,
 -1.00000;0.00000;0.00000;,
 0.00000;0.00000;-1.00000;,
 -1.00000;0.00000;0.00000;,
 0.00000;1.00000;0.00000;,
 0.00000;0.00000;1.00000;,
 -1.00000;0.00000;0.00000;,
 0.00000;-1.00000;-0.00000;,
 0.00000;0.00000;-1.00000;,
 0.00000;1.00000;0.00000;,
 0.00000;0.00000;-1.00000;,
 1.00000;0.00000;0.00000;,
 0.00000;1.00000;0.00000;,
 0.00000;0.00000;-1.00000;,
 -1.00000;0.00000;0.00000;,
 -1.00000;0.00000;0.00000;,
 0.00000;0.00000;1.00000;,
 0.00000;1.00000;0.00000;,
 -1.00000;0.00000;0.00000;,
 0.00000;0.00000;-1.00000;,
 0.00000;-1.00000;-0.00000;,
 0.00000;1.00000;0.00000;,
 1.00000;0.00000;0.00000;,
 0.00000;0.00000;-1.00000;;
 
 16;
 3;0,1,2;,
 3;3,4,5;,
 3;6,7,8;,
 3;9,10,11;,
 3;5,4,11;,
 3;11,8,7;,
 3;1,5,7;,
 3;11,7,5;,
 3;12,13,14;,
 3;15,16,17;,
 3;18,19,20;,
 3;21,22,23;,
 3;16,22,17;,
 3;22,20,19;,
 3;14,20,16;,
 3;22,16,20;;
 
 MeshMaterialList {
  2;
  16;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;0.350000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;0.350000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  8;
  0.577350;-0.577350;0.577350;,
  0.577350;-0.577350;-0.577350;,
  0.577350;0.577350;0.577350;,
  -0.577350;-0.577350;0.577350;,
  -0.577350;0.577350;-0.577350;,
  -0.577350;0.577350;0.577350;,
  -0.577350;-0.577350;-0.577350;,
  0.577350;0.577350;-0.577350;;
  16;
  3;0,0,0;,
  3;1,1,1;,
  3;2,2,2;,
  3;3,3,3;,
  3;6,6,6;,
  3;5,5,5;,
  3;7,7,7;,
  3;4,4,4;,
  3;4,4,4;,
  3;5,5,5;,
  3;6,6,6;,
  3;7,7,7;,
  3;2,2,2;,
  3;1,1,1;,
  3;3,3,3;,
  3;0,0,0;;
 }
 MeshTextureCoords {
  24;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;
  0.000000;0.000000;;
 }
}