#include<vector>
using namespace std;
vector<int> getCircle(vector<vector<int> >& arr){
    vector<int> res;
    if (arr.size() == 0) return res;
    int n = arr.size();
    int m = arr[0].size();
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int d = 0;
    int x = 0, y = -1;   // 0, -1
    int k;
    bool which  = true;
    while(n > 0 && m > 0){   //
        if (which) k = n, m--;
        else k = m, n--;

        which = !which;

        for (int i = 0; i < k; i++){
            x += dir[d][0], y += dir[d][1];
            res.push_back(arr[x][y]);
        }
        // change the direction
        d ++;
        if (d == 4) d = 0;
    }
}
