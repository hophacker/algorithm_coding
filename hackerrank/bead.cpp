#include <iostream>  
#include <algorithm>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define ll long long
#define M 1000000007

int main ( int argc, char *argv[] ) {
    int T, n, b[10];
    ll F[31], res;
    FE(i,1,30){
        F[i] = 1;
        F(t,0,i-2) F[i] = F[i] * i % M;
    }
    cin >> T;
    while(T--){
        cin >> n;
        int sum = 0;
        F(i,0,n) {
            cin >> b[i];
            sum += b[i];
        }
        res = 1;
        F(i,0,n) res = res  * F[b[i]] % M;
        if (n > 1){
            F(i,0,n-2) res = res * sum % M;
            F(i,0,n) res = res * b[i] % M;
        }
        cout << res << endl;
    }
    return EXIT_SUCCESS;
}
