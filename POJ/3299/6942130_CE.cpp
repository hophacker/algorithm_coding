#define k1 0.5555
#define k2 10.0
#define k3 6.11
#define k4 5417.7530
#define k5 273.16
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const double mind = -1e20;
char c1, c2;
double n1, n2, n, t, d, h;
int assign(char c, double x)
{
	if (c == 'T') t = x; else
	if (c == 'D') d = x; else
	h = x;
}
double ffh(double d)
{
	return k1 * (k3 * exp(k4 * (1/k5-1/(k5+d))) - k2);
}
double ft(double d, double h)
{
	return h - ffh(d);
}
double fd(double t, double h)
{
	double temp = (((h - t)/ k1 + k2) / k3);
	temp = log(temp)/ k4;
	temp = 1/ (1 / k5 - temp) - k5;
	return temp;
}
double fh(double t, double d)
{
	double c = ffh(d);
	return t + ffh(d);
}
int main()
{	
	//freopen("in.txt", "r", stdin);
	cin >> c1;
	while (c1 != 'E')
	{
		cin >> n1 >> c2 >> n2;	
		h = t = d = mind;
		assign(c1, n1);
		assign(c2, n2);
		if (abs(t-mind) < 0.1) t = ft(d, h);
		if (abs(d-mind) < 0.1) d = fd(t, h);
		if (abs(h-mind) < 0.1) h = fh(t, d);
		printf("T %0.1lf D %0.1lf H %0.1lf\n", t, d, h);
		cin >> c1;
	}
}
