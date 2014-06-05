class Solution {
public:
    bool search(int A[], int n, int target) {
        int L = 0, R = n-1;
        while(L <= R){
            int M = (L + R) / 2;
            if (A[M] == target) return true;
    
            if (A[M] < A[R]){
                if (A[M] <= target && target <= A[R]) L = M+1;
                else R = M-1;
            }else if (A[L] < A[M]){
                if (A[L] <= target && target <= A[M]) R = M-1;
                else L = M+1;
            }else{
                while(L <= R && A[L] == A[M]) L++;
                while(L <= R && A[M] == A[R]) R--;
            }
            
        }
        return false;
    }
};
