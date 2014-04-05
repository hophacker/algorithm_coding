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
#include <ctime>
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
#define getII(n,m) scanf("%d %d", &n,&m)
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
const int Ni = 105;
const int MAX = 1<<26;
struct Edge{
	int u,v,c;
	int next;
}edge[Ni*Ni];
int n,m;
int edn;//边数
int p[Ni];//父亲
int d[Ni];
int sp,tp;//原点，汇点

void addedge(int u,int v,int c)
{
	edge[edn].u=u; edge[edn].v=v; edge[edn].c=c;
	edge[edn].next=p[u]; p[u]=edn++;

	edge[edn].u=v; edge[edn].v=u; edge[edn].c=0;
	edge[edn].next=p[v]; p[v]=edn++;
}
int bfs()
{
	queue <int> q;
	memset(d,-1,sizeof(d));
	d[sp]=0;
	q.push(sp);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i=p[cur];i!=-1;i=edge[i].next)
		{
			int u=edge[i].v;
			if(d[u]==-1 && edge[i].c>0)
			{
				d[u]=d[cur]+1;
				q.push(u);
			}
		}
	}
	return d[tp] != -1;
}
int dfs(int a,int b)
{
	int r=0;
	if(a==tp)return b;
	for(int i=p[a];i!=-1 && r<b;i=edge[i].next)
	{
		int u=edge[i].v;
		if(edge[i].c>0 && d[u]==d[a]+1)
		{
			int x=min(edge[i].c,b-r);
			x=dfs(u,x);
			r+=x;
			edge[i].c-=x;
			edge[i^1].c+=x;
		}
	}
	if(!r)d[a]=-2;
	return r;
}

int dinic(int sp,int tp)
{
	int total=0,t;
	while(bfs())
	{
		while(t=dfs(sp,MAX))
			total+=t;
	}
	return total;
}
void skip(char c){
	char c1;
	while(true){
		scanf("%c", &c1);
		if (c1 == c) return;
	}
}
int main()
{
	//freopen("in", "r", stdin);
	int np, nc;
	int u,v,c;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=-1)
	{
		edn=0;//初始化
		memset(p,-1,sizeof(p));
		F(i,0,m) {
			skip('(');
			scanf("%d,%d", &u, &v);
			skip(')');
			getI(c);
			addedge(u,v,c);
		}
		F(i,0,np){
			skip('(');
			getI(u);
			skip(')');
			getI(c);
			addedge(n,u,c);
		}
		F(i,0,nc){
			skip('(');
			getI(u);
			skip(')');
			getI(c);
			addedge(u,n+1,c);
		}

		sp=n;tp=n+1;
		printf("%d\n",dinic(sp,tp));
	}
	return 0;
}