#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> stringToStringArray(string s){
    vector<string> res;
    int state = 0;
    string e;
    for (int i = 0; i < s.length(); i++){
        switch(state){
            case 0:
                switch(s[i]){
                    case ' ':
                        break;
                    case '"':
                        state = 2;
                        break;
                    default:
                        e.push_back(s[i]);
                        state = 1;
                }
                break;
            case 1:
                switch(s[i]){
                    case ' ': 
                        res.push_back(e);
                        e.clear();
                        state = 0;
                        break;
                    default:
                        e.push_back(s[i]);
                }
                break;
            case 2:
                switch(s[i]){
                    case '"':
                        state = 0;
                        res.push_back(e);
                        e.clear();
                        break;
                    case '\\':
                        state = 3;
                        break;
                    default:
                        e.push_back(s[i]);
                }
                break;
            case 3:
                state = 2;
                e.push_back(s[i]);
                break;
        }
//        cout << s[i] << ' ' << state << endl;
    }
    return res;
}

int main(){
    vector<string> res = stringToStringArray("a b cde \"f g\"\"h j\"");
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}
