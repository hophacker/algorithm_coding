#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(a,x) memset(a,x,sizeof(a))
#define getI(a) scanf("%llu", &a)
#define getII(a,b) scanf("%llu%llu", &a, &b)
#define getIII(a,b,c) scanf("%llu%llu%llu", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define ll long long unsigned
#define ui unsigned int
#define us unsigned short
#define N 1002

ll c;
inline ll mul(ll a, ll b){
    ll ret = 0;
    ll bit = 1;
    while(b){
        if (b & bit){
            ret = (ret + a) % c;
            b ^= bit;
        }
        a = (a << 1) % c;
        bit <<= 1;
    }
    return ret;
}
int main ( int argc, char *argv[] ) {
    int T,n, L, R, cN;
    ll num[N], a, b, p, q;
    bool ch[N];
    char s[N];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        F(i,0,n) getI(num[i]);
        getIII(a,b,c);
        getS(s);
        L = 0, R = n-1;
        p = 1, q = 0;
        cN = 0;
        F(i,0,n){
            if (s[i] == 'R'){
                swap(L,R);
            }else if (s[i] == 'M'){
                p = mul(p,b);
                q = mul(q,b);
                ch[cN++] = 1;
            }else{
                q = (q+a) % c;
                ch[cN++] = 0;
            }
            ll res = mul(num[L],p);
            res = (res + q) % c;
            cout << res << (i==n-1?'\n':' ');

            if (L < R) L++;
            else L--;
        }
    }
    return EXIT_SUCCESS;
}



