/*
 * =====================================================================================
 *
 *       Filename:  21.cc
 *
 *    Description:  Amicable numbers
 *
 *        Version:  1.0
 *        Created:  12/29/2013 02:37:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "euler.h"
int main(){
    vector<int> p = getPrimes(10001);
    int total = 0;
    for (int i = 1; i <= 10000; i++){
        int t = getSumOfDivisorsPrimeTable(i, p)-i;
        if (i != t && t != 0 && t <= 10000 && getSumOfDivisorsPrimeTable(t, p)-t == i){
            total += t;
            cout << i << " " << t << endl;
        }
    }
    cout << total << endl; //Answer is 31626
}
