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
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
int t, n;
int a[13], path[13];

bool yeah;

void search(int dep, int len, int total){
	if (total == t){
		yeah = true;
		for (int i = 0; i < len; i++){
			cout << path[i];
			if (i == len-1) cout << endl;
			else cout << '+';
		}
		return;
	}
	if (dep == n) return;
	int depT = dep+1;
	while(depT < n && a[depT] == a[dep]) depT++;
	for (int i = 0; i < depT-dep; i++) path[len+i] = a[dep];
	for (int i = depT-dep; i >= 1; i--){
		if(total+a[dep]*i <= t)
			search(depT, len+i, total+a[dep]*i);
	}
	search(depT, len, total);
/*	for (int i = dep; i < n; i++)
		if (total + a[i] <= t){
			path[len] = a[i];
			search(i+1, len+1, total+a[i]);
		}*/
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//ifstream cin("in.txt");
	while (cin >> t >> n && n != 0){
		cout << "Sums of " << t << ":\n";
		yeah = false;
		for (int i = 0; i < n; i++) cin >> a[i];
		search(0, 0, 0);
		if (!yeah) cout << "NONE\n";
	}
}