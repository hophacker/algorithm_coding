#include <stdio.h>
int a[101][101],f[101][101];
const ok=-1000;
int r,c;
void main ()
{
	int search(int , int );
	int i,j,k=0;
	scanf("%d %d",&r,&c);
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
		{
			scanf("%d",&a[i][j]);
			f[i][j]=ok;
		}
	for (i=1;i<=r;i++)
		for (j=1;j<=r;j++)
		{
			search(i,j);
		}
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
		{
			if (f[i][j]>k) k=f[i][j];
		}
	printf("%d\n",k);
}
int search(int i,int j)
{
	int max=1,t;
	if (f[i][j]!=ok) return (f[i][j]);
	if (i-1>=1)
		if (a[i][j]>a[i-1][j])
		{
			t=1+search(i-1,j);
			if (t>max) max=t;
		}
	if (j+1<=c);
		if (a[i][j]>a[i][j+1])
		{
			t=1+search(i,j+1);
			if (t>max) max=t;
		}
	if (i+1<=r)
		if (a[i][j]>a[i+1][j])
		{
			t=1+search(i+1,j);
			if (t>max) max=t;
		}
	if (j-1>=1)
		if (a[i][j]>a[i][j-1])
		{
			t=1+search(i,j-1);
			if (t>max) max=t;
		}
	f[i][j]=max;
	return(f[i][j]);
}