/*
 * 
 *http://www.mitbbs.com/article_t/JobHunting/32710077.html
Given a string s, remove duplicate adjacent characters from s recursively.

For example: 
Input: "abbac"  
Output: "c", first remove adjacent duplicated 'b's, then remove adjacent 
duplicated 'a'.

Input: "acbbcad" 
Output" "d", first remove 'b', then remove 'c', then remove 'a'. 

Input: "acbbcda" 
Output: "ada" 

Do it with one pass over the string.
Thx!
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

string solution(string s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++){
        bool insert = true;
        while(!st.empty() && st.top() == s[i]){
            insert = false;
            st.pop();
        }
        if (insert) st.push(s[i]);
    }
    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    cout << solution("abbac") << endl;
    cout << solution("acbbcad") << endl;
    cout << solution("acbbcda") << endl;
}
