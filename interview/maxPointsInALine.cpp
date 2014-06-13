#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,(int)a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,a[i].size())cout << a[i][j] << ' '; cout << endl;}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


#define eps 1e-13
#define zero(x) (abs(x) < eps)
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int M = 0;
        for (int i = 0; i < points.size(); i++){
            int dup = 1;
            int ver = 0;
            vector<double> S;
            for (int j = i+1; j < points.size(); j++){
                if(zero(points[i].x-points[j].x)){
                    if (zero(points[i].y-points[j].y)){
                        dup++;
                    }else{
                        ver++;
                    }
                }else{
                    S.push_back( (1.0*points[j].y-points[i].y) / (points[j].x - points[i].x));
                }
            }
            int maxN = ver + dup;
            sort(S.begin(), S.end());
            int j = 0;
            while(j < S.size()){
                int jj = j+1;
                while(jj < S.size() && zero(S[j]-S[jj])) jj++;
                maxN = max(maxN, jj-j+dup);
                j = jj;
            }
//            printV(S);
//            cout << "Dup:" << dup << "  ver:"  << ver << endl;
            M = max(maxN, M);
        }
        return M;
    }
};



int main(){
    vector<Point> p;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back(Point(x,y));
    }
    Solution s;
    cout << s.maxPoints(p) << endl;
}
