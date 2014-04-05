#include<iostream>
#include<fstream>
using namespace std;

struct node
{
	int a, b, k, fa;
}q[10001];
int ma, mb, mc, h, t;
bool used[101][101];
inline void pour(int &a, int ma, int &b, int mb)
{
	if (a + b > mb)
		a = a+b - mb, b = mb;
	else
		b = a+b, a = 0;
}
inline void pop(int aa, int bb, int kind)
{
	if (!used[aa][bb])
		used[aa][bb] = true, t++, q[t].a = aa, q[t].b = bb, q[t].fa = h, q[t].k = kind;
}
void overIt()
{
	int way[10001], wayT = 0;
	while (q[h].fa != -1)
	{
		way[++wayT] = q[h].k;
		h = q[h].fa;
	}
	cout << wayT << endl;
	for (int i = wayT; i >= 1; i--)
	{
		if (way[i] == 1) cout << "POUR(1,2)\n";
		if (way[i] == 2) cout << "POUR(2,1)\n";
		if (way[i] == 3) cout << "FILL(1)\n";
		if (way[i] == 4) cout << "FILL(2)\n";
		if (way[i] == 5) cout << "DROP(1)\n";
		if (way[i] == 6) cout << "DROP(2)\n";
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> ma >> mb >> mc;
	h = t = 0;
	q[0].a = q[0].b = 0;
	q[0].fa = -1;
	while (h <= t)
	{
		if (q[h].a == mc || q[h].b == mc) 
		{
			overIt();
			return 0;
		}
		int aa, bb;
		aa = q[h].a, bb = q[h].b;
		pour(aa, ma, bb, mb);
			pop(aa, bb, 1);

		aa = q[h].a, bb = q[h].b;
		pour(bb, mb, aa, ma);
			pop(aa, bb, 2);

		aa = ma, bb = q[h].b;
			pop(aa, bb, 3);
			
		aa = q[h].a, bb = mb;
			pop(aa, bb, 4);

		aa = 0, bb = q[h].b;
			pop(aa, bb, 5);

		aa = q[h].a, bb = 0;
			pop(aa, bb, 6);
		h++;
	}
	cout << "impossible\n";
}
