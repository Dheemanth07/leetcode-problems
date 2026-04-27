// Last updated: 4/27/2026, 7:19:31 PM
1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6
7        vector<vector<int>> res;
8
9        for (int i = 0; i < n - 3; i++) {
10            if (i > 0 && nums[i] == nums[i - 1])
11                continue;
12
13            for (int j = i + 1; j < n - 2; j++) {
14                if (j > i + 1 && nums[j] == nums[j - 1])
15                    continue;
16
17                int l = j + 1, r = n - 1;
18
19                while (l < r) {
20                    long long sum =
21                        (long long)nums[i] + nums[j] + nums[l] + nums[r];
22                    if (sum == target) {
23                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
24
25                        while (l < r && nums[l] == nums[l + 1])
26                            l++;
27                        while (l < r && nums[r] == nums[r - 1])
28                            r--;
29                            
30                        l++;
31                        r--;
32
33                    } else if (sum < target)
34                        l++;
35                    else
36                        r--;
37                }
38            }
39        }
40        return res;
41    }
42};