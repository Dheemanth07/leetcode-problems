// Last updated: 2/25/2026, 8:10:11 AM
1class Solution {
2public:
3    int rows, cols;
4
5    bool dfs(vector<vector<int>>& grid, int i, int j) {
6        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
7            return false; // touched boundary
8
9        if (grid[i][j] == 1)
10            return true; // water doesn't break closure
11
12        grid[i][j] = 1; // mark visited
13
14        bool up = dfs(grid, i - 1, j);
15        bool down = dfs(grid, i + 1, j);
16        bool left = dfs(grid, i, j - 1);
17        bool right = dfs(grid, i, j + 1);
18
19        return up && down && left && right;
20    }
21
22    int closedIsland(vector<vector<int>>& grid) {
23        int count = 0;
24
25        for (int i = 0; i < grid.size(); i++) {
26            for (int j = 0; j < grid[0].size(); j++) {
27                if (grid[i][j] == 0) {
28                    if (dfs(grid, i, j))
29                        count++;
30                }
31            }
32        }
33
34        return count;
35    }
36};