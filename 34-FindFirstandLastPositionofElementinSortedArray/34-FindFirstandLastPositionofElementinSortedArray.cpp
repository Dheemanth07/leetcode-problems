// Last updated: 4/27/2026, 7:51:04 PM
1class Solution {
2public:
3    int findFirst(vector<int>& nums, int target) {
4        int l = 0, r = nums.size() - 1, ans = -1;
5
6        while (l <= r) {
7            int mid = l + (r - l) / 2;
8
9            if (nums[mid] == target) {
10                ans = mid;
11                r = mid - 1; // go left
12            } else if (nums[mid] < target) {
13                l = mid + 1;
14            } else {
15                r = mid - 1;
16            }
17        }
18        return ans;
19    }
20
21    int findLast(vector<int>& nums, int target) {
22        int l = 0, r = nums.size() - 1, ans = -1;
23
24        while (l <= r) {
25            int mid = l + (r - l) / 2;
26
27            if (nums[mid] == target) {
28                ans = mid;
29                l = mid + 1; // go right
30            } else if (nums[mid] < target) {
31                l = mid + 1;
32            } else {
33                r = mid - 1;
34            }
35        }
36        return ans;
37    }
38
39    vector<int> searchRange(vector<int>& nums, int target) {
40        return {findFirst(nums, target), findLast(nums, target)};
41    }
42};