// Last updated: 5/2/2026, 9:45:40 AM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int current_sum = 0;
5        int count = 0;
6        unordered_map<int, int> prefix_map;
7        prefix_map[0] = 1;
8
9        for (int num : nums) {
10            current_sum += num;
11
12            int target = current_sum - k;
13            if (prefix_map.find(target) != prefix_map.end()) {
14                count += prefix_map[target];
15            }
16
17            prefix_map[current_sum]++;
18        }
19
20        return count;
21    }
22};