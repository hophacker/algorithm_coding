
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
class SwitchingGame
{
    public:
        int timeToWin(vector <string> states)
        {
            int M = states[0].length();
            string cur = string(M, '-');
            int cnt = 0;
//            F(i,0,states.size()) cout << states[i] << endl;
            FFE(i, states.size()-1, 1){
                F(j,0,M){
                    if (states[i][j] != '?' && states[i-1][j] == '?'){
                        states[i-1][j] = states[i][j];
                    }
                }
            }

            F(i,0,states.size()){
                int a = 0;
                int b = 0;
//                cout << endl << states[i] << endl;
                F(j,0,M){
                    if (states[i][j] == '-' && cur[j] == '+'){
                        cur[j] = '-';
                        a = 1;
                    }else if (states[i][j] == '+' && cur[j] == '-'){
                        cur[j] = '+';
                        b = 1;
                    }
                }
//                cout << a + b << endl <<endl;
                cnt += (a + b +1);
            }
            return cnt;
        }

        

};
