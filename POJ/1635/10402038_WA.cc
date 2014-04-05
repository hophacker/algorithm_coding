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
#define F(i,l,r) for (int i=l;i<=r;i++)
#define FD(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define ok1(L,R) (s1[L]=='0' && s1[R]=='1')
#define ok2(L,R) (s2[L]=='0' && s2[R]=='1')

int T, m, n;
char s1[3002], s2[3001];
int len1, len2;
struct node{
	int L, R, len;
	bool ma;
	friend bool operator<(node a, node b){
		return (a.len < b.len);
	}
};
bool match(int L1, int R1, int L2, int R2){
	vector<node> v1;
	vector<node> v2;
	if (R1-L1==1) return true;
	//L1++; L2++; R1--; R2--;
	int t = 0;
	int k = L1;
	F(i,L1,R1){
		if (s1[i] == '0') t++;
		else t--;
		if (i != L1 && t == 0){
			node tN = {k,i,i-k+1, false};
			v1.push_back(tN);
			k = i+1;
		}
	}
	if (t != 0) return false;
	k = L2;
	F(i,L2,R2){
		if (s2[i] == '0') t++;
		else t--;
		if (i != L2 && t == 0){
			node tN = {k,i,i-k+1, false};
			v2.push_back(tN);
			k = i+1;
		}
	}
	if (t != 0) return false;
	if (v1.size() != v2.size()) return false;
	int size = v1.size();
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	F(i,0,size-1) if (v1[i].len != v2[i].len || v1[i].len % 2) return false;
	t = 0;
	F(i,0,size-1){
		if (i != 0 && v1[i].len != v1[i-1].len) t = i;
		F(j,t,j<size) if (!v2[j].ma){
			if (v2[j].len != v2[t].len) return false;
			if (ok1(v1[i].L,v1[i].R) && ok2(v2[j].L,v2[j].R) && match(v1[i].L+1, v1[i].R-1, v2[j].L+1, v2[j].R-1)){
				v1[i].ma = v2[j].ma = true;
				break;
			}
		}
		if (!v1[i].ma) return false;
	}
	return true;
	return false;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	while(T--){
		getS(s1); getS(s2);
		len1 = strlen(s1); len2 = strlen(s2);
		if (len1 != len2 || len1 % 2){
			printf("different\n");
		}
		if (match(0,len1-1, 0,len2-1))
			printf("same\n");
		else 
			printf("different\n");
		
	}
}





