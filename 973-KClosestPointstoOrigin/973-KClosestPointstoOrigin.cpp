// Last updated: 7/5/2026, 5:38:06 PM
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
5        int dist, i;
6        for (i = 0; i < points.size(); i++) {
7            int x = points[i][0];
8            int y = points[i][1];
9            dist = x * x + y * y;
10            pq.push({dist, i});
11
12            if (pq.size() > k)
13                pq.pop();
14        }
15
16        vector<vector<int>> result;
17        while (!pq.empty()) {
18            result.push_back(points[pq.top().second]);
19            pq.pop();
20        }
21        return result;
22    }
23};