#include <vector>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define ll long long
class LongWordsDiv1
{
    private: 
        const ll mod = 1000000007;
        void ex_euclid(ll a, ll& x, ll b, ll& y){
            ll x1, y1;
            if (a == 1){
                x = 1;
                y = 0;
                return;
            }
            ex_euclid(b%a, x1, a, y1);
            y = x1;
            x = y1 - (b/a) * x1;
        }
        ll rev_mod(ll a){
            ll x, y;
            ex_euclid(a,x,mod,y);
            return (x%mod+mod)%mod;
        }
    public:
        int count(int n)
        {
            if (n <= 2) return n;
            vector<ll> dp(n+1);
            vector<ll> jie(n+1);
            vector<ll> revJie(n+1);
            jie[1] = 1;
            jie[2] = 2;
            revJie[1] = rev_mod(1);
            revJie[2] = rev_mod(2);
            dp[1] = 1;
            dp[2] = 2;
            FE(i,3,n){
                jie[i] = i * jie[i-1] % mod;
                revJie[i] = rev_mod(jie[i]);
                dp[i] = dp[i-1] * i;
                FE(j,1,i-2){
                    dp[i] = (dp[i] + dp[j] * dp[i-1-j] % mod * (jie[i]*revJie[j]%mod*revJie[i-j-1]%mod) % mod) % mod;
                }
            }
            return dp[n];
        }
};
