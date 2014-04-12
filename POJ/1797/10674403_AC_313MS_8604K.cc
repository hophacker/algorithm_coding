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
#define maxN 1000
struct node{
	int v, d;
};
int T, m, n;
vector<node> edge[maxN+1];
int enter[maxN+1];
int maxD[maxN+1], A;
bool vis[maxN+1];
int size[maxN+1];
bool spaf(){
	queue<int> q;
	FE(i,1,n) maxD[i] = 0, enter[i] = 0, vis[i] = false;
	maxD[A] = INT_MAX;
	q.push(A); enter[A] = 1; vis[A] = true;
	int u, v, d, L;
	while(!q.empty()){
		u = q.front();
		vis[u] = false;
		if (enter[u] > n) 
			break;
		q.pop();
		F(i,0,size[u]){
			v = edge[u][i].v;
			d = min(edge[u][i].d, maxD[u]);
			if (d > maxD[v]){
				maxD[v] = d;
				if (!vis[v]){
					vis[v] = true;
					q.push(v);
					enter[v]++;
				}
			}
		}
	}
}

int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	int a, b, d;
	node t;
	FE(i,1,maxN) edge[i].resize(999);
	FE(cases,1,T){
		clr(size, 0);
		getII(n,m);
		F(i,0,m){
			scanf("%d %d %d", &a, &b, &d);
			t.v = b, t.d = d;
			edge[a][size[a]++] = t;
			t.v = a;
			edge[b][size[b]++] = t;
		}
		A = 1;
		spaf();
		printf("Scenario #%d:\n", cases);
		cout << maxD[n] << endl << endl;
	}
}