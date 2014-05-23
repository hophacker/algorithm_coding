#include<iostream>
using namespace std;

int main(){
    char a[4];
    int *b = (int*)a;
    *b = 1;
    if (a[0]) cout << "Little Endian" << endl;
    else cout << "Big Endian" << endl;
}
