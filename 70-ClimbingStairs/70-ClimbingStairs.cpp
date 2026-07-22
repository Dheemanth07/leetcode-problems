// Last updated: 7/22/2026, 8:41:29 PM
1class Solution {
2public:
3    int climbStairs(int n) {
4        // Base cases:
5        // 0 steps requires 1 way (do nothing).
6        // 1 step requires 1 way (take 1 step).
7        if (n <= 1)
8            return 1;
9
10        // We only need to remember the "last two" steps
11        int twoStepsBehind = 1; // dp[0]
12        int oneStepBehind = 1;  // dp[1]
13        int currentStep = 0;
14
15        // Build our way up to step N
16        for (int i = 2; i <= n; i++) {
17            // The core DP logic: My ways = (ways to get here from 1 step) +
18            // (ways from 2 steps)
19            currentStep = oneStepBehind + twoStepsBehind;
20
21            // Shift our memory forward for the next loop iteration!
22            twoStepsBehind = oneStepBehind;
23            oneStepBehind = currentStep;
24        }
25
26        return currentStep;
27    }
28};