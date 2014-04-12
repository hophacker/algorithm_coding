#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define max(a,b) (a<b?b:a)
#define F(i,L,R) for (int i = L; i < R; i++)
#define ll long long
class AlienAndGame
{
    public:
        inline int calc(int a, int b){
            if (a < b) return a*a;
            else return b*b;
        }
        int getNumber(vector <string> board) {
            int n = board.size(), m = board[0].length();
            int h[n+2][2];
            int q[n+2], w[n+2];
            int top;
            ll ans = 0;
            int now = 0, pre;
            F(j,0,m){
                pre = (now+1)%2;
                if (j == 0){
                    F(i,0,n) h[i][now] = 1;
                }else{
                    F(i,0,n) h[i][now] = (board[i][j] == board[i][pre] ? h[i][pre]+1 : 1);
                }
                h[n][now] = 0;
                top = 0;
                q[top] = -1;
                F(i,0,n+1){
                    if(h[i][now] > q[top]) 
                        q[++top] = h[i][now] , w[top] = 1; 
                    else{ 
                        ll cnt = 0; 
                        while(h[i][now] <= q[top]) { 
                            ans = max(ans ,calc(cnt+w[top],q[top])); 
                            cnt += w[top--]; 
                        } 
                        q[++top] = h[i][now]; 
                        w[top] = cnt+1; 
                    } 
                } 
            }
            return ans;
        }
};
