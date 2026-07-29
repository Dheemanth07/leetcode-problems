// Last updated: 7/29/2026, 5:59:13 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n = nums.size();
5        int max_ele = 0, second_max_ele = 0;
6        int idx;
7
8        for (int i = 0; i < n; i++) {
9            if (nums[i] > max_ele) {
10                second_max_ele = max_ele;
11                max_ele = nums[i];
12            } else
13                second_max_ele = max(second_max_ele, nums[i]);
14        }
15
16        return (max_ele - 1) * (second_max_ele - 1);
17    }
18};