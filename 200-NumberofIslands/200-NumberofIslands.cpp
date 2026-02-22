// Last updated: 2/22/2026, 10:16:08 AM
1class Solution {
2public:
3    void dfs(vector<vector<char>>& grid, int i, int j) {
4        if (i < 0 || j < 0 || i >= grid.size() ||
5            j >= grid[0].size())    // return if index goes out of bounds
6            return;
7
8        if (grid[i][j] == '0')      // If already visited return
9            return;
10
11        grid[i][j] = '0';       // Mark it as visited
12
13        // DFS all its neighbours
14        dfs(grid, i + 1, j);    // DFS down
15        dfs(grid, i - 1, j);    // DFS up
16        dfs(grid, i, j - 1);    // DFS left
17        dfs(grid, i, j + 1);    // DFS right
18    }
19
20    int numIslands(vector<vector<char>>& grid) {
21        int count = 0;
22        for (int i = 0; i < grid.size(); i++) {
23            for (int j = 0; j < grid[i].size(); j++) {
24                if (grid[i][j] == '1') {
25                    dfs(grid, i, j);
26                    count++; // Increment count for every island found
27                }
28            }
29        }
30        return count;
31    }
32};
33