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
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int hh[20][20];
bool map[20][20][4];
int T, m, n;
struct node{
	int x, y, f;
};
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	bool first = true;
while(~scanf("%d %d", &n, &m)){
	F(i,0,n)
		F(j,0,m)
			getI(hh[i][j]);
	clr(map, false);
	int x, y;
	int x1, y1, x2, y2, d;
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2), x1!=0||y1!=0||x2!=0||y2!=0){
		x1--, y1--, x2--, y2--;
		if (x1 == x2){
			if (y1 < y2) d = 2;
			else d = 3;
		}else{
			if (x1 < x2) d = 0;
			else d = 1;
		}
		for(;x1!=x2||y1!=y2; x1+=fx[d][0], y1+=fx[d][1]){
			if (hh[x1+fx[d][0]][y1+fx[d][1]]-hh[x1][y1] <= 10)
				map[x1][y1][d] = true;
		}
	}
	node q[401];
	int res[401];
	int resT;
	bool use[20][20];
	clr(use, false);
	int h, t;
	int xT, yT;
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2), x1!=0||y1!=0||x2!=0||y2!=0){
		x1--, y1--, x2--, y2--;
		if (x1<0||y1<0||x2<0||y2<0){
			printf("There is no acceptable route from %d-%d to %d-%d.\n\n", x1+1,y1+1,x2+1,y2+1);
			continue;
		}
		if (x1==x2 && y1==y2){
			printf("To get from %d-%d to %d-%d, stay put!\n\n",x1+1,y1+1,x2+1,y2+1);
			continue;
		}
		clr(use, false);
		h = t = 0;
		q[h].x = x1, q[h].y = y1, q[h].f = -1;
		use[x1][y1] = true;
		while(h <= t){
			x1 = q[h].x, y1 = q[h].y;
			if (x1==x2 && y1==y2) break;
			F(d,0,4) if(map[x1][y1][d]){
				xT = x1 + fx[d][0];
				yT = y1 + fx[d][1];
				if (!use[xT][yT]){
					use[xT][yT] = true;
					t++;
					q[t].x = xT;
					q[t].y = yT;
					q[t].f = h;
				}
			}
			h++;
		}
		if (h <= t){
			resT = 0;
			while(q[t].f != -1){
				res[resT++] = t;
				t = q[t].f;
			}
			res[resT++] = t;
			FFE(i,resT-1,0){
				printf("%d-%d", q[res[i]].x+1, q[res[i]].y+1);
				if (i == 0) printf("\n");
				else printf(" to ");
			}
			printf("\n");
		}else{
			printf("There is no acceptable route from %d-%d to %d-%d.\n\n", q[0].x+1,q[0].y+1,x2+1,y2+1);
		}
	}
}
}