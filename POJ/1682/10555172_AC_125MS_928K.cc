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
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T;
int x[102], y[102], z[102];
int xN, yN, zN;
int yx[102][102], zy[102][102], xz[102][102];
int yxd[102][102], zyd[102][102], xzd[102][102];
inline int min3(int x, int y, int z){
	if (x<y) return x<z?x:z;
	else return y<z?y:z;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	while(T--){
		scanf("%d %d %d", &xN, &yN, &zN);
		FE(i,1,xN) getI(x[i]);
		FE(i,1,yN) getI(y[i]);
		FE(i,1,zN) getI(z[i]);

		FE(i,1,xN) FE(j,1,zN) xzd[i][j] = abs(x[i]-z[j]);
		FE(i,1,zN) FE(j,1,yN) zyd[i][j] = abs(z[i]-y[j]);
		FE(i,1,yN) FE(j,1,xN) yxd[i][j] = abs(y[i]-x[j]);

		xz[0][zN] = xz[1][zN+1] = 0;
		FE(i,1,xN) xz[i][zN] = xz[i-1][zN] + xzd[i][zN];
		FFE(j,zN,1) xz[1][j] = xz[1][j+1] + xzd[1][j];
		FE(i,2,xN)
			FFE(j,zN-1,1)
				xz[i][j] = min3(xz[i-1][j], xz[i][j+1], xz[i-1][j+1]) + xzd[i][j];

		zy[0][yN] = zy[1][yN+1] = 0;
		FE(i,1,zN) zy[i][yN] = zy[i-1][yN] + zyd[i][yN];
		FFE(j,yN,1) zy[1][j] = zy[1][j+1] + zyd[1][j];
		FE(i,2,zN)
			FFE(j,yN-1,1)
				zy[i][j] = min3(zy[i-1][j], zy[i][j+1], zy[i-1][j+1])+zyd[i][j];

		yx[0][xN] = yx[1][xN+1] = 0;
		FE(i,1,yN) yx[i][xN] = yx[i-1][xN] + yxd[i][xN];
		FFE(j,xN,1) yx[1][j] = yx[1][j+1] + yxd[1][j];
		FE(i,2,yN)
			FFE(j,xN-1,1)
				yx[i][j] = min3(yx[i-1][j], yx[i][j+1], yx[i-1][j+1])+yxd[i][j];

		int minV = INT_MAX;
		FE(i,1,xN)
			FE(j,1,yN)
				FE(k,1,zN){
					minV = min(minV, yx[j][i]+xz[i][k]+zy[k][j]);
					if (k!=1) 	minV = min(minV, yx[j][i]+xz[i][k]+zy[k-1][j]);
					if (i!=1) 	minV = min(minV, yx[j][i]+xz[i-1][k]+zy[k][j]);
					if (j!=1) 	minV = min(minV, yx[j-1][i]+xz[i][k]+zy[k][j]);
					if (i!=1&&j!=1) minV = min(minV, yx[j-1][i]+xz[i-1][k]+zy[k][j]);
					if (i!=1&&k!=1) minV = min(minV, yx[j][i]+xz[i-1][k]+zy[k-1][j]);
					if (j!=1&&k!=1) minV = min(minV, yx[j-1][i]+xz[i][k]+zy[k-1][j]);
					if (i!=1&&j!=1&&k!=1)
						minV = min(minV, yx[j-1][i]+xz[i-1][k]+zy[k-1][j]);
				}

		FE(j,1,yN-1)
			minV = min3(minV, zy[zN][j]+yx[j][1], zy[zN][j+1]+yx[j][1]);
		minV = min(minV, zy[zN][yN]+yx[yN][1]);
		
		FE(k,1,zN-1)
			minV = min3(minV, xz[xN][k]+zy[k][1], xz[xN][k+1]+zy[k][1]);
		minV = min(minV, xz[xN][zN]+zy[zN][1]);

		FE(i,1,xN-1)
			minV = min3(minV, yx[yN][i]+xz[i][1], yx[yN][i+1]+xz[i][1]);
		minV = min(minV, yx[yN][xN]+xz[xN][1]);

		printf("%d\n", minV);
	}

}




