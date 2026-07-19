// Last updated: 7/19/2026, 8:53:20 PM
1class Solution {
2public:
3    // Helper function to map a 1D square number to 2D matrix coordinates
4    pair<int, int> getCoordinates(int square, int n) {
5        // Squares are 1-indexed, make it 0-indexed for easier math
6        int r = n - 1 - (square - 1) / n;
7        int c = (square - 1) % n;
8
9        // If the row is an odd distance from the bottom, it goes right-to-left
10        if ((n - 1 - r) % 2 != 0)
11            c = n - 1 - c;
12
13        return {r, c};
14    }
15
16    int snakesAndLadders(vector<vector<int>>& board) {
17        int n = board.size();
18
19        // Queue stores pairs of {current_square, moves_taken}
20        queue<pair<int, int>> q;
21
22        // Visited array to prevent infinite loops (size is n*n + 1 because
23        // squares are 1 to n*n)
24        vector<bool> visited(n * n + 1, false);
25
26        // Start at square 1 with 0 moves
27        q.push({1, 0});
28        visited[1] = true;
29
30        while (!q.empty()) {
31            auto [curr, moves] = q.front();
32            q.pop();
33
34            // If we reached the final square, return the moves it took
35            if (curr == n * n)
36                return moves;
37
38            // Simulate rolling a 6-sided die
39            for (int i = 1; i <= 6; i++) {
40                int next_square = curr + i;
41
42                // Don't roll past the end of the board
43                if (next_square > n * n)
44                    break;
45
46                // Get 2D coordinates to check for snakes/ladders
47                auto [r, c] = getCoordinates(next_square, n);
48
49                // If there's a snake or ladder, update next_square
50                if (board[r][c] != -1)
51                    next_square = board[r][c];
52
53                // If we haven't visited this square yet, add it to the queue
54                if (!visited[next_square]) {
55                    visited[next_square] = true;
56                    q.push({next_square, moves + 1});
57                }
58            }
59        }
60
61        // If the queue empties and we never reached n*n, it's impossible
62        return -1;
63    }
64};