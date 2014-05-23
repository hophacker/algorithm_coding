
#include <sstream>
#include <cmath>
#include <set>
#include <list>
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

class RadioRange
{
    public:
    struct node{
        double b, e;
        bool operator<(const node& other)const{
            return b < other.b;
        }
        node(double bb, double ee):b(bb), e(ee){
        }
    };

        double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int z)
        {
            double Z = z;
            vector<node> p;
            F(i,0,X.size()){
                double d = sqrt(1.0*X[i]*X[i] + 1.0*Y[i]*Y[i]);
                if (d-R[i] <= Z){
                    p.push_back(node(max(d-R[i],0.0), min(d+R[i],Z)));
                }
            }

            if (p.size() == 0) return 1.0;
            sort(p.begin(), p.end());


            double ok_seg = min(p[0].b, 1.0*Z);

            int i = 0;
            double e_max = 0.0;
            while(i < p.size()){
                e_max = p[i].e;
                int j = i+1;
                while(j < p.size() && p[j].b <= e_max){
                    e_max = max(e_max, p[j].e),j++;
                }
                if (j < p.size()){
                    ok_seg += p[j].b - e_max;
                }
                i = j;
            }
            ok_seg += Z - e_max;
            return ok_seg / Z;
        }

};
