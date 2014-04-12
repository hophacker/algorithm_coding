/*
 * =====================================================================================
 *
 *       Filename:  8.cc
 *
 *    Description:  Reverse words
 *
 *        Version:  1.0
 *        Created:  01/03/2014 08:43:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */



#include<cmath>
#include<stdio.h>
#include<vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cassert>
#include <ctype.h>
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

int main ( int argc, char *argv[] ) {
    FILE* file = fopen(argv[1], "r");
    char s[1000];
    while(fgets(s, 1000, file)){
        bool first = true;
        if (s[0] == 0) continue;
        int i = strlen(s) -1;
        while(i >= 0){
            while(i >= 0 && isspace(s[i])) i--;
            s[i+1] = 0;
            int j = i;
            while(j >= 0 && s[j] != ' ') j--;
            if (j != i){
                if (first) first =false;
                else printf(" ");
                printf("%s", s+j+1);
            }
            i = j;
        }
        if (!first) printf("\n");
    }
    return EXIT_SUCCESS;
}



