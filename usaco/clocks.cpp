/*
ID: fengjie3
PROG: clocks
LANG: C++
*/
#include<queue>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<memory.h>
using namespace std;
typedef vector<int>  v;


struct node{
	int clock;
	int father;
	int step;
};
vector<int> sou(9);
int tar;
node q[262144];
int tail, head;
string way[9];
bool pan[262144];
int calc(const vector<int> &clock)
{
	int total = 0;
	for (int i = 0; i < 9; i++)	
			total = (total * 4) + clock[i];
	return total;
}
void fancalc(int number, vector<int> & clock)
{
	for (int i = 8; i >= 0; i--)
	{
		clock[i] = number % 4;
		number /= 4;
	}
}
int main()
{
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	for (int i = 0; i < 9; i++)
	{
		cin >> sou[i];
		if (sou[i] == 12) sou[i] = 0;
		sou[i] /= 3;
	}
	tar = 0;
	way[0] = "ABDE";  
	way[1] = "ABC";  
	way[2] = "BCEF";  
	way[3] = "ADG";  
	way[4] = "BDEFH";  
	way[5] = "CFI";  
	way[6] = "DEGH";  
	way[7] = "GHI";  
	way[8] = "EFHI";
	memset(pan, true, sizeof(pan));
	head = tail = 1;
	
	node temp; /////
	temp.clock = calc(sou);
	temp.father = 0;
	temp.step = 0;
	//print(temp);
	pan[calc(sou)] = false;
	q[head] = temp;
	vector<int> clock(9);
	while (head <= tail)
	{
		//print(temp);
		for (int i = 0; i < 9; i++)
		{
			fancalc(q[head].clock, clock);
			for (int j = 0; j < way[i].length(); j++)
				clock[way[i][j]-'A'] = (clock[way[i][j]-'A'] + 1) % 4;
			int t = calc(clock);
			if (pan[t])
			{
				pan[t] = false;
				tail++;
				temp.clock  =  t;
				temp.father = head;
				temp.step = i;
				q[tail] = temp;
				if (q[tail].clock == tar)
				goto end;
			}
		}
		head++;
	}
	end:
		int answer[26214];
		int total = 0;
		while (q[tail].father != 0)
		{
			answer[++total] = q[tail].step;
			tail = q[tail].father;
		}
		for (int i = total; i >= 1; i--)
			if (i == 1)
				printf("%d\n", answer[i]+1);
			else
				printf("%d ", answer[i]+1);
   }
