// Last updated: 2/22/2026, 12:15:07 PM
1class Solution {
2public:
3    void dfs(int curroom, vector<vector<int>>& rooms, vector<bool>& visited) {
4        visited[curroom] = true;
5        for (int key : rooms[curroom])
6            if (!visited[key])
7                dfs(key, rooms, visited);
8    }
9
10    bool canVisitAllRooms(vector<vector<int>>& rooms) {
11        vector<bool> visited(rooms.size(), false);
12        dfs(0, rooms, visited);
13        for (int v : visited)
14            if (!v)
15                return false;
16        return true;
17    }
18};