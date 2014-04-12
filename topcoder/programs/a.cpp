/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2014 07:12:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jiefeng.hopkins@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h> 
#define max(a,b) a > b ? a : b 
#define N 100005 
int q[N]={-1},w[N];     //w记录的是从这个点开始，之前有几个高度大于等于此高度. 
int main() 
{ 
    int n,h; 
    while(scanf("%d",&n),n) 
    { 
        int top = 0; 
        __int64 ans = 0; 
        for(int i=1;i<=n+1;i++) 
        { 
            if(i != n+1) 
                scanf("%d",&h); 
            else 
                h = 0; 
            if(h > q[top]) 
                q[++top] = h , w[top] = 1; 
            else 
            { 
                __int64 cnt = 0; 
                while(h <= q[top]) 
                { 
                    ans = max(ans ,(cnt+w[top])*q[top] ); 
                    cnt += w[top--]; 
                } 
                q[++top] = h; 
                w[top] = cnt+1; 
            } 
        } 
        printf("%I64d\n",ans); 
    } 
    return 0; 
} 
