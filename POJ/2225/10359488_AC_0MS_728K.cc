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
char map[11][11][11];
int step[11][11][11];
int N;
int fx[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node{
	int i, j, s;
};
void search(int s, int i, int j, int b){
	step[s][i][j] = 0;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	char start[10];
	int s,i,j,sT,iT,jT;
	node q[1009];
	int h, t;
	while(scanf("%s %d", start, &N) != -1){
		for (int s = 0; s < N; s++)
			for (int i = 0; i < N; i++)
				scanf("%s", map[s][i]);
		
		h = t = 0;
		scanf("%d %d %d", &q[0].j, &q[0].i, &q[0].s);
		scanf("%d %d %d", &jT, &iT, &sT);

		map[q[0].s][q[0].i][q[0].j] = 'X';
		
		scanf("%s", start);
		bool attach = false;
		step[q[0].s][q[0].i][q[0].j] = 0;

		while(h <= t){
			if (q[h].s == sT && q[h].i == iT && q[h].j == jT){
				attach = true;
				break;
			}
			for (int k = 0; k < 6; k++){
				s = q[h].s + fx[k][0];
				i = q[h].i + fx[k][1];
				j = q[h].j + fx[k][2];
				if (0 <= s && 0 <= i && 0 <= j && s < N && i < N && j < N && map[s][i][j]=='O'){
					t++;
					map[s][i][j] = 'X';
					step[s][i][j] = step[q[h].s][q[h].i][q[h].j] + 1;
					q[t].i = i;
					q[t].j = j;
					q[t].s = s;
				}
			}
			h++;
		}
		if (attach)
			cout << N << ' ' << step[sT][iT][jT] << endl;
		else cout << "NO ROUTE" << endl;
	}	
}