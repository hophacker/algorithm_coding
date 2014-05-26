#include<iostream>
#include<algorithm>
#include<priority_queue>
using namespace std;


//k < n/(log n)
int select_k_th(vector<int> arr, int k){
    priority_queue<int> pq;
    for (int i = 0; i < arr.size(); i++){
        pq.push(arr[i]);
    }
    int ret;
    for (int i = 0; i < k; i++){
        ret = pq.top();
        pq.pop();
    }
    return ret;
}
