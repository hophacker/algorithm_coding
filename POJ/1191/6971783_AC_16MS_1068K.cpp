#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int n;
double map[9][9];
double v[9][9][9][9], dp[9][9][9][9][15], v1[9][9][9];
inline double sqr(double t)
{
	return t * t;
} 
int main()
{
	//freopen("E:\\My Programs\\in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    int i, j, i1, j1, k;
    cin >> n; 
    for (i = 1; i < 9; i++)
        for (j = 1; j < 9; j++) cin >> map[i][j];
    for (k = 1; k < 9; k++)
		for (i = 1; i < 9; i++)
			for (j = i; j < 9; j++)
				v1[k][i][j] = v1[k][i][j-1] + map[k][j];
	memset(dp, 0, sizeof(dp));
	for (int cut = 0; cut < n; cut++)
		for (i = 1; i <= 8; i++)
        	for (j = 1; j <= 8; j++)
            	for (i1 = 1;  i1 <= 8; i1++)
                	for (j1 = 1; j1 <= 8; j1++)
						dp[i][j][i1][j1][cut] = 1e20;
    for (i = 1; i < 9; i++)
        for (j = 1; j < 9; j++)
            for (i1 = i;  i1 < 9; i1++)
                for (j1 = j; j1 < 9; j1++)
                {
					v[i][j][i1][j1] = v[i][j][i1][j1-1] + v1[j1][i][i1];
					dp[i][j][i1][j1][0] = sqr(v[i][j][i1][j1]); 
				//	printf("%ld %ld %ld %ld %lf\n", i, j, i1, j1, dp[i][j][i1][j1][0]);  

				}            
	for (int cut = 1; cut < n; cut++)
	{
		for (i = 1; i <= 8; i++)
        	for (j = 1; j <= 8; j++)
            	for (i1 = i;  i1 <= 8; i1++)
                	for (j1 = j; j1 <= 8; j1++) if ((i1-i+j1-j) >= cut)
                	{
						for (int x = i+1; x <= min(i1+j1-j+1-cut, i1); x++)
							dp[i][j][i1][j1][cut] = min(dp[i][j][i1][j1][cut], sqr(v[i][j][x-1][j1]) + dp[x][j][i1][j1][cut-1]);
							
						for (int y = j+1; y <= min(i1-i+j1+1-cut, j1); y++)
							dp[i][j][i1][j1][cut] = min(dp[i][j][i1][j1][cut], sqr(v[i][j][i1][y-1]) + dp[i][y][i1][j1][cut-1]);
							
						for (int x = max(i, cut-1+j-j1+i); x <= i1-1; x++)
							dp[i][j][i1][j1][cut] = min(dp[i][j][i1][j1][cut], dp[i][j][x][j1][cut-1] + sqr(v[x+1][j][i1][j1]));
							
						for (int y = max(j, cut-1+i-i1+j); y <= j1-1; y++)
							dp[i][j][i1][j1][cut] = min(dp[i][j][i1][j1][cut], dp[i][j][i1][y][cut-1] + sqr(v[i][y+1][i1][j1]));
					//	printf("%ld %ld %ld %ld %ld %lf\n", cut, i, j, i1, j1, dp[i][j][i1][j1][cut]);
					}
	}
	double t1 = pow(double(v[1][1][8][8]/(n)), 2.0);
	printf("%0.3lf\n", sqrt(dp[1][1][8][8][n-1]/(n) - t1));
}
