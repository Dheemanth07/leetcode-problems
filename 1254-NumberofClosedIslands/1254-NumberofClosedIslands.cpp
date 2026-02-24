// Last updated: 2/24/2026, 11:24:23 AM
1class Solution {
2public:
3    int rows, cols;
4
5    bool dfs(vector<vector<int>>& grid, int i, int j) {
6        // If out of bounds → touches boundary → NOT closed
7        if (i < 0 || j < 0 || i >= rows || j >= cols)
8            return false;
9
10        // If water or visited → safe
11        if (grid[i][j] == 1)
12            return true;
13
14        // Mark the land cell as visited
15        grid[i][j] = 1;
16
17        // Visit all 4 directions
18        bool up = dfs(grid, i - 1, j);
19        bool down = dfs(grid, i + 1, j);
20        bool left = dfs(grid, i, j - 1);
21        bool right = dfs(grid, i, j + 1);
22
23        // Closed only if all directions are closed
24        return up && down && left && right;
25    }
26
27    int closedIsland(vector<vector<int>>& grid) {
28        rows = grid.size();
29        if (rows == 0)
30            return 0;
31
32        cols = grid[0].size();
33
34        int count = 0;
35
36        // Try DFS only on land cells
37        for (int i = 0; i < rows; i++) {
38            for (int j = 0; j < cols; j++) {
39                if (grid[i][j] == 0) {
40                    if (dfs(grid, i, j))
41                        count++;
42                }
43            }
44        }
45
46        return count;
47    }
48};