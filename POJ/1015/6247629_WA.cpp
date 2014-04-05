//#define cin icin
//#define cout ocout 
#include <iostream>
#include <fstream>
using namespace std;
int personSelected[21];
int maxValue;
int d;
int n,m;

/*void display1(short int dpNum[201][21][41][2])
{
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++)
	  for (int k = 0; k <= 40; k++)
	    if (dpNum[i][j][k][0] > 0)   
		  ocout << i << " " << j << " " << k - 20 << "   " << dpNum[i][j][k][0] << " " <<  dpNum[i][j][k][1] << endl;
	  
}*/
int main()
{
  const int zero = 20;
  ifstream icin;
  ofstream ocout;
  int a[201][2];
  bool dynamic[201][21][41];
  short int dpNum[201][21][41][2];//0 表示当前最大值，1表示前驱。
 // icin.open("poj1015.txt");
 // ocout.open("poj1015fuck.txt");
  cin >> n >> m;
  int total = 0;
  while ((n && m) != 0)
  {
    total++;
    for (int i = 1; i <= n; i++) 
	   cin >> a[i][0] >> a[i][1];

	for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) //!!!!!!
	  for (int k = 0; k <= 40; k++)
	  {
        dynamic[i][j][k] = false;
		 dpNum[i][j][k][0] = 0;
		 dpNum[i][j][k][1] = 0;
	  }
    dynamic[1][1][a[1][0] - a[1][1] + zero] = true;
    dynamic[1][0][zero] = true; 
	dpNum[1][1][a[1][0] - a[1][1] + zero][0] = a[1][0] + a[1][1];
    for (int i= 2; i <= n; i++)
	{
	  dynamic[i][0][zero] = true;
	  int d = a[i][0] - a[i][1];
	  for (int j = 1; j <= m; j++)
	   for (int k = -20; k <= 20 ; k++)
	   {
	     if (j == 1)
		 {
		   if (a[i][0] + a[i][1] > dpNum[i][j][k+zero][0])
		   {
			  dynamic[i][1][zero+d] = true;
			  dpNum[i][1][zero+d][0] = a[i][0] + a[i][1];
			  dpNum[i][1][zero+d][1] = 0;
		   }
		 }
		 else
		 {
	     if ((k+d >= -20) && (k+d <= 20) && (dpNum[i-1][j-1][k+zero][0] != 0))
          if (dpNum[i-1][j-1][k+zero][0] + a[i][0] + a[i][1] > dpNum[i][j][k+d+zero][0])
			 {
			   dynamic[i][j][k+zero+d] = true;

			   dpNum[i][j][k+zero+d][0] = dpNum[i-1][j-1][k+zero][0] + a[i][0] + a[i][1];

			   dpNum[i][j][k+zero+d][1] = ((dynamic[i-1][j-1][k+zero])? (i-1):dpNum[i-1][j-1][k+zero][1]); 
			 }
		 }
		 if (dpNum[i-1][j][k+zero][0] > dpNum[i][j][k+zero][0]) 
		 {
		   dynamic[i][j][k+zero] = false;

		   dpNum[i][j][k+zero][0] = dpNum[i-1][j][k+zero][0];

		   dpNum[i][j][k+zero][1] = ((dynamic[i-1][j][k+zero])? i-1:dpNum[i - 1][j][k+zero][1] );
		 }
	  }
//display(dynamic);//dynamic[i][j][k]记录的是从前i个人中选j个人有无可能出现差值 k-shift；
	}
    maxValue = -1;
    for (int i = 0;i <= 20; i++)
	{
	  if (dpNum[n][m][i + zero][0] > 0) 
	  {
        d = i;
		 if (dpNum[n][m][-i + zero][0] > dpNum[n][m][i + zero][0]) d = -i;
		 break;
	  }
	  if (dpNum[n][m][-i + zero][0] > 0)
	  {
        d = -i;
        break;		

	  }
	}
//	display1(dpNum);
//	ocout.close();
	int father = n,value1 = 0,value2 = 0,t;
	if (!dynamic[n][m][d + zero]) father = dpNum[n][m][d + zero][1];
	for (int i = m; i >= 1; i--)
	{
	  personSelected[i] = father;
	  value1 += a[father][0];
	  value2 += a[father][1];
	  t = d;
	  d -= (a[father][0] - a[father][1]);
	  father = dpNum[father][i][t + zero][1];
	  
	}
	cout << "Jury #" << total << endl; 
	cout << "Best jury has value " << value1 << " for prosecution and value " << value2 << " for defence: " << endl;
   for (int i = 1; i <= m; i++)
   cout << " " << personSelected[i];
   cout << endl;
   cout << endl;
   cin >> n >> m;
  }  
}