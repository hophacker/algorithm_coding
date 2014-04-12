/*
 * =====================================================================================
 *
 *       Filename:  382A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/17/2014 10:30:38 AM
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
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
    if (c <= a)
        cout << 0 << endl;
    else{
        c = c - a;
        int b1 = b;
        int m = (b < x);
        F(i,1,w){
            b = (b - x + w) % w;
            m += (b < x);
        }
        if (c > m){
            a = (c/m) * w;
            c = c % m;
        }else a = 0;
        b = b1;
        while(c > 0){
            if (b < x) c--;
            a++;
            b = (b - x + w) % w;
        }
        cout << a << endl;
    }
    return EXIT_SUCCESS;
}
