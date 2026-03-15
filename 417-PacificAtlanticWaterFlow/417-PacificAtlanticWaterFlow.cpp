// Last updated: 3/15/2026, 9:20:31 AM
1class Solution {
2public:
3    void dfs(int r, int c, vector<vector<int>>& heights,
4             vector<vector<bool>>& visited) {
5        visited[r][c] = true;
6
7        vector<int> dir = {0, 1, 0, -1, 0};
8        for (int d = 0; d < 4; d++) {
9            int nr = r + dir[d];
10            int nc = c + dir[d + 1];
11
12            if (nr < 0 || nc < 0 || nr >= heights.size() ||
13                nc >= heights[0].size())
14                continue;
15
16            if (visited[nr][nc])
17                continue;
18
19            if (heights[nr][nc] < heights[r][c])
20                continue;
21
22            dfs(nr, nc, heights, visited);
23        }
24    }
25
26    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
27        int row = heights.size(), cols = heights[0].size();
28
29        vector<vector<bool>> pac(row, vector<bool>(cols, false));
30        vector<vector<bool>> atl(row, vector<bool>(cols, false));
31
32        for (int i = 0; i < row; i++)
33            dfs(i, 0, heights, pac);
34        for (int j = 0; j < cols; j++)
35            dfs(0, j, heights, pac);
36
37        for (int i = 0; i < row; i++)
38            dfs(i, cols - 1, heights, atl);
39        for (int j = 0; j < cols; j++)
40            dfs(row - 1, j, heights, atl);
41
42        vector<vector<int>> res;
43
44        for (int i = 0; i < row; i++)
45            for (int j = 0; j < cols; j++)
46                if (pac[i][j] && atl[i][j])
47                    res.push_back({i, j});
48
49        return res;
50    }
51};
52