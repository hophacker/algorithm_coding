#include <iostream>
using namespace std;
bool check(int div,int KI[],int li)
{
    int i = 0;
    int remain = 0;
    while (i < li)remain = (remain * 1000 + KI[i++]) % div;
    return (remain == 0) ? false:true;
}
int main(int argc, char* argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out1.txt", "w", stdout);
    //create prime table
    int const SIZE = 1000005;
    bool isprime[SIZE];
    memset(isprime, 1, sizeof(isprime));
    int prime[80000];
    memset(prime, 0, sizeof(prime));
    isprime[0] = isprime[1] = false;
    int j = 0;
    for (int i = 2; i < SIZE; ++i)
        if (isprime[i] == true)
        {
            prime[j++] = i;
            int k = 2;
            while(i * k < SIZE)isprime[i * k] = false, ++k;
        };

    int L,KI[40];
    char K[105];
    while (scanf("%s %d", &K, &L) != EOF && K[0] != '0' && L != 0)
    {
        //init 1000 base int array
        int N = strlen(K);
        int lowbound = 0, upbound = (N % 3 == 0) ? 3: N % 3;
        int li = (N % 3 == 0)? N / 3: N /3 + 1;
        int i = 0;
        while (upbound <= N)
        {
            int num = 0;
            for (int j = lowbound; j < upbound; ++j) num = num * 10 + (K[j] - '0');
            KI[i++] = num;
            lowbound = upbound;
            upbound += 3;
        }

        //check good
        i = 0;
        bool good = true;
        while(prime[i] < L)
        {
            if (check(prime[i], KI, li) == false)
            {
                good = false;
                break;
            }
            ++i;
        }

        if (good == true) cout <<"GOOD\n";
        else cout << "BAD "<<prime[i]<<endl;
    }
    return 0;
}
