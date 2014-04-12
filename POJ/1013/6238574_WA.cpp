#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
bool search(char* s, int which, int state)
{
  for (int i = 0; i <= 3; i++)
    if (s[i] == which + 'A')
      if ((state == 1) && (s[10] == 'u') || (state == -1) && (s[10] == 'd')) return true;
      else return false;
  for (int i = 5; i <= 8; i++)
    if (s[i] == which + 'A') 
      if ((state == -1) && (s[10] == 'u') || (state == 1) && (s[10] == 'd')) return true;
      else return false;
  return true;
}
int main()
{
  int n,which,state;
  char a[100],b[100],c[100];
  char *s1 = a, *s2 = b, *s3 = c;
  cin.getline(s1,100,'\n');
  n = atoi(s1); //!!!!!!!!!
 // input >> ch;
  for (int i = 1; i <= n; i++)
  {
    cin.getline(s1,100,'\n');
    cin.getline(s2,100,'\n');
    cin.getline(s3,100,'\n');
    for (int j = 0; j <= 11; j++)
      {
        if ((search(s1,j,1))&&(search(s2,j,1))&&(search(s3,j,1))) 
        {
          which = j;
          state = 1;
          break;
        }
        if ((search(s1,j,-1))&&(search(s2,j,-1))&&(search(s3,j,-1)))
        {
          which  = j;
          state = -1;
          break;
        }
      }
    cout << static_cast<char>(which + 'A') << " is the counterfeit coin and it is " ;
    cout << ((state == -1)?"light.":"heavy."); cout << endl;
  }
}
