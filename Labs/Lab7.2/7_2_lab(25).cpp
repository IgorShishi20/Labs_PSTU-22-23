#include <iostream>
#include <cmath>
using namespace std;

double sidelength(int x1, int y1, int x2, int y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double square(double a, double b, double c)
{
	double p;
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

float square1(int k,...)
{
	int* p = &k;
    int* x = new int [k / 2];
    int* y = new int[k / 2];
	for (int i=0; i<k; i++)
	{
		if (i % 2 == 0)
		{
			x[i/2] = *p;
		}
		else
		{
			y[i/2]= *p;
		}
		p++;
	}
	double max=-1000000000;
	int ind1=0, ind2=0;
	for (int i = 0; i < k/2; i++)
	{
		for (int j = 0; j < k/2; j++)
		{
			if (abs(i - j) > 1 && abs(i - j) != (k / 2) - 1)
			{
				if (max < sidelength(x[i], y[i], x[j], y[j]))
				{
					max = sidelength(x[i], y[i], x[j], y[j]);
					ind1 = i;
					ind2 = j;
				}
			}
		}
	}
	int ind3=0;
	for (int m=0; m < k / 2; m++)
	{
		if (m != ind1 && m != ind2)
		{
			ind3 = m;
		}
	}
	return square(sidelength(x[ind1], y[ind1], x[ind2], y[ind2]), sidelength(x[ind3], y[ind3], x[ind2],y[ind2]), sidelength(x[ind1], y[ind1], x[ind3], y[ind3]));
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << square(sidelength(1, 5, -3, 12), sidelength(1, 5, 27, 4), sidelength(-3, 12, 27, 4)) << endl;;
	cout << square1(10, 1, 5, -3, 12, 27, 4, -32, 19, 42, 77) << endl;
	return 0;
}





