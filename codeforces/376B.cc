/*
 * =====================================================================================
 *
 *       Filename:  376B.cc
 *
 *    Description:  B.I.O.U
 *
 *        Version:  1.0
 *        Created:  12/29/2013 10:57:40 PM
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
#include <cstring>
#include <cassert>
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define clr(a,x) memset(a,x,sizeof(a))
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n));
#define ll long long
#define ui unsigned int
#define us unsigned short
using namespace std;

int main ( int argc, char *argv[] ) {
    int n, m, a, b, c;
    int d[101];
    clr(d,0);
    cin >> n >> m; 
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        d[a] += c;
        d[b] -= c;
    }
    int total = 0;
    for (int i = 1; i <= n; i++) 
        if (d[i] > 0) total += d[i];
    cout << total << endl;
    return EXIT_SUCCESS;
}
