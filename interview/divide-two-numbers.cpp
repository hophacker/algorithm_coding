#include<iostream>
using namespace std;

// divide two positive numbers

int divide(int a, int b){
    int bb = b;
    int c = 0, pow = 1;

    if (a < b) return 0;

    while(bb <= a){
        bb <<= 1;
        pow <<= 1;
    }
    bb >>= 1;
    pow >>= 1;


    while(a >= b){
        if (a >= bb){
            a -= bb;
            c += pow;
        }
        bb >>= 1;
        pow >>= 1;
    }
    return c;
}
int main(){
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++){
            int c = divide(i, j);
            cout << c << endl;
            if (i/j != c){
                cout << i << ' ' << j << ' ' << c << endl;
            }
        }
}

