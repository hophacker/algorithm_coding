#include "leetcode.h"
class Solution {
private:
    vector<bool> col, right, wrong;
    vector<int> path;
    int n;
    int res;
public:
    void search(int i){
        if (i == n){
            res++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!col[j] && !right[i+j] && !wrong[n-1-i+j]){
                col[j] = 1;
                right[i+j] = 1;
                wrong[n-1-i+j] = 1;

                path[i] = j;
                search(i+1);

                col[j] = 0;
                right[i+j] = 0;
                wrong[n-1-i+j] = 0;
            }
        }
    }
    int totalNQueens(int n) { 
        this->n = n;
        col = vector<bool>(n, 0);
        right = vector<bool>(n+n-1, 0);
        wrong = vector<bool>(n+n-1, 0);
        path = vector<int>(n);
        res = 0;
        search(0);
        return res;
    }
};
int main()
{
    int a[] = {0,1};
    cout << Solution().totalNQueens(11) << endl;
}
