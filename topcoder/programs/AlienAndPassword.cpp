#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std ;
#define F(i,L,R) for (int i = L; i < R; i++)
#define ll long long
#define MOD 100000000000007
class AlienAndPassword
{
    public:
        inline ll calc(string& S, int t){
            ll ans = 0;
            F(i,0,S.length()) if (i != t){
                ans = (ans * 256 + S[i]) % MOD;
            }
            return ans;
        }
        int getNumber(string S){
            map<ll,bool> has;
            F(i,0,S.length()){
                ll k = calc(S,i);
                has[k] = true;
            }
            return has.size();
        }

        
};
