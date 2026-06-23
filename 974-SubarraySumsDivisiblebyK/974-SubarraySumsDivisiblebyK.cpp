// Last updated: 6/23/2026, 4:14:46 PM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        unordered_map<int, int> prefix_map;
7        prefix_map[0] = 1;
8
9        int count = 0;
10        int prefix_sum = 0;
11
12        for (int i = 0; i < n; i++) {
13            prefix_sum += nums[i];
14
15            int remainder = (prefix_sum % k + k) % k;
16
17            if (prefix_map.find(remainder) != prefix_map.end())
18                count += prefix_map[remainder];
19
20            prefix_map[remainder]++;
21        }
22
23        return count;
24    }
25};