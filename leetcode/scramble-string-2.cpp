#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    vector<vector<vector<bool> > > canMatch;
    vector<vector<vector<char> > > f;
    int n;
    string s1, s2;
    bool balanced(int bal[]){
        for (int i = 0; i < 26; i++) if (bal[i]) return false;
        return true;
    }
    bool canScramble(int i1, int i2, int len){
        if (len == 1) return canMatch[i1][i2][1];
        if (f[i1][i2][len] == -1){
            for (int l1 = 1; l1 < len; l1++){
                int l2 = len - l1;
                f[i1][i2][len] = 
                    (canMatch[i1][i2][l1] && canMatch[i1+l1][i2+l1][l2] && canScramble(i1,i2,l1) && canScramble(i1+l1, i2+l1, l2)) ||
                    (canMatch[i1][i2+l2][l1] && canMatch[i1+l1][i2][l2] && canScramble(i1,i2+l2,l1) && canScramble(i1+l1, i2, l2));
                if (f[i1][i2][len]) break;
            }
        }
        return f[i1][i2][len];
    }
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        this->s1 = s1;
        this->s2 = s2;
        n = s1.size();
        canMatch = vector<vector<vector<bool> > >(n+1, vector<vector<bool> >(n+1, vector<bool>(n+1)));
        f = vector<vector<vector<char> > >(n+1, vector<vector<char> >(n+1, vector<char>(n+1, -1)));
        for (int i1 = 0; i1 < n; i1++)
            for (int i2 = 0; i2 < n; i2++){
                int bal[26] = {0};
                for (int d = 1; d <= n; d++){
                    if (i1+d <= n && i2+d <= n){
                        bal[s1[i1+d-1] - 'a']++;
                        bal[s2[i2+d-1] - 'a']--;
                        canMatch[i1][i2][d] = balanced(bal);
                    }else break;
                }
            }
        return canScramble(0, 0, n);
    }
};
int main(){
    Solution s;
    cout << s.isScramble("a", "a") << endl;
}
