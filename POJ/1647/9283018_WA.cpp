#include<iostream>
#include<stdio.h>
using namespace std;

int board[10][10];
struct pos{
	int x, y;
};
const int fx[][2] = {{0,-1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
pos wK, wQ, bK, wQReserve, wQAns;
void setBoard(){
	memset(board, 0, sizeof(board));
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			board[i][j] = 1;
}
bool setAchieve(int x, int y){
	if (board[x][y] == 1) {
		board[x][y] = 2;
		return true;
	}else return false;
}
bool check(){
	if ((wQ.x==wK.x && wQ.y==wK.y) || (wQ.x==bK.x && wQ.y==bK.y)) return false;
	setBoard();
	for (int d = 0; d < 8; d++){
		setAchieve(wK.x+fx[d][0], wK.y+fx[d][1]);
		for (int i = 1; i < 8; i++)
			if (!setAchieve(wQ.x+fx[d][0]*i, wQ.y+fx[d][1]*i)) break;
	}
	if (board[bK.x][bK.y] == 1) return false;
	for (int d = 0; d < 8; d++)
		if (board[bK.x+fx[d][0]][bK.y+fx[d][1]] == 1) return false;
	return true;
}
void printIt(){
	printf("%c%c\n", wQAns.y+'a'-1, wQAns.x+'0');
}
void setAns(){
	if (wQ.y < wQAns.y || wQ.y==wQAns.y && wQ.x < wQAns.x)
		wQAns = wQ;
}
int main()
{
	freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	char s1[3], s2[3], s3[3];
	scanf("%s%s%s", s1, s2, s3); 
	wK.y = s1[0]-'a'+1; wK.x = s1[1]-'0';
	wQ.y = s2[0]-'a'+1; wQ.x = s2[1]-'0';
	bK.y = s3[0]-'a'+1; bK.x = s3[1]-'0';
	wQReserve = wQ;
	wQAns.y = 9;
	if (check()){
		setAns();
	}
	for (int d = 0; d < 8; d++){
		for (int i = 1; i < 8; i++){
			wQ.x = wQReserve.x + fx[d][0]*i;
			wQ.y = wQReserve.y + fx[d][1]*i;
			if (board[wQ.x][wQ.y] == 1) break;
			if (check()){
				setAns();
			}
		}
	}
	if (wQAns.y < 9) printIt();
	else printf("no\n");
}