#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <limits.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
int minS = INT_MAX;
int minV[20];
int v, m;
int min(int a, int b){
	return a>b ? b:a;
}
void search(int hL, int rL, int lev, int s, int leftV){
	if (lev == 0){
		if (leftV ==0 && s < minS) 
			minS = s;
		return;
	}
	if (sqrt(float(leftV/rL))*rL*2 + s > minS) return;
	if (s > minS) return;
	if (leftV < minV[lev]) return;


	for (int r=min(rL, (int)(sqrt((float)leftV)) ); r >= lev; r--){
		int hMax = leftV / (r*r);
		for (int h = min(hMax, hL); h >= lev; h--)
			search(h-1, r-1, lev-1, s+2*r*h, leftV-r*r*h);
	}
	
}
int main(){
	cin >> v >> m;
	int rMax = sqrt((float)v);
	minV[0] = 0;
	for (int rm = rMax; rm >= m; rm--){
		int hMax = v / (rm*rm);
		for (int hm = hMax; hm >= m; hm--)
			search(hm-1, rm-1, m-1, rm*rm+2*rm*hm, v-rm*rm*hm);
	}
	if (minS == INT_MAX) cout << 0 << endl;
	else cout << minS << endl;
}