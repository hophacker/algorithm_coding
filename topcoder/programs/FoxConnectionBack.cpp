#include <sstream>
/*
*/
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
// END CUT HERE
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (ui i = L; i < R; i++)
#define FE(i,L,R) for (ui i = L; i <= R; i++)
#define FF(i,L,R) for (ui i = L; i > R; i--)
#define FFE(i,L,R) for (ui i = L; i >= R; i--)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(arr,x) memset(arr,x,sizeof(arr))
#define ll long long
#define ui unsigned int
#define us unsigned short
#define mod 1000000007
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
const int maxN = 100 + 10;
class FoxConnection2
{
    ll F[51][51];
    ll f[51];
    ui K;
    vector<ui> link[51];
    void doTree(ui x, ui fa){
        ui size = link[x].size();
        F[x][0] = F[x][1] = 1;
        if (x != 1 && size == 1) {
            return;
        }

        F(i,0,size) if (link[x][i] != fa) doTree(link[x][i], x);

        F(i,0,size) if (link[x][i] != fa){
            clr(f,0);
            f[0] = 1;
            ui y = link[x][i];
            FE(other,0,K-1){
                FE(left,0,other)
                    f[other+1] += F[x][left+1] * F[y][other-left] % mod;
            }
            memcpy(F[x], f, sizeof(f));
        }

    }
    int ways(vector <int> A, vector <int> B, int k) {
        K = k;
        F(i,0,51) link[i].clear();
        clr(F,0);
        F(i,0,A.size()){
            link[A[i]].push_back(B[i]);
            link[B[i]].push_back(A[i]);
        }
        doTree(1,0);
        ll ret = 0;
        FE(i,1,A.size()+1) ret += F[i][k];
        return ret % mod;
    }


};
