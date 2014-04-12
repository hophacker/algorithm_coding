/*
 * =====================================================================================
 *
 *       Filename:  381A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 10:32:47 AM
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
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int N;
    int a[1000], L, R, A = 0, B = 0;
    bool isA = true;
    getI(N);
    F(i,0,N) getI(a[i]);
    L = 0;
    R = N-1;
    while(L <= R){
        if (a[L] < a[R]){
            if (isA) A += a[R]; else B += a[R];
            R--;
        }else {
            if (isA) A += a[L]; else B += a[L];
            L++;
        }
        isA = !isA;
    }
    cout << A << ' ' << B << endl;
}


