/*
 * =====================================================================================
 *
 *       Filename:  poj1111.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  06/30/2012 03:34:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Farmer J (), fengjie1314126@126.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include<iostream>
#include<fstream>
#define cin fin
using namespace std;
char map[26][25];
int x, y, x1, y1;
int total = 0;




void search(int x1, int y1){
	map[x1][y1] = 'x';
	if (x1 == 1 || map[x1-1][y1] =='.') total++;
	if (x1 == x || map[x1+1][y1] =='.') total++;
	if (y1 == 1 || map[x1][y1-1] =='.') total++;
	if (y1 == y || map[x1][y1+1] =='.') total++;

	if (x1-1 >= 1 && map[x1-1][y1] =='X') search(x1-1, y1);
	if (x1+1 <= x && map[x1+1][y1] =='X') search(x1+1, y1);
	if (y1-1 >= 1 && map[x1][y1-1] =='X') search(x1, y1-1);
	if (y1+1 <= y && map[x1][y1+1] =='X') search(x1, y1+1);

	
	if (x1-1 >= 1 && y1-1>=1 && map[x1-1][y1-1] =='X') search(x1-1, y1-1);
	if (x1+1 <= x && y1+1<=y && map[x1+1][y1+1] =='X') search(x1+1, y1+1);
	if (y1-1 >= 1 && x1+1<=x && map[x1+1][y1-1] =='X') search(x1+1, y1-1);
	if (y1+1 <= y && x1-1>=1 && map[x1-1][y1+1] =='X') search(x1-1, y1+1);
}
int main(){
	ifstream fin("in.txt");
	cin >> x >> y >> x1 >> y1;
	while(x != 0){
		total = 0;
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				cin >> map[i][j];
		if (map[x1][y1]=='X')search(x1, y1);
		cout << total << endl;
		cin >> x >> y >> x1 >> y1;
	}



}