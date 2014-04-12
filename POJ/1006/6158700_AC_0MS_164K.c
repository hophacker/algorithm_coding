#include<stdio.h>
void main()
{
	long int p1=28*33,e1=23*33,i1=23*28,d,p,e,i;
	long int total,p2,e2,i2,s=23*28*33,day;
	scanf("%ld%ld%ld%ld",&p,&e,&i,&d);
	day=0;
	while ((d!=-1)||(p!=-1)||(e!=-1)||(i!=-1))
	{
		day++;
		for (p2=0;(p2<=22)&&(((p2*p1)%23)!=(p%23));p2++);
		for (e2=0;(e2<=27)&&(((e2*e1)%28)!=(e%28));e2++);
		for (i2=0;(i2<=32)&&(((i2*i1)%33)!=(i%33));i2++);
		total=(p1*p2+e1*e2+i1*i2-d-1+23*28*33*20)%(23*28*33);
		total++;
		printf("Case %ld: the next triple peak occurs in %ld days.\n",day,total);
		scanf("%ld%ld%ld%ld",&p,&e,&i,&d);
	}
}