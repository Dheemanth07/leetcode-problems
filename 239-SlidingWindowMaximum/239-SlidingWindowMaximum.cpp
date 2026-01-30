// Last updated: 1/30/2026, 2:18:41 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        priority_queue<pair<int, int>> pq; // {value, index}
5        vector<int> res;
6
7        for (int i = 0; i < nums.size(); i++) {
8            pq.push({nums[i], i});
9
10            if (i >= k - 1) {
11                // Remove the top element if it is outside the current window
12                while (pq.top().second <= i - k) {
13                    pq.pop();
14                }
15                res.push_back(pq.top().first);
16            }
17        }
18        return res;
19    }
20};