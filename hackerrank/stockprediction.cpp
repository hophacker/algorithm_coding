#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (ui i = L; i < R; i++)
#define FE(i,L,R) for (ui i = L; i <= R; i++)
#define FF(i,L,R) for (ui i = L; i > R; i--)
#define FFE(i,L,R) for (ui i = L; i >= R; i--)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(a,x) memset(a,x,sizeof(x))
#define ll long long
#define ui unsigned int
#define us unsigned short
#define price(i) prices[i][prices[i].size()-1]

struct node{
    int ow;
    double val;
    node(const int& o, const double& v){
        ow = o;
        val = v;
    }
    bool operator<(const node &b)const{
        return this->val < b.val;
    }
};
/* Head ends here */
vector<double> calValue(vector < vector <double> > & prices){
    vector<double> val(prices.size());
    F(i,0,prices.size()){
        double ratio = 1;
        FFE(j,prices[i].size()-1,1){
            val[i] += ratio * (prices[i][j]-prices[i][j-1]);
            ratio /= 2;
        }
    }
    return val;
}
void printTransactions(double m, int k, int d, vector <string> name, vector <int> owned, vector < vector <double> > prices) {
    vector<double> val = calValue(prices);
    vector<node> buy;
    vector<string> ans;
    char s[10][100];
    int sN = 0;
    double limit = 0.1;
    F(i,0,val.size()){
        double ratio = val[i] / price(i);
        if (ratio > 0){
            int sell;
            if (ratio > 0.5) sell = owned[i];
            else sell = (owned[i]+1)/2;
            if (sell > 0){
                sprintf(s[sN], "%s SELL %d\n", name[i].c_str(), sell);
                sN++;
            }
        }else if (ratio < -0.125){
            buy.push_back(node(i,val[i]));
        }
    }
    sort(buy.begin(),buy.end());
    F(i,0,buy.size()){
        int o = buy[i].ow;
        int size = prices[o].size();
        int num;
        if (i == buy.size() -1) num = (int)(m/price(o));
        else num =  ((int)(m/price(o)) + 1) / 2;
        if (num > 0) {
            sprintf(s[sN], "%s BUY %d\n", name[o].c_str(), num);
            sN++;
        }
        m -= num * price(o);
    }
    printf("%d\n", sN);
    F(i,0,sN) printf("%s", s[i]);
}

/* Tail starts here */
int main(void) {
    double _m;
    cin >> _m;
    
    int _k;
    cin >> _k;
    
    int _d;
    cin >> _d;
    
    vector<string> _name;
    vector<int> _owned;
    vector < vector <double> > _prices;
    
    string _name_item;
    int _owned_item;
    double _prices_item_item;
    
    for(int _i=0; _i<_k; _i++) {
        cin >> _name_item;
        _name.push_back(_name_item);
        
        cin >> _owned_item;
        _owned.push_back(_owned_item);

        vector <double> _prices_item;
        for(int _j = 0; _j<5; _j++) {
            cin >> _prices_item_item;
            _prices_item.push_back(_prices_item_item);
        }
        _prices.push_back(_prices_item);        
        
    }
    
    printTransactions(_m, _k, _d, _name, _owned, _prices);
    
    return 0;
}
