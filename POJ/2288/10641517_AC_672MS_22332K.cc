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
#define lll long long
struct node{
	int v;
	int ne;
};
struct node1{
	int maxT;
	lll num;
};
int T, m, n;
int val[14];
node lin[157];
int linkT;
int u[13];
int map[13][13];
node1 dp[8192][13][13];
int target;
void add(int a, int b){
	lin[linkT].v = b;
	if (u[a] == -1){
		u[a] = linkT;
		lin[linkT].ne = -1;
	}else{
		lin[linkT].ne = u[a];
		u[a] = linkT;
	}
	linkT++;
}
void search(int st, int l, int ll){
	if (st == target){
		dp[st][l][ll].maxT = 0;
		dp[st][l][ll].num = 1;
		return;
	}
	int ln = u[l];
	lll vv;
	while(ln != -1){
		int v = lin[ln].v;
		if (nbit(st,v)){
			if (dp[st|1<<v][v][l].maxT == -1)
				search(st|1<<v, v, l);
			vv = dp[st|1<<v][v][l].maxT + val[v]*val[l]*(val[ll]*map[v][ll]+1);
			if (dp[st|1<<v][v][l].maxT != -1){
				if (dp[st][l][ll].maxT < vv){
					dp[st][l][ll].maxT = vv;
					dp[st][l][ll].num = dp[st|1<<v][v][l].num;
				}else if (dp[st][l][ll].maxT == vv)
					dp[st][l][ll].num += dp[st|1<<v][v][l].num;
			}
		}
		ln = lin[ln].ne;
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	int a, b;
	while(T--){
		clr(lin,-1);
		linkT = 0;
		clr(u, -1);
		clr(map, 0);

		getII(n,m);
		int sum = 0;
		F(i,0,n){
			getI(val[i]);
			sum += val[i];
		}
		F(i,0,m){
			getII(a,b);
			a--, b--;
			if (!map[a][b]){
				add(a,b);
				add(b,a);
			}
			map[a][b] = map[b][a] = true;
		}
		if (n == 1){
			printf("%d 1\n", sum);
			continue;
		}else if(n==2){
			if (m >= 1)
				printf("%d 1\n", sum+val[0]*val[1]);
			else printf("0 0\n");
			continue;
		}
		clr(dp,-1);
		int maxT = -1;
		lll num, vv;
		target = (1<<n)-1;
		F(i,0,n){
			int ln = u[i], v;
			while(ln != -1){
				v = lin[ln].v;
				search(1<<i|1<<v, v, i);
				vv = dp[1<<i|1<<v][v][i].maxT + val[v]*val[i];
				if (dp[1<<i|1<<v][v][i].maxT != -1){
					if (vv > maxT){
						maxT = vv;
						num = dp[1<<i|1<<v][v][i].num;
					}else if (vv == maxT){
						num += dp[1<<i|1<<v][v][i].num;
					}
				}
				ln = lin[ln].ne;
			}
		}
		if (maxT == -1)
			printf("0 0\n");
		else printf("%d %lld\n", maxT+sum, num/2);
	}

}