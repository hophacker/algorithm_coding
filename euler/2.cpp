#include<iostream>
using namespace std;

int main(){
    int A = 1, B = 1, C;
    int fibMax = 4000000;
    long long total = 0;
    while (B <= fibMax){
        if (B % 2 == 0){
            total += B;
            cout << B << endl;
        }
        C = A+B;
        A = B;
        B = C;
    }
    cout << total << endl;
}
