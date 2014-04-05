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
int T, m, n;
int main(){
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int n;
	char  s[5001];
	getI(n);
	getS(s);
	int dp[3][5001];
	clr(dp, 0);
	F(i,0,n-1)
		dp[1][i] = 0;
	F(k,2,n)
		F(i,0,n-k){
			dp[k%3][i] = min(dp[(k-1)%3][i]+1, dp[(k-1)%3][i+1]+1);
			if (s[i] == s[i+k-1]) dp[k%3][i] = min(dp[k%3][i], dp[(k-2)%3][i+1]);
		}
	printf("%d\n", dp[n%3][0]);
}

