// Last updated: 6/23/2026, 4:55:18 PM
1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int maxc = 0, count = 0;
5        for (int num : nums) {
6            if (num)
7                count++;
8            else
9                count = 0;
10            maxc = max(maxc, count);
11        }
12        return maxc;
13    }
14};