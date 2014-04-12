#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
//BFS 只能从高往低处走，高度差不大于10
//最后把每条道路都输出来
int n,m;
bool s[21][21][4];//s[x][y][k]表示从x,y点可以朝着k方向走
int map[21][21];
int pre[21][21];//从哪个方向转移过来的
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
typedef struct node
{
    int x,y;   
    }node;
node p,t;
queue<node>q;   
int work(int x1,int y1,int x2,int y2)//判断(x1,y1), (x2,y2)构成的边的方向
{
if(x1==x2)//东西走向
{
    if(y2-y1>0)return 1;
    return 3;
       }
    else //南北走向
    {  
    if(x2-x1>0)return 2;
    return 0;
       }
    }
bool check(int x,int y)
{
    if(x>0&&x<=n&&y>0&&y<=m)return 1;
    return 0;
    }
void BFS(int sx,int sy)
{
    int k,x,y,xx,yy;
    while(!q.empty())q.pop();
    p.x=sx;p.y=sy;
    q.push(p);
    pre[sx][sy]=-2;
    while(!q.empty())
    {
          p=q.front();
          q.pop();
          x=p.x;y=p.y;
          for(k=0;k<4;k++)
          {
              xx=x+dx[k];
              yy=y+dy[k];
              if(!check(xx,yy)||pre[xx][yy]!=-1||!s[x][y][k]||map[xx][yy]-map[x][y]>10)continue;
              pre[xx][yy]=k;
              t.x=xx;
              t.y=yy;
              q.push(t);                                                                              
              }          
          }
    }
void output(int x1,int y1,int x2,int y2)
{
    if(x1!=x2||y1!=y2)
    {
       int k=pre[x2][y2];
       output(x1,y1,x2-dx[k],y2-dy[k]);
       printf(" to ");              
       }
    printf("%d-%d",x2,y2);   
    }           
int main()
{
    int i,j,k,x1,y1,x2,y2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          for(i=1;i<=n;i++)
          {
              for(j=1;j<=m;j++)
              {
                  scanf("%d",&map[i][j]);            
                  }            
              }                        
          memset(s,0,sizeof(s));
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)//输入道路，注意可能横跨
    {
               if(x1==0&&y1==0&&x2==0&&y2==0)break;                                       
      k=work(x1,y1,x2,y2);//将(x1, y1) 与 (x2, y2) 之间的点都标记是否可以到达
      while(x1!=x2||y1!=y2)
      {
         s[x1][y1][k]=1;
         x1+=dx[k];
         y1+=dy[k];
            }
               }
          while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
          {
               if(x1==0&&y1==0&&x2==0&&y2==0)break;
               if(x1==x2&&y1==y2)//特判
               {
                  printf("To get from %d-%d to %d-%d, stay put!\n\n",x1,y1,x2,y2);
                  continue;              
                  }                                       
               memset(pre,-1,sizeof(pre));
               BFS(x1,y1);               
               if(pre[x2][y2]==-1)//不可到达的情况
               {
                  printf("There is no acceptable route from %d-%d to %d-%d.\n\n",x1,y1,x2,y2);
                  continue;
                  }
               output(x1,y1,x2,y2);
               printf("\n\n");    
               }                  
          }
    return 0;
    }
