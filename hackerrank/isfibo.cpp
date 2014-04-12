#include <iostream>  
#include <algorithm>
#include <cstring>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define ll long long
ll a[52];
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int T;
    ll n;
    a[0] = 0; a[1] = 1;
    F(i,2,51){
        a[i] = a[i-1] + a[i-2];
    }
    cin >> T;
    while(T--){
        cin >> n;
        cout << (binary_search(a, a+51, n)?"IsFibo":"IsNotFibo") << endl;
    }
    return EXIT_SUCCESS;
}
