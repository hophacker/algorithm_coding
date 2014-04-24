#include "leetcode.h"
class Solution {
private:
    vector<vector<vector<bool> > > block;
    vector<vector<bool> > col;
    vector<vector<bool> > row;
#define ctoi(c) (c-'1')
public:
    bool solve(vector<vector<char> >&board, int i, int j){
        if (i == 9) return true;
        if (board[i][j] == '.'){
            for (int k = 0; k < 9; k++){
                if (!block[i/3][j/3][k] && !row[i][k] && !col[j][k]){
                    block[i/3][j/3][k] = row[i][k] = col[j][k] = 1;

                    board[i][j] = k + '1';
                    if (j == 8) {
                        if (solve(board, i+1, 0)) return true;
                    }
                    else {
                        if (solve(board, i, j+1)) return true;
                    }
                    board[i][j] = '.';

                    block[i/3][j/3][k] = row[i][k] = col[j][k] = 0;
                }
            }
        }else{
            if (j == 8) {
                if (solve(board, i+1, 0)) return true;
            }
            else {
                if (solve(board, i, j+1)) return true;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        block = vector<vector<vector<bool> > >
            (3, vector<vector<bool> >(3, vector<bool>(9,0)));
        col = vector<vector<bool> >(9, vector<bool>(9,0));
        row = vector<vector<bool> >(9, vector<bool>(9,0));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) if (board[i][j] != '.'){
                int t = ctoi(board[i][j]);
                block[i/3][j/3][t] = 1;
                col[j][t] = 1;
                row[i][t] = 1;
            }
        solve(board, 0, 0);
    }
};
int main()
{
    //int num[] = {10,1,2,7,6,1,5};
    char* a[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char> >A(9,vector<char>(9));
    F(i,0,9) F(j,0,9) A[i][j] = a[i][j];
    printVV(A);
    Solution().solveSudoku(A);
    printVV(A);
}
