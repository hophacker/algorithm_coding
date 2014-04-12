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
#define min(a,b) (a<b?a:b)
#define F(i,l,r) for (int i=l;i<r;i++)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
int jie[11];
int pla[11];
int n, m, T;
int total;
void search(int de, int up, int m){
	if (de == n && m == 0){
		total ++;
		return;
	}

	if (m == 0) search(de+1, 0, 0);
	else{
		F(i,1,min(up,m)+1)if ((n-de)*i >= m){
			pla[de] = i;
			search(de+1, i, m-i);
		}
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	jie[0] = 1;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &m, &n);
		total = 0;
		search(0, 11, m);
		printf("%d\n", total);
	}
}