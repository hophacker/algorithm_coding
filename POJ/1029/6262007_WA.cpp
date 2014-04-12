//#define cin ccin
#include<fstream>
#include<memory.h>
#include<iostream>
using namespace std;
int main()
{
  ifstream ccin;
  ccin.open("data.in");
  int n,times;
  int comp[101][2][501];
  int compNum[101];
  bool appear[1001];
  char  weight[1001];
  int falseCoin;
  memset(appear,0,sizeof(appear));
  cin >> n >> times;
  for (int i = 0; i < times ; i++)
  {
    cin >> compNum[i];
    for (int j = 0; j <= 1; j++)
      for (int k = 0; k < compNum[i]; k++)
	  {
        cin >> comp[i][j][k];
		 appear[comp[i][j][k]] = true;
	  }
    cin >> weight[i]; 
  }
  int num = 0,t;

  for (int i = 1; i <= n; i++)
	if (!appear[i])
   {
     num++;
	 t = i;
   }
  if (num == 1) 
	appear[t] = true;
  falseCoin = -1;
  for (int coin = 0; coin < n; coin++)
  if (appear[coin + 1])
    for (int state = 0; state <= 1; state++) //1 express weitgher;
    {
	   bool isItFalse = true;

      for (int i = 0; i < times; i++)
      {
        int left = 0;
        int right = 0;
        bool pan = false;
        for (int j = 0; j < compNum[i]; j++)
        {
          
          if (comp[i][0][j] != coin + 1) left += 1;
          else 
          {
            if (state == 0)
              left += 0;
            else 
              left += 2;
          }
          
          if (comp[i][1][j] != coin + 1) right += 1;
          else 
          {
            if (state == 0)
              right += 0;
            else 
              right += 2;
          }
        }
        
        if ((left > right)&&(weight[i] == '>')) pan = true;
        if ((left < right)&&(weight[i] == '<')) pan = true;
        if ((left == right)&&(weight[i] == '=')) pan = true;
        if (!pan)
        {
          isItFalse = false;
          break;
        }
      }
      if (isItFalse) 
      {
        falseCoin = coin;
        break;
      }
    }
  cout << falseCoin+1 << endl;
  system("PAUSE");
}
