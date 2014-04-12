#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
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
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(a,x) memset(a,x,sizeof(a))
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define ll long long
#define ui unsigned int
#define us unsigned short
const int N = 10000000;      
int prime[664579],num_prime = 0;      
int isNotPrime[N] = {1, 1};      

int a[1000002];
int seg[N>>1];

int  Insert(int i, int L, int R, int  a, int b , int cover) {
    int M = (L+R) >> 1;
    if (a > R || b < L) return 0;
    if(a <= L &&  R <= b) 
        seg[i] += cover;
    else {
        Insert(i<<1, L, M, a, b, cover);
        Insert((i<<1)+1, M+1, R, a, b, cover);
    }
} 
int Count(int i, int L, int R, int a, int b){
    int M = (L+R) >> 1;
    if (a > R || b < L) return 0;
    else if(a <= L &&  R <= b) return seg[i];
    else {
        return Count(i<<1, L, M, a, b) +  Count((i<<1)+1, M+1, R, a, b);
    }
}
int getPrime(){      
    for(long i = 2 ; i < N ; i ++)      {      
        if(! isNotPrime[i])      
            prime[num_prime ++]=i;    
        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)      
        {      
            isNotPrime[i * prime[j]] = 1;      
            if( !(i % prime[j]))  
                break;      
        }      
    }      
    //cout << num_prime << endl;
    return 0;      
} 
void add(int x){
    for (int i = 0; i < num_prime; i++){
        if (x % prime[i] == 0){
            a[i]++;
            while (x % prime[i] == 0) x /= prime[i];
        }
        if (x == 1 || prime[i]*prime[i] > x) break;
    }
    if (x != 1) {
        int *i = lower_bound(prime, prime+num_prime, x);
        a[(int)(i-prime)]++;
    }
}
inline int upper(int x){
    int a = (int)(lower_bound(prime, prime+num_prime, x) - prime);
    if (a >= num_prime) a = num_prime-1;
    return a;
}
inline int lower(int x){
    int p = (int)(lower_bound(prime, prime+num_prime, x) - prime);
    if (p >= num_prime) p = num_prime-1;
    if (prime[p] > x) p--;
    return p;
}
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    getPrime();
    num_prime = 6;
    clr(seg,0);
    clr(a, 0);
    int N,M,x;
    //cout << upper_bound(prime, prime+num_prime, 1000000000) - prime << endl;
    getI(N);
    while(N--){
        getI(x);
        add(x);
    }
    F(i,0,num_prime) if (a[i] > 0){
        Insert(1, 0, num_prime, i, i, a[i]);
    }
    getI(M);
    int L, R;
    while(M--){
        getII(L,R);
        int l = upper(L);
        int r = lower(R);
        cout << Count(1, 0, num_prime, l, r) << endl;
    }
    //cout << num_prime << endl;
    //F(i,0,20) cout << prime[i] << endl;
    return EXIT_SUCCESS;
}
