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
int dp[2][maxN+1][2];
int v[maxN+1];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getII(n,b);
	int total = 0, minIt = INT_MAX;
	FE(i,1,n) {
		getI(v[i]);
		total += v[i];
		if (v[i] < minIt) minIt = v[i];

	}	
	if (n <= 1){
		cout << 0 << endl;; return 0;
	}
	if (n == b){
		cout << total-minIt << endl; return 0;
	}
	FE(j,0,b) dp[1][j][0] = dp[1][j][1] = INT_MIN;
	dp[1][0][0] = 0;
	int i0, i1;
	FE(i,2,n){
		i0 = i%2;
		i1 = (i-1)%2;
		FE(j,0,b) dp[i0][j][0] = dp[i0][j][1] = INT_MIN;
		dp[i0][0][0] = 0;
		FE(j,1,min(i,b)){
			dp[i0][j][1] = max(dp[i1][j-1][1]+v[i], dp[i1][j-1][0]);
			if (j < i)
				dp[i0][j][0] = max(dp[i1][j][1], dp[i1][j][0]);
		}
	}
	int maxV =  max(dp[n%2][b][0], dp[n%2][b][1]);

	FE(j,0,b) dp[1][j][0] = dp[1][j][1] = INT_MIN;
	dp[1][1][1] = 0;
	FE(i,2,n){
		i0 = i%2;
		i1 = (i-1)%2;
		FE(j,0,b) dp[i0][j][0] = dp[i0][j][1] = INT_MIN;
		dp[i0][1][0] = 0;
		FE(j,2,min(i,b)){
			dp[i0][j][1] = max(dp[i1][j-1][1]+v[i], dp[i1][j-1][0]);
			if (j < i)
				dp[i0][j][0] = max(dp[i1][j][1], dp[i1][j][0]);
		}
	}
	cout <<  max(maxV, dp[n%2][b][1]+v[1]) << endl;
}


