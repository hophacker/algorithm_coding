#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 1010;
const int MAXM = 21;
const int ASCII = 128;
char str1[MAXN / 10], str2[MAXN / 10];
char word[MAXN][MAXM], result[MAXN / 10];
int n, len, head[ASCII], length[MAXN];
bool find, flag[MAXN];
 
void dfs(int len1, int len2) /* len1 是第一种拆分下的长度，len2 是第二种拆分下的长度 */
{
    if(len1 > len || len2 > len) return;
    if(len1 == len2) {
        if(len1 == len && strcmp(result, str1) > 0) {
            find = true; 
            strcpy(result, str1);
        }
        return;
    }
    int i, l;
    char str[MAXN / 10];
    if(len1 > len2) {
        l = len1 - len2;
        strcpy(str, str1 + len2);
        for(i = head[str[0]]; i < n; i ++) {
            if(str[0] < word[i][0]) 
                break;
            if(! flag[i] && ((l < length[i] && strstr(word[i], str) == word[i])
                        || (l >= length[i] && strstr(str, word[i]) == str))) 
            { /* 将 word[i] 拼接到较短的 len2 后面 */
                strcpy(str2 + len2, word[i]);
                if(strcmp(result, str2) < 0) 
                    break;
                flag[i] = true;
                dfs(len1, len2 + length[i]);
                flag[i] = false;
            }
        }
    }else {
        l = len2 - len1;
        strcpy(str, str2 + len1);
        for(i = head[str[0]]; i < n; i ++) {
            if(str[0] < word[i][0]) 
                break;
            if(! flag[i] && ((l < length[i] && strstr(word[i], str) == word[i])
                        || (l >= length[i] && strstr(str, word[i]) == str))) {
                strcpy(str1 + len1, word[i]);
                if(strcmp(result, str1) < 0) break;
                flag[i] = true;
                dfs(len1 + length[i], len2);
                flag[i] = false;
            }
        }
    }
}
 
int main()
{
    char last = ' ';
    scanf("%d %d", &len, &n);
    for(int i = 0; i < n; i ++) {
        scanf("%s", &word[i]);
        if(word[i][0] != last) {
            head[word[i][0]] = i;
            last = word[i][0];
        }
        length[i] = strlen(word[i]);
    }
    find = false;
    memset(flag, false, sizeof(flag));
    memset(result, ASCII, sizeof(result));
    for(int i = 0; i < n; i ++) {
        if(strcmp(result, word[i]) < 0) break;
        strcpy(str1, word[i]);
        flag[i] = true;
        dfs(length[i], 0);
        flag[i] = false;
    }
    if(find) printf("%s\n", result);
    else printf("NO SOLUTION\n");
    return(0);
}