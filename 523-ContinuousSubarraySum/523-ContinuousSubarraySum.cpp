// Last updated: 5/2/2026, 10:38:37 AM
1class Solution {
2public:
3    bool checkSubarraySum(vector<int>& nums, int k) {
4
5        int current_sum = 0;
6        unordered_map<int, int> remainder_map;
7
8        remainder_map[0] = -1;
9
10        for (int i = 0; i < nums.size(); i++) {
11            current_sum += nums[i];
12
13            int remainder = current_sum % k;
14
15            if (remainder_map.find(remainder) != remainder_map.end()) {
16                if (i - remainder_map[remainder] >= 2)
17                    return true;
18            } else
19                remainder_map[remainder] = i;
20        }
21        return false;
22    }
23};