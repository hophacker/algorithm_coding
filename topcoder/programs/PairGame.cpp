#include <sstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
class PairGame
{
    public:
        int maxSum(int a, int b, int c, int d)
        {
            while(a != c || b != d){
                if (a == 0 || b == 0 || c == 0 || d == 0) return -1;
                if (a >= b && a >= c && a >= d)
                    a -= b;
                else if (b >= a && b >= c && b >= d)
                    b -= a;
                else if (c >= a && c >= b && c >= d)
                    c -= d;
                else if (d >= a && d >= b && d >= c)
                    d -= c;
            }
            return a+b;
        }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
