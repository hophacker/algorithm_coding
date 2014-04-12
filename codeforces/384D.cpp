#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <queue>
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
struct node{
    int x, y;
    bool operator < (const node& r)const{
        if (x == r.x) return y < r.y;
        else return x < r.x;
    }
}vol[100000], f[2][100009];
int N,M;
int sou = 0, tar = 1;
int fn[2];
bool inIt(int X, int Y){
    int L = 0, R = fn[sou]-1, M;
    bool yes = false;
    while(L <= R){
        M = (L+R) >> 1;
        if (f[sou][M].y < X) L = M+1;
        else if (f[sou][M].x > Y) R = M-1;
        else {
            yes = true;
            break;
        }
    }
    if (yes){
        f[tar][fn[tar]].x = X;
        f[tar][fn[tar]].y = Y;
        fn[tar]++;
    }
    return yes;
}
int main ( int argc, char *argv[] ) {
    getII(N,M);
    F(i,0,M) getII(vol[i].x, vol[i].y);
    sort(vol, vol + M);
    f[0][0].x = 1;
    f[0][0].y = 1;
    fn[0] = 1;
    int i = 0, lastX = 0;
    tar = 0;
    sou = 0;
    while(i < M){
        if (fn[sou] == 0) break;
        if (lastX < vol[i].x-1){
            fn[sou] = 1;
            f[sou][0].x = 1;
            f[sou][0].y = N;
        }
        lastX = vol[i].x;
        int j = i;
        while(j < M && vol[j].x == vol[i].x) j++;

        tar = (sou+1) % 2;
        fn[tar] = 0;

        inIt(1,vol[i].y-1);
        F(k,i+1,j) inIt(vol[k-1].y+1, vol[k].y-1);
        inIt(vol[j-1].y+1, N);
        i = j;
        sou = tar;
    }
    if (fn[sou] == 0) cout << -1 << endl;
    else if (lastX < N) cout << (N-1)*2 << endl;
    else if (inIt(N,N)) cout << (N-1)*2 << endl;
    else cout << -1 << endl;
    return EXIT_SUCCESS;
}
