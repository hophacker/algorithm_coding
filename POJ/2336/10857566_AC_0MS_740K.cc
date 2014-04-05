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
#define copy(des,sou) memcpy(des,sou,sizeof(sou))
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define getI(n) scanf("%d", &n)
#define getII(n,m) scanf("%d%d", &n,&m)
#define getIII(n,m,k) scanf("%d%d%d", &n,&m,&k)
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
#define ull unsigned long long
#define maxn 1500
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int T, m, n, t;
int arr[maxn];
int dp[maxn];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	// ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	while(T--){
		getIII(n,t,m);
		F(i,0,m) getI(arr[i]);
		F(i,0,m) dp[i] = INT_MAX;
		dp[0] = t+t+arr[0];
		F(i,1,m){
			if (i+1<=n) dp[i] = arr[i]+t+t;
			F(j,max(0,i-n),i)
				dp[i] = min(max(dp[j],arr[i]) + t + t, dp[i]);
		}
		int i = m-1, times = 0, j;
		while(true){
			if (i+1<=n && arr[i]+t+t==dp[i]){
				times++;
				break;
			}
			for(j=max(0,i-n); j < i; j++)
				if (max(dp[j],arr[i])+t+t == dp[i]) break;
			times++;
			i = j;
		}
		cout << dp[m-1]-t << ' ' << times << endl;
	}
}