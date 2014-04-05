#include <iostream>
using namespace std;

#define maxn 11
#define maxw 11
#define maxh 11

struct Pos
{
int x;
int y;
};

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

Pos a[maxn];
int n,w,h;
int ans;
int done[maxw][maxh];
int leftmost;

void px(Pos tar[])
{
int i,j;
Pos temp;

for(i=2;i<=n;i++)
{
   temp=tar[i];
   for(j=i-1;j>=1&&tar[j].x*1000+tar[j].y>temp.x*1000+temp.y;j--)
    tar[j+1]=tar[j];
   tar[j+1]=temp;
}
}

int xiao(Pos b[],Pos c[])
{
int i,j,k;
int tb,tc;
px(b);

for(i=1;i<=n;i++)
{
   tb=b[i].x*1000+b[i].y;
   tc=c[i].x*1000+c[i].y;

   if(tb<tc) return 1;
   if(tb>tc) return 0;
}

return 0;
}

void check()
{
int i,j,k,p;
Pos b[maxn],c[maxn],d[maxn];
int ta,tb;

ta=tb=-100000;

for(i=1;i<=n;i++)
{
   if(ta<a[i].x) ta=a[i].x;
   if(tb<a[i].y) tb=a[i].y;
}

if(ta>tb) return;

for(i=1;i<=n;i++)
   c[i]=a[i];
px(c);

if(ta<tb)
{
   for(i=1;i<=n;i++)
   {
    b[i].x=ta-a[i].x+1;
    b[i].y=a[i].y;
   }

   if(xiao(b,c))
    return;

   for(i=1;i<=n;i++)
   {
    b[i].x=a[i].x;
    b[i].y=tb-a[i].y+1;
   }

   if(xiao(b,c))
    return;

   for(i=1;i<=n;i++)
   {
    b[i].x=ta-a[i].x+1;
    b[i].y=tb-a[i].y+1;
   }

   if(xiao(b,c))
    return;
}
else
{
   for(i=1;i<=n;i++)
    d[i]=c[i];

   for(p=1;p<=3;p++)
   {
    for(i=1;i<=n;i++)
    {
     b[i].x=d[i].y;
     b[i].y=ta-d[i].x+1;
    }
   
    for(i=1;i<=n;i++)
     d[i]=b[i];

    if(xiao(b,c))
     return;
   }

   for(i=1;i<=n;i++)
   {
    d[i].x=ta-c[i].x+1;
    d[i].y=c[i].y;
    b[i]=d[i];
   }

   for(p=1;p<=4;p++)
   {
    if(xiao(b,c))
     return;
   
    for(i=1;i<=n;i++)
    {
     b[i].x=d[i].y;
     b[i].y=ta-d[i].x+1;
    }

    for(i=1;i<=n;i++)
     d[i]=b[i];
   }
}

ans++;
}

void dfs(int last,int lastj,int level)
{
int i,j,k;
int ta,tb;
int start;
int nx,ny;
int tx,ty;
int can;

if(level>n)
{
   j=0;
   for(i=1;i<=n;i++)
    if(a[i].y==1)
    {
     j=1;
     break;
    }

   if(j)
    check();
   /*
   for(i=1;i<=n;i++)
    cout<<"("<<a[i].x<<","<<a[i].y<<") ";
   cout<<endl;
   */

   return;
}

for(i=last;i<level;i++)
{
   if(i==last)
    start=lastj+1;
   else
    start=0;

   for(j=start;j<4;j++)
   {
    nx=a[i].x+dx[j];
    ny=a[i].y+dy[j];

    if((nx>=1&&nx<=w)&&(ny>=1&&ny<=h)&&!done[nx][ny])
   
    if(nx==1&&ny<leftmost)
    {}
    else
    {
     can=1;
     for(k=0;k<4;k++)
     {
      tx=nx+dx[k];
      ty=ny+dy[k];
     
      if(tx>=1&&tx<=w&&ty>=1&&ty<=h&&done[tx][ty]&&done[tx][ty]<i)
      {
       can=0;
       break;
      }
     }

     if(can)
     {
      done[nx][ny]=level;
      a[level].x=nx;
      a[level].y=ny;
      dfs(i,j,level+1);
      done[nx][ny]=0;
     }
    }
   }
}
}

void work()
{
int i,j;
for(i=1;i<=w;i++)
   for(j=1;j<=h;j++)
    done[i][j]=0;

for(leftmost=1;leftmost<=h;leftmost++)
{
   a[1].x=1;
   a[1].y=leftmost;
   done[1][leftmost]=1;
   dfs(1,0,2);
   done[1][leftmost]=0;
}

}

int main()
{
int t;

cin>>n>>w>>h;
if(w>h)
{
   t=w;
   w=h;
   h=t;
}
ans=0;
work();
cout<<ans<<endl;

return 0;
}