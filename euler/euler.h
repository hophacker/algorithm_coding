/*
A.Naming Conventions 
    1.New type(for convenience, such as "ui" for "unsigned short") 
      is written by lower case letters.
    2.New macro(such as "#define IN(i,l,r) (l<i&&i<r)") 
      is written by bigger case letters.
 */
#ifndef EULER_H
#define EULER_H
#include<cmath>
#include<vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <cstring>
#include <cassert>
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
/*These four macros are used to judge if number i is between l and r.
    (l,r): IN
    [l,r]: LINR
    [l,r): LIN
    (l,r]: INR
*/
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n));
#define ll long long
#define ui unsigned int
#define us unsigned short
using namespace std;
struct primeFactor{
    int factor;
    int num;
    primeFactor(int f, int n){
        factor = f;
        num = n;
    }
};
bool isPrime(int);
bool isPalindrome(int);
int gcd(int, int);
int squareOfSum(int);
int sumOfSquare(int);
void selectPrimes(bool*, int maxN);
vector<int> getPrimes(int maxN);
vector<primeFactor> getPrimeFactors(int n);
vector<primeFactor> getPrimeFactorsPrimeTable(int n, vector<int> p);
int getNumOfFactors(int n);
int getNumOfFactorsPrimeTable(int n, vector<int> p);
ll getSumOfDivisors(int n);
ll getSumOfDivisorsPrimeTable(int n, vector<int> p);
string spellNumber(ui number);
bool isLeapYear(ui n);
ll exgcd(ll x, ll p, ll w);
#endif
