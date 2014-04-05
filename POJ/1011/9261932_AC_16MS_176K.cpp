#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;

bool flag[99];
int a[100], m, cnt, n;

bool DFS(int x, int rest, int step)
{
 if (step == cnt) return true;
 for (int i = x; i < n; ++i)
  if (!flag[i])
  {
   if (a[i] == rest)
   {
    flag[i] = true;
    if (DFS(0, m, step + 1)) return true;
    return flag[i] = false;
   }
   else if (a[i] < rest)
   {
    flag[i] = true;
    if (DFS(x + 1, rest - a[i], step)) return true;
    flag[i] = false;
    if (rest == m) return false;
    while (a[i] == a[i + 1]) ++i;
   }
  };
 return false;
}

int main()
{
 int a_max, sum;
 while (scanf("%d", &n), n)
 {
  a_max = 0; sum = 0;
  for (int i = n; i; )
  {
   scanf("%d", &a[--i]);
   sum += a[i];
   if (a[i] > a_max) a_max = a[i];
  }
  sort(a, a + n, greater<int>());
  for (m = a_max; m < sum; ++m)
   if (sum % m == 0)
   {
    memset(flag, false, n);
    cnt = sum / m;
    if (DFS(0, m, 1))
    {
     printf("%d\n", m);
     goto NEXT;
    }
   };
  printf("%d\n", sum);
NEXT:;
 }
 return 0;
}