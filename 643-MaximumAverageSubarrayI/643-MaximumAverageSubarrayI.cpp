// Last updated: 5/2/2026, 11:42:46 AM
1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        int window_sum = 0;
5
6        // 1. Calculate the sum of the very first window
7        for (int i = 0; i < k; i++) {
8            window_sum += nums[i];
9        }
10
11        int max_sum = window_sum;
12
13        // 2. Slide the window through the rest of the array
14        for (int i = k; i < nums.size(); i++) {
15            window_sum += nums[i] - nums[i - k];
16            max_sum = max(max_sum, window_sum);
17        }
18
19        // 3. Divide exactly once at the end!
20        // (We cast to double so we get proper decimal places)
21        return (double)max_sum / k;
22    }
23};