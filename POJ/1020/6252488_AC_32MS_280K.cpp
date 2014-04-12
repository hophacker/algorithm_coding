//#define cin ccin 
#include<fstream>
#include<iostream>
#include<memory.h>

using namespace std;

  int nOfData,
      edge,
      area,
      nOfCake,
      i,
      j,
      k;
  int used[41],cake[11];

bool fill(int dep)
{
  int lowR,colu;
  bool flag;
  if (dep == nOfCake + 1) return true;
  lowR = used[1]; 
  colu = 1;
  for (int i = 2; i <= edge; i++)
    if (used[i] < lowR) 
    {
      lowR = used[i];
      colu = i;
    }
  
  for (int i = 10; i >= 1; i--)
    if ((cake[i] > 0) && (i + lowR <= edge + 1) && (i + colu <= edge + 1))
    {
      flag = true;
      for (int j = colu; j <= colu + i - 1; j++)
        if (used[j] > lowR) flag  = false;
      if (flag)
      {
        for (int j = colu; j <= colu + i - 1; j++)
          used[j] += i;
        cake[i]--;
        if (fill(dep + 1)) return true;
        cake[i]++;
        for (int j = colu; j <= colu + i - 1; j++)
          used[j] -= i;
      }
    }
  return false;
}

 
int main()
{
  ifstream ccin;
  ccin.open("data.in");    
  cin >> nOfData;

  while (nOfData--)
  {
    area = 0;
    cin >> edge >> nOfCake;
    for (i = 1; i <= edge; i++)
    {
      used[i] = 1;
    }
    memset(cake,0,sizeof(cake));
    for (i = 1; i <= nOfCake; i++) 
    {
      int kidEdge;
      cin >> kidEdge;
      cake[kidEdge]++;
      area += kidEdge * kidEdge;
    }
    
    if (area == edge * edge)
	{ 
     if ((fill(1))) cout << "KHOOOOB!" << endl; 
	 else cout << "HUTUTU!" << endl;
	}
    else 
      cout << "HUTUTU!" << endl;
  }
  
  system("PAUSE");
}
