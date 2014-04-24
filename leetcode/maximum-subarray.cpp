#include "leetcode.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = A[0], subSum = A[0];
        for (int i = 1; i < n; i++){
            if (subSum < 0) subSum = 0;
            subSum += A[i];
            maxSum = max(maxSum, subSum);
        }
        return maxSum;
    }
};
int main()
{
    int a[] = {-2,-1,-3,-4};
    cout << Solution().maxSubArray(a, 4) << endl;
}

