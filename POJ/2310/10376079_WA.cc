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
#define F(i,l,r) for (int i=l;i<r;i++)
#define FF(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define qi (me?'O':'X')
#define M(c1,c2,c3) ((c1==c2)&&(c2==c3))
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char map[4][4][4];
int T, m, n;
struct node{
	int x, y, z;
	bool u;
}e[28];
int eL;
bool check(){
	F(i,0,3)
		F(j,0,3)
			if (M(map[i][j][0],map[i][j][1],map[i][j][2])
			|| M(map[i][0][j],map[i][1][j],map[i][2][j])
			|| M(map[0][j][i],map[1][j][i],map[2][j][i])) return true;
	F(i,0,3)
		if (M(map[0][0][i],map[1][1][i],map[2][2][i])
		||  M(map[0][i][0],map[1][i][1],map[2][i][2])
		||  M(map[i][0][0],map[i][1][1],map[i][2][2])
		||  M(map[0][2][i],map[1][1][i],map[2][0][i])
		||  M(map[0][i][2],map[1][i][1],map[2][i][0])
		||  M(map[i][0][2],map[i][1][1],map[i][2][0])) return true;
	if (M(map[0][0][0],map[1][1][1],map[2][2][2]) 
	|| M(map[0][2][2],map[1][1][1],map[2][0][0]) 
	|| M(map[2][0][2],map[1][1][1],map[0][2][0]) 
	|| M(map[2][2][0],map[1][1][1],map[0][0][2])) return true;
}
int game(int de, bool me){
	if (de == eL) return 0;
	int x, y, z;
	int s;
	bool draw = false;
	F(i,0,eL) if(!e[i].u){
		e[i].u = true;
		map[e[i].x][e[i].y][e[i].z] = qi;
		if (check()) return 1;
		s = game(de+1, !me);

		if(s == -1) return 1;
		else if (s == 0) draw = true;

		map[e[i].x][e[i].y][e[i].z] = '.';
		e[i].u = false;
	}
	if (draw) return 0;
	else return -1;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	char s[4];

	while(~scanf("%s", map[0][0])) {
		int O = 0, X = 0;
		F(i,0,3)
			F(j,0,3)
				if (i!=0 || j !=0)
					scanf("%s", map[i][j]);
		eL = 0;
		F(i,0,3)
			F(j,0,3)
				F(k,0,3)
					if (map[i][j][k] == '.'){
						e[eL].x = i;
						e[eL].y = j;
						e[eL].z = k;
						e[eL].u = false;
						eL++;
					}else if (map[i][j][k] == 'X') X++;
				else O++;
		int s;
		if (O == X)
			s = game(0, true);
		else 
			s = - game(0, false);
		if (s == 0)
			printf("DRAW\n");
		else if (s == 1)
			printf("WIN\n");
		else printf("LOSE\n");

	}
}