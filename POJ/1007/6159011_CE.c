#include<stdio.h>
#include<cstring>
int x,t,xu[101];
char c[102][51],ts[51];
void main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) 
	{
		scanf("%s",c[i]);
		xu[i]=0;
		for (j=1;j<m;j++)
			for (k=i+1;k<=m;k++)
				if (c[i][j]>c[i][k]) xu[i]++;
	}
	for (i=1;i<=m;i++);
	    for (j=1;j<=m-1;j++);
			if (xu[i]>xu[j])
			{
				t=xu[i];xu[i]=xu[j];xu[j]=t;
				strcpy(ts,c[i]);
				strcpy(c[i],c[j]);
				strcpy(c[j],c[i]);
			}
	for (i=1;i<=m;i++)
		printf("%s\n",c[i]);
}