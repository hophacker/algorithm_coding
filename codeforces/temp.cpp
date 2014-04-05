#include<iostream>       
using namespace std;      
const long N = 10000000;      
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};      
int main()      
{      
    for(long i = 2 ; i < N ; i ++)      
    {      
        if(! isNotPrime[i])      
            prime[num_prime ++]=i;    
//关键处1             
        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)      
        {      
            isNotPrime[i * prime[j]] = 1;      
            if( !(i % prime[j]))  //关键处2    
                break;      
        }      
    }      
    cout << num_prime << endl;
    return 0;      
} 

