#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct node
{
	int x, y;
}p[50001], hull[50001]; 
int n, top;

bool cmp(const node& a, const node& b)
{
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
inline bool right(node& a, node& b, node& c)
{
	int x1 = b.x-a.x, y1 = b.y-a.y, x2 = c.x-a.x, y2 = c.y-a.y;
	return x1 * y2 - y1 * x2 <= 0;
}
void graham()
{
	hull[1] = p[1];
	hull[2] = p[2];
	top = 2;
	for (int i = 3; i <= n; i++)
	{
		while (top >= 2 && right(hull[top-1], hull[top], p[i])) top--;
		hull[++top] = p[i];
	}
	int len = top;
	hull[++top] = p[n-1];
	for (int i = n-2; i >= 1; i--)
	{
		while (top >= len+1 && right(hull[top-1], hull[top], hull[i])) top--;
		hull[++top] = p[i];
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	sort(p+1, p+n+1, cmp);
	graham();
	int maxD = -1, t;
	for (int i = 1; i <= top-2; i++)
		for (int j = i+1; j <= top-1; j++)
		{
			t = abs(hull[i].x-hull[j].x) + abs(hull[i].y-hull[j].y);
			if (t > maxD) maxD = t;
		}
	cout << maxD << endl;
}
