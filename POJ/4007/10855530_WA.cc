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
#define getII(n,m) scanf("%d%d", &n,&m)
#define getIII(n,m,k) scanf("%d%d%d", &n,&m,&k)
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<r))
#define bit(x,i) ((x&(1<<i))!=0)
#define nbit(x,i) ((x&(1<<i))==0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define ull unsigned long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int maze[8][8];
bool vis[8][8];
bool flood[8][8];
int T, m, n;
int dep;
int add;
void fill(int x, int y, int c){
	if (!flood[x][y]) add++;
	flood[x][y] = 1;
	vis[x][y] = 1;
	int x1, y1;
	F(d,0,4){
		x1 = x + fx[d][0];
		y1 = y + fx[d][1];
		if (D(x1,0,n) && D(y1,0,n) && !vis[x1][y1] && 
				(flood[x1][y1] || !flood[x1][y1] && maze[x1][y1]==c))
			fill(x1,y1,c);
	}
}
int left(){
	int col = 0;
	F(i,0,n) F(j,0,n) if (!flood[i][j]) col |= (1<<maze[i][j]);
	int cnt=0;
	while(col){
			col&=(col-1);
				cnt++;
	}
	return cnt;
}
bool floodIt(int d){
	if (d == dep){
		if (left() == 0) return true; return false;
	}
	bool flood1[8][8];
	if (left() > dep-d) return false;
	F(col,0,6){
		memcpy(flood1, flood, sizeof(flood));
		add = 0;
		clr(vis,0);
		fill(0,0,col);

		if (add && floodIt(d+1)) return true;

		memcpy(flood, flood1, sizeof(flood));
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	// ifstream cin("in");
//	freopen("in", "r", stdin);
	while(getI(n), n){
		F(i,0,n) F(j,0,n) getI(maze[i][j]);
		clr(vis,0);
		clr(flood,0);
		fill(0,0,maze[0][0]);
		dep = 0;
		while(true){
			if (floodIt(0)) break;
			dep++;
		}
		cout << dep << endl;
	}
}