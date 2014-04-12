#include <iostream>  
#include <string.h>
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define ll long long
using namespace std;
#define maxN 1001
#define M 1000000007
int main(){
    int T, n, m;
    ll line[maxN], bl[maxN], F[maxN];
    line[0] = 1; 
    line[1] = 1;
    line[2] = 2;
    line[3] = 4;
    FE(i,4,1000) line[i] = (line[i-1] + line[i-2] + line[i-3] + line[i-4]) % M;
    cin >> T;
    while(T--){
        cin >> n >> m;
        memcpy(bl, line, sizeof(bl));
        FE(i,2,n) FE(j,1,m) bl[j] = bl[j]*line[j]%M;
        F[1] = 1;
        FE(k,2,m){
            F[k] = bl[k];
            FE(j,1,k-1) F[k] = (F[k]-F[k-j]*bl[j])%M;
        }
        cout << (F[m]+M)%M << endl;
    }
}






