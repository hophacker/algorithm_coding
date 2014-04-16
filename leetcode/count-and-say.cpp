#include "leetcode.h"
class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        for (int i = 1; i < n; i++){
            string mid;
            int j = 0;
            while(j < res.length()){
                int jj = j+1;
                while(jj < res.length() && res[j] == res[jj]) jj++;
                mid.push_back(jj-j+'0');
                mid.push_back(res[j]);
                j = jj;
            }
            res = mid;
        }
        return res;
    }
};
int main()
{
    cout << Solution().countAndSay(1) << endl;
}
