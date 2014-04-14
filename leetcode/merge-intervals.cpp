#include "leetcode.h"

bool cmp(const Interval &a, const Interval &b){
    if (a.start == b.start) return a.end < b.end;
    else return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size();){
            int j = i+1, end = intervals[i].end;
            for (;j < intervals.size(); j++){
                if (intervals[j].start <= end) 
                    end = max(end, intervals[j].end);
                else break;
            }
            res.push_back(Interval(intervals[i].start, end));
            i = j;
        }
        return res;
    }
};
int main ( int argc, char *argv[] ) {

    Solution s = Solution();

    vector<Interval> i;
    i.push_back(Interval(1,3));
    i.push_back(Interval(2,6));
    i.push_back(Interval(8,10));
    i.push_back(Interval(15,18));
    i = s.merge(i);
    printIntervals(i);
    return EXIT_SUCCESS;
}
