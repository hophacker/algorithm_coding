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
bool a[101][101];
int in[101], n, m;
queue<int> q;

void visit(int u){
    vis[u] = 1;
    total++;
    F(i,0,link[u].size()){
        int v = link[u][i];
        if (!vis[v]) visit(v);
    }
}
void deleteOne(){
    while(!q.empty()) q.pop();
    FE(i,1,n) if (in[i] == 1) q.push(i);

    while(!q.empty()){
        int u = q.front(); q.pop();
        if (in[u] != 1) continue;
        int v, w;
        F(i,0,link[u].size()){
            v = link[u][i];
            if (!vis[v]) break;
        }
        vis[u] = vis[v] = true;
        F(i,0,link[v].size()){
            w = link[v][i];
            if (!vis[w] && --in[w] == 1)
                q.push(w);
        }
    }
}
int main ( int argc, char *argv[] ) {
    printf("%.60f\n", 1.0/911) ;
    printf("%.60lf\n", (double)1.0/911) ;
    return EXIT_SUCCESS;
}


