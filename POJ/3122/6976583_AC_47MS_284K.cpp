#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const double PI = 3.1415926535897932384626;
int n, m, tests;
double l, r, s[10001], sum, t, total, tt;
int main()
{
	//freopen("E:\\My Programs\\in.txt", "r", stdin);
	cin >> tests;
	while (tests--)
	{
		scanf("%ld %ld", &n, &m); m++;
		sum = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lf", &s[i]), s[i] = s[i]*s[i], sum += s[i];
		
		l = 0; r = sqrt(sum / m);
		while (r - l > 1e-10)
		{
			t = (r+l) / 2;
			tt = t * t;
			total = 0;
			for (int i = 1; i <= n; i++)
				total += (int)(s[i] / tt);
			if (total >= m)
				l = t;
			else r = t;
		}
		t = (l+r)/2;
		printf("%0.4lf\n", PI*t*t);
	}
}
