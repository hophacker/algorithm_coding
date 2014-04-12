#include <iostream>  
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define getI(a) scanf("%d", &a)
int n;
int a[100009];
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    getI(n);
    F(i,0,n) getI(a[i]);
    sort(a, a+n);
    if (n == 1){
        printf("-1\n");
    }else{
        if(a[0] == a[n-1]){
            printf("1\n%d\n", a[0]);
        }else if (n == 2){
            int d = a[1] - a[0];
            if (d%2) printf("2\n%d %d\n", a[0]-d, a[1]+d);
            else printf("3\n%d %d %d\n", a[0]-d, a[0]+d/2, a[1]+d);
        }else{
            int d1 = -1, d2 = -1, d,
                n1 = 0, n2 = 0,
                i1 = 0, i2 = 0;
            bool p = true;
            F(i,0,n-1){
                d = a[i+1] - a[i];
                if (d1 == -1) {
                    if (d == 0){
                        p = false;
                        break;
                    }
                    d1 = d, n1 = 1, i1 = i;
                }
                else if (d1 == d) n1++;
                else if (d2 == -1) {
                    if (d == 0){
                        p = false;
                        break;
                    }
                    d2 = d, n2 = 1, i2 = i;
                }
                else if (d2 == d) n2++;
                else{
                    p = false;
                    break;
                }
            }
            if (d2 != -1 && d1 > d2){
                swap(d1, d2);
                swap(i1,i2);
                swap(n1,n2);
            }
            if (!p) printf("0\n");
            else{
                if (d2 == -1)
                    printf("2\n%d %d\n", a[0]-d1, a[n-1]+d1);
                else{
                    if (n2 == 1){
                        printf("1\n%d\n", a[i2]+d1);
                    }else printf("0\n");
                }
            }
        }
    }
    return EXIT_SUCCESS;
}




