#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <iostream>  
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int startX, startY, endX, endY, total, n, m, ways;
vector<vector<int> >  a;

void search(int xx, int yy, int count){
    for (int d = 0; d < 4; d++){
        int x = xx + fx[d][0];
        int y = yy + fx[d][1];
        if (0 <= x  && x < n && 0 <= y  && y < m){
            if (count == total && a[x][y] == 3) ways++;
            else if(a[x][y] == 0){
                a[x][y] = 1;
                search(x, y, count+1);
                a[x][y] = 0;
            }
        }
    }
}
int main ( int argc, char *argv[] ) {
    cin >> n >> m;
    a = vector<vector<int> >(n, vector<int>(m));
    total = 0;
    ways = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            if (a[i][j] == 0) total++;
            else if (a[i][j] == 2) startX = i, startY = j;
            else if (a[i][j] == 3) endX = i, endY = j;
        }
    search(startX, startY, 0);
    cout << ways << endl;
    return EXIT_SUCCESS;
}
