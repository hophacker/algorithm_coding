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
char map[21][21];
int T, m, n;
void search(int x, int y){
	int xt, yt;
	T++;
	map[x][y] = '#';
	F(d,0,4){
		xt = x + fx[d][0];
		yt = y + fx[d][1];
		if (D(xt,0,n-1)&&D(yt,0,m-1) && map[xt][yt]=='.') search(xt,yt);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	while(getII(m,n), n!=0){
		F(i,0,n) getS(map[i]);
		F(i,0,n) F(j,0,m) 
			if (map[i][j]=='@'){
				T = 0;
				search(i,j);
				break;
			}
		printf("%d\n", T);
	}
}





