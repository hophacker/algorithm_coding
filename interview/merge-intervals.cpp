#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b){
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        int i = 0;
        while(i < intervals.size()){
            int j = i+1;
            int end = intervals[i].end;
            while(j < intervals.size() && intervals[j].start >= end){
                end = max(end, intervals[j].end);
                j++;
            }
            res.push_back(Interval(intervals[i].start, end));
            i = j;
        }
        return res;
    }
};
