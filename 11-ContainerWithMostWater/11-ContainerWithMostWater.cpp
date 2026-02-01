// Last updated: 2/1/2026, 12:51:03 PM
1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int maxarea = 0;
5        int n = height.size();
6        int left = 0, right = n - 1;
7        while (left < right) {
8            int h = min(height[left], height[right]);
9            int w = right - left;
10            maxarea = max(maxarea, h * w);
11            if (height[left] < height[right])
12                left++;
13            else
14                right--;
15        }
16        return maxarea;
17    }
18};