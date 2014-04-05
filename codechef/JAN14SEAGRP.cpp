#include <cmath>
#include <vector>
#include <map>
//new
#include <queue>
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
int total = 0;
vector<int> link[101];
bool vis[101];
int n, m, match[101];


bool find(int u){
    vis[u] = 1;
    F(i,0,link[u].size()){
        int v = link[u][i];
        if (vis[v]) continue;
        int w = match[v];
        vis[v] = 1;
        if (w){
            if (!vis[w] && find(w)){
                match[u] = v;
                match[v] = u;
                return true;
            }
        }else{
            match[v] = u;
            match[u] = v;
            return true;
        }
        vis[v] = 0;
    }
    vis[u] = 0;
    return false;
}
int main ( int argc, char *argv[] ) {
    int T;
    getI(T);
    while(T--){
        getII(n,m);
        FE(i,1,n) link[i].clear();
        clr(match,0);
        int u, v, cnt = 0;
        F(i,0,m){
            getII(u,v);
            link[u].push_back(v);
            link[v].push_back(u);
        }
        if (n % 2){
            printf("NO\n");
            continue;
        }
        FE(i,1,n) if (!match[i]){
            clr(vis,0);
            if (find(i)) cnt++;
            else break;
        }
        if (cnt == n/2) printf("YES\n");
        else printf("NO\n");
    }
    return EXIT_SUCCESS;
}


