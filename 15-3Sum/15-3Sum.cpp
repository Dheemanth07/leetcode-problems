// Last updated: 1/29/2026, 7:29:59 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> res;
5        int n = nums.size();
6        sort(nums.begin(), nums.end());
7        for (int i = 0; i < n - 2; i++) {
8            if (i > 0 && nums[i] == nums[i - 1])
9                continue;
10            int l = i + 1, r = n - 1;
11            while (l < r) {
12                int sum = nums[i] + nums[l] + nums[r];
13                if (!sum) {
14                    res.push_back({nums[i], nums[l], nums[r]});
15                    while (l < r && nums[l] == nums[l + 1])
16                        l++; // Skip duplicates
17                    while (l < r && nums[r] == nums[r - 1])
18                        r--; // Skip duplicates
19                    l++;
20                    r--;
21                } else if (sum < 0)
22                    l++;
23                else
24                    r--;
25            }
26        }
27        return res;
28    }
29};