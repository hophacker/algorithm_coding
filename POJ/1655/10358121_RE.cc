#include <cstdlib>
#include <limits.h>
#include <cctype>
#include <stdio.h>
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
struct node{
	int x;
	node* next;
};
int n;
node* adj[25019];
int num[25019];
int minBal[25019];
void add(int a, int b){
	node* temp = new node;
	temp->x = b;
	temp-> next = adj[a];
	adj[a] = temp;
}
int DFS(int x, int fx){
	node* t = adj[x];
	num[x] = 1;
	while(t != NULL){
		if (t->x != fx)
			num[x] += DFS(t->x, x);
		t = t->next;
	}
	t = adj[x];
	int maxB = n-num[x];

	while(t != NULL){
		if (t->x != fx && num[t->x] > maxB) maxB = num[t->x];
		t = t->next;
	}
	minBal[x] = maxB;
	return num[x];
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//ifstream cin("in.txt");
	int t, a, b, minB, minI;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i < n; i++){
			cin >> a >> b;
			//scanf("%d %d", &a, &b);
			add(a, b);
			add(b, a);
		}
		DFS(1, 0);
		minB = minBal[1];
		minI = 1;
		for (int i = 2; i <= n; i++)
			if (minBal[i] < minB){
				minB = minBal[i];
				minI = i;
			}
		cout << minI << ' ' << minB << endl;
	}
}