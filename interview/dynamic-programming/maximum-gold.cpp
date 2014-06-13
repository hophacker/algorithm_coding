#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int n;
    vector<int> A;
    vector<vector<int> > mem;
public:
    void input(){
        cin >> n;
        mem = vector<vector<int> >(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            A.push_back(x);
        }
    }
    int maxGold(int L, int R){
        if (L > R) return 0;
        else if (L == R) return A[L];

        if (mem[L][R] == -1){
            mem[L][R] = max( min(maxGold(L+2, R), maxGold(L+1, R-1)) + A[L], 
                             min(maxGold(L, R-2), maxGold(L+1, R-1)) + A[R]);
        }
        return mem[L][R];
    }

    int maxGold(){
        return maxGold(0, n-1);
    }
};

int main(){
    Solution s;
    s.input();
    cout << s.maxGold() << endl;
}

