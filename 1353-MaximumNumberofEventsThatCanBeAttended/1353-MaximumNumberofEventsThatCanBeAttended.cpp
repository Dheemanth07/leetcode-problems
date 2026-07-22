// Last updated: 7/22/2026, 11:13:30 AM
1class Solution {
2public:
3    int maxEvents(vector<vector<int>>& events) {
4
5        // Min heap stores the ending days of all events
6        // that have started but haven't been attended yet.
7        priority_queue<int, vector<int>, greater<int>> minHeap;
8
9        // Sort events by starting day.
10        sort(events.begin(), events.end());
11
12        int i = 0, n = events.size();
13        int currentDay = 0;
14        int attended = 0;
15
16        // Continue until all events are processed
17        // and no available events remain.
18        while (i < n || !minHeap.empty()) {
19
20            // If no event is currently available,
21            // jump directly to the next event's start day.
22            if (minHeap.empty())
23                currentDay = events[i][0];
24
25            // Add every event that starts today
26            // into the heap.
27            while (i < n && events[i][0] == currentDay) {
28                minHeap.push(events[i][1]);
29                i++;
30            }
31
32            // Remove events that have already expired
33            // (their ending day is before today).
34            while (!minHeap.empty() && minHeap.top() < currentDay)
35                minHeap.pop();
36
37            // Greedy Choice:
38            // Attend the event that ends the earliest,
39            // since delaying it may cause us to lose it forever.
40            if (!minHeap.empty()) {
41                attended++;
42                minHeap.pop();
43            }
44
45            // Move to the next day.
46            currentDay++;
47        }
48
49        return attended;
50    }
51};