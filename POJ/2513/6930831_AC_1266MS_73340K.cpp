#include<iostream>
#include<fstream>
#include<map>
using namespace std;

struct node
{
  int flag;
  node *p[26];  
  node()
  {
    int i;
    flag=-1;
    for(i=0;i<26;i++)
      p[i]=NULL;      
  }   
};

node* root;
int sum;
int d[500001], f[500001];
int getNum(char s[])
{
	node* r = root;
	for (int i = 0; s[i]; i++)
	{
		if (r->p[s[i]-'a'] == NULL)
			r->p[s[i]-'a'] = new node;
		r = r->p[s[i]-'a'];
	}
	if (r->flag == -1)
		r->flag = sum++;
	return r->flag;
}
int father(int u)
{
	if (f[u] != u)
		return father(f[u]);
	else return u;
}
void Union(int n1, int n2)
{
	int f1, f2;
	f1 = father(n1);
	f2 = father(n2);
	if (f1 == f2) return;
	else
	{
		if (f1 < f2)
			f[f2] = f1;
		else
			f[f1] = f2;
	}
}
map<string,int> stoi;
int main()
{	
	int n1, n2;
	char s1[20], s2[20];
	root = new(node);
	//freopen("in.txt", "r", stdin);
	for (int i = 1; i <= 500000; i++)
		f[i] = i;
	sum = 0;
	while(scanf("%s%s", s1, s2) == 2)
	{
		n1 = getNum(s1);
		n2 = getNum(s2);
		d[n1]++;
		d[n2]++;
		if (n1 != n2)
			Union(n1, n2);		
	}
	int total = 0;
	for (int i = 0; i < sum; i++)
		if (d[i] % 2) total++;
	int t = father(0);
	for (int i = 1; i < sum; i++)
		if (father(i) != t)	
		{
			printf("Impossible\n");
			return 0;
		}
	if (total < 3)
		printf("Possible\n");
	else
		printf("Impossible\n");
}
