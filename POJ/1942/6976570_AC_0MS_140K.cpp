#include <iostream>
using namespace std;
double CNM(unsigned int N, unsigned int M)
{
    M = (M > N - M) ? N - M : M;
    double ret = 1;
    while(M > 0)ret *= double(N--) / double (M--);
    return ret;
}
int main(int argc, char* argv[])
{
    unsigned int A, B;
    while(scanf("%d %d", &A, &B) && !(A == 0 && B == 0))
        printf("%.0lf\n",CNM(A + B, B));
    return 0;
}