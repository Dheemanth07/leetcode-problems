// Last updated: 5/2/2026, 3:39:35 PM
1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int min_length = INT_MAX;
5        int current_sum = 0;
6        int left = 0;
7
8        for (int right = 0; right < nums.size(); right++) {
9            current_sum += nums[right];
10
11            while (current_sum >= target) {
12                int current_window_size = right - left + 1;
13                min_length = min(min_length, current_window_size);
14
15                current_sum -= nums[left];
16                left++;
17            }
18        }
19
20        return min_length == INT_MAX ? 0 : min_length;
21    }
22};