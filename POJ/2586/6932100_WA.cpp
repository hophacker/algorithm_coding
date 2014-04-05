#include<iostream>
#include<fstream>
using namespace std;

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int s, d;
	int t;
	while (cin >> s >> d)
	{
		if (4*s-d < 0)
		{
			t = 10 * s - 2 * d;
			if (t > 0) cout << t << endl; else cout << "Deficit\n";
		}
		else
		if (3*s-2*d < 0)
		{
			t = 8 * s - 4 * d;
			if (t > 0) cout << t << endl; else cout << "Deficit\n";
		}else
		if (2*s-3*d < 0)
		{
			t = 6 * s - 6 * d;
			if (t > 0) cout << t << endl; else cout << "Deficit\n";
		}else
		if (s+4*d < 0)
		{
			t = 3 * s - 9 * d;
			if (t > 0) cout << t << endl; else cout << "Deficit\n";
		}
		else cout << "Deficit\n";
	}
}
