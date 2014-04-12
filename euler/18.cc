/*
 * =====================================================================================
 *
 *       Filename:  18.cc
 *
 *    Description:  Maximum path sum I
 *
 *        Version:  1.0
 *        Created:  12/28/2013 01:33:00 AM
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
    int n;
    cin >> n;
    int a[15][15];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++){
            if (j == 0) a[i][j] += a[i-1][j];
            else if (j == i) a[i][j] += a[i-1][j-1];
            else a[i][j] += max(a[i-1][j-1], a[i-1][j]);
        }
    int maxN = 0;
    for (int j = 0; j < n; j++) maxN = max(maxN, a[n-1][j]);
    cout << maxN << endl;

}

