#include<iostream>
#include<string.h>
#include<fstream>

#define val(c) (('0'<=c&&c<='9')? c-'0':c-'a'+10)
using namespace std;

int n, len;
char s[62];
int digit[37];
int num[62];
int base;
long long value;

int main()
{
    //ifstream cin("in");
    cin >> n;
    for (int cases = 1; cases <= n; cases++){
        cin >> s;
        memset(digit, -1, sizeof(digit));
        len = strlen(s);

        digit[val(s[0])] = 1;
        num[0] = 1;
        base = 0;
        for (int i = 1; i < len; i++){
            int p = val(s[i]);
            if (digit[p] != -1)
                num[i] = digit[p];  
            else{
                digit[p] = base++;
                if (base == 1) base++;
                num[i] = digit[p];
            }
        }
        if (base == 0) base = 2;
        value = 0;
        for (int i = 0; i < len; i++)
            value = value * base + num[i];
        cout << "Case #" << cases << ": " << value << endl;
    }
}
