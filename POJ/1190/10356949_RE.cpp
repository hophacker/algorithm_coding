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
int minV[31];
int minSS[31];
int v, m;
int min(int a, int b){
	return a>b?b:a;
}
void search(int hL, int rL, int lev, int s, int leftV){
	int h, r;
	if (lev == 1){
		for (r = min(rL, (int)(sqrt((float)leftV)) ); r >= 1; r--){
			h = leftV/(r*r);
			if (h > hL) break;
			if (h*r*r == leftV && s+2*h*r < minS)
				minS = s+2*h*r;
		}
		return;
	}
//	if (sqrt(float(leftV/rL))*rL*2 + s > minS) return;
	if (s > minS) return;
	if (leftV < minV[lev]) return;
	if (s + minSS[lev] > minS) return;

	for (r=min(rL, (int)(sqrt((float)leftV))) ;r >= lev; r--)
		if (s+2*leftV/r < minS){
		int hMax = leftV / (r*r);
		for (h = min(hMax, hL); h >= lev; h--)
			if(leftV>r*r*h)
				search(h-1, r-1, lev-1, s+2*r*h, leftV-r*r*h);
	}
}
int main(){
	minV[0] = minSS[0] = 0;
	for (int i = 1; i <= 30; i++){
		minV[i] = minV[i-1] + i*i*i;
		minSS[i] = minSS[i-1] + 2*i*i;
	}
	cin >> v >> m;
	if (v <= 0){
		cout << 0 << endl;
		return 0;
	}
	int rMax = sqrt((float)v);
	for (int rm = rMax; rm >= m; rm--){
		int hMax = v / (rm*rm);
		for (int hm = hMax; hm >= m; hm--)
			if (v > rm*rm*hm)
				search(hm-1, rm-1, m-1, rm*rm+2*rm*hm, v-rm*rm*hm);
	}
	if (minS == INT_MAX) cout << 0 << endl;
	else cout << minS << endl;
}