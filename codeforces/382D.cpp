/*
 * =====================================================================================
 *
 *       Filename:  382D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/17/2014 11:44:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


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
int n, m, maxS, s1, s2;
char B[2003][2003];
void search(int x, int y, int step){
    if (step > maxS)  maxS = step;
    B[x][y] = '#';
    if (0 <= x-1 && x-1 < n && 0 <= y && y <= m && B[x-1][y] == 'v'){
        search(x-1,y,step+1);
    };
    if (0 <= x+1 && x+1 < n && 0 <= y && y <= m && B[x+1][y] == '^'){
        search(x+1,y,step+1);
    };
    if (0 <= x && x < n && 0 <= y-1 && y-1 <= m && B[x][y-1] == '>'){
        search(x,y-1,step+1);
    };
    if (0 <= x && x < n && 0 <= y+1 && y+1 <= m && B[x][y+1] == '<'){
        search(x,y+1,step+1);
    };
}

void ok(int& x, int& y){
    if (0 <= x-1 && x-1 < n && 0 <= y && y <= m && B[x][y] == '^'){
        x = x-1, y = y;
        return;
    };
    if (0 <= x+1 && x+1 < n && 0 <= y && y <= m && B[x][y] == 'v'){
        x = x+1, y = y;
        return;
    };
    if (0 <= x && x < n && 0 <= y-1 && y-1 <= m && B[x][y] == '<'){
        x = x, y = y-1;
        return;
    };
    if (0 <= x && x < n && 0 <= y+1 && y+1 <= m && B[x][y] == '>'){
        x = x, y = y+1;
        return;
    };
    x = -1, y = -1;
}
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    F(i,0,n) getS(B[i]);
    s1 = 0, s2 = 0;
    F(i,0,n) F(j,0,m) if (B[i][j] == '#'){
        maxS = 0;
        search(i,j, 0);
        if (maxS > s1) s2 = s1, s1 = maxS;
        else if (maxS > s2) s2 = maxS;
    }
    bool circle = false;
    F(i,0,n) F(j,0,m) if (B[i][j] != '#' && B[i][j] != '.'){
        circle = true;
        break;
    }
    if (circle) printf("-1\n");
    else{
        if (s1 != 0 && s2 != 0) cout << s1 + s2 << endl;
        else if (s1 != 0) cout << s1 + s1 -1 << endl;
        else cout << 0 << endl;
    }
    return EXIT_SUCCESS;
}


