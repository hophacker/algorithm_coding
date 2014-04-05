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
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int m, n, p, q, a, total;
inline int gcd(int p,int q){
	if (p < q) swap(p,q);
	int c;
	while(q != 0)
		c = p%q, p = q, q =c;
	return p;
}
void search(int p, int q, int n, int low, int aa){
	if (n == 0) return;
	int p1, q1, d;
	FE(k,max((q+p-1)/p,low),aa){
		p1 = k*p-q, q1 = k*q;
		if (p1 == 0) {
			total++;
			continue;
		}
		d = gcd(p1,q1);
		p1 /= d;
		q1 /= d;
		search(p1,q1,n-1,k,aa/k);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	freopen("in", "r", stdin);
	while(scanf("%d %d %d %d", &p, &q, &a, &n), p != 0){
		total = 0;
		search(p,q,n,1,a);
		printf("%d\n", total);//
	}
}