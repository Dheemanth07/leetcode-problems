// Last updated: 6/22/2026, 7:45:31 PM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int current_sum = 0;
5        int count = 0;
6
7        unordered_map<int, int> prefix_map;
8        prefix_map[0] = 1;
9
10        for (int num : nums) {
11            current_sum += num;
12
13            int target = current_sum - k;
14            if (prefix_map.find(target) != prefix_map.end()) 
15                count += prefix_map[target];
16
17            prefix_map[current_sum]++;
18        }
19
20        return count;
21    }
22};