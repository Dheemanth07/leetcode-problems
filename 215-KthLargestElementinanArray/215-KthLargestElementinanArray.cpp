// Last updated: 1/30/2026, 11:01:53 AM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int,vector<int>,greater<int>>pq;
5        for(int num:nums){
6            pq.push(num);
7            if(pq.size()>k) pq.pop();
8        }
9        return pq.top();
10    }
11};