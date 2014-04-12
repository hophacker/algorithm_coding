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
#define N 730
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int T, m, n;
int P[8];
char map[7][N][N];
void printIt(int n){
	printIt(n-1);    
}
void copyIt(char map1[][N], char map2[][N], int i2, int j2, int n){
	F(i,0,n)
		F(j,0,n)
			map2[i+i2][j+j2] = map1[i][j];
}
void fill(char map1[][N], int i1, int j1, int n){
	F(i,0,n)
		F(j,0,n)
			map1[i+i1][j+j1] = ' ';
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	map[0][0][0] = 'X';
	P[0] = 1;
	F(i,1,8) P[i] = P[i-1] * 3;
	F(k,0,6){
		copyIt(map[k], map[k+1], 0, 0, P[k]);
		fill( 			 map[k+1], 0, P[k], P[k]);
		copyIt(map[k], map[k+1], 0, 2*P[k], P[k]);
		fill( 			 map[k+1], P[k], 0, P[k]);
		copyIt(map[k], map[k+1], P[k], P[k], P[k]);
		fill( 			 map[k+1], P[k], 2*P[k], P[k]);
		copyIt(map[k], map[k+1], 2*P[k], 0, P[k]);
		fill( 			 map[k+1], 2*P[k], P[k], P[k]);
		copyIt(map[k], map[k+1], 2*P[k], 2*P[k], P[k]);
	}
	while(scanf("%d", &n), n!=-1){
		F(i,0,P[n-1]){
			F(j,0,P[n-1]) printf("%c", map[n-1][i][j]);
			printf("\n");
		}
		printf("-\n");
	}
}