#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(*needle == 0){
            return haystack;
        }
        int m = 0;
        while(needle[m] != 0) m++;
        vector<int> preLen(m+1);
        preLen[0] = -1;
        
        for (int L = 0; L < m; L++){
            int l = L;
            while(preLen[l] != -1 && needle[preLen[l]] != needle[L]) l = preLen[l];
            preLen[L+1] = preLen[l]+1;
        }
        
        int matchLen = 0;
        for (int i = 0; *(haystack+i) != 0; i++){
            while(matchLen != -1 && haystack[i] != needle[matchLen]){
                matchLen = preLen[matchLen];
            }          
            matchLen++;
            if (matchLen == m) return haystack+i-matchLen+1;
        }
        return NULL;
    }
};



