#include<stdio.h>
#include<string.h>

#define inf 0x3f3f3f3f

struct node{
	int x,y,step;
}a[1000000];

int vis[40000][2],ar[201][201],ans[201][201][2],x,y,n;

void bfs(int x)
{
	int i,row,col,front=0,tail=1;
	int dir[4][2]={0,1,1,0,-1,0,0,-1};
	while(front!=tail)
	{
		for(i=0;i<4;i++)
		{
			row=dir[i][0]+a[front].x;
			col=dir[i][1]+a[front].y;
			if(row>=0&&col>=0&&row<n&&col<n&&!ar[row][col])
			{
				ar[row][col]=-1;
				a[tail].x=row;
				a[tail].y=col;
				a[tail].step=a[front].step+1;
				
				if(ans[row][col][0]>a[tail].step)
				{
					ans[row][col][0]=a[tail].step;
					ans[row][col][1]=x;
				}
				else if(ans[row][col][0]==a[tail].step)
				{
					ans[row][col][1]=0;
				}
				tail++;
			}
		}
		front++;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int i,j,k=0,an[201][201];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&an[i][j]);
			ans[i][j][1]=an[i][j];
			ans[i][j][0]=inf;
			if(an[i][j])
			{
				vis[k][0]=i;
				vis[k++][1]=j;
			}
		}
	}
	if(n==1)
	{
		printf("%d\n",an[0][0]);
		return 0;
	}
	for(i=0;i<k;i++)
	{
		memcpy(ar,an,sizeof(ar));
		a[0].x=vis[i][0];
		a[0].y=vis[i][1];
		a[0].step=0;
		bfs(ar[vis[i][0]][vis[i][1]]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",ans[i][j][1]);
		printf("\n");
	}
	return 0;
}