#include <iostream>
#include <cstdio>//////是define值可以利用
#include <vector>
#define M 9000
using namespace std;
struct snowflake
{
 int arm[6];
}snow;
bool cmp(struct snowflake &a,struct snowflake &b)/////////////&的话就.///*就->////
{
 int start[6],i,j,num=0;
 for(i=0;i<6;i++)
  if(a.arm[0]==b.arm[i])
  {
   start[num++]=i;
  }
  bool flag;
 for(i=0;i<num;i++)
 {
  flag=true;
  for(j=1;j<6;j++)
   if(a.arm[j]!=b.arm[(start[i]+j)%6])//顺时针
   {
    flag=false;
    break;
   }
  if(flag)
   return true ;
  flag=true;
  for(j=1;j<6;j++)
   if(a.arm[j]!=b.arm[(start[i]-j+6)%6])//逆时针
   {
    flag=false;
    break;
   }
  if(flag)
   return true;
 }
 return false;
}
int h(struct snowflake&a)
{
 return (a.arm[0]+a.arm[1]+a.arm[2]+a.arm[3]+a.arm[4]+a.arm[5]+a.arm[6])%M;////获取地址
}
int main()
{
 vector<snowflake>vs[M+3];//////////////////////声明
 int n,i;
 cin>>n;
 while(n--)
 {
  for(i=0;i<6;i++)
   scanf("%d",&snow.arm[i]);
  int address=h(snow);/////////////////
  vs[address].push_back(snow);/////////用了拉链法！vs可看为二维数组!
 }
 int j,k;
 for(i=0;i<M;i++)
 {
  for(j=0;j<vs[i].size();j++)//////////vs[i].size
   for(k=j+1;k<vs[i].size();k++)////
    if(cmp(vs[i][j],vs[i][k])==true)
    {
     printf("Twin snowflakes found.\n");
     return 0;
    }
 }
 printf("No two snowflakes are alike.\n");
return 0;
}
