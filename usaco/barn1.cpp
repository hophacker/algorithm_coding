/*
ID: fengjie3
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const int& a, const int& b)
{
	if (a > b) return true;
	else 
		return false;
} 
void print(int a[], int n)
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int m, s, c;
	int stall[201];
	int gap[201];
	cin >> m >> s >> c;
	for (int i = 1; i <= c; i++)
	{
		cin >> stall[i];
	//	cout << c << endl;
	}
//	cout << c << endl;
//	print(stall,c);
	sort(stall+1, stall+c+1, cmp);
//	print(stall,c);
	for (int i = 1; i <= c-1; i++)
		gap[i] = stall[i] - stall[i+1] - 1;
	sort(gap+1, gap+c, cmp);
	s = stall[1] - stall[c] + 1;
	if (m > c) m = c;
	for (int i = 1; i <= (m-1); i++)
		s -= gap[i];
	cout << s << endl;
}
