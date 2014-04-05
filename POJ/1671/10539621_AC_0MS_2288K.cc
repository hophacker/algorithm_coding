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
int T, m, N;
double C[401][401];
double dp[201][201];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	FE(n,0,400) C[n][0] = C[n][n] = 1;
	FE(n,1,400)
		FE(m,1,n-1)
			C[n][m] = C[n-1][m-1] + C[n-1][m];
	FE(n,1,200) dp[n][1] = 1;
	FE(n,1,200)
		FE(m,2,n){
			dp[n][m] = dp[n-1][m-1];
			if (n > m) dp[n][m] += dp[n-1][m] * m;
		}
	double res[201];
	FE(i,1,200){
		res[i] = 0;
		FE(j,1,i) res[i] += dp[i][j];
	}
	//freopen("in", "r", stdin);
	while(true){
		getI(N);
		if (N==0) break;
		printf("%d %0.0f\n", N, res[N]);
	}
}




