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
#define F(i,l,r) for (int i=l;i<r;i++)
#define FF(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	int s, v;
	bool dual;
};
int n;
int a[202][202];
node near[202][202];
bool u[202][202];
void dpIt(int i, int j){
	near[i][j].s = INT_MAX-1;
	int x, y;
	F(d,0,4){
		x = i + fx[d][0];
		y = j + fx[d][1];
		if (D(x,0,n-1) && D(y,0,n-1)){
			if (near[x][y].s == INT_MAX) 
				dpIt(x,y);
			if(near[x][y].s == near[i][j].s-1)
				near[i][j].dual = true;
			else if (near[x][y].s < near[i][j].s-1)
				near[i][j] = near[x][y], near[i][j].s += 1;
		}
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	getI(n);
	F(i,0,n)
		F(j,0,n){
			getI(a[i][j]);
			if (a[i][j] == 0)
				near[i][j].s = INT_MAX;
			else{
				near[i][j].s = 0;
				near[i][j].v = a[i][j];
			}
			near[i][j].dual = false;
		}
	clr(u, 0);
	F(i,0,n)
		F(j,0,n) if(near[i][j].s == INT_MAX && a[i][j] == 0)
			dpIt(i, j);
	F(i,0,n)
		F(j,0,n){
			if(!near[i][j].dual && a[i][j] == 0)
				printf("%d", near[i][j].v);
			else 
				printf("%d", a[i][j]);
			printf(" ");
			if (j == n-1) printf("\n");
		}
}




