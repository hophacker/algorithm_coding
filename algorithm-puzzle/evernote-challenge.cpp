#include<iostream>
#include<string>
#include<vector>
#define ui unsigned int
using namespace std;



int main(){
    vector<string> buf;
    int head, tail;
    int n, k;
    char cho;
    cin >> n;
    buf.resize(n);
    head = tail = 0;
    int count = 0;
    string s;
    while(cin >> cho && cho != 'Q'){
        if (cho == 'A'){
            cin >> k;
            while(k--){
                cin >> s;
                buf[tail++] = s;
                if (tail >= n) tail = 0;
                count++;
            }
            if (count > n){
                count = n;
                head = tail;
            }
        }else if (cho == 'R'){
            cin >> k;
            head += k;
            if (head >= n) head -= n;
            count -= k;
        }else if (cho == 'L'){
            for (int c = count, h = head; c > 0; c--){
                cout << buf[h] << endl;
                h++;
                if (h == n) h = 0;
            }
        }
    }
}
