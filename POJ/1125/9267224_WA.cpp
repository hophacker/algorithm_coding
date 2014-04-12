#include<iostream>
using namespace std;
//=======================================	
int ss[100][100];
int main()
{

	int n,i,group,j,k;
	while(cin>>n&&n!=0)
	{
    
    for(i=1;i<100;++i)
	{
		for(j=1;j<100;++j)
		{
			ss[i][j]=10000;
		}
	}
	for(i=1;i<=n;++i)
	{
		cin>>group;
		for(j=1;j<=group;++j)
		{
			int num,c;
			cin>>num>>c;
			ss[i][num]=c;
		}
	}
    for(k=1;k<=n;++k)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(ss[i][j]>ss[i][k]+ss[k][j])
				{
					ss[i][j]=ss[i][k]+ss[k][j];
				}
			}
		}	
	}
	int min=1000,pos;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(ss[i][j]<min)
			{
				min=ss[i][j];
				pos=i;
			}
		}
	}
	int max=-1;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
		    if(ss[i][j]!=10000)
			{
				if(ss[pos][j]>max)
				{
					max=ss[pos][j];
				}
			}
		}
	}

	cout<<pos<<" "<<max<<endl;
	}
	
		
}
