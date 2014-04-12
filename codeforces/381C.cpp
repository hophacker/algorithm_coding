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
#define abs(x) (x<0?-x:x)
#define IN(i,lct,r) (l<i&&i<r)
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
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define ll long long
#define ui unsigned int
#define us unsigned short
struct node{
    ll type, l, c;
}act[100011];
ll want[100011];
ll wanti = 0;
ll num[100011];
ll numN = 0, total = 0;
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    ll m, n;
    cin >> m;
    F(i,0,m) {
        cin >> act[i].type;
        if (act[i].type == 1) cin >> act[i].l;
        else cin >> act[i].l >>  act[i].c;
    }
    cin >> n;
    F(i,0,n) cin >> want[i];
    F(i,0,m){
        ll l = act[i].l;
        ll c = act[i].c;

        if (act[i].type == 1){
            total++;
            if (numN < 100010)
                num[numN++] = l;
            if (wanti < n && want[wanti] == total){
                cout << l <<  (wanti == n-1? '\n':' ');
                wanti++;
            }
        }else{
            F(j,0,l*c)
                if (numN < 100010) num[numN++] = num[j % l];
                else break;

            while(wanti < n && want[wanti] <= total+ l*c){
                cout << num[(want[wanti]-total-1) % l] <<  (wanti == n-1? '\n':' ');
                wanti++;
            }
            total += l * c;
        }
    }
}

