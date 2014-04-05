
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    double N,C,L;
    while(scanf("%lf%lf%lf",&L,&N,&C)&&N>=0&&C>=0&&L>=0)
    {
        if(N==0||L==0||C==0)
        {
            printf("0.000\n");
            continue;
        }

        double minv = 0,maxv = acos(-1.0), midv;
        double L2 = ( 1 + N * C ) * L;
        while(maxv - minv > 1e-12)    
        {
            midv = (minv + maxv) / 2;
            if( 2 * L2 / L > midv / sin(midv / 2))
                minv = midv;
            else
                maxv = midv;
        }
        printf("%.3lf\n",L2 / midv * (1-cos(midv / 2)));
    }
    return 0;
}