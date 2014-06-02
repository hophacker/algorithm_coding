class Solution {
public:
    int search(int A[], int n, int target) {
        int L = 0, R = n-1;
        if (target >= A[0]){
            while(L <= R){
                int M = (L + R) >> 1;
                if (A[M] < A[0]) R = M - 1;
                else if (target < A[M]) R = M - 1;
                else L = M + 1;
            }
            if (R != n && A[R] == target) return R;
            else return -1;
        }else{
            while(L <= R){
                int M = (L + R) >> 1;
                if (A[M] >= A[0]) L = M + 1;
                else if (target < A[M]) R = M - 1;
                else L = M + 1;
            }
            if (R != n && A[R] == target) return R;
            else return -1;
        }
    }
};
