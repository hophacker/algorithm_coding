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
#define scaI(n) scanf("%d", &n)
#define scaII(a,b) scanf("%d %d", &a, &b)
#define scaS(s) scanf("%s", s);
#define F(i,l,r) for (int i=l;i<r;i++)
#define FF(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
struct node{
	int x1, y1, x2, y2;
}w[10001];

struct node1{
	int x, y;
};
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char dir[10001];
int dirL;
bool map[100][100][4];
int T, m, n, wL, xT, yT, xEnd, yEnd;
int num[100][100];
int step[100][100];
node1 q[10001];
bool used[100][100];
void setMap(int x1, int y1, int x2, int y2, bool b){
	if (x1 == x2){
		if (y1 < y2)
			map[x1][y1][2] = b, map[x2][y2][3] = b;
		else
			map[x1][y1][3] = b, map[x2][y2][2] = b;
	}else{
		if (x1 < x2)
			map[x1][y1][0] = b, map[x2][y2][1] = b;
		else
			map[x1][y1][1] = b, map[x2][y2][0] = b;

	}
}
bool getTar(int &x, int &y){
	x = 0;
	y = 0;
	int d;
	F(i,0,dirL){
		switch(dir[i]){
			case 'R':d = 0;break;
			case 'L':d = 1;break;
			case 'U':d = 2;break;
			case 'D':d = 3;break;
		}
		if (!map[x][y][d]) return false;
		x += fx[d][0];
		y += fx[d][1];
	}
	return true;
}
bool getStep(int state){
	int h, t;
	clr(num, 0);
	clr(used, 0);
	clr(step, 0);
	h = t = 0;
	q[h].x = 0, q[h].y = 0;
	num[0][0] = 1;
	used[0][0] = true;
	step[0][0] = 0;
	while(h <= t){
		if (q[h].x == xEnd && q[h].y == yEnd) break;
		F(d,0,4) if (map[q[h].x][q[h].y][d]){
			xT = q[h].x + fx[d][0];
			yT = q[h].y + fx[d][1];
			if (!used[xT][yT]){
				step[xT][yT] = step[q[h].x][q[h].y]+1;
				t++;
				q[t].x = xT;
				q[t].y = yT;
				used[xT][yT] = true;
			}
			if (step[xT][yT] == step[q[h].x][q[h].y]+1)
				num[xT][yT] += num[q[h].x][q[h].y];
		}
		h++;
	}
	if (state == 1) return num[xEnd][yEnd] == 1 && step[xEnd][yEnd] == dirL;
	else
		return num[xEnd][yEnd] != 1 || step[xEnd][yEnd] != dirL;
}
int main(){
	//freopen("in", "r", stdin);
	scaI(T);
	while(T--){
		int x1, y1, x2, y2;
		bool path;
		wL = 0;
		clr(map, 1);
		scaII(n,m);
//int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		F(i,0,n)
			map[i][0][3] = 0, map[i][m-1][2] = 0;
		F(i,0,m)
			map[0][i][1] = 0, map[0][n-1][1] = 0;
		scaS(dir);
		dirL = strlen(dir);
		scaI(wL);
		F(i,0,wL){
			scanf("%d %d %d %d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
			setMap(w[i].x1, w[i].y1, w[i].x2, w[i].y2, false);
		}
		if (!getTar(xEnd, yEnd)){
			printf("INCORRECT\n");
			continue;
		}
		if (!getStep(1)){
			printf("INCORRECT\n");
			continue;
		}
		bool inC = false;
		F(i,0,wL){
			setMap(w[i].x1, w[i].y1, w[i].x2, w[i].y2, true);
			if (!getStep(2)){
				inC = true;
				printf("INCORRECT\n");
				break;
			}
			setMap(w[i].x1, w[i].y1, w[i].x2, w[i].y2, false);
		}
		if (!inC)
			printf("CORRECT\n");
	}
}





