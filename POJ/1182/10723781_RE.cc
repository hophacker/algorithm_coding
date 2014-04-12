#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100005
#define next(x) (x/3*3+(x%3+1)%3)
#define pre(x) (x/3*3+(x%3+2)%3)
#define go(kx,dx) while((kx+dx)%3!=0 && KK[kx+dx]!=-1) dx++
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
struct set
{
	int parent;  //记录父节点
	int rank;
}elem[N*3];

int kindN;
int n;
int KK[N];
void init() {
	int i;
	for(i=1;i<=3*n;i++)
	{
		KK[i] = -1;
		elem[i].parent=i;
		elem[i].rank = 1;
	}
}
int Find(int x) {
	int root,temp;
	temp=x;
	while(x!=elem[x].parent)    //寻找根节点
		x=elem[x].parent;
	root=x;
	x=temp;
	while (x!=elem[x].parent)   //压缩路径，全部赋值为根节点的值
	{
		temp=elem[x].parent;
		elem[x].parent=root;
		x=temp;
	}
	return root;
}

bool Union(int x,int y){
		if(elem[x].rank>=elem[y].rank) {
			elem[y].parent=elem[x].parent;
			elem[x].rank+=elem[y].rank;
		}
		else {
			elem[x].parent=elem[y].parent;
			elem[y].rank+=elem[x].rank;
		}
}
int main()
{
	int k;
	int a,b, r;
	//freopen("in", "r", stdin);
	scanf("%d%d", &n, &k);
	init();
	int fx1, fx2, fx3, fy1, fy2, fy3, fa = 0;
	while (k--){
		scanf("%d%d%d",&r,&a,&b);
		if (a > n || b > n || (r==2 &&a==b)) fa++;
		else{
			fx1=Find(a); 
			fx2=Find(a+n); 
			fx3=Find(a+n+n); 
			fy1=Find(b); 
			fy2=Find(b+n); 
			fy3=Find(b+n+n); 
			if (r == 1){
				if (fx1 != fy2 && fx1 != fy3){
					Union(fx1,fy1);
					Union(fx2,fy2);
					Union(fx3,fy3);
				}else fa++;
			}else{
				if (fx2 != fy2 && fx2 != fy3){
					Union(fx2,fy1);
					Union(fx1,fy3);
					Union(fx3,fy2);
				}else fa++;
			}
		}
	}
	cout << fa << endl;
	return 0;
}