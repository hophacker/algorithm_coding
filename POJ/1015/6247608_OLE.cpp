//#define cin icin
//#define cout ocout
#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;

//ifstream icin;
//ofstream ocout;
   
/* 转换数字 */
string calc(string n)
{
	ifstream icin;
ofstream ocout;

    int j = 0;
    int num[10] = {0};
    char inv[80];
    for (int i = 0; i < n.length(); i++)
    {
        num[n[i] - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (num[i] > 0 && num[i] < 10)
        {
            inv[j++] = num[i] + '0';
            inv[j++] = i + 48;
        }
        else if (num[i] >= 10)
        {
            inv[j++] = num[i] / 10 + '0';
            inv[j++] = num[i] % 10 + '0';
            inv[j++] = i + '0';
        }
    }
    inv[j] = '\0';
    return inv;
}
 
/* 求解 */
void work(string n)
{
	ifstream icin;
ofstream ocout;

    int i, j;
    bool ok = false;
    string inv[16];
    string tmp = n;
    for (i = 0; i < 15; i++)
    {
        tmp = calc(tmp);
        for (j = 0; j < i; j++)
        {
            if (tmp == inv[j])
            {
                ok = true;
                break;
            }
        }
        if (ok)
        {
            if (i == 1 && j == 0)
            {
                cout << n << " is self-inventorying\n";
                return;
            }
            else if (j == i - 1)
            {
                cout << n << " is self-inventorying after " << i << " steps\n";
                return;
            }
            else
            {
                cout << n << " enters an inventory loop of length " << i - j << endl;
                return;
            }
        }
        inv[i] = tmp;
    }
    cout << n << " can not be classified after 15 iterations\n";
}
 
int main()
{
    string n;
    while(1)
    {
        cin >> n;
        if (n == "-1")  break;
        work(n);        
    }
    //system("pause");
    return 0;
}
