#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <stdio.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair

int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char map[12][12];
int n, m, col;
int line, circle;
void search(int i, int j, int step){
	int d = map[i][j];
	map[i][j] = step;
	int i1 = i+fx[d][0], j1  = j + fx[d][1];
	if (0 <= i1 && i1 < n && 0 <= j1 && j1 < m){
		if (map[i1][j1] < 0){
			line = (-map[i1][j1])-1;
			circle = map[i1][j1] - step +1;
		}else{
			search(i1, j1, step-1);
		}
	}else{
		line = -step;
		circle = 0;
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//ifstream cin("in.txt");
	while(cin >> n >> m >> col && n != 0){
		char c;
		circle = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0;j < m; j++){
				cin >> c;
				switch (c){
					case 'S':map[i][j] = 0; break;
					case 'N':map[i][j] = 1; break;
					case 'E':map[i][j] = 2; break;
					case 'W':map[i][j] = 3; break;
				}
			}
		search(0, col-1, -1);

		if (circle == 0) printf("%d step(s) to exit\n", line);
		else printf("%d step(s) before a loop of %d step(s)\n", line, circle);
	}
}