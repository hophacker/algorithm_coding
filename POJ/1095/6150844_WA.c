#include <stdio.h>
long int a[19],s[19];
void main ()
{ 
	long int i,k,n,left;
	double ss;
	long int cal(long int n,long int bit);
	a[0]=1;
	s[1]=0;
	for (k=1;k<=20;k++)
		{
			ss=1;
			for (i=k+1;i<=2*k;i++)
				{
					ss=ss*i/(i-k);	
				}
			ss=ss/(k+1);
			a[k]=(long int)(ss+0.5);
			s[k]=s[k-1]+a[k];
		}
	scanf("%ld",&n);
	while (n!=0)
		{
			left=1;
			while (n>s[left])
			{
				left++;
			}
			if (n==1) printf("x");
			  else cal(n-s[left-1],left-1);
			printf("\n");
	        scanf("%ld",&n);
		}	

}
long int cal(long int n,long int bit)
{
	 long int bit1,n1,n2;
	 if ((n==1)&&(bit==0) )
	 {
		 printf("x");
		 return 0;
	 }
	 if (n==1)
	 {
		printf("x");
		printf("(");
	    cal(1,bit-1);
		printf(")");
		return 0;
	 }
	 bit1=0;
	 n1=n;
	 while (n1>(a[bit1]*a[bit-bit1]))
	 {
		n1=n1-a[bit1]*a[bit-bit1];
		bit1++;
	 } 
	 n2=(n1-1)%a[bit-bit1]+1;
	 if (bit1>0)
	 {
		printf("(");
		cal((n1-1)/a[bit-bit1]+1,bit1-1);
		printf(")");
	 }
	 printf("x");
	 if (bit-bit1>0)
	 {
     		printf("(");
		cal(n2,bit-bit1-1);
     		printf(")");
	 }
}