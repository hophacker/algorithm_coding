#include<stdio.h>
void main()
{
	long int n,i,t;
	double x,y,PI=3.14159265358979;
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x,&y);
		t=(long int)((x*x+y*y)*PI/2/50);
		t++;
		printf("Property %ld: This property will begin eroding in year %ld.\n",i,t);
	}
	printf("END OF OUTPUT.\n");
}