#include "leetcode.h"
void sort_like_wave(vector<int>& a){
    bool rise = false;
    for (int i = 0; i < a.size()-1; i++){
        if (rise){
            if (a[i] > a[i+1]) swap(a[i], a[i+1]);
        }else{
            if (a[i+1] > a[i]) swap(a[i], a[i+1]);
        }
    }
}
int min_seq_larger_than_sum(vector<int> &a, int sum){
    int L = 0, R = 0, tempSum = a[0], minSeq = INT_MAX;
    while(R < a.size()){
        if (tempSum > sum){
            minSeq = min(R-L+1, minSeq);
            tempSum -= a[L];
            L++;
        } else{
            R++;
            if (R < a.size()){
                tempSum += a[R];
            }else break;
        }
    }
    return (minSeq == INT_MAX? -1: minSeq);
}
int main()
{
    int num[] = {2,1,1,4,3,6};
    vector<int> vnum(num, num+sizeof(num)/4);
    cout << min_seq_larger_than_sum(vnum, 8) << endl;
}
