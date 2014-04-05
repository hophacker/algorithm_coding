#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
void divide(int number[100], int len)
{
  int advan = 0;
  for (int i = 1; i <= len; i++)
  {
    int advanNow = advan;
    if (number[i] % 2 == 1) advan = 1; 
    else  advan = 0;
    
    number[i] = (advanNow * 10 + number[i]) / 2;
  }
}


void transTenToBit(int number[100], int len, int bit[100])
{
  for (int i = 1; i <=65 ; i++)
  {
    if (number[len] % 2 == 1)
    {
      bit[i] = 1;
      number[len]--;
    }
	else 
      bit[i] =0;
      
    divide(number, len);
  }  
}

bool max(int a[100], int lenA, int b[100], int lenB)
{
  if (lenA > lenB) return true;
  if (lenA < lenB) return false;
  int i = lenA;
  while ((a[i] == b[i]) && (i >= 1)) i--;
  if (i == 0) return true;
  if (a[i] > b[i]) return true;
  return false;
}
void substract(int a[100], int lenA, int b[100], int lenB)
{
  int advan = 0;
  for (int i = 1; i <= lenA; i++)
    if (advan + a[i] < b[i]) 
    {
      a[i] = advan + a[i] + 2 - b[i];
      advan = -1;
    }
    else 
    {
      a[i] = advan + a[i] - b[i];
      advan = 0;
    }
}
int main()
{
  int numOfData;
  bool fu;
  cin >> numOfData;
  for (int i = 1; i <= numOfData; i++)
  {
    int numOfBit,nn;
    cin >> numOfBit;
    nn = numOfBit;
    
    string np;
    cin >> np;
    
  
    string number1;
    int number[100], bit[100], maxBit[100];
    cin >> number1;
    
    if ((number1.length() == 1) && (number1[0] ==0))
    {
      cout << 0 << endl;
      break;
    }
    
    int len;
    if (number1[0] == '-')
    {
      for (int i = 1; i <= number1.length() - 1; i++)
        number[i] = number1[i] - '0';
      fu = true;
      len = number1.length() - 1;
    }
    else
    { 
      for (int i = 0; i <= number1.length() - 1; i++)
        number[i + 1] = number1[i] - '0';
      fu = false;
      len = number1.length();
    }

    if (fu)
      for (int i = 0; i <= numOfBit - 1; i++)
        if (np[i] == 'n') np[i] = 'p';
        else  np[i] = 'n';
    memset(bit, 0, sizeof(bit));    
    transTenToBit(number, len, bit); 
    len = 65; 
    while (bit[len] == 0) len--;
    
    int BBB[100] = {0};
    memset(maxBit, 0, sizeof(maxBit));
    int ii = 0;
    while (np[ii] == 'n') ii++;
    for (int j = numOfBit - 1; j >= ii; j--)
     {
      maxBit[numOfBit - j] = (np[j] == 'p')? 1:0;
      BBB[numOfBit - j] = maxBit[numOfBit - j];
    }
    numOfBit -= ii;
    
    
    if (max(maxBit, numOfBit, bit, len))
    {
      substract(maxBit, numOfBit, bit, len);
      for (int i = 1; i <= numOfBit; i++) 
        if (maxBit[i] == 1)
          BBB[i] = !BBB[i];
      while ((BBB[numOfBit] == '0') && (numOfBit >= 1))  numOfBit--;
      if (numOfBit == 0) cout << 0 << endl;
      else 
      {  
	   //  while ((BBB[numOfBit] == '0') && (numOfBit >= 1))  numOfBit--;
        for (int i = nn; i >= 1; i--) cout << BBB[i];
        cout << endl;
      }
    }
    else 
      cout << "Impossible" << endl;
    
  
  }
  system("PAUSE");
}
