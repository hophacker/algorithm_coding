#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct node
{
	int x, t;
}p[5001];
int adj[5001][5000], bdj[5001][5000];
int visit[5001];
int f[5001];
bool fail[5001];
int id[5001];
int v, e, a, b, total;
int tim = 0;

void search(int x)
{
	tim++;
	visit[x] = 1;
	for (int i = 1; i <= adj[x][0]; i++)
		if (visit[adj[x][i]] == 0)	
		{
			search(adj[x][i]);
		}
	tim++;
	f[x] = tim;
}
void search1(int x)
{
	visit[x] = total;
	for (int i = 1; i <= bdj[x][0]; i++)
		if (visit[bdj[x][i]] == 0)
			search1(bdj[x][i]);
}
bool cmp(const node& a, const node& b)
{
	return a.t > b.t;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &v);
	while (v)
	{
		scanf("%d", &e);
		for (int i = 1; i <= v; i++) adj[i][0] = bdj[i][0] = 0;
		for (int i = 1; i <= e; i++)
		{
			scanf("%d%d", &a, &b);
			adj[a][++adj[a][0]] = b;
			bdj[b][++bdj[b][0]] = a;
		}
		memset(visit, 0, sizeof(visit));
		tim = 0;
		for (int i = 1; i <= v; i++)
			if (visit[i] == 0)
				search(i);
		for (int i = 1; i <= v; i++)
			p[i].x = i, p[i].t = f[i];
		sort(p+1, p+v+1, cmp);
		memset(visit,  0, sizeof(visit));
		total = 0;
		for (int i = 1; i <= v; i++)
			if (!visit[p[i].x])
			{
				total++;
				search1(p[i].x);
			}
		memset(id, 0, sizeof(id));
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= adj[i][0]; j++)
				if (visit[i] != visit[adj[i][j]])
					id[visit[i]] = 1;
		int b[5001], bt = 0;
		for (int  i = 1; i <= v; i++)
			if (id[visit[i]] == 0)
				b[++bt] = i;
		for (int i = 1; i <= bt; i++) 
			if (i == 1) cout << b[i]; else cout << ' ' << b[i];
		cout << endl;
		scanf("%d", &v);	
	}
}
