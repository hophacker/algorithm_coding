#include <iostream>  
#include <cstring>
#include <cassert>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define ll long long
#define MOD 1000000007
#define maxN 10
ll x, y, t, res;
int T,n,k,m,nm;
int map[9][9];
ll J[70];
void search(int x, int y, int c, int total){
    map[x][y] = c;
    if (y+1 == m){
        if (x+1 == n){
            res = (res + J[total]) % MOD;
        }else{
            FE(cT,1,total){
                if (map[x][0] == cT) continue;
                search(x+1, 0, cT, total);
            }
            if (total < k && total < nm) search(x+1, 0, total+1, total+1);
        }
    }else{
        FE(cT,1,total){
            if (c == cT) continue;
            if (x != 0 && map[x-1][y+1] == cT) continue;
            search(x, y+1, cT, total);
        }
        if (total < k && total < nm) search(x, y+1, total+1, total+1);
    }
}
int main ( int argc, char *argv[] ) {
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        nm = n * m;
        clr(map, -1);
        J[0] = 1;
        FE(i,1,min(n*m,k)) J[i] = J[i-1] * (k-i+1) % MOD;
        res = 0;
        search(0,0,1,1);
        cout << res << endl;
    }
    return 0;
}

