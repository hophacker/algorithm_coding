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
int main()
{
    int num[] = {10,1,2,7,6,1,5};
    vector<int> vnum(num, num+sizeof(num)/4);
    sort_like_wave(vnum);
    printV(vnum);
}
