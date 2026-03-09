// Last updated: 3/9/2026, 11:34:23 AM
1class Solution {
2public:
3    vector<int> parent;
4    vector<int> rank;
5
6    void initialize(int n) {
7        parent.resize(n + 1);
8        rank.resize(n + 1, 0);
9        for (int i = 1; i <= n; i++)
10            parent[i] = i;
11    }
12
13    int find(int x) {
14        if (parent[x] != x)
15            parent[x] = find(parent[x]);
16        return parent[x];
17    }
18
19    bool unite(int x, int y) {
20        int px = find(x);
21        int py = find(y);
22
23        if (px == py)
24            return false;
25        if (rank[px] < rank[py])
26            parent[px] = py;
27        else if (rank[px] > rank[py])
28            parent[py] = px;
29        else {
30            parent[py] = px;
31            rank[px]++;
32        }
33
34        return true;
35    }
36
37    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
38        int n = edges.size();
39        initialize(n);
40
41        for (auto& edge : edges)
42            if (!unite(edge[0], edge[1]))
43                return edge;
44        return {};
45    }
46};
47