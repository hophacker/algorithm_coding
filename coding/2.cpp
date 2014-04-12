#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int ways[201][8];
    int cir[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    memset(ways, 0, sizeof(ways));
    int n = 200;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 8; j++) if (i > cir[j]){
            int ii = i - cir[j];
            for (int k = 0; k <= j; k++){
                    ways[i][j] += ways[ii][k];
            }
        }else if (i == cir[j]) ways[i][j] = 1;
    }
    int sum = 0;
    for (int j= 0; j < 8; j++){
        sum += ways[n][j];
    }
    cout << sum << endl;
}
