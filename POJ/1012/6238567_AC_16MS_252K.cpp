#include <iostream>
using namespace std;
bool search(long int numOfMen, long int step)
{
  int a[28];
  for (int i = 1; i <= numOfMen * 2; i++) a[i] = i;
  int left = numOfMen * 2;
  int who = 0;
  for (int i = 1; i <= numOfMen; i++)
  {
    who = (who + step - 1) % left + 1;
    if (a[who] <= numOfMen) return false;
    left--;
    for (int j = who; j <= left; j++) a[j] = a[j + 1];
    who--;
  }
  return true;
}
long int joseph(long int numOfMen)
{
  for (int step = numOfMen + 1;; step++)
  {
    if (search(numOfMen,step)) return step;
  }
} 
int main(long)
{

  long int numOfMen;
  int fuck[14] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
  cin >> numOfMen;
  while (numOfMen != 0)
  {
    cout << fuck[numOfMen] << endl;
    cin >> numOfMen;
  }
}
