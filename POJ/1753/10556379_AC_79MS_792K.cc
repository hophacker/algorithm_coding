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
struct node{
	int s;
	int step;
};
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool board[4][4];
bool pan[65536];
int T, m, n;
int bti(){
	int s = 0;
	F(i,0,4)
		F(j,0,4)
			s = s*2+board[i][j];
	return s;
}
int itb(int s){
	FFE(i,3,0)
		FFE(j,3,0){
			board[i][j] = s % 2;
			s /= 2;
		}
}
void flip(int x, int y){
	int x1, y1;
	F(d,0,4){
		x1 = x + fx[d][0];
		y1 = y + fx[d][1];
		if (D(x1,0,3) && D(y1,0,3))
			board[x1][y1] = !board[x1][y1];
	}
	board[x][y] = !board[x][y];
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	char ss[5];
	clr(pan, 0);
	F(i,0,4){
		getS(ss);
		F(j,0,4)
			board[i][j] = (ss[j]=='b'?0:1);
	}
	queue<node> q;
	int s = bti();
	node h, t;
	t.s = s;
	t.step = 0;
	q.push(t);
	pan[s] = true;
	while(!q.empty()){
		h = q.front();
		if (h.s == 0 || h.s == 65535) break;
		q.pop();
		itb(h.s);
		F(i,0,4)
			F(j,0,4){
				flip(i,j);
				s = bti();
				if (!pan[s]){
					pan[s] = true;
					t.s = s;
					t.step = h.step+1;
					q.push(t);
				}
				flip(i,j);
			}
	}
	if (q.empty())
		printf("Impossible\n");
	else{
		printf("%d\n", h.step);
	}

}




