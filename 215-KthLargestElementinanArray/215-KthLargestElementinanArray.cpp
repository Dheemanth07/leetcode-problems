// Last updated: 7/5/2026, 4:33:26 PM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5        
6        for (int num : nums) {
7            pq.push(num);
8            if (pq.size() > k)
9                pq.pop();
10        }
11        return pq.top();
12    }
13};