// Last updated: 7/18/2026, 4:39:24 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int rows = grid.size();
5        int cols = grid[0].size();
6
7        // If start or destination is blocked, impossible
8        if (grid[0][0] || grid[rows - 1][cols - 1])
9            return -1;
10
11        // 8 possible directions
12        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
13                                             {0, -1},  {0, 1},  {1, -1},
14                                             {1, 0},   {1, 1}};
15
16        queue<pair<int, int>> q;
17        q.push({0, 0});
18
19        // Mark start as visited
20        grid[0][0] = 1;
21
22        int pathLength = 1;
23
24        while (!q.empty()) {
25            int levelSize = q.size();
26
27            // Process one BFS level
28            for (int i = 0; i < levelSize; i++) {
29                auto [x, y] = q.front();
30                q.pop();
31
32                // Destination reached
33                if (x == rows - 1 && y == cols - 1)
34                    return pathLength;
35
36                for (auto [dx, dy] : directions) {
37                    int nx = x + dx;
38                    int ny = y + dy;
39
40                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
41                        !grid[nx][ny]) {
42
43                        grid[nx][ny] = 1; // mark visited
44                        q.push({nx, ny});
45                    }
46                }
47            }
48
49            // One more step away from the source
50            pathLength++;
51        }
52
53        return -1;
54    }
55};