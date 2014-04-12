#define ll long long
#include<iostream>
#include<memory.h>
using namespace std;

ll mem[21][21][2];
void del(ll* a, int n, int k){
	for (int i = k; i <= n-1; i++)
		a[i] = a[i+1];
}
void getFirst(ll n, ll &c, int &t, int &flag){
	t = 1;
	while(mem[n][t][0] + mem[n][t][1] < c){
		c -= (mem[n][t][0] + mem[n][t][1]);
		t++;
	}
	if (mem[n][t][0] < c) {
		flag = 1;
		c -= mem[n][t][0];
	}
	else flag = 0;
}
int main()
{
	ll tests;
	ll n, c;
	int i, j, t, k, flag;
	ll a[21];
	memset(mem, 0, sizeof(mem));
	mem[1][1][0] = mem[1][1][1] = 1;
	for (n = 2; n <= 20; n++){
		for (k = 1; k <= n; k++){ 
			mem[n][k][0] = mem[n][k][1]  = 0;
			for (j = 1; j <= k-1; j++)
				mem[n][k][0] += mem[n-1][j][1];
			for (j = k; j <= n-1; j++)
				mem[n][k][1] += mem[n-1][j][0];
		}
	}
	ll total = 0;
	cin >> tests;

	while(tests--){
		cin >> n >> c;
		for (i = 1; i <= n; i++)
			a[i] = i;
		getFirst(n, c, t, flag); //be  sure it is right
					
		cout << t;
		del(a, n, t);
		for (i = n-1; i >= 1; i--){
			if (flag == 0){
				for (k = 1; k < t; k++){
					if (mem[i][k][1] < c) c -= mem[i][k][1];
					else break;
				}
				t = k;
			}else{
				for (k = t; k <= i; k++){
					if (mem[i][k][0] < c) c -= mem[i][k][0];
					else break;
				}
				t = k;
			}
			flag = 1 - flag;
			cout << ' ' << a[t];
			del(a, n, t);
		}
		cout << endl;
	}
}
	