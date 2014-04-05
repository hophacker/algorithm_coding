#include <iostream>  
#include <cstring>
#include <cassert>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define ll long long
#define MOD 1000000007
ll x, y, t;
void gcd(ll a,ll b)
{
    if(b==0) {
        x=1; y=0;
        return;
    }
    gcd(b,a%b);
    t=x;
    x=y;
    y=t-(a/b)*y;
}
ll R[2000000];
ll C(ll n, ll r){
    ll ret = 1;
    FE(i,1,n) ret = ret * i % MOD;
    FE(i,1,r) ret = ret * R[i] % MOD;
    FE(i,1,n-r) ret = ret * R[i] % MOD;
    return ret;
}
int main ( int argc, char *argv[] ) {
    int T,N,M;
    clr(R, -1);
    F(i,1,2000000)if (R[i] == -1){
        gcd(i,MOD);
        R[i] = (x%MOD+MOD)%MOD;
        if (R[i] < 2000000) R[R[i]] = i;
    }
    cin >> T;
    while(T--){
        cin >> N >> M;
        cout << C(N+M-2, N-1) << endl;
    }
    return 0;
}
