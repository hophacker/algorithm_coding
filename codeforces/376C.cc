/*
 * =====================================================================================
 *
 *       Filename:  376C.cc
 *
 *    Description:  Divisible by Seven
 *
 *        Version:  1.0
 *        Created:  12/30/2013 12:07:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */



#include<cmath>
#include<vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <cstring>
#include <cassert>
//new
#include <string.h>
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
//new
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n));
#define clr(a,x) memset(a,x,sizeof(x))
#define ll long long
#define ui unsigned int
#define us unsigned short
using namespace std;

int main ( int argc, char *argv[] ) {
/*  
    int d[4] = {1,6,8,9};
    F(i,0,4)
        F(j,0,4) if (i != j)
            F(k,0,4) if (k != i && k != j)
                F(l,0,4) if (l != i && l != j && l != k){
                    cout << d[i] << d[j] << d[k] << d[l] << ' ' 
                        << (d[i]*1000+d[j]*100+d[k]*10+d[l]) % 7 << endl;
                }
*/
        
    char s[1000002];
    int suff[7] = {1869,1968, 1689, 6198 , 1698 , 1986 , 1896 };
    int d[10];
    clr(d,0);
    scanf("%s", s);
    ui len = strlen(s);

    F(i,0,len) d[s[i]-'0'] ++;
    d[1]--; d[6]--; d[8]--; d[9]--;

    int m = 0;
    if (d[0]+4 == len){
        cout << suff[0];
        F(i,0,d[0]) cout << 0;
    }else{
        FFE(i,9,0)
            F(j,0,d[i]){
                cout << i;
                m = (m * 10 + i) % 7;
            }
        F(i,0,4) m = (m * 10) % 7;
        cout << suff[(7-m)%7];
    }
    cout << endl;
    return EXIT_SUCCESS;
}
