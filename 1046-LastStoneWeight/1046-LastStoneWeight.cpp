// Last updated: 2/21/2026, 8:48:24 PM
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq(stones.begin(),stones.end());
5        while (pq.size()>1) {
6            int largest = pq.top();
7            pq.pop();
8            int seclargest = pq.top();
9            pq.pop();
10            if(largest!=seclargest) pq.push(largest-seclargest);
11        }
12        return pq.empty()?0:pq.top();
13    }
14};