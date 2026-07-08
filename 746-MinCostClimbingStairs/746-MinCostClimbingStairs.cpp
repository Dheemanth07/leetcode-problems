// Last updated: 7/8/2026, 9:14:41 PM
1class Solution {
2public:
3    int minCostClimbingStairs(vector<int>& cost) {
4        // Base cases: The cost to reach the first two steps is 0.
5        int twoStepsBehind = 0; // dp[i-2]
6        int oneStepBehind = 0;  // dp[i-1]
7
8        // We iterate up to cost.size() because the "Top Floor" is
9        // literally one step PAST the end of the array.
10        for (int i = 2; i <= cost.size(); i++) {
11            // The recurrence relation
12            int currentStepCost =
13                min(twoStepsBehind + cost[i - 2], oneStepBehind + cost[i - 1]);
14
15            // Shift our window forward for the next iteration
16            twoStepsBehind = oneStepBehind;
17            oneStepBehind = currentStepCost;
18        }
19
20        // step1 now holds the minimum cost to reach the Top Floor
21        return oneStepBehind;
22    }
23};
24