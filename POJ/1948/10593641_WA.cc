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
int T, m, n;
bool dp[1601][1601];
int len[41];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(n);
	F(i,0,n) getI(len[i]);
	clr(dp,0);
	dp[0][len[0]] = dp[len[0]][0] = dp[0][0] = true;
	int total = len[0];
	F(t,1,n){
		total += len[t];
		FE(i,0,total)
			FE(j,0,total){
				if (i >= len[t]) dp[i][j] |= dp[i-len[t]][j];
				if (j >= len[t]) dp[i][j] |= dp[i][j-len[t]];
			}
	}
	int c;
	double p = total/2, maxA = 0, area;
	F(a,1,total)
		F(b,1,total){
			c = total-a-b;
			if (a+b>c && a+c>b && b+c>a){
				area = (p-a)*(p-b)*(p-c);
				if (area > maxA) maxA = area;
			}
		}
	maxA = sqrt(maxA*p)*100;
	printf("%d\n", (int)maxA);
}