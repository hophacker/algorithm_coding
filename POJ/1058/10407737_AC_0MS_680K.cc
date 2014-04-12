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
#define FF(i,l,r) for (i=l;i<r;i++)
#define FD(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T, m, n;
bool man[16][16];
char s[20][5];
int lf[16][6];
bool ok[16];
void Failed(){
	printf("It is not possible to complete this schedule.\n\n");
}
bool setS(){
	clr(man, 0);
	int x, y;
	F(i,0,12){
		F(j1,0,4)
			F(j2,j1+1,4){
				x = s[i][j1] - 'A';
				y = s[i][j2] - 'A';
				if (man[x][y] || man[y][x]) return false;
				man[x][y] = man[y][x] = true;
			}
	}
	return true;
}
bool setLeft(){
	int LN[16];
	clr(LN, 0);
	int x, t;
	F(p,0,16){
		F(i,0,16)
			if (i != p && !man[p][i]){
				if (LN[p] == 6) 
					return false;
				lf[p][LN[p]++] = i;
			}
	}
	return true;
}
bool check(int* p){
	F(i,0,4)
		F(j,0,4) if(i!=j)
			if (man[p[i]][p[j]]) return false;
	return true;
}
bool checkAndP(){
	int t;
	bool ha[16];
	clr(ha, 0);
	int p[4];
	int m = 0;
	F(x,0,16) if(!ha[x]){
		p[0] = x;
		t = 1;
		F(i,0,6) if (!man[x][lf[x][i]]) 
			p[t++] = lf[x][i];
		if (!check(p)) return false;
		F(i,0,4){
			ha[p[i]] = true;
			s[m+16][i] = p[i] + 'A';
		}
		m++;
	}
	return true;
}
bool search(int x, int dep){
	if (x == 16){
		if (checkAndP()){
			return true;
		}else return false;
	}
	if (ok[x]) {
		if (search(x+1, dep)) return true;
		else return false;
	}

	int p[4];
	p[0] = x;

	F(i1,0,6)
		F(i2,i1+1,6)
			F(i3,i2+1,6){
				p[1] = lf[x][i1];
				p[2] = lf[x][i2];
				p[3] = lf[x][i3];
				if(ok[p[1]]||ok[p[2]]||ok[p[3]]) continue;

				if (check(p)){
					F(i,0,4){
						F(j,0,4)if(i!=j) man[p[i]][p[j]] = true;
						ok[p[i]] = true;
					}
					if (search(x+1, dep+1)){
						F(i,0,4)
							s[12+dep][i] = 'A' + p[i];
						return true;
					}
					F(i,0,4){
						F(j,0,4)if(i!=j) man[p[i]][p[j]] = false;
						ok[p[i]] = false;
					}
				}
			}
	return false;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	while(~getS(s[0])){
		F(i,1,12) getS(s[i]);
		if (!setS()){
			Failed();
			break;
		}
		//printf("%d", man[0]);
		if (!setLeft()){
			Failed();
			break;
		}
		clr(ok, 0);
		if (search(0,0)){
			F(i,0,20){
				F(j,0,4)
					printf("%c", s[i][j]);
				if (i % 4 == 3) printf("\n");
				else printf(" ");
			}
			printf("\n");
		}else{
			Failed();
		}
	}
}






