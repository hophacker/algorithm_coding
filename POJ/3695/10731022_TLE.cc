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
#define insert(xT,x) if (find(xT.begin(),xT.end(),x) == xT.end()) xT.push_back(x)
struct node{
	int x1, y1, x2,y2;
}rec[21];
struct node1{
	int x, y;
};
int T, m, n, xN, yN, R;
int size[41][41];
int vis[41][41];
vector<node1> num[21];
int main(){
//if you do not want to use file input stream, put "//" before ifstream
// ifstream cin("in");
	//freopen("in", "r", stdin);
	vector<int> xT;
	vector<int> yT;
	node1 T1;
	int cas = 0;
	while(getII(n,m), n != 0){
		xT.clear();
		yT.clear();
		F(i,0,21) num[i].clear();
		
		F(i,0,n){
			scanf("%d%d%d%d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
			insert(xT,rec[i].x1);
			insert(xT,rec[i].x2);
			insert(yT,rec[i].y1);
			insert(yT,rec[i].y2);
		}
		sort(xT.begin(), xT.end());
		sort(yT.begin(), yT.end());
		xN = xT.size()-1;
		yN = yT.size()-1;
		F(i,0,xN)
			F(j,0,yN){
			size[i][j] = (xT[i+1]-xT[i])*(yT[i+1]-yT[i]);
			F(k,0,n) if (rec[k].x1<=xT[i] && xT[i+1]<=rec[k].x2 && rec[k].y1<=yT[j] && yT[j+1] <= rec[k].y2){
				T1.x = i; T1.y = j;
				num[k].push_back(T1);
			}
		}
		clr(vis, -1);
		int k;
		int total;
		int x, y;
		printf("Case %d:\n", ++cas);
		F(q,0,m){
			getI(R);
			total = 0;
			while(R--){
				getI(k); k--;
				F(i,0,num[k].size()){
					x = num[k][i].x; y = num[k][i].y;
					if (vis[x][y] != q){
						total += size[x][y];
						vis[x][y] = q;
					}
				}
			}
			printf("Query %d: %d\n", q+1, total);
		}
		cout << endl;
	}
	
}


