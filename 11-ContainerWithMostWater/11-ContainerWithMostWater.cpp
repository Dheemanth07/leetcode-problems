// Last updated: 6/25/2026, 11:22:13 AM
1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int maxarea = 0;
5        int n = height.size();
6        int left = 0, right = n - 1;
7
8        while (left < right) {
9            int area = min(height[left], height[right]) * (right - left);
10            maxarea = max(maxarea, area);
11
12            if (height[left] < height[right])
13                left++;
14            else
15                right--;
16        }
17
18        return maxarea;
19    }
20};