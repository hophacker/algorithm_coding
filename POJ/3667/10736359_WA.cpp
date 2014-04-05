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
#define maxN 50100
#define ii i+i
#define ii1 i+i+1
struct node{
	int sta;
	int LS, RS, MS;
}seg[maxN*2];
void build(int i, int L, int R){
	seg[i].LS = seg[i].RS =  seg[i].MS = R-L+1;
	seg[i].sta = -1;
	if (L==R) return;
	else{
		int mid = (L+R)/2;
		build(i*2,L,mid);
		build(i*2+1,mid+1,R);
	}
}
int query(int i, int L, int R, int len){
	if (L==R) return L;
	int mid = (L+R)/2;
	if (seg[ii].MS >= len) return query(ii,L,mid,len);
	else if (seg[ii].RS+seg[ii1].LS >= len) return mid-seg[ii].RS+1;
	else return query(ii1,mid+1,R,len);
}
void update(int i, int L, int R, int a, int b){
	int mid = (L+R) /2;
	if (a>R || b<L) return;
	if (a<=L && R<=b) {
		seg[i].LS= seg[i].RS= seg[i].MS = 0;
		if (seg[i].sta==-1) seg[i].sta = 1;
		else{
			update(ii,L,mid,a,b);
			update(ii1,mid+1,R,a,b);
		}
		return;
	}else{
		update(ii, L,mid,a,b);
		update(ii1,mid+1,R,a,b);

		seg[i].LS=(seg[ii].LS==mid-L+1)?seg[ii].LS+seg[ii1].LS:seg[ii].LS;
		seg[i].RS=(seg[ii1].RS==R-mid)?seg[ii].RS+seg[ii1].RS:seg[ii1].RS;
		seg[i].MS = max(seg[ii].RS+seg[ii1].LS, 
						max(max(seg[i].LS, seg[i].RS),
							max(seg[ii].MS, seg[ii1].MS)));
		seg[i].sta = 0;
	}
}
void del(int i, int L, int R, int a, int b){
	int mid = (L+R)/2;
	if (a>R || b<L) return;
	if (a<=L && R<=b) {
		seg[i].LS= seg[i].RS= seg[i].MS = R-L+1;
		if (seg[i].sta == 1 || L==R) seg[i].sta = -1;
		else{
			del(ii,L,mid,a,b);
			del(ii1,mid+1,R,a,b);
		}
		return;
	}else{
		del(ii, L,mid,a,b);
		del(ii1,mid+1,R,a,b);
		seg[i].LS=(seg[ii].LS==mid-L+1)?seg[ii].LS+seg[ii1].LS:seg[ii].LS;
		seg[i].RS=(seg[ii1].RS==R-mid)?seg[ii].RS+seg[ii1].RS:seg[ii1].RS;
		seg[i].MS = max(seg[ii].RS+seg[ii1].LS, 
						max(max(seg[i].LS, seg[i].RS),
							max(seg[ii].MS, seg[ii1].MS)));
		seg[i].sta = 0;
	}
}
int main(){
	int m, n, L, R;
	//freopen("in", "r", stdin);
	getII(n,m);
	int type;
	build(1,1,n);
	while(m--){
		getI(type);
		if(type == 1){
			getI(L);
			if (seg[1].MS >= L){
				int p = query(1,1,n,L);
				cout << p << endl;
				update(1,1,n,p,p+L-1);
			}else cout << 0 << endl;
		}else{
			getII(L,R);
			del(1,1,n,L,L+R-1);
		}
	}
}

/*
 *
	}else{
		if (seg[ii1].MS >= len) return query(ii1,mid+1,R,len,true);
		else if (seg[ii].RS+seg[ii1].LS >= len){
			return query(ii1,mid+1,R,len-seg[ii].RS,true);
		}
		else return query(ii,L,mid,len,false);
 */

