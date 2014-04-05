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
#define maxN 2001
int T, m, n;
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int d, cost, minD, minP, p;
	char s[maxN][8];
	int dis[maxN];
	bool vis[maxN];
	while(getI(n), n!=0){
		cost = 0;
		F(i,0,n) dis[i] = INT_MAX;
		clr(vis, 0);
		dis[0] = 0;
		F(i,0,n)
			getS(s[i]);
		p = 0;
		F(time,0,n-1){
			vis[p] = true;
			minD = INT_MAX;
			F(i,0,n) if (!vis[i]){
				d = 0;
				F(k,0,7) if (s[i][k] != s[p][k]) d++;
				if (d < dis[i])
					dis[i] = d;
				if (dis[i] < minD){
					minD = dis[i];
					minP = i;
				}
			}
			cost += minD;
			p = minP;
		}
		printf("The highest possible quality is 1/%d.\n", cost);
	}
}