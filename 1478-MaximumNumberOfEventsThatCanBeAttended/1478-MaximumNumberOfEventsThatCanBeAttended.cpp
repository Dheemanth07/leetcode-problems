// Last updated: 7/16/2026, 9:41:55 PM
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(events.begin(), events.end());

        int i = 0, n = events.size();
        int currentDay = 0;
        int attended = 0;

        while (i < n || !minHeap.empty()) {
            if (minHeap.empty())
                currentDay = events[i][0];

            while (i < n && events[i][0] == currentDay) {
                minHeap.push(events[i][1]);
                i++;
            }

            while (!minHeap.empty() && minHeap.top() < currentDay)
                minHeap.pop();
            if (!minHeap.empty()) {
                attended++;
                minHeap.pop();
            }

            currentDay++;
        }

        return attended;
    }
};