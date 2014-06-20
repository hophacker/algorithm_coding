#include<iostream>
using namespace std;


int lower_bound(int A[], int n, int x){
    int L = 0, R = n-1;
    //maintain A[L-1] < x  , A[R+1] >= x
    while(L <= R){
        //A[-1] < x  , A[n] >= x
        //there exists i in (L-1..R) A[i] < x && A[i+1] >= x
        int M = (L + R) >> 1;
        if (A[M] < x) L = M+1;
        //A[-1] < x  , A[n] >= x
        //there exists i in (L-1..R) A[i] < x && A[i+1] >= x
        else R = M-1;
        //A[-1] < x  , A[n] >= x
        //there exists i in (L-1..R) A[i] < x && A[i+1] >= x
    }
    // RL(R==L-1)
    // A[L-1]...A[R], A[i] < x && A[i+1] = x
    return L;
}
int upper_bound(int A[], int n, int x){
    int L = 0, R = n-1;
    while(L <= R){
        int M = (L + R) >> 1;
        if (A[M] > x) R = M-1;
        else L = M+1;
    }
    return L;
}
int mai(){
    int A[] = {1,2,3,4,5,6,6,6,7,8};
    cout << lower_bound(A, 10, 6) << endl;
    cout << upper_bound(A, 10, 6) << endl;
}

