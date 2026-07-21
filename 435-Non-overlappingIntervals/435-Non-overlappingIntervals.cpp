// Last updated: 7/21/2026, 10:07:38 PM
1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(),
5             [](const vector<int>& a, const vector<int>& b) {
6                 return a[1] < b[1];
7             });
8
9        int removeCount = 0;
10        int lastEnd = intervals[0][1];
11
12        for (int i = 1; i < intervals.size(); i++) {
13            if (intervals[i][0] < lastEnd)
14                removeCount++;
15            else
16                lastEnd = intervals[i][1];
17        }
18
19        return removeCount;
20    }
21};