

#include <sstream>
#include <cmath>
#include <set>
#include <list>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define ll long long
#define ui unsigned int
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,(int)a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,(int)a[i].size())cout << a[i][j] << ' '; cout << endl;}

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
class SumAndProductPuzzle
{
    private:
        vector<int> prime;
    public:
        SumAndProductPuzzle(){
            prime = getPrimes(5000000);
        }
        bool isPrime(int x){
            vector<int>::iterator i = lower_bound(prime.begin(), prime.end(), x);
            if (i != prime.end() && *i == x) return true;
            else return false;
        }
        bool allPrimeExceptOne(int x){
            for (int i = 2; i <= sqrt(x); i++){
                if (x % i == 0){
                    if (!isPrime(x/i+i-1)){
//                        cout << "all " <<  x << ' ' << i << endl;
                        return false;
                    }
                }
            }
            return true;
        }
        bool ok(int x){
            int a = x - 1;
            if (isPrime(a)) {
//                cout << x << ' ' << a << endl;
                return false;
            }
            if (allPrimeExceptOne(a)) return true;
            else return false;
        }
        long long getSum(int A, int B)
        {
            ll cnt = 0;
            A = max(3, A);
            FE(x, A, B){
                if (ok(x)){
                    cnt += x;
                }
            }
            return cnt;
        }

        

};
