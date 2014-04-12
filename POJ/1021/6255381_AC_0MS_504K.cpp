#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct BLOCK
{
    int num;
    double hash;
    int wmin,wmax,hmin,hmax;
}block[2][2501];
int graph[2][101][101]; 
int belong[2][101][101];          
int visit[2501]={0};

int maxw,maxh;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int grh,int x,int y,int blk)
{
    int i,xx,yy;
 if (graph[grh][x][y]==1)
 {
     belong[grh][x][y]=blk;
     graph[grh][x][y]=0;
     block[grh][blk].num++;
 }
 else return;
 for (i=0;i<4;i++)
 {
     xx=x+dir[i][0];
     yy=y+dir[i][1];
     if (xx>=0&&xx<maxw&&yy>=0&&yy<maxh)
     {
      if (graph[grh][xx][yy]==1)
      {
       if (block[grh][blk].wmin>xx)block[grh][blk].wmin=xx;
       if (block[grh][blk].wmax<xx)block[grh][blk].wmax=xx;
       if (block[grh][blk].hmin>yy)block[grh][blk].hmin=yy;
       if (block[grh][blk].hmax<yy)block[grh][blk].hmax=yy;
       dfs(grh,xx,yy,blk);
      }
     }
 }
}
int main()
{
    int ncase,n,i,tmpx,tmpy,j,k,num1,num2,a,b,success;
    
    cin>>ncase;
    success=1;
    while (ncase--)
    {
     memset(block,0,sizeof(block));
     memset(block,0,sizeof(graph));
     memset(visit,0,sizeof(visit));
     memset(belong,-1,sizeof(belong));
     cin>>maxw>>maxh>>n;
     for (i=0;i<n;i++)
     {
      cin>>tmpx>>tmpy;
      graph[0][tmpx][tmpy]=1;
     }
     for (i=0;i<n;i++)
     {
         cin>>tmpx>>tmpy;
         graph[1][tmpx][tmpy]=1;
     }
       
       num1=0;
       for(j=0;j<maxw;j++)
           for (k=0;k<maxh;k++)
           {
               if(graph[0][j][k]==1)
               {
                   block[0][num1].hmax=block[0][num1].hmin=k;
                   block[0][num1].wmax=block[0][num1].wmin=j;
                   dfs(0,j,k,num1++);
               }
           }
       num2=0;
       for(j=0;j<maxw;j++)
           for (k=0;k<maxh;k++)
               {
                   if(graph[1][j][k]==1)
                   {
                   block[1][num2].hmax=block[1][num2].hmax=k;
                   block[1][num2].wmax=block[1][num2].wmax=j;
                   dfs(1,j,k,num2++);
                   }
               }
           if(num1!=num2)
           {
               cout<<"NO"<<endl;
               continue;
           }
           
           for (i=0;i<2;i++)
           {
               for (j=0;j<num1;j++)
               {
                   int cnt=0;
                   int xx[200]={0};
                   int yy[200]={0};
                for (a=block[i][j].wmin;a<=block[i][j].wmax;a++)
                    for(b=block[i][j].hmin;b<=block[i][j].hmax;b++)
                {
                       if(belong[i][a][b]==j)
                       {
                           
                           xx[cnt]=a;
                           yy[cnt]=b;
                           cnt++;
                       }
                }
                    
                    double value=0;
                    for (int aa=0;aa<block[i][j].num;aa++)
                        for(int bb=aa+1;bb<block[i][j].num;bb++)
                    {
                        value+=sqrt((double)(xx[aa]-xx[bb])*(xx[aa]-xx[bb])+(double)(yy[aa]-yy[bb])*(yy[aa]-yy[bb]));
                    }
                    block[i][j].hash=value;
               }
           }
           success=1;
           for (i=0;i<num1;i++)
           {
               int find=0;
               for (j=0;j<num1;j++)
               {
                   if (visit[j]!=1)
                   { 
                   if(block[0][i].num!=block[1][j].num)continue;
                   if(fabs(block[0][i].hash-block[1][j].hash)<(1E-8))
                   {
                       find=1;
                       visit[j]=1;
                       break;
                   }
                   }
                  
               }
               if(find==0){success=0;break;}
           }
           if(success)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
     }
         
    
    return 0;
}