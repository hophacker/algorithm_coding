/*
 * =====================================================================================
 *
 *       Filename:  4.cc
 *
 *    Description:  Sum Of Primes
 *
 *        Version:  1.0
 *        Created:  01/03/2014 08:32:46 PM
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

vector<bool> selectPrimes(int maxN){
    vector<bool> p(maxN, true);
    p[0] = p[1] = false;
    int i = 2;
    while(i < maxN){
        while(!p[i] && i < maxN) i++;
        int j = i + i;
        while(j < maxN){
            p[j] = false;
            j+= i;
        }
        i += 1;
    }
    return p;
}
/* 
 * Get primes smaller than maxN(<maxN).
 * Return an int array which contains all primes smaller than maxN.
 */
vector<int> getPrimes(int maxN){
    vector<bool> p = selectPrimes(maxN);
    vector<int> pInt;
    for (ui i = 0; i< p.size(); i++) 
        if (p[i]) pInt.push_back(i);
    return pInt;
}
int main ( int argc, char *argv[] ) {
    vector<int> p = getPrimes(12000);
    int total = 0;
    F(i,0,1000) total += p[i];
    cout << total << endl;
    return EXIT_SUCCESS;
}
