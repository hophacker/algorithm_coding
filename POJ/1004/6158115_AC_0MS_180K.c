#include<stdio.h>
void main()
{
	int i;
	double s,t;
	s=0;
	for (i=1;i<=12;i++)
	{
		scanf("%lf",&t);s+=t;
	};
	printf("$%0.2lf\n",(s/12));
}