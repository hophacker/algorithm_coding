/*
 * =====================================================================================
 *
 *       Filename:  379D.cc
 *
 *    Description:  New Year Letter
 *
 *        Version:  1.0
 *        Created:  12/30/2013 11:11:23 AM
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
#define maxN 210
using namespace std;


inline int maxAC(int b, int e, int n){
    if (b == 1 || b == 2)
        return (e == 1? (n-1)/2:(n-2)/2);
    else{
        return (e == 1? n/2: (n-1)/2);
    }
}
inline int minAC(int b, int e, int n){
    if (b == 0 && e == 1 && n == 2) return 1;
    else return 0;
}
inline void pr(int b){
    switch (b){
        case 0: cout << 'A';  break;
        case 1: cout << 'C';  break;
        case 2: cout << 'X';  break;
    }
}
inline int makeStr(int b, int e, int n, int k){
    pr(b);
    F(i,1,n-1){
        if (k){
            if (b == 0){
                pr(b=1);
                k--;
            }else pr(b=0);
        }else cout << 'X';
    }
    if (n != 1) pr(e);
    cout << endl;
}
int k, x, n, m;
bool calc(int ab, int ae, int bb, int be, int ia, int ib){
    int cb, ce, ic;
    FE(i,3,k){
        if (ae == 0 && bb == 1)
            ic = ia + ib + 1;
        else ic = ia + ib;
        if (ic > x) return false;
        cb = ab, ce = be;
        ab = bb, ae = be;
        bb = cb, be = ce;
        ia = ib, ib = ic;
    }
    return (ic == x);
}
int main ( int argc, char *argv[] ) {
    cin >> k >> x >> n >> m;
    FE(ab,0,2) FE(aet,0,2) FE(bb,0,2) FE(bet,0,2){
        int ae, be;
        if (n == 1) ae = ab; else ae = aet;
        if (m == 1) be = bb; else be = bet;
        FE(i,minAC(ab,ae,n),maxAC(ab,ae,n)) FE(j,minAC(ab,ae,n),maxAC(bb,be,m)){
            if (calc(ab,ae,bb,be,i,j)){
                makeStr(ab,ae,n,i);
                makeStr(bb,be,m,j);
                return 0;
            }
        }
    }
    cout << "Happy new year!" << endl;
    return EXIT_SUCCESS;
}
