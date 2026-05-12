// Last updated: 5/12/2026, 10:46:03 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> res;
5
6        int n = nums.size();
7
8        sort(nums.begin(), nums.end());
9
10        for (int i = 0; i < n - 2; i++) {
11
12            if (i > 0 && nums[i] == nums[i - 1])
13                continue;
14
15            int l = i + 1, r = n - 1;
16
17            while (l < r) {
18                int sum = nums[i] + nums[l] + nums[r];
19
20                if (!sum) {
21                    res.push_back({nums[i], nums[l], nums[r]});
22
23                    while (l < r && nums[l] == nums[l + 1])
24                        l++; // Skip duplicates
25
26                    while (l < r && nums[r] == nums[r - 1])
27                        r--; // Skip duplicates
28
29                    l++;
30                    r--;
31                } else if (sum < 0)
32                    l++;
33                else
34                    r--;
35            }
36        }
37
38        return res;
39    }
40};