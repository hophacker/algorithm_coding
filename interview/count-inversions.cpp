/*
 * http://www.mitbbs.com/article_t/JobHunting/32708791.html
 */
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



int merge(int A[], int L, int M, int R){
    int *B = new int[R-L+1];
    int L1 = L, L2 = M+1, i = 0;
    int cnt = 0;
    while(L1 <= M && L2 <= R){
        if (A[L1] <= A[L2]){
            B[i++] = A[L1++];
            cnt += L2-(M+1);
        }else
            B[i++] = A[L2++];
    }

    if (L1 <= M){
        cnt += (M+1-L1) * (R-M);
        while(L1 <= M){
            B[i++] = A[L1++];
        }
    }else{
        while(L2 <= R){
            B[i++] = A[L2++];
        }
    }

    memcpy(A+L, B, sizeof(int)*(R-L+1));
    return cnt;
}

int count(int A[], int L, int R){
    if (L == R) return 0;
    int M = (L + R) / 2;
    int cnt = count(A, L, M) + count(A, M+1, R);
//    cout << L << ' ' << R << ' ' << cnt << endl;
    cnt += merge(A, L, M, R);
    return cnt;
}

int main(){
    int A[] = {5,4,3,2,1};
    int n = sizeof(A)/4;
    cout << count(A, 0, n-1) << endl;
}
