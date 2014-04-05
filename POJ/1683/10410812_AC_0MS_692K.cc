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
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FD(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<r))
#define bit(a,x) ((a&(1<<x))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T, m, n;
char item[8][8];
int cho[8][8];
bool use[8][8];
bool rep[7][7][7][7];
int f[49];
int q[49];
int qN;
int father(int i, int j){
	int x = i * m  + j;
	qN =  0;
	while(f[x] != x){
		q[qN++] = x;
		x = f[x];
	}
	F(i,0,qN)
		f[q[i]] = x;
	return x;
}
bool repel(int x, int y, int cus){
	F(j,0,n) if(cho[cus][j] != -1){
		if (rep[j][cho[cus][j]][x][y])
		return true;
	}
	return false;
}
bool search(int cus, int ite){
	if (cus == m) return true;
	if (cho[cus][ite] != -1) 
		if (ite == n-1)
		{	if (search(cus+1, 0)) return true;else return false;}
		else
			{if (search(cus, ite+1)) return true;else return false;}
	
	int faIte;
	int q[8];
	int qN;
	bool bad;
	F(i,0,m) if (!use[ite][i]){
		if (repel(ite,i,cus)) continue;

		faIte = father(ite, i);

		bad = false;
		F(x,0,n) if (x != ite)
			F(y,0,m)
				if (father(x, y) == faIte){
					if (repel(x,y,cus) || cho[cus][x] != y && cho[cus][x] != -1)
						bad = true;
				}
			

		if (bad)  continue;

		cho[cus][ite] = i;
		use[ite][i] = true;
		qN = 0;
		F(x,0,n) if (x != ite)
			F(y,0,m)
				if (father(x, y) == faIte){
					use[x][y] = true;
					if (cho[cus][x] == -1) q[qN++] = x;
					cho[cus][x] = y;
				}
		if (ite == n-1){
			if (search(cus+1, 0)) return true;}
		else{
			if (search(cus, ite+1)) return true;}

		F(k,0,qN){
			int x = q[k];
			int y = cho[cus][x];
			use[x][y] = false;
			cho[cus][x] = -1;
		}
		use[ite][i] = false;
		cho[cus][ite] = -1;
	}
	return false;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	int i1, j1, i2, j2;
	int fa1, fa2;
	char c;
	while(T--){
		scanf("%d %d", &n, &m);
		clr(rep, false);
		F(i,0,49) f[i] = i;
		clr(use, false);
		clr(cho, -1);
		F(i,0,n)
			scanf("%s", item[i]);
		while(scanf("%d %d %c %d %d", &i1, &j1, &c, &i2, &j2), i1!=0){
			i1--, j1--, i2--, j2--;
			if (c == 'N'){
				rep[i1][j1][i2][j2] = rep[i2][j2][i1][j1] = true;}
			else{
				fa1 = father(i1,j1);
				fa2 = father(i2,j2);
				f[fa1] = fa2;
			}
		}
		search(0,0);
		F(cus,0,m){
			F(ite,0,n)
				printf("%c", item[ite][cho[cus][ite]]);
			printf("\n");
		}
		printf("\n");
	}
}





