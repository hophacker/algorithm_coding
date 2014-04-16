#include "leetcode.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.length(), n2 = num2.length();
        vector<int> res(n1+n2, 0);
        res.resize(n1+n2);
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n2; j++)
                res[i+j] += (num1[i]-'0') * (num2[j]-'0');
        int carry = 0;
        for (int i = 0; i < n1+n2; i++){
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        int k = n1+n2;
        while(k > 0 && res[k-1] == 0) k--;
        string num3;
        if (k == 0) num3.push_back('0');
        else{
            for (int i = 0; i < k; i++)
                num3.push_back(res[i] +'0');
        }
        reverse(num3.begin(), num3.end());
        return num3;
    }
};
int main()
{
    cout << Solution().multiply("9", "9") << endl;
}

