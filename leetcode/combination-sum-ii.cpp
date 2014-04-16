#include "leetcode.h"

class Solution {
private:
    vector<vector<int> > res;
    int target;
    vector<int> num, path;
    int n;
public:
    void search(int i, int sum){
        if (sum >= target){
            if (sum == target) res.push_back(path);
            return;
        }
        if (i == n) return;
        if (sum + num[i] > target) return;


        search(i+1, sum);
        sum += num[i];
        int j = i+1;
        while(j < n && num[j] == num[i]) sum += num[j], j++;
        if (sum <= target){
            for (int k = i; k < j; k++) path.push_back(num[i]);
            search(j, sum);
            for (int k = i; k < j; k++) path.pop_back();
        }

    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        this->target = target;
        sort(num.begin(), num.end());
        this->num = num;
        this->n = num.size();
        search(0,0);
        return res;
    }
};
int main()
{
    //int num[] = {10,1,2,7,6,1,5};
    int num[] = {};
    vector<int> vnum(num, num+sizeof(num)/4);
    vvi res = Solution().combinationSum2(vnum, 8);
    printVV(res);
}
