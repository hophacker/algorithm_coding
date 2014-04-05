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
int m, n;
ll dp[12][2048];
int b2[12];
bool mat[2048][12];
bool match(int c, int m){
	int count = 0, i = 0;
	while(i < m){
		count = 0;
		while(bit(c,i) && i < m) i++;
		while(nbit(c,i) && i < m) count++, i++;
		if (count % 2 == 1) return false;
	}
	return true;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	b2[0] = 1;
	FE(i,1,11) b2[i] = 2 * b2[i-1];
	FE(m,1,11)
		F(a,0,b2[m]) mat[a][m] = match(a,m);
	while(getII(n,m), n!=0){
		dp[0][0] = 1;

		FE(d,1,n)
			F(a,0,b2[m]){
				dp[d][a] = 0;
				F(b,0,b2[m])
					if (((a&b)==0) && mat[a|b][m])
						dp[d][a] += dp[d-1][b];
			}
		cout << dp[n][0] << endl;
	}
}