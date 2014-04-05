#include <limits.h>
#include <iostream>  
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define getI(a) scanf("%u", &a)
#define less(a,b,c,d) (a*d<c*b)
#define ll unsigned long long
#define ui unsigned int
struct node{
    ll cost;
    ll road;
}path[501][501];
ui cost[501][501];
void gcd(ll& aa, ll& bb){
    ll c, a = aa, b = bb;
    while( b != 0 ){
        c = a % b;
        a = b;
        b = c;
    }
    aa /= a;
    bb /= a;
}
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int N;
    ll c,r, cM = 1, rM = 0;
    cin >> N;
    F(i,0,N) F(j,0,N) {
        getI(cost[i][j]);
        if (i == j) path[i][j].cost = 1, path[i][j].road = 0;
        else path[i][j].cost = cost[i][j], path[i][j].road = 1;
    }
    F(t,0,3)
    F(k,0,N) 
        F(i,0,N) if (i != k)
            F(j,0,N) if (j != i && j != k){
                c = path[i][k].cost + cost[k][j];
                r = path[i][k].road + 1;
                if (less(c,r,path[i][j].cost, path[i][j].road))
                    path[i][j].cost = c, path[i][j].road = r;
            }
    F(i,0,N) F(j,i+1,N){
        c = path[i][j].cost + path[j][i].cost;
        r = path[i][j].road + path[j][i].road;
        if (less(c,r,cM,rM)) cM = c, rM = r;
    }
    gcd(cM,rM);
    cout << cM << '/' << rM << endl;
    return EXIT_SUCCESS;
}


