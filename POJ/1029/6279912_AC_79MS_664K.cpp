//#define cin ccin
#include<fstream>
#include<iostream>
using namespace std;
int exp[101][1001];
int big[101];
bool appear[1001];

bool whoFalse(int who, int weight, int total)
{
	int TWeight1,TWeight2;
	for (int i = 1; i <= total; i++)
	{
		TWeight1 = 0;
		for (int j = 1; j <= exp[i][0]; j++)
		  if (exp[i][j] == who) TWeight1 += weight;
		  else TWeight1 += 1;
		
		TWeight2 = 0;
		for (int j = 1 + exp[i][0]; j <= exp[i][0] * 2; j++)
		  if (exp[i][j] == who) TWeight2 += weight;
		  else TWeight2 += 1;
		
		if (!((TWeight1 > TWeight2 && big[i]) || (TWeight1 < TWeight2 &&  !big[i])))
		  return false;
	}
	return true;
}
int main()
{
    ifstream ccin;
	int n,
	    k,
			nOExp;
	bool mayF[1001];
	
	ccin.open("input.txt");
	cin >> n >> k;	
	nOExp = 0;
	for (int i = 1; i <= n; i++)
	{
	  mayF[i] = true;
	  appear[i] = false;
   }
	for (int i = 1; i <= k; i++)
	{
		cin >> exp[0][0];
		for (int j = 1; j <= exp[0][0]; j++) 
      {
        int a;
        cin >> a;
        exp[0][j] = a;
        appear[a] = true;
      }
        
       for (int j = 1; j <= exp[0][0]; j++) 
          {
            int a;
            cin >> a;
            exp[0][j + exp[0][0]] = a;
            appear[a] = true;
          }	
        char ch;
    cin >> ch;
    if (ch == '=')
        for (int j = 1; j <= exp[0][0]; j++)
        {
		    mayF[exp[0][j]] = mayF[exp[0][j + exp[0][0]]] = false;
		    }
		else 
		{
			nOExp++;
			for (int j = 0; j <= exp[0][0] * 2; j++)
			  exp[nOExp][j] = exp[0][j];
			if (ch == '>') big[nOExp] = true;
			else big[nOExp] = false;
		}
	}
	int totalMayF = 0,who;
	for (int i = 1; i <= n; i++)
	  if (mayF[i])
	  {
			totalMayF++;
			who = i;
		}
	if (nOExp == 0)
	{
	  if (totalMayF == 1) cout << who;
	  else if (totalMayF > 1) cout << 0;
  }
	else
	{
    who = 0;
		for (int i = 1; i <= n; i++)
		  if ((mayF[i]) && (appear[i]))
		  {
				if (whoFalse(i , 2, nOExp))
				  if (who == 0) who = i;
				  else 
				  {
						cout << 0;
						return 0;
				  }
				if (whoFalse(i , 0, nOExp))
				  if (who == 0) who = i;
				  else 
				  {
						cout << 0;
						return 0;
					}
			}
		cout << who;
	}
	system("PAUSE");
}
