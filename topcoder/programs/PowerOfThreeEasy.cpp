#include <iostream>
#include <string>
using namespace std;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long ll ;

const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class PowerOfThreeEasy
{
    public:
        bool isMod3(ll a){
            while(a % 3 == 0 ) a /= 3;
            return a == 1;
        }
        string ableToGet(int x, int y)
        {
            if (x < 0 || y < 0) return "Impossible";
            if (!isMod3(((ll(x)+y))*2+1)) return  "Impossible";
            while(x != 0 && x % 3 != 2)
                x /= 3;
            return x % 3 == 2?"Impossible":"Possible";
        }
};
