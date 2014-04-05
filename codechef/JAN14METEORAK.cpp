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
#define maxN 1002
int q[maxN], w[maxN];
int area[maxN][maxN], blk[maxN][maxN];

int N,M,K,x,y;
void pr(){
    FE(i,1,N) {
        FE(j,0,M) cout << blk[i][j] << ' ';
        cout << endl;
    }
}
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    getIII(N,M,K);
    clr(blk,0);
    clr(area,0);
    F(i,0,K){ 
        getII(x,y); area[x][y] = 1; 
    }
    FE(x,1,N) FE(y,1,M)
        area[x][y] = (area[x][y]==1? 0: area[x-1][y]+1);
    FE(i,1,N){
        int top = 0;
        q[top] = -1;
        //calculate max width
        FE(j,1,M+1){
            int h = area[i][j];
            if (h > q[top])
                q[++top] = h,  w[top] = 1;
            else{
                int cnt = 0;
                while(h <= q[top]){
                    blk[i][q[top]] = max(blk[i][q[top]], cnt+w[top]);
                    cnt += w[top--];
                }
                q[++top] = h;
                w[top] = cnt+1;
            }
        }
        FFE(t,i-1,1) blk[i][t] = max(blk[i][t], blk[i][t+1]);
        //calculate max block
        FE(t,1,i) blk[i][t] = blk[i][t] * t;
        FE(t,2,i) blk[i][t] = max(blk[i][t], blk[i][t-1]);

        FE(t,2,i) blk[i][t] = max(blk[i][t], blk[i-1][t-1]);
    }

    int Q, L, H;
    getI(Q);
    while(Q--){
        getII(L,H);
        printf("%d\n", blk[H][H-L+1]);
    }
    return EXIT_SUCCESS;
}




