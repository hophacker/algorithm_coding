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
#include <string.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define F(i,l,r) for (int i=l;i<r;i++)
#define D(i,l,r) ((l<=i)&&(i<=r))
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	int L;
	char map[102][102];
	char s[102];
	int len;
	scanf("%d\n", &L);
	F(i,0,L)
		scanf("%s", map[i]);
	bool NO, exists;
	int dir, dx, dy;
	while(scanf("%s", s), s[0]!='0'){
		len = strlen(s);
		exists = false;
		F(i,0,L){
			F(j,0,L) if(map[i][j] == s[0]){
				F(d,0,8){
					dx = dy = 0;
					NO = false;
					F(k,1,len){
						dx += fx[d][0];
						dy += fx[d][1];
						if (!(D(i+dx,0,L-1) && D(j+dy,0,L-1) && map[i+dx][j+dy] == s[k])){
							NO = true;
							break;
						}
					}
					if (!NO){
						dir = d;
						break;
					}
				}
				if (!NO){
					exists = true;
					printf("%d,%d %d,%d\n", i+1, j+1, i+fx[dir][0]*(len-1)+1, j+fx[dir][1]*(len-1)+1);
					break;
				}
			}
			if (exists == true) break;
		}
		if (!exists) printf("Not found\n");
	}
}



