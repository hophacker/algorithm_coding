/*
 * =====================================================================================
 *
 *       Filename:  5.cc
 *
 *    Description:  Smallest multiple
 *
 *        Version:  1.0
 *        Created:  12/22/2013 07:10:24 PM
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
    ll c = 1;
    for (int i = 2; i <= 20; i++){
        c = c * i / gcd(c, i);
        cout << c << endl;
    }
    cout << c << endl;
}
