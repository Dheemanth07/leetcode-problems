// Last updated: 2/25/2026, 6:28:15 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        queue<pair<int, int>> q;
5        int fresh = 0;
6        int rows = grid.size(), cols = grid[0].size();
7        for (int i = 0; i < rows; i++) {
8            for (int j = 0; j < cols; j++) {
9                if (grid[i][j] == 2)
10                    q.push({i, j});
11                else if (grid[i][j] == 1)
12                    fresh++;
13            }
14        }
15
16        if (!fresh)
17            return 0;
18
19        vector<int> dir = {0, 1, 0, -1, 0};
20        int minutes = 0;
21
22        while (!q.empty()) {
23            int level = q.size();
24            bool rotted = false;
25
26            for (int i = 0; i < level; i++) {
27                auto [x, y] = q.front();
28                q.pop();
29
30                for (int d = 0; d < 4; d++) {
31                    int nx = x + dir[d];
32                    int ny = y + dir[d + 1];
33
34                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
35                        grid[nx][ny] = 2;
36                        q.push({nx,ny});
37                        fresh--;
38                        rotted = true;
39                    }
40                }
41            }
42
43            if (rotted)
44                minutes++;
45        }
46
47        return fresh == 0 ? minutes : -1;
48    }
49};