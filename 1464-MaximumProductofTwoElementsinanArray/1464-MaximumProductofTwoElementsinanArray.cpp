// Last updated: 7/29/2026, 5:56:51 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n = nums.size();
5        int max_ele = 0, second_max_ele = 0;
6        int idx;
7
8        for (int i = 0; i < n; i++) {
9            if (nums[i] > max_ele) {
10                max_ele = nums[i];
11                idx = i;
12            }
13        }
14
15        for (int i = 0; i < n; i++) {
16            if (nums[i] == max_ele && i == idx)
17                continue;
18            second_max_ele = max(second_max_ele, nums[i]);
19        }
20
21        return (max_ele - 1) * (second_max_ele - 1);
22    }
23};