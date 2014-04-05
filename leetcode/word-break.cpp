#include <cmath>
#include <list>
#include <unordered_set>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;




struct node{
    bool exist;
    node* next[26];
    node(){
        exist = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class Solution {
    node* trie = NULL;
#define pos(c) (c-'a')
public:
    void insert(string s){
        node* cur = trie;
        for (int i = 0; i < s.length(); i++){
            int p = pos(s[i]);
            if (cur->next[p] == NULL)
                cur->next[p] = new node();
            cur = cur->next[p];
        }
        cur->exist = true;
    }
    void print(vector<bool>& a){
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << ' ';
        cout << endl;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        trie = new node();
        for (auto i = dict.begin(); i != dict.end(); i++) insert(*i);
        int n = s.length();
        vector<bool> f(n+1, false);
        f[0] = true;
        for (int i = 0; i < n; i++)if (f[i]){
            int j = i;
            node* cur = trie;
            while(j < n){
                int p = pos(s[j]);
                cur = cur->next[p];
                if (cur == NULL) break;
                j++;
                if (cur->exist) f[j] = true;
            }
        }
        //print(f);
        return f[n];
    }
};
int main ( int argc, char *argv[] ) {
    Solution s = Solution();
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("ee");
    dict.insert("code");
    cout << s.wordBreak("leetcodeleetee", dict) << endl;
    return EXIT_SUCCESS;
}
