#include <iostream>  
#include <cstring>
#include <cassert>
#include <vector>
using namespace std;
#define getI(a) scanf("%d", &a)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define ll long long
#define MOD 1000000007
#define maxL 100009
vector<ll> fac[maxL];
ll added[maxL];
ll L[501], LT[501];
ll T,n, minL;
void calcFactors(){
    F(i,1,maxL){
        ll j = i+i;
        while(j < maxL){
            fac[j].push_back(i);
            j += i;
        }
    }
}
void pp(int num){
    F(i,0,fac[num].size()){
        cout << fac[num][i] << endl;
    }
}
ll calc(ll num){
    ll res = 1;
    F(i,0,n) res = res * (L[i]/num) % MOD;
    return res;
}
int main ( int argc, char *argv[] ) {
    calcFactors();
    cin >> T;
    while(T--){
        minL = maxL;
        cin >> n;
        F(i,0,n) {
            cin >> L[i];
            minL = min(minL, L[i]);
        }
        clr(added, 0);
        ll sum = 0;
        FE(num,1,minL){
            ll Added = 0;
            F(i,0,fac[num].size())
                Added += added[fac[num][i]];
            added[num] = num - Added;
            sum = (sum + added[num] * calc(num)) % MOD;
        }
        cout << sum << endl;
    }
    return 0;
}


