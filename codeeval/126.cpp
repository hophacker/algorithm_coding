/*
 *    Description:  PLAY WITH DNA
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  The Johns Hopkins University
 */
#include <iostream>  
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int F[51][51];
int M, SLen, DNALen, recN;
char S[51], DNA[301];
struct node{
    int pos, minC;
    bool operator<(const node& b)const{
        if (minC == b.minC) 
            return strncmp(DNA+pos, DNA+b.pos, SLen) < 0;
        else return minC < b.minC;
    }
}rec[301];
int minChanges(char* A, char *B, int n){
    memset(F, 0, sizeof(F));
    for (int i = 0; i <= n; i++)
        F[i][0] = F[0][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            F[i][j] = min(F[i-1][j], F[i][j-1]) + 1;
            F[i][j] = min(F[i][j], F[i-1][j-1] + (A[i-1]==B[j-1]?0:1));
        }
    return F[n][n];
}
int main ( int argc, char *argv[] ) {
    FILE* file = fopen(argv[1], "r");
    while(fscanf(file, "%s %d %s", S, &M, DNA) != EOF){
        SLen = strlen(S);
        DNALen = strlen(DNA);
        recN = 0;
        int C;
        for (int i = 0; i < DNALen-SLen; i++)
            if ((C=minChanges(S, DNA+i, SLen)) <= M){
                rec[recN].pos = i;
                rec[recN].minC = C;
                recN++;
            }
        sort(rec, rec+recN);
        for (int i = 0; i < recN; i++){
            char* cur = DNA+rec[i].pos;
            //if (i != 0 && strncmp(last, cur, SLen) == 0) continue;
            char c = 0;
            swap(c, cur[SLen]);
            printf("%s%c", cur, (i==recN-1?'\n':' '));
            swap(c, cur[SLen]);
        }
        if (recN == 0) printf("No match\n");
    }
    return EXIT_SUCCESS;
}
