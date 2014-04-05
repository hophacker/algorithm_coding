#include<stdio.h>
long int pan[100000];
long int t,x;
void main()
{
	char digit[8];
    char s[30];
	long int n,i,j,len,num,t,k,pl;
	void qs(long int l,long int r);
	scanf("%ld",&n);
	pl=0;
	for (i=1;i<=n;i++)
	{
		scanf("%s",&s);
		len=strlen(s);
		num=0;
		for (j=0;j<=len-1;j++)
		{
			if ((s[j]>=48)&&(s[j]<=57))
			{
				num=num*10+s[j]-48;
			}
			if ((s[j]>=65)&&(s[j]<=89))
			{
				if (s[j]<81) num=num*10+(s[j]-1-64)/3+2;
				if (s[j]>81) num=num*10+(s[j]-2-64)/3+2;
			}
		}
		pl++;pan[pl]=num;
	}
	qs(1,pl);
	i=1;
	while (i<=pl)
		{
			t=0;
			j=pan[i];
			k=i+1;
	        while ((pan[k]==pan[i])&&(k<=pl)) k++;
			if ((k-i)>1) 
			{
			while (j>0)
			{
				t++;
				digit[t]=(j%10)+48;
				j/=10;
				if (t==4){t++;digit[t]="-";}
			}
			while (t<=8)
			{	
				if (t==4) {digit[t]="-";t++;}
				t++;
				digit[t]="0";
			}
			for (j=8;j>=1;j--) printf("%c",digit[j]);
			printf(" ");
			printf("%d\n",k-i);
			}
			i=k;
		}	
}
void qs(long int l,long int r)
{
	long int i,j;
	i=l;j=r;x=pan[r-(r-l)/3];pan[r-(r-l)/3]=pan[i];
    while (i<j)
	{
		while ((i<j)&&(pan[j]>=x)) {j--;}
		if (i<j) {pan[i]=pan[j];i++;}
		while ((i<j)&&(pan[i]<=x)) {i++;}
		if (i<j) {pan[j]=pan[i];j--;}	
	}
	pan[i]=x;
	if (l<i-1) qs(l,i-1);
	if (j+1<r) qs(j+1,r);
}