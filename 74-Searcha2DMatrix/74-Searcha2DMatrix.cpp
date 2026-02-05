// Last updated: 2/5/2026, 10:37:01 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        int left = 0;
8        int right = m * n - 1;
9
10        while (left <= right) {
11            int mid = left + (right - left) / 2;
12
13            // Map 1D index back to 2D coordinates
14            int midValue = matrix[mid / n][mid % n];
15
16            if (midValue == target) {
17                return true;
18            } else if (midValue < target) {
19                left = mid + 1;
20            } else {
21                right = mid - 1;
22            }
23        }
24
25        return false;
26    }
27};