#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(a,x) memset(a,x,sizeof(a))
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define ll long long
#define ui unsigned int
#define us unsigned short
#define maxN 105
int n;
char s[maxN];
int sn;
bool F[maxN][maxN][maxN];
int match[maxN];
void setMatch(){
    clr(match, -1);
    stack<int> bra;
    F(i,0,sn){
        if (s[i] == '(') bra.push(i);
        else if (s[i] == ')'){
            int j = bra.top();
            bra.pop();
            match[j] = i;
            match[i] = j;
        }
    }
}
inline void merge(int L, int M, int R){
    FE(i,0,n) FE(j,0,n)
        if (F[L][M][i]  &&  F[M+1][R][j])  
            F[L][R][i+j] = 1;
}
void matchIt(int L, int R){
    if (L > R) {
        F[L][R][0] = 1;
        return;
    }
    if (s[L] == '('){
        int P = match[L];
        matchIt(L+1, P-1);
        memcpy(F[L][P], F[L+1][P-1], sizeof(F[0][0]));
        if (P < R){
            if (s[P+1] == '*' || s[P+1] == '|'){
                if (P+2 <= R) matchIt(P+2, R);
                if (s[P+1] == '*'){
                    F[L][P+1][0] = 0;
                    FE(i,1,n) if(F[L][P][i])
                        for (int j = 0; j <= n; j += i) F[L][P+1][j] = 1;
                    if (P+2 <= R) merge(L,P+1,R);
                }else{
                    FE(i,0,n) F[L][R][i] = (F[L][P][i] || F[P+2][R][i]);
                }
            }else{
                matchIt(P+1,R);
                merge(L,P,R);
            }
        }
    }else{
        //find next '(' begin{
        int P = L+1;
        int star = 0;
        while(P <= R && s[P] != '(' && s[P] != '|') 
            star += (s[P] == '*'), P++;
        //end}
        if (star) FE(i,max(P-L-2*star,0),n) F[L][P-1][i] = 1;
        else  F[L][P-1][P-L] = 1;
        if (P < R) {
            if (s[P] == '('){//P+1<=R
                matchIt(P, R);
                merge(L,P-1,R);
            }else if (s[P] == '|'){
                matchIt(P+1, R);
                FE(i,0,n) F[L][R][i] =  (F[L][P-1][i] || F[P+1][R][i]);
            }

        }
    }
}
string duplicate(const string& str, int x){
    string newStr;
    F(i,0,x) newStr += str;
    return newStr;
}
string line(int L, int R, int num){
    string ret;
    int star = 0;
    bool first = true;
    FE(i,L,R) if (s[i] == '*') star++;
    FE(i,L,R) if (s[i] != '*'){
        if (i < R && s[i+1] == '*'){
            if (first){
                first = false;
                F(t,0,num-(R+1-L-star*2)) ret += s[i];
            }
        }else ret += s[i];
    }
    return ret;
}
string construct(int L, int R, int num){
    string ret;
    if (L > R) return "";
    if (s[L] == '('){
        int P = match[L];
        if (P < R){
            if (s[P+1] == '*'){
                FE(i,0,num) if (F[P+2][R][num-i]){
                    if (i == 0){
                        return construct(P+2, R, num);
                    }else{
                        FE(j,1,i) if (i%j == 0 && F[L][P][j]){
                            ret =  duplicate(construct(L,P,j),i/j);
                            return ret += construct(P+2,R,num-i);
                        }
                    }
                }
            }else if (s[P+1] == '|'){
                if (F[L][P][num]) return construct(L,P,num);
                else if (F[P+2][R][num]) return construct(P+2,R,num);
            }else{
                FE(i,0,num) if (F[L][P][i] && F[P+1][R][num-i]){
                    ret = construct(L,P,i);
                    return ret += construct(P+1, R, num-i);
                }
            }
        }else{
            return construct(L+1, P-1, num);
        }
    }else{
        int P = L+1;
        while(P <= R && s[P] != '(' && s[P] != '|') P++; 
        if (P < R) {
            if (s[P] == '('){//P+1<=R
                FE(i,0,num) if (F[L][P-1][i] && F[P][R][num-i]){
                    ret = construct(L,P-1,i);
                    ret += construct(P,R,num-i);
                    return ret;
                }
            }else if (s[P] == '|'){
                if (F[L][P-1][num]) return line(L,P-1,num);
                else return construct(P+1,R,num);
            }
        }else{
            return line(L,P-1,num);
        }
    }
}
int main ( int argc, char *argv[] ) {
    scanf("%d\n%s", &n, s);
    sn = strlen(s);
    setMatch();
    clr(F,0);
    matchIt(0,sn-1);
    if (F[0][sn-1][n]){
        cout << construct(0,sn-1,n) << endl;
    }else{
        printf("NIL\n");
    }
    return EXIT_SUCCESS;
}

