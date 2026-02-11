// Last updated: 2/11/2026, 7:41:18 PM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int slow = nums[0];
5        int fast = nums[0];
6        do {
7            slow = nums[slow];
8            fast = nums[nums[fast]];
9        } while (slow != fast);
10        slow = nums[0];
11        while (slow != fast) {
12            slow = nums[slow];
13            fast = nums[fast];
14        }
15        return slow;
16    }
17};