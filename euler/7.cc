/*
 * =====================================================================================
 *
 *       Filename:  7.cc
 *
 *    Description:  10001st prime
 *
 *        Version:  1.0
 *        Created:  12/23/2013 12:08:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "euler.h"
#define maxN 1000000
int main ( int argc, char *argv[] ) {
    bool p[maxN];
    memset(p, 1, sizeof(p));
    int i = 2;
    while(i < maxN){
        while(!p[i] && i < maxN) i++;
        int j = i + i;
        while(j < maxN){
            p[j] = 0;
            j+= i;
        }
        i += 1;
    }
    int total = 0;
    for (i = 2; i < maxN; i++){
        if (p[i]) {
            total ++;
            cout << i << endl;
        }
        if (total == 10001) {
            cout << i << endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}
