// Last updated: 6/25/2026, 11:02:23 AM
1class Solution {
2public:
3    int threeSumClosest(vector<int>& nums, int target) {
4        sort(nums.begin(), nums.end());
5
6        int n = nums.size();
7
8        int minDiff = INT_MAX;
9        int minSum = 0;
10
11        for (int i = 0; i < n - 2; i++) {
12            int l = i + 1, r = n - 1;
13
14            while (l < r) {
15                int sum = nums[i] + nums[l] + nums[r];
16                int diff = abs(target - sum);
17
18                if (diff < minDiff) {
19                    minDiff = diff;
20                    minSum = sum;
21                }
22
23                if (sum < target)
24                    l++;
25                else if (sum > target)
26                    r--;
27                else
28                    return sum;
29            }
30        }
31        return minSum;
32    }
33};