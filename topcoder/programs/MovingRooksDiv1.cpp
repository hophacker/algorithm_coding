#include <vector>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
class MovingRooksDiv1
{
private:
    int n;
    vector<int> ans;
    bool check(vector<int> a, vector<int> b){
        vector<int> pos_a(n);
        F(i,0,n) pos_a[a[i]] = i;

        F(i,0,n){
            if (a[i] >= b[i]){
                int j = pos_a[b[i]];
                swap(a[i], a[j]);
                swap(pos_a[a[i]], pos_a[a[j]]);
            }else return false;
        }
        return true;
    }
    void output(vector<int> a, vector<int> b){
        vector<int> pos_a(n);
        F(i,0,n) pos_a[a[i]] = i;

        F(i,0,n){
            if (a[i] > b[i]){
                int j = pos_a[b[i]];
                ans.push_back(i);
                ans.push_back(j);
                swap(a[i], a[j]);
                swap(pos_a[a[i]], pos_a[a[j]]);
            }
        }
    }
public:
    vector <int> move(vector <int> Y1, vector <int> Y2)
    {
        ans.clear();
        n = Y1.size();
        if (!check(Y1, Y2)) return vector<int>(1,-1);
        output(Y1, Y2);
        return ans;
    }
};
