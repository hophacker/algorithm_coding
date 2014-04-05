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
struct node{
    int sum, bX, drop, items;
    node(int s, int x, int d, int i){
        sum = s;
        bX = x;
        drop = d;
        items = i;
    }
    bool operator<(const node& rhs)const{
        int d = drop-sum;
        int drhs = rhs.drop - rhs.sum;
        if (d == drhs)
            return items > rhs.items;
        else return d < drhs;
    }
};
int a[100], b[100];
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int T,aN,bN;
    vector<node> cho;
    getIII(T,aN,bN);
    F(i,0,aN) getI(a[i]);
    F(i,0,bN) getI(b[i]);
    sort(a, a+aN);
    sort(b, b+bN);
    if (bN == 0){
        printf("%d %d\n", a[0], 0);
    }else{
        F(x,0,(1<<bN)){
            int sum = 0;
            int items = 0;
            F(i,0,bN) if (bit(x,i)){
                sum += b[i];
                items++;
            }
            int ai = 0;
            while(ai < aN && sum >= a[ai]) ai++;
            if (ai < aN)
                cho.push_back(node(sum, x, a[ai], items));
        }
        sort(cho.begin(), cho.end());
        printf("%d %d\n", cho[0].drop, cho[0].items);
        if (cho[0].items > 0){
            bool first = 1;
            F(i,0,bN) if (bit(cho[0].bX,i)){
                if (first) first = 0;
                else printf(" ");
                printf("%d", b[i]);
            }
            cout << endl;
        }

//        F(i,0,cho.size()){
//            printf("sum:%d bX:%d drop:%d items:%d\n", cho[i].sum, cho[i].bX, cho[i].drop, cho[i].items);
//        }
    }
    return EXIT_SUCCESS;
}
