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
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair

char map[102][102];
int n, m;
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
void spread(int i , int j){
	map[i][j] = '*';
	int i1, j1;
	for (int d = 0; d < 8; d++){
		i1 = i + fx[d][0];
		j1 = j + fx[d][1];
		if (0 <= i1 && i1 < n && 0 <= j1 && j1 < m && map[i1][j1] == '@')
			spread(i1, j1);
			
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//
	ifstream cin("in.txt");
	while (cin >> n >> m && n != 0){
		for (int i = 0; i < n; i++)
			for (int j =0; j < m; j++)
				cin >> map[i][j];
		int total = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) if (map[i][j] == '@'){
				spread(i, j);
				total++;
			}
		cout << total << endl; 
	}
	
}