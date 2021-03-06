#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	int pri, gra, num;
	int p[101], mon[101];
}obj[101];
int m, n, i, j, r, l;
bool used[102];
inline bool ok(int k)
{
	return k >= l && k <= r;
}
int search(int who)
{
	if (obj[who].num == 0)
		return obj[who].pri;
	int minMon = obj[who].pri;
	for (int i = 1; i <= obj[who].num; i++)
		if (ok(obj[obj[who].p[i]].gra))
			minMon = min(minMon, search(obj[who].p[i]) + obj[who].mon[i]);
	return minMon;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> m >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> obj[i].pri >> obj[i].gra >> obj[i].num;
		for (j = 1; j <= obj[i].num; j++)
			cin >> obj[i].p[j] >> obj[i].mon[j];
	}
	fill(&used[0], &used[n+1], false);
	used[1] = true;
	int minP = obj[1].pri;
	for (i = -m; i <= 0; i++)
	{
		l = obj[1].gra + i;
		r = l + m;
		minP = min(search(1), minP);
	}
	cout << minP << endl;
}
