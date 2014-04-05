#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <memory.h>
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

int D = 100000;
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//ifstream cin("in.txt");
	int N;
	int s[101], t[101];
	int dp[200001][2];
	cin >> N;
	int L = -1000*N, R = 1000*N;
	for (int i = 1; i <= N; i++)
		cin >> s[i] >> t[i];
	for (int j = L; j <= R; j++)
		dp[j+D][0] = INT_MIN;
	dp[D][0] = 0;

	for (int i = 1; i <= N; i++){

		for (int j = L; j <= R; j++)
			dp[j+D][i%2] = dp[j+D][(i-1)%2];
			
		for (int j = L; j <= R; j++)
			if (L<=j+s[i] && j+s[i]<=R && dp[j+D][(i-1)%2] != INT_MIN && dp[j+D][(i-1)%2]+t[i] >  dp[j+s[i]+D][(i-1)%2])
				dp[j+s[i]+D][i%2] = dp[j+D][(i-1)%2]+t[i];
	}
	int maxRes = 0;
	for (int j = 0; j <= R; j++)
		if (dp[j+D][N%2] >= 0 && dp[j+D][N%2] + j > maxRes){
			maxRes = dp[j+D][N%2] + j;
		}
	cout << maxRes << endl;
//	cout << dp[-5+D][1] << dp[8+D][2] << dp[3+D][2] << endl;
}