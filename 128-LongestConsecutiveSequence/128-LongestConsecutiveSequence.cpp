// Last updated: 6/24/2026, 9:03:20 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        unordered_set<int> s(nums.begin(), nums.end());
5
6        int longest = 0;
7
8        for (int num : s) {
9            if (s.find(num - 1) == s.end()) {
10                int current = num;
11                int length = 1;
12
13                while (s.find(current + 1) != s.end()) {
14                    current++;
15                    length++;
16                }
17
18                longest = max(longest, length);
19            }
20        }
21
22        return longest;
23    }
24};
25