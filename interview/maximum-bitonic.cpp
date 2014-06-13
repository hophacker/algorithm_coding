#include<iostream>
#include<vector>
using namespace std;

int maximum_bitonic(vector<int>&A){
    int n = A.size();
    vector<vector<int> > F(n, vector<int>(2, -1));

    int ans = 0;
    F[0][0] = 1;
    for (int i = 1; i < n; i++){
        F[i][0] = 1;
        for (int j = 0; j < i; j++){
            if (F[j][0] != -1){
                if (A[j] < A[i]){
                    F[i][0] = max(F[i][0], F[j][0] + 1);
                }else if (A[j] > A[i]){
                    F[i][1] = max(F[i][1], F[j][0] + 1);
                }
            }
            if (F[j][1] != -1){
                if (A[j] > A[i])
                    F[i][1] = max(F[i][1], F[j][1] + 1);
            }
        }
        ans = max(ans, max(F[i][0], F[i][1]));
    }
    return ans;
}
int main(){
    vector<int> A;
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        A.push_back(x);
    }
    cout << maximum_bitonic(A) << endl;
}
