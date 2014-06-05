/*Facebook
 * 给一个string，比如UAXXBAUB，给一个pattern，比如AB，返回包含pattern的最短
substring，结果是AUB
 */
#include<string>
#include<vector>
#include<climits>
#include<iostream>
using namespace std;

struct node{
    int size;
    int last;
};
string smallest_matched_substring(string s, string sub){
    int n = s.length();
    int m = sub.length();

    vector<vector<int> > f(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        if (s[i] == sub[0]) f[i][0] = i;

    for (int d = 1; d < m; d++){

        for (int i = d; i < s.size(); i++)if (s[i] == sub[d]){
            for(int j = d-1; j < i; j++) if (f[j][d-1] > f[i][d]){
                f[i][d] = f[j][d-1];
            }
        }

    }

    int minLen = INT_MAX, start;

    for (int i = 0; i < n; i++)
        if (f[i][m-1] != -1 && i-f[i][m-1]+1 < minLen){
            minLen = i - f[i][m-1] + 1;
            start = f[i][m-1];
        }

    if (minLen == INT_MAX) return "";
    else return s.substr(start, minLen);
}

int main(){
    cout << smallest_matched_substring("UAXXBAUB", "ABAB") << endl;
}
