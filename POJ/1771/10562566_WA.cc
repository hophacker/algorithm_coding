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
int m, n;
int want[31];
int dp[32][32];
int stop[32][32];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	while(getI(n), n!=0){
		FE(i,1,n){
			getI(want[i]);
			want[i]--;
		}
		clr(dp,0);
		clr(stop,0);
		FE(i,1,30)	
			FE(j,i+1,30){
				FE(t,1,n) if (D(want[t],i,j))
					stop[i][j] = max(stop[i][j], min((want[t]-i)*20,10+4*(j-i)+20*(j-want[t])));
			}
		FE(i,1,30){
			FE(t,1,n) if (want[t] <= i)
				dp[i][1] = max(dp[i][1], min(20*want[t], 4*i+(i-want[t])*20));
		}
		FE(k,2,30)
			FE(i,k,30){
				dp[i][k] = INT_MAX;
				FE(j,k-1,i-1)
					dp[i][k] = min(dp[i][k], max(dp[j][k-1],stop[j][i]+4*j+10*(k-2)));
			}
		int t, minT = INT_MAX, Li,Lk;
		FE(k,1,30)
			FE(i,k,30){
				t = dp[i][k];
				if (want[n] > i) t += (want[n]-i) * 20;
				if (t < minT){
					Li = i;
					Lk = k;
					minT = t;
				}
			}
		stack<int> sta;
		sta.push(Li);
		while(Lk > 1){
			FE(i,Lk-1,Li-1)		
				if (dp[Li][Lk] == max(dp[i][Lk-1],stop[i][Li]+4*i+10*(Lk-2)) ){
					Li = i;
					Lk--;
				}
			sta.push(Li);
		}
		printf("%d\n", minT);
		printf("%d", sta.size());
		int size = sta.size();
		F(i,0,size){
			printf(" %d", sta.top()+1);
			sta.pop();
		}
		printf("\n");
	}
}
