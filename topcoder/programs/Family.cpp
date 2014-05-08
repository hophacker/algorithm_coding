#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std ;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
class Family
{
    private:
        int n;
        vector<int> sex;
        int sexN = 0;
    public:
        int findSexHelper(int x){
            if (sex[x] == -1){
                return x;
            }else{
                return sex[x] = findSexHelper(sex[x]);
            }
        }
        int findSex(int x){
            if (sex[x] == -1) return -1;
            else return findSexHelper(sex[x]);
        }
        string isFamily(vector <int> parent1, vector <int> parent2)
        {
            n = parent1.size();
            sex = vector<int>(n, -1);
            F(i,0,n)if (parent1[i] != -1){
                int sex1 = findSex(parent1[i]);
                int sex2 = findSex(parent2[i]);
                if (sex1 == -1 || sex2 == -1){
                    if (sex1 != -1){
                        sex[parent2[i]] = (sex1/2)*4+1 - sex1;
                    }else if (sex2 != -1){
                        sex[parent1[i]] = (sex2/2)*4+1 - sex2;
                    }else{
                        sex[parent1[i]] = sexN++;
                        sex[parent2[i]] = sexN++;
                    }
                }else if (sex1 == sex2) return "Impossible";
            }
            return "Possible";
        }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
