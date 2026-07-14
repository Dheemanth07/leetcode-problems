// Last updated: 7/14/2026, 10:59:47 AM
1class Solution {
2public:
3    int twoCitySchedCost(vector<vector<int>>& costs) {
4        int n = costs.size();
5        int minCost = 0;
6
7        vector<int> diff;
8
9        for (vector<int> cost : costs) {
10            minCost += cost[0];
11            diff.push_back(cost[1] - cost[0]);
12        }
13
14        sort(diff.begin(), diff.end());
15
16        for (int i = 0; i < costs.size() / 2; i++)
17            minCost += diff[i];
18
19        return minCost;
20    }
21};