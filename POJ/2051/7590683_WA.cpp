#include<iostream>
#include<memory.h>
#include<fstream>
#include<string>
using namespace std;
#define MAXN 10000
#define _cp(a,b) (a.t<b.t||(a.t==b.t&&a.id<b.id))
typedef struct elem_t
{
	int id, pe, t;
};
struct heap{
	elem_t h[MAXN];
	int n,p,c;
	void init(){n=0;}
	void ins(elem_t e){
		for (p=++n;p>1&&_cp(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p]=e;
	}
	int del(elem_t& e){
		if (!n) return 0;
		for (e=h[p=1],c=2;c<n&&_cp(h[c+=(c<n-1&&_cp(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];return 1;
	}
}_h;
int main()
{
	//freopen("poj.in", "r", stdin);
	//freopen("poj.out", "w", stdout);
	string s;
	elem_t e;
	_h.init();
	int id, pe, n = 0, num;
	for (cin>>s;s!="#";cin>>s){
		cin >> e.id >> e.pe; e.t = e.pe;
		_h.ins(e);
	}
	cin >> num;
	while (num--)
	{
		_h.del(e);
		cout << e.id << endl;
		e.t += e.pe;
		_h.ins(e);
	}
}
