// Last updated: 7/17/2026, 2:02:00 PM
class Solution {
public:
    void dfs(int curroom, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[curroom] = true;
        for (int key : rooms[curroom])
            if (!visited[key])
                dfs(key, rooms, visited);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);
        for (int v : visited)
            if (!v)
                return false;
        return true;
    }
};