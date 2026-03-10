// Last updated: 3/10/2026, 4:58:08 PM
1class Solution {
2public:
3    int m, n;
4
5    void dfs(int i, int j, vector<vector<char>>& board) {
6        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
7            return;
8
9        board[i][j] = '#'; // mark safe
10
11        dfs(i + 1, j, board);
12        dfs(i - 1, j, board);
13        dfs(i, j + 1, board);
14        dfs(i, j - 1, board);
15    }
16
17    void solve(vector<vector<char>>& board) {
18        m = board.size();
19        n = board[0].size();
20
21        // Run DFS from borders
22        for (int i = 0; i < m; i++) {
23            dfs(i, 0, board);
24            dfs(i, n - 1, board);
25        }
26
27        for (int j = 0; j < n; j++) {
28            dfs(0, j, board);
29            dfs(m - 1, j, board);
30        }
31
32        // Convert surrounded regions
33        for (int i = 0; i < m; i++) {
34            for (int j = 0; j < n; j++) {
35                if (board[i][j] == 'O')
36                    board[i][j] = 'X';
37                else if (board[i][j] == '#')
38                    board[i][j] = 'O';
39            }
40        }
41    }
42};