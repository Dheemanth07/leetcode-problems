// Last updated: 7/1/2026, 10:28:07 AM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int slow = nums[0];
5        int fast = nums[0];
6
7        do {
8            slow = nums[slow];
9            fast = nums[nums[fast]];
10        } while (slow != fast);
11
12        slow = nums[0];
13
14        while (slow != fast) {
15            slow = nums[slow];
16            fast = nums[fast];
17        }
18
19        return slow;
20    }
21};