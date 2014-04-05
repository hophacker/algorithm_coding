#include <stdio.h>
void main()
{
	double a[300],s;
	int i;
	a[0]=0;
	for (i=1;i<=299;i++)
		a[i]=a[i-1]+(double)(1)/(double)(i+1);
	for (;scanf("%lf",&s),s!=0;)
	{
		i=1;
		while (a[i]<s) i++;
		printf("%d card(s)\n",i);
	}
}