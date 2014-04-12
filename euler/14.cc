/*
 * =====================================================================================
 *
 *       Filename:  14.cc
 *
 *    Description:  Longest Collatz sequence
 *
 *        Version:  1.0
 *        Created:  12/27/2013 02:15:24 AM
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
#define rule(n) (n%2?3*n+1:n/2)
int num[maxN+1];
int maxStep = 1, maxStart = 1;

int steps(ll n){
    if (n > maxN){
        return steps(rule(n))+1;
    }else{
        if (num[n] != -1) return num[n];
        else return (num[n] = steps(rule(n)) + 1);
    }
}
int main(){
    memset(num, -1, sizeof(num));
    num[1] = 1;
    for (ll i = 2; i <= maxN; i++){
        if (num[i] == -1) steps(i);
        printf("%d: %d\n", i, num[i]);
        if (num[i] > maxStep){
            maxStep = num[i];
            maxStart = i;
        }
    }
    cout << maxStart << endl;
}

