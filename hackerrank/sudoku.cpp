#include<iostream>
#include<cstring>
using namespace std;
#define I int
#define F(i) for(I i=0;i<9;i++)
#define C(a) memset(a,0,sizeof(a));
#define G y==8?S(x+1,0):S(x,y+1)
#define A(z) l[x][k]=r[y][k]=b[x/3][y/3][k]=z
#define R return
I n,k,a[9][9],l[9][9],r[9][9],b[3][3][9];
I P(){F(i)F(j)cout<<a[i][j]+1<<(j==8?'\n':' ');}
I S(I x,I y){if(x>8){P();R 1;}if(~a[x][y]){if(G)R 1;}else{F(k)if(!l[x][k]&&!r[y][k]&&!b[x/3][y/3][k]){A(1);a[x][y]=k;if(G)R 1;A(0);}a[x][y]=-1;}R 0;}
I main(){cin>>n;while(n--){C(l)C(r)C(b)F(x)F(y){cin>>k;a[x][y]=--k;if(~k)A(1);}S(0,0);}}
