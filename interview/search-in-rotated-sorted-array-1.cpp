class Solution {
public:
    int search(int A[], int n, int target) {
        int L = 0, R = n-1;
        while(L <= R){
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            
            if (A[M] < A[R]){
                // M..R sorted
                if (A[M] <= target && target <= A[R]) L = M+1;
                else R = M-1;
            }else{
                // L..M sorted
                if (A[L] <= target && target <= A[M]) R = M-1;
                else L = M+1;
            }
        }
        return -1;
    }
};
