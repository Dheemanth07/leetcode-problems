// Last updated: 6/24/2026, 11:14:18 AM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int rows = matrix.size();
5        int cols = matrix[0].size();
6
7        int left = 0;
8        int right = rows * cols - 1;
9
10        while (left <= right) {
11            int mid = left + (right - left) / 2;
12
13            // Map 1D index back to 2D coordinates
14            int midValue = matrix[mid / cols][mid % cols];
15
16            if (midValue == target) 
17                return true;
18            else if (target > midValue) 
19                left = mid + 1;
20            else 
21                right = mid - 1;       
22        }
23
24        return false;
25    }
26};