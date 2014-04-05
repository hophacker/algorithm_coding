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
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<=r;i++)
#define FD(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define w(i,j,k) dp[i][j][k]
int T, m, n;
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int dp[21][21][21];
	F(a,0,20) F(b,0,20) F(c,0,20) dp[a][b][c] = 1;
	F(a,1,20)
		F(b,1,20)
			F(c,1,20){
				if (a < b && b < c) w(a,b,c) =
					w(a, b, c-1) + w(a, b-1, c-1) - w(a,b-1,c);
				else
					w(a,b,c)=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
			}
	int a, b, c;
	while(scanf("%d %d %d", &a, &b ,&c), a!=-1||b!=-1||c!=-1){
		printf("w(%d, %d, %d) = ", a, b, c);
		if (a <= 0 || b <= 0 || c <= 0) putI(1);
		else if (a > 20 || b > 20 || c >  20) putI(dp[20][20][20]);
		else putI(dp[a][b][c]);
	}
}