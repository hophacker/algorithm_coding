#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define N 110
#define E 10000
#define inf 1000000000

#define typef int
// type of flow
#define typec int
// type of dis
const typef inff =0x3f3f3f3f;
// max of flow
const typec infc =0x3f3f3f3f;
// max of dis
int shop[N][N], supply[N][N];
struct network
{
	int nv, ne, pnt[E], nxt[E];
	int vis[N], que[N], head[N], pv[N], pe[N];
	int sum;
	typef flow, cap[E];
	typec cost, dis[E], d[N];
	void addedge(int u, int v, typef c, typec w)
	{
		pnt[ne] = v;
		cap[ne] = c;
		dis[ne] =+w;
		nxt[ne] = head[u];
		head[u] = (ne++);
		pnt[ne] = u;
		cap[ne] =0;
		dis[ne] =-w;
		nxt[ne] = head[v];
		head[v] = (ne++);
	}
	int mincost(int src, int sink)
	{
		int i, k, f, r;
		typef mxf;
		for (flow =0, cost =0;;)
		{
			memset(pv, -1, sizeof(pv));
			memset(vis, 0, sizeof(vis));
			for (i =0; i < nv; ++i)
				d[i] = infc;
			d[src] =0;
			pv[src] = src;
			vis[src] =1;
			for (f =0, r =1, que[0] = src; r != f;)
			{
				i = que[f++];
				vis[i] =0;
				if (N == f)
					f =0;
				for (k = head[i]; k !=-1; k = nxt[k])
					if (cap[k] && dis[k] + d[i] < d[pnt[k]])
					{
						d[pnt[k]] = dis[k] + d[i];
						if (0== vis[pnt[k]])
						{
							vis[pnt[k]] =1;
							que[r++] = pnt[k];
							if (N == r)
								r =0;
						}
						pv[pnt[k]] = i;
						pe[pnt[k]] = k;
					}
			}
			if (-1== pv[sink])
				break;
			for (k = sink, mxf = inff; k != src; k = pv[k])
				if (cap[pe[k]] < mxf)
					mxf = cap[pe[k]];
			flow += mxf;
			cost += d[sink] * mxf;
			for (k = sink; k != src; k = pv[k])
			{
				cap[pe[k]] -= mxf;
				cap[pe[k] ^1] += mxf;
			}
		}
		return cost;
	}
	void build(int n, int m, int o)
	{
		nv = n + m +2;
		ne =0;
		int src =0;
		int sink =1;
		sum =0;
		memset(head, -1, sizeof(head));
		for (int i =0; i < n; i++)
		{
			addedge(i +2, sink, shop[i][o], 0);
			sum += shop[i][o];
		}
		for (int i =0; i < m; i++)
			addedge(src, i +2+ n, supply[i][o], 0);
		for (int i =0; i < n; i++)
			for (int j =0; j < m; j++)
			{
				int a;
				scanf("%d", &a);
				addedge(j +2+ n, i +2, inf, a);
			}
	}
};

int n, m, o;

void input()
{
	for (int i =0; i < n; i++)
		for (int j =0; j < o; j++)
			scanf("%d", &shop[i][j]);
	for (int i =0; i < m; i++)
		for (int j =0; j < o; j++)
			scanf("%d", &supply[i][j]);
}

int main()
{
	//freopen("in", "r", stdin);
	while (scanf("%d%d%d", &n, &m, &o), n | m | o)
	{
		bool ok =true;
		int ans =0;
		input();
		for (int i =0; i < o; i++)
		{
			network g;
			g.build(n, m, i);
			if (ok)
				ans += g.mincost(0, 1);
			if (g.flow != g.sum)
				ok =false;
		}
		if (ok)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}