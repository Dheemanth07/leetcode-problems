// Last updated: 7/18/2026, 1:59:31 PM
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int max = *max_element(nums.begin(), nums.end());
5        int min = *min_element(nums.begin(), nums.end());
6
7        while (min > 0) {
8            int temp = min;
9            min = max % min;
10            max = temp;
11        }
12
13        return max;
14    }
15};