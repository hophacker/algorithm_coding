/*
 * =====================================================================================
 *
 *       Filename:  30.cpp
 *
 *    Description:  set intersection
 *
 *        Version:  1.0
 *        Created:  01/04/2014 02:07:17 AM
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

int getArray(FILE* file, int *arr, char SEP){
    int cnt = 0, n;
    char sep;
    bool firstRead = true;
    while(fscanf(file, "%d%c", &n, &sep) != EOF){
        firstRead = false;
        *(arr+cnt) = n;
        cnt++;
        if (sep ==  SEP) break;
    }
    if (firstRead) return -1;
    else return cnt;
}
int main ( int argc, char *argv[] ) {
    FILE* file = fopen(argv[1], "r");
    int a[1000] , b[1000], aN, bN;
    for(;;){
        if ((aN = getArray(file, a, ';')) == -1)  break;
        else bN = getArray(file, b, '\n');
        int aI = 0, bI = 0;
        bool first = true;
        while(aI < aN && bI < bN){
            while(aI < aN && a[aI] < b[bI]) aI++;
            while(bI < bN && a[aI] > b[bI]) bI++;
            if (aI >= aN || bI >= bN) break;
            if (a[aI] == b[bI]) {
                if (first) first = false;
                else printf(",");
                printf("%d", a[aI]);
                aI++; bI++;
            }else if (a[aI] < b[bI]) aI++;
            else bI++;
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}





