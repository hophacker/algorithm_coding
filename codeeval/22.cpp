/*
 * =====================================================================================
 *
 *       Filename:  22.cpp
 *
 *    Description:  Fibonacci series
 *
 *        Version:  1.0
 *        Created:  01/03/2014 11:15:08 PM
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
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(a,x) memset(a,x,sizeof(x))

#define ll long long
#define ui unsigned int
#define us unsigned short
using namespace std;
int main ( int argc, char *argv[] ) {
    FILE* file = fopen(argv[1], "r");
    int a[1000];
    a[0] = 0; a[1] = 1;
    for(int i = 2;; i++){
        a[i] = a[i-1] + a[i-2];
        if (a[i] < 0) break;
    }
    int n;
    while(fscanf(file, "%d", &n) != EOF){
        printf("%d\n", a[n]);
    }
    return EXIT_SUCCESS;
}
