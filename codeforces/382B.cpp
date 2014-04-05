#include <iostream>  
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define ll long long
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    ll a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
    if (c <= a)
        cout << 0 << endl;
    else{
        c = c - a;
        ll b1 = b;
        ll m = (b >= x);
        F(i,1,w){
            b = (b - x + w) % w;
            m += (b >= x);
        }
        if (c > m){
            a = ((c-1)/m) * w;
            c = (c-1) % m + 1;
        }else a = 0;
        b = b1;
        while(c > 0){
            if (b >= x) c--;
            a++;
            b = (b - x + w) % w;
        }
        cout << a << endl;
    }
    return 0;
}
