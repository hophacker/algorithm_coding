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
struct node{
	int x, y, step;
};
int fx[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//freopen("in.txt", "r", stdin);
	char ss[4], tt[4];
	node q[70];
	int map[8][8];
	int h, t, xT, yT, x,y;
	bool find;
	while(scanf("%s %s", ss, tt) != -1){
		memset(map, 0, sizeof(map));
		h = t = 0;
		map[q[0].x=ss[0]-'a'][q[0].y = ss[1]-'1'] = 1;
		q[0].step = 0;
		xT = tt[0]-'a';
		yT = tt[1]-'1';
		while(h <= t){
			if (q[h].x == xT && q[h].y == yT){
				break;
			}
			for (int d = 0; d < 8; d++){
				x = fx[d][0] + q[h].x;
				y = fx[d][1] + q[h].y;
				if (0 <= x && 0 <= y && x < 8 && y < 8 && map[x][y] == 0){
					map[x][y] = 1;
					t++;
					q[t].x = x;
					q[t].y = y;
					q[t].step = q[h].step+1;
				}
			}
			h++;
		}
		printf("To get from %s to %s takes %d knight moves.\n", ss, tt, q[h].step);
	}
}