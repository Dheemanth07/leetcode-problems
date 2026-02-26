// Last updated: 2/26/2026, 9:07:34 PM
1class Solution {
2public:
3    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
4        if (node == destination)
5            return true;
6
7        visited[node] = true;
8
9        for (int neighbor : adj[node])
10            if (!visited[neighbor])
11                if (dfs(neighbor, destination, adj, visited))
12                    return true;
13
14        return false;
15    }
16
17    bool validPath(int n, vector<vector<int>>& edges, int source,
18                   int destination) {
19        vector<vector<int>> adj(n);
20
21        for (auto& edge : edges) {
22            adj[edge[0]].push_back(edge[1]);
23            adj[edge[1]].push_back(edge[0]);
24        }
25
26        vector<bool>visited(n, false);
27
28        return dfs(source, destination, adj, visited);
29    }
30};