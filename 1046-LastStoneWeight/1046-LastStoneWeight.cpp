// Last updated: 7/5/2026, 5:12:41 PM
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq(stones.begin(), stones.end());
5        while (pq.size() > 1) {
6            int largest = pq.top();
7            pq.pop();
8            int seclargest = pq.top();
9            pq.pop();
10            
11            if (largest != seclargest)
12                pq.push(largest - seclargest);
13        }
14        return pq.empty() ? 0 : pq.top();
15    }
16};