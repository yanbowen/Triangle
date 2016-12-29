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

	void Traceback(int i, int j, int **s); //�õݹ�ķ�������ʷֺ�ĸ���������

	bool minWeightTriangulation(); //��������ֵ�㷨

	bool Input();                 //����������룬ͬʱ�ж��ܷ񹹳�һ��͹�����

	int w(point X, point Y, point Z);   //����������Ȩֵ�ĺ���

	int distance(point X, point Y);    //����ƽ����������������ĺ���

	int **s;                     //��¼���������ʷ���������������Ϣ

	int **t;                      //��¼���������ʷ�����Ӧ��Ȩ����ֵ

	point *v;                    //��¼͹����θ���������

	int *total;                    //��¼������ֱ�߷����е�ֵ

	int M;

};