// Last updated: 3/15/2026, 10:20:14 AM
1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>> adjList(numCourses);
5        vector<int> indegree(numCourses, 0);
6
7        for (auto& pre : prerequisites) {
8            adjList[pre[1]].push_back(pre[0]);
9            indegree[pre[0]]++;
10        }
11
12        queue<int> q;
13
14        for (int i = 0; i < numCourses; i++)
15            if (!indegree[i])
16                q.push(i);
17
18        int count = 0;
19
20        while (!q.empty()) {
21            int top = q.front();
22            q.pop();
23            count++;
24
25            for (int neighbor : adjList[top]) {
26                indegree[neighbor]--;
27                if (!indegree[neighbor])
28                    q.push(neighbor);
29            }
30        }
31        return count == numCourses;
32    }
33};