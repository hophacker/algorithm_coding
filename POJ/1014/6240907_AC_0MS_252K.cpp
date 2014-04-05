#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  int a[6],i,j,num,numberOfDate = 0;
  ifstream icin;
//  icin.open("poj1014.txt");
  bool ok[64],*pan = &ok[30];
  bool ok1[64],*panNow = &ok1[30];
  bool isOver = true;
  for (i = 0; i <= 5; i++)
  {
    cin >> a[i];
    if (a[i] != 0) isOver = false;
  }
  while  (!isOver)
  {
    numberOfDate++;
    for (i = - 30; i <= 30; i++)
      *(pan + i) = false;
    *pan = true;
    for (i = 0; i <= 5; i++)
    if (a[i] > 0)
    {
      for (j = -30; j <= 30; j++) *(panNow + j) = false;
      int point = i + 1;
      if (a[i] % 2 == 0) num = 0; else num = point;
      for (int k = 0; k <= (a[i] / 2); k++)
      {
        if ((num + k * 2 * point) > 60) break;
        for (int t = -30; t <= 30; t++)
        {
          if ((t + num + k * 2 * point) > 30) break;
          if (*(pan + t))    *(panNow + t + num + k * 2 * point) = true;
        }
      }
    for (j = -30; j <= 30; j++) *(pan + j) = ((*(panNow + j)) || (*(panNow - j)));
    //for (j = -15; j <= 15; j++) cout << pan[j] << " "; cout << endl;
    }
    if (pan[0])
      cout << "Collection #" << numberOfDate << ":" << endl << "Can be divided." << endl;
    else 
      cout << "Collection #" << numberOfDate << ":" << endl << "Can't be divided."<< endl;
    isOver = true;
    for (i = 0; i <= 5; i++)
    {
      cin >> a[i];
      if (a[i] != 0) isOver = false;
    }
    if (!isOver) cout << endl;
  }
 // icin.close();
}
