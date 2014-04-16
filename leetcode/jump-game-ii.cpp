#include "leetcode.h"
class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0) return  0;
        int L = 0, R = 0, step = 0;
        while(R < n-1){
            int R1 = R;
            for (int i = L; i <= R; i++){
                R1 = max(R1, i + A[i]);
            }
            L = R+1;
            R = R1;
            step++;
        }
        return step;
    }
};
int main()
{
    int a[] = {0,1};
    cout << Solution().jump(a,2) << endl;
}
