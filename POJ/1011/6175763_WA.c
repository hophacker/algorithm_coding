#include<stdio.h>
int n,stick[66],used[66];
int search(int from,int len)
{
	int i,pan;
	if (from==(n+1)) return(0);
	for (i=from;i<=n;i++)
	if (used[i]==0)
	{
		if (stick[i]==len)
		{
			used[i]=1;
			return(1);
		}
		if (stick[i]<len)
		{
			used[i]=1;
			pan=search(i+1,len-stick[i]);
			if (pan==1) return (1);
			    else used[i]=0;
		}
	}
	return(0);
}
int doit(int len)
{
	int i,pan;
	for (i=1;i<=n;i++)
	{
		if (used[i]==0)
		{
			if (len==stick[i]) used[i]=1;else
			{
				used[i]=1;
				pan=search(i+1,len-stick[i]);
				if (pan==0)
				return(0);
			}
		}
	}
	return(1);
}
void main ()
{
	int i,s,total,max,many,ok,yue[100],k;
	scanf("%d",&n);
	while (n!=0)
	{
		total=0;
		max=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&stick[i]);
			total+=stick[i];
			if (stick[i]>max) 
				max=stick[i];
		}
		{
			int x,y,t;
			for (x=1;x<=n-1;x++)
				for (y=x+1;y<=n;y++)
					if (stick[x]<stick[y])
					{
						t=stick[x];
						stick[x]=stick[y];
						stick[y]=t;
					}
		}
		many=0;
		for (i=max;i<=total-1;i++)
		{
			if ((total%i)==0) 
			{
				many++;
				yue[many]=i;
			}
		}
		for (i=1;i<=many;i++)
		{
			for (k=1;k<=n;k++)
				used[i]=0;
			ok=doit(yue[i]);
			if (ok==1) 
			{
				printf("%d\n",yue[i]);
				break;
			}
		}
		scanf("%d",&n);
	}
}
