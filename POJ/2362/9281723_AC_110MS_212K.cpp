#include<iostream>
#include<stdio.h>
#include <cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int sticks[20];
bool used[20];
int tests, n, sum, divi;
bool search(int pos, int left, int stickNum){
	while((sticks[pos] > left || used[pos]) && pos < n) pos++;
	if (pos == n) return false;
	if (sticks[pos] == left){
		used[pos] = 1;
		if (stickNum == 3) return true;
		else
			if (search(0, divi, stickNum+1)) return true;
		used[pos] = 0;
	}
	else{
		for (int i = pos; i < n; i++)if (!used[i]){
			used[i] = 1;
			if (search(i+1, left-sticks[i], stickNum)) return true;
			used[i] = 0;
		}
	}
	return false;
}
int main()
{
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	scanf("%d", &tests);
	while(tests--){
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &sticks[i]);
			sum += sticks[i];
		}
		if (sum % 4 != 0){
			cout << "no" << endl; continue;
		}
		memset(used, false, sizeof(used));
		divi = sum/4;
		sort(sticks, sticks + n, cmp);
		if (search(0, divi, 1)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}