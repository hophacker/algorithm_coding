#include<set>//!
#include<vector>//!
#include<iostream>
#include<string>
using namespace std;

class vowel{
private: //
    set<char> vowels;
public: //
    vowel(){
		vowels.insert('a');
		vowels.insert('e');
		vowels.insert('i');
		vowels.insert('o');
		vowels.insert('u');
		vowels.insert('A');
		vowels.insert('E');
		vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
	}
    bool isVowel(char c){
    }
    void reverse_vowel(string &s){
        vector<int> pos;
        for (int i = 0; i < s.length(); i++) if (vowels.find(s[i]) != vowels.end()){
            pos.push_back(i);
        }
        int n = pos.size();
        //started from here
        for (int i = 0; i < n/2; i++){
            swap(s[pos[i]], s[pos[n-1-i]]);
        }
    }
};//don't forget it
int main(){
}
