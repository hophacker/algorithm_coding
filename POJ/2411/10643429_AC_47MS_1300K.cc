#include<cstdio>
#include<cstring>
long long f[30][1<<12],i,j,n,m,saya=1;
void sayatime (int i,int s1,int pos)
{
	if (pos==m) {f[i][s1]+=saya;return;}
	sayatime(i,s1,pos+1);
	if (pos<=m-2&&!(s1&1<<pos)&&!(s1&1<<pos+1)) sayatime(i,s1|1<<pos|1<<pos+1,pos+2);
}
int main()
{
	
	while(scanf("%d%d",&n,&m),n!=0)
	{
	memset(f,0,sizeof(f));saya=1;
	sayatime(1,0,0);
	for (i=2;i<=n;i++)
	for (j=0;j<1<<m;j++)
	{
		if (f[i-1][j]) saya=f[i-1][j]; else continue;
		sayatime(i,~j&((1<<m)-1),0);
	}
	printf("%lld\n",f[n][(1<<m)-1]);
	}
}