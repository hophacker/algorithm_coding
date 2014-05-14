#include "euler.h"
/* 3 */
bool isPrime(int x){
    for (int i = 2; i <= (int)sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}
/* 4 */
bool isPalindrome(int n){
    int d[100];
    int dN = 0;
    while (n > 0){
        d[dN++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < dN/2; i++){
        if (d[i] != d[dN-1-i]) return false;
    }
    return true;
}
int gcdIt(int a, int b){
    int c;
    while( b != 0 ){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
/* 5 */
int gcd(int a, int b){
    if (a == 0 || b == 0) return 0;
    else if (a > b) return gcdIt(a, b);
    else return gcdIt(b, a);
}
int squareOfSum(int n){
    int a = (1+n)*n/2;
    return a * a;
}
int sumOfSquare(int n){
    return (n+1)*(2*n+1)*n/6;
}
/* 
 * Select a boolean array which indicates if i is prime by p[i].
 * Return: If p[i] == true, then i is prime; If p[i] != true, then i is not a prime.
 */
vector<bool> selectPrimes(int maxN){
    vector<bool> p(maxN, true);
    p[0] = p[1] = false;
    int i = 2;
    while(i < maxN){
        while(!p[i] && i < maxN) i++;
        int j = i + i;
        while(j < maxN){
            p[j] = false;
            j+= i;
        }
        i += 1;
    }
    return p;
}
/* 
 * Get primes smaller than maxN(<maxN).
 * Return an int array which contains all primes smaller than maxN.
 */
vector<int> getPrimes(int maxN){
    vector<bool> p = selectPrimes(maxN);
    vector<int> pInt;
    int size = 0;
    for (ui i = 0; i< p.size(); i++) 
        if (p[i]) pInt[size++] = i;
    return pInt;
}
/*
 * Get prime factors of n.
 * Return:  a vector, in each element of this vector, factor is the prime factor, 
 *          n is the times this factor in n.
 */
vector<primeFactor> getPrimeFactors(int n){
    int sqrtn = (int)sqrt(n);
    vector<int> p = getPrimes(n+1);
    vector<primeFactor> ret;
    for (ui i = 0; i < p.size() && p[i] <= sqrtn; i++)
        if (n % p[i] == 0){
            int num = 0;
            while (n % p[i] == 0){
                n /= p[i];
                num++;
            }
            ret.push_back(primeFactor(p[i], num));
        }
    if (n != 1) ret.push_back(primeFactor(n, 1));
    return ret;
}
/*
 *  Return the number of factors of n using prime table.
 */
vector<primeFactor> getPrimeFactorsPrimeTable(int n, vector<int> p){
    int sqrtn = (int)sqrt(n);
    assert(lastEle(p) >= sqrtn);
    vector<primeFactor> ret;
    for (ui i = 0; i < p.size() && p[i] <= sqrtn; i++)
        if (n % p[i] == 0){
            int num = 0;
            while (n % p[i] == 0){
                n /= p[i];
                num++;
            }
            ret.push_back(primeFactor(p[i], num));
        }
    if (n != 1) ret.push_back(primeFactor(n, 1));
    return ret;
}
/*
 *  Return the number of factors of n.
 */
int getNumOfFactors(int n){
    vector<primeFactor> p = getPrimeFactors(n);
    int ret = 1;
    for (ui i = 0; i < p.size(); i++)
        ret *= (p[i].num + 1);
    return ret;
}
/*  
 * Get the sum of all divisors of n.
 */
ll getSumOfDivisors(int n){
    vector<primeFactor> pf = getPrimeFactors(n);
    ll ret = 1;
    for (ui i = 0; i < pf.size(); i++){
        int a = 1, b = 1;
        for (int j = 0; j < pf[i].num; j++){
            b *= pf[i].factor;
            a += b;
        }
        ret *= a;
    }
    return ret;
}
/*  
 * Get the sum of all divisors of n using prime table p.
 */
ll getSumOfDivisorsPrimeTable(int n, vector<int> p){
    vector<primeFactor> pf = getPrimeFactorsPrimeTable(n, p);
    ll ret = 1;
    for (ui i = 0; i < pf.size(); i++){
        int a = 1, b = 1;
        for (int j = 0; j < pf[i].num; j++){
            b *= pf[i].factor;
            a += b;
        }
        ret *= a;
    }
    return ret;
}
/*
 * Get number of factors of n using prime Table.
 * This is used to solve some questions requiring large amount of factorings.
 */
int getNumOfFactorsPrimeTable(int n, vector<int> p){
    int ret = 1;
    for (ui i = 0; i < p.size(); i++){
        if (n % p[i] == 0){
            int num = 0;
            while (n % p[i] == 0){
                n /= p[i];
                num++;
            }
            ret *= (num+1);
        }
        if (n == 1) break;
    }
    return ret;
}

bool isLeapYear(ui n){
    return ( n%400 == 0 ) || (( n%4 == 0 )&&( n%100 ));
}

/*  
 *  This function is used to calculate y, which satisfy (x*y % p == w).
 */
ll exgcd(ll x, ll p, ll w){
    x %= p;
    w %= p;
    if (w == 0) return 0;
    return (exgcd(p, x, (x*p-w)%x) * p + w)/x;
}
