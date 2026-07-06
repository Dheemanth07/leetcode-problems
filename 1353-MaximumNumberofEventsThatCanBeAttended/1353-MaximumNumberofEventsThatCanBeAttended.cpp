// Last updated: 7/6/2026, 5:50:51 PM
1class Solution {
2public:
3    int maxEvents(vector<vector<int>>& events) {
4        priority_queue<int, vector<int>, greater<int>> minHeap;
5        sort(events.begin(), events.end());
6
7        int i = 0, n = events.size();
8        int currentDay = 0;
9        int attended = 0;
10
11        while (i < n || !minHeap.empty()) {
12            if (minHeap.empty())
13                currentDay = events[i][0];
14
15            while (i < n && events[i][0] == currentDay) {
16                minHeap.push(events[i][1]);
17                i++;
18            }
19
20            while (!minHeap.empty() && minHeap.top() < currentDay)
21                minHeap.pop();
22            if (!minHeap.empty()) {
23                attended++;
24                minHeap.pop();
25            }
26
27            currentDay++;
28        }
29
30        return attended;
31    }
32};