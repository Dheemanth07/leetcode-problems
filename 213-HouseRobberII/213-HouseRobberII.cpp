// Last updated: 7/8/2026, 10:31:00 PM
1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        int n = nums.size();
5
6        // Base cases for very small arrays
7        if (n == 0)
8            return 0;
9        if (n == 1)
10            return nums[0];
11
12        // Run House Robber 1 on Reality A (Exclude Last)
13        int maxA = robLinear(nums, 0, n - 2);
14
15        // Run House Robber 1 on Reality B (Exclude First)
16        int maxB = robLinear(nums, 1, n - 1);
17
18        // The ultimate max!
19        return max(maxA, maxB);
20    }
21
22private:
23    // This is literally your exact House Robber 1 code!
24    // The only difference is we pass in a start and end index.
25    int robLinear(const vector<int>& nums, int start, int end) {
26        int prev2 = 0;
27        int prev1 = 0;
28
29        for (int i = start; i <= end; i++) {
30            int current_max = max(nums[i] + prev2, prev1);
31            prev2 = prev1;
32            prev1 = current_max;
33        }
34
35        return prev1;
36    }
37};