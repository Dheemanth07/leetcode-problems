// Last updated: 6/24/2026, 7:00:11 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        if (matrix.empty() || matrix[0].empty())
5            return false;
6
7        int rows = matrix.size();
8        int cols = matrix[0].size();
9
10        // Start at the top-right corner
11        int r = 0;
12        int c = cols - 1;
13
14        // Keep searching as long as we are inside the matrix boundaries
15        while (r < rows && c >= 0) {
16            if (matrix[r][c] == target)
17                return true; // Found it!
18            else if (matrix[r][c] > target)
19                c--; // Current number is too big, move left to find smaller
20                     // numbers
21            else
22                r++; // Current number is too small, move down to find bigger
23                     // numbers
24        }
25
26        return false; // Fell off the grid, target doesn't exist
27    }
28};