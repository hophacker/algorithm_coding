#include <iostream>  
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define getI(a) scanf("%d", &a)
int main ( int argc, char *argv[] ) {
    //ios_base::sync_with_stdio(0);
    int N;
    getI(N);
    printf("%d\n", (N&1)?(N*N+1)/2: N*N/2);
    F(i,0,N) F(j,0,N){
        printf("%c", ((i+j) & 1) ? '.': 'C');
        if (j == N-1) printf("\n");
    }
    return EXIT_SUCCESS;
}



