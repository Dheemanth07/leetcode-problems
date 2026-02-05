// Last updated: 2/5/2026, 10:10:10 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        if (nums.empty())
5            return -1;
6        int n = nums.size();
7        int left = 0, right = n - 1;
8        while (left <= right) {
9            int mid = left + (right - left) / 2;
10            if (nums[mid] == target)
11                return mid;
12            else if (nums[mid] < target)
13                left = mid + 1;
14            else
15                right = mid - 1;
16        }
17        return -1;
18    }
19};
20