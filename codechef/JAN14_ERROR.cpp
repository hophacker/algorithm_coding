#include<cmath>
#include<vector>
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
#define clr(a,x) memset(a,x,sizeof(x))
//new

#define ll long long
#define ui unsigned int
#define us unsigned short
int main ( int argc, char *argv[] ) {
    int T;
    char s[100009];
    scanf("%d\n", &T);
    while(T--){
        scanf("%s", s);
        int i = 0;
        bool p = false;
        while(s[i]){
            if (s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1' || s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0'){
                printf("Good\n");
                p = true;
                break;
            }
            i++;
        }
        if (!p) printf("Bad\n");
    }
    return EXIT_SUCCESS;
}
