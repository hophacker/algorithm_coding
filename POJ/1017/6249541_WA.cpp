#include<iostream>
using namespace std;
int totalPack;

int min(int a, int b)
{
  if (a > b) return b;
    else return a;
}

void doit3(int a[7])
{
  int left,
      t;
  if (a[3] == 1) 
  {
    left = 36 - 9;
    a[2] -= (t = min(a[2], 5));
    left -= t * 4;
    a[1] -= min(a[1], left);
  }
  else if (a[3] == 2)
  {
    left = 36 - 18;
    a[2] -= (t = min(a[2], 3));
    left -= t * 4;
    a[1] -= min(a[1], left);
  }
  else if (a[3] == 3)
  {
    left = 36 - 27;
    a[2] -= (t = min(a[2], 1));
    left -= t * 4;
    a[1] -= min(a[1], left);
  }
  a[3] = 0;
}

int main()
{
  int a[7];
  
  bool readAgain = false;
  //read data first
  for (int i = 1; i <= 6; i++)
  {
    cin >> a[i];
    if (a[i] > 0) readAgain = true;
  }
  
  //solve it
  while (readAgain) 
  {
    totalPack = a[6] + a[5] + a[4];
    
    if (5 * a[4] > a[2])
    {
      a[2] = 0;
      a[1] -= min(a[1], (5 * a[4] - a[2]) * 4);
    }
    else
      a[2] = a[2] - 5 * a[4];  
    a[1] = a[1] - min(a[1], 11 * a[5]);
    a[6] = 0; a[5] = 0; a[4] = 0;
    
    totalPack += a[3] / 4;
    a[3] = a[3] % 4;
    // now a[1]:some  a[2]:some  a[3]<4
    
    if (a[3] > 0)
    {
      totalPack += 1;
      doit3(a);
    }
    
    if (a[2] > 0)
    {
      totalPack += a[2] / 9;
      a[2] = a[2] % 9;
      a[1] -= min(a[1], 36 - a[2] * 4);
      a[2] = 0;
    }
    
    totalPack += a[1] / 36;
    if (a[1] % 36 > 0) totalPack += 1;
    
    cout << totalPack << endl;\
    
    
    // read data again
    readAgain = false;
    for (int i = 1; i <= 6; i++)
      cin >> a[i];
    for (int i = 1; i <= 6; i++)
      if (a[i] > 0) readAgain = true;
  }
  
}
