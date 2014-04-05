/*
 * =====================================================================================
 *
 *       Filename:  2.cc
 *
 *    Description:  PRIME PALINDROME
 *
 *        Version:  1.0
 *        Created:  01/03/2014 08:17:57 PM
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
using namespace std;

bool isPalindrome(int n){
    int d[10];
    int dN = 0;
    while (n > 0){
        d[dN++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < dN/2; i++){
        if (d[i] != d[dN-1-i]) return false;
    }
    return true;
}
bool isPrime(int x){
    for (int i = 2; i <= (int)sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}
int main ( int argc, char *argv[] ) {

    int res = 2;
    FE(i,2,1000){
        if (isPalindrome(i) && isPrime(i)) 
            res = max(i, res);
    }
    cout << res << endl;
    return EXIT_SUCCESS;
}



