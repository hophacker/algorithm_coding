#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;
const int mod = 99991;
struct node
{
	int x;
	node* next;
};
int a[6];
int x1[101];
int* x = x1 + 50;
bool pan1[250001];
bool* pan = pan1 + 125000;
node* hash[mod];
void add(int x)
{
	int t = x % mod;
	if (t < 0) t += mod; 
	node* temp = new(node);
	temp->x = x;
	temp->next = hash[t];
	hash[t] = temp;
}
int search(int x)
{
	int n = 0;
	int t = x % mod;
	if (t < 0) t += mod;
	node* h = hash[t];
	while (h != NULL)
	{
		if (h->x == x) n++;
		h = h->next;
	}
	return n;
}
int main()
{
	memset(pan, false, sizeof(pan));
	memset(hash, 0, sizeof(hash));
// 	freopen("in.txt", "r",stdin);
	for (int i = 1; i <= 5; i++) 
		cin >> a[i];
	int p;
	for (p = 1; p <= 5; p++)
		if (a[p] != 0)
		{
			swap(a[5], a[p]);
			break;
		}
	if (p == 6)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = -50; i <= 50; i++) 
		x[i] = i * i * i, pan[x[i]] = true;

	int total = 0;
	int x1, x2, x3, x4, x5;
	for (x1 = 1; x1 <= 50; x1++)
		for (x2 = -50; x2 <= 50; x2++) if (x2 != 0)
			add(x[x1]*a[1] + x[x2]*a[2]);

	for (x3 = -50; x3 <= 50; x3++) if (x3 != 0)
		for (x4 = -50; x4 <= 50; x4++) if (x4 != 0)
			for (x5 = -50; x5 <= 50; x5++) if (x5 != 0)
				total += search(x[x3]*a[3] + x[x4]*a[4] + x[x5]*a[5]);
	cout << total*2 << endl;
}
