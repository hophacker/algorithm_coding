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
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int T, m, n, k;
int map[33][33];
vector<int> lin[1000];
int x[1000], y[1000];
bool vis[1000];
bool search(int u){
	int v;
	F(i,0,lin[u].size()){
		v = lin[u][i];
		if (!vis[v]){
			vis[v] = true;
			if (y[v]==-1 || search(y[v])){
				x[u] = v;
				y[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main(){
//if you do not want to use file input stream, put "//" before ifstream
// ifstream cin("in");
//	freopen("in", "r", stdin);
	scanf("%d%d%d", &m,&n,&k);
	clr(map, 0);
	int X, Y;
	F(i,0,k){
		getII(Y,X);
		map[X][Y] = -1;
	}
	int n1=0, n0=0;
	FE(i,1,m) FE(j,1,n) if (map[i][j] != -1){
		if ((i+j)%2) map[i][j] = n1++;
		else map[i][j] = n0++;
	}
	if (n0 != n1){
		cout << "NO" << endl;
		return 0;
	}
	FE(i,1,m)
		FE(j,1,n) if (map[i][j] != -1 && (i+j)%2)
			F(d,0,4){
				X = i + fx[d][0];
				Y = j + fx[d][1];
				if (D(X,1,m) && D(Y,1,n) && map[i][j] != -1)
					lin[map[i][j]].push_back(map[X][Y]);
			}
	clr(x,-1);
	clr(y,-1);
	F(i,0,n0){
		clr(vis,0);
		if (!(x[i]==-1 && search(i))){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}



