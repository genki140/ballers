#define rad 0.0174533f//(3.141592/180)
#define deg 57.2957795f//(180/3.141592)
#define pi 3.1415926536f

//0以上rndmax未満 のランダムな数値を実数で返す関数
float rnd(float rndmax);

//ランダムジェネレータの初期化
void srnd();

//2つの座標の距離を、原点よりもとめる関数
float distance(float x,float y);

//3つの座標の距離を、原点よりもとめる関数
float distance3(float x,float y,float z);



//2つの座標が、dis*2を１辺とする正方形の中にあるかをもとめる関数(あればtrueを返す)
bool cubedistance(float x,float y,float dis);

//3つの座標が、dis*2を１辺とする立方体の中にあるかをもとめる関数(あればtrueを返す)
bool cubedistance3(float x,float y,float z,float dis);

//2つの座標の角度を、原点よりもとめる関数
float angle(float x,float y);

//二つのベクトルのなす角度を求める
float angle3(float x1,float y1,float z1,float x2,float y2,float z2);


//角度を0以上360未満の範囲に修正する関数
float reangle(float angle);

//2次元ベクトルの長さを変更する関数
void changedistance(float *x,float *y,float dis);

//3次元ベクトルの長さを変更する関数
void changedistance3(float *x,float *y,float *z,float dis);

//2つの座標の角度を、plusangleプラスする関数
void rotation(float *x,float *y,float plusangle);
//
////ベクトルを任意軸で回転させる
//void rotationaxis(float *x,float *y,float *z,float vx,float vy,float vz,float ang);
////
////ベクトルを任意軸で伸縮する
//void scalaxis(float *x,float *y,float *z,float vx,float vy,float vz,float scal);


//2つの物体の重さと移動速度より、ぶつかったときに生じる力の計算をする関数
//float sayou(float m1,float v1,float m2,float v2,double kyoyou);
float sayou(float m1,float v1,float m2,float v2,float keisuu);

//ベクトルAの方向成分がベクトルBにどれだけあるかをスカラーで返す関数
float dotpro(float ax,float ay,float bx,float by);

//ベクトルAの方向成分がベクトルBにどれだけあるかをスカラーで返す関数
float dotpro3(float ax,float ay,float az,float bx,float by,float bz);

//ベクトルAとベクトルBの法線を返す関数(原点→A→Bの順に時計回りが表)
void crosspro3(float *x,float *y,float *z,float ax,float ay,float az,float bx,float by,float bz);





//ある点の距離をある軸より求める関数
float distanceaxis(float x,float y,float z,float vx,float vy,float vz);


//ある点へのベクトルをある軸上の、点に一番近いところより求める関数(ローカル)
void axisvector(float *x,float *y, float *z,float ax,float ay,float az,float vx,float vy,float vz);


//
////ある点へのベクトルをある軸上の、点に一番近いところより求める関数(ワールド)
//float axisvectorW(float x*,float y* float z*,float vx,float vy,float vz,float vx,float vy,float vz);
//




//
////線と線が触れているか調べ、触れていたらその位置を返す関数
////(pointは、線の端が触れていたときの判定をするかをブール値で格納endlessはtrueにすると無限な線になる)
//bool linejud(float *bx,float *by,
//			 float l1x1,float l1y1,float l1x2,float l1y2,float l2x1,float l2y1,float l2x2,float l2y2,
//			 bool point=false,bool endless=false);
//
////点が三角形の範囲か調べる関数
//bool pointtrianglejud(float px,float py,float x1,float y1,float x2,float y2,float x3,float y3,bool point=false,bool line=false);
//
////三角形と三角形が触れているか調べる関数
//bool trianglejud(float tri1x1,float tri1y1,float tri1x2,float tri1y2,float tri1x3,float tri1y3,
//				  float tri2x1,float tri2y1,float tri2x2,float tri2y2,float tri2x3,float tri2y3);
//
////三角形の面積を求める関数
//float trianglearea(float x1,float y1,float x2,float y2,float x3,float y3);
//
////三角形の重心を求める関数
//void trianglegravity(float *bx,float *by,float x1,float y1,float x2,float y2,float x3,float y3);
//
////複数の点の重心を求める関数(countには、配列の要素数を渡す)
//void pointgravity(float *bx,float *by,float *bw,float x[],float y[],float w[],int count);
//
////多角形が右回りか調べる関数
//bool rotationright(float x[],float y[],int count);
//
////多角形の回る方向をいれかえる関数
//void rotationchange(float x[],float y[],int count);
//
////最大公約数を求める関数
//int kouyaku(int num1,int num2);
//
////最小公倍数を求める関数
//int koubai(int num1,int num2);
//
////aとbを比較し、aBigがtrueならaの方を、falseならbの方が大きくなるように入れ替える関数
//void change(bool aBig,float *a,float *b);
//
////三角形の外接円の原点と半径を求める関数
//void gaisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3);
//
////三角形の内接円の原点と半径を求める関数
//void naisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3);
//
////法線ベクトルを求める関数
//void housen(float *nxs,float *nys,float *nzs,
//			float x1s,float y1s,float z1s,float x2s,float y2s,float z2s,float x3s,float y3s,float z3s);

////三つの点a,b,cの∠bの中にpがはいるかを調べる関数 hukumuは、pがaと同じ方向や、cと同じ方向を含むかを指定する
////(a,b,cとたどる、右側の角について)
//bool inangle(float px,float py,float ax,float ay,float bx,float by,float cx,float cy,bool hukumu=true);
//
////点が、多角形の中にあるかを調べる関数(px,pyは、点の位置、x[],y[],countは、多角形の点とその数をあらわす)
//bool polygonpointjud(float px,float py,float x[],float y[],int count);
//
////多角形と多角形が触れているかを調べる関数(x1,y1,count1は一つ目の多角形、x2,y2,count2は二つ目の多角形をあらわす)
//bool polygonjud(float x1[],float y1[],int count1,float x2[],float y2[],int count2);
