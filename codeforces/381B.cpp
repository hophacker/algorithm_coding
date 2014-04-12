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
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define ll long long
#define ui unsigned int
#define us unsigned short
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int N;
    int a[100010];
    int b[100010], bN = 0, c[100010], cN = 1;
    getI(N);
    F(i,0,N) getI(a[i]);
    sort(a, a+N);
    int count = 1, total = 1;
    c[0] = a[0];
    F(i,1,N) {
        if (a[i] == a[i-1])
            count++;
        else count = 1;
        if (count == 2){
            b[bN++] = a[i];
            total++;
        } else if (count == 1){
            c[cN++] = a[i];
            total++;
        }
    }
    if (b[bN-1] == c[cN-1]) total--, bN--;
    cout << total << endl;
    printf("%d", c[0]);
    F(i,1,cN) printf(" %d", c[i]);
    FFE(i,bN-1,0) printf(" %d", b[i]);
    printf("\n");
    return EXIT_SUCCESS;
}
