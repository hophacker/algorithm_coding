#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

struct node{
    int pos;
    int num;
    node(int p, int n):pos(p), num(n){};
    bool operator<(const node& other)const{
        return num < other.num;
    }
};
int solution(vector<int> &A) {
    vector<node> B;
    for (int i = 0; i < A.size(); i++){
        B.push_back(node(i, A[i]));
    }
    sort(B.begin(), B.end());
    int minPos = INT_MAX, maxDis = 0;
    int i = 0;
    for (unsigned i = 0; i < B.size(); i++){
        minPos = min(minPos, B[i].pos);
        maxDis = max(maxDis, B[i].pos - minPos);
    }
    return maxDis;
}

int main(){
    int A[] = {5,3,6,3,4,2};
    vector<int> arr(A, A + sizeof(A)/4);
    cout << solution(arr) << endl;
}
