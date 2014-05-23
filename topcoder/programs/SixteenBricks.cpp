#include <vector>
#include <algorithm>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
class SixteenBricks
{
    public:
        int maximumSurface(vector <int> height)
        {
            sort(height.begin(), height.end());

            int sum = 0;

            F(i,8,16) sum += height[i] * 4;
            F(i,0,2) sum -= height[i] * 4;
            F(i,2,6) sum -= height[i] * 2;

            return sum + 16;
        }

        

};
