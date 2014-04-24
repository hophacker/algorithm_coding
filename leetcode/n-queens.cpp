#include "leetcode.h"
class Solution {
private:
    vector<bool> col, right, wrong;
    vector<int> path;
    vector<vector<string> > res;
    vector<string> gra;
    int n;
public:
    void change(char c){
        for (int i = 0; i < n; i++)
            gra[i][path[i]] = c;
    }
    void search(int i){
        if (i == n){
            change('Q');
            res.push_back(gra);
            change('.');
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
    vector<vector<string> > solveNQueens(int n) { 
        this->n = n;
        col = vector<bool>(n, 0);
        right = vector<bool>(n+n-1, 0);
        wrong = vector<bool>(n+n-1, 0);
        path = vector<int>(n);
        gra = vector<string>(n,string(n,'.'));
        search(0);
        return res;
    }
};
int main()
{
    int a[] = {0,1};
    vector<vector<string> > res = Solution().solveNQueens(8);
    printVV(res);
    cout << res.size() << endl;
}
