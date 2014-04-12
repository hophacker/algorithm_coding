/*
 * =====================================================================================
 *
 *       Filename:  379F.cc
 *
 *    Description:  New Year Tree
 *
 *        Version:  1.0
 *        Created:  12/30/2013 11:57:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */



#include<cmath>
#include<vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cassert>
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
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n));
#define clr(a,x) memset(a,x,sizeof(x))

#define ll long long
#define ui unsigned int
#define us unsigned short
using namespace std;


#define N 1000005
#define M 20

int dis[N], far[M][N], v;
int n, m, a = 2, b = 3, r = 2;

int query(int a, int b){
    if (dis[a] < dis[b]) swap(a,b);
    int d = dis[a] - dis[b];
    F(i,0,M) if (d&1<<i)
        a = far[i][a];
    if (a == b) return a;

    FFE(s,M-1,0)
        if (far[s][a] != far[s][b])
            a = far[s][a], b = far[s][b];
    return far[0][a];
}

int main(){
    scanf("%d", &m);
    far[0][1] = far[0][2] = far[0][3] = far[0][4] = 1;
    dis[1] = 0;
    dis[2] = dis[3] = dis[4] = 1;
    n = 4;
    F(i,0,m){
        scanf("%d", &v);
        far[0][n+1] = far[0][n+2] = v;
        dis[n+1] = dis[n+2] = dis[v]+1;
        n += 2;
    }
    F(i,1,M) F(j,1,n)
        far[i][j] = far[i-1][far[i-1][j]];
    F(i,0,m){
        int c = 5 + i * 2;
        int x = query(c, a);
        int y = query(c, b);
        int dx = dis[a]+dis[c]-2*dis[x];
        int dy = dis[b]+dis[c]-2*dis[y];
        if (dx > dy && dx > r) r = dx, b = c;
        else if (dy > r) r = dy, a = c;
        printf("%d\n", r);
    }
}




