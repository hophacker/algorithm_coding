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
#define maxN 101
int T, m, n;
struct node{
	int u, v, d;
	friend bool operator<(const node a, const node b){
		return a.d > b.d;
	};
};
priority_queue<node> q;
int fa[maxN];
int father(int u){
	if (fa[u] == u) return u;
	else
		return fa[u] = father(fa[u]);
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	char c1, c2;
	int d, u1, v1;
	node t;
	int cost;
	getI(n);
	cost = 0;
	F(i,0,n) fa[i] = i;
	F(i,0,n){
		t.u = i;
		F(j,0,n){
			getI(d);
			if (i < j){
				t.v = j;
				t.d = d;
				q.push(t);
			}
		}
	}
	F(i,0,n-1){
		while(true){
			t = q.top(), q.pop();
			u1 = father(t.u);
			v1 = father(t.v);
			if (u1 != v1){
				fa[u1] = v1;
				cost += t.d;
				break;
			}
		}
	}
	cout << cost << endl;
}