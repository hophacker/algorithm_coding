#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
class BuildingHeights
{
    public:
        int minimum(vector <int> heights)
        {
            int n = heights.size();
            vector<int> sum(n+1);
            sort(heights.begin(), heights.end());
            sum[0] = 0;
            FE(i,1,n) sum[i] = sum[i-1] + heights[i-1];

            int ans = 0;
            for (int d = 2; d <= n; d++){
                int minLevel = INT_MAX;
                for (int i = 0; i <= n-d; i++){
                    int levels = heights[i+d-1] * d - (sum[i+d] - sum[i]);
                    minLevel = min(levels, minLevel);
                }
                ans = ans xor minLevel;
            }
            return ans;
        }
};
