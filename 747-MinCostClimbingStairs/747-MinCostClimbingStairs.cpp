// Last updated: 7/17/2026, 2:02:12 PM
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Base cases: The cost to reach the first two steps is 0.
        int twoStepsBehind = 0; // dp[i-2]
        int oneStepBehind = 0;  // dp[i-1]

        // We iterate up to cost.size() because the "Top Floor" is
        // literally one step PAST the end of the array.
        for (int i = 2; i <= cost.size(); i++) {
            // The recurrence relation
            int currentStepCost =
                min(twoStepsBehind + cost[i - 2], oneStepBehind + cost[i - 1]);

            // Shift our window forward for the next iteration
            twoStepsBehind = oneStepBehind;
            oneStepBehind = currentStepCost;
        }

        // step1 now holds the minimum cost to reach the Top Floor
        return oneStepBehind;
    }
};
