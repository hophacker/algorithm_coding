#include <string.h>
#include <iostream>
using namespace std;
#define lowbit(x) ((x)&((x)^((x)-1)))
#define MAXN 10000
typedef int elem_t;
struct sumSeg{
    elem_t a[MAXN],c[MAXN],ret;
    int n;
    void init(int i){
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        n=i;
    }
    void update(int i,elem_t v){
        for (v-=a[i],a[i]+=v;
                i<=n;
                c[i-1]+=v,i+=lowbit(i));}
    elem_t query(int i){
        for (ret=0;
                i;
                ret+=c[i-1],i^=lowbit(i));
        return ret;
    }
};

int main(){
    sumSeg s;
    s.init(10);
    s.update(1, 1);
    s.update(2, 1);
    s.update(5, 1);
    s.update(7, 2);
    cout << s.query(5) << endl;
    cout << s.query(2) << endl;
    cout << s.query(7) << endl;

}
