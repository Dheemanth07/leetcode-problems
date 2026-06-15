// Last updated: 6/15/2026, 10:40:57 AM
1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        int n = nums.size();
5
6        int pivot = -1;
7
8        for (int i = n - 2; i >= 0; i--) {
9            if (nums[i] < nums[i + 1]) {
10                pivot = i;
11                break;
12            }
13        }
14
15        if (pivot == -1) {
16            reverse(nums.begin(), nums.end());
17            return;
18        }
19
20        for (int i = n - 1; i > pivot; i--) {
21            if (nums[i] > nums[pivot]) {
22                swap(nums[i], nums[pivot]);
23                break;
24            }
25        }
26
27        sort(nums.begin() + pivot + 1, nums.end());
28    }
29};