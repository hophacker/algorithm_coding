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
struct node{
	int v, d;
	node* ne;
};
int m, n, a, b, f, d;
node* u[50001];
bool vi[50001];
int x1[50001], x2[50001];
void add(int a, int b, int d){
	node* t = new node();
	t->v = b;
	t->d = d;
	t->ne = NULL;
	if (u[a] == NULL) u[a] = t;
	else{
		t->ne = u[a];
		u[a] = t;
	}
}
void search(int t, int fa){
	node* now = u[t]; 
	if (fa != 0 && now->ne == NULL){
		x1[t] = x2[t] = 0;
		return;
	}
	int total = 0;
	while(now != NULL){
		if (now->v != fa){
			search(now->v, t);
			if (vi[now->v])
				total += (x2[now->v]+2*now->d);
		}	
		now = now->ne;
	}
	if (total > 0) vi[t] = true;
	x2[t] = total;
	now = u[t];
	x1[t] = total;
	while(now != NULL){
		if (now->v != fa && vi[now->v])
			x1[t] = min(x1[t], total-x2[now->v]+x1[now->v]-now->d);
		now = now->ne;
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getII(n,f);
	clr(u, 0);
	clr(vi,0);
	F(i,0,n-1){
		scanf("%d %d %d", &a, &b, &d);
		add(a,b, d);
		add(b,a, d);
	}
	getI(m);
	int k;
	F(i,0,m){
		getI(k);
		vi[k] = true;
	}
	search(f, 0);
	printf("%d\n", x1[f]);
}




