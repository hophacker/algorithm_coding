//#define cin ccin  //define 末尾不能有引号
#include<fstream>
#include<iostream>
#include<memory.h>
using namespace std;
const int modP = 979573;
bool map[101][101],
     mapDo[101][101],
     mapDoNow[101][101],
     used[10000];
long double  hash[10000];
int hashl[10000];
int maxH, minH,
    maxW, minW,
    doH, doW,
    stock;
bool print;
long double abs(long double a)
{
  if (a < 0) return(-a);
  else return a;
}
void expand(int i, int j)
{
  if (i > maxH) maxH = i;
  if (i < minH) minH = i;
  if (j > maxW) maxW = j;
  if (j < minW) minW = j;
  
  map[i][j] = false;
  if (map[i + 1][j]) expand(i + 1, j);
  if (map[i - 1][j]) expand(i - 1, j);
  if (map[i][j + 1]) expand(i, j + 1);
  if (map[i][j - 1]) expand(i, j - 1);  
  map[i][j] = true;
}

void left(int &doH, int &doW)
{
  for (int i = 1; i <= doH; i++)
    for (int j = 1; j <= doW; j++)
      mapDoNow[i][j] = mapDo[i][j];

  for (int i = 1; i <= doH; i++)
    for (int j = 1; j <= doW; j++)
      mapDo[j][doH + 1 - i] = mapDoNow[i][j];
  int temp = doH;
      doH = doW;
      doW = temp;
}
void up(int doH, int doW)
{
  for (int i = 1; i <= (doH/2); i++)
    for (int j = 1; j <= doW; j++)
      {
        bool temp = mapDo[i][j];
             mapDo[i][j] = mapDo[doH + 1 - i][j];
             mapDo[doH + 1 -i][j] = temp;
      }
}
long double  calc()
{
  long double  value = 0, mul = 1;
  for (int i = 1; i <= doH; i++)
    for (int j = 1; j <= doW; j++)
    {
      mul = mul * 2;
      if (mapDo[i][j]) value = value + mul;
    }  
  return value;
}
int min(int a, int b)
{
  if (a>b) return b;
  else return a;
}

void doit(int step)
{
  int i,j;
  doH = maxH - minH + 1;
  doW = maxW - minW + 1;
  
  for (i = minH; i <= maxH; i++)
    for (j = minW; j <= maxW; j++)
    {
      mapDo[i - minH + 1][j - minW + 1] = map[i][j];
      map[i][j] = false;
    }
    
  long double minValue = 1E43,
      value;
for (int t = 1; t <= 2; t++)
{
  for (i = 1; i <= 4; i++)
    if (i == 1)
    {
      value = calc();
      if (value < minValue) minValue = value;
    }
    else
    {
      left(doH,doW);
      value = calc();
      if (value < minValue) minValue = value;
    }
  if (t == 1) up(doH, doW);
} 
  if (step == 1)
  {
    stock++;
    hash[stock] = minValue;
    hashl[stock] = min(doH,doW);
  }
  else 
  {
    bool cao = false;
    for (int i = 1; i <= stock; i++)
      if ((abs(minValue - hash[i]) <= ((1E-8) * minValue))&&(!used[i])&&(hashl[i] == min(doH, doW)))
        {
          cao = true;
          used[i] = true;
          break;
        }
    if (!cao) print = false;
  }
// cout << minValue << "   "<<  doH << " " << doW << endl;
}


int main()
{
  ifstream ccin;
  ccin.open("data.in");
  int nOfData,
      w,
      h,
      nOfDot;
  cin >> nOfData;
  while (nOfData--)
  {
    cin >> h >> w >> nOfDot;
    memset(map ,0 , sizeof(map)); 
    for (int i = 1; i <= nOfDot; i++)
    {
      int x, y;
      cin >> x >> y;
      map[x + 1][y + 1] = true;
    }
    
    memset(hash, 0 , sizeof(hash));
    print  = true;
    stock = 0;
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        if (map[i][j])
        {
          maxH = minH = i;
          maxW = minW = j;
          expand(i,j);
          doit(1);
        }
    
    memset(map ,0 , sizeof(map));
    for (int i = 1; i <= nOfDot; i++)
    {
      int x, y;
      cin >> x >> y;
      map[x + 1][y + 1] = true;
    }
    memset(used ,0 , sizeof(used));
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        if ((map[i][j]) && print)
        {
          maxH = minH = i;
          maxW = minW = j;
          expand(i,j);
          doit(2);
        }
    if (print) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  system("PAUSE");
}
