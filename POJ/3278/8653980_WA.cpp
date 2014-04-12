#include <iostream>
#include <deque>
using namespace std;
int d[200200];

int main()
{
	int n,k,u,v,i;
	bool is;
	deque<int> Q;
	cin>>n;
	cin>>k;

	if(n==k)
	{
		cout<<0<<endl;
		return 0;
	}
   
	Q.push_back(n);
   while(Q.empty()==0)
   {
	   u = Q[0];
	   if(u == k)
		   break;
	   Q.pop_front();
	   for(i=1;i<=3;i++)
	   {
			is = true;  
			switch(i)
			{
				case 1:
				{
					v = u*2;
					break;
				}
				case 2:
				{	
					v = u+1;
					break;
				}
				case 3:
				{
					if(u==0)
					{
						is = false;
						break;            
					}
					v = u-1;
					break;
				}                                                 
			}
			if(is==false)
				continue;
			if(d[v]==0)
			{
				d[v] = d[u]+1;
				if(v<100000)
					Q.push_back(v);
			}
		}
   }
   cout<<d[k]<<endl;

   return 0;
}
