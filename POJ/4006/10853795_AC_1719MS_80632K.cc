#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <limits.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define getI(n) scanf("%d", &n)
#define getII(n,m) scanf("%d%d", &n,&m)
#define getIII(n,m,k) scanf("%d%d%d", &n,&m,&k)
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define nbit(x,i) ((x&(1<<i))==0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define ull unsigned long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define inf 1000000001
#define maxn 3010
int T, m, n;
int dis[maxn][maxn];
bool sel[maxn][maxn];
vector<int>  lin[maxn];
int g[maxn][maxn];
int minSpan;
int tim1[maxn], tim2[maxn], tim;
void prim(){
	int minDis[maxn];
	int pre[maxn];
	bool vis[maxn];
	clr(vis, 0);
	F(i,1,n) if (dis[0][i] != -1){
		minDis[i] = dis[0][i];
		pre[i] = 0;
	}else minDis[i] = pre[i] = -1;

	vis[0] = true;
	int minD, minI;
	F(t,0,n-1){//n-1 tims
		minD = INT_MAX;
		F(i,0,n) if (!vis[i] && minDis[i] < minD)
			minI = i, minD = minDis[i];
		vis[minI] = true;
		F(i,0,n) if (!vis[i] && dis[minI][i] < minDis[i]){
			pre[i] = minI;
			minDis[i] = dis[minI][i];
		}
	}
	minSpan = 0;
	F(i,1,n) {
		minSpan += minDis[i];
		sel[i][pre[i]] = sel[pre[i]][i] = true;
		lin[i].push_back(pre[i]);
		lin[pre[i]].push_back(i);
	}
//	cout << minSpan << endl;
//	F(i,1,n) cout << i << ' ' << pre[i] << endl;
}
void dfs(int h, int f, int u){
	int v;
	if (!sel[h][u])
		g[h][u] = dis[h][u];
	else g[h][u] = inf;


	F(i,0,lin[u].size()){
		v = lin[u][i];
		if (v != f){
			dfs(h, u, v);
			if (!sel[h][v])
				g[h][u] = min(g[h][u], g[h][v]);
		}
	}
}
void hackIt(){
	F(i,0,n){
		dfs(i, -1, i);
	}
}
void dfs1(int u, int f){
	tim1[u] = ++tim;
	F(i,0,lin[u].size())
		if (lin[u][i] != f)
			dfs1(lin[u][i], u);
	tim2[u] = ++tim;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	// ifstream cin("in");
	//freopen("in", "r", stdin);
	int a, b, c;
	double sum;
	while(getII(n,m), n||m){
		F(i,0,n) F(j,0,n) dis[i][j] = inf;
		clr(sel, false);
		F(i,0,n) lin[i].clear();
		F(i,0,m){
			getIII(a, b, c);
			dis[a][b] = dis[b][a] = c;
		}
		prim();
		tim = 0;
		dfs1(0,-1);
		hackIt();
		sum = 0;
		int DD;
		getI(m);
		FE(t,1,m){
			getIII(a,b,c);
			if (tim1[a] > tim1[b]) swap(a,b);
			DD = INT_MAX;
			F(i,0,n) if (tim1[i] < tim1[b] || tim2[i] > tim2[b])
				DD = min(DD, g[i][b]);
			if (!sel[a][b]) sum += minSpan;
			else sum += (minSpan-dis[a][b]) + min(DD,c);
		}
		printf("%.4f\n", sum/m);
	}
}

