#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<stack>
#include<set>
#include<ctype.h>
using namespace std;

int n, sN = 0, p;
char s[1000010];
map<string,set<string> > M;
map<string,set<string> >::iterator iM;
//stack<string> tags;
string attr, tag;
void skipTo(char c){
    while(p < sN && s[p] != c) p++;
}
void skipToQuote(){
    while(p < sN && s[p] != '\'' && s[p] != '\"') p++;
}
bool isNotIn(char c, const char* pat, int len){
    for (int i = 0; i < len; i++) if (pat[i] == c) return true;
    return false;
}
void skip(const char *pat){
    int len = strlen(pat);
    while(p < sN && isNotIn(s[p],pat,len)) p++;
}
void skipSpace(){
    skip(" \t\n");
}
void pr(){
    for(iM=M.begin(); iM != M.end(); iM++){
        cout << iM->first << ":";
        set<string> S = iM->second;
        bool first = true;
        for (set<string>::iterator iS = S.begin(); iS != S.end(); iS++){
            if (first) first = false;
            else cout << ',';
            cout << *iS;
        }
        cout << endl;
    }
}
string getElement(){
    int p1 = p;
    while(p < sN && (isalnum(s[p])||s[p]=='-')) p++;
    string tag(s+p1,p-p1); 
    return tag;
}
int main(){
    char c;
    scanf("%d\n", &n);
    while((c = getchar()) != EOF)
        if (c == '\n') continue;
        else s[sN++] = c;
    while(p < sN){
        skipTo('<');
        if (s[p+1] == '!') {
            skipTo('>');
            continue;
        }
        p++;
        skipSpace();
        if (s[p] == '/'){
            skipTo('>');
        }else{ 
            tag = getElement();
            if (M.find(tag) == M.end()){
                set<string> S;
                M[tag] = S;
            }
            skipSpace();
            while(p < sN && s[p] != '>' && s[p] != '/'){
                attr = getElement();
                M[tag].insert(attr);
                skipTo('=');p++;
                skipSpace();
                if (s[p] == '\"' || s[p] == '\''){
                    p++;
                    skipToQuote();
                }else{
                    while(p < sN && !isspace(s[p]) && s[p] != '>') p++;
                }
                p++;
                skipSpace();
            }
        }
        skip("/>");
    }
    pr();
}
