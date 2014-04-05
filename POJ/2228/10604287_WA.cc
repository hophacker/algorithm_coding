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
#define maxN 3830

int n, b;
int dp[maxN+1][maxN+1][2];
int v[maxN+1];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getII(n,b);
	FE(i,1,n) getI(v[i]);
	if (n <= 1){
		cout << 0; return 0;
	}
	FE(i,1,n) dp[i][0][1] = INT_MIN, dp[i][0][0] = 0;
	dp[1][1][1] = 0;
	FE(i,2,n)
		FE(j,1,min(i,b)){
			dp[i][j][1] = max(dp[i-1][j-1][1]+v[i], dp[i-1][j-1][0]);
			dp[i][j][0] = max(dp[i-1][j][1], dp[i-1][j][0]);
		}
	cout << max(dp[n][b][0]+v[1], dp[n][b][1]) << endl;
}


