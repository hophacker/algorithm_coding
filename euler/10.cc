/*
 * =====================================================================================
 *
 *       Filename:  10.cc
 *
 *    Description:  Summation of primes
 *
 *        Version:  1.0
 *        Created:  12/23/2013 01:46:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "euler.h"
#define maxN 2000000
int main ( int argc, char *argv[] ) {
    bool p[maxN+1];
    selectPrimes(p, maxN+1);
    ll total = 0;
    for (int i = 2; i <= maxN; i++)
        if (p[i]) {
            total += i;
        }

    cout << total << endl;
    return EXIT_SUCCESS;
}
