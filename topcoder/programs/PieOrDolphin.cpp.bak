

#include <set>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
class PieOrDolphin
{
    private:
        vector<int> in, out;
        vector<set<int> > edgeOut, edgeIn;
        void reverse(int p){
            if (out[p] > in[p]){
                int q = *edgeOut[p].begin();
                edgeOut[p].erase(q);
                edgeOut[q].insert(p);

                edgeIn[q].erase(p);
                edgeIn[p].insert(q);

                out[p]--;
                in[p]++;

                out[q]++;
                in[q]--;

                if (out[q]-in[q] > 1){
                    reverse(q);
                }
            }else{
                int q = *edgeIn[p].begin();
                edgeIn[p].erase(q);
                edgeIn[q].insert(p);

                edgeOut[q].erase(p);
                edgeOut[p].insert(q);

                in[p]--;
                out[p]++;

                in[q]++;
                out[q]--;

                if (in[q]-out[q] > 1){
                    reverse(q);
                }
            }
        }
    public:
        vector <int> Distribute(vector <int> choice1, vector <int> choice2)
        {
            int m = choice1.size();
            in = vector<int>(50, 0);
            out = vector<int>(50, 0);

            edgeOut = vector<set<int> >(50, set<int>());
            edgeIn = vector<set<int> >(50, set<int>());
            F(i,0,m){
                out[choice1[i]]++;
                in[choice2[i]]++;
                edgeOut[choice1[i]].insert(choice2[i]);
                edgeIn[choice2[i]].insert(choice1[i]);
            }

            while(true){
                int p = -1;
                F(i,0,50){
                    if (abs(out[i] - in[i]) > 1){
                        p = i;
                        break;
                    }
                }
                if (p == -1) break;
                else reverse(p);
            }
            vector<int> result(m, 1);
            F(i,0,m){
                if (edgeOut[choice1[i]].find(choice2[i]) == edgeOut[choice1[i]].end()){
                    result[i] = 2;
                }
            }
            return result;
        }


};
