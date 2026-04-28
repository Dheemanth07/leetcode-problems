// Last updated: 4/28/2026, 9:45:10 AM
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals,
4                               vector<int>& newInterval) {
5        vector<vector<int>> res;
6        int i = 0, n = intervals.size();
7
8        // 1. Add intervals before overlap
9        while (i < n && intervals[i][1] < newInterval[0]) {
10            res.push_back(intervals[i]);
11            i++;
12        }
13
14        // 2. Merge overlapping intervals
15        while (i < n && intervals[i][0] <= newInterval[1]) {
16            newInterval[0] = min(newInterval[0], intervals[i][0]);
17            newInterval[1] = max(newInterval[1], intervals[i][1]);
18            i++;
19        }
20        res.push_back(newInterval);
21
22        // 3. Add remaining intervals
23        while (i < n) {
24            res.push_back(intervals[i]);
25            i++;
26        }
27
28        return res;
29    }
30};