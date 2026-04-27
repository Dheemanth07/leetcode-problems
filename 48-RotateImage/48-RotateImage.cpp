// Last updated: 4/27/2026, 8:28:06 PM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5
6        // Step 1: Transpose
7        for (int i = 0; i < n; i++) {
8            for (int j = i + 1; j < n; j++) {
9                swap(matrix[i][j], matrix[j][i]);
10            }
11        }
12
13        // Step 2: Reverse each row
14        for (int i = 0; i < n; i++) {
15            reverse(matrix[i].begin(), matrix[i].end());
16        }
17    }
18};