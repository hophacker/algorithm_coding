#include<iostream>
#include<ctime>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(NULL));
    while(true){
        cout << "ZhouFan:" << rand() % 10 + 1 << endl; 
        getchar();
        cout << "FengJie:" << rand() % 10 + 1 << endl;
        getchar();
        cout << "Cuibin:" << rand() % 10 + 1 << endl;
        getchar();
        cout << "Wangpeiyue:" << rand() % 10 + 1 << endl;
        getchar();
    }
}

