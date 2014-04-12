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
#define F(i,l,r) for (int i=l;i<r;i++)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
struct node{
	int x;
	int n;
	friend bool operator<(node a, node b){
		return a.n > b.n;
	}
};
int getMax(int * link, int n){
	int m = 0, p = -1;
	F(i,0,n)
		if(link[i] > m)
			p = i, m = link[i];
	return p;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	int T, n, link[11], tl, p;
	bool map[11][11];
	scanf("%d", &T);
	while(T--){
		memset(map, 0, sizeof(map));
		scanf("%d", &n);
		tl = 0;
		F(i,0,n) scanf("%d", &link[i]), tl += link[i];
		if (tl % 2 == 1){
			printf("NO\n");
			continue;
		}
		while(true){
			p = getMax(link, n);
			if (p == -1) {
				printf("YES\n");
				F(i,0,n)
					F(j,0,n)
						if(j < n-1) printf("%d ", map[i][j]);
						else printf("%d\n", map[i][j]);
				break;
			}else{
				F(i,0,n) if(i != p && link[i]>0){
					if (link[p] <= 0) continue;
					link[i]--;
					link[p]--;
					map[i][p] = map[p][i] = 1;
				}
				if (link[p] > 0){
					printf("NO\n");
					break;
				}
			}
		}
		if (T!=0) printf("\n");
	}
}




