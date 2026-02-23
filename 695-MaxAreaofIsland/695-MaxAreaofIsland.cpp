// Last updated: 2/23/2026, 10:38:43 AM
1class Solution {
2public:
3    int dfs(vector<vector<int>>& grid, int i, int j) {
4        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
5            grid[i][j] == 0)
6            return 0;
7        grid[i][j] = 0;
8        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +
9               dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
10    }
11
12    int maxAreaOfIsland(vector<vector<int>>& grid) {
13        int max_area = 0;
14        for (int i = 0; i < grid.size(); i++)
15            for (int j = 0; j < grid[i].size(); j++)
16                max_area = max(max_area, dfs(grid, i, j));
17        return max_area;
18    }
19};