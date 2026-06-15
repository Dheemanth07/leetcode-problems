// Last updated: 6/15/2026, 9:52:41 AM
1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4        int n = nums.size();
5
6        vector<vector<int>> res;
7
8        sort(nums.begin(), nums.end());
9
10        for (int i = 0; i < n - 3; i++) {
11            if (i > 0 && nums[i] == nums[i - 1])
12                continue;
13
14            for (int j = i + 1; j < n - 2; j++) {
15                if (j > i + 1 && nums[j] == nums[j - 1])
16                    continue;
17
18                int l = j + 1, r = n - 1;
19
20                while (l < r) {
21                    long long sum =
22                        (long long)nums[i] + nums[j] + nums[l] + nums[r];
23
24                    if (sum == target) {
25                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
26
27                        while (l < r && nums[l] == nums[l + 1])
28                            l++;
29                        while (l < r && nums[r] == nums[r - 1])
30                            r--;
31
32                        l++;
33                        r--;
34
35                    } else if (sum < target)
36                        l++;
37                    else
38                        r--;
39                }
40            }
41        }
42
43        return res;
44    }
45};