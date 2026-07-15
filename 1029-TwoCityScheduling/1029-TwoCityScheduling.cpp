// Last updated: 7/15/2026, 11:31:33 AM
1class Solution {
2public:
3    int twoCitySchedCost(vector<vector<int>>& costs) {
4        int n = costs.size() / 2;
5        int minCost = 0;
6
7        // nth_element places the top 'n' cheapest-to-divert-to-A people
8        // in the first half of the array. It runs in O(N) time.
9        nth_element(costs.begin(), costs.begin() + n, costs.end(),
10                    [](const vector<int>& a, const vector<int>& b) {
11                        // Compare the opportunity cost (Cost A - Cost B)
12                        return (a[0] - a[1]) < (b[0] - b[1]);
13                    });
14
15        // Sum up the costs. The first half goes to A, second half to B.
16        for (int i = 0; i < n; i++) {
17            minCost += costs[i][0];     // First half goes to City A
18            minCost += costs[i + n][1]; // Second half goes to City B
19        }
20
21        return minCost;
22    }
23};