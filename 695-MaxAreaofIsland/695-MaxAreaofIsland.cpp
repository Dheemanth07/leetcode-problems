// Last updated: 7/18/2026, 12:14:48 PM
1class Solution {
2public:
3    int maxAreaOfIsland(vector<vector<int>>& grid) {
4        int rows = grid.size();
5        int cols = grid[0].size();
6
7        int max_area = 0;
8
9        for (int i = 0; i < rows; i++) {
10            for (int j = 0; j < cols; j++) {
11                if (grid[i][j]) {
12                    int area = 0;
13                    max_area = max(max_area, dfs(i, j, grid, area));
14                }
15            }
16        }
17
18        return max_area;
19    }
20
21    int dfs(int i, int j, vector<vector<int>>& grid, int& area) {
22        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
23            return 0;
24
25        if (!grid[i][j])
26            return 0;
27
28        grid[i][j] = 0;
29        area++;
30
31        dfs(i + 1, j, grid, area);
32        dfs(i, j + 1, grid, area);
33        dfs(i - 1, j, grid, area);
34        dfs(i, j - 1, grid, area);
35
36        return area;
37    }
38};