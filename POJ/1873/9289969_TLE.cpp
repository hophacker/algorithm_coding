#include <iostream>
#include <math.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{
	double x,y;
	int v, l;
};
point p[15], p3[15], convex[15];
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}
//构造凸包接口函数,传入原始点集大小n,点集p(p原有顺序被打乱!)
//返回凸包大小,凸包的点在convex中
//参数maxsize为1包含共线点,为0不包含共线点,缺省为1
//参数clockwise为1顺时针构造,为0逆时针构造,缺省为1
//在输入仅有若干共线点时算法不稳定,可能有此类情况请另行处理!
//不能去掉点集中重合的点
double distan(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	if (n == 0) return 0;
	if (n == 1) return 0;
	if (n == 2) return distan(p[0], p[1])*2;
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i]; 
	delete []temp;
	double len = 0;
	for (int i = 0; i < n; i++)
		len += distan(convex[i], convex[(i+1)%n]);
	return len;
}
double calcExtra(int n, point* p, point* convex, double cutLen){
	return cutLen - graham(n, p, convex, 1, 1);
}
int main(){
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	int n;
	int pow2[16];
	pow2[0] = 1;
	for (int i = 1; i <= 15; i++)
		pow2[i] = pow2[i-1] * 2;
	scanf("%d", &n);
	double cutLen, extra, MaxExtra;
	int cutNum, minCutNum, getValue, maxgetValue;
	int leftTreeNum, minCutTreeHash = 0, cases = 0;
	bool first = true;
	while(n){
		if (first) first = false;
		else printf("\n");
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%d%d", &p[i].x, &p[i].y, &p[i].v, &p[i].l);
		minCutTreeHash = 0;
		for (int cutTreeHash = 1; cutTreeHash < pow2[n]; cutTreeHash++){
			getValue = 0;
			cutNum = 0;
			cutLen = 0;
			leftTreeNum = 0;
			for (int i = 0; i < n; i++)
				if (cutTreeHash & pow2[i]){
					cutLen += p[i].l;
					cutNum++;
				}
				else {
					getValue += p[i].v;
					p3[leftTreeNum++] = p[i];
				}
			extra = calcExtra(leftTreeNum, p3, convex, cutLen);
			if (extra >= 0 && (minCutTreeHash == 0 || (getValue>maxgetValue || getValue==maxgetValue && cutNum < minCutNum))){
				minCutNum = cutNum;
				maxgetValue = getValue;
				minCutTreeHash = cutTreeHash;
				MaxExtra = extra;
			}
		}
		printf("Forest %d\n", ++cases);
		printf("Cut these trees:");
		for (int i = 0; i < n; i++)
			if (minCutTreeHash & pow2[i]) printf(" %d", i+1);
		printf("\n");
		printf("Extra wood: %.2lf\n", MaxExtra);
		scanf("%d", &n);
	}
}