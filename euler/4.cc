/*
 * =====================================================================================
 *
 *       Filename:  4.cpp
 *
 *    Description:  Largest palindrome product
 *
 *        Version:  1.0
 *        Created:  12/22/2013 01:27:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "euler.h"
int main ( int argc, char *argv[] )
{
    int maxP = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = 100; j < 1000; j++){
            int n = i * j;
            if (isPalindrome(n))
                maxP = max(maxP, n);
        }
    cout << maxP << endl;
	return EXIT_SUCCESS;
}		

