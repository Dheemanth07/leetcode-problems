// Last updated: 1/26/2026, 6:07:27 PM
1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int maxc = INT_MIN;
5        int count = 0;
6        for (int i = 0; i < nums.size(); i++) {
7            if (nums[i] == 1)
8                count++;
9            else
10                count = 0;
11            maxc = max(maxc, count);
12        }
13        return maxc;
14    }
15};