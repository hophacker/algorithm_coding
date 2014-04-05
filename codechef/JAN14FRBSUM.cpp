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
#define maxN 100002
int N,M;
//2^17= 131072
/*  inline int highBit(int a){
    int m;
    hBit(m,a);
    if (a == (1<<m)) return m;
    else return -1;
}
void calcF(){
    F(b,0,30) F(t,1,18) 
        F(i,0,N) 
            if (i + (1<<t) <= N)
                F[b][i][t]= F[b][i][t-1] || F[b][i+ (1<<(t-1))][t-1];
            else break;
    
}
bool has(int L, int R, int b){
    int d = R-L+1;
    while(d != 0){
        int hb;
        hBit(hb,d);
        if (F[b][L][hb]) return true;
        d -= (1 << hb);
        L += (1 << hb);
    }
    return false;
}*/
int seg[maxN*2], segN = 0;
int pos[maxN*2], posN = 0;
int A[maxN];
int F[18][maxN];
void prA(){
    F(i,0,posN) printf("%d ", pos[i]); cout << endl << "A:\n";
    F(i,0,N) printf("%4d", A[i]); 
    cout << endl;
}
void pr(){
    prA();
    cout << "F:\n";
    F(i,0,N) printf("%4d", i); 
    cout << endl;
    F(t,0,3){
        F(i,0,N) printf("%4d", F[t][i]); 
        cout << endl;
    }
}
void combine(int *A, int *B, int L1, int L2, int R2){
    printf("%d %d %d\n", L1, L2, R2);
    int R1 = L2;
    int L = L1;
    while(L1 < R1 && L2 < R2)
        if (B[L1] < B[L2]) A[L++] = B[L1], L1++;
        else               A[L++] = B[L2], L2++;
    if (L1 < R1)
        while(L1 < R1) A[L++] = B[L1++];
    if (L2 < R2)
        while(L2 < R2) A[L++] = B[L2++];
}
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    getI(N);
    F(i,0,N) getI(A[i]);

    getI(M);
    int L, R;
    F(i,0,M){
        getII(L,R);
        seg[segN++] = L-1;
        seg[segN++] = R;
    }
    sort(seg, seg+segN);
    map<int,int> segToPos;
    pos[posN++] = seg[0];
    F(i,1,segN){
        segToPos[seg[i]] = posN;
        if (seg[i] != seg[i-1]) pos[posN++] = seg[i];
    }
    memcpy(F[0], A, sizeof(int)*N);
    pr();
    F(i,0,posN-1) sort(F[0]+pos[i], F[0]+pos[i+1]);
    F(t,1,18) {
        if (posN < (1<<t)) break;
        F(i,0,posN-(1<<t)){
            combine(F[t], F[t-1], pos[i], pos[i+(1<<(t-1))], pos[i+(1<<t)]);
        }
    }
    pr();
    return EXIT_SUCCESS;
}
