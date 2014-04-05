/*
 * =====================================================================================
 *
 *       Filename:  19.cpp
 *
 *    Description:  Bit Positions
 *
 *        Version:  1.0
 *        Created:  01/03/2014 10:51:40 PM
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
    int n, b, c;
    while(fscanf(file, "%d,%d,%d", &n, &b, &c) != EOF){
        if (!(bit(n,b-1) > 0 ^ bit(n,c-1) > 0))  printf("true\n");
        else printf("false\n");
    }
    return EXIT_SUCCESS;
}
