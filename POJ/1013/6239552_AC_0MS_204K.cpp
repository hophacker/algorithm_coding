#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
bool pan;
bool search(char* s, int which, int state)
{
  int len = 0;
  bool ok;
  while (s[len] != ' ') len++;
  ok = false;
  for (int i = 0; i <= len - 1; i++)
    if (s[i] == which + 'A')
    {
      ok = true;
      pan = true;
      if ((state == 1) && (s[len * 2 + 2] == 'u') || (state == -1) && (s[len * 2 + 2] == 'd')) return true;
      else return false;
     
    }
  for (int i = len + 1; i <= len * 2; i++)
    if (s[i] == which + 'A') 
    {
      ok = true;
      pan = true;
      if ((state == -1) && (s[len * 2 + 2] == 'u') || (state == 1) && (s[len * 2 + 2] == 'd')) return true;
      else return false;
    }
  if ((!ok) && ((s[len * 2 + 2] == 'u') || (s[len * 2 + 2] == 'd'))) return false;
  return true;
}
int main()
{
  int n,which,state;
  ifstream icin;
  char a[100],b[100],c[100];
  char *s1 = a, *s2 = b, *s3 = c;
//  icin.open("poj1013.txt");
  cin.getline(s1,100,'\n');
  n = atoi(s1); //!!!!!!!!!
   
  for (int i = 1; i <= n; i++)
  {
    cin.getline(s1,100,'\n');
    cin.getline(s2,100,'\n');
    cin.getline(s3,100,'\n');
    for (int j = 0; j <= 11; j++)
      {
        pan = false;
        if ((search(s1,j,1))&&(search(s2,j,1))&&(search(s3,j,1))) 
        if (pan) 
        {
          which = j;
          state = 1;
          break;
        }
        pan = false;
        if ((search(s1,j,-1))&&(search(s2,j,-1))&&(search(s3,j,-1)))
        if (pan)
        {
          which  = j;
          state = -1;
          break;
        }
      }
    cout << static_cast<char>(which + 'A') << " is the counterfeit coin and it is " ;
    cout << ((state == -1)?"light.":"heavy."); cout << endl;
  }
//  system("PAUSE");
//  icin.close();
}

