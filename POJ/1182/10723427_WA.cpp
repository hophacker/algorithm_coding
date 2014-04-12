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
	int kind;
}elem[N];

int kindN;
int n;
int KK[N];
void init() {
	int i;
	for(i=1;i<=n;i++)
	{
		KK[i] = -1;
		elem[i].parent=i;
		elem[i].rank = 1;
		elem[i].kind = -1;
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

bool Union(int x,int y, int kind)   //合并两个集合
{
	if (x==-1 && y==-1) return false;
	if (x==-1)
		elem[y].kind = kind, KK[kind] = y;
	else if (y==-1)
		elem[x].kind = kind, KK[kind] = x;
	else{
		if(elem[x].rank>=elem[y].rank)
		{
			elem[y].parent=elem[x].parent;
			elem[x].rank+=elem[y].rank;
			elem[x].kind = kind;
			KK[kind] = x;
		}
		else
		{
			elem[x].parent=elem[y].parent;
			elem[y].rank+=elem[x].rank;
			elem[y].kind = kind;
			KK[kind] = y;
		}
	}
}
int main()
{
	int k;
	int a,b,x,y, r;
	//freopen("in", "r", stdin);
	scanf("%d%d", &n, &k);
	init();
	int fa = 0;
	kindN = 0;
	int dx, dy, kx, ky;
	while (k--) {
		scanf("%d%d%d",&r,&a,&b);
		if (a > n || b > n || (r==2 &&a==b)) fa++;
		else{
			x=Find(a);
			y=Find(b);
			kx = elem[x].kind;
			ky = elem[y].kind;
			if (r==1){
				if (kx==-1 && ky==-1){
					Union(x,y,-1);
				}else if (kx!= -1 && ky!= -1){
					if (kx/3==ky/3){
						if (kx != ky) fa++;
						else cout << "what";
					} else {
					dx = 1, dy = 1;
					go(kx,dx); go(ky,dy);
					if (max(kx%3,ky%3)+max(dx,dy) > 3) fa++;
					else F(i,0,3){
							Union(kx,ky,kx);
							kx = next(kx);
							ky = next(ky);
						}
					}
				}else{
					if (kx-=-1) Union(x,y,ky);
					else Union(x,y,kx);
				}
			}else{
				if (kx==-1 && ky==-1){
					elem[x].kind = kindN, KK[kindN] = x;
					elem[y].kind = kindN+1, KK[kindN+1] = y;
					kindN += 3;
				}else if (kx!=-1 && ky!=-1){
					if (kx/3==ky/3){
						if (next(kx)!=ky) 
							fa++;
					}else{
					dx = 1, dy = 1;
					go(kx,dx); go(ky,dy);
					if (max(kx%3,ky%3-1)+max(dx,dy+1) > 3) fa++;
					else{
						kx = next(kx);
						F(i,0,3){
							Union(kx,ky,kx);
							kx = next(kx);
							ky = next(ky);
						}
					}
					}
				}else{
					if (kx!=-1){
						if (kx%3<2){
							elem[y].kind = next(kx);
							KK[next(kx)] = y;
						}else fa++;
					}else{
						if (ky%3<2){
							elem[x].kind = next(ky);
							KK[next(ky)] = x;
						}else fa++;
					}
				}
			}
		}
	}
	cout << fa << endl;
	return 0;
}