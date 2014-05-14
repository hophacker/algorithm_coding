#include <sstream>
#include <vector>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define bit(x,i) (x&(1<<i))
#define ui unsigned int
class MyLongCake
{

private:
    vector<bool> selectPrimes(int maxN){
        vector<bool> p(maxN, true);
        p[0] = p[1] = false;
        int i = 2;
        while(i < maxN){
            while(!p[i] && i < maxN) i++;
            int j = i + i;
            while(j < maxN){
                p[j] = false;
                j+= i;
            }
            i += 1;
        }
        return p;
    }
    vector<int> getPrimes(int maxN){
        vector<bool> p = selectPrimes(maxN);
        vector<int> pInt;
        for (ui i = 0; i< p.size(); i++) 
            if (p[i]) pInt.push_back(i);
        return pInt;
    }
    public:

        int cut(int n)
        {
            vector<int> primes = getPrimes(n);
            vector<int> pFactor;
            F(i,0,primes.size()){
                if (n % primes[i] == 0) pFactor.push_back(primes[i]);
            }
            int total = 0;
            F(x,0,1<<pFactor.size()){
                bool minus = true;
                int fac = 1;
                    F(i,0,pFactor.size()) if (bit(x,i)){
                        fac *= pFactor[i];
                        minus = !minus;
                    }
                if (fac != 1){
                    if (minus) total -= (n/fac - 1);
                    else total += (n/fac - 1);
                }
            }
            return total+1;
        }

        

};
