#include "stdafx.h"

#define N 50

#include <math.h>

#include <stdlib.h>

#include "MyTriangle.h"

#include<iostream>

using namespace std;


CTriangle::CTriangle()

{

	M = 0;

	t = new int *[N];

	s = new int *[N];

	for (int i = 0; i < N; i++)

	{

		t[i] = new int[N];

		s[i] = new int[N];

	}

	v = new point[N];

	total = new int[N];

}



CTriangle::~CTriangle()

{

	for (int i = 0; i < N; i++)

	{

		delete[]t[i];

		delete[]s[i];

	}

	delete[]t;

	delete[]s;

	delete[]v;

	delete[]total;

}



int CTriangle::distance(point X, point Y)

{

	int dis = (Y.x - X.x)*(Y.x - X.x) + (Y.y - X.y)*(Y.y - X.y);

	return (int)sqrt(dis);

}



int CTriangle::w(point X, point Y, point Z)

{

	return distance(X, Y) + distance(Y, Z) + distance(Z, X);

}



bool CTriangle::Input()

{

	int m;

	int a, b, c;

	cout << "������͹����ζ��������";

	cin >> m;

	M = m - 1;

	for (int i = 0; i < m; i++)

	{

		cout << "���붥��v" << i << "�����꣺";

		cin >> v[i].x >> v[i].y;

	}



	//���ݶ��������ж��Ƿ��ܹ���һ��͹�����

	for (int j = 0; j < m; j++)

	{

		int p = 0;

		int q = 0;

		if (m - 1 == j)

		{

			a = v[m - 1].y - v[0].y;

			b = v[m - 1].x - v[0].y;

			c = b * v[m - 1].y - a * v[m - 1].x;

		}

		else

		{

			a = v[j].y - v[j + 1].y;

			b = v[j].x - v[j + 1].x;

			c = b * v[j].y - a * v[j].x;

		}

		for (int k = 0; k < m; k++)

		{

			total[k] = a * v[k].x - b * v[k].y + c;

			if (total[k] > 0)

			{

				p = p + 1;

			}

			else if (total[k] < 0)

			{

				q = q + 1;

			}

		}

		if ((p > 0 && q > 0) || (p == 0 && q == 0))

		{

			cout << "�޷�����͹����Σ�" << endl;

			exit(1);

		}

	}



	if (NULL != v)

		return true;

	else

		return false;

}



bool CTriangle::minWeightTriangulation()

{

	if (NULL == v)

		return false;

	for (int i = 1; i <= M; i++)

		t[i][i] = 0;

	for (int r = 2; r <= M; r++)

		for (int i = 1; i <= M - r + 1; i++)

		{

			int j = i + r - 1;

			t[i][j] = t[i + 1][j] + w(v[i - 1], v[i], v[j]);

			s[i][j] = i;

			for (int k = i + 1; k < i + r - 1; k++)

			{

				int u = t[i][k] + t[k + 1][j] + w(v[i - 1], v[k], v[j]);

				if (u < t[i][j])

				{

					t[i][j] = u;

					s[i][j] = k;

				}

			}

		}

	return true;

}



void CTriangle::Traceback(int i, int j, int **s)

{

	if (i == j)

		return;

	/*{

	cout<<"�ֳɵ�����������Ϊ��"<<endl;

	cout<<"v"<<i-1<<"v"<<i<<"v"<<j<<endl;

	}

	else*/

	Traceback(i, s[i][j], s);

	Traceback(s[i][j] + 1, j, s);

	cout << "�����Σ�v" << i - 1 << "v" << s[i][j] << "v" << j << endl;

}



bool CTriangle::Run()

{

	if (Input())

	{

		if (CTriangle::minWeightTriangulation())

		{

			CTriangle::Traceback(1, M, s);

			cout << endl;

			cout << "����Ȩֵ֮��Ϊ��" << t[1][M] << endl;

			return true;

		}

		else

			return false;

	}

	else

		return false;

}