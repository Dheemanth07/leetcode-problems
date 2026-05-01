// Last updated: 5/1/2026, 10:53:24 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        long n = nums.size();
5        long sum = 0, cur_F = 0;
6        vector<int> res;
7        for (int i = 0; i < n; i++) {
8            sum += nums[i];
9            cur_F += (long)i * nums[i];
10        }
11
12        long max_F = cur_F;
13
14        for (int k = 1; k < n; k++) {
15            cur_F = cur_F + sum - n * nums[n - k];
16            max_F = max(max_F, cur_F);
17        }
18
19        return max_F;
20    }
21};