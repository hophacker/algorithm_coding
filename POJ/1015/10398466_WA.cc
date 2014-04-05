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
#define FD(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define ID 400
int d[201];
int  p[201];
int dp[201][21][801];
int L, R, k;
void search(int i, int j, int AR, int SR){
	int SRI = SR -(d[i]-p[i]);
	int ARI = AR -(d[i]+p[i]);
	if (SRI==0 && ARI==0){
		printf(" %d", i);
	}
	if (dp[i-1][j][SR+ID] == AR)
		search(i-1,j,AR,SR);
	else if (D(SRI,L,R) && dp[i-1][j-1][SRI+ID]==ARI){
		search(i-1,j-1,ARI, SRI);
		printf(" %d", i);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int T = 0, m, n;
	while(scanf("%d %d", &n, &m), m!=0&&n!=0){
		L = m*-20, R= m*20;
		F(i,1,n) scanf("%d %d", &d[i], &p[i]);
		clr(dp, -1);
		dp[0][0][ID] = 0;
		F(i,1,n)
			dp[i][1][d[i]-p[i]+ID] = d[i]+p[i];
		F(i,1,n)
			F(t,1,m)
				F(j,L,R){
					dp[i][t][j+ID] = max(dp[i-1][t][j+ID], dp[i][t][j+ID]);
					k = j-(d[i]-p[i]);
					if (D(k,L,R) && dp[i-1][t-1][k+ID] != -1)
						dp[i][t][j+ID] = max(d[i]+p[i]+dp[i-1][t-1][k+ID], dp[i][t][j+ID]);
				}
		int AR, SR;
		F(j,0,R){
			if (dp[n][m][j+ID] != -1 || dp[n][m][-j+ID] != -1){
				SR = j;
				AR = max(dp[n][m][j+ID], dp[n][m][-j+ID]);
				break;
			}
		}
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n", ++T, (AR+SR)/2, (AR-SR)/2);
		search(n, m, AR, SR);
		cout << endl << endl;
	}

}