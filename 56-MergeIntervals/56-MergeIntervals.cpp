// Last updated: 7/21/2026, 10:19:41 PM
1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        if (intervals.empty())
5            return {};
6
7        sort(intervals.begin(), intervals.end());
8
9        vector<vector<int>> merged;
10        merged.push_back(intervals[0]);
11
12        for (const auto& interval : intervals) {
13            if (merged.empty() || interval[0] > merged.back()[1])
14                merged.push_back(interval); // No overlap, add new interval
15            else
16                merged.back()[1] =
17                    max(merged.back()[1], interval[1]); // Merge overlap
18        }
19
20        return merged;
21    }
22};