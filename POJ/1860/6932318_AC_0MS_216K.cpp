#include<iostream>
using namespace std;

struct node
{
	int u, v;
	double r, c;
}edge[20001];
int n, m, s, eT;
double mon;
bool ok[101][101];
double cash[101];
int main()
{
	int s1, s2;
	double r1, c1, r2, c2;
	//freopen("in.txt", "r", stdin);
	cin >> n >> m >> s >> mon;
	eT = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> s1 >> s2 >> r1 >> c1 >> r2 >> c2;
		eT++;
		edge[eT].u = s1, edge[eT].v = s2, edge[eT].r = r1, edge[eT].c = c1;
		eT++;
		edge[eT].u = s2, edge[eT].v = s1, edge[eT].r = r2, edge[eT].c = c2;
	}
	for (int i = 1; i <= n; i++)
		cash[i] = 0;
	cash[s] = mon;
	int u, v;
	for (int time = 1; time <= 10000; time++)
	{
		bool canRelax = false;
		for (int i = 1; i <= eT; i++)
		{
			u = edge[i].u, v = edge[i].v;
			if ((cash[u]-edge[i].c)*edge[i].r > cash[v]) 
			{
				cash[v] = (cash[u]-edge[i].c)*edge[i].r;				
				canRelax = true;
			}
		}
		if (!canRelax) break;
		if (cash[s] > mon) 
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
