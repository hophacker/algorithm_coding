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
int T, m, N, N1;
int a, b, ni;
int ten[11];
int getLen(int N){
	int i = 0;
	while(N > 0){
		i++;
		N /= 10;
	}
	return i;
}
struct node{
	int x,y;
	friend bool operator <(node a, node b){
		return a.x < b.x;
	}
};
node res[1000];
int rL;
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	ten[0] = 1;
	F(i,1,11) ten[i] = ten[i-1] * 10;
	//freopen("in", "r", stdin);
	getI(N1);
	int x, y;
	rL = 0;
	F(i,0,getLen(N1))
		F(j,0,10){
			N = N1 - j * ten[i];
			F(k,0,2){
				b = (N % ten[i] + k * ten[i]);
				if (b % 2 == 0){
					b /= 2;
					a = (N - b*2) / ten[i] / 11;
					if (a >= 0 && b >= 0 && a*11*ten[i]+j*ten[i]+2*b == N1){
						res[rL].x = a*ten[i+1]+j*ten[i]+b;
						res[rL].y = a*ten[i]+b;
						rL++;
					}
				}
			}
		}
	sort(res, res+rL);
	printf("%d\n", rL);
	F(i,0,rL){
		int LX = getLen(res[i].x);
		int LY = getLen(res[i].y);
		printf("%d + ", res[i].x);
		F(t,0,LX-LY-1) printf("0");
		printf("%d = %d\n",  res[i].y, N1);
	}
}













