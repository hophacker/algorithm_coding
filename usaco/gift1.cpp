/*
ID: fengjie3
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <string>
#include <map>
#include <memory.h>
using namespace std;
int main()
{
   string s;
   freopen("gift1.in", "r", stdin);
   freopen("gift1.out", "w", stdout);

   string nameOfThem[11];
   int money[11];
   memset(money, 0, sizeof(money));
   int n;
   cin >> n;
   map<string, int> stoi;
   stoi.clear();
   for (int i = 1; i <= n; i++)
   {
      cin >> s;
      nameOfThem[i] = s;
      stoi[s] = i;
   }   
   map<string, int>::iterator iter;
   while (cin >> s)
   {
      int t, m;
      cin >> t >> m;
      if (m != 0)t /= m;
      string name;
      for (int i = 1; i <= m; i++)
      {
         cin >> name;
         iter = stoi.find(name);
         money[iter->second] += t;
      }   
      iter = stoi.find(s);
      money[iter->second] -= t*m;
   }   
   for (int i = 1; i <= n; i++)
   	cout << nameOfThem[i] << " " << money[i] << endl;
  	return 0;
}   
