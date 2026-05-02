// Last updated: 5/2/2026, 10:07:21 AM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4
5        int maxi = nums[0];
6        int current_max = nums[0];
7        int current_min = nums[0];
8
9        for (int i = 1; i < nums.size(); i++) {
10
11            if (nums[i] < 0)
12                swap(current_max, current_min);
13
14            current_max = max(current_max * nums[i], nums[i]);
15            current_min = min(current_min * nums[i], nums[i]);
16            maxi = max(maxi, current_max);
17        }
18
19        return maxi;
20    }
21};