#include<cmath>
#include<vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <cstring>
#define max(a,b) (a<b?b:a)
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
#define char2Int(c) (c-'0')
#define ll long long
#define ui unsigned int
using namespace std;
struct primeFactor{
    int factor;
    int num;
    primeFactor(int f, int n){
        factor = f;
        num = n;
    }
};
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
    for (ui i = 0; i< p.size(); i++) 
        if (p[i]) pInt.push_back(i);
    return pInt;
}
/*
 * Get prime factors of n.
 * Return:  a vector, in each element of this vector, factor is the prime factor, 
 *          n is the times this factor in n.
 */
vector<primeFactor> getPrimeFactors(int n){
    vector<int> p = getPrimes(n+1);
    vector<primeFactor> ret;
    for (ui i = 0; i < p.size(); i++)
        if (n % p[i] == 0){
            int num = 0;
            while (n % p[i] == 0){
                n /= p[i];
                num++;
            }
            ret.push_back(primeFactor(p[i], num));
        }
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
 * Get number of factors of n using prime Table.
 * This is used to solve some questions requiring large amount of factorings.
 */

int getPos(char* s, int len){
    for (int i = 0; i < len; i++){
        if (s[i] == '^'){
            return i;
        }
    }
}
int main(){
    char s[1000010];
    scanf("%s", s);
    int len = strlen(s);
    ll w = 0;
    int pos = getPos(s, len);
    for (int i = 0; i < len; i++)
        if (LINR(s[i],'0','9')){
            w += (s[i] - '0') * (i-pos);
        }
    if (w == 0) cout << "balance" << endl;
    else if (w < 0) cout << "left" << endl;
    else cout << "right" <<  endl;
}
