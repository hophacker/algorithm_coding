#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int m, t, n, i, j, k;
double p[1001], f[1001][1001];
double p1, pn, pp;
int main()
{
//	freopen("in.txt", "r", stdin);
	while (true)
	{
		scanf("%d%d%d", &m, &t, &n);
		if (t == 0) break;
		p1 = 1; pn = 1;
		for (i = 1; i <= t; i++)	
		{
			for (j = 1; j <= m; j++) 
				scanf("%lf", &p[j]);
			f[1][1] = p[1]; f[1][0] = 1-p[1];
			for (j = 2; j <= m; j++)
			{
				f[j][0] = f[j-1][0] * (1-p[j]);
				for (k = 1; k < n; k++)
					f[j][k] = f[j-1][k-1] * p[j] + f[j-1][k] * (1-p[j]);
			}
			pp = 0;
			for (j = 1; j < n; j++)
				pp += f[m][j];
			p1 *= (1-f[m][0]);
			pn *= pp;
		}
		cout << fixed << setprecision(3) << p1-pn << endl;
	}
}
