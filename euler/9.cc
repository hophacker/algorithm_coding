/*
 * =====================================================================================
 *
 *       Filename:  9.cc
 *
 *    Description:  Special Pythagorean triplet
 *
 *        Version:  1.0
 *        Created:  12/23/2013 01:07:10 AM
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
    for (int a = 1; a < 333; a++)
        for (int b = a+1; b < (1000-a)/2; b++)
            if (a*a + b*b == (1000-a-b) * (1000-a-b)){
                cout << a * b * (1000-a-b) << endl;
            }
    return EXIT_SUCCESS;
}
