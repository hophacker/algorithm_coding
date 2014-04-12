/*
 * =====================================================================================
 *
 *       Filename:  379C.cc
 *
 *    Description:  New Year Ratings Change
 *
 *        Version:  1.0
 *        Created:  12/30/2013 10:52:38 AM
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
//new
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

struct present{
    int pos;
    int val;
}a[300009];
bool cmpVal(const present &a, const present &b){
    return a.val < b.val;
}
bool cmpPos(const present &a, const present &b){
    return a.pos < b.pos;
}
int main ( int argc, char *argv[] ) {
    int n;
    scanf("%d", &n);
    F(i,0,n) {
        a[i].pos = i;
        scanf("%d", &a[i].val);
    }
    sort(a, a+n, cmpVal);
    int value = 0;
    F(i,0,n) {
        if (a[i].val > value) value = a[i].val;
        else a[i].val = value;
        value++;
    }
    sort(a, a+n, cmpPos);
    F(i,0,n){
        if (i == 0) printf("%d", a[i].val);
        else printf(" %d", a[i].val);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
