// Last updated: 6/22/2026, 6:30:12 PM
class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false; // touched boundary

        if (grid[i][j] == 1)
            return true; // water doesn't break closure

        grid[i][j] = 1; // mark visited

        bool up = dfs(grid, i - 1, j);
        bool down = dfs(grid, i + 1, j);
        bool left = dfs(grid, i, j - 1);
        bool right = dfs(grid, i, j + 1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j))
                        count++;
                }
            }
        }

        return count;
    }
};