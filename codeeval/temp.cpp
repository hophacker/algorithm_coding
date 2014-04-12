/*
 * =====================================================================================
 *
 *       Filename:  temp.cpp
 *
 *    Description:  temp
 *
 *        Version:  1.0
 *        Created:  01/03/2014 11:20:14 PM
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
    char s[1000], t;
    int a[10]; 
    memset(a, 0, sizeof(a));
    int b;
    while(~fscanf("%d", &b)){
        while(b){
            a[b%10]++;
            b /= 10;
        }
    }
    /* find the digits lost next */
    for (int i = 0; i < 10; i++){

    }
    /*  then rescanf the numbers in the file, determine which number lost */
    return EXIT_SUCCESS;
}





