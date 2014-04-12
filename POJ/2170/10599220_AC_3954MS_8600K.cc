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
#define modN 99991
#define stepN 997
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool map[21][21];
bool cMap[11][11], cMapT[11][11];
int N, h, w;
char* pan[6][modN];
int xW[11], yW[11];
int total;
void rotate(int& dx, int& dy){
	F(i,0,dx)
		F(j,0,dy) cMapT[i][j] = cMap[i][j];
	F(i,0,dy)
		F(j,0,dx) cMap[i][j] = cMapT[dx-1-j][i];
	swap(dx,dy);
}
void mirror(int dx, int dy){
	F(i,0,dx)
		F(j,0,dy/2) swap(cMap[i][j], cMap[i][dy-1-j]);
}
int calcHash(char* minHash){
	int val = 0;
	for(int i = 0; minHash[i]!=0; i++)
		val = (val*256+minHash[i]) % modN;
	return val;
}
int find(char* minHash, int type){
	int hashV = calcHash(minHash);
	while(pan[type][hashV] != NULL){
		if (strcmp(pan[type][hashV], minHash) == 0) return -1;
		hashV = (hashV+stepN) % modN;
	}
	return hashV;
}
bool check(int dx, int dy, int type){
	char hash[21];
	char* minHash = new char[2*N+1];
	F(t,0,8){
		if (t != 0){
			if (t == 4)  mirror(dx, dy);
			else rotate(dx, dy);
		}
		int T = 0;
		F(i,0,dx) F(j,0,dy) if (cMap[i][j]){
			hash[2*T] = '0' + i;
			hash[2*T+1] = '0' + j;
			T++;
		}
		hash[2*T] = 0;
		if (t == 0 || strcmp(hash, minHash) <0)
			strcpy(minHash, hash);
	}
	int hashV = find(minHash, type);
	if (hashV!= -1){
		pan[type][hashV] = minHash;
		if (type ==1)
			total++;
	}
	return hashV != -1;
}
void search(int n, int x1, int x2, int y1, int y2){
	if (!(x2-x1<h && y2-y1<w || x2-x1<w && y2-y1<h)) return;
	if (n == 5 || n == 7 || n==8 || n == 9 || n == 5){
		FE(i,x1,x2)
			FE(j,y1,y2)
				cMap[i-x1][j-y1] = map[i][j];
		switch(n){
			case 5: if (!check(x2-x1+1, y2-y1+1,4)) return; else break;
			case 7: if (!check(x2-x1+1, y2-y1+1,3)) return; else break;
			case 8: if (!check(x2-x1+1, y2-y1+1,2)) return; else break;
			case 9: if (!check(x2-x1+1, y2-y1+1,0)) return; else break;
			case 6: if (!check(x2-x1+1, y2-y1+1,5)) return; else break;
		}
	}
	if (n == N+1){
		FE(i,x1,x2)
			FE(j,y1,y2)
				cMap[i-x1][j-y1] = map[i][j];
		check(x2-x1+1, y2-y1+1,1);
		return;
	}
	int xT, yT, x, y;
	FE(i,1,n-1){
		x = xW[i], y = yW[i];
		F(d,0,4){
			xT = x+fx[d][0];
			yT = y+fx[d][1];
			if (map[xT][yT] == 0){
				map[xT][yT] = 1;
				xW[n] = xT, yW[n] = yT;
				search(n+1,min(xT,x1), max(xT,x2), min(yT,y1), max(yT,y2));
				map[xT][yT] = 0;
			}
		}
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	clr(map, 0);
	clr(pan, 0);
	total = 0;
	scanf("%d %d %d", &N, &h, &w);
	map[10][10] = 1;
	xW[1] = yW[1] = 10;
	search(2,10,10,10,10);
	printf("%d\n", total);
}