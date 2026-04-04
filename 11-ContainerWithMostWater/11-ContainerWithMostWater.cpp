// Last updated: 4/4/2026, 12:33:48 PM
1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int maxarea = 0;
5        int n = height.size();
6        int left = 0, right = n - 1;
7        while (left < right) {
8            int area = min(height[left], height[right])*(right-left);
9            maxarea = max(maxarea, area);
10            if (height[left] < height[right])
11                left++;
12            else
13                right--;
14        }
15        return maxarea;
16    }
17};