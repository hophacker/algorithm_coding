#include<stdio.h>
#include<string.h>
int x,t,xu[101];
char c[102][52],ts[52];
void main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) 
	{
		scanf("%s",&c[i]);
		xu[i]=0;
		for (j=0;j<n-1;j++)
			for (k=j+1;k<=n-1;k++)
				if (c[i][j]>c[i][k]) xu[i]++;
	}
	for (i=1;i<=m;i++)
	    for (j=1;j<=m-1;j++)
			if (xu[j]>xu[j+1])
			{
				t=xu[j];xu[j]=xu[j+1];xu[j+1]=t;
				strcpy(ts,c[j]);
				strcpy(c[j],c[j+1]);
				strcpy(c[j+1],ts);
			}
	for (i=1;i<=m;i++)
		printf("%s\n",c[i]);
}