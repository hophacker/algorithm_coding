#include<stdio.h>
#include<string.h>
void main()
{
	long int  n,i,j,day,year,days,d,m,y;
	char a[][10]={(""),("pop"),("no"),("zip"),("zotz"),("tzec"),("xul"),("yoxkin"),("mol"),("chen"),("yax"),("zac"),("ceh"),("mac"),("kankin"),("muan"),("pax"),("koyab"),("cumhu"),("uayet")};
	char b[][10]={"","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
	char mon[10];
	scanf("%d",&n);
	printf("%d\n",n);
	for (i=1;i<=n;i++)
	{
		scanf("%d.%s %d",&day,&mon,&year);
		for (j=1;(j<=19)&&(strcmp(a[j],mon)!=0);j++);
		days=year*365+(j-1)*20+day+1;
		y=(days-1)/260;
		j=(days-1)%260+1;
		d=(j-1)%13+1;
		m=(j-1)%20+1;
		printf("%d %s %d\n",d,b[m],y);
	}
}