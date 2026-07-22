// Last updated: 7/22/2026, 2:04:26 PM
1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int maxReachable = 0;
5        int n = nums.size();
6
7        for (int i = 0; i < n; i++) {
8            if (i > maxReachable)
9                return false;
10            maxReachable = max(maxReachable, i + nums[i]);
11
12            if (maxReachable >= n - 1)
13                return true;
14        }
15
16        return true;
17    }
18};