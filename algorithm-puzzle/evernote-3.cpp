#include<iostream>
using namespace std;
#define ll long long


int main(){
    ll s[1000], product = 1;
    int n, zeros = 0;
    int a, ai;
    bool firstNonZero = true;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        if (s[i] != 0){
            if (firstNonZero){
                firstNonZero = false;
                a = s[i];
                ai = i;
            }else
                product *= s[i];
        }
        else zeros++;
    }
    if (zeros > 1) {
        for (int i = 0; i < n; i++)
            cout << 0 << endl;
    }else if (zeros == 1){
        for (int i = 0; i < n; i++){
            if (s[i] == 0)
                cout << product * a << endl;
            else 
                cout << 0 << endl;
        }
    }else{
        for (int i = 0; i < n; i++){
            if (i == ai)
                cout << product << endl;
            else cout << product/s[i] * a << endl;
        }

    }
}
