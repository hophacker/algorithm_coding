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
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<=r;i++)
#define FD(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T, m, n, v;
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int d[301][301], dis[301][301];
	int p[301];
	getI(n); getI(v);
	F(i,0,n-1) getI(p[i]);
	F(i,0,n-1){
		d[i][i] = 0;
		F(j,i+1,n-1)
			d[i][j] = d[i][j-1] + abs(p[j]-p[j-1]);
	}
	int k;
	F(i,0,n-1){
		F(j,i+1,n-1){
			dis[i][j] = 0;
			k = (i+j)/2;
			F(t,i,k) dis[i][j] += d[t][k];
			F(t,k,j) dis[i][j] += d[k][t];
		}
	}

	int dp[301][31];
	F(i,0,n-1)
		dp[i][1] = dis[0][i];
	F(k,2,v)
		F(i,k-1,n-1){
			dp[i][k] = INT_MAX;
			F(j,k-2,i-1)
				dp[i][k] = min(dp[i][k], dp[j][k-1] + dis[j+1][i]);
		}
	printf("%d\n", dp[n-1][v]);
}
