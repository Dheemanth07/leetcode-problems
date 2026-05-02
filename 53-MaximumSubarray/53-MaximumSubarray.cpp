// Last updated: 5/2/2026, 8:55:45 AM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int current_sum = nums[0];
5        int max_sum = nums[0];
6
7        // Start looping from the second element
8        for (int i = 1; i < nums.size(); i++) {
9            // Keep the history or start fresh at nums[i]?
10            current_sum = max(nums[i], current_sum + nums[i]);
11
12            // Did we just find a new all-time high?
13            max_sum = max(max_sum, current_sum);
14        }
15
16        return max_sum;
17    }
18};