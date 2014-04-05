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
#include <map>
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
#define modN 800000
#define step 9997
struct node{
	int x, y, v;
}p[200001];
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int T, m, n;
int totalV, maxV;
int hash[modN];
void put(int x, int y, int i){
	x *= y;
	while(hash[x]!=0) x = ((x+step) % modN+modN)%modN;
	hash[x] = i;
}
int find(int x, int y){
	x *= y;
	while(hash[x]!=0){
		if (p[hash[x]].x == x && p[hash[x]].y == y) return hash[x];
		x = ((x+step) % modN+modN)%modN;
	}
	return -1;
}
void search(int i){
	totalV += p[i].v;
	p[i].v = -1;
	int x, y, ii;
	F(d,0,4){
		x = p[i].x + fx[d][0];
		y = p[i].y + fx[d][1];
		ii = find(x, y);
		if (ii != -1 && p[ii].v != -1)
			search(ii);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int x, y, v;
	while(getI(n), n!=0){
		maxV = 0;
		clr(hash, 0);
		F(i,0,n){
			scanf("%d %d %d", &x, &y, &v);
			p[i].x = x;
			p[i].y = y;
			p[i].v = v;
			put(x,y,i);
		}
		F(i,0,n) if (p[i].v != -1){
			totalV = 0;
			search(i);
			maxV = max(totalV, maxV);
		}
		printf("%d\n", maxV);
	}
}