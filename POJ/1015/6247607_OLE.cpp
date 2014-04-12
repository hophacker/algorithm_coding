#include<iostream>
#include<string>
#include<map>
#include<vector>
//---------------------------------------------------------------------------

using namespace std;

string str,temp;
vector<int> digit(10);

string convert()
{
           string  tp;
           digit.assign(10,0);
           for(int i = 0; i < str.size();i++)
                         digit[str[i] - '0']++;
           for(int i = 0 ; i < 10; i++) 
                        if(digit[i] > 9) {
                                   tp.push_back(digit[i]/10 + '0');
                                   tp.push_back(digit[i]%10 + '0');
                                   tp.push_back(i + '0');
                      }
                      else if(digit[i] != 0&& digit[i] < 10){
                                  tp.push_back(digit[i]+'0');
                                  tp.push_back(i+ '0');
           }
 
    return tp;
}
int main(int argc, char* argv[])
{
             map<string,int> Map;
            while(cin >> str && str != "-1") {
                    int step  = 2;
                    Map[str] = 1;
                     temp = str;
                     while (1) {
                                 string _tp = convert();
                                 int check = Map[_tp];
                                 if(check > 0){
                                               if (step == 2)
                                                                    cout<< temp <<" is self-inventorying"<<endl;
                                              else if (step -  check == 1)
                                                                    cout<< temp <<" is self-inventorying after "<<check - 1<<" steps"<<endl;
                                              else
                                                                   cout<< temp <<" enters an inventory loop of length "<<step - check<<endl;
                                             break;
                                 }
                                Map[_tp] = step;
                               step ++;
                               if(step > 16)    {
                                                 cout<< temp <<" can not be classified after 15 iterations"<<endl;
                                                break;
                              }
                              str = _tp;
             }
               Map.clear();
       }
              return 0;
}