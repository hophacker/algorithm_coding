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
#define S0 step%3
#define S1 (step+1)%3
#define S2 (step+2)%3

struct node{
	int x, y;
};
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//freopen("in.txt", "r", stdin);
	node q[3][90000];
	int len[3];
	char map[302][302];
	int n, m, xT, yT, x, y, step = 0;
	bool find;
	while(scanf("%d %d", &n,&m) && n != 0){
		for (int i = 0; i < n; i++){
			scanf("%s", map[i]);
			for (int j = 0; j < m; j++)
				if (map[i][j] == 'Y'){
					q[0][0].x = i;
					q[0][0].y = j;
				}else if(map[i][j] == 'T'){
					xT = i;
					yT = j;
				}
		}
		len[0] = 1; len[1] = len[2] = 0;
		bool find = false;
		while(len[S0] > 0 || len[S1] > 0){
			if (len[S0] == 0) step++;
			for (int i =0; i<len[S0]; i++){
				if (q[S0][i].x == xT && q[S0][i].y == yT){
					find = true;
					break;
				}
				
				for (int d = 0; d < 4; d++){
					x = fx[d][0] + q[S0][i].x;
					y = fx[d][1] + q[S0][i].y;
					if (0 <= x && 0 <= y && x < n && y < m){
						if (map[x][y] == 'E' || map[x][y] == 'T'){
							q[S1][len[S1]].x = x;
							q[S1][len[S1]].y = y;
							len[S1]++;
							map[x][y] = '.';
						}else if(map[x][y] == 'B'){
							q[S2][len[S2]].x = x;
							q[S2][len[S2]].y = y;
							len[S2]++;
							map[x][y] = '.';
						}
					}
				}
			}
			if (find) break;
			len[S0] = 0;
			step++;
		}
		if (find)
			printf("%d\n", step);
		else 
			printf("-1\n");
	}
}