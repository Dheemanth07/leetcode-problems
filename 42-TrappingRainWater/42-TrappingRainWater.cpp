// Last updated: 2/1/2026, 12:53:29 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int left = 0, right = height.size() - 1;
5        int leftmax = 0, rightmax = 0, water = 0;
6        while (left < right) {
7            if (height[left] < height[right]) {
8                height[left] >= leftmax ? (leftmax = height[left])
9                                        : water += (leftmax - height[left]);
10                left++;
11            } else {
12                height[right] >= rightmax ? (rightmax = height[right])
13                                          : water += (rightmax - height[right]);
14                right--;
15            }
16        }
17        return water;
18    }
19};