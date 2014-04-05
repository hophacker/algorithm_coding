#include<iostream>
#include<memory>
using namespace std;

inline int max(int a, int b){
		if (a > b) return a;
		else return b;
}
int main()
{
		int a[101][101];
		int line[101][101][101];
		int mm[101][101][101];
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		  for (int j = 1; j <= n; j++)
		    cin >> a[i][j];
		for (int i = 1; i <= n; i++)
		  for (int j = 1; j <= n; j++){
		    line[i][i][j] = a[i][j];
		    for (int i1 = i+1; i1 <= n; i1++)
		      line[i][i1][j] = line[i][i1-1][j] + a[i1][j];
			}
		int maxS = 0;
		for (int i = 1; i <= n; i++)
		  for (int i1 = i; i1 <= n; i1++){
					mm[i][i1][1] = max(0, line[i][i1][1]);
					maxS = max(maxS, mm[i][i1][1]);
					for (int j = 2; j <= n; j++){
						mm[i][i1][j] = max(0, mm[i][i1][j-1] + line[i][i1][j]);
						maxS = max(maxS, mm[i][i1][j]);
					}
			}
		cout << maxS << endl;
					
}
