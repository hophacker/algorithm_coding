#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
	int a, b;
};
bool cmp(const node& x, const node& y)
{
	if (x.a < y.a) return true;
	else return false;
}
int main()
{
	void turn(int x, int bit, string & result);
 	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int many[100001], manyNum = 0;
	map<int,int> match;
	node two[100001];
	
	int n;
	cin >> n;
	map<int,int>::iterator ii;
	bool flag = false;
	while (n--)
	{
		string s;
		cin >> s;
		int total = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'P')
			{
				total = total * 10 + ((s[i] - 'A')/3 + 2);
			}
			if (s[i] >= 'R' && s[i] <= 'Y')
			{
				total = total * 10 + (s[i] - 'B')/3 + 2;
			}
			if (s[i] >= '0' && s[i] <= '9')
			{
				total = total * 10 + s[i] - '0';
			}
		}
		ii = match.find(total); 
		if (ii == match.end())
		{
			manyNum++;
			match[total] = manyNum;
			many[manyNum] = 1;
		}
		else
			many[ii->second]++;
	}	
	int t = 0;
	for (ii = match.begin(); ii != match.end(); ii++)
	{
		t++;
		two[t].a = ii->first;
		two[t].b = many[ii->second];
	}
	sort(two+1, two+t+1, cmp);
	string s1, s2;
	for (int i = 1; i <= t; i++)
		if (two[i].b > 1)
		{
			flag = true;
			turn(two[i].a/10000,3,s1);
			turn(two[i].a%10000,4,s2);
			cout << s1 << "-" << s2 << " " << two[i].b << endl;
		}
	if (!flag) cout << "No duplicates." << endl; 
}
void turn(int x, int bit, string& result)
{
	result = "";
	while (x > 0)
	{
		result = static_cast<char>(x % 10+'0') + result;
		x /= 10;
	}
	int t = bit - result.length();
	for (int i = 1; i <= t; i++)
		result = '0' + result;
}
