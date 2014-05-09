#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// you can also use includes, for example:
// #include <algorithm>
#define ui unsigned int
#define inside(x,L,R) (L<x&&x<R)
const int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
inline bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x3 > x4) swap(x3, x4);
    if (y3 > y4) swap(y3, y4);

    if (x1 == x2){
        if (x3 == x4){
            if (x1 == x3){
                return !(y3 >= y2 || y1 >= y4);
            }else return false;
        }else{
            return inside(y3,y1,y2) && inside(x1,x3,x4);
        }
    }else{
        if (x3 == x4){
            return inside(x3,x1,x2) && inside(y1,y3,y4);
        }else{
            if (y1 == y3){
                return !(x3 >= x2 || x1 >= x4);
            }else return false;
        }
    }
}
int solution(const vector<int> &A) {
    int x1 = 0, y1 = 0, x2, y2, d = 0;
    for (ui i = 0; i < A.size(); i++){


        x2 = x1 + dir[d][0] * A[i];
        y2 = y1 + dir[d][1] * A[i];


        int x3 = 0, y3 = 0, x4, y4, d1 = 0; 
        for (ui j = 0; j < i; j++){
            x4 = x3 + dir[d1][0] * A[j];
            y4 = y3 + dir[d1][1] * A[j];
            if (cross(x1, y1, x2, y2, x3, y3, x4, y4)) return i+1;
            if (++d1 == 4) d1 = 0;
            x3 = x4;
            y3 = y4;
        }
        if (++d == 4) d = 0;
        x1 = x2;
        y1 = y2;
    }
    return -1;
}



int main(){
    int a[] = {1,3,2,5,4,4,6,3,2};
    vector<int> A(a, a+sizeof(a)/4);
    cout << solution(A) << endl;
}
