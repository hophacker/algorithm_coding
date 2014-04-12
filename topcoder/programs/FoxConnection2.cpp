#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define F(i,L,R) for (ui i = L; i < R; i++)
#define FE(i,L,R) for (ui i = L; i <= R; i++)
#define FF(i,L,R) for (ui i = L; i > R; i--)
#define FFE(i,L,R) for (ui i = L; i >= R; i--)
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(arr,x) memset(arr,x,sizeof(arr))
#define ll long long
#define ui unsigned int
#define us unsigned short
#define mod 1000000007
class FoxConnection2
{
    public:
    ll F[51][51];
    ll f[51];
    ui K;
    vector<ui> link[51];
    void doTree(ui x, ui fa){
        ui size = link[x].size();
        if (x != 1 && size == 1) {
            F[x][0] = F[x][1] = 1;
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


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
