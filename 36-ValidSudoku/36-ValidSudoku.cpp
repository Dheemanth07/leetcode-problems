// Last updated: 1/27/2026, 10:20:43 PM
1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        // Track digits seen in rows, columns, and 3x3 sub-boxes
5        bool rows[9][9] = {false}, cols[9][9] = {false}, boxes[9][9] = {false};
6
7        for (int i = 0; i < 9; ++i) {
8            for (int j = 0; j < 9; ++j) {
9                char c = board[i][j];
10                if (c == '.') continue;
11
12                int num = c - '1';  // Map '1'-'9' to 0-8
13                int boxIndex = (i / 3) * 3 + (j / 3);
14
15                // Check row, column, and 3x3 box
16                if (rows[i][num] || cols[j][num] || boxes[boxIndex][num])
17                    return false;
18
19                // Mark as seen
20                rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
21            }
22        }
23        return true;
24    }
25};