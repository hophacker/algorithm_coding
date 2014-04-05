#include<stdio.h>
void main()
{
	char s[8];
	long int  n,a[151],b,len,lenx,i,j;
	while (scanf("%s%d",s,&n)!=EOF)
	{
	    for (len=5;(len>=0)&&(s[len]=='0');len--);
		if (len==-1){ printf("0");continue;}	
		lenx=0;j=0;b=0;
		for (i=0;i<=len;i++)
		{
			if ((s[i]>=48)&&(s[i]<=57)) b=b*10+s[i]-48;
			else 
				if (s[i]=='.')
				{
					lenx=len-i;
				}
		}
		if (b==0) {printf("0");continue;}
		lenx=lenx*n;
		for (i=1;i<=150;i++) a[i]=0;
		a[1]=1;
		len=1;
		for (i=1;i<=n;i++)
		{	
			for (j=1;j<=len;j++) a[j]=a[j]*b;
			for (j=1;j<=len+7;j++)
			{
				a[j+1]=a[j+1]+a[j]/10;
				a[j]=a[j]%10;
			}
			for (j=len+7;(a[j]==0)&&(j>=1);j--);
			len=j;
		}
		for (i=len;i>lenx;i--) printf("%d",a[i]);
	    if (lenx!=0)
		{
			printf(".");
			for (i=lenx;i>=1;i--) printf("%d",a[i]);
		}
		printf("\n");
	}
}