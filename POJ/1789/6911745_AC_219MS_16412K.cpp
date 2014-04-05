#include<iostream>
#include<fstream>
using namespace std;

struct node
{
	int s, e, d;
}way[2101];
int n, i, j;
char s[2101][9];
int dis[2101][2101];
int disIt(int i, int j)
{
	int t = 0;
	for (int k = 0; k < 7; k++)
		if (s[i][k] != s[j][k]) t++;
	return t;
}
int main()
{	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int temp;
while(true)
{
	cin >> n;
	if (n == 0) break;
	getchar();
	for (i = 1; i <= n; i++)
		cin.getline(s[i], 100, '\n');
	for (i = 1; i <= n-1; i++)
		for (j = i+1; j <= n; j++)
		{
			temp = disIt(i, j);
			dis[i][j] = dis[j][i] = temp;
		}
	for (i = 1; i < n; i++)
		way[i].s = 1, way[i].e = i+1, way[i].d = dis[1][i+1];
	int total = 0;
	for (int time = 1; time < n; time++)
	{
		int minD = 100000000, minP; 
		for (i = time; i < n; i++)
			if (way[i].d < minD) minD = way[i].d, minP = i;
		swap(way[time], way[minP]);
		total += way[time].d;
		int from = way[time].e;
		for (i = time+1; i < n; i++)
			if (dis[from][way[i].e] < way[i].d)
				way[i].s = from, way[i].d = dis[way[i].s][way[i].e];
	}
	printf("The highest possible quality is %d/%d.\n", 1, total);
}
}
