/*
ID: fengjie3
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
   freopen("beads.in", "r", stdin);
   freopen("beads.out", "w", stdout);
   int n;
   cin >> n;
   char bead[700];
   for (int i = 0; i < n; i++)
   {
   	cin >> bead[i];
   	bead[i+n] = bead[i];
	}
	int total;
	char c;
	int pos;
	int max = 0;
	for (int k = 0; k < n; k++)
	{
		c = 'w';
		for (pos = 1; pos <= n; pos++)
			if (bead[k+pos-1] != 'w')
			{
				if (c == 'w') c = bead[k+pos-1];
				if (bead[k+pos-1] != c)
					break;
			}
		total = pos-1;
		c = 'w';
		for (pos = 1; pos <= n; pos++)
			if (bead[n+k-pos] != 'w')
			{
				if (c == 'w') c = bead[k+n-pos];
				if (bead[k+n-pos] != c)
					break;
			}
		total += pos-1;
		if (total >= n) total = n;
		if (total > max) 
			max = total;
	}
	cout << max << endl;
}
