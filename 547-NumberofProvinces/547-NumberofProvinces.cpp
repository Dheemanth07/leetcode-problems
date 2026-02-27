// Last updated: 2/27/2026, 8:23:11 PM
1class Solution {
2public:
3    void dfs(int city, vector<vector<int>>& isConnected,
4             vector<bool>& visited) {
5        visited[city] = true;
6        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
7            if (city == neighbor)
8                continue;
9            if (isConnected[city][neighbor] && !visited[neighbor])
10                dfs(neighbor, isConnected, visited);
11        }
12    }
13
14    int findCircleNum(vector<vector<int>>& isConnected) {
15        int n = isConnected.size();
16        vector<bool> visited(n, false);
17        int provinces = 0;
18        for (int i = 0; i < n; i++) {
19            if (!visited[i]) {
20                dfs(i, isConnected, visited);
21                provinces++;
22            }
23        }
24        return provinces;
25    }
26};