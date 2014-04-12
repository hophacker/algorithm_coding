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
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int T, m, n;
int total;
int lx, ly, rx, ry;
char bf[1001][1001];
void search(int x, int y){
	bf[x][y] = '.';
	total++;
	if (x < lx) lx = x; 
	if (x > rx) rx = x;
	if (y < ly) ly = y;
	if (y > ry) ry = y;
	int x1, y1;
	F(d,0,8){
		x1 = x+fx[d][0];
		y1 = y+fx[d][1];
		if (D(x1,0,n-1) && D(y1,0,m-1) && bf[x1][y1] == '#')
			search(x1,y1);
	}
}

int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int num;
	bool badP;
	while(getII(n,m), n!=0){
		num = 0;
		badP = false;
		F(i,0,n) getS(bf[i]);
		F(i,0,n){
			F(j,0,m) if(bf[i][j] == '#'){
				num++;
				rx = ry = -1;
				lx = n, ly = m;
				total = 0;
				search(i,j);
				if (total != (ry-ly+1)*(rx-lx+1)){
					badP = true;
					break;
				}
			}
			if (badP) break;
		}
		if (badP) printf("Bad placement.\n");
		else printf("There are %d ships.\n", num);
	}
}