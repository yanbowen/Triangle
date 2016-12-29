#pragma once
typedef struct

{

	int x;

	int y;

}point;



class CTriangle

{

public:

	bool Run();

	CTriangle();

	virtual ~CTriangle();



private:

	void Traceback(int i, int j, int **s); //用递归的方法输出剖分后的各个三角形

	bool minWeightTriangulation(); //计算最优值算法

	bool Input();                 //处理键盘输入，同时判断能否构成一个凸多边形

	int w(point X, point Y, point Z);   //计算三角形权值的函数

	int distance(point X, point Y);    //计算平面上任意两点间距离的函数

	int **s;                     //记录最优三角剖分中所有三角形信息

	int **t;                      //记录最优三角剖分所对应的权函数值

	point *v;                    //记录凸多边形各顶点坐标

	int *total;                    //记录坐标在直线方程中的值

	int M;

};