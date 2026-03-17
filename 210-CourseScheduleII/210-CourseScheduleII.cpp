// Last updated: 3/17/2026, 8:04:39 PM
1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>> adj(numCourses);
5        vector<int> indegree(numCourses, 0);
6
7        for (auto& pre : prerequisites) {
8            adj[pre[1]].push_back(pre[0]);
9            indegree[pre[0]]++;
10        }
11
12        queue<int> q;
13        vector<int> res;
14
15        for (int i = 0; i < numCourses; i++)
16            if (!indegree[i])
17                q.push(i);
18
19        while (!q.empty()) {
20            int top = q.front();
21            q.pop();
22
23            res.push_back(top);
24
25            for (int neighbour : adj[top]) {
26                indegree[neighbour]--;
27                if (!indegree[neighbour])
28                    q.push(neighbour);
29            }
30        }
31        
32        if (res.size() == numCourses)
33            return res;
34        return {};
35    }
36};