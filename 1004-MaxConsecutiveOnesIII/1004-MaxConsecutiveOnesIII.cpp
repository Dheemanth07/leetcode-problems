// Last updated: 5/2/2026, 4:58:43 PM
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int left = 0;
5        int max_len = 0;
6        int zero_budget = k;
7
8        for (int right = 0; right < nums.size(); right++) {
9            if (!nums[right])
10                zero_budget--;
11
12            while (zero_budget < 0) {
13                if (!nums[left])
14                    zero_budget++;
15                left++;
16            }
17
18            max_len = max(max_len, right - left + 1);
19        }
20        return max_len;
21    }
22};