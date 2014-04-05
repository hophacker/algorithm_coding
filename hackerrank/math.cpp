#include <iostream>  
#include <cstring>
#include <cassert>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define ll long long
#define MOD 1000000007
#define maxN 1000009
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
ll R[maxN];
ll D[maxN];
ll J[maxN];
ll C(ll n, ll r){
    ll ret = 1;
    if (n-r > r) r = n-r;
    FE(i,r+1,n) ret = ret * i % MOD;
    FE(i,1,n-r) ret = ret * R[i] % MOD;
    return ret;
}
ll CC[maxN], JJ[maxN], RR[maxN];
inline ll group(ll n, ll per, ll g){
    return CC[g] * JJ[g] % MOD * RR[g] % MOD;
}
int main ( int argc, char *argv[] ) {
    int T,n,k;
    D[0] = 1; D[1] = 0; D[2] = 1;
    F(i,3,maxN) D[i] = (i-1)*(D[i-1]+D[i-2]) % MOD;
    J[0] = 1; J[1] = 1;
    F(i,2,maxN) J[i] = i * J[i-1] % MOD;

    clr(R, -1);
    F(i,1,maxN)if (R[i] == -1){
        gcd(i,MOD);
        R[i] = (x%MOD+MOD)%MOD;
        if (R[i] < maxN) R[R[i]] = i;
    }
    cin >> T;
    while(T--){
        ll res = 0;
        cin >> n >> k;
        if (k == 1){
            cout << 0 << endl;
            continue;
        }
        CC[0] = JJ[0] = RR[0] = 1;
        FE(i,1,n/k){
            CC[i] = CC[i-1] * C(n-i*k+k, k) % MOD;
            JJ[i] = JJ[i-1] * J[k-1] % MOD;
            RR[i] = RR[i-1] * R[i] % MOD;
        }
        FE(i,1,n/k){
            ll temp = group(n,k,i) * D[n-k*i];
            if (i % 2) res = (res+temp) % MOD;
            else res = (res-temp) % MOD;
        }
        cout << (res%MOD+MOD)%MOD << endl;
    }
    return 0;
}

