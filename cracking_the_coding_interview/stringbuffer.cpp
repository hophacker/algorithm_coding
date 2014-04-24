#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class newstringbuf{
private:
    char* char_seq;
    int length;
    int capacity;
public:
    newstringbuf(){
        length = capacity = 0;
    }
    newstringbuf(string s){
        length = s.length();
        if (length < 10) length = 10;
        capacity = length*2;
        char_seq = new char[capacity];
        for (int i = 0; i < length; i++) char_seq[i] = s[i];
    }
    void expand(int newLength){
        char *s = new char[newLength * 2];
        memcpy(s, char_seq, sizeof(char) * length);
        swap(s, char_seq);
        free(s);
    }
    void append(string s){
        if (s.length() + length > capacity){
            expand(s.length() + length);
        }
        for (int i = 0; i < s.length(); i++){
            char_seq[i + length] = s[i];
        }
        length += s.length();
    }
    friend ostream& operator <<(ostream &os, newstringbuf& n){
        for (int i = 0; i < n.length; i++)
            os << n.char_seq[i];
        return os;
    }
};
int main(){
    newstringbuf sb("fengjie");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    sb.append("hello");
    cout << sb << endl;
}
