/*
 * =====================================================================================
 *
 *       Filename:  12.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/24/2013 01:25:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "euler.h"
int main ( int argc, char *argv[] ) {
    vector<int> primeTable = getPrimes(10000000);
    for(int i = 1;; i++){
        int n = getNumOfFactorsPrimeTable(i*(i+1)/2, primeTable);
        cout << i << ' ' << ' ' << i*(i+1)/2 << ' ' <<  n << endl;
        if (n >= 500){
            break;
        }
    }
    return EXIT_SUCCESS;
}
