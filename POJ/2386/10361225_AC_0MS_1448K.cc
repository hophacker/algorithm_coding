#include <cstdlib>
#include <cctype>
#include <cstring>
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
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define F(i,l,r) for (int i=l;i<r;i++)
#define D(i,l,r) ((l<=i)&&(i<r))
char map[102][102];
int n, m;
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
void spread(int i, int j){
	map[i][j] = '.';
	int i1, j1;
	F(d,0,8){
		i1 = i + fx[d][0];
		j1 = j + fx[d][1];
		if (D(i1,0,n)&&D(j1,0,m)&& map[i1][j1]=='W')
			spread(i1,j1);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	int total = 0;
	F(i,0,n)
		F(j,0,m) 
			if (map[i][j] == 'W'){
				spread(i,j);
				total++;
			}
	printf("%d\n", total);		
}