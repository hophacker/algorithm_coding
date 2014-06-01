#include<iostream>
using namespace std;

void readline(char* buf, int size){
    char c;
    int i = 0;
    while(scanf("%c", &c) && c != '\n' && i < size-1){
        buf[i++] = c;
    }
    buf[i+1] = 0;
}
int main(){
    char buf[4098];
    readline(buf, 4098);
    printf("%s\n", buf);
}
