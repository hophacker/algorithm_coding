//#define cout ccout;
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
 // ifstream ccin;
 // ccin.open("data.in");
  unsigned int nOfData,
               n,
               total,
               number,
               number1;
  unsigned int a[100001];
  
  
 // char cao[100];
 // for (int i = 1; i <= 80; i++)
  //  ccin >> cao[i];
   
  a[0] = 0;
  for (int i = 1; i <= 99999; i++)
    if (i < 10) a[i] = a[i - 1] + 1;
    else if (i < 100) a[i] = a[i - 1] + 2;
         else if (i < 1000) a[i] = a[i -1 ] + 3;
              else if (i < 10000) a[i] = a[i - 1] + 4;
                   else a[i] = a[i - 1] + 5;

  
  
  cin >> nOfData;
  for (int kk = 1; kk <= nOfData; kk++)
  {
    cin >> n; 
  //  n = kk;int nn = kk;
    total = 0;
    for (number = 1;; number++)
    {
      total += a[number];
      if (total >= n) break;
    }
    n -= (total - a[number]);
    
    
    number1 = 1;
    while (a[number1] < n) number1++;
    n -= a[number1 - 1];
    
    
    int bit,digit[8];
    bit = 0;
    while (number1 > 0) 
    {
      bit++;
      digit[bit] = number1 % 10;
      number1 /= 10; 
    }
   cout << digit[bit - n + 1] << endl;
   // if (digit[bit - n + 1] == cao[kk] - '0') cout << "true" << " ";
  } 
  system("PAUSE");
}
