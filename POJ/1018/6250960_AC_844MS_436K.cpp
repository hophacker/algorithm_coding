//#define cin ccin 
//#define cout ccout
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

double min(double a, double b)
{
  if (a < b) return a;
    else return b;
}
int main()
{
   double  b[102][101],
		       p[102][101],
		       pTotal[102],
		       total,
		       minB;

  int nOfData,
	  nOfChoice[102];
     
//   ifstream ccin;
//	ccin.open("poj1018.txt");
  
  int n;//one test for n lines of  different devices;
  cin >> nOfData;

  for (int k = 1; k <= nOfData; k++)
  {
    cin >> n;
    total = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> nOfChoice[i];
      for (int j = 1; j <= nOfChoice[i]; j++)
        cin >> b[i][j] >> p[i][j];
    }   
    
    double maxB_P = -99999999999.0 ;
    
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= nOfChoice[i]; j++)
      {
        total = p[i][j]; 
        minB = b[i][j];
        bool youCan = true;
        for (int ii = 1; ii <= n; ii++)
          if (ii != i)
          {
            youCan = false;
            double minP = 999999;
            for (int jj = 1; jj <= nOfChoice[ii]; jj++)
              if (b[ii][jj] >= minB)
              {
                youCan = true;
                if (p[ii][jj] < minP) minP = p[ii][jj];
              }
            if (youCan)  total += minP;
              else break;  
          }
        if (youCan)
          if (minB / total > maxB_P) maxB_P = minB /total;
      }
    }

    printf( "%.3lf\n", maxB_P);
    
  }
  system("PAUSE");
}
