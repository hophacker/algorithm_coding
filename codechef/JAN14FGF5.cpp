#include <cmath>
#include <map>
#include <vector>
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
#define clr(a,x) memset(a,x,sizeof(x))
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);

#define ll long long
#define ui unsigned int
#define us unsigned short
struct node{
    int s, f;
    node(int S, int F){
        s = S;
        f = F;
    }
    bool operator<(const node& b) const{
        return this->f < b.f;
    }
};

int calc(vector<node> & cus){
    sort(cus.begin(), cus.end());
    int total = 0, f = 0;
    F(i,0,cus.size())
        if (cus[i].s >= f){
            total++;
            f = cus[i].f;
        }
    return total;
}
int main ( int argc, char *argv[] ) {
    int T, n, k, s, f, p, kN;
    getI(T);
    map<int,int> M;
    vector<node> room[100000];
    while(T--){
        getII(n,k);
        M.clear();
        kN = 0;
        F(i,0,n){
            getIII(s,f,p);
            if (M.find(p) == M.end()){
                room[kN].clear();
                M[p] = kN++;
            }
            room[M[p]].push_back(node(s,f));
        }
        int total = 0;
        F(i,0,kN) total += calc(room[i]);
        cout << total << endl;
    }
    return EXIT_SUCCESS;
}


