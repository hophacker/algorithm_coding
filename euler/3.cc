/*
 * =====================================================================================
 *
 *       Filename:  3.cc
 *
 *    Description:  Largest prime factor
 *
 *        Version:  1.0
 *        Created:  12/22/2013 01:15:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <cmath>
#include "euler.h"
#define ll long long
using namespace std;


int main ( int argc, char *argv[] )
{
    ll n = 600851475143;
    int a[11];
    int aN = 0;
    for (ll i = 2; i <= (ll)sqrt(n); i++){
        if (n % i == 0) 
            a[aN++] = i;

    }
    for (int i = aN-1; i >= 0; i--){
        if (isPrime(a[i])) {
            cout << a[i] << endl;
            break;
        }
    }
	return EXIT_SUCCESS;
}		

