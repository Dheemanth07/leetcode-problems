// Last updated: 7/7/2026, 10:55:52 AM
1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        unordered_map<char, int> map;
5
6        for (char c : tasks)
7            map[c]++;
8
9        priority_queue<int, vector<int>> maxHeap;
10        for (auto& p : map)
11            maxHeap.push(p.second);
12
13        queue<pair<int, int>> cooldown;
14        int time = 0;
15
16        while (!maxHeap.empty() || !cooldown.empty()) {
17            time++;
18
19            if (!maxHeap.empty()) {
20                int remaining = maxHeap.top() - 1;
21                maxHeap.pop();
22
23                if (remaining)
24                    cooldown.push({remaining, time + n});
25            }
26            if (!cooldown.empty() && cooldown.front().second == time) {
27                maxHeap.push(cooldown.front().first);
28                cooldown.pop();
29            }
30        }
31
32        return time;
33    }
34};