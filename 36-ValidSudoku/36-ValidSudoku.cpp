// Last updated: 6/15/2026, 11:15:15 AM
1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        // Track digits seen in rows, columns, and 3x3 sub-boxes
5        bool rows[9][9] = {false}, cols[9][9] = {false}, boxes[9][9] = {false};
6
7        for (int i = 0; i < 9; ++i) {
8            for (int j = 0; j < 9; ++j) {
9                char c = board[i][j];
10                
11                if (c == '.') continue;
12
13                int num = c - '1';  // Map '1'-'9' to 0-8
14                int boxIndex = (i / 3) * 3 + (j / 3);
15
16                // Check row, column, and 3x3 box
17                if (rows[i][num] || cols[j][num] || boxes[boxIndex][num])
18                    return false;
19
20                // Mark as seen
21                rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
22            }
23        }
24        return true;
25    }
26};