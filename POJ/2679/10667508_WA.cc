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
#define nbit(x,i) ((x&(1<<i))==0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define maxN 1200
struct node{
	int v, c, L;
};
int T, m, n, A, B, u, v, L, c1, c2;
vector<node> edge[maxN];
int enter[maxN];
int minD[maxN];
int minC[maxN];
bool visit[maxN];
void add(int u, int v, int c, int L){
	node t;
	t.v = v, t.c = c, t.L = L;
	if (edge[u].empty())
		edge[u].push_back(t);
	else{
		if (t.c <= edge[u][0].c){
			if (t.c < edge[u][0].c) edge[u].clear();
			edge[u].push_back(t);
		}
	}
}
bool path(int u){
	if (u == B) return true;
	F(i,0,edge[u].size()) if (!visit[edge[u][i].v]){
		visit[edge[u][i].v] = true;
		if (path(edge[u][i].v)) return true;
	}
	return false;
}
bool spaf(){
	queue<int> q;
	F(i,0,n) minD[i] = INT_MAX, enter[i] = 0, minC[i] = INT_MAX;
	minD[A] = 0;
	minC[A] = 0;
	q.push(A); enter[A] = 1;
	int u, v, c, L;
	while(!q.empty()){
		u = q.front();
		if (enter[u] == n) 
			break;
		q.pop();
		F(i,0,edge[u].size()){
			v = edge[u][i].v;
			c = edge[u][i].c;
			L = edge[u][i].L;
			if (minC[u]+c<minC[v] || minC[u]+c==minC[v] && minD[u]+L < minD[v]){
				minC[v] = minC[u] + c;
				minD[v] = minD[u] + L;
				q.push(v);
				enter[v]++;
			}
		}
	}
	while(!q.empty()) q.pop();
	clr(visit,0);
	if (path(u)) return false;
	else return true;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	char ch;
	while(scanf(" %d %d %d %d ", &n, &m, &A, &B) != -1){
		F(i,0,maxN) edge[i].clear();
		F(i,0,m){
			//scanf(" ( %d , %d , %d [ %d ] %d ) ", &u, &v, &c1, &L, &c2);
			while(scanf("%c", &ch), ch != '(');
		    scanf("%d,%d,%d[%d]%d)", &u, &v, &c1, &L, &c2);
			//printf("%d %d %d %d %d\n", u, v, c1, L, c2);
			add(u,v,c1,L);
			add(v,u,c2,L);
		}
		//F(i,0,n){
		//	F(j,0,edge[i].size())
		//		printf("%d %d %d %d\n", i, edge[i][j].v, edge[i][j].c, edge[i][j].L);
		//}
	//	clr(visit, 0); visit[A] = true;
		//if (!path(A)) cout << "VOID" << endl;
	//	else if (!spaf())
		//	cout << "UNBOUND" << endl;
		//else cout << minC[B] << ' ' << minD[B] << endl;
	}
}