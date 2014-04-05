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
#include <map>
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
struct node{
	int x, y;
};
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	char map[301][301];
	int  dis[301][301];
	int n, m, x1, y1, x2, y2;
	node q[90001];
	int h, t;
	//freopen("in.txt", "r", stdin);
	while(scanf("%d %d", &n,&m) && n!=0){
		for (int i = 0; i < n; i++){
			scanf("%s", map[i]);
			for (int j = 0; j < m; j++){
				dis[i][j] = INT_MAX;
				if (map[i][j] == 'Y')
					x1 = i, y1 =j;
				else if (map[i][j] == 'T')
					x2 = i, y2 = j;
			}
		}
		q[0].x = x1;
		q[0].y = y1;
		dis[x1][y1] = 0;
		h = t = 0;
		while(h <= t){
			/* for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++)
					printf("%d ", dis[i][j]);
				printf("\n");
			}*/
			for (int d = 0; d < 4; d++){
				x1 = q[h].x + fx[d][0];
				y1 = q[h].y + fx[d][1];
				if (0 <= x1 && 0 <= y1 && x1 < n && y1 < m){
					if ((map[x1][y1] == 'E' || map[x1][y1] == 'T') && dis[q[h].x][q[h].y] + 1 < dis[x1][y1]){
						dis[x1][y1] = dis[q[h].x][q[h].y] + 1 ;
						t++;
						q[t].x = x1;
						q[t].y = y1;
					}
					if (map[x1][y1] == 'B'&& dis[q[h].x][q[h].y] + 2 < dis[x1][y1]){
						dis[x1][y1] = dis[q[h].x][q[h].y] + 2 ;
						t++;
						q[t].x = x1;
						q[t].y = y1;
					}
				}
			}
			h++;
		}
		if (dis[x2][y2] == INT_MAX)
			printf("-1\n");
		else printf("%d\n", dis[x2][y2]);

	}
}