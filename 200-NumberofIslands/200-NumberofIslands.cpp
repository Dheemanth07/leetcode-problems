// Last updated: 7/18/2026, 11:53:37 AM
1class Solution {
2public:
3    int numIslands(vector<vector<char>>& grid) {
4        int rows = grid.size();
5        int cols = grid[0].size();
6
7        int count = 0;
8
9        for (int i = 0; i < rows; i++) {
10            for (int j = 0; j < cols; j++) {
11                if (grid[i][j] == '1') {
12                    dfs(i, j, grid);
13                    count++;
14                }
15            }
16        }
17
18        return count;
19    }
20
21    void dfs(int i, int j, vector<vector<char>>& grid) {
22        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
23            return;
24
25        if (grid[i][j] == '0')
26            return;
27
28        grid[i][j] = '0';
29
30        dfs(i + 1, j, grid);
31        dfs(i, j + 1, grid);
32        dfs(i - 1, j, grid);
33        dfs(i, j - 1, grid);
34    }
35};