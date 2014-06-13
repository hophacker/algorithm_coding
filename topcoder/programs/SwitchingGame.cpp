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
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define ll long long
#define ui unsigned int
class SwitchingGame
{
    public:
        int timeToWin(vector <string> states)
        {
            int M = states[0].length();
            vector<int> cur = vector<int>(M, -1);
            int cnt = 0;

            F(i,0,states.size()){
                bool turnOn = 0;
                bool turnOff = 0;
//                cout << endl << states[i] << endl;
                F(j,0,M){
                    if (states[i][j] == '-' && cur[j] == 1){
                        turnOff = true;
                    }else if (states[i][j] == '+' && cur[j] == -1){
                        turnOn = true;
                    }
                }
                F(j,0,M){
                    if (states[i][j] == '+')
                        cur[j] = 1;
                    else if (states[i][j] == '-')
                        cur[j] = -1;
                    else if (states[i][j] == '?'){
                        if (cur[j] == 1 && turnOff) cur[j] = 0;
                        else if (cur[j] == -1 && turnOn) cur[j] = 0;
                    }
                }
                cnt += (turnOn + turnOff +1);
            }
            return cnt;
        }

        

};
