#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node{
    int i, val;
    node(){
    }
    node(int i, int val):i(i), val(val){
    }
};

vector<int> nextGreaterElement(vector<int>& A){
    stack<node> st;
    vector<int> res(A.size());
    for (int i = 0; i < A.size(); i++){
        if (st.empty()){
        }else{
            while(!st.empty() && st.top().val < A[i]){
                res[st.top().i] = A[i];
                st.pop();
            }
        }
        st.push(node(i, A[i]));
    }
    while(!st.empty()){
        res[st.top().i] = -1;
        st.pop();
    }
    return res;
}

int main(){
    vector<int> A;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        A.push_back(x);
    }
    vector<int> res =  nextGreaterElement(A);
    for (int i = 0; i < n; i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}
