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
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	char s1[1000], s2[1000];
	int dp[1000][1000];
	int L1, L2;
	while(~scanf("%s%s", s1+1, s2+1)){
		L1 = strlen(s1);
		L2 = strlen(s2);
		F(i,0,L1) dp[i][0] = 0;
		F(j,0,L2) dp[0][j] = 0;
		F(i,1,L1-1)
			F(j,1,L2-1){
				if (s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = 0;
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
				dp[i][j] = max(dp[i][j], dp[i][j-1]);
			}
		printf("%d\n", dp[L1-1][L2-1]);
	}
}