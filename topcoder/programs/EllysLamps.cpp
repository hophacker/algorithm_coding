#include <sstream>
/*
*/
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
// END CUT HERE
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
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
#define clr(a,x) memset(a,x,sizeof(x))
#define ll long long
#define ui unsigned int
#define us unsigned short
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class EllysLamps
{
    public:
        int getMin(string lamps)
        {
            int n = lamps.length();
            vector<int> f(n+1,0);
            for (int i = 2; i <= n; i++){
                f[i] = max(f[i-1], (lamps[i-1] != lamps[i-2]) + f[i-2]);
                if (i >= 3 && (lamps[i-1] == 'Y' && lamps[i-2] == 'Y' && lamps[i-3] == 'Y')){
                    f[i] = max(f[i], 1 + f[i-3]);
                }
            }
            return f[n] ;
        }

        

// END CUT HERE

};
