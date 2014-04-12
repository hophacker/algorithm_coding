#define ll long long 
#include<iostream>
#include<fstream>
#include<memory.h>
#include<algorithm>
using namespace std;

struct node 
{
	int x;
	node* next;
};
const int mod = 999983;
int n, k;	// n <= 100000; k <= 30
ll num;
int s[100001][31];
node* hash[1000000];
int hashNum;
void trans(ll& num, int a[31], int k)
{
	for (int i = 1; i <= k; i++)
	{
		a[i] = num % 2;
		num >>= 1;
	}
}
int hashIt(int a[31], int k)
{
	int  s = 0;
	for (int i = 2; i <= k; i++)
		s = (s + (a[i]-a[1]) * 97) % mod;
	return (s + mod) % mod;
}
bool same(int a[31], int b[31], int k)
{
	for (int i = 2; i <= k; i++)
		if ((a[i] - a[1]) != (b[i] - b[1])) return false;
	return true;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n >> k;
	memset(hash, 0, sizeof(hash));
	for (int i = 1; i <= k; i++) s[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		trans(num, s[i], k);
		for (int j = 1; j <= k; j++)
			s[i][j] += s[i-1][j];
	}
	int maxd = 0;
	hash[0] = new(node);
	hash[0]->x = 0;
	hash[0]->next = NULL;
	for (int i = 1; i <= n; i++)
	{
		hashNum = hashIt(s[i], k);		
		if (hash[hashNum] == NULL)
		{
			node* temp = new(node);
			temp->x = i;
			temp->next = hash[hashNum];
			hash[hashNum] = temp;
		}
		else
		{
			node* h = hash[hashNum];
			while (h != NULL)
			{
				if (same(s[h->x], s[i], k) && (i - h->x) > maxd)
					maxd = i - h->x;
				h = h->next;
			}
			node* temp = new(node);
			temp->x = i;
			temp->next = hash[hashNum];
			hash[hashNum] = temp;
		}
	}
	cout << maxd << endl;
}
