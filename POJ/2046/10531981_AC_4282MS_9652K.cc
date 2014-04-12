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
#include <string>
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
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define bad(c) (c%10==7||c=='_')
struct node{
	int steps;
	string state;
};
int T, m, n;
string finalS; 
set<string>hash;
void initial(string &s){
	int m, p;
	F(i,0,4){
		p = s.find_first_of((char)(i*10+11));
		swap(s[p], s[8*i]);
	}
}
int main(){//.
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	F(i,0,4){
		F(j,0,7)
			finalS.push_back((char)(i*10+11+j)); 
		finalS.push_back('_');
	}
	//freopen("in", "r", stdin);
	getI(T);
	while(T--){
		int lastN;
		string s;
	 	F(i,0,4){
			s.push_back('_');
			F(j,0,7){
				getI(n);
				lastN = n;
				s.push_back((char)n);
			}
		}//.
		queue<node> q;
		node hn;
		initial(s);
			hash.clear();
			hash.insert(s);
				node temp;
				temp.steps = 0;
				temp.state = s;
				q.push(temp);
		int lastP = 0;//.
		while(!q.empty()){
			hn = q.front();
			if (hn.state == finalS) break;
			q.pop();
			hn.steps++;
			lastP = 0;//.
			F(t,0,4){
				int _p = hn.state.find_first_of('_', lastP);
				lastP = _p+1;
				//if (_p == string::npos) printf("bad\n");
				if (bad(hn.state[_p-1])) continue;
				int cp = hn.state.find_first_of(hn.state[_p-1]+1);
				swap(hn.state[_p], hn.state[cp]);
				
				if (hash.find(hn.state) == hash.end()){
					hash.insert(hn.state);
					q.push(hn);
				}
				
				swap(hn.state[_p], hn.state[cp]);
			}
		}
		if (q.empty())
			putI(-1);
		else putI(hn.steps);
	}
}















